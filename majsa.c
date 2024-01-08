#include "majsa.h"

int CmpTrans(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
Result *majsa(Status *status) {
    //主要依赖这个函数运行

    // 转换牌型
    HaiTrans(*status);
    // 获得大小
    GetLen(*status, &handTilelLen, &GroupTileLen, handTile1, groupTile1, GroupEachLen, &doraLen, dora1, &DisLen, discardTile1);
    // 排序
    qsort(handTile1,handTilelLen, sizeof(handTile1[0]), CmpTrans);
    // 检查胡牌
    if (AgariCheck(*status, handTile1, discardTile1, currentTile1, groupTile1)) {
        // 检查役种
        // 计算符数、点数
    }
    return result;
}