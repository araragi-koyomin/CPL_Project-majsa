#define MAX(a, b) (a > b ? a : b)

/// @brief 风的类型
typedef enum {
  TON,   // 东风
  NAN,   // 南风
  SHAA,  // 西风
  PEI    // 北风
} KazeType;

/// @brief 副露区类型与牌
typedef enum {
  Shuntsu,  // 顺子
  Koutsu,   // 刻子
  Kantsu,   // 杠子
  Ankan     // 暗杠
} GroupType;

/// @brief 原始副露区，包含副露种类与副露字符串
typedef struct group {
  GroupType fulutype;
  char groupHai[10];
} Group;

/// @brief 转化后副露区，包含副露种类与副露整形数组
struct groupInt{
    GroupType fulutype;
    int groupHaiInt[4];
};
typedef struct groupInt GroupInt;
GroupInt groupTile1[30];

typedef enum {
  JICHA = -1,   // 自家
  KAMICHA = 0,  // 上家
  TOIMEN = 1,   // 对家
  SHIMOCHA = 2  // 下家
} Player;

/// @brief 牌局结果
typedef enum {
  RON,      // 荣和
  TSUMO,    // 自摸
  TENPAI,   // 听牌
  FURITEN,  // 振听
  NOTEN,    // 不听
} ResultType;

typedef enum {
  Riichi = 0x110,           // 立直
  Ippatsu = 0x111,          // 一发
  Menzenchintsumo = 0x112,  // 门前清自摸和
  Tanyao = 0x100,           // 断幺九
  YakuhaiJikaze = 0x101,    // 自风
  YakuhaiBakaze = 0x102,    // 场风
  YakuhaiHaku = 0x103,      // 白
  YakuhaiHatsu = 0x104,     // 发
  YakuhaiChun = 0x105,      // 中
  Pinhu = 0x113,            // 平和
  Iipeikou = 0x114,         // 一杯口
  Chankan = 0x106,          // 抢杠（排除）
  Rinshankaihou = 0x107,    // 岭上开花
  Haiteiraoyue = 0x108,     // 海底摸月
  Houteiraoyui = 0x109,     // 河底捞鱼

  doubleRiichi = 0x210,    // 两立直
  Sanshokudoukou = 0x200,  // 三色同刻
  Sankantsu = 0x201,       // 三杠子
  Toitoihou = 0x202,       // 对对和
  Sanankou = 0x203,        // 三暗刻
  Shousangen = 0x204,      // 小三元
  Honroutou = 0x205,       // 混老头
  Chiitoitsu = 0x211,      // 七对子

  Honchantaiyaochuu = 0x206,   // 混全带幺九（门清）
  HonchantaiyaochuuF = 0x126,  // 混全带幺九（副露）
  Ikkitsuukan = 0x207,         // 一气通贯（门清）
  IkkitsuukanF = 0x127,        // 一气通贯（副露）
  Sanshokudoujun = 0x208,      // 三色同顺（门清）
  SanshokudoujunF = 0x128,     // 三色同顺（副露）

  Ryanpeikou = 0x310,          // 两杯口
  Junchantaiyaochuu = 0x300,   // 纯全带幺九（门清）
  JunchantaiyaochuuF = 0x220,  // 纯全带幺九（副露）
  Honitsu = 0x301,             // 混一色（门清）
  HonitsuF = 0x221,            // 混一色（副露）

    Nagashimangan = 0x500,  // 流局满贯（排除）
    Chinitsu = 0x600,       // 清一色（门清）
    ChinitsuF = 0x520,      // 清一色（副露）

    Tenhou = 0xd00,         // 天和
    Chihou = 0xd01,         // 地和
    Daisangen = 0xd02,      // 大三元
    Suuankou = 0xd10,       // 四暗刻
    Tsuuiisou = 0xd03,      // 字一色
    Ryuuiisou = 0xd04,      // 绿一色
    Chinroutou = 0xd05,     // 清老头
    Kokushimusou = 0xd11,   // 国士无双
    Shousuushi = 0xd06,     // 小四喜
    Suukantsu = 0xd07,      // 四杠子
    Chuurenpoutou = 0xd12,  // 九莲宝灯

    Suuankoutanki = 0xf10,          // 四暗刻单骑
    Kokushijuusanmenmachi = 0xf11,  // 国士无双十三面
    Chuurenkyuumenmachi = 0xf12,    // 纯正九莲宝灯
    Daisuushi = 0xf00,              // 大四喜
} Yaku;


enum hailist {
    im = 1, nm, sm, ym, gm, rm, shm, hm, km, ip, np, sp, yp, gp, rp, shp, hp, kp, is, ns, ss, ys, gs, rs, shs, hs, ks, east, south, west, north, bai, fa, zhong, 
};
typedef enum hailist HaiList;

int handTile1[14], discardTile1[30], currentTile1, uradora1[6], dora1[6];

int Fan, Dora, Fu;

typedef struct mentsutype {
    int shuntsunum, koutsunum;
    int shun[4][3], kou[4][4], jyan[2];
} MentsuType;
MentsuType mentsuType;