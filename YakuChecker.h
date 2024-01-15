#ifndef YAKUCHECKER_H
#define YAKUCHECKER_H

#include "main.h"

#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif // STDLIB_H

#ifndef STRING_H
#define STRING_H
#include <string.h>
#endif // STRING_H

#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif // STDIO_H

void IsMenzenchintsumohou(Status status, int *yakunum);

bool IsRiichi(Status status, int *yakunum);

void IsDoubleRiichi(Status status, int *yakunum);

void IsIppatsu(Status status, int *yakunum);

void IsPinfu(Status status, int *yakunum);

void IsIipeikou(Status status, int *yakunum);

void IsHaiteiraoyue(Status status, int *yakunum);

void IsHouteiraoyui(Status status, int *yakunum);

void IsRinshankaihou(Status status, int *yakunum);

void IsTanyao(Status status, int *yakunum, int *handTile2);

void IsYakuhai(Status status, int *yakunum);

void IsChantaiyao(Status status, int *yakunum);

void IsSanshoukudoujun(Status status, int *yakunum);

void IsIttsu(Status status, int *yakunum);

void IsToitoi(Status status, int *yakunum);

void IsSanshokudoukou(Status status, int *yakunum);

void IsSanankou(Status status, int *yakunum);

void IsSankantsu(Status status, int *yakunum);

bool IsChiitoitsu(Status status, int *yakunum, int handTile2[]);

void IsHonroutou(Status status, int *yakunum, int *handTile2);

void IsShousangan(Status status, int *yakunum);

void IsHonitsu(Status status, int *yakunum, int handTile2[]);

bool IsJunchantaiyao(Status status, int *yakunum, int handTile2[]);

bool IsRyanpeikou(Status status, int *yakunum);

bool IsChinitsu(Status status, int *yakunum, int *handTile2);

void IsKokushimusou(Status status, int *yakunum, int handTile2[]);

void IsSuuankou(Status status, int *yakunum);

void IsDaisangen(Status status, int *yakunum);

void IsShousuushii(Status status, int *yakunum);

void IsTsuiisou(Status status, int *yakunum, int handTile2[]);

void IsChinroutou(Status status, int *yakunum, int handTile2[]);

void IsRyuuiisou(Status status, int *yakunum, int *handTile2);

void IsChuurenpoutou(Status status, int *yakunum, int *handTile2);

void IsSuukantsu(Status status, int *yakunum);

void IsTenhou(Status status, int *yakunum);

void IsChiihou(Status status, int *yakunum);

bool IsSuuankoutanki(Status status, int *yakunum);

void IsDaisuushii(Status status, int *yakunum);

bool IsJunseichuurenpoutou(Status status, int *yakunum, int handTile2[]);

void YakuCheck(Status status, int handTile2[], GroupInt groupTile1[], int discardTile1[], int currentTile);

///////////////////////////////////////////////////////上面为役，下面为宝牌///////////////////////////////////////////////////////////////////

void AddDora(Status status, int *handTile2, GroupInt *groupTile1, int *dora1);

void AddUradora(Status status, int *handTile2, GroupInt *groupTile1, int *uradora1);

///////////////////////////////////////////////////////下面为是否门前清的两个函数//////////////////////////////////////////////////////////////

bool IsMenzenchin1(const Status status);

bool IsMenzenchin2(const Status status);

int CmpYaku(const void *a, const void *b);

#endif // YAKUCHECKER_H