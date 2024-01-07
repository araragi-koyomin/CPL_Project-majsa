#include "YakuChecker.h"

//////// 整体思路：先判断双倍役满牌型，然后是役满，接下来是会互相覆盖的牌型，如两杯口 > 七对子 > 一杯口, 以及 两立直 > 立直
////////////////////////////////////////////////////////下为用来判断番数的主要函数////////////////////////////////////////



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
    if (IsMenzenchin2(status) && result->type == TSUMO) {
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
    if (IsMenzenchin2(status) && mentsuType.shuntsunum == 4) {
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
        flag = 1;
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
    int count = 0;
    if (!IsMenzenchin1(status)) {
        for (int i = 0; i < sizeof(groupTile1) / sizeof(groupTile1[0]); i++) {
            if (groupTile1[i].fulutype == Ankan) {
                count++;
            }
        }
    }
    if (IsMenzenchin1(status) && mentsuType.kou + count == 4 && mentsuType.jyan[0] == currentTile1) {
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
    int count = 0;
    if (!IsMenzenchin1(status)) {
        for (int i = 0; i < sizeof(groupTile1) / sizeof(groupTile1[0]); i++) {
            if (groupTile1[i].fulutype == Ankan) {
                count++;
            }
        }
    }
    if (IsMenzenchin1(status) && mentsuType.kou + count == 4 && mentsuType.jyan[0] != currentTile1 && status.currentPlayer == JICHA) {
        result->han -= 1;
        result->yaku[(*yakunum)++] = Suuankou;
    }
}

/// @brief 判断是否九莲宝灯
/// @param status 
/// @param yakunum 
/// @param handTile1 
void IsChuurenpoutou(Status status, int *yakunum, int *handTile1) {
    int bucket[zhong + 1] = {0}, flag = 0;
    if (!IsMenzenchin1(status)) {
        for (int i = 0; i < sizeof(groupTile1) / sizeof(groupTile1[0]); i++) {
            if (groupTile1[i].fulutype != Ankan) return; 
            else {
                bucket[groupTile1[i].groupHaiInt[0]]+=4;
            }
        }
    }
    for (int i = 0; i < sizeof(handTile1); i++) {
        bucket[handTile1[i]]++;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = im; j <= km; j++) {
            if (!bucket[handTile1[j + i * 9]]) {
                break;
            }
        }
        flag = 1;
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
        if (handTile1[i] != ns && handTile1[i] != ss && handTile1[i] != ys && handTile1[i] != rs && handTile1[i] != hs && handTile1[i] != fa) {
            return;
        }
    }
    if (!IsMenzenchin1(status)) {
        for (int i = 0; i < sizeof(groupTile1) / sizeof(groupTile1[0]); i++) {
            if (groupTile1[i].fulutype == Kantsu && groupTile1[i].fulutype == Ankan && groupTile1[i].fulutype == Koutsu) {
                if (groupTile1[i].groupHaiInt[0] != ns && groupTile1[i].groupHaiInt[0] != ss && groupTile1[i].groupHaiInt[0] != ys && groupTile1[i].groupHaiInt[0] != rs && groupTile1[i].groupHaiInt[0] != hs && groupTile1[i].groupHaiInt[0] != fa) {
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
        if (handTile1[i] != im && handTile1[i] != km && handTile1[i] != ip && handTile1[i] != kp && handTile1[i] != is && handTile1[i] != ks) {
            return;
        }
    }
    if (!IsMenzenchin1(status)) {
        for (int i = 0; i < sizeof(groupTile1) / sizeof(groupTile1[0]); i++) {
            if (groupTile1[i].fulutype == Shuntsu) return;
            else {
                if (groupTile1[i].groupHaiInt[0] != im && groupTile1[i].groupHaiInt[0] != km && groupTile1[i].groupHaiInt[0] != ip && groupTile1[i].groupHaiInt[0] != kp && 
                    groupTile1[i].groupHaiInt[0] != is && groupTile1[i].groupHaiInt[0] != ks) {
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

/////////////////////////////////////////////////////////以下为6番役//////////////////////////////////////////////////////////////////////////

/// @brief 判断是否清一色
/// @param status 
/// @param yakunum 
/// @param handTile1 
void IsChinitsu(Status status, int *yakunum, int *handTile1) {
    int flag = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < sizeof(handTile1) / sizeof(handTile1[0]); j++) {
            if (handTile1[j] < im + i * 9 || handTile1[j] > km + 9 * i) {
                goto NOT;
            }
        }
        if (!IsMenzenchin1(status)) {
            for (int j = 0; j < sizeof(groupTile1) / sizeof(groupTile1[0]); j++) {
                if (groupTile1[j].groupHaiInt[0] < im + 9 * i || groupTile1[j].groupHaiInt[0] > km + 9 * i) {
                    goto NOT;
                }
            }
        }
        flag = 1;
        NOT:
    }
    if (flag) {
        if (IsMenzenchin2(status)) {
            result->han += 6;
            result->yaku[(*yakunum)++] = Chinitsu;
        } else {
            result->han += 5;
            result->yaku[(*yakunum)++] = ChinitsuF;
        }
    }
}

/////////////////////////////////////////////////////////以下为3番役//////////////////////////////////////////////////////////////////////////

/// @brief 判断是否两杯口
/// @param status 
/// @param yakunum 
void IsRyanpeikou(Status status, int *yakunum) {
    if (mentsuType.shuntsunum == 4) {
        if (mentsuType.shun[0][0] == mentsuType.shun[1][0] && mentsuType.shun[2][0] == mentsuType.shun[3][0] ||
            mentsuType.shun[0][0] == mentsuType.shun[2][0] && mentsuType.shun[1][0] == mentsuType.shun[3][0] ||
            mentsuType.shun[0][0] == mentsuType.shun[3][0] && mentsuType.shun[1][0] == mentsuType.shun[2][0]) {
            result->han += 3;
            result->yaku[(*yakunum)++] = Ryanpeikou;
        }
    }
}

/// @brief 判断是否纯全带幺九
/// @param status 
/// @param yakunum 
/// @param handTile1 
void IsJunchantaiyao(Status status, int *yakunum, int handTile1[]) {
    for (int i = 0; i < mentsuType.koutsunum; i++) {
        if (mentsuType.kou[i][0] != im && mentsuType.kou[i][0] != km && mentsuType.kou[i][0] != ip && mentsuType.kou[i][0] != ks && mentsuType.kou[i][0] != is && mentsuType.kou[i][0] != kp) {
            return;
        }
    }
    for (int i = 0; i < mentsuType.shuntsunum; i++) {
        if ((mentsuType.shun[i][0] != im && mentsuType.shun[i][2] != km) && (mentsuType.shun[i][0] != ip && mentsuType.shun[i][2] != kp) && (mentsuType.shun[i][0] != is && mentsuType.shun[i][2] != ks)) {
            return;
        }
    }
    if (IsMenzenchin1(status)) {
        result->han += 3;
        result->yaku[(*yakunum)++] = Junchantaiyaochuu;
    } else {
        for (int i = 0; i < sizeof(groupTile1) / sizeof(groupTile1[0]); i++) {
            if (groupTile1->fulutype == Shuntsu && groupTile1->groupHaiInt[0] != im && groupTile1->groupHaiInt[2] != km && groupTile1->groupHaiInt[0] != ip && groupTile1->groupHaiInt[2] != kp && groupTile1->groupHaiInt[0] != is && groupTile1->groupHaiInt[2] != ks) {
                return;
            } else if (groupTile1->fulutype != Shuntsu && groupTile1->groupHaiInt[0] != im && groupTile1->groupHaiInt[0] != km && groupTile1->groupHaiInt[0] != ip && groupTile1->groupHaiInt[0] != kp && groupTile1->groupHaiInt[0] != is && groupTile1->groupHaiInt[0] != ks) {
                return;
            }
        }
        if (IsMenzenchin2(status)) {
            result->han += 3;
            result->yaku[(*yakunum)++] = Junchantaiyaochuu;
        } else {
            result->han += 2;
            result->yaku[(*yakunum)++] = JunchantaiyaochuuF;
        }
    }
}

/// @brief 判断是否混一色
/// @param status 
/// @param yakunum 
/// @param handTile1 
void IsHonitsu(Status status, int *yakunum, int handTile1[]) {
    int flag = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < sizeof(handTile1) / sizeof(handTile1[0]); j++) {
            if (handTile1[j] >= east) continue;
            if (handTile1[j] < im + i * 9 || handTile1[j] > km + 9 * i) {
                goto NOT;
            }
        }
        if (!IsMenzenchin1(status)) {
            for (int j = 0; j < sizeof(groupTile1) / sizeof(groupTile1[0]); j++) {
                if (groupTile1[j].groupHaiInt[0] >= east) continue;
                if (groupTile1[j].groupHaiInt[0] < im + 9 * i || groupTile1[j].groupHaiInt[0] > km + 9 * i) {
                    goto NOT;
                }
            }
        }
        flag = 1;
        NOT:
    }
    if (flag) {
        if (IsMenzenchin2(status)) {
            result->han += 3;
            result->yaku[(*yakunum)++] = Honitsu;
        } else {
            result->han += 2;
            result->yaku[(*yakunum)++] = HonitsuF;
        }
    }
}

//////////////////////////////////////////////////////////////以下为2番役/////////////////////////////////////////////////////////////////////

/// @brief 判断是否小三元
/// @param status 
/// @param yakunum 
void IsShousangan(Status status, int *yakunum) {
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
    if (count == 2 && mentsuType.jyan[0] >= bai) {
        result->han += 2;
        result->yaku[(*yakunum)++] = Shousangen;
    }
}

/// @brief 判断是否混老头
/// @param status 
/// @param yakunum 
/// @param handTile1 
void IsHonroutou(Status status, int *yakunum, int *handTile1) {
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < sizeof(handTile1) / sizeof(handTile1[0]); i++) {
            if (handTile1[i] != im + j * 9 && handTile1[i] != km + 9 * j && handTile1[j] < east) {
                return;
            }
        }
    }
    if (!IsMenzenchin1(status)) {
        for (int j = 0; j < 3; j++) {
            for (int i = 0; i < sizeof(groupTile1) / sizeof(groupTile1[0]); i++) {
                for (int k = 0; k < sizeof(groupTile1[i].groupHaiInt) / sizeof(groupTile1[i].groupHaiInt[0]); k++) {
                    if (groupTile1[i].groupHaiInt[k] != im + 9 * j && groupTile1[i].groupHaiInt[k] != km + 9 * j && groupTile1[i].groupHaiInt[k] < east) {
                        return;
                    }
                }
            }
        }
    }
    result->han += 2;
    result->yaku[(*yakunum)++] = Honroutou;
}

/// @brief 判断是否三杠子
/// @param status 
/// @param yakunum 
void IsSankantsu(Status status, int *yakunum) {
    int count = 0;
    if (IsMenzenchin1(status)) return;
    for (int i = 0; i < sizeof(groupTile1) / sizeof(groupTile1[0]); i++) {
        if (groupTile1[i].fulutype == Ankan || groupTile1[i].fulutype == Kantsu) {
            count++;
        }
    }
    if (count == 3) {
        result->han += 2;
        result->yaku[(*yakunum)++] = Sankantsu;
    }
}

/// @brief 判断是否三暗刻
/// @param status 
/// @param yakunum 
void IsSanankou(Status status, int *yakunum) {
    int count = 0;
    if (!IsMenzenchin1(status)) {
        for (int i = 0; i < sizeof(groupTile1) / sizeof(groupTile1[0]); i++) {
            if (groupTile1[i].fulutype == Ankan) {
                count++;
            }
        }
    }
    int flag = 1;
    for (int i = 0; i < mentsuType.shuntsunum; i++) {
        for (int j = 0; j < 3; j++) {
            if (mentsuType.shun[i][j] == currentTile1) {
                flag = 0;
            }
        }
    }
    if (mentsuType.jyan[0] == currentTile1) flag = 0;
    if ((mentsuType.koutsunum + count == 3 && flag) || (mentsuType.koutsunum + count == 4 && !flag)) {
        result->han += 2;
        result->yaku[(*yakunum)++] = Sanankou;
    }
}

/// @brief 判断是否对对和
/// @param status 
/// @param yakunum 
void IsToitoi(Status status, int *yakunum) {
    if (mentsuType.shuntsunum) return;
    if (!IsMenzenchin1(status)) {
        for (int i = 0; i < sizeof(groupTile1) / sizeof(groupTile1[0]); i++) {
            if (groupTile1[i].fulutype == Shuntsu) {
                return;
            }
        }
    }
    result->han += 2;
    result->yaku[(*yakunum)++] = Toitoihou;
}

/// @brief 判断是否三色同刻
/// @param status 
/// @param yakunum 
void IsSanshokudoukou(Status status, int *yakunum) {
    int count = 0, val[4];
    if (!IsMenzenchin1(status)) {
        for (int i = 0; i < sizeof(groupTile1) / sizeof(groupTile1[0]); i++) {
            if (groupTile1[i].fulutype != Shuntsu) {
                val[count++] = groupTile1[i].groupHaiInt[0];
            }
        }
    }
    for (int i = 0; i < mentsuType.koutsunum; i++) {
        val[count++] = mentsuType.kou[i][0];
    }
    int bucket[10] = {0};
    if (count >= 3) {
        for (int i = 0; i < count - 1; i++) {
            if (val[i] < east) {
                bucket[val[i] % 9]++;
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        if (bucket[i] >= 3) {
            result->han += 2;
            result->yaku[(*yakunum)++] = Sanshokudoukou;
            return;
        }
    }
}

/// @brief 判断是否混全带幺九
/// @param status 
/// @param yakunum 
void IsChantaiyao(Status status, int *yakunum) {
    for (int i = 0; i < mentsuType.koutsunum; i++) {
        if (mentsuType.kou[i][0] != im && mentsuType.kou[i][0] != km && mentsuType.kou[i][0] != ip && mentsuType.kou[i][0] != ks && mentsuType.kou[i][0] != is && mentsuType.kou[i][0] != kp &&
            mentsuType.kou[i][0] < east) {
            return;
        }
    }
    for (int i = 0; i < mentsuType.shuntsunum; i++) {
        if (mentsuType.shun[i][0] != im && mentsuType.shun[i][2] != km && mentsuType.shun[i][0] != ip && mentsuType.shun[i][2] != kp && mentsuType.shun[i][0] != is && mentsuType.shun[i][2] != ks) {
            return;
        }
    }
    if (IsMenzenchin1(status)) {
        result->han += 2;
        result->yaku[(*yakunum)++] = Honchantaiyaochuu;
    } else {
        for (int i = 0; i < sizeof(groupTile1) / sizeof(groupTile1[0]); i++) {
            if (groupTile1->fulutype == Shuntsu && groupTile1->groupHaiInt[0] != im && groupTile1->groupHaiInt[2] != km && groupTile1->groupHaiInt[0] != ip && groupTile1->groupHaiInt[2] != kp && groupTile1->groupHaiInt[0] != is && groupTile1->groupHaiInt[2] != ks) {
                return;
            } else if (groupTile1->fulutype != Shuntsu && groupTile1->groupHaiInt[0] != im && groupTile1->groupHaiInt[0] != km && groupTile1->groupHaiInt[0] != ip && groupTile1->groupHaiInt[0] != kp && groupTile1->groupHaiInt[0] != is && groupTile1->groupHaiInt[0] != ks &&
                       groupTile1->groupHaiInt[0] < east) {
                return;
            }
        }
        if (IsMenzenchin2(status)) {
            result->han += 2;
            result->yaku[(*yakunum)++] = Honchantaiyaochuu;
        } else {
            result->han += 1;
            result->yaku[(*yakunum)++] = HonchantaiyaochuuF;
        }
    }
}

/// @brief 判断是否三色同刻
/// @param status 
/// @param yakunum 
void IsSanshoukudoujun(Status status, int *yakunum) {
    int count = 0, val[4];
    if (!IsMenzenchin1(status)) {
        for (int i = 0; i < sizeof(groupTile1) / sizeof(groupTile1[0]); i++) {
            if (groupTile1[i].fulutype == Shuntsu) {
                val[count++] = groupTile1[i].groupHaiInt[0];
            }
        }
    }
    for (int i = 0; i < mentsuType.shuntsunum; i++) {
        val[count++] = mentsuType.shun[i][0];
    }
    int bucket[10] = {0};
    if (count >= 3) {
        for (int i = 0; i < count - 1; i++) {
            bucket[val[i] % 9]++;
        }
    }
    for (int i = 0; i < 10; i++) {
        if (bucket[i] >= 3) {
            if (IsMenzenchin2(status)) {
                result->han += 2;
                result->yaku[(*yakunum)++] = Sanshokudoujun;
                return;
            } else {
                result->han += 1;
                result->yaku[(*yakunum)++] = SanshokudoujunF;
                return;
            }
        }
    }
}

/// @brief 判断是否为一气通贯
/// @param status 
/// @param yakunum 
void IsIttsu(Status status, int *yakunum) {
    int count = 0, val[4];
    if (!IsMenzenchin1(status)) {
        for (int i = 0; i < sizeof(groupTile1) / sizeof(groupTile1[0]); i++) {
            if (groupTile1[i].fulutype == Shuntsu) {
                val[count++] = groupTile1[i].groupHaiInt[0];
            }
        }
    }
    for (int i = 0; i < mentsuType.shuntsunum; i++) {
        val[count++] = mentsuType.shun[i][0];
    }
    int bucket[east] = {0};
    if (count >= 3) {
        for (int i = 0; i < count - 1; i++) {
            bucket[val[i] % 3 + val[i] / 9]++;
        }
    }
    for (int i = 0; i < east; i++) {
        if (bucket[i] >= 3) {
            if (IsMenzenchin2(status)) {
                result->han += 2;
                result->yaku[(*yakunum)++] = Ikkitsuukan;
                return;
            } else {
                result->han += 1;
                result->yaku[(*yakunum)++] = IkkitsuukanF;
                return;
            }
        }
    }
}

/// @brief 判断是否七对子
/// @param status 
/// @param yakunum 
/// @param handTile1 
void IsChiitoitsu(Status status, int *yakunum, int handTile1[]) {
    for (int i = 0; i < sizeof(handTile1); i += 2)
        if (handTile1[i] != handTile1[i + 1] || handTile1[i + 1] == handTile1[i + 2])
            return;
    result->han+= 2;
    result->yaku[(*yakunum)++] = Chiitoitsu;
}

//////////////////////////////////////////////////////////////////以下为宝牌加番///////////////////////////////////////////////////////////////////////

/// @brief 增加宝牌番数
/// @param status 
/// @param handTile1 
/// @param groupTile1 
/// @param dora1 
void AddDora(Status status, int *handTile1, GroupInt *groupTile1, int *dora1) {
    for (int i = 0; i < sizeof(handTile1) / sizeof(handTile1[0]); i++) {
        for (int j = 0; j < sizeof(dora1) / sizeof(dora1[0]); i++) {
            if (dora1[j] < east) {
                if (dora1[j] % 9 + dora1[j] / 9 + 1 == handTile1[i]) {
                    result->han++;
                }
            } else if (dora1[j] < north && dora1[j] + 1 == handTile1[i]) {
                result->han++;
            } else if (dora1[j] == north && handTile1[i] == east) {
                result->han++;
            } else if (dora1[j] < zhong && dora1[j] + 1 == handTile1[i]) {
                result->han++;
            } else if (dora1[j] == zhong && handTile1[i] == bai) {
                result->han++;
            }
        }
    }
    if (IsMenzenchin1(status)) {
        for (int i = 0; i < sizeof(groupTile1) / sizeof(groupTile1[0]); i++) {
            for (int k = 0; k < sizeof(groupTile1[i].groupHaiInt) / sizeof(groupTile1[i].groupHaiInt[0]); k++) {
                for (int j = 0; j < sizeof(dora1) / sizeof(dora1[0]); j++) {
                    if (dora1[j] < east) {
                        if (dora1[j] % 9 + dora1[j] / 9 + 1 == groupTile1[i].groupHaiInt[k]) {
                            result->han++;
                        }
                    } else if (dora1[j] < north && dora1[j] + 1 == groupTile1[i].groupHaiInt[k]) {
                        result->han++;
                    } else if (dora1[j] == north && groupTile1[i].groupHaiInt[k] == east) {
                        result->han++;
                    } else if (dora1[j] < zhong && dora1[j] + 1 == groupTile1[i].groupHaiInt[k]) {
                        result->han++;
                    } else if (dora1[j] == zhong && groupTile1[i].groupHaiInt[k] == bai) {
                        result->han++;
                    }
                }
            }
        }
    }
    result->han += Dora;
}

/// @brief 增加里宝牌番数
/// @param status 
/// @param handTile1 
/// @param groupTile1 
/// @param uradora1 
void AddUradora(Status status, int *handTile1, GroupInt *groupTile1, int *uradora1) {
    for (int i = 0; i < sizeof(handTile1) / sizeof(handTile1[0]); i++) {
        for (int j = 0; j < sizeof(uradora1) / sizeof(uradora1[0]); i++) {
            if (uradora1[j] < east) {
                if (uradora1[j] % 9 + uradora1[j] / 9 + 1 == handTile1[i]) {
                    result->han++;
                }
            } else if (uradora1[j] < north && uradora1[j] + 1 == handTile1[i]) {
                result->han++;
            } else if (uradora1[j] == north && handTile1[i] == east) {
                result->han++;
            } else if (uradora1[j] < zhong && uradora1[j] + 1 == handTile1[i]) {
                result->han++;
            } else if (uradora1[j] == zhong && handTile1[i] == bai) {
                result->han++;
            }
        }
    }
    if (IsMenzenchin1(status)) {
        for (int i = 0; i < sizeof(groupTile1) / sizeof(groupTile1[0]); i++) {
            for (int k = 0; k < sizeof(groupTile1[i].groupHaiInt) / sizeof(groupTile1[i].groupHaiInt[0]); k++) {
                for (int j = 0; j < sizeof(uradora1) / sizeof(uradora1[0]); j++) {
                    if (uradora1[j] < east) {
                        if (uradora1[j] % 9 + uradora1[j] / 9 + 1 == groupTile1[i].groupHaiInt[k]) {
                            result->han++;
                        }
                    } else if (uradora1[j] < north && uradora1[j] + 1 == groupTile1[i].groupHaiInt[k]) {
                        result->han++;
                    } else if (uradora1[j] == north && groupTile1[i].groupHaiInt[k] == east) {
                        result->han++;
                    } else if (uradora1[j] < zhong && uradora1[j] + 1 == groupTile1[i].groupHaiInt[k]) {
                        result->han++;
                    } else if (uradora1[j] == zhong && groupTile1[i].groupHaiInt[k] == bai) {
                        result->han++;
                    }
                }
            }
        }
    }
}
