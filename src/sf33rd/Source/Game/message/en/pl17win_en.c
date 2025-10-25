/**
 * @file pl17win_en.c
 * Q Win Quotes (English)
 */

#include "sf33rd/Source/Game/message/en/pl17win_en.h"
#include "common.h"

static s8* msgWinPL17_00P[1] = { "" };
static s8* msgWinPL17_01P[1] = { "" };
static s8* msgWinPL17_02P[1] = { "" };
static s8* msgWinPL17_03P[1] = { "" };
static s8* msgWinPL17_04P[1] = { "" };
static s8* msgWinPL17_05P[1] = { "" };
static s8* msgWinPL17_06P[1] = { "" };
static s8* msgWinPL17_07P[1] = { "" };
static s8* msgWinPL17_08P[1] = { "" };
static s8* msgWinPL17_09P[1] = { "" };
static s8* msgWinPL17_10P[1] = { "" };
static s8* msgWinPL17_11P[1] = { "" };
static s8* msgWinPL17_12P[1] = { "" };
static s8* msgWinPL17_13P[1] = { "" };
static s8* msgWinPL17_14P[1] = { "" };
static s8* msgWinPL17_15P[1] = { "" };
static s8* msgWinPL17_16P[1] = { "" };
static s8* msgWinPL17_17P[1] = { "" };
static s8* msgWinPL17_18P[1] = { "" };
static s8* msgWinPL17_19P[1] = { "" };
static s8* msgWinPL17_20P[2] = { "   !.........                                   ",
                                 "   (No!)                                        " };
static s8* msgWinPL17_21P[2] = { "   ?!.........                                  ",
                                 "   (Seriously?!)                                " };
static s8* msgWinPL17_22P[2] = { "   .....................                        ",
                                 "   (Leave.)                                     " };
static s8* msgWinPL17_23P[2] = { "   .....................                        ",
                                 "   (Bye.)                                       " };
static s8* msgWinPL17_24P[2] = { "   .........                                    ",
                                 "   (Done.)                                      " };
static s8* msgWinPL17_25P[2] = { "   .........!                                   ",
                                 "   (Never!)                                     " };
static s8* msgWinPL17_26P[2] = { "   ?.........                                   ",
                                 "   (Yes?)                                       " };
static s8* msgWinPL17_27P[2] = { "   .........?                                   ",
                                 "   (Again?)                                     " };

static s8** msgWinAdrPL17[28] = {
    msgWinPL17_00P, msgWinPL17_01P, msgWinPL17_02P, msgWinPL17_03P, msgWinPL17_04P, msgWinPL17_05P, msgWinPL17_06P,
    msgWinPL17_07P, msgWinPL17_08P, msgWinPL17_09P, msgWinPL17_10P, msgWinPL17_11P, msgWinPL17_12P, msgWinPL17_13P,
    msgWinPL17_14P, msgWinPL17_15P, msgWinPL17_16P, msgWinPL17_17P, msgWinPL17_18P, msgWinPL17_19P, msgWinPL17_20P,
    msgWinPL17_21P, msgWinPL17_22P, msgWinPL17_23P, msgWinPL17_24P, msgWinPL17_25P, msgWinPL17_26P, msgWinPL17_27P,
};

static s8 msgWinCtrPL17[28] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2,
};

MessageTable pl17win_usa_tbl = { msgWinAdrPL17, msgWinCtrPL17 };
