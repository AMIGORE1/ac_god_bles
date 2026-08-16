#define IMGUI_DEFINE_MATH_OPERATORS
#include "menu.h"

void menu::ApplyTheme(int themeIndex)
{
    ImGuiStyle& style = ImGui::GetStyle();

    style.WindowPadding = ImVec2(20.0f, 20.0f);
    style.WindowRounding = 12.0f;
    style.ChildRounding = 10.0f;
    style.FramePadding = ImVec2(12.0f, 8.0f);
    style.FrameRounding = 8.0f;
    style.ItemSpacing = ImVec2(10.0f, 10.0f);
    style.ScrollbarSize = 12.0f;
    style.GrabRounding = 8.0f;
    style.TabRounding = 8.0f;
    style.ChildBorderSize = 1.0f;

    style.WindowBorderSize = (themeIndex == THEME_NORD || themeIndex == THEME_MONOKAI) ? 0.0f : 1.0f;

    ImVec4 colorText, colorBg, colorAccent, colorHover, colorChild, colorBorder,
        colorFrame, colorFrameHover, colorFrameActive;

    switch (themeIndex)
    {
    case THEME_NORD:
        colorText = ImVec4(0.88f, 0.91f, 0.95f, 1.00f);
        colorBg = ImVec4(0.18f, 0.22f, 0.27f, 1.00f);
        colorAccent = ImVec4(0.53f, 0.71f, 0.72f, 1.00f);
        colorHover = ImVec4(0.47f, 0.64f, 0.75f, 1.00f);
        colorChild = ImVec4(0.14f, 0.16f, 0.20f, 1.00f);
        colorBorder = ImVec4(0.26f, 0.32f, 0.38f, 0.60f);
        colorFrame = ImVec4(0.23f, 0.28f, 0.34f, 1.00f);
        colorFrameHover = ImVec4(0.28f, 0.35f, 0.41f, 1.00f);
        colorFrameActive = ImVec4(0.35f, 0.43f, 0.50f, 1.00f);
        break;

    case THEME_MINIMAL_DARK:
        colorText = ImVec4(0.90f, 0.90f, 0.92f, 1.00f);
        colorBg = ImVec4(0.12f, 0.12f, 0.14f, 1.00f);
        colorAccent = ImVec4(0.35f, 0.40f, 0.95f, 1.00f);
        colorHover = ImVec4(0.42f, 0.47f, 1.00f, 1.00f);
        colorChild = ImVec4(0.09f, 0.09f, 0.10f, 1.00f);
        colorBorder = ImVec4(0.22f, 0.22f, 0.25f, 1.00f);
        colorFrame = ImVec4(0.18f, 0.18f, 0.20f, 1.00f);
        colorFrameHover = ImVec4(0.24f, 0.24f, 0.27f, 1.00f);
        colorFrameActive = ImVec4(0.28f, 0.28f, 0.31f, 1.00f);
        break;

    case THEME_EMERALD:
        colorText = ImVec4(0.00f, 1.00f, 0.50f, 1.00f);
        colorBg = ImVec4(0.06f, 0.08f, 0.07f, 1.00f);
        colorAccent = ImVec4(0.00f, 0.75f, 0.40f, 1.00f);
        colorHover = ImVec4(0.00f, 0.90f, 0.45f, 1.00f);
        colorChild = ImVec4(0.04f, 0.05f, 0.04f, 1.00f);
        colorBorder = ImVec4(0.00f, 0.50f, 0.25f, 0.40f);
        colorFrame = ImVec4(0.09f, 0.12f, 0.10f, 1.00f);
        colorFrameHover = ImVec4(0.12f, 0.16f, 0.14f, 1.00f);
        colorFrameActive = colorAccent;
        break;


    case THEME_GRUVBOX:
        colorText = ImVec4(0.93f, 0.88f, 0.78f, 1.00f);
        colorBg = ImVec4(0.24f, 0.18f, 0.13f, 1.00f);
        colorAccent = ImVec4(0.98f, 0.65f, 0.25f, 1.00f);
        colorHover = ImVec4(0.85f, 0.45f, 0.15f, 1.00f);
        colorChild = ImVec4(0.20f, 0.15f, 0.10f, 1.00f);
        colorBorder = ImVec4(0.55f, 0.45f, 0.35f, 0.45f);
        colorFrame = ImVec4(0.32f, 0.25f, 0.18f, 1.00f);
        colorFrameHover = ImVec4(0.40f, 0.32f, 0.22f, 1.00f);
        colorFrameActive = ImVec4(0.85f, 0.60f, 0.35f, 1.00f);
        break;


    case THEME_OCEAN:
        colorText = ImVec4(0.85f, 0.93f, 1.00f, 1.00f);
        colorBg = ImVec4(0.08f, 0.14f, 0.22f, 1.00f);
        colorAccent = ImVec4(0.25f, 0.65f, 0.95f, 1.00f);
        colorHover = ImVec4(0.35f, 0.80f, 1.00f, 1.00f);
        colorChild = ImVec4(0.06f, 0.11f, 0.18f, 1.00f);
        colorBorder = ImVec4(0.20f, 0.45f, 0.75f, 0.40f);
        colorFrame = ImVec4(0.12f, 0.20f, 0.30f, 1.00f);
        colorFrameHover = ImVec4(0.18f, 0.30f, 0.45f, 1.00f);
        colorFrameActive = colorAccent;
        break;

    case THEME_MONOKAI:
        colorText = ImVec4(0.95f, 0.96f, 0.95f, 1.00f);
        colorBg = ImVec4(0.16f, 0.15f, 0.14f, 1.00f);
        colorAccent = ImVec4(0.98f, 0.70f, 0.00f, 1.00f);
        colorHover = ImVec4(0.60f, 0.85f, 0.25f, 1.00f);
        colorChild = ImVec4(0.13f, 0.12f, 0.11f, 1.00f);
        colorBorder = ImVec4(0.45f, 0.45f, 0.40f, 0.40f);
        colorFrame = ImVec4(0.22f, 0.21f, 0.20f, 1.00f);
        colorFrameHover = ImVec4(0.30f, 0.29f, 0.28f, 1.00f);
        colorFrameActive = ImVec4(0.98f, 0.70f, 0.00f, 1.00f);
        break;

    }

    style.Colors[ImGuiCol_Text] = colorText;
    style.Colors[ImGuiCol_WindowBg] = colorBg;
    style.Colors[ImGuiCol_ChildBg] = colorChild;
    style.Colors[ImGuiCol_PopupBg] = colorBg;
    style.Colors[ImGuiCol_Border] = colorBorder;
    style.Colors[ImGuiCol_FrameBg] = colorFrame;
    style.Colors[ImGuiCol_FrameBgHovered] = colorFrameHover;
    style.Colors[ImGuiCol_FrameBgActive] = colorFrameActive;
    style.Colors[ImGuiCol_CheckMark] = colorAccent;
    style.Colors[ImGuiCol_SliderGrab] = colorAccent;
    style.Colors[ImGuiCol_SliderGrabActive] = colorHover;

    style.Colors[ImGuiCol_Button] = (themeIndex == THEME_NORD || themeIndex == THEME_MONOKAI)
        ? ImVec4(0.90f, 0.90f, 0.92f, 1.00f) : colorFrame;

    style.Colors[ImGuiCol_ButtonHovered] = colorHover;
    style.Colors[ImGuiCol_ButtonActive] = colorAccent;

    style.Colors[ImGuiCol_Header] = colorFrame;
    style.Colors[ImGuiCol_HeaderHovered] = colorHover;
    style.Colors[ImGuiCol_HeaderActive] = colorAccent;

    style.Colors[ImGuiCol_Tab] = colorFrame;
    style.Colors[ImGuiCol_TabHovered] = colorHover;
    style.Colors[ImGuiCol_TabActive] = colorAccent;
}

