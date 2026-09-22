#pragma once
#include "imgui.h"
inline void ApplyProjectTheme() {
    ImGuiStyle& s=ImGui::GetStyle();
    s.WindowPadding=ImVec2(18,18); s.FramePadding=ImVec2(12,9);
    s.ItemSpacing=ImVec2(10,9); s.ItemInnerSpacing=ImVec2(8,6);
    s.WindowRounding=18; s.ChildRounding=14; s.FrameRounding=10;
    s.PopupRounding=12; s.ScrollbarRounding=10; s.GrabRounding=10;
    s.TabRounding=10; s.WindowBorderSize=1; s.ChildBorderSize=1;
    s.ScrollbarSize=7; s.GrabMinSize=18;
    ImVec4* c=s.Colors;
    c[ImGuiCol_Text]=ImVec4(.94f,.95f,.98f,1); c[ImGuiCol_TextDisabled]=ImVec4(.55f,.58f,.65f,1);
    c[ImGuiCol_WindowBg]=ImVec4(.055f,.065f,.09f,.97f); c[ImGuiCol_ChildBg]=ImVec4(.075f,.085f,.115f,.94f);
    c[ImGuiCol_PopupBg]=ImVec4(.065f,.075f,.105f,.98f); c[ImGuiCol_Border]=ImVec4(.22f,.28f,.40f,.55f);
    c[ImGuiCol_FrameBg]=ImVec4(.11f,.13f,.18f,1); c[ImGuiCol_FrameBgHovered]=ImVec4(.15f,.18f,.25f,1);
    c[ImGuiCol_FrameBgActive]=ImVec4(.19f,.22f,.31f,1); c[ImGuiCol_TitleBg]=ImVec4(.045f,.055f,.08f,1);
    c[ImGuiCol_TitleBgActive]=ImVec4(.06f,.075f,.11f,1);
    c[ImGuiCol_Button]=ImVec4(.10f,.13f,.19f,1); c[ImGuiCol_ButtonHovered]=ImVec4(.16f,.22f,.32f,1);
    c[ImGuiCol_ButtonActive]=ImVec4(.20f,.28f,.40f,1); c[ImGuiCol_CheckMark]=ImVec4(.35f,.75f,1,1);
    c[ImGuiCol_Tab]=ImVec4(.08f,.10f,.15f,1); c[ImGuiCol_TabHovered]=ImVec4(.18f,.30f,.46f,1);
    c[ImGuiCol_TabActive]=ImVec4(.14f,.24f,.38f,1); c[ImGuiCol_Separator]=ImVec4(.20f,.25f,.34f,.65f);
}
inline ImVec4 ProjectAccent(){ return ImVec4(.28f,.72f,1,1); }
