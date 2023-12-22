#include "majsa.h"
#include <stdlib.h>

void Cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
Result *majsa(Status *status) {
    //主要依赖这个函数运行
    HaiTrans(*status);
    qsort(handTile1,sizeof(handTile1), sizeof(handTile1[0]), Cmp);
    
}