void menu::RenderWindowTrail()
{
    ImGuiStyle& style = ImGui::GetStyle();
    ImVec2 current_pos = ImGui::GetWindowPos();
    ImVec2 current_size = ImGui::GetWindowSize();

    const int TRAIL_SIZE = 15;
    static ImVec2 trail_positions[TRAIL_SIZE];
    static bool is_trail_init = false;

    if (!is_trail_init) {
        for (int i = 0; i < TRAIL_SIZE; i++)
            trail_positions[i] = current_pos;
        is_trail_init = true;
    }

    for (int i = TRAIL_SIZE - 1; i > 0; i--)
        trail_positions[i] = trail_positions[i - 1];
    trail_positions[0] = current_pos;

    ImDrawList* bg_draw = ImGui::GetBackgroundDrawList();
    for (int i = 1; i < TRAIL_SIZE; i++) {
        float alpha_factor = (1.0f - ((float)i / (float)TRAIL_SIZE)) * 0.25f;
        ImVec4 col_vec = ImGui::GetStyleColorVec4(ImGuiCol_WindowBg);
        col_vec.w = alpha_factor;

        ImVec2 p_min = trail_positions[i];
        ImVec2 p_max = ImVec2(trail_positions[i].x + current_size.x, trail_positions[i].y + current_size.y);

        bg_draw->AddRectFilled(
            p_min,
            p_max,
            ImGui::ColorConvertFloat4ToU32(col_vec),
            style.WindowRounding
        );
    }
}

