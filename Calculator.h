#ifndef CALCULATOR_H
#define CALCULATOR_H

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

void CalFu(Status status, int handTile[], GroupInt groupTile1[]);

void CalPoi(Status status);

void Calculator(Status status, int handTile2[], GroupInt groupTile1[]);

void CalHonba(Status status);

///////////////////////////////////////辅助用函数///////////////////////

bool IsMenzenchin3(const Status status);

bool IsMenzenchin4(const Status status);

#endif // CALCULATOR_H