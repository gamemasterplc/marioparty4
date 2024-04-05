#include "src/REL/m407dll/m407dll.h"
#include "game/process.h"
#include "game/object.h"
#include "game/gamework_data.h"
#include "game/esprite.h"

void Hu3D3Dto2D(Vec *arg0, s16 arg1, Vec *arg2);
void fn_1_3D28(omObjData* arg0, s32 arg1);
void fn_1_3E34(omObjData*);
void fn_1_3F7C(omObjData* arg0);
void fn_1_3FF0(omObjData*);
void fn_1_3FF4(omObjData* arg0);
void fn_1_40F4(omObjData* arg0);

s32 bssPad;
Process* lbl_1_bss_37D8;
omObjData* lbl_1_bss_37C8[4];

ObjFuncs lbl_1_data_278[] = {
    fn_1_3FF0,
    fn_1_3FF4,
    fn_1_40F4,
};

typedef struct unkDominationData3 {
    u32 unk_00;
    s32 unk_04;
    Vec unk_08;
    s32 unk_14;
    s16 unk_18[4];
    f32 unk_20;
} unkDominationData3;

void fn_1_3AC8(Process* arg0) {
    u32 i;

    lbl_1_bss_37D8 = arg0;

    for (i = 0; i < ARRAY_COUNT(lbl_1_bss_37C8); i++) {
        lbl_1_bss_37C8[i] = omAddObjEx(lbl_1_bss_37D8, 0x500, 0U, 0U, 4, fn_1_3E34);
        lbl_1_bss_37C8[i]->work[0] = i;
    }
}

void fn_1_3B68(void) {
    s32 temp_r4;
    u32 i;

    for (i = 0; i < ARRAY_COUNT(lbl_1_bss_37C8); i++) {
        fn_1_3F7C(lbl_1_bss_37C8[i]);
    }
}

void fn_1_3BB8(s16 arg0, f32 arg8, f32 arg9) {
    omObjData* obj;
    Vec sp14;
    unkDominationData3* temp_r31;
    u32 i;
    s16 temp;;

    for (i = 0; i < ARRAY_COUNT(lbl_1_bss_37C8); i++) {
        obj = lbl_1_bss_37C8[i];
        temp_r31 = OM_GET_DATA_PTR(obj, unkDominationData3);
        if (temp_r31->unk_04 == 0) {
            temp = arg0;
            espBankSet(temp_r31->unk_18[1], (temp / 100));
            temp = (temp - ((temp / 100) * 100));
            espBankSet(temp_r31->unk_18[2],(temp / 10));
            temp = (temp - ((temp / 10) * 10));
            espBankSet(temp_r31->unk_18[3], temp);
            sp14.x = arg8;
            sp14.y = 0.0f;
            sp14.z = arg9;
            Hu3D3Dto2D(&sp14, 1, &temp_r31->unk_08);
            fn_1_3D28(obj, 1);
            return;
        }
    }
}

void fn_1_3D28(omObjData* arg0, s32 arg1) {
    unkDominationData3* temp_r31;

    temp_r31 = arg0->data;
    temp_r31->unk_04 = arg1;
    temp_r31->unk_14 = 0;
}

void fn_1_3D4C(omObjData* arg0) {
    s32 temp_r5;
    unkDominationData3* temp_r31;

    temp_r31 = arg0->data;
    lbl_1_data_278[temp_r31->unk_04](arg0);

    espPosSet(temp_r31->unk_18[0], temp_r31->unk_08.x, temp_r31->unk_08.y);
    espPosSet(temp_r31->unk_18[1], temp_r31->unk_08.x - 18.0f, temp_r31->unk_08.y - 8.0f);
    espPosSet(temp_r31->unk_18[2], temp_r31->unk_08.x, temp_r31->unk_08.y - 8.0f);
    espPosSet(temp_r31->unk_18[3], 18.0f + temp_r31->unk_08.x, temp_r31->unk_08.y - 8.0f);
}