bool menu::CustomCheckbox(const char* label, bool* v)
{
    ImGuiWindow* window = ImGui::GetCurrentWindow();
    if (window->SkipItems)
        return false;

    ImGuiContext& g = *GImGui;
    const ImGuiStyle& style = g.Style;
    const ImGuiID id = window->GetID(label);
    const ImVec2 label_size = ImGui::CalcTextSize(label, NULL, true);

    const float base_height = label_size.y + style.FramePadding.y * 2.0f;
    const float base_width = base_height * 2.0f;
    const ImRect check_bb(window->DC.CursorPos, window->DC.CursorPos + ImVec2(base_width, base_height));

    ImGui::ItemSize(check_bb, style.FramePadding.y);

    ImRect total_bb = check_bb;
    if (label_size.x > 0)
        ImGui::SameLine(0, style.ItemInnerSpacing.x);

    const ImRect text_bb(window->DC.CursorPos + ImVec2(0, style.FramePadding.y), window->DC.CursorPos + ImVec2(0, style.FramePadding.y) + label_size);
    if (label_size.x > 0)
    {
        ImGui::ItemSize(ImVec2(text_bb.GetWidth(), check_bb.GetHeight()), style.FramePadding.y);
        total_bb = ImRect(ImMin(check_bb.Min, text_bb.Min), ImMax(check_bb.Max, text_bb.Max));
    }

    if (!ImGui::ItemAdd(total_bb, id))
        return false;

    bool hovered, held;
    bool pressed = ImGui::ButtonBehavior(total_bb, id, &hovered, &held);
    if (pressed)
        *v = !(*v);

    ImDrawList* draw_list = window->DrawList;

    float shrink_h = check_bb.GetHeight() * 0.12f;
    float shrink_w = check_bb.GetWidth() * 0.12f;
    ImRect render_bb(check_bb.Min + ImVec2(shrink_w, shrink_h), check_bb.Max - ImVec2(shrink_w, shrink_h));

    float height = render_bb.GetHeight();
    float width = render_bb.GetWidth();
    float rounding = height / 2.0f;

    ImU32 bg_col;
    if (held)
    {
        bg_col = ImGui::GetColorU32(*v ? ImGuiCol_SliderGrabActive : ImGuiCol_FrameBgActive);
    }
    else if (hovered)
    {
        bg_col = ImGui::GetColorU32(*v ? ImGuiCol_SliderGrabActive : ImGuiCol_FrameBgHovered);
    }
    else
    {
        bg_col = ImGui::GetColorU32(*v ? ImGuiCol_CheckMark : ImGuiCol_FrameBg);
    }

    draw_list->AddRectFilled(render_bb.Min, render_bb.Max, bg_col, rounding);

    float knob_radius = (height / 2.0f) * 0.85f;
    float knob_pos_x_off = render_bb.Min.x + rounding;
    float knob_pos_x_on = render_bb.Max.x - rounding;
    float current_knob_x = *v ? knob_pos_x_on : knob_pos_x_off;

    ImU32 knob_col = *v ? IM_COL32(255, 255, 255, 255) : ImGui::GetColorU32(ImGuiCol_Text);

    draw_list->AddCircleFilled(ImVec2(current_knob_x, render_bb.GetCenter().y), knob_radius, knob_col);

    if (g.LogEnabled)
        ImGui::LogRenderedText(&text_bb.Min, *v ? "[X]" : "[]");
    if (label_size.x > 0.0f)
        ImGui::RenderText(text_bb.Min, label);

    return pressed;
}

