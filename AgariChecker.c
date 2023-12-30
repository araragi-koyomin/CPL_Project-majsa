#include "AgariChecker.h"


/// @brief 将手牌、进张、舍牌、副露、（里）宝牌转化为枚举结构
/// @param status 
void HaiTrans(Status status) {
    for (int i = 0; i < strlen(status.handTile); i += 2) {
        if (status.handTile[i] == '0') {
            if (status.handTile[i + 1] == 'm') {
                handTile1[i / 2] = gm;
                Dora++;
            } else if (status.handTile[i + 1] == 'p') {
                handTile1[i / 2] = gp;
                Dora++;
            } else if (status.handTile[i + 1] == 's') {
                handTile1[i / 2] = gs;
                Dora++;
            }
        } else if (status.handTile[i + 1] == 'm') handTile1[i / 2] = status.handTile[i] - '1' + im;
        else if (status.handTile[i + 1] == 'p') handTile1[i / 2] = status.handTile[i] - '1' + ip;
        else if (status.handTile[i + 1] == 's') handTile1[i / 2] = status.handTile[i] - '1' + is;
        else if (status.handTile[i + 1] == 'z') handTile1[i / 2] = status.handTile[i] - '1' + east;
    }
    for (int i = 0; i < strlen(status.discardTile); i += 2) {
        if (status.discardTile[i] == '0') {
            if (status.discardTile[i + 1] == 'm') discardTile1[i / 2] = gm;
            else if (status.discardTile[i + 1] == 'p') discardTile1[i / 2] = gp;
            else if (status.discardTile[i + 1] == 's') discardTile1[i / 2] = gs;
        } else if (status.discardTile[i + 1] == 'm') discardTile1[i / 2] = status.discardTile[i] - '1' + im;
        else if (status.discardTile[i + 1] == 'p') discardTile1[i / 2] = status.discardTile[i] - '1' + ip;
        else if (status.discardTile[i + 1] == 's') discardTile1[i / 2] = status.discardTile[i] - '1' + is;
        else if (status.discardTile[i + 1] == 'z') discardTile1[i / 2] = status.discardTile[i] - '1' + east;
    }
    for (int i = 0; i < sizeof(status.groupTile) / sizeof(status.groupTile[0]); i += 2) {
        for (int j = 0; j < strlen(status.groupTile[i].groupHai); j += 2) {
            if (status.groupTile[i].groupHai[j] == '0') {
                if (status.groupTile[i].groupHai[j + 1] == 'm') {
                    groupTile1[i].groupHaiInt = gm;
                    Dora++;
                }
                else if (status.groupTile[i].groupHai[j + 1] == 'p') {
                    groupTile1[i].groupHaiInt = gp;
                    Dora++;
                }
                else if (status.groupTile[i].groupHai[j + 1] == 's') {
                    groupTile1[i].groupHaiInt = gs;
                    Dora++;
                }
            } else if (status.groupTile[i].groupHai[j + 1] == 'm') groupTile1[i].groupHaiInt = status.groupTile[i].groupHai[j] - '1' + im;
            else if (status.groupTile[i].groupHai[j + 1] == 'p') groupTile1[i].groupHaiInt = status.groupTile[i].groupHai[j] - '1' + ip;
            else if (status.groupTile[i].groupHai[j + 1] == 's') groupTile1[i].groupHaiInt = status.groupTile[i].groupHai[j] - '1' + is;
            else if (status.groupTile[i].groupHai[j + 1] == 'z') groupTile1[i].groupHaiInt = status.groupTile[i].groupHai[j] - '1' + east;
        }
    }
    for (int i = 0; i < strlen(status.dora); i += 2) {
        if (status.dora[i] == '0') {
            if (status.dora[i + 1] == 'm') dora1[i / 2] = gm;
            else if (status.dora[i + 1] == 'p') dora1[i / 2] = gp;
            else if (status.dora[i + 1] == 's') dora1[i / 2] = gs;
        } else if (status.dora[i + 1] == 'm') dora1[i / 2] = status.dora[i] - '1' + im;
        else if (status.dora[i + 1] == 'p') dora1[i / 2] = status.dora[i] - '1' + ip;
        else if (status.dora[i + 1] == 's') dora1[i / 2] = status.dora[i] - '1' + is;
        else if (status.dora[i + 1] == 'z') dora1[i / 2] = status.dora[i] - '1' + east;
    }
    for (int i = 0; i < strlen(status.uradora); i += 2) {
        if (status.uradora[i] == '0') {
            if (status.uradora[i + 1] == 'm') uradora1[i / 2] = gm;
            else if (status.uradora[i + 1] == 'p') uradora1[i / 2] = gp;
            else if (status.uradora[i + 1] == 's') uradora1[i / 2] = gs;
        } else if (status.uradora[i + 1] == 'm') uradora1[i / 2] = status.uradora[i] - '1' + im;
        else if (status.uradora[i + 1] == 'p') uradora1[i / 2] = status.uradora[i] - '1' + ip;
        else if (status.uradora[i + 1] == 's') uradora1[i / 2] = status.uradora[i] - '1' + is;
        else if (status.uradora[i + 1] == 'z') uradora1[i / 2] = status.uradora[i] - '1' + east;
    }
    for (int i = 0; i < strlen(status.currentTile); i += 2) {
        if (status.currentTile[i] == '0') {
            if (status.currentTile[i + 1] == 'm') {
                currentTile1 = gm;
                Dora++;
            } else if (status.currentTile[i + 1] == 'p') {
                currentTile1 = gp;
                Dora++;
            } else if (status.currentTile[i + 1] == 's') {
                currentTile1 = gs;
                Dora++;
            }
        } else if (status.currentTile[i + 1] == 'm') currentTile1 = status.currentTile[i] - '1' + im;
        else if (status.currentTile[i + 1] == 'p') currentTile1 = status.currentTile[i] - '1' + ip;
        else if (status.currentTile[i + 1] == 's') currentTile1 = status.currentTile[i] - '1' + is;
        else if (status.currentTile[i + 1] == 'z') currentTile1 = status.currentTile[i] - '1' + east;
    }
    handTile1[13] = currentTile1;
}
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
bool IsRiichi(Status status)
{
    return status.isRiichi ? true : false;
}

