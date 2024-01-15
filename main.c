#include "main.h"
#include "majsa.h"


int main(){
    Status status = {
      .bakaze = TON,
      .jikaze = NAN,
      .honbaCount = 0,
      .dora="5z",
      .uradora="",
      .handTile="4p5p6p7p8p9p6s6s5z5z",
      .groupTile={{Koutsu, "6z6z6z"}},
      .discardTile="1m5p2z6z8p4p7p",
      .currentPlayer=KAMICHA,
      .currentTile="5z",
      .remainTileCount=33,
      .isRiichi=false,
      .isDoubleRiichi=false,
      .isIppatsu=false,
      .isRinshan=false,
    };
    

    Result *result = majsa(&status);
    assert(result->type == RON);
    // printf("Result Type error!\n");
    Yaku stdYaku[2] = {YakuhaiHaku, HonitsuF};
    printf("%d\n", sizeof(result->yaku));
    printf("%d\n", sizeof(stdYaku));
    assert(sizeof(result->yaku) == sizeof(stdYaku));
    // printf("Result Yaku error!\n");
    for (int i = 0; i < sizeof(result->yaku) / sizeof(result->yaku[0]); i++){
        assert(result->yaku[i] == stdYaku[i]);
        printf("Result Yaku[%d] != stdYaku[%d] (%d)!\n");
    }
    assert(result->han == -2);
    // printf("Result Han Error!\n");
    assert(result->fu == 30);  // 国士无双，不考虑符数
    assert(result->point[KAMICHA] == 32000);
    assert(result->point[TOIMEN] == 32000);
    assert(result->point[SHIMOCHA] == 32000);
    // printf("Result Point Error!\n");
    // assert(result->machi == 13);  // 已和牌，不考虑面听数
    // assert(result->shanten == 0);  // 已和牌，不考虑向听数
    // if (result->han) {
    //     printf("%d %d %d\n", result->type, result->han, result->fu);
    //     for (int i = 0; i < 3; i++) {
    //         printf("%d%c", result->point[i], " \n"[i == 2]);
    //     }
    //     for (int i = 0; result->yaku[i] != 0; i++) {
    //         printf("%d%c", result->yaku[i], " \n"[result->yaku[i + 1] == 0]);
    //     }
    // }
    // else if (result->type == TENPAI || result->type == FURITEN) printf("%d\n", result->machi);
    // else printf("%d\n", result->shanten);
    return 0;
}