#pragma once
#include <cmath>
#include "../../../ext/imgui/imgui.h"
#include "../../../ext/imgui/imgui_internal.h"
#include "../../sdk/glob/config.h"

enum VisualTheme {
    THEME_NORD = 0,
    THEME_MINIMAL_DARK,
    THEME_EMERALD,
    THEME_GRUVBOX,
    THEME_OCEAN,
    THEME_MONOKAI,
};


namespace menu
{
    inline bool IsOpen = true;
    inline int CurrentTheme = THEME_MINIMAL_DARK;
    void RenderMenu();
    void ApplyTheme(int themeIndex);
    void RenderWindowTrail();


    bool CustomCheckbox(const char* label, bool* v);
    bool CustomSliderFloat(const char* label, float* v, float v_min, float v_max);
}