/// @brief 判断是否为胡牌型
/// @param status 
/// @param handTile1 
/// @param discardTile1 
/// @param currentTile1 
/// @param groupTile1 
/// @return 满足胡牌型且不振听，返回true，否则返回false
bool AgariCheck(Status status, int *handTile1, int *discardTile1, int currentTile1, GroupInt *groupTile1) {
    // 我们知道，麻将胡牌型为 4面子 + 1对子 / 7对子 / 国士无双，我们接下来将对这三种情况进行判断
    // 首先从 门前清（不含暗杠） 与 副露 两种状态进行判断
    int ismenzenchin = IsMenzenchin(status);
    if (ismenzenchin) {
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
        if (IsAgari(handTile1, 4, discardTile1, currentTile1, status)) {
            if (IsFuritenInAgari(discardTile1, currentTile1, status)) {
                // 判断振听。若振听，结果类型为FURUTEN，返回false
                if (IsFuritenInAgari(discardTile1, currentTile1, status)) {
                    result->type = FURITEN;
                    return false;
                }
                // 未振听，返回true，表示胡牌
                return true;
            }
        }
    }
    else { // 副露状态（含暗杠）
        int fuluNumber = sizeof(groupTile1) / sizeof(groupTile1[0]);
        if (IsAgari(handTile1, 4 - fuluNumber, discardTile1, currentTile1, status)) {
            if (IsFuritenInAgari(discardTile1, currentTile1, status)) {
                if (IsFuritenInAgari(discardTile1, currentTile1, status)) {
                    result->type = FURITEN;
                    return false;
                }
                return true;
            }
        } else if (ismenzenchin){
            // 检验是否七对听牌或国士无双听牌
            if (!Is7gTennpai(handTile1, discardTile1, currentTile1, status)) {
                // 计算向听数
                
            }
        }
    }
}

