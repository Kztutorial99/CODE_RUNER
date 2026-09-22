//CREDIT CROSS MODS
//CREDIT CROSS MODS
//CREDIT CROSS MODS
//CREDIT CROSS MODS
//CREDIT CROSS MODS
//CREDIT CROSS MODS
//CREDIT CROSS MODS
//CREDIT CROSS MODS
//CREDIT CROSS MODS
//CREDIT CROSS MODS
//CREDIT CROSS MODS
//CREDIT CROSS MODS
//CREDIT CROSS MODS
//CREDIT CROSS MODS
#include <android/log.h>
#include <unistd.h>
#include <thread>
#include <limits>
#include <ctime>
#include <xdl.h>
#include <KittyUtils.h>
#include <KittyMemory.h>
#include <Il2Cpp.h>
#include <SubstrateHook.h>
#include <CydiaSubstrate.h>
#include "ADITYA MODS/Gui.hpp"
#include <ADITYA MODS/main.h>
#include "menu/Menu.hpp"
#include "fonts/FontAwesome6_solid.h"
#include "Toggle.h"

#define ICON_FA_CROSSHAIRS "\xef\x81\x9b"
#define ICON_FA_EYE "\xef\x81\xae"
#define ICON_FA_FIRE "\xef\x81\xad"
#define ICON_FA_USER "\xef\x80\x87"

static float currentWidth = 650.0f;
static float currentHeight = 450.0f;
static int currentTab = 0; 
void hack_thread();
bool ImGuiOK = true;

void OpenURL(Il2CppString* url) {
    if (!url) return; 
    typedef void (*Application_OpenURL_ftn)(Il2CppString*);
    static Application_OpenURL_ftn open_url = nullptr;
    
    if (!open_url) {
        void* methodOffset = Il2CppGetMethodOffset(
            OBFUSCATE("UnityEngine.CoreModule.dll"), 
            OBFUSCATE("UnityEngine"), 
            OBFUSCATE("Application"), 
            OBFUSCATE("OpenURL"), 
            1
        );
        if (methodOffset) {
            open_url = (Application_OpenURL_ftn)methodOffset;
        }
    }
    
    if (open_url != nullptr) {
        open_url(url);
    }
}
static int titleIndex = 0;
static const char* menuTitles[] = {
"BD HACKER OFFlClAl" 
};

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    jvm = vm;
    std::thread(hack_thread).detach();
    return JNI_VERSION_1_6;
}

