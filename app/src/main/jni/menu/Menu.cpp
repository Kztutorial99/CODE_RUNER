#include "Menu.hpp"
#include "MenuState.hpp"
#include "Theme.hpp"
#include "DumpSpec.hpp"
#include "imgui.h"
#include <cstring>

static void DumpEntries(const char* category){
    ImGui::TextColored(ProjectAccent(),"DUMP MAPPING");
    ImGui::Separator();
    ImGui::BeginChild("##dump_mapping",ImVec2(0,190),true);
    for(std::size_t i=0;i<DumpSpec::entryCount;i++){
        const auto& e=DumpSpec::entries[i];
        if(std::strcmp(e.category,category)!=0) continue;
        ImGui::Text("%s::%s",e.className,e.member);
        ImGui::SameLine();
        ImGui::TextDisabled("+0x%llX",(unsigned long long)e.offset);
    }
    ImGui::EndChild();
}
static void SideButton(const char* label,int id,int& selected){
    bool active=selected==id;
    ImGui::PushStyleColor(ImGuiCol_Button,active?ImVec4(.16f,.36f,.55f,1):ImVec4(.09f,.12f,.18f,1));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered,ImVec4(.18f,.42f,.64f,1));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive,ImVec4(.22f,.50f,.75f,1));
    if(ImGui::Button(label,ImVec2(ImGui::GetContentRegionAvail().x,42))) selected=id;
    ImGui::PopStyleColor(3);
}
static void RenderSection(const char* title,const char* subtitle,bool* enabled,const char* category){
    ImGui::TextColored(ProjectAccent(),"%s",title);
    ImGui::TextDisabled("%s",subtitle);
    ImGui::Spacing();
    ImGui::Checkbox("Enable section",enabled);
    ImGui::Spacing();
    if(*enabled) DumpEntries(category);
    else {
        ImGui::BeginChild("##empty_state",ImVec2(0,190),true);
        ImGui::SetCursorPosY(ImGui::GetCursorPosY()+60);
        ImGui::TextDisabled("Section is disabled");
        ImGui::EndChild();
    }
}
namespace ProjectMenu {
void Render(){
    static int selected=0;
    ImGui::SetNextWindowSize(ImVec2(760,540),ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowPos(ImVec2(ImGui::GetIO().DisplaySize.x*.5f-380,
                                   ImGui::GetIO().DisplaySize.y*.5f-270),ImGuiCond_FirstUseEver);
    if(!ImGui::Begin("ZLH  //  PROJECT MENU",nullptr,ImGuiWindowFlags_NoCollapse)){ImGui::End();return;}
    ImGui::TextColored(ProjectAccent(),"ZLH CONTROL CENTER");
    ImGui::SameLine(); ImGui::TextDisabled(" | Native UI");
    ImGui::Spacing();
    ImGui::BeginChild("##sidebar",ImVec2(155,0),true);
    SideButton("PLAYER",0,selected); SideButton("CAMERA",1,selected);
    SideButton("WEAPON",2,selected); SideButton("INVENTORY",3,selected);
    SideButton("AIM",4,selected); SideButton("MOVEMENT",5,selected);
    SideButton("ESP",6,selected); SideButton("DEBUG",7,selected);
    ImGui::EndChild(); ImGui::SameLine();
    ImGui::BeginChild("##content",ImVec2(0,0),true);
    switch(selected){
        case 0: RenderSection("PLAYER","Player state and mapped fields",&g_MenuState.player,"Player"); break;
        case 1: RenderSection("CAMERA","Camera settings and mapped fields",&g_MenuState.camera,"Camera"); break;
        case 2: RenderSection("WEAPON","Weapon data and mapped fields",&g_MenuState.weapon,"Weapon"); break;
        case 3: RenderSection("INVENTORY","Inventory state and mapped fields",&g_MenuState.inventory,"Inventory"); break;
        case 4: RenderSection("AIM","Network aim mapping",&g_MenuState.aim,"Network"); break;
        case 5: RenderSection("MOVEMENT","Movement state and mapped fields",&g_MenuState.movement,"Movement"); break;
        case 6: RenderSection("ESP","Body mapping and debug data",&g_MenuState.esp,"Body"); break;
        default:
            ImGui::TextColored(ProjectAccent(),"DEBUG"); ImGui::TextDisabled("Development information");
            ImGui::Spacing(); ImGui::Checkbox("Show dump mapping",&g_MenuState.showOffsets);
            ImGui::Checkbox("Show runtime information",&g_MenuState.showRuntimeInfo);
            ImGui::Separator(); ImGui::Text("Mapped entries: %llu",(unsigned long long)DumpSpec::entryCount); break;
    }
    ImGui::EndChild(); ImGui::End();
}
}