/// @brief 判断是否满足4+1胡牌型
/// @param handTile1 
/// @param needMentsu 
/// @return 满足返回true，否则返回false
bool IsAgari(int handTile1[], int needMentsu, const int *discardTile1, const int currentTile1, const Status status) {
    // 统计手牌中各牌个数，为虚听做好准备
    int bucket[zhong + 1] = {0};
    for (int i = 0; i < 14; i++) 
        bucket[handTile1[i]]++;
    for (int i = 0; i <= 13; i++) {
        if (handTile1[i] == handTile1[i + 1]) {
            // 先找出雀头
            int tmp1 = handTile1[i], tmp2 = handTile1[i + 1];
            handTile1[i] = 0;
            handTile1[i + 1] = 0;
            // 再找出4个面子
            int mentsu = 0;
            if (FindShuntsu(handTile1, 0, mentsu, discardTile1, currentTile1, status, bucket) || FindKoutsu(handTile1, 0, mentsu, discardTile1, currentTile1, status, bucket)) {
                printf("*");
                return true;
            }
            handTile1[i] = tmp1, handTile1[i + 1] = tmp2;
        }
    }
    return false;
}

/// @brief 判断在胡牌型的基础上是否振听
/// @param discardTile1
/// @param currentTile1
/// @param status
/// @return 振听返回true，否则返回false
bool IsFuritenInAgari(const int *discardTile1, const int currentTile1, const Status status) {
    for (int i = 0; i < sizeof(discardTile1) / sizeof(discardTile1[0]); i++) {
        if (discardTile1[i] == currentTile1 && status.currentPlayer != JICHA)
            return true;
    }
    return false;
}

/// @brief 判断是否门前清状态
/// @param status
/// @return 门前清返回true, 副露返回false
bool IsMenzenchin(const Status status) {
    return status.groupTile[0].groupHai[0] == 0 ? true : false;
}

/// @brief 判断是否为七对子牌型
/// @param handTile1
/// @return 是七对子则返回true, 否则返回false
bool IsChiitoitsuHai(const int *handTile1) {
    for (int i = 0; i < sizeof(handTile1); i += 2)
        if (handTile1[i] != handTile1[i + 1] || handTile1[i + 1] == handTile1[i + 2])
            return false;
    // printf("*chiitoitsu*");
    return true;
}

