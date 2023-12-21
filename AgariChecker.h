#include "main.h"

void AgariCheck(int isRiichi, char handTile[], char currentTile[], Group groupTile[], char discardTile[], bool isRinshan, int remainTileCount, KazeType bakaze, KazeType jikaze, Player currentPlayer);

bool IsRiichi(int isRiichi);

bool IsAgari(char handTile[], char currentTile[], Group groupTile[]);

bool IsTenpai(char handTile[], Group groupTile[]);

bool IsFuriten(char discardTile[], char handTile[], Group groupTile[]);

bool NoYaku(char handTile[], char currentTile[], Group groupTile[], bool isRinshan, int remainTileCount, KazeType bakaze, KazeType jikaze, Player currentPlayer);