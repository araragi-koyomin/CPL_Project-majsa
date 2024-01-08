#include "main.h"
#include "majsa.h"

GroupInt groupTile1[30];
int handTile1[14], discardTile1[30], currentTile1, uradora1[6], dora1[6];
int Fan, Dora, Fu;
MentsuType mentsuType;
int handTilelLen, GroupTileLen, GroupEachLen[30], doraLen, DisLen;
Result *resultTemp, *result;

int main(){
    Status status = {
      .bakaze = TON,
      .jikaze = TON,
      .honbaCount = 0,
      .dora="1m",
      .uradora="3s",
      .handTile="1m9m1p9p1s9s1z2z3z4z5z6z7z",
      .groupTile={},
      .discardTile="2m3m4m5m3p4p5p6p2s3s4s5s",
      .currentPlayer=JICHA,
      .currentTile="1z",
      .remainTileCount=18,
      .isRiichi=false,
      .isDoubleRiichi=false,
      .isIppatsu=false,
      .isRinshan=false,
    };
    // 为 result 分配内存
    result = (Result *)malloc(sizeof(Result));

    if (result == NULL) {
        return -1;
    }

    result->type = 5;
    for (int i = 0; i < 20; i++) {
        result->yaku[i] = 0;
    }
    result->han = 0;
    result->fu = 0;
    for (int i = 0; i < 3; i++) {
        result->point[i] = 0;
    }
    result->machi = 0;
    result->shanten = 0;

    resultTemp = (Result *)malloc(sizeof(Result));

    if (resultTemp == NULL) {
        return -1;
    }

    resultTemp->type = 5;
    for (int i = 0; i < 20; i++) {
        resultTemp->yaku[i] = 0;
    }
    resultTemp->han = 0;
    resultTemp->fu = 0;
    for (int i = 0; i < 3; i++) {
        resultTemp->point[i] = 0;
    }
    resultTemp->machi = 0;
    resultTemp->shanten = 0;

    result = majsa(&status);
    assert(result->type == TSUMO);
    printf("Result Type error!\n");
    Yaku stdYaku[1] = {Kokushijuusanmenmachi};
    assert(sizeof(result->yaku) == sizeof(stdYaku));
    printf("Result Yaku error!\n");
    for (int i = 0; i < sizeof(result->yaku) / sizeof(result->yaku[0]); i++){
        assert(result->yaku[i] == stdYaku[i]);
        printf("Result Yaku[%d] != stdYaku[%d] (%d)!\n");
    }
    assert(result->han == -2);
    printf("Result Han Error!\n");
    // assert(result->fu == 30);  // 国士无双，不考虑符数
    assert(result->point[KAMICHA] == 32000);
    assert(result->point[TOIMEN] == 32000);
    assert(result->point[SHIMOCHA] == 32000);
    printf("Result Point Error!\n");
    // assert(result->machi == 13);  // 已和牌，不考虑面听数
    // assert(result->shanten == 0);  // 已和牌，不考虑向听数
    return 0;
}