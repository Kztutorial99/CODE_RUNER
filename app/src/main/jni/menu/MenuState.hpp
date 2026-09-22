#pragma once
struct MenuState {
    bool player=false, camera=false, weapon=false, inventory=false;
    bool aim=false, movement=false, esp=false, debug=false;
    bool showOffsets=false, showRuntimeInfo=false;
};
inline MenuState g_MenuState{};
