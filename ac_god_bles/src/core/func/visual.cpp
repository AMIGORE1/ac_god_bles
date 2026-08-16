#include "visual.h"


bool esp::WorldToScreen(Vector3 pos, Vector2& screen, const Matrix4x4& matrix, int windowWidth, int windowHeight)
{
    Vector4 clipCoords = matrix * Vector4{ pos.x, pos.y, pos.z, 1.0f };

    if (clipCoords.w < 0.1f)
        return false;

    Vector3 NDC;
    NDC.x = clipCoords.x / clipCoords.w;
    NDC.y = clipCoords.y / clipCoords.w;
    NDC.z = clipCoords.z / clipCoords.w;

    screen.x = (windowWidth / 2.0f * NDC.x) + (windowWidth / 2.0f);
    screen.y = -(windowHeight / 2.0f * NDC.y) + (windowHeight / 2.0f);
    return true;
}

void esp::Update()
{

    if (!cfg::BoxEsp  && !cfg::HealthBar && !cfg::TraceEsp)
        return;


    uintptr_t localPlayerPtr = *reinterpret_cast<uintptr_t*>(mem::ac_base + offs::LocalPlayer);
    uintptr_t entityListArray = *reinterpret_cast<uintptr_t*>(mem::ac_base + offs::EntityList);
    Matrix4x4* viewMatrix = reinterpret_cast<Matrix4x4*>(offs::ViewMatrix);

    if (!localPlayerPtr || !entityListArray || !viewMatrix)
        return;

    Entity* LocalPlayer = reinterpret_cast<Entity*>(localPlayerPtr);
    int numOfPlayers = *reinterpret_cast<int*>(mem::ac_base + offs::NumOfPlayers);


    if (numOfPlayers <= 1 || numOfPlayers > 64)
        return;

    ImGuiIO& io = ImGui::GetIO();
    int windowWidth = static_cast<int>(io.DisplaySize.x);
    int windowHeight = static_cast<int>(io.DisplaySize.y);

    ImDrawList* drawList = ImGui::GetBackgroundDrawList();


    for (int i = 1; i < numOfPlayers; i++) 
    {
        uintptr_t playerPtr = *reinterpret_cast<uintptr_t*>(entityListArray + (i * 0x4));
        if (!playerPtr)
            continue;

        Entity* player = reinterpret_cast<Entity*>(playerPtr);


        RenderPlayerESP(player, LocalPlayer, *viewMatrix, windowWidth, windowHeight, drawList);
    }
}

void esp::DrawOutlinedBox(ImDrawList* drawList, const ImVec2& topLeft, const ImVec2& bottomRight, ImU32 color, float thickness)
{
    drawList->AddRect(
        ImVec2(topLeft.x - 1.0f, topLeft.y - 1.0f),
        ImVec2(bottomRight.x + 1.0f, bottomRight.y + 1.0f),
        IM_COL32(0, 0, 0, 220), 0.0f, 0, thickness
    );

    drawList->AddRect(
        ImVec2(topLeft.x + 1.0f, topLeft.y + 1.0f),
        ImVec2(bottomRight.x - 1.0f, bottomRight.y - 1.0f),
        IM_COL32(0, 0, 0, 220), 0.0f, 0, thickness
    );

    drawList->AddRect(topLeft, bottomRight, color, 0.0f, 0, thickness);
}

void esp::DrawLines(Entity* player, const Matrix4x4& viewMatrix, int screenW, int screenH, ImDrawList* drawList)
{
    Vector2 screenFoot;
    if (!WorldToScreen(player->PlayerPos, screenFoot, viewMatrix, screenW, screenH))
        return;

    drawList->AddLine(
        ImVec2(static_cast<float>(screenW) / 2.0f, static_cast<float>(screenH)),
        ImVec2(screenFoot.x, screenFoot.y),
        IM_COL32(255, 255, 255, 255),
        1.5f
    );
}

void esp::RenderPlayerESP(Entity* player, Entity* localPlayer, const Matrix4x4& viewMatrix, int screenW, int screenH, ImDrawList* drawList)
{

    if (!player || player == localPlayer)
        return;

    if (player->PlayerHealth <= 0 || player->PlayerHealth > 100)
        return;

    bool isTeammate = (player->Team == localPlayer->Team);
    if (cfg::TeamCheck && isTeammate)
        return;


    Vector3 headWorldPos = player->HeadPos;
    headWorldPos.z += 0.8f;

    Vector2 screenFoot, screenHead;
    if (!WorldToScreen(player->PlayerPos, screenFoot, viewMatrix, screenW, screenH) ||
        !WorldToScreen(headWorldPos, screenHead, viewMatrix, screenW, screenH))
    {
        return;
    }

    float boxHeight = screenFoot.y - screenHead.y;
    if (boxHeight <= 0) return;

    float boxWidth = boxHeight / 2.0f; 

    ImVec2 topLeft(screenHead.x - (boxWidth / 2.0f), screenHead.y);
    ImVec2 bottomRight(screenHead.x + (boxWidth / 2.0f), screenFoot.y);

    ImU32 boxColor = isTeammate ? IM_COL32(0, 255, 0, 255) : IM_COL32(255, 0, 0, 255);


    if (cfg::BoxEsp)
    {
        DrawOutlinedBox(drawList, topLeft, bottomRight, boxColor);
    }


    if (cfg::HealthBar)
    {
        float healthPercent = player->PlayerHealth / 100.0f;
        float barWidth = 4.0f;
        ImVec2 barTopLeft(topLeft.x - barWidth - 3.0f, topLeft.y);
        ImVec2 barBottomRight(topLeft.x - 3.0f, bottomRight.y);

        drawList->AddRectFilled(barTopLeft, barBottomRight, IM_COL32(0, 0, 0, 180));

        float currentHealthHeight = boxHeight * healthPercent;
        ImVec2 fillTopLeft(barTopLeft.x, bottomRight.y - currentHealthHeight);
        drawList->AddRectFilled(fillTopLeft, barBottomRight, IM_COL32((1.0f - healthPercent) * 255, healthPercent * 255, 0, 255));
    }

    if(cfg::TraceEsp)
    {

        DrawLines(player, viewMatrix, screenW, screenH, drawList);
    }
    
}


