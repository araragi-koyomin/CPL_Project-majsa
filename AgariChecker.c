#include <AgariChecker.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

// struct status {
//     KazeType bakaze;       // 场风
//     KazeType jikaze;       // 自风
//     int honbaCount;        // 本场棒数
//     char dora[12];         // 宝牌指示牌
//     char uradora[12];      // 里宝牌指示牌
//     char handTile[30];     // 自家手牌
//     Group groupTile[30];   // 自家副露区（包括暗杠）
//     char discardTile[60];  // 自家舍牌区（包含被别家副露掉的牌）
//     Player currentPlayer;  // 当前控牌玩家
//     char currentTile[2];   // 当前控牌
//     int remainTileCount;   // 牌山剩余牌数
//     bool isRiichi;         // 是否已立直
//     bool isDoubleRiichi;   // 是否为两立直
//     bool isIppatsu;        // 是否为一发
//     bool isRinshan;        // 是否为岭上牌
// };
// typedef struct status Status;

// struct result {
//     ResultType type;  // 结果类型
//     Yaku yaku[20];    // 役种，排除古役、抢杠与流局满贯，请按升序排列
//     int han;          // 番数，约定役满役种得到的番数为负数，X倍役满即为 -X，以此与累计役满区分
//     int fu;           // 符数，国士无双时符数无意义
//     int point[3];     // 点数，三家各自要给自家的点数，不考虑包牌，下标为 0=上家，1=对家，2=下家
//     int machi;        // 面听数
//     int shanten;      // 向听数
// };
// typedef struct result Result;

// int handTile1[15], discardTile1[30], currentTile1, uradora1[6], dora1[6];

// int Fan, Dora, Fu;

// GroupInt groupTile1[30];

/// @brief 判断是否已经立直
/// @param status 
/// @return 立直则为true，反之为false
bool IsRiichi(Status status) {
    return status.isRiichi ? true : false;
}

int AgariCheck(Status status, int handTile1[], int discardTile1[], int currentTile1, int uradora1[], int dora1[], GroupInt groupTile1[]) {
    // 我们知道，麻将胡牌型为 4面子 + 1对子 / 7对子 / 国士无双，我们接下来将对这三种情况进行判断
    // 首先从 门前清 与 副露 两种状态进行判断
    if (IsMenzenchin(status)) {
        // 七对子判断
        if (IsChiitoitsuHai(handTile1)) {
            // 判断振听。若振听，结果类型为FURUTEN，返回false
            if (IsFuritenInAgari(discardTile1, currentTile1, status)) {
                result->type = FURITEN;
                return false;
            }
            // 未振听，返回true，表示胡牌
            return true;
        }
        // 国士无双判断
        if (IsKoukushimusou(handTile1, currentTile1)) {
            if (IsFuritenInAgari(discardTile1, currentTile1, status)) {
                result->type = FURITEN;
                return false;
            }
            return true;
        }
        // 接下来就是常见胡牌型判断
        int mentsu = 0, jantou = 0;
        // 4刻
        for (int i = 0; i < 14; i++) {
            if (handTile1[i] != 0) {
                if (IsKoutsu(handTile1[i])) {
                    mentsu++;
                    continue;
                }
                if (IsJantou(handTile1[i])) {
                    jantou++;
                    continue;
                }
            }
        }
        // 1顺3刻
        // 2顺2刻
        // 3顺1刻
        // 4顺
    }
}

bool IsAgari(Status status, int handTile1[], int discardTile1[], int currentTile1, int uradora1[], int dora1[], GroupInt groupTile1[]);

bool IsTenpai(Status status, int handTile1[], int discardTile1[], int currentTile1, int uradora1[], int dora1[], GroupInt groupTile1[]);

/// @brief 判断在胡牌型的基础上是否振听
/// @param discardTile1 
/// @param currentTile1 
/// @param status 
/// @return 振听返回true，否则返回false
bool IsFuritenInAgari(int discardTile1[], int currentTile1, Status status) {
    for (int i = 0; i < sizeof(discardTile1); i++) {
        if (discardTile1[i] == currentTile1 && status.currentPlayer != JICHA) return true;
    }
    return false;
}

bool NoYaku(Status status, int handTile1[], int discardTile1[], int currentTile1, int uradora1[], int dora1[], GroupInt groupTile1[]);

/// @brief 判断是否门前清状态
/// @param status 
/// @return 门前清返回true, 副露返回false
bool IsMenzenchin(Status status) {
    return strcmp(status.groupTile[0].groupHai, NULL) == 0 ? true : false;
}

/// @brief 判断是否为七对子牌型
/// @param handTile1 
/// @return 是七对子则返回true, 否则返回false
bool IsChiitoitsuHai(int handTile1[]) {
    for (int i = 0; i < sizeof(handTile1); i += 2) {
        if (handTile1[i] != handTile1[i + 1] || handTile1[i + 1] == handTile1[i + 2]) return false;
    }
    return true;
}

/// @brief 判断是否为国士无双（十三面）
/// @param handTile1 
/// @param currentTile1 
/// @return 不是，返回0；是国士无双，返回1；是国士无双十三面，返回2
int IsKoukushimusou(int handTile1[], int currentTile1) {
    int counts[zhong + 1], flag = 1;
    for (int i = 0; i < sizeof(handTile1); i++) {
        if (handTile1[i] == im || handTile1[i] == km || handTile1[i] == ip || handTile1[i] == kp || handTile1[i] == is || handTile1[i] >= ks)
            counts[handTile1[i]]++;
        else return 0;
    }
    for (int i = im; i <= zhong; i++) {
        if (counts[i] > 2) return 0;
        else if (counts[i] != 1) flag = 0; 
    }
    return flag == 1 ? 2 : 1;
}