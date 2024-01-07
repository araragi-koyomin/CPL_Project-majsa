#ifndef CALCULATOR_H
#define CALCULATOR_H


#include "main.h"

void CalFu(Status status, int handTile[], GroupInt groupTile1[]);

void CalPoi(Status status);

void Calculator(Status status, int handTile1[], GroupInt groupTile1[]);

///////////////////////////////////////辅助用函数///////////////////////

bool IsMenzenchin3(const Status status);

bool IsMenzenchin4(const Status status);

#endif // CALCULATOR_H