/// @brief 判断是否为国士无双（十三面）
/// @param handTile1
/// @param currentTile1
/// @return 不是，返回0；是国士无双，返回1；是国士无双十三面，返回2
int IsKoukushimusou(const int *handTile1, const int currentTile1) {
    int counts[zhong + 1] = {0}, flag = 1;
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

/// @brief 从当前索引号index向右寻找顺子
/// @param handTile1
/// @param index
/// @return 能找到返回true，反之返回false
bool FindShuntsu(int handTile1[], int index, int mentsu, const int *discardTile1, const int currentTile1, const Status status, const int bucket[]) {
    // 返回成功条件：手牌清空
    int i1 = 0, i2 = 0, i3 = 0;
    int flag = 0;
    int value1 = handTile1[0], value2 = handTile1[0], value3 = handTile1[0];
    int checkIfZero = 0;
    for (int i = 0; i < 14; i++)
        if (handTile1[i] == 0)
            checkIfZero++;
    if (checkIfZero == 14) return true;
    if (index >= 12) return false;
    // 寻找顺子
    for (int i = index; i < 13; i++) {
        if (handTile1[i] == 0)
            continue;
        if (handTile1[i] == handTile1[index] + 1) {
            for (int j = i + 1; j < 14; j++) {
                if (handTile1[j] == handTile1[index] + 2) {
                    value1 = handTile1[index], value2 = handTile1[i], value3 = handTile1[j];
                    i1 = index, i2 = i, i3 = j;
                    handTile1[index] = 0, handTile1[i] = 0, handTile1[j] = 0;
                    flag = 1;
                    break;
                    // 找到了就退出
                }
            }
        }
    }
    bool CanFind = FindShuntsu(handTile1, index + 1, mentsu + 1, discardTile1, currentTile1, status, bucket);
    // 检验是否听牌型
    int IsTen = Is41Tennpai(mentsu, discardTile1, currentTile1, status, handTile1, bucket);
    if (flag) 
        handTile1[i1] = value1, handTile1[i2] = value2, handTile1[i3] = value3;
    if (CanFind) return true;
    CanFind = FindKoutsu(handTile1, index + 1, mentsu + 1, discardTile1, currentTile1, status, bucket);
    // 检验是否听牌型
    IsTen += Is41Tennpai(mentsu, discardTile1, currentTile1, status, handTile1, bucket);
    if (flag) 
        handTile1[i1] = value1, handTile1[i2] = value2, handTile1[i3] = value3;
    if (CanFind) return true;
    // 计算向听数
    if (!IsTen) {
        FindMinusShanten();
    }
    return false;
}

/// @brief 从当前索引号index向右寻找刻子
/// @param handTile1
/// @param index
/// @return 能找到返回true，反之返回false
bool FindKoutsu(int handTile1[], int index, int mentsu, const int *discardTile1, const int currentTile1, const Status status, const int bucket[]) {
    // 返回成功条件：手牌清空
    int flag = 0;
    int value1, value2, value3;
    int checkIfZero = 0;
    for (int i = 0; i < 14; i++)
        if (handTile1[i] == 0)
            checkIfZero++;
    if (checkIfZero == 14) return true;
    if (index >= 12) return false;
    // 寻找刻子
    if (handTile1[index] == handTile1[index + 1] && handTile1[index + 1] == handTile1[index + 2] && handTile1[index] != 0) {
        value1 = handTile1[index], value2 = handTile1[index + 1], value3 = handTile1[index + 2];
        handTile1[index] = 0, handTile1[index + 1] = 0, handTile1[index + 2] = 0;
        flag = 1;
    }
    bool CanFind = FindShuntsu(handTile1, index + 1, mentsu + 1, discardTile1, currentTile1, status, bucket);
    // 判断是否听牌
    Is41Tennpai(mentsu, discardTile1, currentTile1, status, handTile1, bucket);
    if (flag) {
        handTile1[index] = value1, handTile1[index + 1] = value2, handTile1[index + 2] = value3;
    }
    if (CanFind) return true;
    CanFind = FindKoutsu(handTile1, index + 1, mentsu + 1, discardTile1, currentTile1, status, bucket);
    // 判断是否听牌
    Is41Tennpai(mentsu, discardTile1, currentTile1, status, handTile1, bucket);
    if (flag) {
        handTile1[index] = value1, handTile1[index + 1] = value2, handTile1[index + 2] = value3;
    }
    if (CanFind)
        return true;
    return false;
}

int Cmp(const void *a, const void *b) {
	return *(int*)a-*(int*)b;
}

/// @brief 检验是否4 + 1听牌
/// @param mentsu 
/// @param discardTile1 
/// @param currentTile1 
/// @param status 
/// @param handTile1 
/// @return 听牌返回true， 未听返回false
bool Is41Tennpai(int mentsu, int *discardTile1, int currentTile1, Status status, int handTile1[], const int bucket[]) {
    bool flag = false;
    if (mentsu != 3) return false;
    int nokoru[3], index = 0;
    for (int i = 0; i < 14; i++)
        if (handTile1)
            nokoru[index++] = handTile1;
    // 判断剩余3张牌是否形成搭子
    // 听对碰
    for (int i = 0; i < 2; i++)
        if (nokoru[i] == nokoru[i + 1] && bucket[i] != 4) {
            flag = true, result->machi++;
            // 检验振听
            for (int j = 0; j < sizeof(discardTile1) / sizeof(discardTile1[0]); j++)
                if (nokoru[i] == discardTile1[j]) {
                    result->type = FURITEN;
                    break;
                }
        }
    // 听边张
    for (int i = 0; i < 2; i++) {
        if (nokoru[0] == im + 9 * i && nokoru[1] == nm + 9 * i && bucket[nokoru[0] + 2] != 4) {
            flag = true, result->machi++;
            for (int j = 0; j < sizeof(discardTile1) / sizeof(discardTile1[0]); j++)
                if (nokoru[0] + 2 == discardTile1[j]) {
                    result->type = FURITEN;
                    break;
                }
        } 
        if (nokoru[1] == hm + 9 * i && nokoru[2] == hm + 9 * i && bucket[nokoru[1] - 1] != 4) {
            flag = true, result->machi++;
            for (int j = 0; j < sizeof(discardTile1) / sizeof(discardTile1[0]); j++)
                if (nokoru[1] - 1 == discardTile1[j]) {
                    result->type = FURITEN;
                    break;
                }
        }
    }
    // 听嵌张
    for (int i = 0; i < 2; i++) {
        if (nokoru[0] == nokoru[2] - 1 && nokoru[2] != im + 9 * i && nokoru[2] != nm + 9 * i && bucket[nokoru[0] + 1] != 4) {
            flag = true, result->machi++;
            for (int j = 0; j < sizeof(discardTile1) / sizeof(discardTile1[0]); j++)
                if (nokoru[0] + 1 == discardTile1[j]) {
                    result->type = FURITEN;
                    break;
                }
        } 
    }
    // 听两面
    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < 2; i++) {
            if (nokoru[k] == nokoru[k + 1] - 1 && nokoru[k] > im + 9 * i && nokoru[k + 1] < km + 9 * i) {
                if (bucket[nokoru[k] - 1] != 4) {
                    flag = true, result->machi++;
                    for (int j = 0; j < sizeof(discardTile1) / sizeof(discardTile1[0]); j++)
                        if (nokoru[k] - 1 == discardTile1[j]) {
                            result->type = FURITEN;
                            break;
                        }
                }
                if (bucket[nokoru[k + 1] + 1] != 4) {
                    flag = true, result->machi++;
                    for (int j = 0; j < sizeof(discardTile1) / sizeof(discardTile1[0]); j++)
                        if (nokoru[k + 1] + 1 == discardTile1[j]) {
                            result->type = FURITEN;
                            break;
                        }
                }
            }
        }
    }
    // 总结
    if (result->type != FURITEN && result->type != RON && result->type != TSUMO && flag) {
        result->type = TENPAI;
        return true;
    }
    return false;
}

