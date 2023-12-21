enum kazetype {
    TON, NAN, SHAA, PEI
};
typedef enum kazetype KazeType;

enum group {
    Shuntsu, Koutsu, Kantsu, Ankan
};
typedef enum group Group;

enum player {
    JICHA, KAMICHA, TOIMEN, SHIMOCHA
};
typedef enum player Player;

enum resulttype {
    RON, TSUMO, TENPAI, FURITEN, NOTEN
};
typedef enum resulttype ResultType;

enum yakulist {
    Menzenchintsumohou, Riichi, Ippatsu, Pinfu, Iipeikou, Haiteiraoyue, Houteiraoyui, Rinshankaihou, Chankan, Tanyao, Ton, Nan, Shaa, Pei, Haku, Hatsu, Chun,
    Doubleriichi, Chantaiyao, Sanshoukudoujun, Ittsu, Toitoi, Sanankou, Sanshokudoukou, Sankantsu, Chiitoitsu, Honroutou, Shousangen,
    Honitsu, Junchantaiyao, Ryanpeikou,
    Chinitsu,
    Koukushimusou, Suuankou, Daisangen, Shousuushii, Tsuiisou, Chinroutou, Ryuuiisou, Chuurenpoutou, Suukantsu, Tenhou, Chiihou,
    Kokushijuusanmenmachi, Suuankoutanki, Daisuushii, Junseichuurenpoutou
};
typedef enum yakulist Yaku;