void fn_1_3E34(omObjData* arg0) {
    unkDominationData3* temp_r29;
    unkDominationData3* temp_r31;

    arg0->func = fn_1_3D4C;
    arg0->data = HuMemDirectMallocNum(HEAP_SYSTEM, 0x24, 0x10000000U);
    temp_r31 = arg0->data;
    temp_r31->unk_00 = arg0->work[0];
    temp_r31->unk_14 = 0;
    temp_r31->unk_04 = 0;
    temp_r31->unk_18[0] = espEntry(0x260026, 1, 0);
    temp_r31->unk_18[1] = espEntry(0x260020, 0, 0);
    temp_r31->unk_18[2] = espEntry(0x260020, 0, 0);
    temp_r31->unk_18[3] = espEntry(0x260020, 0, 0);
    espDispOff(temp_r31->unk_18[0]);
    espDispOff(temp_r31->unk_18[1]);
    espDispOff(temp_r31->unk_18[2]);
    espDispOff(temp_r31->unk_18[3]);
    espScaleSet(temp_r31->unk_18[0], 1.8f, 1.8f);
    temp_r31->unk_08.x = (f32) 0.0f;
    temp_r31->unk_08.y = (f32) 0.0f;
    temp_r29 = arg0->data;
    temp_r29->unk_04 = 0;
    temp_r29->unk_14 = 0;
}

void fn_1_3F7C(omObjData* arg0) {
    s32 i;
    unkDominationData3* temp_r29;
    
    temp_r29 = arg0->data;

    for (i = 0; i < ARRAY_COUNT(temp_r29->unk_18); i++) {
        espKill(temp_r29->unk_18[i]);
    }

    if (arg0->data) {
        HuMemDirectFree(arg0->data);
    }
}

void fn_1_3FF0(omObjData* arg0) {

}

void fn_1_3FF4(omObjData* arg0) {
    unkDominationData3* temp_r30;
    unkDominationData3* temp_r31;

    temp_r31 = arg0->data;
    if (temp_r31->unk_14 == 0) {
        espDispOn(temp_r31->unk_18[0]);
        espDispOn(temp_r31->unk_18[1]);
        espDispOn(temp_r31->unk_18[2]);
        espDispOn(temp_r31->unk_18[3]);
        temp_r31->unk_20 = 0.0f;
    }
    if (temp_r31->unk_20 < 1.0f) {
        espTPLvlSet(temp_r31->unk_18[0], temp_r31->unk_20);
        espTPLvlSet(temp_r31->unk_18[1], temp_r31->unk_20);
        espTPLvlSet(temp_r31->unk_18[2], temp_r31->unk_20);
        espTPLvlSet(temp_r31->unk_18[3], temp_r31->unk_20);
        temp_r31->unk_20 += 0.1f;
    }

    if (temp_r31->unk_14++ >= 0x3C) {
        temp_r30 = arg0->data;
        temp_r30->unk_04 = 2;
        temp_r30->unk_14 = 0;
    }
}

void fn_1_40F4(omObjData* arg0) {
    unkDominationData3* temp_r30;
    unkDominationData3* temp_r31;

    temp_r31 = arg0->data;
    if (temp_r31->unk_20 > 0.0f) {
        espTPLvlSet(temp_r31->unk_18[0], temp_r31->unk_20);
        espTPLvlSet(temp_r31->unk_18[1], temp_r31->unk_20);
        espTPLvlSet(temp_r31->unk_18[2], temp_r31->unk_20);
        espTPLvlSet(temp_r31->unk_18[3], temp_r31->unk_20);
        temp_r31->unk_20 -= 0.05;
        return;
    }
    espDispOff(temp_r31->unk_18[0]);
    espDispOff(temp_r31->unk_18[1]);
    espDispOff(temp_r31->unk_18[2]);
    espDispOff(temp_r31->unk_18[3]);
    temp_r30 = arg0->data;
    temp_r30->unk_04 = 0;
    temp_r30->unk_14 = 0;
}

f32 pad2[1] = {0.0f};