/// @brief 检验是否七对或国士无双听牌
/// @param handTile1 
/// @param discardTile1 
/// @param currentTile1 
/// @param status 
/// @return 听了返回true，没听返回false
bool Is7gTennpai(const int handTile1[], const int *discardTile1, const int currentTile1, const Status status) {
    // 七对
    int bucket[zhong + 1] = {0}, count = 0, flag = 0;
    for (int i = 0; i < 14; i++) {
        bucket[handTile1[i]]++;
        if (bucket[handTile1[i]] == 2) {
            count++;
        }
    }
    if (count == 5) {
        for (int i = 0; i < 14; i++) {
            if (bucket[handTile1[i]] % 2 == 1) {
                for (int j = 0; j < sizeof(discardTile1) / sizeof(discardTile1[0]); j++) {
                    if (discardTile1[j] == handTile1[i]) {
                        if (result->type != TENPAI && result->type != RON && result->type != TSUMO) {
                            result->type = FURITEN;
                            return true;
                        }
                    }
                } 
            }
        }
        if (result->type != FURITEN || result->type != RON || result->type != TSUMO) {
            result->type = TENPAI;
            return true;
        }
    }
    // 国士无双
    memset(bucket, 0, zhong + 1);
    count = 0;
    for (int i = 0; i < 14; i++) {
        if (handTile1[i] == im || handTile1[i] == km || handTile1[i] == ip || handTile1[i] == kp || handTile1[i] == is || handTile1[i] == ks ||
            handTile1[i] == east || handTile1[i] == south || handTile1[i] == west || handTile1[i] == north || 
            handTile1[i] == bai || handTile1[i] == fa || handTile1[i] == zhong) {
            bucket[handTile1[i]]++;
            count++;
            }
    }
    if (count == 13) {
        for (int i = 0; i < sizeof(discardTile1) / sizeof(discardTile1[0]); i++) {
            if (discardTile1[i] == im || discardTile1[i] == km || discardTile1[i] == ip || discardTile1[i] == kp || discardTile1[i] == is || discardTile1[i] == ks ||
                discardTile1[i] == east || discardTile1[i] == south || discardTile1[i] == west || discardTile1[i] == north || 
                discardTile1[i] == bai || discardTile1[i] == fa || discardTile1[i] == zhong) {
                    if (result->type != TENPAI && result->type != RON && result->type != TSUMO) {
                        result->type = FURITEN;
                        return true;
                    }
                }
        }
        if (result->type != FURITEN || result->type != RON || result->type != TSUMO) {
            result->type = TENPAI;
            return true;
        }
    }
    if (count == 12) {
        for (int i = 0; i < 2; i++) {
            if (!bucket[im + 9 * i]) {
                for (int j = 0; j < sizeof(discardTile1) / sizeof(discardTile1[0]); j++) {
                    if (bucket[im + 9 * i] == discardTile1[j]) {
                        if (result->type != TENPAI && result->type != RON && result->type != TSUMO) {
                            result->type = FURITEN;
                            return true;
                        }
                    }
                }
            } else if (!bucket[km + 9 * i]) {
                for (int j = 0; j < sizeof(discardTile1) / sizeof(discardTile1[0]); j++) {
                    if (bucket[im + 9 * i] == discardTile1[j]) {
                        if (result->type != TENPAI && result->type != RON && result->type != TSUMO) {
                            result->type = FURITEN;
                            return true;
                        }
                    }
                }
            }
        }
        for (int i = east; i <= zhong; i++) {
            if (!bucket[i]) {
                for (int j = 0; j < sizeof(discardTile1) / sizeof(discardTile1[0]); j++) {
                    if (bucket[i] == discardTile1[j]) {
                        if (result->type != TENPAI && result->type != RON && result->type != TSUMO) {
                            result->type = FURITEN;
                            return true;
                        }
                    }
                }
            }
        }
        if (result->type != FURITEN || result->type != RON || result->type != TSUMO) {
            result->type = TENPAI;
            return true;
        }
    }
    return false;
}

