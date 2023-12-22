#include <Trans.h>

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
}