// ==========================================
// 🎨 NEW MODERN DARK AMBER THEME
// ==========================================
void SetModernPremiumTheme() {
ImGuiStyle* style = &ImGui::GetStyle();
style->ScrollbarSize     = 4.0f;  // mặc định thường 14–16, giảm xuống cho nhỏ
style->WindowRounding    = 15.0f; // Bo góc cửa sổ
style->FrameRounding     = 12.0f; // Bo góc nút, checkbox
style->GrabRounding      = 10.0f;
style->ScrollbarRounding = 8.0f;
style->WindowPadding     = ImVec2(16, 16);
style->FramePadding      = ImVec2(12, 6);   // Tăng kích thước nút, checkbox
style->ItemSpacing       = ImVec2(8, 6);
    
	ImVec4* colors = ImGui::GetStyle().Colors;
	
	colors[ImGuiCol_Text]                   = ImVec4(0.86f, 0.86f, 0.86f, 1.00f); // Màu chữ
	colors[ImGuiCol_TextDisabled]           = ImVec4(0.60f, 0.60f, 0.60f, 1.00f); // Màu chữ vô hiệu hóa
	colors[ImGuiCol_WindowBg]               = ImVec4(0.16f, 0.16f, 0.16f, 0.95f); // Màu nền cửa sổ
	colors[ImGuiCol_ChildBg]                = ImVec4(0.18f, 0.18f, 0.18f, 0.58f); // Màu nền bên trong Child window
	colors[ImGuiCol_PopupBg]                = ImVec4(0.08f, 0.08f, 0.08f, 0.94f); // Màu nền của Popup window
	colors[ImGuiCol_Border]                 = ImVec4(0.08f, 0.08f, 0.08f, 0.40f); // Màu đường viền
	colors[ImGuiCol_BorderShadow]           = ImVec4(0.00f, 0.00f, 0.00f, 0.00f); // Màu bóng đổ đường viền
	colors[ImGuiCol_FrameBg]                = ImVec4(0.27f, 0.27f, 0.27f, 0.54f); // Màu nền Frame
	colors[ImGuiCol_FrameBgHovered]         = ImVec4(0.47f, 0.47f, 0.47f, 0.40f); // Màu nền Frame khi hover
	colors[ImGuiCol_FrameBgActive]          = ImVec4(0.40f, 0.40f, 0.40f, 0.67f); // Màu nền Frame khi active
	colors[ImGuiCol_TitleBg]                = ImVec4(0.04f, 0.04f, 0.04f, 1.00f); // Màu nền tiêu đề cửa sổ
	colors[ImGuiCol_TitleBgActive]          = ImVec4(0.16f, 0.16f, 0.16f, 1.00f); // Màu nền tiêu đề cửa sổ khi active
	colors[ImGuiCol_TitleBgCollapsed]       = ImVec4(0.00f, 0.00f, 0.00f, 0.51f); // Màu nền tiêu đề cửa sổ khi bị thu gọn
	colors[ImGuiCol_MenuBarBg]              = ImVec4(0.14f, 0.14f, 0.14f, 1.00f); // Màu nền của MenuBar
	colors[ImGuiCol_ScrollbarBg]            = ImVec4(0.02f, 0.02f, 0.02f, 0.53f); // Màu nền của thanh cuộn
	colors[ImGuiCol_ScrollbarGrab]          = ImVec4(0.31f, 0.31f, 0.31f, 1.00f); // Màu của cần cẩu thanh cuộn
	colors[ImGuiCol_ScrollbarGrabHovered]   = ImVec4(0.41f, 0.41f, 0.41f, 1.00f); // Màu của cần cẩu thanh cuộn khi hover
	colors[ImGuiCol_ScrollbarGrabActive]    = ImVec4(0.51f, 0.51f, 0.51f, 1.00f); // Màu của cần cẩu thanh cuộn khi active
	colors[ImGuiCol_CheckMark]              = ImVec4(0.26f, 0.59f, 0.98f, 1.00f); // Màu của dấu check
	colors[ImGuiCol_SliderGrab]             = ImVec4(0.24f, 0.52f, 0.88f, 1.00f); // Màu của cần cẩu thanh trượt
	colors[ImGuiCol_SliderGrabActive]       = ImVec4(0.26f, 0.59f, 0.98f, 1.00f); // Màu của cần cẩu thanh trượt khi active
	colors[ImGuiCol_Button]                 = ImVec4(0.26f, 0.59f, 0.98f, 0.40f); // Màu của nút
	colors[ImGuiCol_ButtonHovered]          = ImVec4(0.26f, 0.59f, 0.98f, 1.00f); // Màu của nút khi hover
	colors[ImGuiCol_ButtonActive]           = ImVec4(0.06f, 0.53f, 0.98f, 1.00f); // Màu của nút khi active
	colors[ImGuiCol_Header]                 = ImVec4(0.26f, 0.59f, 0.98f, 0.31f); // Màu của tiêu đề
	colors[ImGuiCol_HeaderHovered]          = ImVec4(0.26f, 0.59f, 0.98f, 0.80f); // Màu của tiêu đề khi hover
	colors[ImGuiCol_HeaderActive]           = ImVec4(0.26f, 0.59f, 0.98f, 1.00f); // Màu của tiêu đề khi active
	colors[ImGuiCol_Separator]              = ImVec4(0.43f, 0.43f, 0.50f, 0.50f); // Màu của dấu phân cách
	colors[ImGuiCol_SeparatorHovered]       = ImVec4(0.10f, 0.40f, 0.75f, 0.78f); // Màu của dấu phân cách khi hover
	colors[ImGuiCol_SeparatorActive]        = ImVec4(0.10f, 0.40f, 0.75f, 1.00f); // Màu của dấu phân cách khi active
	colors[ImGuiCol_ResizeGrip]             = ImVec4(0.26f, 0.59f, 0.98f, 0.25f); // Màu của khớp co giãn
	colors[ImGuiCol_ResizeGripHovered]      = ImVec4(0.26f, 0.59f, 0.98f, 0.67f); // Màu của khớp co giãn khi hover
	colors[ImGuiCol_ResizeGripActive]       = ImVec4(0.26f, 0.59f, 0.98f, 0.95f); // Màu của khớp co giãn khi active
	colors[ImGuiCol_Tab]                    = ImVec4(0.18f, 0.18f, 0.18f, 0.86f); // Màu của tab
	colors[ImGuiCol_TabHovered]             = ImVec4(0.26f, 0.59f, 0.98f, 0.80f); // Màu của tab khi hover
	colors[ImGuiCol_TabActive]              = ImVec4(0.20f, 0.20f, 0.20f, 1.00f); // Màu của tab khi active
	colors[ImGuiCol_TabUnfocused]           = ImVec4(0.06f, 0.06f, 0.06f, 0.97f); // Màu của tab khi không focus
	colors[ImGuiCol_TabUnfocusedActive]     = ImVec4(0.13f, 0.13f, 0.13f, 1.00f); // Màu của tab khi không focus nhưng active
	colors[ImGuiCol_PlotLines]              = ImVec4(0.61f, 0.61f, 0.61f, 1.00f); // Màu của đồ thị dạng line
	colors[ImGuiCol_PlotLinesHovered]       = ImVec4(0.61f, 0.61f, 0.61f, 1.00f); // Màu của đồ thị dạng line khi hover
	colors[ImGuiCol_PlotHistogram]          = ImVec4(0.90f, 0.70f, 0.00f, 1.00f); // Màu của đồ thị dạng histogram
	colors[ImGuiCol_PlotHistogramHovered]   = ImVec4(1.00f, 0.60f, 0.00f, 1.00f); // Màu của đồ thị dạng histogram khi hover
	colors[ImGuiCol_TextSelectedBg]         = ImVec4(0.26f, 0.59f, 0.98f, 0.35f); // Màu nền khi chọn văn bản
	colors[ImGuiCol_DragDropTarget]         = ImVec4(0.41f, 0.41f, 0.41f, 1.00f); // Màu của Drag and Drop target
	colors[ImGuiCol_NavHighlight]           = ImVec4(0.26f, 0.59f, 0.98f, 1.00f); // Màu highlight trong navigation
	colors[ImGuiCol_NavWindowingHighlight]  = ImVec4(1.00f, 1.00f, 1.00f, 0.70f); // Màu highlight trong navigation khi windowing
	colors[ImGuiCol_NavWindowingDimBg]      = ImVec4(0.80f, 0.80f, 0.80f, 0.20f); // Màu nền khi windowing
	colors[ImGuiCol_ModalWindowDimBg]       = ImVec4(0.80f, 0.80f, 0.80f, 0.35f); // Màu nền khi modal 
}

