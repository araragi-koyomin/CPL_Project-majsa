#include "YakuChecker.h"
#include "Calculator.h"

//////// 整体思路：先判断双倍役满牌型，然后是役满，接下来是会互相覆盖的牌型，如两杯口 > 七对子 > 一杯口, 以及 两立直 > 立直
////////////////////////////////////////////////////////下为用来判断番数的主要函数////////////////////////////////////////

void YakuCheck(Status status, int handTile2[], GroupInt groupTile1[], int discardTile1[], int currentTile) {
    int yakunum = 0;
    // 首先判断役满
    if (!IsJunseichuurenpoutou(status, &yakunum, handTile2)) {
        IsChuurenpoutou(status, &yakunum, handTile2);
    }
    IsKokushimusou(status, &yakunum, handTile2);
    IsDaisuushii(status, &yakunum);
    if (!IsSuuankoutanki(status, &yakunum)) {
        IsSuuankou(status, &yakunum);
    }
    IsShousuushii(status, &yakunum);
    IsTenhou(status, &yakunum);
    IsChiihou(status, &yakunum);
    IsRyuuiisou(status, &yakunum, handTile2);
    IsChinroutou(status, &yakunum, handTile2);
    IsSuukantsu(status, &yakunum);
    IsTsuiisou(status, &yakunum, handTile2);
    IsDaisangen(status, &yakunum);

    if (yakunum > 0) { 
        // 若为役满，则直接进行点数结算，不进行后续役种判断操作
        resultTemp->type = status.currentPlayer == JICHA ? TSUMO : RON;
        qsort(resultTemp->yaku, yakunum, sizeof(int), CmpYaku);
        Calculator(status, handTile2, groupTile1);
        return;
    }

    // 接下来判断会被覆盖的役
    if (!IsJunchantaiyao(status, &yakunum, handTile2)) {
        IsChantaiyao(status, &yakunum);
    }
    if (!IsRyanpeikou(status, &yakunum)) {
        if (!IsChiitoitsu(status, &yakunum, handTile2)) {
            IsIipeikou(status, &yakunum);
        }
    }
    if (!IsChinitsu(status, &yakunum, handTile2)) {
        IsHonitsu(status, &yakunum, handTile2);
    }

    //接下来是立直役的累加判断
    if (IsRiichi(status, &yakunum)) {
        IsDoubleRiichi(status, &yakunum);
        IsIppatsu(status, &yakunum);
        AddUradora(status, handTile2, groupTile1, uradora1);
    }

    // 接下来是其他役的累加
    IsMenzenchintsumohou(status, &yakunum);
    IsPinfu(status, &yakunum);
    IsHaiteiraoyue(status, &yakunum);
    IsHouteiraoyui(status, &yakunum);
    IsRinshankaihou(status, &yakunum);
    IsTanyao(status, &yakunum, handTile2);
    IsYakuhai(status, &yakunum);
    IsHonroutou(status, &yakunum, handTile2);
    IsSankantsu(status, &yakunum);
    IsSanankou(status, &yakunum);
    IsIttsu(status, &yakunum);
    IsSanshokudoukou(status, &yakunum);
    IsSanshoukudoujun(status, &yakunum);
    IsShousangan(status, &yakunum);
    IsToitoi(status, &yakunum);

    if (yakunum > 0) {
        resultTemp->type = status.currentPlayer == JICHA ? TSUMO : RON;
        qsort(resultTemp->yaku, yakunum, sizeof(int), CmpYaku);
        AddDora(status, handTile2, groupTile1, dora1);
        Calculator(status, handTile2, groupTile1);
        return;
    }
}

////////////////////////////////////////////////////////下面为1番役/////////////////////////////////////////////////////

/// @brief 判断是否立直
/// @param status
/// @param yakunum
bool IsRiichi(Status status, int *yakunum) {
    if (status.isRiichi) {
        resultTemp->han++;
        resultTemp->yaku[(*yakunum)++] = Riichi;
        return true;
    }
    return false;
}

/// @brief 判断是否双立直
/// @param status 
/// @param yakunum 
void IsDoubleRiichi(Status status, int *yakunum) {
    if (status.isDoubleRiichi) {
        resultTemp->han++;
        resultTemp->yaku[(*yakunum)] = doubleRiichi;
    }
}