int main() {
    Status status = {
        .bakaze = TON,
        .jikaze = TON,
        .honbaCount = 0,
        .dora = "0p",
        .uradora = "0s",
        .handTile = "8s8s8s8s8s8s8s8s8s8s8s8s8s",
        .groupTile = {},
        .discardTile = "7m5m1m4p1p",
        .currentPlayer = SHIMOCHA,
        .currentTile = "8s",
        .remainTileCount = 36,
        .isRiichi = true,
        .isDoubleRiichi = false,
        .isIppatsu = false,
        .isRinshan = false,
    };
    HaiTrans(status);
    qsort(handTile1, sizeof(handTile1) / sizeof(*handTile1), sizeof(*handTile1), Cmp);
    int check = AgariCheck(status, handTile1, discardTile1, currentTile1, groupTile1);
    
    //   Result *result = majsa(&status);
    //   assert(result->type == TSUMO);
    //   Yaku stdYaku[1] = {Kokushijuusanmenmachi};
    //   assert(sizeof(result->yaku) == sizeof(stdYaku));
    //   for (int i = 0; i < sizeof(result->yaku) / sizeof(result->yaku[0]); i++){
    // assert(result->yaku[i] == stdYaku[i]);
    //   }
    //   assert(result->han == -2);
    // assert(result->fu == 30);  // 国士无双，不考虑符数
    //   assert(result->point[KAMICHA] == 32000);
    //   assert(result->point[TOIMEN] == 32000);
    //   assert(result->point[SHIMOCHA] == 32000);
    // assert(result->machi == 13);  // 已和牌，不考虑面听数
    // assert(result->shanten == 0);  // 已和牌，不考虑向听数
    return 0;
}
