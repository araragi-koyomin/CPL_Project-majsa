#include "YakuChecker.h"

/// @brief 判断是否立直
/// @param status
/// @param yakunum
void IsRiichi(Status status, int yakunum) {
    if (status.isRiichi && !) {
        result->han++;
        result->yaku[yakunum++] = Riichi;
    }
}

/// @brief 判断是否双立直
/// @param status 
/// @param yakunum 
void IsDoubleRiichi(Status status, int yakunum) {
    if (status.isDoubleRiichi) {
        result->han++;
    }
}

void IsIppatsu(Status status, int yakunum);