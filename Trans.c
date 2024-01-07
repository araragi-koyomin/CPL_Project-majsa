#include "Trans.h"

/// @brief 将手牌、进张、舍牌、副露、（里）宝牌转化为枚举结构
/// @param status
void HaiTrans(Status status)
{
    // 手牌转换
    for (int i = 0; i < strlen(status.handTile); i += 2)
    {
        if (status.handTile[i] == '0')
        {
            if (status.handTile[i + 1] == 'm')
            {
                handTile1[i / 2] = gm;
                Dora++;
            }
            else if (status.handTile[i + 1] == 'p')
            {
                handTile1[i / 2] = gp;
                Dora++;
            }
            else if (status.handTile[i + 1] == 's')
            {
                handTile1[i / 2] = gs;
                Dora++;
            }
        }
        else if (status.handTile[i + 1] == 'm')
            handTile1[i / 2] = status.handTile[i] - '1' + im;
        else if (status.handTile[i + 1] == 'p')
            handTile1[i / 2] = status.handTile[i] - '1' + ip;
        else if (status.handTile[i + 1] == 's')
            handTile1[i / 2] = status.handTile[i] - '1' + is;
        else if (status.handTile[i + 1] == 'z')
            handTile1[i / 2] = status.handTile[i] - '1' + east;
    }
    // 牌河转换
    for (int i = 0; i < strlen(status.discardTile); i += 2)
    {
        if (status.discardTile[i] == '0')
        {
            if (status.discardTile[i + 1] == 'm')
                discardTile1[i / 2] = gm;
            else if (status.discardTile[i + 1] == 'p')
                discardTile1[i / 2] = gp;
            else if (status.discardTile[i + 1] == 's')
                discardTile1[i / 2] = gs;
        }
        else if (status.discardTile[i + 1] == 'm')
            discardTile1[i / 2] = status.discardTile[i] - '1' + im;
        else if (status.discardTile[i + 1] == 'p')
            discardTile1[i / 2] = status.discardTile[i] - '1' + ip;
        else if (status.discardTile[i + 1] == 's')
            discardTile1[i / 2] = status.discardTile[i] - '1' + is;
        else if (status.discardTile[i + 1] == 'z')
            discardTile1[i / 2] = status.discardTile[i] - '1' + east;
    }
    // 副露转换
    for (int i = 0; i < sizeof(status.groupTile) / sizeof(status.groupTile[0]); i += 1)
    {
        for (int j = 0; j < strlen(status.groupTile[i].tile); j += 2)
        {
            if (status.groupTile[i].tile[j] == '0')
            {
                if (status.groupTile[i].tile[j + 1] == 'm')
                {
                    groupTile1[i].groupHaiInt[j / 2] = gm;
                    Dora++;
                }
                else if (status.groupTile[i].tile[j + 1] == 'p')
                {
                    groupTile1[i].groupHaiInt[j / 2] = gp;
                    Dora++;
                }
                else if (status.groupTile[i].tile[j + 1] == 's')
                {
                    groupTile1[i].groupHaiInt[j / 2] = gs;
                    Dora++;
                }
            }
            else if (status.groupTile[i].tile[j + 1] == 'm')
                groupTile1[i].groupHaiInt[j / 2] = status.groupTile[i].tile[j] - '1' + im;
            else if (status.groupTile[i].tile[j + 1] == 'p')
                groupTile1[i].groupHaiInt[j / 2] = status.groupTile[i].tile[j] - '1' + ip;
            else if (status.groupTile[i].tile[j + 1] == 's')
                groupTile1[i].groupHaiInt[j / 2] = status.groupTile[i].tile[j] - '1' + is;
            else if (status.groupTile[i].tile[j + 1] == 'z')
                groupTile1[i].groupHaiInt[j / 2] = status.groupTile[i].tile[j] - '1' + east;
        }
        groupTile1[i].fulutype = status.groupTile[i].type;
    }
    // 宝牌转换
    for (int i = 0; i < strlen(status.dora); i += 2)
    {
        if (status.dora[i] == '0')
        {
            if (status.dora[i + 1] == 'm')
                dora1[i / 2] = gm;
            else if (status.dora[i + 1] == 'p')
                dora1[i / 2] = gp;
            else if (status.dora[i + 1] == 's')
                dora1[i / 2] = gs;
        }
        else if (status.dora[i + 1] == 'm')
            dora1[i / 2] = status.dora[i] - '1' + im;
        else if (status.dora[i + 1] == 'p')
            dora1[i / 2] = status.dora[i] - '1' + ip;
        else if (status.dora[i + 1] == 's')
            dora1[i / 2] = status.dora[i] - '1' + is;
        else if (status.dora[i + 1] == 'z')
            dora1[i / 2] = status.dora[i] - '1' + east;
    }
    // 里宝牌转换
    for (int i = 0; i < strlen(status.uradora); i += 2)
    {
        if (status.uradora[i] == '0')
        {
            if (status.uradora[i + 1] == 'm')
                uradora1[i / 2] = gm;
            else if (status.uradora[i + 1] == 'p')
                uradora1[i / 2] = gp;
            else if (status.uradora[i + 1] == 's')
                uradora1[i / 2] = gs;
        }
        else if (status.uradora[i + 1] == 'm')
            uradora1[i / 2] = status.uradora[i] - '1' + im;
        else if (status.uradora[i + 1] == 'p')
            uradora1[i / 2] = status.uradora[i] - '1' + ip;
        else if (status.uradora[i + 1] == 's')
            uradora1[i / 2] = status.uradora[i] - '1' + is;
        else if (status.uradora[i + 1] == 'z')
            uradora1[i / 2] = status.uradora[i] - '1' + east;
    }
    // 进张转换
    for (int i = 0; i < strlen(status.currentTile); i += 2)
    {
        if (status.currentTile[i] == '0')
        {
            if (status.currentTile[i + 1] == 'm')
            {
                currentTile1 = gm;
                Dora++;
            }
            else if (status.currentTile[i + 1] == 'p')
            {
                currentTile1 = gp;
                Dora++;
            }
            else if (status.currentTile[i + 1] == 's')
            {
                currentTile1 = gs;
                Dora++;
            }
        }
        else if (status.currentTile[i + 1] == 'm')
            currentTile1 = status.currentTile[i] - '1' + im;
        else if (status.currentTile[i + 1] == 'p')
            currentTile1 = status.currentTile[i] - '1' + ip;
        else if (status.currentTile[i + 1] == 's')
            currentTile1 = status.currentTile[i] - '1' + is;
        else if (status.currentTile[i + 1] == 'z')
            currentTile1 = status.currentTile[i] - '1' + east;
    }
    handTile1[13] = currentTile1;
}

void GetLen(Status status, int *handTilelLen, int *GroupTileLen, int handTile1[], GroupInt groupTile1[], int GroupEachLen[], int *doraLen, int dora1[], int *DisLen, int discardTile1[]) {
    for (int i = 0; handTile1[i] != '\0'; i++) {
        (*handTilelLen)++;
    }
    for (int i = 0; groupTile1[i].groupHaiInt[0] != '\0'; i++) {
        (*GroupTileLen)++;
    }
    for (int i = 0; i < *GroupTileLen; i++) {
        for (int j = 0; groupTile1[i].groupHaiInt[j] != '\0'; j++) {
            GroupEachLen[i]++;
        }
    }
    for (int i = 0; dora1[i] != '\0'; i++) {
        (*doraLen)++;
    }
    for (int i = 0; discardTile1[i] = '\0'; i++) {
        (*DisLen)++;
    }
}