bool menu::CustomSliderFloat(const char* label, float* v, float v_min, float v_max)
{
    ImGuiContext& g = *GImGui;
    ImGuiWindow* window = ImGui::GetCurrentWindow();
    if (window->SkipItems) return false;

    const ImGuiStyle& style = g.Style;
    const ImGuiID id = window->GetID(label);
    const float w = ImGui::GetContentRegionAvail().x * 0.4f;
    const float capsule_h = 15.0f;

    const ImRect frame_bb(window->DC.CursorPos, window->DC.CursorPos + ImVec2(w, capsule_h));

    const ImVec2 label_size = ImGui::CalcTextSize(label, NULL, true);
    const ImRect total_bb(frame_bb.Min, frame_bb.Max + ImVec2(label_size.x > 0.0f ? style.ItemInnerSpacing.x + label_size.x : 0.0f, 0.0f));

    if (!ImGui::ItemAdd(total_bb, id, &frame_bb))
    {
        ImGui::ItemSize(total_bb, style.FramePadding.y);
        return false;
    }
    ImGui::ItemSize(total_bb, style.FramePadding.y);

    bool hovered, held;
    ImGui::ButtonBehavior(frame_bb, id, &hovered, &held);

    if (held)
    {
        float clicked_t = ImClamp((g.IO.MousePos.x - frame_bb.Min.x) / frame_bb.GetWidth(), 0.0f, 1.0f);
        *v = ImLerp(v_min, v_max, clicked_t);
    }

    ImDrawList* draw_list = window->DrawList;
    float rounding = capsule_h / 2.0f;

    draw_list->AddRectFilled(frame_bb.Min, frame_bb.Max, ImGui::GetColorU32(ImGuiCol_FrameBg), rounding);


    float t = ImClamp((*v - v_min) / (v_max - v_min), 0.0f, 1.0f);
    if (t > 0.0f)
    {
        float fill_width = ImLerp(0.0f, frame_bb.GetWidth(), t);
        draw_list->PushClipRect(frame_bb.Min, ImVec2(frame_bb.Min.x + fill_width, frame_bb.Max.y), true);
        draw_list->AddRectFilled(frame_bb.Min, frame_bb.Max, ImGui::GetColorU32(held ? ImGuiCol_SliderGrabActive : ImGuiCol_SliderGrab), rounding);
        draw_list->PopClipRect();
    }

    if (label_size.x > 0.0f)
    {
        ImGui::RenderText(ImVec2(frame_bb.Max.x + style.ItemInnerSpacing.x, frame_bb.Min.y + (capsule_h - label_size.y) * 0.5f), label);
    }

    return held;
}


void menu::RenderMenu()
{
    ImGui::SetNextWindowSize({ 460, 500 }, ImGuiCond_Once);
    ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse;

    if (ImGui::Begin("Agyzak", &IsOpen, window_flags))
    {
        RenderWindowTrail();

        CustomCheckbox("BoxEsp", &cfg::BoxEsp);
        CustomCheckbox("TeamCheck", &cfg::TeamCheck);
        CustomCheckbox("HealthBar", &cfg::HealthBar);
        CustomCheckbox("DrawLines", &cfg::TraceEsp);
        CustomCheckbox("AimBot", &cfg::AimBot);

        static const char* themeNames[] = { "Nordic Frost", "Clean Dark", "Emerald", "Gruvbox Dark", "Ocean Depth", "Monokai Pro" };
        if (ImGui::Combo("##ThemeSelector", &CurrentTheme, themeNames, IM_ARRAYSIZE(themeNames))) {
            ApplyTheme(CurrentTheme);
        }
    }
    ImGui::End();
}