ImVec4 ThemeAccent = ImVec4(0.83f, 0.56f, 0.22f, 1.00f); // Amber Gold

// ==========================================
// 🔘 NEW SLIDER CUSTOM DESIGN
// ==========================================
bool ManuSlider(const char* label, float* value, float min, float max, const char* format = "%.0f") {
    if (!value) return false;
    ImGui::Text("%s: ", label);
    ImGui::SameLine();
    ImGui::TextColored(ThemeAccent, format, *value);

    float sliderWidth = ImGui::GetContentRegionAvail().x - 10.0f;  
    ImVec2 pos = ImGui::GetCursorScreenPos();  
    ImDrawList* draw = ImGui::GetWindowDrawList();  
    if (!draw) return false;
    
    ImGui::InvisibleButton(label, ImVec2(sliderWidth, 22));  
    bool changed = false;  
    if (ImGui::IsItemActive()) {  
        float t = (ImGui::GetIO().MousePos.x - pos.x) / sliderWidth;  
        t = ImClamp(t, 0.f, 1.f);  
        *value = min + (max - min) * t;  
        changed = true;  
    }  
    
    float fraction = (*value - min) / (max - min);
    float radius = 11.f; 
    float knobX = pos.x + radius + (sliderWidth - radius * 2) * fraction;  
    float centerY = pos.y + 11.f;

    draw->AddRectFilled(ImVec2(pos.x, pos.y + 8), ImVec2(pos.x + sliderWidth, pos.y + 14), ImColor(38, 38, 42, 255), 10.0f);  
    ImU32 accent_col = ImGui::ColorConvertFloat4ToU32(ThemeAccent);
    draw->AddRectFilled(ImVec2(pos.x, pos.y + 8), ImVec2(knobX, pos.y + 14), accent_col, 10.0f);
    draw->AddCircleFilled(ImVec2(knobX, centerY), 6.0f, ImColor(255, 255, 255, 255), 32);
    
    return changed;
}

