/// @brief 风的类型
enum kazetype {
    TON = 1, NAN, SHAA, PEI
};
typedef enum kazetype KazeType;

/// @brief 副露区类型与牌
enum fulutype {
    Shuntsu = 1, Koutsu, Kantsu, Ankan
}; 
typedef enum fulutype FuluType;

struct groupChar {
    FuluType fuluType;
    char groupHai[];
};
typedef struct groupChar Group;

struct groupInt{
    FuluType fulutype;
    int groupHaiInt;
};
typedef struct groupInt GroupInt;


enum player {
    JICHA, KAMICHA, TOIMEN, SHIMOCHA
};
typedef enum player Player;

/// @brief 牌局结果
enum resulttype {
    RON, TSUMO, TENPAI, FURITEN, NOTEN
};
typedef enum resulttype ResultType;

enum yakulist {
    // 一番
    Menzenchintsumohou, Riichi, Ippatsu, Pinfu, Iipeikou, Haiteiraoyue, Houteiraoyui, Rinshankaihou, Tanyao, Ton, Nan, Shaa, Pei, Haku, Hatsu, Chun,
    // 二番
    Doubleriichi, Chantaiyao, Sanshoukudoujun, Ittsu, Toitoi, Sanankou, Sanshokudoukou, Sankantsu, Chiitoitsu, Honroutou, Shousangen,
    // 三番
    Honitsu, Junchantaiyao, Ryanpeikou,
    // 六番
    Chinitsu,
    // 役满
    Koukushimusou, Suuankou, Daisangen, Shousuushii, Tsuiisou, Chinroutou, Ryuuiisou, Chuurenpoutou, Suukantsu, Tenhou, Chiihou,
    // 双倍役满
    Kokushijuusanmenmachi, Suuankoutanki, Daisuushii, Junseichuurenpoutou
};
typedef enum yakulist Yaku;

enum hailist {
    im = 1, nm, sm, ym, gm, rm, shm, hm, km, ip, np, sp, yp, gp, rp, shp, hp, kp, is, ns, ss, ys, gs, rs, shs, hs, ks, east, south, west, north, bai, fa, zhong, 
};
typedef enum hailist HaiList;

int handTile1[14], discardTile1[30], currentTile1, uradora1[6], dora1[6];

int Fan, Dora, Fu;

GroupInt groupTile1[30];