#ifndef TRANS_H
#define TRANS_H

#include "main.h"

#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif // STDLIB_H

#ifndef STRING_H
#define STRING_H
#include <string.h>
#endif // STRING_H

#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif // STDIO_H

void HaiTrans(Status status);

void GetLen(Status status, int *handTilelLen, int *GroupTileLen, int handTile1[], GroupInt groupTile1[], int GroupEachLen[], int *doraLen, int dora1[], int *DisLen, int discardTile1[]);

#endif // TRANS_H