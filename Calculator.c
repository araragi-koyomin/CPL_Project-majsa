#include "Calculator.h"

/// @brief 计算符数
/// @param status 
/// @param handTile 
/// @param groupTile1 
void CalFu(Status status, int handTile[], GroupInt groupTile1[]) {
    /*特殊规则*/
    // 七对子
    for (int i = 0; i < sizeof(resultTemp->yaku) / sizeof(resultTemp->yaku[0]); i++) {
        if (resultTemp->yaku[i] == Chiitoitsu) {
            resultTemp->fu = 25;
            return;
        }
    }
    // 平和自摸
    int count = 0;
    for (int i = 0; i < sizeof(resultTemp->yaku) / sizeof(resultTemp->yaku[0]); i++) {
        if (resultTemp->yaku[i] == Pinhu || resultTemp->yaku[i] == Menzenchintsumo) {
            count++;
        }
    }
    if (count == 2) {
        resultTemp->fu = 20;
        return;
    }

    /*和牌符*/

    // 底符
    resultTemp->fu += 20;
    // 门前清荣和
    if (IsMenzenchin4(status) && result->type == RON) {
        resultTemp->fu += 10;
    }
    // 自摸和
    if (result->type = TSUMO) {
        resultTemp->fu += 2;
    }

    /*听牌符*/

    // 单骑听牌
    if (currentTile1 == mentsuType.jyan[0]) {
        resultTemp->fu += 2;
    }
    // 边张听牌
    for (int i = 0; i < mentsuType.shuntsunum; i++) {
        if (currentTile1 == mentsuType.shun[i][0] || currentTile1 == mentsuType.shun[i][2]) {
            resultTemp->fu += 2;
            break;
        }
    }
    // 嵌张听牌
    for (int i = 0; i < mentsuType.shuntsunum; i++) {
        if (currentTile1 == mentsuType.shun[i][1]) {
            resultTemp->fu += 2;
            break;
        }
    }
    
    /*面子符*/
    
    // 中张明刻
    for (int i = 0; i < mentsuType.koutsunum; i++) {
        if (currentTile1 == mentsuType.kou[i][0]) {
            resultTemp->fu += 2;
            // 幺九明刻
            if (currentTile1 >= east || currentTile1 == im || currentTile1 == km || currentTile1 == ip || currentTile1 == kp || currentTile1 == is || currentTile1 == ks) {
                resultTemp->fu += 4;
            }
            break;
        }
    }
    // 中张暗刻
    for (int i = 0; i < mentsuType.koutsunum; i++) {
        if (currentTile1 != mentsuType.kou[i][0]) {
            resultTemp->fu += 4;
            // 幺九暗刻
            if (mentsuType.kou[i][0] >= east || mentsuType.kou[i][0] == im || mentsuType.kou[i][0] == km || mentsuType.kou[i][0] == ip || mentsuType.kou[i][0] == kp || mentsuType.kou[i][0] == is || mentsuType.kou[i][0] == ks) {
                resultTemp->fu += 8;
            }
            break;
        }
    }
    // 中张明暗杠
    if (!IsMenzenchin3(status)) {
        for (int i = 0; i < sizeof(groupTile1) / sizeof(groupTile1[0]); i++) {
            if (groupTile1[i].fulutype == Ankan) {
                resultTemp->fu += 16;
                // 幺九明杠
                if (groupTile1[i].groupHaiInt[0] >= east || groupTile1[i].groupHaiInt[0] == im || groupTile1[i].groupHaiInt[0] == km || groupTile1[i].groupHaiInt[0] == ip || groupTile1[i].groupHaiInt[0] == kp || groupTile1[i].groupHaiInt[0] == is || groupTile1[i].groupHaiInt[0] == ks) {
                    resultTemp->fu += 32;
                }
            } else if (groupTile1[i].fulutype == Kantsu) {
                resultTemp->fu += 8;
                if (groupTile1[i].groupHaiInt[0] >= east || groupTile1[i].groupHaiInt[0] == im || groupTile1[i].groupHaiInt[0] == km || groupTile1[i].groupHaiInt[0] == ip || groupTile1[i].groupHaiInt[0] == kp || groupTile1[i].groupHaiInt[0] == is || groupTile1[i].groupHaiInt[0] == ks) {
                    resultTemp->fu += 16;
                }
            }
        }
    }

    /*雀头符*/
    // 役牌雀头
    if (mentsuType.jyan[0] >= east || mentsuType.jyan[0] == im || mentsuType.jyan[0] == km || mentsuType.jyan[0] == ip || mentsuType.jyan[0] == kp || mentsuType.jyan[0] == is || mentsuType.jyan[0] == ks) {
        resultTemp->fu += 2;
    }
    // 连风雀头
    if (mentsuType.jyan[0] == status.bakaze && mentsuType.jyan[0] == status.jikaze) {
        resultTemp->fu += 4;
    }

    /*合计*/
    if (resultTemp->fu % 10 != 0) {
        resultTemp->fu = (resultTemp->fu / 10 + 1) * 10;
    }

    /*特殊规则*/
    // 吃
    if (!IsMenzenchin4(status)) {
        for (int i = 0; i < sizeof(groupTile1) / sizeof(groupTile1[0]); i++) {
            if (groupTile1[i].fulutype == Shuntsu && resultTemp->fu <= 30) {
                resultTemp->fu = 30;
            }
        }
    }
}

void CalPoi();