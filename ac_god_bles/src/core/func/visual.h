#pragma once
#include "../../../ext/imgui/imgui.h"
#include "../../sdk/math/math.h"
#include "../../sdk/glob/offsets.h"
#include "../../sdk/glob/struct.h"
#include "../../sdk/glob/config.h"
#include "../../sdk/mem/mem.h"

namespace esp
{
	bool WorldToScreen(Vector3 pos, Vector2& screen, const Matrix4x4& matrix, int windowWidth, int windowHeight);

	void Update();
	void DrawOutlinedBox(ImDrawList* drawList, const ImVec2& topLeft, const ImVec2& bottomRight, ImU32 color, float thickness = 1.5f);
	void RenderPlayerESP(Entity* player, Entity* localPlayer, const Matrix4x4& viewMatrix, int screenW, int screenH, ImDrawList* drawList);
	void DrawLines(Entity* player, const Matrix4x4& viewMatrix, int screenW, int screenH, ImDrawList* drawList);

}