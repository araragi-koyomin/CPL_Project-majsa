#ifndef YAKUCHECKER_H
#define YAKUCHECKER_H

#include "main.h"

void IsMenzenchintsumohou(Status status, int *yakunum);

bool IsRiichi(Status status, int *yakunum);

void IsDoubleRiichi(Status status, int *yakunum);

void IsIppatsu(Status status, int *yakunum);

void IsPinfu(Status status, int *yakunum);

void IsIipeikou(Status status, int *yakunum);

void IsHaiteiraoyue(Status status, int *yakunum);

void IsHouteiraoyui(Status status, int *yakunum);

void IsRinshankaihou(Status status, int *yakunum);

void IsTanyao(Status status, int *yakunum, int *handTile1);

void IsYakuhai(Status status, int *yakunum);

void IsChantaiyao(Status status, int *yakunum);

void IsSanshoukudoujun(Status status, int *yakunum);

void IsIttsu(Status status, int *yakunum);

void IsToitoi(Status status, int *yakunum);

void IsSanshokudoukou(Status status, int *yakunum);

void IsSanankou(Status status, int *yakunum);

void IsSankantsu(Status status, int *yakunum);

bool IsChiitoitsu(Status status, int *yakunum, int handTile1[]);

void IsHonroutou(Status status, int *yakunum, int *handTile1);

void IsShousangan(Status status, int *yakunum);

void IsHonitsu(Status status, int *yakunum, int handTile1[]);

bool IsJunchantaiyao(Status status, int *yakunum, int handTile1[]);

bool IsRyanpeikou(Status status, int *yakunum);

bool IsChinitsu(Status status, int *yakunum, int *handTile1);

void IsKokushimusou(Status status, int *yakunum, int handTile1[]);

void IsSuuankou(Status status, int *yakunum);

void IsDaisangen(Status status, int *yakunum);

void IsShousuushii(Status status, int *yakunum);

void IsTsuiisou(Status status, int *yakunum, int handTile1[]);

void IsChinroutou(Status status, int *yakunum, int handTile1[]);

void IsRyuuiisou(Status status, int *yakunum, int *handTile1);

void IsChuurenpoutou(Status status, int *yakunum, int *handTile1);

void IsSuukantsu(Status status, int *yakunum);

void IsTenhou(Status status, int *yakunum);

void IsChiihou(Status status, int *yakunum);

bool IsSuuankoutanki(Status status, int *yakunum);

void IsDaisuushii(Status status, int *yakunum);

bool IsJunseichuurenpoutou(Status status, int *yakunum, int handTile1[]);

void YakuCheck(Status status, int handTile1[], GroupInt groupTile1[], int discardTile1[], int currentTile);

///////////////////////////////////////////////////////上面为役，下面为宝牌///////////////////////////////////////////////////////////////////

void AddDora(Status status, int *handTile1, GroupInt *groupTile1, int *dora1);

void AddUradora(Status status, int *handTile1, GroupInt *groupTile1, int *uradora1);

///////////////////////////////////////////////////////下面为是否门前清的两个函数//////////////////////////////////////////////////////////////

bool IsMenzenchin1(const Status status) {
    if(status.groupTile[0].tile[0] == 0) return true;
    // for (int i = 0; i < sizeof(groupTile1) / sizeof(groupTile1[0]); i++) {
    //     if (groupTile1[i].fulutype != Ankan) return false;
    // }
    // return true;
    return false;
}

bool IsMenzenchin2(const Status status) {
    if(status.groupTile[0].tile[0] == 0) return true;
    for (int i = 0; i < sizeof(groupTile1) / sizeof(groupTile1[0]); i++) {
        if (groupTile1[i].fulutype != Ankan) return false;
    }
    return true;
}

bool CmpYaku(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

#endif // YAKUCHECKER_H