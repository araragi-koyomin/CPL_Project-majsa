#include "main.h"
int currentTile[2], currentTile[2], dora[1], uradora[1], currentTile1;
int main() {
for (int i = 0; i < 12; i += 2) {
        if (currentTile[i] == '1' && currentTile[i + 1] == 'm') currentTile1 = im;
        if (currentTile[i] == '2' && currentTile[i + 1] == 'm') currentTile1 = nm;
        if (currentTile[i] == '3' && currentTile[i + 1] == 'm') currentTile1 = sm;
        if (currentTile[i] == '4' && currentTile[i + 1] == 'm') currentTile1 = ym;
        if (currentTile[i] == '5' && currentTile[i + 1] == 'm') currentTile1 = gm;
        if (currentTile[i] == '6' && currentTile[i + 1] == 'm') currentTile1 = rm;
        if (currentTile[i] == '7' && currentTile[i + 1] == 'm') currentTile1 = shm;
        if (currentTile[i] == '8' && currentTile[i + 1] == 'm') currentTile1 = hm;
        if (currentTile[i] == '9' && currentTile[i + 1] == 'm') currentTile1 = km;
        if (currentTile[i] == '0' && currentTile[i + 1] == 'm') {
            currentTile1 = gm;
            Dora++;
        }
        if (currentTile[i] == '1' && currentTile[i + 1] == 'p') currentTile1 = ip;
        if (currentTile[i] == '2' && currentTile[i + 1] == 'p') currentTile1 = np;
        if (currentTile[i] == '3' && currentTile[i + 1] == 'p') currentTile1 = sp;
        if (currentTile[i] == '4' && currentTile[i + 1] == 'p') currentTile1 = yp;
        if (currentTile[i] == '5' && currentTile[i + 1] == 'p') currentTile1 = gp;
        if (currentTile[i] == '6' && currentTile[i + 1] == 'p') currentTile1 = rp;
        if (currentTile[i] == '7' && currentTile[i + 1] == 'p') currentTile1 = shp;
        if (currentTile[i] == '8' && currentTile[i + 1] == 'p') currentTile1 = hp;
        if (currentTile[i] == '9' && currentTile[i + 1] == 'p') currentTile1 = kp;
        if (currentTile[i] == '0' && currentTile[i + 1] == 'p') {
            currentTile1 = gp;
            Dora++;
        }
        if (currentTile[i] == '1' && currentTile[i + 1] == 's') currentTile1 = is;
        if (currentTile[i] == '2' && currentTile[i + 1] == 's') currentTile1 = ns;
        if (currentTile[i] == '3' && currentTile[i + 1] == 's') currentTile1 = ss;
        if (currentTile[i] == '4' && currentTile[i + 1] == 's') currentTile1 = ys;
        if (currentTile[i] == '5' && currentTile[i + 1] == 's') currentTile1 = gs;
        if (currentTile[i] == '6' && currentTile[i + 1] == 's') currentTile1 = rs;
        if (currentTile[i] == '7' && currentTile[i + 1] == 's') currentTile1 = shs;
        if (currentTile[i] == '8' && currentTile[i + 1] == 's') currentTile1 = hs;
        if (currentTile[i] == '9' && currentTile[i + 1] == 's') currentTile1 = ks;
        if (currentTile[i] == '0' && currentTile[i + 1] == 's') {
            currentTile1 = gs;
            Dora++;
        }
        if (currentTile[i] == '1' && currentTile[i + 1] == 'z') currentTile1 = east;
        if (currentTile[i] == '2' && currentTile[i + 1] == 'z') currentTile1 = south;
        if (currentTile[i] == '3' && currentTile[i + 1] == 'z') currentTile1 = west;
        if (currentTile[i] == '4' && currentTile[i + 1] == 'z') currentTile1 = north;
        if (currentTile[i] == '5' && currentTile[i + 1] == 'z') currentTile1 = bai;
        if (currentTile[i] == '6' && currentTile[i + 1] == 'z') currentTile1 = fa;
        if (currentTile[i] == '7' && currentTile[i + 1] == 'z') currentTile1 = zhong;
    }
}