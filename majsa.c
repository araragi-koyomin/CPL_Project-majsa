#include "majsa.h"

GroupInt groupTile1[30];
int handTile1[14], discardTile1[30], currentTile1, uradora1[6], dora1[6], handTile2[14];
int Fan, Dora, Fu;
MentsuType mentsuType;
int handTilelLen, GroupTileLen, GroupEachLen[30], doraLen, DisLen;
Result *resultTemp, *result;

int CmpTrans(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
Result *majsa(Status *status) {
    //主要依赖这个函数运行

    // 为 result 分配内存
    result = (Result *)malloc(sizeof(Result));

    if (result == NULL) {
        exit(-1);
    }

    result->type = 5;
    for (int i = 0; i < 20; i++) {
        result->yaku[i] = 0;
    }
    result->han = 0;
    result->fu = 0;
    for (int i = 0; i < 3; i++) {
        result->point[i] = 0;
    }
    result->machi = 0;
    result->shanten = 0;

    resultTemp = (Result *)malloc(sizeof(Result));

    if (resultTemp == NULL) {
        exit(-1);
    }

    resultTemp->type = 5;
    for (int i = 0; i < 20; i++) {
        resultTemp->yaku[i] = 0;
    }
    resultTemp->han = 0;
    resultTemp->fu = 0;
    for (int i = 0; i < 3; i++) {
        resultTemp->point[i] = 0;
    }
    resultTemp->machi = 0;
    resultTemp->shanten = 0;

    // 转换牌型
    HaiTrans(*status);
    // 获得大小
    GetLen(*status, &handTilelLen, &GroupTileLen, handTile1, groupTile1, GroupEachLen, &doraLen, dora1, &DisLen, discardTile1);
    // 排序
    qsort(handTile1,handTilelLen, sizeof(handTile1[0]), CmpTrans);
    qsort(handTile2,handTilelLen, sizeof(handTile2[0]), CmpTrans);
    // 检查胡牌
    if (AgariCheck(*status, handTile1, discardTile1, currentTile1, groupTile1)) {
        // 检查役种
        // 计算符数、点数
    }
    return result;
}