/// @brief 判断是否一发
/// @param status 
/// @param yakunum 
void IsIppatsu(Status status, int *yakunum) {
    if (status.isIppatsu) {
        resultTemp->han++;
        resultTemp->yaku[(*yakunum)++] = Ippatsu;
    }
}

/// @brief 判断是否门前清自摸和
/// @param status 
/// @param yakunum 
void IsMenzenchintsumohou(Status status, int *yakunum) {
    if (IsMenzenchin2(status) && status.currentPlayer == JICHA) {
        resultTemp->han++;
        resultTemp->yaku[(*yakunum)++] = Menzenchintsumo;
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
        resultTemp->han++;
        resultTemp->yaku[(*yakunum)++] = Pinhu;
    } 
}

/// @brief 判断是否一杯口
/// @param status 
/// @param yakunum 
void IsIipeikou(Status status, int *yakunum) {
    if (!IsMenzenchin2(status)) return;
    int flag = 0;
    if (mentsuType.shuntsunum >= 2) {
        for (int i = 0; i < mentsuType.shuntsunum - 1; i++) {
            for (int j = i + 1; j < mentsuType.shuntsunum; j++) {
                if (mentsuType.shun[i][0] == mentsuType.shun[j][0]) {
                    resultTemp->han++;
                    resultTemp->yaku[(*yakunum)++] = Iipeikou;
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
        resultTemp->han++;
        resultTemp->yaku[(*yakunum)++] = Haiteiraoyue;
    }
}

/// @brief 判断是否河底捞鱼
/// @param status 
/// @param yakunum 
void IsHouteiraoyui(Status status, int *yakunum) {
    if (status.remainTileCount == 0 && status.currentPlayer != JICHA) {
        resultTemp->han++;
        resultTemp->yaku[(*yakunum)++] = Houteiraoyui;
    }
}

/// @brief 判断是否岭上开花
/// @param status 
/// @param yakunum 
void IsRinshankaihou(Status status, int *yakunum) {
    if (status.isRinshan) {
        resultTemp->han++;
        resultTemp->yaku[(*yakunum)++] = Rinshankaihou;
    }
}

/// @brief 判断是否断幺
/// @param status 
/// @param yakunum 
/// @param handTile2 
void IsTanyao(Status status, int *yakunum, int *handTile2) {
    for (int i = 0; i < handTilelLen; i++) {
        if (handTile2[i] == im || handTile2[i] == km || handTile2[i] == ip || handTile2[i] == kp || handTile2[i] == is || handTile2[i] >= ks) {
            return;
        }
    }
    if (!IsMenzenchin1(status)) {
        for (int i = 0; i < GroupTileLen; i++) {
            for (int j = 0; j < 3; j++) {
                if (groupTile1[i].groupHaiInt[j] == im || groupTile1[i].groupHaiInt[j] == km || groupTile1[i].groupHaiInt[j] == ip || groupTile1[i].groupHaiInt[j] == kp || groupTile1[i].groupHaiInt[j] == is || groupTile1[i].groupHaiInt[j] >= ks) {
                    return;
                }
            }
        }
    }
    resultTemp->han++;
    resultTemp->yaku[(*yakunum)++] = Tanyao;
}

/// @brief 判断是否有役牌
/// @param status 
/// @param yakunum 
void IsYakuhai(Status status, int *yakunum) {
    for (int i = 0; i < mentsuType.koutsunum; i++) {
        if (mentsuType.kou[i][0] == bai) {
            resultTemp->han++;
            resultTemp->yaku[(*yakunum)++] = YakuhaiHaku;
        } else if (mentsuType.kou[i][0] == fa) {
            resultTemp->han++;
            resultTemp->yaku[(*yakunum)++] = YakuhaiHatsu;
        } else if (mentsuType.kou[i][0] == zhong) {
            resultTemp->han++;
            resultTemp->yaku[(*yakunum)++] = YakuhaiChun;
        } else if (mentsuType.kou[i][0] == status.bakaze) {
            resultTemp->han++;
            resultTemp->yaku[(*yakunum)++] = YakuhaiBakaze;
        } else if (mentsuType.kou[i][0] == status.jikaze) {
            resultTemp->han++;
            resultTemp->yaku[(*yakunum)++] = YakuhaiJikaze;
        }
    }
    if (!IsMenzenchin1(status)) {
        for (int i = 0; i < GroupTileLen; i++) {
            if (groupTile1[i].groupHaiInt[0] == bai) {
                resultTemp->han++;
                resultTemp->yaku[(*yakunum)++] = YakuhaiHaku;
            } else if (groupTile1[i].groupHaiInt[0] == fa) {
                resultTemp->han++;
                resultTemp->yaku[(*yakunum)++] = YakuhaiHatsu;
            } else if (groupTile1[i].groupHaiInt[0] == zhong) {
                resultTemp->han++;
                resultTemp->yaku[(*yakunum)++] = YakuhaiChun;
            } else if (groupTile1[i].groupHaiInt[0] == status.bakaze) {
                resultTemp->han++;
                resultTemp->yaku[(*yakunum)++] = YakuhaiBakaze;
            } else if (groupTile1[i].groupHaiInt[0] == status.jikaze) {
                resultTemp->han++;
                resultTemp->yaku[(*yakunum)++] = YakuhaiJikaze;
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////以下为双倍役满//////////////////////////////////////////////////////////////////////////

/// @brief 判断是否纯九说走就走
/// @param status 
/// @param yakunum 
/// @param handTile2 
bool IsJunseichuurenpoutou(Status status, int *yakunum, int handTile2[]) {
    if (!mentsuType.koutsunum + mentsuType.shuntsunum) return false;
    int bucket[zhong + 1] = {0}, flag = 0;
    if (!IsMenzenchin1(status)) return false;
    for (int i = 0; i < 14; i++) {
        bucket[handTile2[i]]++;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = im; j <= km; j++) {
            if (!bucket[handTile2[j + i * 9]]) {
                break;
            }
        }
        flag = 1;
    }
    if (!flag) return false;
    for (int i = 0; i < 3; i++) {
        if (bucket[im + i * 9] >= 3 && bucket[nm + 9 * i] && bucket[sm + 9 * i] && bucket[shm + 9 * i] && bucket[gm + 9 * i] && bucket[rm + 9 * i]
            && bucket[nm + 9 * i] && bucket[hm + 9 * i] && bucket[km + 9 * i] >= 3 && (bucket[currentTile1] == 2 || bucket[currentTile1] == 4)) {
            resultTemp->han -= 2;
            resultTemp->yaku[(*yakunum)++] = Chuurenkyuumenmachi;
            return true;
        }
    }
    return false;
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
        for (int i = 0; i < GroupTileLen; i++) {
            if (groupTile1[i].groupHaiInt[0] >= east && groupTile1[i].groupHaiInt[0] <= north) {
                count++;
            }
        }
    }
    if (count == 4) {
        resultTemp->han -= 2;
        resultTemp->yaku[(*yakunum)++] = Daisuushi;
    }
}

/// @brief 判断是否四暗刻单骑
/// @param status 
/// @param yakunum 
bool IsSuuankoutanki(Status status, int *yakunum) {
    int count = 0;
    if (!IsMenzenchin1(status)) {
        for (int i = 0; i < GroupTileLen; i++) {
            if (groupTile1[i].fulutype == Ankan) {
                count++;
            }
        }
    }
    if (IsMenzenchin1(status) && mentsuType.koutsunum + count == 4 && mentsuType.jyan[0] == currentTile1) {
        resultTemp->han -= 2;
        resultTemp->yaku[(*yakunum)++] = Suuankoutanki;
        return true;
    }
    return false;
}

/// @brief 判断是否是国士无双（十三面）
/// @param status 
/// @param yakunum 
/// @param handTile2 
void IsKokushimusou(Status status, int *yakunum, int handTile2[]) {
    if (mentsuType.koutsunum + mentsuType.shuntsunum) return;
    int counts[zhong + 1] = {0}, flag = 1;
    for (int i = 0; i < 14; i++) {
        if (handTile2[i] == im || handTile2[i] == km || handTile2[i] == ip || handTile2[i] == kp || handTile2[i] == is || handTile2[i] >= ks)
            counts[handTile2[i]]++;
        else return;
    }
    for (int i = im; i <= zhong; i++) {
        if (counts[i] > 2) return;
        else if (counts[i] != 1 && counts[i] != counts[currentTile1]) flag = 0;
    }
    if (flag) {
        resultTemp->han -= 1;
        resultTemp->yaku[(*yakunum)++] = Kokushimusou;
    } else {
        resultTemp->han -= 2;
        resultTemp->yaku[(*yakunum)++] = Kokushijuusanmenmachi;
    }
}

///////////////////////////////////////////////////////////////////下为役满/////////////////////////////////////////////////////////////////////

/// @brief 判断是否天和
/// @param status 
/// @param yakunum 
void IsTenhou(Status status, int *yakunum) {
    if (status.currentPlayer == JICHA && status.remainTileCount == 69) {
        resultTemp->han -= 1;
        resultTemp->yaku[(*yakunum)++] = Tenhou;
    }
}

/// @brief 判断是否地和
/// @param status 
/// @param yakunum 
void IsChiihou(Status status, int *yakunum) {
    if (status.currentPlayer != JICHA && status.remainTileCount >= 66) {
        resultTemp->han -= 1;
        resultTemp->yaku[(*yakunum)++] = Chihou;
    }
}

/// @brief 判断是否四暗刻
/// @param status 
/// @param yakunum 
void IsSuuankou(Status status, int *yakunum) {
    int count = 0;
    if (!IsMenzenchin1(status)) {
        for (int i = 0; i < GroupTileLen; i++) {
            if (groupTile1[i].fulutype == Ankan) {
                count++;
            }
        }
    }
    if (IsMenzenchin1(status) && mentsuType.koutsunum + count == 4 && mentsuType.jyan[0] != currentTile1 && status.currentPlayer == JICHA) {
        resultTemp->han -= 1;
        resultTemp->yaku[(*yakunum)++] = Suuankou;
    }
}

/// @brief 判断是否九莲宝灯
/// @param status 
/// @param yakunum 
/// @param handTile2 
void IsChuurenpoutou(Status status, int *yakunum, int *handTile2) {
    if (!mentsuType.koutsunum + mentsuType.shuntsunum) return;
    int bucket[zhong + 1] = {0}, flag = 0;
    if (!IsMenzenchin1(status)) {
        for (int i = 0; i < GroupTileLen; i++) {
            if (groupTile1[i].fulutype != Ankan) return; 
            else {
                bucket[groupTile1[i].groupHaiInt[0]]+=4;
            }
        }
    }
    for (int i = 0; i < handTilelLen; i++) {
        bucket[handTile2[i]]++;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = im; j <= km; j++) {
            if (!bucket[handTile2[j + i * 9]]) {
                break;
            }
        }
        flag = 1;
    }
    if (!flag) return;
    for (int i = 0; i < 3; i++) {
        if (bucket[im + i * 9] >= 3 && bucket[nm + 9 * i] && bucket[sm + 9 * i] && bucket[shm + 9 * i] && bucket[gm + 9 * i] && bucket[rm + 9 * i]
            && bucket[nm + 9 * i] && bucket[hm + 9 * i] && bucket[km + 9 * i] >= 3 && (bucket[currentTile1] == 1 || bucket[currentTile1] == 3)) {
            resultTemp->han -= 1;
            resultTemp->yaku[(*yakunum)++] = Chuurenpoutou;
        }
    }
}

/// @brief 判断是否绿一色
/// @param status 
/// @param yakunum 
/// @param handTile2 
void IsRyuuiisou(Status status, int *yakunum, int *handTile2) {
    for (int i = 0; i < handTilelLen; i++) {
        if (handTile2[i] != ns && handTile2[i] != ss && handTile2[i] != ys && handTile2[i] != rs && handTile2[i] != hs && handTile2[i] != fa) {
            return;
        }
    }
    if (!IsMenzenchin1(status)) {
        for (int i = 0; i < GroupTileLen; i++) {
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
    resultTemp->han -= 1;
    resultTemp->yaku[(*yakunum)++] = Ryuuiisou;
}

/// @brief 判断是否清老头
/// @param status 
/// @param yakunum 
/// @param handTile2 
void IsChinroutou(Status status, int *yakunum, int handTile2[]) {
    for (int i = 0; i < handTilelLen; i++) {
        if (handTile2[i] != im && handTile2[i] != km && handTile2[i] != ip && handTile2[i] != kp && handTile2[i] != is && handTile2[i] != ks) {
            return;
        }
    }
    if (!IsMenzenchin1(status)) {
        for (int i = 0; i < GroupTileLen; i++) {
            if (groupTile1[i].fulutype == Shuntsu) return;
            else {
                if (groupTile1[i].groupHaiInt[0] != im && groupTile1[i].groupHaiInt[0] != km && groupTile1[i].groupHaiInt[0] != ip && groupTile1[i].groupHaiInt[0] != kp && 
                    groupTile1[i].groupHaiInt[0] != is && groupTile1[i].groupHaiInt[0] != ks) {
                    return;
                }
            }
        }
    }
    resultTemp->han -= 1;
    resultTemp->yaku[(*yakunum)++] = Chinroutou;
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
    resultTemp->han -= 1;
    resultTemp->yaku[(*yakunum)++] = Suukantsu;
}

/// @brief 判断是否字一色
/// @param status 
/// @param yakunum 
/// @param handTile2 
void IsTsuiisou(Status status, int *yakunum, int handTile2[]) {
    for (int i = 0; i < handTilelLen; i++) {
        if (handTile2[i] < east) {
            return;
        }
    }
    if (!IsMenzenchin1(status)) {
        for (int i = 0; i < GroupTileLen; i++) {
            if (groupTile1[i].fulutype == Shuntsu) return;
            else {
                if (groupTile1[i].groupHaiInt[0] < east) {
                    return;
                }
            }
        }
    }
    resultTemp->han -= 1;
    resultTemp->yaku[(*yakunum)++] = Tsuuiisou;
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
        for (int i = 0; i < GroupTileLen; i++) {
            if (groupTile1[i].groupHaiInt[0] >= east && groupTile1[i].groupHaiInt[0] <= north) {
                count++;
            }
        }
    }
    if (count == 3 && mentsuType.jyan[0] >= east && mentsuType.jyan[0] <= north) {
        resultTemp->han -= 1;
        resultTemp->yaku[(*yakunum)++] = Shousuushi;
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
        for (int i = 0; i < GroupTileLen; i++) {
            if (groupTile1[i].groupHaiInt[0] >= bai) {
                count++;
            }
        }
    }
    if (count == 3) {
        resultTemp->han -= 1;
        resultTemp->yaku[(*yakunum)++] = Daisangen;
    }
}

/////////////////////////////////////////////////////////以下为6番役//////////////////////////////////////////////////////////////////////////

/// @brief 判断是否清一色
/// @param status 
/// @param yakunum 
/// @param handTile2 
bool IsChinitsu(Status status, int *yakunum, int *handTile2) {
    int flag = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < handTilelLen; j++) {
            if (handTile2[j] < im + i * 9 || handTile2[j] > km + 9 * i) {
                goto NOT;
            }
        }
        if (!IsMenzenchin1(status)) {
            for (int j = 0; j < GroupTileLen; j++) {
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
            resultTemp->han += 6;
            resultTemp->yaku[(*yakunum)++] = Chinitsu;
            return true;
        } else {
            resultTemp->han += 5;
            resultTemp->yaku[(*yakunum)++] = ChinitsuF;
            return true;
        }
    }
    return false;
}

/////////////////////////////////////////////////////////以下为3番役//////////////////////////////////////////////////////////////////////////

/// @brief 判断是否两杯口
/// @param status 
/// @param yakunum 
bool IsRyanpeikou(Status status, int *yakunum) {
    if (mentsuType.shuntsunum == 4) {
        if (mentsuType.shun[0][0] == mentsuType.shun[1][0] && mentsuType.shun[2][0] == mentsuType.shun[3][0] ||
            mentsuType.shun[0][0] == mentsuType.shun[2][0] && mentsuType.shun[1][0] == mentsuType.shun[3][0] ||
            mentsuType.shun[0][0] == mentsuType.shun[3][0] && mentsuType.shun[1][0] == mentsuType.shun[2][0]) {
            resultTemp->han += 3;
            resultTemp->yaku[(*yakunum)++] = Ryanpeikou;
            return true;
        }
    }
    return false;
}

/// @brief 判断是否纯全带幺九
/// @param status 
/// @param yakunum 
/// @param handTile2 
bool IsJunchantaiyao(Status status, int *yakunum, int handTile2[]) {
    if (!mentsuType.koutsunum + mentsuType.shuntsunum) return false;
    for (int i = 0; i < mentsuType.koutsunum; i++) {
        if (mentsuType.kou[i][0] != im && mentsuType.kou[i][0] != km && mentsuType.kou[i][0] != ip && mentsuType.kou[i][0] != ks && mentsuType.kou[i][0] != is && mentsuType.kou[i][0] != kp) {
            return false;
        }
    }
    for (int i = 0; i < mentsuType.shuntsunum; i++) {
        if ((mentsuType.shun[i][0] != im && mentsuType.shun[i][2] != km) && (mentsuType.shun[i][0] != ip && mentsuType.shun[i][2] != kp) && (mentsuType.shun[i][0] != is && mentsuType.shun[i][2] != ks)) {
            return false;
        }
    }
    if (IsMenzenchin1(status)) {
        resultTemp->han += 3;
        resultTemp->yaku[(*yakunum)++] = Junchantaiyaochuu;
        return true;
    } else {
        for (int i = 0; i < GroupTileLen; i++) {
            if (groupTile1->fulutype == Shuntsu && groupTile1->groupHaiInt[0] != im && groupTile1->groupHaiInt[2] != km && groupTile1->groupHaiInt[0] != ip && groupTile1->groupHaiInt[2] != kp && groupTile1->groupHaiInt[0] != is && groupTile1->groupHaiInt[2] != ks) {
                return false;
            } else if (groupTile1->fulutype != Shuntsu && groupTile1->groupHaiInt[0] != im && groupTile1->groupHaiInt[0] != km && groupTile1->groupHaiInt[0] != ip && groupTile1->groupHaiInt[0] != kp && groupTile1->groupHaiInt[0] != is && groupTile1->groupHaiInt[0] != ks) {
                return false;
            }
        }
        if (IsMenzenchin2(status)) {
            resultTemp->han += 3;
            resultTemp->yaku[(*yakunum)++] = Junchantaiyaochuu;
            return true;
        } else {
            resultTemp->han += 2;
            resultTemp->yaku[(*yakunum)++] = JunchantaiyaochuuF;
            return true;
        }
    }
    return false;
}

/// @brief 判断是否混一色
/// @param status 
/// @param yakunum 
/// @param handTile2 
void IsHonitsu(Status status, int *yakunum, int handTile2[]) {
    int flag = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < handTilelLen; j++) {
            if (handTile2[j] >= east) continue;
            if (handTile2[j] < im + i * 9 || handTile2[j] > km + 9 * i) {
                goto NOT;
            }
        }
        if (!IsMenzenchin1(status)) {
            for (int j = 0; j < GroupTileLen; j++) {
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
            resultTemp->han += 3;
            resultTemp->yaku[(*yakunum)++] = Honitsu;
        } else {
            resultTemp->han += 2;
            resultTemp->yaku[(*yakunum)++] = HonitsuF;
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
        for (int i = 0; i < GroupTileLen; i++) {
            if (groupTile1[i].groupHaiInt[0] >= bai) {
                count++;
            }
        }
    }
    if (count == 2 && mentsuType.jyan[0] >= bai) {
        resultTemp->han += 2;
        resultTemp->yaku[(*yakunum)++] = Shousangen;
    }
}

/// @brief 判断是否混老头
/// @param status 
/// @param yakunum 
/// @param handTile2 
void IsHonroutou(Status status, int *yakunum, int *handTile2) {
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < handTilelLen; i++) {
            if (handTile2[i] != im + j * 9 && handTile2[i] != km + 9 * j && handTile2[j] < east) {
                return;
            }
        }
    }
    if (!IsMenzenchin1(status)) {
        for (int j = 0; j < 3; j++) {
            for (int i = 0; i < GroupTileLen; i++) {
                for (int k = 0; k < GroupEachLen[i]; k++) {
                    if (groupTile1[i].groupHaiInt[k] != im + 9 * j && groupTile1[i].groupHaiInt[k] != km + 9 * j && groupTile1[i].groupHaiInt[k] < east) {
                        return;
                    }
                }
            }
        }
    }
    resultTemp->han += 2;
    resultTemp->yaku[(*yakunum)++] = Honroutou;
}

/// @brief 判断是否三杠子
/// @param status 
/// @param yakunum 
void IsSankantsu(Status status, int *yakunum) {
    int count = 0;
    if (IsMenzenchin1(status)) return;
    for (int i = 0; i < GroupTileLen; i++) {
        if (groupTile1[i].fulutype == Ankan || groupTile1[i].fulutype == Kantsu) {
            count++;
        }
    }
    if (count == 3) {
        resultTemp->han += 2;
        resultTemp->yaku[(*yakunum)++] = Sankantsu;
    }
}

/// @brief 判断是否三暗刻
/// @param status 
/// @param yakunum 
void IsSanankou(Status status, int *yakunum) {
    int count = 0;
    if (!IsMenzenchin1(status)) {
        for (int i = 0; i < GroupTileLen; i++) {
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
        resultTemp->han += 2;
        resultTemp->yaku[(*yakunum)++] = Sanankou;
    }
}

/// @brief 判断是否对对和
/// @param status 
/// @param yakunum 
void IsToitoi(Status status, int *yakunum) {
    if (!mentsuType.koutsunum + mentsuType.shuntsunum) return;
    if (mentsuType.shuntsunum) return;
    if (!IsMenzenchin1(status)) {
        for (int i = 0; i < GroupTileLen; i++) {
            if (groupTile1[i].fulutype == Shuntsu) {
                return;
            }
        }
    }
    resultTemp->han += 2;
    resultTemp->yaku[(*yakunum)++] = Toitoihou;
}

/// @brief 判断是否三色同刻
/// @param status 
/// @param yakunum 
void IsSanshokudoukou(Status status, int *yakunum) {
    int count = 0, val[4];
    if (!IsMenzenchin1(status)) {
        for (int i = 0; i < GroupTileLen; i++) {
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
            resultTemp->han += 2;
            resultTemp->yaku[(*yakunum)++] = Sanshokudoukou;
            return;
        }
    }
}

/// @brief 判断是否混全带幺九
/// @param status 
/// @param yakunum 
void IsChantaiyao(Status status, int *yakunum) {
    if (!mentsuType.koutsunum + mentsuType.shuntsunum) return;
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
        resultTemp->han += 2;
        resultTemp->yaku[(*yakunum)++] = Honchantaiyaochuu;
    } else {
        for (int i = 0; i < GroupTileLen; i++) {
            if (groupTile1->fulutype == Shuntsu && groupTile1->groupHaiInt[0] != im && groupTile1->groupHaiInt[2] != km && groupTile1->groupHaiInt[0] != ip && groupTile1->groupHaiInt[2] != kp && groupTile1->groupHaiInt[0] != is && groupTile1->groupHaiInt[2] != ks) {
                return;
            } else if (groupTile1->fulutype != Shuntsu && groupTile1->groupHaiInt[0] != im && groupTile1->groupHaiInt[0] != km && groupTile1->groupHaiInt[0] != ip && groupTile1->groupHaiInt[0] != kp && groupTile1->groupHaiInt[0] != is && groupTile1->groupHaiInt[0] != ks &&
                       groupTile1->groupHaiInt[0] < east) {
                return;
            }
        }
        if (IsMenzenchin2(status)) {
            resultTemp->han += 2;
            resultTemp->yaku[(*yakunum)++] = Honchantaiyaochuu;
        } else {
            resultTemp->han += 1;
            resultTemp->yaku[(*yakunum)++] = HonchantaiyaochuuF;
        }
    }
}

/// @brief 判断是否三色同刻
/// @param status 
/// @param yakunum 
void IsSanshoukudoujun(Status status, int *yakunum) {
    int count = 0, val[4];
    if (!IsMenzenchin1(status)) {
        for (int i = 0; i < GroupTileLen; i++) {
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
                resultTemp->han += 2;
                resultTemp->yaku[(*yakunum)++] = Sanshokudoujun;
                return;
            } else {
                resultTemp->han += 1;
                resultTemp->yaku[(*yakunum)++] = SanshokudoujunF;
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
        for (int i = 0; i < GroupTileLen; i++) {
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
                resultTemp->han += 2;
                resultTemp->yaku[(*yakunum)++] = Ikkitsuukan;
                return;
            } else {
                resultTemp->han += 1;
                resultTemp->yaku[(*yakunum)++] = IkkitsuukanF;
                return;
            }
        }
    }
}

/// @brief 判断是否七对子
/// @param status 
/// @param yakunum 
/// @param handTile2 
bool IsChiitoitsu(Status status, int *yakunum, int handTile2[]) {
    for (int i = 0; i < handTilelLen; i += 2)
        if (handTile2[i] != handTile2[i + 1] || handTile2[i + 1] == handTile2[i + 2])
            return false;
    resultTemp->han+= 2;
    resultTemp->yaku[(*yakunum)++] = Chiitoitsu;
    return true;
}

//////////////////////////////////////////////////////////////////以下为宝牌加番///////////////////////////////////////////////////////////////////////

/// @brief 增加宝牌番数
/// @param status 
/// @param handTile2 
/// @param groupTile1 
/// @param dora1 
void AddDora(Status status, int *handTile2, GroupInt *groupTile1, int *dora1) {
    for (int i = 0; i < handTilelLen; i++) {
        for (int j = 0; j < doraLen; j++) {
            int nextTile;
            if (dora1[j] < east) {
                nextTile = (dora1[j] % 9 == 0) ? dora1[j] - 8 : dora1[j] + 1;
            } else {
                if (dora1[j] == north) {
                    nextTile = east;
                } else if (dora1[j] == zhong) {
                    nextTile = bai;
                } else {
                    nextTile = dora1[j] + 1;
                }
            }
            if (nextTile == handTile2[i]) {
                resultTemp->han++;
            }
        }
    }
    if (IsMenzenchin1(status)) {
        for (int i = 0; i < GroupTileLen; i++) {
            for (int k = 0; k < GroupEachLen[i]; k++) {
                for (int j = 0; j < doraLen; j++) {
                    int nextTile;
                    if (dora1[j] < east) {
                        nextTile = (dora1[j] % 9 == 0) ? dora1[j] - 8 : dora1[j] + 1;
                    }
                    else if (dora1[j] <= north) {
                        nextTile = (dora1[j] == north) ? east : dora1[j] + 1;
                    }
                    else {
                            nextTile = (dora1[j] == zhong) ? bai : dora1[j] + 1;
                    }
                    if (nextTile == groupTile1[i].groupHaiInt[k]) {
                        resultTemp->han++;
                    }
                }
            }
        }
    }
    resultTemp->han += Dora;
}

/// @brief 增加里宝牌番数
/// @param status 
/// @param handTile2 
/// @param groupTile1 
/// @param uradora1 
void AddUradora(Status status, int *handTile2, GroupInt *groupTile1, int *uradora1) {
    for (int i = 0; i < handTilelLen; i++) {
        for (int j = 0; j < doraLen; j++) {
            int nextTile;
            if (uradora1[j] < east) {
                nextTile = (uradora1[j] % 9 == 0) ? uradora1[j] - 8 : uradora1[j] + 1;
            } else {
                if (uradora1[j] == north) {
                    nextTile = east;
                } else if (uradora1[j] == zhong) {
                    nextTile = bai;
                } else {
                    nextTile = uradora1[j] + 1;
                }
            }
            if (nextTile == handTile2[i]) {
                resultTemp->han++;
            }
        }
    }
    if (IsMenzenchin1(status)) {
        for (int i = 0; i < GroupTileLen; i++) {
            for (int k = 0; k < GroupEachLen[i]; k++) {
                for (int j = 0; j < doraLen; j++) {
                    int nextTile;
                    if (uradora1[j] < east) {
                        nextTile = (uradora1[j] % 9 == 0) ? uradora1[j] - 8 : uradora1[j] + 1;
                    }
                    else if (uradora1[j] <= north) {
                        nextTile = (uradora1[j] == north) ? east : uradora1[j] + 1;
                    }
                    else {
                            nextTile = (uradora1[j] == zhong) ? bai : uradora1[j] + 1;
                    }
                    if (nextTile == groupTile1[i].groupHaiInt[k]) {
                        resultTemp->han++;
                    }
                }
            }
        }
    }
}

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
    for (int i = 0; i < GroupTileLen; i++) {
        if (groupTile1[i].fulutype != Ankan) return false;
    }
    return true;
}

int CmpYaku(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}