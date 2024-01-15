#ifndef MAIN_H
#define MAIN_H


#include "BasicType.h"
#include <stdbool.h>
#include <assert.h>

struct status {
    KazeType bakaze;       // 场风
    KazeType jikaze;       // 自风
    int honbaCount;        // 本场棒数
    char dora[12];         // 宝牌指示牌
    char uradora[12];      // 里宝牌指示牌
    char handTile[30];     // 自家手牌
    Group groupTile[30];   // 自家副露区（包括暗杠）
    char discardTile[60];  // 自家舍牌区（包含被别家副露掉的牌）
    Player currentPlayer;  // 当前控牌玩家
    char currentTile[2];   // 当前控牌
    int remainTileCount;   // 牌山剩余牌数
    bool isRiichi;         // 是否已立直
    bool isDoubleRiichi;   // 是否为两立直
    bool isIppatsu;        // 是否为一发
    bool isRinshan;        // 是否为岭上牌
};
typedef struct status Status;

struct result {
    ResultType type;  // 结果类型
    Yaku yaku[20];    // 役种，排除古役、抢杠与流局满贯，请按升序排列
    int han;          // 番数，约定役满役种得到的番数为负数，X倍役满即为 -X，以此与累计役满区分
    int fu;           // 符数，国士无双时符数无意义
    int point[3];     // 点数，三家各自要给自家的点数，不考虑包牌，下标为 0=上家，1=对家，2=下家
    int machi;        // 面听数
    int shanten;      // 向听数
};
typedef struct result Result;

extern Result *resultTemp;
extern Result *result;




#endif // MAIN_H