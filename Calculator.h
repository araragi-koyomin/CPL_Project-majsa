#include "main.h"

void CalFu(Status status, int handTile[], GroupInt groupTile1[]);

void CalPoi(Status status);

///////////////////////////////////////辅助用函数///////////////////////

bool IsMenzenchin3(const Status status) {
    if(status.groupTile[0].groupHai[0] == 0) return true;
    // for (int i = 0; i < sizeof(groupTile1) / sizeof(groupTile1[0]); i++) {
    //     if (groupTile1[i].fulutype != Ankan) return false;
    // }
    // return true;
    return false;
}

bool IsMenzenchin4(const Status status) {
    if(status.groupTile[0].groupHai[0] == 0) return true;
    for (int i = 0; i < sizeof(groupTile1) / sizeof(groupTile1[0]); i++) {
        if (groupTile1[i].fulutype != Ankan) return false;
    }
    return true;
}