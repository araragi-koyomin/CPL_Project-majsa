#include "majsa.h"

void Cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
Result *majsa(Status *status) {
    //主要依赖这个函数运行

    // 转换牌型
    HaiTrans(*status);
    // 排序
    qsort(handTile1,sizeof(handTile1), sizeof(handTile1[0]), Cmp);
    // 检查胡牌
    if (AgariCheck(*status, handTile1, discardTile1, currentTile1, groupTile1)) {
        // 检查役种
        // 计算符数、点数
    }
}