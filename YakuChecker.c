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
        result->yaku[(*yakunum)] = doubleRiichi;
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
        result->yaku[(*yakunum)++] = Menzenchintsumo;
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
        result->yaku[(*yakunum)++] = Pinhu;
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
void IsYakuhai(Status status, int *yakunum) {
    for (int i = 0; i < mentsuType.koutsunum; i++) {
        if (mentsuType.kou[i][0] == bai) {
            result->han++;
            result->yaku[(*yakunum)++] = YakuhaiHaku;
        } else if (mentsuType.kou[i][0] == fa) {
            result->han++;
            result->yaku[(*yakunum)++] = YakuhaiHatsu;
        } else if (mentsuType.kou[i][0] == zhong) {
            result->han++;
            result->yaku[(*yakunum)++] = YakuhaiChun;
        } else if (mentsuType.kou[i][0] == status.bakaze) {
            result->han++;
            result->yaku[(*yakunum)++] = YakuhaiBakaze;
        } else if (mentsuType.kou[i][0] == status.jikaze) {
            result->han++;
            result->yaku[(*yakunum)++] = YakuhaiJikaze;
        }
    }
    if (!IsMenzenchin1(status)) {
        for (int i = 0; i < sizeof(groupTile1) / sizeof(groupTile1[0]); i++) {
            if (groupTile1[i].groupHaiInt[0] == bai) {
                result->han++;
                result->yaku[(*yakunum)++] = YakuhaiHaku;
            } else if (groupTile1[i].groupHaiInt[0] == fa) {
                result->han++;
                result->yaku[(*yakunum)++] = YakuhaiHatsu;
            } else if (groupTile1[i].groupHaiInt[0] == zhong) {
                result->han++;
                result->yaku[(*yakunum)++] = YakuhaiChun;
            } else if (groupTile1[i].groupHaiInt[0] == status.bakaze) {
                result->han++;
                result->yaku[(*yakunum)++] = YakuhaiBakaze;
            } else if (groupTile1[i].groupHaiInt[0] == status.jikaze) {
                result->han++;
                result->yaku[(*yakunum)++] = YakuhaiJikaze;
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////以下为双倍役满//////////////////////////////////////////////////////////////////////////

/// @brief 判断是否纯九说走就走
/// @param status 
/// @param yakunum 
/// @param handTile1 
void IsJunseichuurenpoutou(Status status, int *yakunum, int handTile1[]) {
    int bucket[zhong + 1] = {0}, flag = 0;
    if (!IsMenzenchin1(status)) return;
    for (int i = 0; i < 14; i++) {
        bucket[handTile1[i]]++;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = im; j <= km; j++) {
            if (!bucket[handTile1[j + i * 9]]) {
                break;
            }
        }
    }
    if (!flag) return;
    for (int i = 0; i < 3; i++) {
        if (bucket[im + i * 9] >= 3 && bucket[nm + 9 * i] && bucket[sm + 9 * i] && bucket[shm + 9 * i] && bucket[gm + 9 * i] && bucket[rm + 9 * i]
            && bucket[nm + 9 * i] && bucket[hm + 9 * i] && bucket[km + 9 * i] >= 3 && (bucket[currentTile1] == 2 || bucket[currentTile1] == 4)) {
            result->han -= 2;
            result->yaku[(*yakunum)++] = Chuurenkyuumenmachi;
        }
    }
}

/// @brief 判断是否大四喜
/// @param status 
/// @param yakunum 
void IsDaisuushii(Status status, int *yakunum) {
    int count = 0;
    for (int i = 0; i < mentsuType.koutsunum; i++) {
        if (mentsuType.kou[i][0] >= east && mentsuType.kou[i][0] <= north) {
            count++;
        }
    }
    if (!IsMenzenchin1(status)) {
        for (int i = 0; i < sizeof(groupTile1) / sizeof(groupTile1[0]); i++) {
            if (groupTile1[i].groupHaiInt[0] >= east && groupTile1[i].groupHaiInt[0] <= north) {
                count++;
            }
        }
    }
    if (count == 4) {
        result->han -= 2;
        result->yaku[(*yakunum)++] = Daisuushi;
    }
}

/// @brief 判断是否四暗刻单骑
/// @param status 
/// @param yakunum 
void IsSuuankoutanki(Status status, int *yakunum) {
    if (IsMenzenchin1(status) && mentsuType.kou == 4 && mentsuType.jyan[0] == currentTile1) {
        result->han -= 2;
        result->yaku[(*yakunum)++] = Suuankoutanki;
    }
}

/// @brief 判断是否是国士无双（十三面）
/// @param status 
/// @param yakunum 
/// @param handTile1 
void IsKokushimusou(Status status, int *yakunum, int handTile1[]) {
    int counts[zhong + 1] = {0}, flag = 1;
    for (int i = 0; i < 14; i++) {
        if (handTile1[i] == im || handTile1[i] == km || handTile1[i] == ip || handTile1[i] == kp || handTile1[i] == is || handTile1[i] >= ks)
            counts[handTile1[i]]++;
        else return;
    }
    for (int i = im; i <= zhong; i++) {
        if (counts[i] > 2) return;
        else if (counts[i] != 1 && counts[i] != counts[currentTile1]) flag = 0;
    }
    if (flag) {
        result->han -= 1;
        result->yaku[(*yakunum)++] = Kokushimusou;
    } else {
        result->han -= 2;
        result->yaku[(*yakunum)++] = Kokushijuusanmenmachi;
    }
}

///////////////////////////////////////////////////////////////////下为役满/////////////////////////////////////////////////////////////////////

/// @brief 判断是否天和
/// @param status 
/// @param yakunum 
void IsTenhou(Status status, int *yakunum) {
    if (status.currentPlayer == JICHA && status.remainTileCount == 69) {
        result->han -= 1;
        result->yaku[(*yakunum)++] = Tenhou;
    }
}

/// @brief 判断是否地和
/// @param status 
/// @param yakunum 
void IsChiihou(Status status, int *yakunum) {
    if (status.currentPlayer != JICHA && status.remainTileCount >= 66) {
        result->han -= 1;
        result->yaku[(*yakunum)++] = Chihou;
    }
}

/// @brief 判断是否四暗刻
/// @param status 
/// @param yakunum 
void IsSuuankou(Status status, int *yakunum) {
    if (IsMenzenchin1(status) && mentsuType.kou == 4 && mentsuType.jyan[0] != currentTile1 && status.currentPlayer == JICHA) {
        result->han -= 1;
        result->yaku[(*yakunum)++] = Suuankou;
    }
}

/// @brief 判断是否九莲宝灯
/// @param status 
/// @param yakunum 
/// @param handTile1 
void IsChuurenpoutou(Status status, int *yakunum, int handTile1[]) {
    int bucket[zhong + 1] = {0}, flag = 0;
    if (!IsMenzenchin1(status)) return;
    for (int i = 0; i < 14; i++) {
        bucket[handTile1[i]]++;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = im; j <= km; j++) {
            if (!bucket[handTile1[j + i * 9]]) {
                break;
            }
        }
    }
    if (!flag) return;
    for (int i = 0; i < 3; i++) {
        if (bucket[im + i * 9] >= 3 && bucket[nm + 9 * i] && bucket[sm + 9 * i] && bucket[shm + 9 * i] && bucket[gm + 9 * i] && bucket[rm + 9 * i]
            && bucket[nm + 9 * i] && bucket[hm + 9 * i] && bucket[km + 9 * i] >= 3 && (bucket[currentTile1] == 1 || bucket[currentTile1] == 3)) {
            result->han -= 1;
            result->yaku[(*yakunum)++] = Chuurenpoutou;
        }
    }
}

/// @brief 判断是否绿一色
/// @param status 
/// @param yakunum 
/// @param handTile1 
void IsRyuuiisou(Status status, int *yakunum, int *handTile1) {
    for (int i = 0; i < sizeof(handTile1); i++) {
        if (handTile1[i] != ns || handTile1[i] != ss || handTile1[i] != ys || handTile1[i] != rs || handTile1[i] != hs || handTile1[i] != fa) {
            return;
        }
    }
    if (!IsMenzenchin1(status)) {
        for (int i = 0; i < sizeof(groupTile1) / sizeof(groupTile1[0]); i++) {
            if (groupTile1[i].fulutype == Kantsu || groupTile1[i].fulutype == Ankan || groupTile1[i].fulutype == Koutsu) {
                if (groupTile1[i].groupHaiInt[0] != ns || groupTile1[i].groupHaiInt[0] != ss || groupTile1[i].groupHaiInt[0] != ys || groupTile1[i].groupHaiInt[0] != rs || groupTile1[i].groupHaiInt[0] != hs || groupTile1[i].groupHaiInt[0] != fa) {
                    return;
                }
            } else {
                if (groupTile1[i].groupHaiInt[0] != ns) {
                    return;
                }
            }
        }
    }
    result->han -= 1;
    result->yaku[(*yakunum)++] = Ryuuiisou;
}

/// @brief 判断是否清老头
/// @param status 
/// @param yakunum 
/// @param handTile1 
void IsChinroutou(Status status, int *yakunum, int handTile1[]) {
    for (int i = 0; i < sizeof(handTile1); i++) {
        if (handTile1[i] != im || handTile1[i] != km || handTile1[i] != ip || handTile1[i] != kp || handTile1[i] != is || handTile1[i] != ks ||
            handTile1[i] != east || handTile1[i] != south || handTile1[i] != west || handTile1[i] != north) {
            return;
        }
    }
    if (!IsMenzenchin1(status)) {
        for (int i = 0; i < sizeof(groupTile1) / sizeof(groupTile1[0]); i++) {
            if (groupTile1[i].fulutype == Shuntsu) return;
            else {
                if (groupTile1[i].groupHaiInt[0] !=im || groupTile1[i].groupHaiInt[0] != km || groupTile1[i].groupHaiInt[0] != ip || groupTile1[i].groupHaiInt[0] != kp || 
                    groupTile1[i].groupHaiInt[0] != is || groupTile1[i].groupHaiInt[0] != ks || groupTile1[i].groupHaiInt[0] != east || 
                    groupTile1[i].groupHaiInt[0] != south || groupTile1[i].groupHaiInt[0] != west || groupTile1[i].groupHaiInt[0] != north) {
                    return;
                }
            }
        }
    }
    result->han -= 1;
    result->yaku[(*yakunum)++] = Chinroutou;
}

/// @brief 判断是否四杠子
/// @param status 
/// @param yakunum 
void IsSuukantsu(Status status, int *yakunum) {
    for (int i = 0; i < 4; i++) {
        if (groupTile1[i].fulutype != Kantsu && groupTile1[i].fulutype != Ankan) {
            return;
        }
    }
    result->han -= 1;
    result->yaku[(*yakunum)++] = Suukantsu;
}

/// @brief 判断是否字一色
/// @param status 
/// @param yakunum 
/// @param handTile1 
void IsTsuiisou(Status status, int *yakunum, int handTile1[]) {
    for (int i = 0; i < sizeof(handTile1); i++) {
        if (handTile1[i] < east) {
            return;
        }
    }
    if (!IsMenzenchin1(status)) {
        for (int i = 0; i < sizeof(groupTile1) / sizeof(groupTile1[0]); i++) {
            if (groupTile1[i].fulutype == Shuntsu) return;
            else {
                if (groupTile1[i].groupHaiInt[0] < east) {
                    return;
                }
            }
        }
    }
    result->han -= 1;
    result->yaku[(*yakunum)++] = Tsuuiisou;
}

/// @brief 判断是否小四喜
/// @param status 
/// @param yakunum 
void IsShousuushii(Status status, int *yakunum) {
    int count = 0;
    for (int i = 0; i < mentsuType.koutsunum; i++) {
        if (mentsuType.kou[i][0] >= east && mentsuType.kou[i][0] <= north) {
            count++;
        }
    }
    if (!IsMenzenchin1(status)) {
        for (int i = 0; i < sizeof(groupTile1) / sizeof(groupTile1[0]); i++) {
            if (groupTile1[i].groupHaiInt[0] >= east && groupTile1[i].groupHaiInt[0] <= north) {
                count++;
            }
        }
    }
    if (count == 3 && mentsuType.jyan[0] >= east && mentsuType.jyan[0] <= north) {
        result->han -= 1;
        result->yaku[(*yakunum)++] = Shousuushi;
    }
}

/// @brief 判断是否大三元
/// @param status 
/// @param yakunum 
void IsDaisangen(Status status, int *yakunum) {
    int count = 0;
    for (int i = 0; i < mentsuType.koutsunum; i++) {
        if (mentsuType.kou[i][0] >= bai) {
            count++;
        }
    }
    if (!IsMenzenchin1(status)) {
        for (int i = 0; i < sizeof(groupTile1) / sizeof(groupTile1[0]); i++) {
            if (groupTile1[i].groupHaiInt[0] >= bai) {
                count++;
            }
        }
    }
    if (count == 3) {
        result->han -= 1;
        result->yaku[(*yakunum)++] = Daisangen;
    }
}