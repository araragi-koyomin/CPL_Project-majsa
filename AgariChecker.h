#ifndef AGARICHECKER_H
#define AGARICHECKER_H


#include "main.h"

bool AgariCheck(Status status, int *handTile1, int *discardTile1, int currentTile1, GroupInt *groupTile1);

bool IsAgari(int handTile1[], int needMentsu, int *discardTile1, int currentTile1, Status status);

bool IsFuritenInAgari(int *discardTile1, int currentTile1, Status status);

bool IsMenzenchin(Status status);

bool IsChiitoitsuHai(int *handTile1);

int IsKoukushimusou(const int *handTile1, int currentTile1);

bool FindShuntsu(int handTile1[], int index, int mentsu, int *discardTile1, int currentTile1, Status status, int bucket[], int needMentsu);

bool FindKoutsu(int handTile1[], int index, int mentsu, int *discardTile1, int currentTile1, Status status, int bucket[], int needMentsu);

bool Is41Tennpai(int mentsu, int *discardTile1, int currentTile1, Status status, int handTile1[], int bucket[]);

bool Is7gTennpai(int handTile1[], int *discardTile1, int currentTile1, Status status);

// void FindMinusShanten();

#endif //AGARICHECKER_H