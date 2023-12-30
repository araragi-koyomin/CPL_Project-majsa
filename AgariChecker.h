#include "main.h"

bool IsRiichi(Status status);

bool AgariCheck(Status status, int *handTile1, int *discardTile1, int currentTile1, GroupInt *groupTile1);

bool IsAgari(int handTile1[], int needMentsu, const int *discardTile1, const int currentTile1, const Status status);

bool IsFuritenInAgari(const int *discardTile1, const int currentTile1, Status status);

bool IsMenzenchin(Status status);

bool IsChiitoitsuHai(const int *handTile1);

int IsKoukushimusou(const int *handTile1, int currentTile1);

bool FindShuntsu(int handTile1[], int index, int mentsu, const int *discardTile1, const int currentTile1, const Status status, const int bucket[]);

bool FindKoutsu(int handTile1[], int index, int mentsu, const int *discardTile1, const int currentTile1, const Status status, const int bucket[]);

bool Is41Tennpai(int mentsu, int *discardTile1, int currentTile1, Status status, int handTile1[], const int bucket[]);

bool Is7gTennpai(const int handTile1[], const int *discardTile1, const int currentTile1, const Status status);

void FindMinusShanten();