#ifndef M418DLL_H
#define M418DLL_H

#include "dolphin.h"

typedef void (*M418DllFunc)(void);
typedef s32 (*M418DllRetFunc)(void);
typedef void (*M418DllInFunc)(s32);
typedef s32 (*M418DllInRetFunc)(s32);

typedef struct M418DllUnkStruct {
    M418DllFunc unk0;
    Vec center;
    char unk10[0xC];
    Vec rot;
    char unk28[0xC];
    f32 zoom;
    char unk38[0x4];
    f32 unk3C[3];
    f32 unk48;
} M418DllUnkStruct; // sizeof 0x4C

typedef struct M418DllUnkStruct7 {
    char unk[0x10];
    M418DllFunc unk10;
    M418DllRetFunc unk14;
} M418DllUnkStruct7; // sizeof 0x18

typedef struct M418DllUnkStruct8 {
    M418DllInFunc unk0;
    M418DllInRetFunc unk4;
    s32 unk8;
} M418DllUnkStruct8; // sizeof 0x24

f32 fn_1_A920(f32, f32, f32);
f32 fn_1_A940(f32, f32, f32, f32);
f32 fn_1_AA30(f32, f32, f32, f32);
void fn_1_ABC4(omObjData*, s32, s32, s32, s32);
void fn_1_AD14(omObjData*, s32, s32, s32, s32);
void fn_1_AEDC(M418DllUnkStruct7*, M418DllUnkStruct8**);
s32 fn_1_AF38(M418DllUnkStruct7*);
s32 fn_1_B034(M418DllUnkStruct7*, s32);
s32 fn_1_B0C8(M418DllUnkStruct7*, s32);
void fn_1_B104(M418DllUnkStruct*, Vec, Vec);
void fn_1_B41C(M418DllUnkStruct*);
void fn_1_B458(M418DllUnkStruct*);
void fn_1_BEAC(M418DllUnkStruct*, M418DllUnkStruct*, f32, f32, f32);
void fn_1_CBF8(M418DllUnkStruct*, M418DllUnkStruct*, f32, f32, f32);
void fn_1_DC10(M418DllUnkStruct*, M418DllUnkStruct*, f32, f32, f32);

#endif