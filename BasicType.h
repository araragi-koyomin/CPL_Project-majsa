enum kazetype
{
    TON,
    NAN,
    SHAA,
    PEI
};
typedef enum kazetype KazeType;

enum fulutype
{
    Shuntsu,
    Koutsu,
    Kantsu,
    Ankan
};
typedef enum fulutype FuluType;

struct groupChar
{
    FuluType fuluType;
    char groupHai[];
};
typedef struct groupChar Group;

struct groupInt
{
    FuluType fulutype;
    int groupHaiInt[];
};
typedef struct groupInt GroupInt;

enum player
{
    JICHA,
    KAMICHA,
    TOIMEN,
    SHIMOCHA
};
typedef enum player Player;

enum resulttype
{
    RON,
    TSUMO,
    TENPAI,
    FURITEN,
    NOTEN
};
typedef enum resulttype ResultType;

enum yakulist
{
    Menzenchintsumohou,
    Riichi,
    Ippatsu,
    Pinfu,
    Iipeikou,
    Haiteiraoyue,
    Houteiraoyui,
    Rinshankaihou,
    Chankan,
    Tanyao,
    Ton,
    Nan,
    Shaa,
    Pei,
    Haku,
    Hatsu,
    Chun,
    Doubleriichi,
    Chantaiyao,
    Sanshoukudoujun,
    Ittsu,
    Toitoi,
    Sanankou,
    Sanshokudoukou,
    Sankantsu,
    Chiitoitsu,
    Honroutou,
    Shousangen,
    Honitsu,
    Junchantaiyao,
    Ryanpeikou,
    Chinitsu,
    Koukushimusou,
    Suuankou,
    Daisangen,
    Shousuushii,
    Tsuiisou,
    Chinroutou,
    Ryuuiisou,
    Chuurenpoutou,
    Suukantsu,
    Tenhou,
    Chiihou,
    Kokushijuusanmenmachi,
    Suuankoutanki,
    Daisuushii,
    Junseichuurenpoutou
};
typedef enum yakulist Yaku;

enum hailist
{
    im = 1,
    nm,
    sm,
    ym,
    gm,
    rm,
    shm,
    hm,
    km,
    ip,
    np,
    sp,
    yp,
    gp,
    rp,
    shp,
    hp,
    kp,
    is,
    ns,
    ss,
    ys,
    gs,
    rs,
    shs,
    hs,
    ks,
    east,
    south,
    west,
    north,
    bai,
    fa,
    zhong,
};
typedef enum hailist HaiList;

int handTile1[15], discardTile1[30], currentTile1, uradora1[6], dora1[6];

int Fan, Dora, Fu;

GroupInt groupTile1[30];