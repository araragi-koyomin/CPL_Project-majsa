#include "Calculator.h"

/// @brief 计算符数
/// @param status 
/// @param handTile 
/// @param groupTile1 
void CalFu(Status status, int handTile2[], GroupInt groupTile1[]) {
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
        for (int i = 0; i < GroupTileLen; i++) {
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
        for (int i = 0; i < GroupTileLen; i++) {
            if (groupTile1[i].fulutype == Shuntsu && resultTemp->fu <= 30) {
                resultTemp->fu = 30;
            }
        }
    }
}

/// @brief 计算点数
/// @param status 
void CalPoi(Status status) {
    if (status.jikaze == TON) {
        // 一番
        // 荣和
        {
        if (resultTemp->han == 1 && resultTemp->fu == 30 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 1500;
        }
        if (resultTemp->han == 1 && resultTemp->fu == 40 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 2000;
        }
        if (resultTemp->han == 1 && resultTemp->fu == 50 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 2400;
        }
        if (resultTemp->han == 1 && resultTemp->fu == 60 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 2900;
        }
        if (resultTemp->han == 1 && resultTemp->fu == 70 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 3400;
        }
        if (resultTemp->han == 1 && resultTemp->fu == 80 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 3900;
        }
        if (resultTemp->han == 1 && resultTemp->fu == 90 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 4400;
        }
        if (resultTemp->han == 1 && resultTemp->fu == 100 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 4800;
        }
        if (resultTemp->han == 1 && resultTemp->fu == 110 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 5300;
        }
        }
        // 自摸
        {
        if (resultTemp->han == 1 && resultTemp->fu == 30 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 500;
            resultTemp->point[TOIMEN] = 500;
            resultTemp->point[SHIMOCHA] = 500;
        }
        if (resultTemp->han == 1 && resultTemp->fu == 40 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 700;
            resultTemp->point[TOIMEN] = 700;
            resultTemp->point[SHIMOCHA] = 700;
        }
        if (resultTemp->han == 1 && resultTemp->fu == 50 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 800;
            resultTemp->point[TOIMEN] = 800;
            resultTemp->point[SHIMOCHA] = 800;
        }
        if (resultTemp->han == 1 && resultTemp->fu == 60 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 1000;
            resultTemp->point[TOIMEN] = 1000;
            resultTemp->point[SHIMOCHA] = 1000;
        }
        if (resultTemp->han == 1 && resultTemp->fu == 70 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 1200;
            resultTemp->point[TOIMEN] = 1200;
            resultTemp->point[SHIMOCHA] = 1200;
        }
        if (resultTemp->han == 1 && resultTemp->fu == 80 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 1300;
            resultTemp->point[TOIMEN] = 1300;
            resultTemp->point[SHIMOCHA] = 1300;
        }
        if (resultTemp->han == 1 && resultTemp->fu == 90 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 1500;
            resultTemp->point[TOIMEN] = 1500;
            resultTemp->point[SHIMOCHA] = 1500;
        }
        if (resultTemp->han == 1 && resultTemp->fu == 100 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 1600;
            resultTemp->point[TOIMEN] = 1600;
            resultTemp->point[SHIMOCHA] = 1600;
        }
        }
        // 2番
        // 荣和
        {
        if (resultTemp->han == 2 && resultTemp->fu == 25 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 2400;
        }
        if (resultTemp->han == 2 && resultTemp->fu == 30 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 2900;
        }
        if (resultTemp->han == 2 && resultTemp->fu == 40 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 3900;
        }
        if (resultTemp->han == 2 && resultTemp->fu == 50 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 4800;
        }
        if (resultTemp->han == 2 && resultTemp->fu == 60 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 5800;
        }
        if (resultTemp->han == 2 && resultTemp->fu == 70 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 6800;
        }
        if (resultTemp->han == 2 && resultTemp->fu == 80 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 7700;
        }
        if (resultTemp->han == 2 && resultTemp->fu == 90 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 8700;
        }
        if (resultTemp->han == 2 && resultTemp->fu == 100 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 9600;
        }
        if (resultTemp->han == 2 && resultTemp->fu == 110 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 10600;
        }
        }
        // 自摸
        {
        if (resultTemp->han == 2 && resultTemp->fu == 20 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 700;
            resultTemp->point[TOIMEN] = 700;
            resultTemp->point[SHIMOCHA] = 700;
        }
        if (resultTemp->han == 2 && resultTemp->fu == 30 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 1000;
            resultTemp->point[TOIMEN] = 1000;
            resultTemp->point[SHIMOCHA] = 1000;
        }
        if (resultTemp->han == 2 && resultTemp->fu == 40 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 1300;
            resultTemp->point[TOIMEN] = 1300;
            resultTemp->point[SHIMOCHA] = 1300;
        }
        if (resultTemp->han == 2 && resultTemp->fu == 50 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 1600;
            resultTemp->point[TOIMEN] = 1600;
            resultTemp->point[SHIMOCHA] = 1600;
        }
        if (resultTemp->han == 2 && resultTemp->fu == 60 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 2000;
            resultTemp->point[TOIMEN] = 2000;
            resultTemp->point[SHIMOCHA] = 2000;
        }
        if (resultTemp->han == 2 && resultTemp->fu == 70 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 2300;
            resultTemp->point[TOIMEN] = 2300;
            resultTemp->point[SHIMOCHA] = 2300;
        }
        if (resultTemp->han == 2 && resultTemp->fu == 80 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 2600;
            resultTemp->point[TOIMEN] = 2600;
            resultTemp->point[SHIMOCHA] = 2600;
        }
        if (resultTemp->han == 2 && resultTemp->fu == 90 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 2900;
            resultTemp->point[TOIMEN] = 2900;
            resultTemp->point[SHIMOCHA] = 2900;
        }
        if (resultTemp->han == 2 && resultTemp->fu == 100 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 3200;
            resultTemp->point[TOIMEN] = 3200;
            resultTemp->point[SHIMOCHA] = 3200;
        }
        if (resultTemp->han == 2 && resultTemp->fu == 110 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 3600;
            resultTemp->point[TOIMEN] = 3600;
            resultTemp->point[SHIMOCHA] = 3600;
        }
        }
        // 3番
        // 荣和
        {
        if (resultTemp->han == 3 && resultTemp->fu == 25 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 4800;
        }
        if (resultTemp->han == 3 && resultTemp->fu == 30 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 5800;
        }
        if (resultTemp->han == 3 && resultTemp->fu == 40 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 7700;
        }
        if (resultTemp->han == 3 && resultTemp->fu == 50 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 9600;
        }
        if (resultTemp->han == 3 && resultTemp->fu == 60 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 11600;
        }
        if (resultTemp->han == 3 && resultTemp->fu >= 70 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 12000;
        }
        }
        // 自摸
        {
        if (resultTemp->han == 3 && resultTemp->fu == 20 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 1300;
            resultTemp->point[TOIMEN] = 1300;
            resultTemp->point[SHIMOCHA] = 1300;
        }
        if (resultTemp->han == 3 && resultTemp->fu == 25 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 1600;
            resultTemp->point[TOIMEN] = 1600;
            resultTemp->point[SHIMOCHA] = 1600;
        }
        if (resultTemp->han == 3 && resultTemp->fu == 30 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 2000;
            resultTemp->point[TOIMEN] = 2000;
            resultTemp->point[SHIMOCHA] = 2000;
        }
        if (resultTemp->han == 3 && resultTemp->fu == 40 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 2600;
            resultTemp->point[TOIMEN] = 2600;
            resultTemp->point[SHIMOCHA] = 2600;
        }
        if (resultTemp->han == 3 && resultTemp->fu == 50 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 3200;
            resultTemp->point[TOIMEN] = 3200;
            resultTemp->point[SHIMOCHA] = 3200;
        }
        if (resultTemp->han == 3 && resultTemp->fu == 60 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 3900;
            resultTemp->point[TOIMEN] = 3900;
            resultTemp->point[SHIMOCHA] = 3900;
        }
        if (resultTemp->han == 3 && resultTemp->fu >= 70 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 4000;
            resultTemp->point[TOIMEN] = 4000;
            resultTemp->point[SHIMOCHA] = 4000;
        }
        }
        // 4番
        // 荣和
        {
        if (resultTemp->han == 4 && resultTemp->fu == 25 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 9600;
        }
        if (resultTemp->han == 4 && resultTemp->fu == 30 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 11600;
        }
        if (resultTemp->han == 4 && resultTemp->fu >= 40 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 12000;
        }
        }
        // 自摸
        {
        if (resultTemp->han == 4 && resultTemp->fu == 20 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 2600;
            resultTemp->point[TOIMEN] = 2600;
            resultTemp->point[SHIMOCHA] = 2600;
        }
        if (resultTemp->han == 4 && resultTemp->fu == 25 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 3200;
            resultTemp->point[TOIMEN] = 3200;
            resultTemp->point[SHIMOCHA] = 3200;
        }
        if (resultTemp->han == 4 && resultTemp->fu == 30 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 3900;
            resultTemp->point[TOIMEN] = 3900;
            resultTemp->point[SHIMOCHA] = 3900;
        }
        if (resultTemp->han == 4 && resultTemp->fu >= 40 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 4000;
            resultTemp->point[TOIMEN] = 4000;
            resultTemp->point[SHIMOCHA] = 4000;
        }
        }
        // 5番
        // 荣和
        {
        if (resultTemp->han == 5 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 12000;
        }
        }
        // 自摸
        {
        if (resultTemp->han == 5 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 4000;
            resultTemp->point[TOIMEN] = 4000;
            resultTemp->point[SHIMOCHA] = 4000;
        }
        }
        // 67番
        // 荣和
        {
        if ((resultTemp->han == 6 || resultTemp->han == 7) && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 18000;
        }
        }
        // 自摸
        {
        if ((resultTemp->han == 6 || resultTemp->han == 7) && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 6000;
            resultTemp->point[TOIMEN] = 6000;
            resultTemp->point[SHIMOCHA] = 6000;
        }
        }
        // 8910番
        // 荣和
        {
        if ((resultTemp->han >= 8 && resultTemp->han <= 10) && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 24000;
        }
        }
        // 自摸
        {
        if ((resultTemp->han >= 8 && resultTemp->han <= 10) && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 8000;
            resultTemp->point[TOIMEN] = 8000;
            resultTemp->point[SHIMOCHA] = 8000;
        }
        }
        // 1112番
        // 荣和
        {
        if ((resultTemp->han >= 11 && resultTemp->han <= 12) && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 36000;
        }
        }
        // 自摸
        {
        if ((resultTemp->han >= 11 && resultTemp->han <= 12) && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 12000;
            resultTemp->point[TOIMEN] = 12000;
            resultTemp->point[SHIMOCHA] = 12000;
        }
        }
        // 役满
        // 荣和
        {
        if ((resultTemp->han >= 13 || resultTemp->han < 0) && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 48000;
        }
        }
        // 自摸
        {
        if ((resultTemp->han >= 13 || resultTemp->han < 0) && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 16000;
            resultTemp->point[TOIMEN] = 16000;
            resultTemp->point[SHIMOCHA] = 16000;
        }
        }
    } else {
        // 一番
        // 荣和
        {
        if (resultTemp->han == 1 && resultTemp->fu == 30 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 1000;
        }
        if (resultTemp->han == 1 && resultTemp->fu == 40 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 1300;
        }
        if (resultTemp->han == 1 && resultTemp->fu == 50 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 1600;
        }
        if (resultTemp->han == 1 && resultTemp->fu == 60 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 2000;
        }
        if (resultTemp->han == 1 && resultTemp->fu == 70 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 2300;
        }
        if (resultTemp->han == 1 && resultTemp->fu == 80 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 2600;
        }
        if (resultTemp->han == 1 && resultTemp->fu == 90 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 2900;
        }
        if (resultTemp->han == 1 && resultTemp->fu == 100 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 3200;
        }
        if (resultTemp->han == 1 && resultTemp->fu == 110 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 3600;
        }
        }
        // 自摸
        {
        if (resultTemp->han == 1 && resultTemp->fu == 30 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 300;
            resultTemp->point[TOIMEN] = 300;
            resultTemp->point[SHIMOCHA] = 300;
            resultTemp->point[JICHA + status.jikaze - TON] = 500;
        }
        if (resultTemp->han == 1 && resultTemp->fu == 40 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 400;
            resultTemp->point[TOIMEN] = 400;
            resultTemp->point[SHIMOCHA] = 400;
            resultTemp->point[JICHA + status.jikaze - TON] = 700;
        }
        if (resultTemp->han == 1 && resultTemp->fu == 60 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 500;
            resultTemp->point[TOIMEN] = 500;
            resultTemp->point[SHIMOCHA] = 500;
            resultTemp->point[JICHA + status.jikaze - TON] = 1000;
        }
        if (resultTemp->han == 1 && resultTemp->fu == 70 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 600;
            resultTemp->point[TOIMEN] = 600;
            resultTemp->point[SHIMOCHA] = 600;
            resultTemp->point[JICHA + status.jikaze - TON] = 1200;
        }
        if (resultTemp->han == 1 && resultTemp->fu == 80 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 700;
            resultTemp->point[TOIMEN] = 700;
            resultTemp->point[SHIMOCHA] = 700;
            resultTemp->point[JICHA + status.jikaze - TON] = 1300;
        }
        if (resultTemp->han == 1 && resultTemp->fu == 90 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 800;
            resultTemp->point[TOIMEN] = 800;
            resultTemp->point[SHIMOCHA] = 800;
            resultTemp->point[JICHA + status.jikaze - TON] = 1500;
        }
        if (resultTemp->han == 1 && resultTemp->fu == 100 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 800;
            resultTemp->point[TOIMEN] = 800;
            resultTemp->point[SHIMOCHA] = 800;
            resultTemp->point[JICHA + status.jikaze - TON] = 1600;
        }
        if (resultTemp->han == 1 && resultTemp->fu == 500 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 400;
            resultTemp->point[TOIMEN] = 400;
            resultTemp->point[SHIMOCHA] = 400;
            resultTemp->point[JICHA + status.jikaze - TON] = 800;
        }
        }
        // 2番
        // 荣和
        {
        if (resultTemp->han == 2 && resultTemp->fu == 25 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 1600;
        }
        if (resultTemp->han == 2 && resultTemp->fu == 30 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 2000;
        }
        if (resultTemp->han == 2 && resultTemp->fu == 40 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 2600;
        }
        if (resultTemp->han == 2 && resultTemp->fu == 50 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 3200;
        }
        if (resultTemp->han == 2 && resultTemp->fu == 60 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 3900;
        }
        if (resultTemp->han == 2 && resultTemp->fu == 70 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 4500;
        }
        if (resultTemp->han == 2 && resultTemp->fu == 80 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 5200;
        }
        if (resultTemp->han == 2 && resultTemp->fu == 90 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 5800;
        }
        if (resultTemp->han == 2 && resultTemp->fu == 100 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 6400;
        }
        if (resultTemp->han == 2 && resultTemp->fu == 110 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 7100;
        }
        }
        // 自摸
        {
        if (resultTemp->han == 2 && resultTemp->fu == 20 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 400;
            resultTemp->point[TOIMEN] = 400;
            resultTemp->point[SHIMOCHA] = 400;
            resultTemp->point[JICHA + status.jikaze - TON] = 700;
        }
        if (resultTemp->han == 2 && resultTemp->fu == 30 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 500;
            resultTemp->point[TOIMEN] = 500;
            resultTemp->point[SHIMOCHA] = 500;
            resultTemp->point[JICHA + status.jikaze - TON] = 1000;
        }
        if (resultTemp->han == 2 && resultTemp->fu == 40 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 700;
            resultTemp->point[TOIMEN] = 700;
            resultTemp->point[SHIMOCHA] = 700;
            resultTemp->point[JICHA + status.jikaze - TON] = 1300;
        }
        if (resultTemp->han == 2 && resultTemp->fu == 50 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 800;
            resultTemp->point[TOIMEN] = 800;
            resultTemp->point[SHIMOCHA] = 800;
            resultTemp->point[JICHA + status.jikaze - TON] = 1600;
        }
        if (resultTemp->han == 2 && resultTemp->fu == 60 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 1000;
            resultTemp->point[TOIMEN] = 1000;
            resultTemp->point[SHIMOCHA] = 1000;
            resultTemp->point[JICHA + status.jikaze - TON] = 2000;
        }
        if (resultTemp->han == 2 && resultTemp->fu == 70 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 1200;
            resultTemp->point[TOIMEN] = 1200;
            resultTemp->point[SHIMOCHA] = 1200;
            resultTemp->point[JICHA + status.jikaze - TON] = 2300;
        }
        if (resultTemp->han == 2 && resultTemp->fu == 80 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 1300;
            resultTemp->point[TOIMEN] = 1300;
            resultTemp->point[SHIMOCHA] = 1300;
            resultTemp->point[JICHA + status.jikaze - TON] = 2600;
        }
        if (resultTemp->han == 2 && resultTemp->fu == 90 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 1500;
            resultTemp->point[TOIMEN] = 1500;
            resultTemp->point[SHIMOCHA] = 1500;
            resultTemp->point[JICHA + status.jikaze - TON] = 2900;
        }
        if (resultTemp->han == 2 && resultTemp->fu == 100 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 1600;
            resultTemp->point[TOIMEN] = 1600;
            resultTemp->point[SHIMOCHA] = 1600;
            resultTemp->point[JICHA + status.jikaze - TON] = 3200;
        }
        if (resultTemp->han == 2 && resultTemp->fu == 110 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 1800;
            resultTemp->point[TOIMEN] = 1800;
            resultTemp->point[SHIMOCHA] = 1800;
            resultTemp->point[JICHA + status.jikaze - TON] = 3600;
        }
        }
        // 3番
        // 荣和
        {
        if (resultTemp->han == 3 && resultTemp->fu == 25 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 3200;
        }
        if (resultTemp->han == 3 && resultTemp->fu == 30 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 3900;
        }
        if (resultTemp->han == 3 && resultTemp->fu == 40 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 5200;
        }
        if (resultTemp->han == 3 && resultTemp->fu == 50 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 6400;
        }
        if (resultTemp->han == 3 && resultTemp->fu == 60 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 7700;
        }
        if (resultTemp->han == 3 && resultTemp->fu >= 70 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 8000;
        }
        }
        // 自摸
        {
        if (resultTemp->han == 3 && resultTemp->fu == 20 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 700;
            resultTemp->point[TOIMEN] = 700;
            resultTemp->point[SHIMOCHA] = 700;
            resultTemp->point[JICHA + status.jikaze - TON] = 1300;
        }
        if (resultTemp->han == 3 && resultTemp->fu == 25 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 800;
            resultTemp->point[TOIMEN] = 800;
            resultTemp->point[SHIMOCHA] = 800;
            resultTemp->point[JICHA + status.jikaze - TON] = 1600;
        }
        if (resultTemp->han == 3 && resultTemp->fu == 30 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 1000;
            resultTemp->point[TOIMEN] = 1000;
            resultTemp->point[SHIMOCHA] = 1000;
            resultTemp->point[JICHA + status.jikaze - TON] = 2000;
        }
        if (resultTemp->han == 3 && resultTemp->fu == 40 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 1300;
            resultTemp->point[TOIMEN] = 1300;
            resultTemp->point[SHIMOCHA] = 1300;
            resultTemp->point[JICHA + status.jikaze - TON] = 2600;
        }
        if (resultTemp->han == 3 && resultTemp->fu == 50 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 1600;
            resultTemp->point[TOIMEN] = 1600;
            resultTemp->point[SHIMOCHA] = 1600;
            resultTemp->point[JICHA + status.jikaze - TON] = 3200;
        }
        if (resultTemp->han == 3 && resultTemp->fu == 60 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 2000;
            resultTemp->point[TOIMEN] = 2000;
            resultTemp->point[SHIMOCHA] = 2000;
            resultTemp->point[JICHA + status.jikaze - TON] = 3900;
        }
        if (resultTemp->han == 3 && resultTemp->fu >= 70 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 2000;
            resultTemp->point[TOIMEN] = 2000;
            resultTemp->point[SHIMOCHA] = 2000;
            resultTemp->point[JICHA + status.jikaze - TON] = 4000;
        }
        }
        // 4番
        // 荣和
        {
        if (resultTemp->han == 4 && resultTemp->fu == 25 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 6400;
        }
        if (resultTemp->han == 4 && resultTemp->fu == 30 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 7700;
        }
        if (resultTemp->han == 4 && resultTemp->fu >= 40 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 8000;
        }
        }
        // 自摸
        {
        if (resultTemp->han == 4 && resultTemp->fu == 20 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 1300;
            resultTemp->point[TOIMEN] = 1300;
            resultTemp->point[SHIMOCHA] = 1300;
            resultTemp->point[JICHA + status.jikaze - TON] = 2600;
        }
        if (resultTemp->han == 4 && resultTemp->fu == 25 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 1600;
            resultTemp->point[TOIMEN] = 1600;
            resultTemp->point[SHIMOCHA] = 1600;
            resultTemp->point[JICHA + status.jikaze - TON] = 3200;
        }
        if (resultTemp->han == 4 && resultTemp->fu == 30 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 2000;
            resultTemp->point[TOIMEN] = 2000;
            resultTemp->point[SHIMOCHA] = 2000;
            resultTemp->point[JICHA + status.jikaze - TON] = 3900;
        }
        if (resultTemp->han == 4 && resultTemp->fu >= 40 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 2000;
            resultTemp->point[TOIMEN] = 2000;
            resultTemp->point[SHIMOCHA] = 2000;
            resultTemp->point[JICHA + status.jikaze - TON] = 4000;
        }
        }
        // 5番
        // 荣和
        {
        if (resultTemp->han == 5 && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 8000;
        }
        }
        // 自摸
        {
        if (resultTemp->han == 5 && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 2000;
            resultTemp->point[TOIMEN] = 2000;
            resultTemp->point[SHIMOCHA] = 2000;
            resultTemp->point[JICHA + status.jikaze - TON] = 4000;
        }
        }
        // 67番
        // 荣和
        {
        if ((resultTemp->han == 6 || resultTemp->han == 7) && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 12000;
        }
        }
        // 自摸
        {
        if ((resultTemp->han == 6 || resultTemp->han == 7) && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 3000;
            resultTemp->point[TOIMEN] = 3000;
            resultTemp->point[SHIMOCHA] = 3000;
            resultTemp->point[JICHA + status.jikaze - TON] = 6000;
        }
        }
        // 8910番
        // 荣和
        {
        if ((resultTemp->han >= 8 && resultTemp->han <= 10) && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 16000;
        }
        }
        // 自摸
        {
        if ((resultTemp->han >= 8 && resultTemp->han <= 10) && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 4000;
            resultTemp->point[TOIMEN] = 4000;
            resultTemp->point[SHIMOCHA] = 4000;
            resultTemp->point[JICHA + status.jikaze - TON] = 8000;
        }
        }
        // 1112番
        // 荣和
        {
        if ((resultTemp->han >= 11 && resultTemp->han <= 12) && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 24000;
        }
        }
        // 自摸
        {
        if ((resultTemp->han >= 11 && resultTemp->han <= 12) && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 6000;
            resultTemp->point[TOIMEN] = 6000;
            resultTemp->point[SHIMOCHA] = 6000;
            resultTemp->point[JICHA + status.jikaze - TON] = 12000;
        }
        }
        // 役满
        // 荣和
        {
        if ((resultTemp->han >= 13 || resultTemp->han < 0) && resultTemp->type == RON) {
            resultTemp->point[status.currentPlayer] = 32000;
        }
        }
        // 自摸
        {
        if ((resultTemp->han >= 13 || resultTemp->han < 0) && resultTemp->type == TSUMO) {
            resultTemp->point[KAMICHA] = 8000;
            resultTemp->point[TOIMEN] = 8000;
            resultTemp->point[SHIMOCHA] = 8000;
            resultTemp->point[JICHA + status.jikaze - TON] = 16000;
        }
        }
    }
}

/// @brief 计算符数点数
/// @param status 
/// @param handTile2 
/// @param groupTile1 
void Calculator(Status status, int handTile2[], GroupInt groupTile1[]) {
    CalFu(status, handTile2, groupTile1);
    CalPoi(status);
}

bool IsMenzenchin3(const Status status)
{
    if (status.groupTile[0].tile[0] == 0)
        return true;
    // for (int i = 0; i < sizeof(groupTile1) / sizeof(groupTile1[0]); i++) {
    //     if (groupTile1[i].fulutype != Ankan) return false;
    // }
    // return true;
    return false;
}

bool IsMenzenchin4(const Status status)
{
    if (status.groupTile[0].tile[0] == 0)
        return true;
    for (int i = 0; i < GroupTileLen; i++)
    {
        if (groupTile1[i].fulutype != Ankan)
            return false;
    }
    return true;
}