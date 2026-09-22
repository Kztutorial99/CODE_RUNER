#pragma once
#include "imgui.h"
inline void ApplyProjectTheme() {
    ImGui::StyleColorsDark();
    ImGuiStyle& s=ImGui::GetStyle();
    s.WindowRounding=8.0f; s.ChildRounding=6.0f; s.FrameRounding=5.0f;
    s.PopupRounding=6.0f; s.ScrollbarRounding=6.0f; s.GrabRounding=5.0f;
    s.WindowPadding=ImVec2(14,14); s.FramePadding=ImVec2(10,7);
    s.ItemSpacing=ImVec2(10,9);
}
