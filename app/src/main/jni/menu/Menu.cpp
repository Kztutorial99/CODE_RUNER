#include "Menu.hpp"
#include "MenuState.hpp"
#include "Theme.hpp"
#include "DumpSpec.hpp"
#include "imgui.h"
#include <cstring>

static void DumpEntries(const char* category) {
    ImGui::Separator();
    ImGui::TextUnformatted("Dump mapping");
    ImGui::BeginChild("##dump_mapping", ImVec2(0,170), true);
    for(std::size_t i=0;i<DumpSpec::entryCount;i++) {
        const auto& e=DumpSpec::entries[i];
        if(std::strcmp(e.category,category)!=0) continue;
        ImGui::Text("%s::%s  +0x%llX",e.className,e.member,
                    static_cast<unsigned long long>(e.offset));
    }
    ImGui::EndChild();
}

namespace ProjectMenu {
void Render() {
    ApplyProjectTheme();
    ImGui::SetNextWindowSize(ImVec2(620,520),ImGuiCond_FirstUseEver);
    if(!ImGui::Begin("ZLH Project Menu")) { ImGui::End(); return; }

    if(ImGui::BeginTabBar("##project_tabs")) {
        if(ImGui::BeginTabItem("Player")) {
            ImGui::Checkbox("Enable section",&g_MenuState.player);
            if(g_MenuState.player) DumpEntries("Player");
            ImGui::EndTabItem();
        }
        if(ImGui::BeginTabItem("Camera")) {
            ImGui::Checkbox("Enable section",&g_MenuState.camera);
            if(g_MenuState.camera) DumpEntries("Camera");
            ImGui::EndTabItem();
        }
        if(ImGui::BeginTabItem("Weapon")) {
            ImGui::Checkbox("Enable section",&g_MenuState.weapon);
            if(g_MenuState.weapon) DumpEntries("Weapon");
            ImGui::EndTabItem();
        }
        if(ImGui::BeginTabItem("Inventory")) {
            ImGui::Checkbox("Enable section",&g_MenuState.inventory);
            if(g_MenuState.inventory) DumpEntries("Inventory");
            ImGui::EndTabItem();
        }
        if(ImGui::BeginTabItem("Aim")) {
            ImGui::Checkbox("Enable section",&g_MenuState.aim);
            if(g_MenuState.aim) DumpEntries("Network");
            ImGui::EndTabItem();
        }
        if(ImGui::BeginTabItem("Movement")) {
            ImGui::Checkbox("Enable section",&g_MenuState.movement);
            if(g_MenuState.movement) DumpEntries("Movement");
            ImGui::EndTabItem();
        }
        if(ImGui::BeginTabItem("ESP")) {
            ImGui::Checkbox("Enable section",&g_MenuState.esp);
            if(g_MenuState.esp) DumpEntries("Body");
            ImGui::EndTabItem();
        }
        if(ImGui::BeginTabItem("Debug")) {
            ImGui::Checkbox("Show dump mapping",&g_MenuState.showOffsets);
            ImGui::Checkbox("Show runtime information",&g_MenuState.showRuntimeInfo);
            if(g_MenuState.showOffsets) {
                ImGui::Separator();
                ImGui::Text("Mapped entries: %llu",
                    static_cast<unsigned long long>(DumpSpec::entryCount));
            }
            ImGui::EndTabItem();
        }
        ImGui::EndTabBar();
    }
    ImGui::End();
}
}