// ==========================================
// 🔄 NEW CUSTOM TOGGLE SWITCH (YADAVJEE REBRANDED)
// ==========================================
bool YADAVJEE(const char* label, bool* v) {
    if (!v) return false; 
    ImGui::PushID(label);

    static float knob_anim = 0.0f;
    float width = 75.0f;
    float height = 30.0f;
    float knob_radius = 12.0f;

    ImVec2 p = ImGui::GetCursorScreenPos();
    ImDrawList* draw_list = ImGui::GetWindowDrawList();
    if (!draw_list) { ImGui::PopID(); return false; }

    ImU32 bgColor = *v ? ImGui::ColorConvertFloat4ToU32(ThemeAccent) : IM_COL32(50, 50, 55, 255);
    ImU32 knobColor = IM_COL32(255, 255, 255, 255);

    draw_list->AddRectFilled(p, ImVec2(p.x + width, p.y + height), bgColor, height * 0.5f);

    float target = *v ? 1.0f : 0.0f;
    knob_anim = ImLerp(knob_anim, target, 0.15f); 

    float knob_x = ImLerp(p.x + knob_radius + 4, p.x + width - knob_radius - 4, knob_anim);
    ImVec2 knob_center = ImVec2(knob_x, p.y + height / 2);

    draw_list->AddCircleFilled(knob_center, knob_radius, knobColor, 32);

    ImGui::InvisibleButton("##switch", ImVec2(width, height));
    if (ImGui::IsItemClicked())
        *v = !*v;

    ImGui::SameLine();
    ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 4);
    ImGui::Text("%s", label);

    ImGui::PopID();
    return *v;
}

// ==========================================// 🗂️ NEW NAVIGATION TAB BUTTON
// ==========================================
static bool LeftNavButton(const char* label, const char* icon, bool selected, ImVec2 size = ImVec2(0, 55)) {
    if (size.x <= 0) size.x = ImGui::GetContentRegionAvail().x;
    ImDrawList* dl = ImGui::GetWindowDrawList();
    if (!dl) return false;
    ImVec2 pos = ImGui::GetCursorScreenPos();
    ImRect bb(pos, ImVec2(pos.x + size.x, pos.y + size.y));

    ImU32 bg_col = selected ? ImGui::ColorConvertFloat4ToU32(ThemeAccent) : IM_COL32(32, 32, 36, 255);
    dl->AddRectFilled(bb.Min, bb.Max, bg_col, 6.0f);

    ImVec2 icon_pos(pos.x + 14, pos.y + 18);
    ImVec2 text_pos(icon_pos.x + 28, pos.y + 18);

    ImU32 text_col = selected ? IM_COL32(15, 15, 15, 255) : IM_COL32(230, 230, 230, 255);

    dl->AddText(icon_pos, text_col, icon);
    dl->AddText(text_pos, text_col, label);

    ImGui::InvisibleButton(label, size);
    return ImGui::IsItemClicked();
}

