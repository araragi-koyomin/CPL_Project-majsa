#include "YakuChecker.h"

//////// 整体思路：先判断双倍役满牌型，然后是役满，接下来是会互相覆盖的牌型，如两杯口 > 七对子 > 一杯口, 以及 两立直 > 立直

////////////////////////////////////////////////////////下面为1番役/////////////////////////////////////////////////////

/// @brief 判断是否立直
/// @param status
/// @param yakunum
void IsRiichi(Status status, int *yakunum) {
    if (status.isRiichi) {
        result->han++;
        result->yaku[(*yakunum)++] = Riichi;
    }
}

/// @brief 判断是否双立直
/// @param status 
/// @param yakunum 
void IsDoubleRiichi(Status status, int *yakunum) {
    if (status.isDoubleRiichi) {
        result->han++;
        result->yaku[(*yakunum)] = Doubleriichi;
    }
}

/// @brief 判断是否一发
/// @param status 
/// @param yakunum 
void IsIppatsu(Status status, int *yakunum) {
    if (status.isIppatsu) {
        result->han++;
        result->yaku[(*yakunum)++] = Ippatsu;
    }
}

/// @brief 判断是否门前清自摸和
/// @param status 
/// @param yakunum 
void IsMenzenchintsumohou(Status status, int *yakunum) {
    if (IsMenzenchin1(status) && result->type == TSUMO) {
        result->han++;
        result->yaku[(*yakunum)++] = Menzenchintsumohou;
    }
}

/// @brief 判断是否平和
/// @param status 
/// @param yakunum 
void IsPinfu(Status status, int *yakunum) {
    if (mentsuType.jyan[0] >= bai || mentsuType.jyan[0] == status.bakaze - TON + east || mentsuType.jyan[0] == status.jikaze - TON + east) {
        return;
    }
    if (IsMenzenchin1(status) && mentsuType.shuntsunum == 4) {
        result->han++;
        result->yaku[(*yakunum)++] = Pinfu;
    } 
}

/// @brief 判断是否一杯口
/// @param status 
/// @param yakunum 
void IsIipeikou(Status status, int *yakunum) {
    int flag = 0;
    if (mentsuType.shuntsunum >= 2) {
        for (int i = 0; i < mentsuType.shuntsunum - 1; i++) {
            for (int j = 1; j < mentsuType.shuntsunum; j++) {
                if (mentsuType.shun[i][0] == mentsuType.shun[j][0]) {
                    result->han++;
                    result->yaku[(*yakunum)++] = Iipeikou;
                    return;
                }
            }
        }
    }
}

/// @brief 判断是否海底捞月
/// @param status 
/// @param yakunum 
void IsHaiteiraoyue(Status status, int *yakunum) {
    if (status.remainTileCount == 0 && status.currentPlayer == JICHA) {
        result->han++;
        result->yaku[(*yakunum)++] = Haiteiraoyue;
    }
}

/// @brief 判断是否河底捞鱼
/// @param status 
/// @param yakunum 
void IsHouteiraoyui(Status status, int *yakunum) {
    if (status.remainTileCount == 0 && status.currentPlayer != JICHA) {
        result->han++;
        result->yaku[(*yakunum)++] = Houteiraoyui;
    }
}

/// @brief 判断是否岭上开花
/// @param status 
/// @param yakunum 
void IsRinshankaihou(Status status, int *yakunum) {
    if (status.isRinshan) {
        result->han++;
        result->yaku[(*yakunum)++] = Rinshankaihou;
    }
}

/// @brief 判断是否断幺
/// @param status 
/// @param yakunum 
/// @param handTile1 
void IsTanyao(Status status, int *yakunum, int *handTile1) {
    for (int i = 0; i < sizeof(handTile1); i++) {
        if (handTile1[i] == im || handTile1[i] == km || handTile1[i] == ip || handTile1[i] == kp || handTile1[i] == is || handTile1[i] >= ks) {
            return;
        }
    }
    if (!IsMenzenchin1(status)) {
        for (int i = 0; i < sizeof(groupTile1) / sizeof(groupTile1[0]); i++) {
            for (int j = 0; j < 3; j++) {
                if (groupTile1[i].groupHaiInt[j] == im || groupTile1[i].groupHaiInt[j] == km || groupTile1[i].groupHaiInt[j] == ip || groupTile1[i].groupHaiInt[j] == kp || groupTile1[i].groupHaiInt[j] == is || groupTile1[i].groupHaiInt[j] >= ks) {
                    return;
                }
            }
        }
    }
    result->han++;
    result->yaku[(*yakunum)++] = Tanyao;
}

/// @brief 判断是否有役牌
/// @param status 
/// @param yakunum 
/// @param handTile1 
void IsYakuhai(Status status, int *yakunum, int handTile1[]) {
    for (int i = 0; i < mentsuType.koutsunum; i++) {
        if (mentsuType.kou[i][0] >= east) {
            result->han++;
            result->yaku[(*yakunum)++] = Ton + mentsuType.kou[i][0] - east;
        }
    }
    if (!IsMenzenchin1(status)) {
        for (int i = 0; i < sizeof(groupTile1) / sizeof(groupTile1[0]); i++) {
            if (groupTile1[i].groupHaiInt[0] >= east) {
                result->han++;
                result->yaku[(*yakunum)++] = Ton + groupTile1[i].groupHaiInt[0] - east;
            }
        }
    }
}