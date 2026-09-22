#pragma once
#include <cstddef>
#include <cstdint>
namespace DumpSpec {
struct Entry { const char* category; const char* className; const char* member; uintptr_t offset; };
inline constexpr Entry entries[] = {
 {"Player","ZLH.Player","HP",0x40},
 {"Player","ZLH.Player","IsDeath",0x00},
 {"Player","ZLH.Player","IsGod",0x00},
 {"Network","ZLH.NetworkPlayer","AimRot",0x88},
 {"Camera","ZLH.CameraManager","cameraCustomFOV",0xA8},
 {"Camera","ZLH.CameraManager","cameraDefaultFOV",0xAC},
 {"Camera","ZLH.CameraManager","SightAimAssist",0xCC},
 {"Camera","ZLH.CameraManager","HipAimAssist",0xCD},
 {"Camera","ZLH.CameraManager","IsOpenCameraRecoil",0x138},
 {"Weapon","ZLH.WeaponDataZLH","fireScatterFactor",0xA4},
 {"Weapon","ZLH.WeaponDataZLH","fireDuration",0xA8},
 {"Weapon","ZLH.WeaponDataZLH","ammo",0xA0},
 {"Inventory","ZLH.InventoryManager","CurrEquipSlot",0x30},
 {"Inventory","ZLH.InventoryManager","Items",0x38},
 {"Movement","ZLH.UserActionHandler","IsCanRun",0xC8},
 {"Movement","ZLH.UserActionHandler","IsCanSlide",0xC9},
 {"Movement","ZLH.UserActionHandler","jumpAcc",0xC4},
 {"Body","ZLH.Body","Root",0x20},
 {"Body","ZLH.Body","headBone",0x48}
};
inline constexpr std::size_t entryCount=sizeof(entries)/sizeof(entries[0]);
}