uintptr_t il2cpp_base = 0;
void *getRealAddr(ulong offset) {
    return reinterpret_cast<void*>(il2cpp_base + offset);
};

bool showSpeedWidget = false;

inline EGLBoolean (*old_eglSwapBuffers)(EGLDisplay dpy, EGLSurface surface);

inline EGLBoolean hook_eglSwapBuffers(EGLDisplay dpy, EGLSurface surface) {
    eglQuerySurface(dpy, surface, EGL_WIDTH, &g_GlWidth);
    eglQuerySurface(dpy, surface, EGL_HEIGHT, &g_GlHeight);

    if (!g_IsSetup) {
        prevWidth = g_GlWidth;
        prevHeight = g_GlHeight;
        SetupImgui();
        g_IsSetup = true;
    }

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplAndroid_NewFrame(g_GlWidth, g_GlHeight);
    ImGui::NewFrame();

    ProjectMenu::Render();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    return old_eglSwapBuffers(dpy, surface);
}

static uintptr_t libBase;

inline void StartGUI() {
    void *ptr_eglSwapBuffer = DobbySymbolResolver("/system/lib/libEGL.so", "eglSwapBuffers");
    if (ptr_eglSwapBuffer != nullptr) {
        DobbyHook((void *)ptr_eglSwapBuffer, (void *)hook_eglSwapBuffers, (void **)&old_eglSwapBuffers);
        LOGD("GUI started successfully");
    }
}

void hack_thread() {
    sleep(5);
    pid_t pid = getpid();
    LOGD("Hack Thread initiated for PID: %i", pid);

    do {
        il2cpp_base = get_module_base(pid, "libil2cpp.so");
        sleep(1);
    } while (il2cpp_base == 0);

    LOGD("libil2cpp.so found at address: 0x%" PRIxPTR, il2cpp_base);
    Il2CppAttach();

    void* m1 = (void*)Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("NewPlayerAnimationSystemComponent"), OBFUSCATE("PlayChangeWeaponAnim"), 2);
    if(m1) DobbyHook(m1, (void*)hook_PlayChangeWeaponAnim, (void**)&orig_PlayChangeWeaponAnim);

    void* m2 = (void*)Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW"), OBFUSCATE("GameFacade"), OBFUSCATE("ClientUsingVersion"), 0);
    if(m2) DobbyHook(m2, (void *)hook_ClientVersion, (void **)&orig_ClientVersion);

    void* m3 = (void*)Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("Player"), OBFUSCATE("get_InSwapWeaponCD"), 0);
    if(m3) DobbyHook(m3, (void *)_get_InSwapWeaponCD, (void **) &get_InSwapWeaponCD);

    void* m4 = (void*)Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("Player"), OBFUSCATE("get_IsFastRunning"), 0);
    if(m4) DobbyHook(m4, (void *)hook_get_IsFastRunning, (void **)&orig_get_IsFastRunning);

    void* m5 = (void*)Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("UGCLevelPointLight"), OBFUSCATE("get_Range"), 0);
    if(m5) DobbyHook(m5, (void*)hook_get_Range, (void**)&orig_get_Range);

    StartGUI();
}


//CREDIT CROSS MODS
//CREDIT CROSS MODS
//CREDIT CROSS MODS
//CREDIT CROSS MODS
//CREDIT CROSS MODS
//CREDIT CROSS MODS
//CREDIT CROSS MODS
//CREDIT CROSS MODS
//CREDIT CROSS MODS
//CREDIT CROSS MODS
//CREDIT CROSS MODS
//CREDIT CROSS MODS
//CREDIT CROSS MODS//CREDIT CROSS MODS
//CREDIT CROSS MODS
//CREDIT CROSS MODS
//CREDIT CROSS MODS
//CREDIT CROSS MODS
//CREDIT CROSS MODS
//CREDIT CROSS MODS
//CREDIT CROSS MODS
//CREDIT CROSS MODS