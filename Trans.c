#include "main.h"
#include <stdio.h>
#include <string.h>

void HaiTrans(char handTile[], char currentTile[], Group groupTile[], char discardTile[], char dora[], char uradora[]) {
    for (int i = 0; i < strlen(handTile) / 2; i += 2) {
        if (handTile[i] == '1' && handTile[i + 1] == 'm') handTile1[i / 2] = im;
        if (handTile[i] == '2' && handTile[i + 1] == 'm') handTile1[i / 2] = nm;
        if (handTile[i] == '3' && handTile[i + 1] == 'm') handTile1[i / 2] = sm;
        if (handTile[i] == '4' && handTile[i + 1] == 'm') handTile1[i / 2] = ym;
        if (handTile[i] == '5' && handTile[i + 1] == 'm') handTile1[i / 2] = gm;
        if (handTile[i] == '6' && handTile[i + 1] == 'm') handTile1[i / 2] = rm;
        if (handTile[i] == '7' && handTile[i + 1] == 'm') handTile1[i / 2] = shm;
        if (handTile[i] == '8' && handTile[i + 1] == 'm') handTile1[i / 2] = hm;
        if (handTile[i] == '9' && handTile[i + 1] == 'm') handTile1[i / 2] = km;
        if (handTile[i] == '0' && handTile[i + 1] == 'm') {
            handTile1[i / 2] = gm;
            Dora++;
        }
        if (handTile[i] == '1' && handTile[i + 1] == 'p') handTile1[i / 2] = ip;
        if (handTile[i] == '2' && handTile[i + 1] == 'p') handTile1[i / 2] = np;
        if (handTile[i] == '3' && handTile[i + 1] == 'p') handTile1[i / 2] = sp;
        if (handTile[i] == '4' && handTile[i + 1] == 'p') handTile1[i / 2] = yp;
        if (handTile[i] == '5' && handTile[i + 1] == 'p') handTile1[i / 2] = gp;
        if (handTile[i] == '6' && handTile[i + 1] == 'p') handTile1[i / 2] = rp;
        if (handTile[i] == '7' && handTile[i + 1] == 'p') handTile1[i / 2] = shp;
        if (handTile[i] == '8' && handTile[i + 1] == 'p') handTile1[i / 2] = hp;
        if (handTile[i] == '9' && handTile[i + 1] == 'p') handTile1[i / 2] = kp;
        if (handTile[i] == '0' && handTile[i + 1] == 'p') {
            handTile1[i / 2] = gp;
            Dora++;
        }
        if (handTile[i] == '1' && handTile[i + 1] == 's') handTile1[i / 2] = is;
        if (handTile[i] == '2' && handTile[i + 1] == 's') handTile1[i / 2] = ns;
        if (handTile[i] == '3' && handTile[i + 1] == 's') handTile1[i / 2] = ss;
        if (handTile[i] == '4' && handTile[i + 1] == 's') handTile1[i / 2] = ys;
        if (handTile[i] == '5' && handTile[i + 1] == 's') handTile1[i / 2] = gs;
        if (handTile[i] == '6' && handTile[i + 1] == 's') handTile1[i / 2] = rs;
        if (handTile[i] == '7' && handTile[i + 1] == 's') handTile1[i / 2] = shs;
        if (handTile[i] == '8' && handTile[i + 1] == 's') handTile1[i / 2] = hs;
        if (handTile[i] == '9' && handTile[i + 1] == 's') handTile1[i / 2] = ks;
        if (handTile[i] == '0' && handTile[i + 1] == 's') {
            handTile1[i / 2] = gs;
            Dora++;
        }
        if (handTile[i] == '1' && handTile[i + 1] == 'z') handTile1[i / 2] = east;
        if (handTile[i] == '2' && handTile[i + 1] == 'z') handTile1[i / 2] = south;
        if (handTile[i] == '3' && handTile[i + 1] == 'z') handTile1[i / 2] = west;
        if (handTile[i] == '4' && handTile[i + 1] == 'z') handTile1[i / 2] = north;
        if (handTile[i] == '5' && handTile[i + 1] == 'z') handTile1[i / 2] = bai;
        if (handTile[i] == '6' && handTile[i + 1] == 'z') handTile1[i / 2] = fa;
        if (handTile[i] == '7' && handTile[i + 1] == 'z') handTile1[i / 2] = zhong;
    }

    for (int i = 0; i < strlen(discardTile); i += 2) {
        if (discardTile[i] == '1' && discardTile[i + 1] == 'm') discardTile1[i / 2] = im;
        if (discardTile[i] == '2' && discardTile[i + 1] == 'm') discardTile1[i / 2] = nm;
        if (discardTile[i] == '3' && discardTile[i + 1] == 'm') discardTile1[i / 2] = sm;
        if (discardTile[i] == '4' && discardTile[i + 1] == 'm') discardTile1[i / 2] = ym;
        if (discardTile[i] == '5' && discardTile[i + 1] == 'm') discardTile1[i / 2] = gm;
        if (discardTile[i] == '6' && discardTile[i + 1] == 'm') discardTile1[i / 2] = rm;
        if (discardTile[i] == '7' && discardTile[i + 1] == 'm') discardTile1[i / 2] = shm;
        if (discardTile[i] == '8' && discardTile[i + 1] == 'm') discardTile1[i / 2] = hm;
        if (discardTile[i] == '9' && discardTile[i + 1] == 'm') discardTile1[i / 2] = km;
        if (discardTile[i] == '0' && discardTile[i + 1] == 'm') discardTile1[i / 2] = gm;
        if (discardTile[i] == '1' && discardTile[i + 1] == 'p') discardTile1[i / 2] = ip;
        if (discardTile[i] == '2' && discardTile[i + 1] == 'p') discardTile1[i / 2] = np;
        if (discardTile[i] == '3' && discardTile[i + 1] == 'p') discardTile1[i / 2] = sp;
        if (discardTile[i] == '4' && discardTile[i + 1] == 'p') discardTile1[i / 2] = yp;
        if (discardTile[i] == '5' && discardTile[i + 1] == 'p') discardTile1[i / 2] = gp;
        if (discardTile[i] == '6' && discardTile[i + 1] == 'p') discardTile1[i / 2] = rp;
        if (discardTile[i] == '7' && discardTile[i + 1] == 'p') discardTile1[i / 2] = shp;
        if (discardTile[i] == '8' && discardTile[i + 1] == 'p') discardTile1[i / 2] = hp;
        if (discardTile[i] == '9' && discardTile[i + 1] == 'p') discardTile1[i / 2] = kp;
        if (discardTile[i] == '0' && discardTile[i + 1] == 'p') discardTile1[i / 2] = gp;
        if (discardTile[i] == '1' && discardTile[i + 1] == 's') discardTile1[i / 2] = is;
        if (discardTile[i] == '2' && discardTile[i + 1] == 's') discardTile1[i / 2] = ns;
        if (discardTile[i] == '3' && discardTile[i + 1] == 's') discardTile1[i / 2] = ss;
        if (discardTile[i] == '4' && discardTile[i + 1] == 's') discardTile1[i / 2] = ys;
        if (discardTile[i] == '5' && discardTile[i + 1] == 's') discardTile1[i / 2] = gs;
        if (discardTile[i] == '6' && discardTile[i + 1] == 's') discardTile1[i / 2] = rs;
        if (discardTile[i] == '7' && discardTile[i + 1] == 's') discardTile1[i / 2] = shs;
        if (discardTile[i] == '8' && discardTile[i + 1] == 's') discardTile1[i / 2] = hs;
        if (discardTile[i] == '9' && discardTile[i + 1] == 's') discardTile1[i / 2] = ks;
        if (discardTile[i] == '0' && discardTile[i + 1] == 's') discardTile1[i / 2] = gs;
        if (discardTile[i] == '1' && discardTile[i + 1] == 'z') discardTile1[i / 2] = east;
        if (discardTile[i] == '2' && discardTile[i + 1] == 'z') discardTile1[i / 2] = south;
        if (discardTile[i] == '3' && discardTile[i + 1] == 'z') discardTile1[i / 2] = west;
        if (discardTile[i] == '4' && discardTile[i + 1] == 'z') discardTile1[i / 2] = north;
        if (discardTile[i] == '5' && discardTile[i + 1] == 'z') discardTile1[i / 2] = bai;
        if (discardTile[i] == '6' && discardTile[i + 1] == 'z') discardTile1[i / 2] = fa;
        if (discardTile[i] == '7' && discardTile[i + 1] == 'z') discardTile1[i / 2] = zhong;
    }
    for (int j = 0; j < sizeof (groupTile) / sizeof (groupTile[0]); j += 2)
        for (int i = 0; i < strlen(groupTile[j].groupHai); i += 2) {
            if (groupTile[j].groupHai[i] == '1' && groupTile[j].groupHai[i + 1] == 'm') groupTile1[j].groupHaiInt[i / 2] = im;
            if (groupTile[j].groupHai[i] == '2' && groupTile[j].groupHai[i + 1] == 'm') groupTile1[j].groupHaiInt[i / 2] = nm;
            if (groupTile[j].groupHai[i] == '3' && groupTile[j].groupHai[i + 1] == 'm') groupTile1[j].groupHaiInt[i / 2] = sm;
            if (groupTile[j].groupHai[i] == '4' && groupTile[j].groupHai[i + 1] == 'm') groupTile1[j].groupHaiInt[i / 2] = ym;
            if (groupTile[j].groupHai[i] == '5' && groupTile[j].groupHai[i + 1] == 'm') groupTile1[j].groupHaiInt[i / 2] = gm;
            if (groupTile[j].groupHai[i] == '6' && groupTile[j].groupHai[i + 1] == 'm') groupTile1[j].groupHaiInt[i / 2] = rm;
            if (groupTile[j].groupHai[i] == '7' && groupTile[j].groupHai[i + 1] == 'm') groupTile1[j].groupHaiInt[i / 2] = shm;
            if (groupTile[j].groupHai[i] == '8' && groupTile[j].groupHai[i + 1] == 'm') groupTile1[j].groupHaiInt[i / 2] = hm;
            if (groupTile[j].groupHai[i] == '9' && groupTile[j].groupHai[i + 1] == 'm') groupTile1[j].groupHaiInt[i / 2] = km;
            if (groupTile[j].groupHai[i] == '0' && groupTile[j].groupHai[i + 1] == 'm') {
                groupTile1[j].groupHaiInt[i / 2] = gm;
                Dora++;
            }
            if (groupTile[j].groupHai[i] == '1' && groupTile[j].groupHai[i + 1] == 'p') groupTile1[j].groupHaiInt[i / 2] = ip;
            if (groupTile[j].groupHai[i] == '2' && groupTile[j].groupHai[i + 1] == 'p') groupTile1[j].groupHaiInt[i / 2] = np;
            if (groupTile[j].groupHai[i] == '3' && groupTile[j].groupHai[i + 1] == 'p') groupTile1[j].groupHaiInt[i / 2] = sp;
            if (groupTile[j].groupHai[i] == '4' && groupTile[j].groupHai[i + 1] == 'p') groupTile1[j].groupHaiInt[i / 2] = yp;
            if (groupTile[j].groupHai[i] == '5' && groupTile[j].groupHai[i + 1] == 'p') groupTile1[j].groupHaiInt[i / 2] = gp;
            if (groupTile[j].groupHai[i] == '6' && groupTile[j].groupHai[i + 1] == 'p') groupTile1[j].groupHaiInt[i / 2] = rp;
            if (groupTile[j].groupHai[i] == '7' && groupTile[j].groupHai[i + 1] == 'p') groupTile1[j].groupHaiInt[i / 2] = shp;
            if (groupTile[j].groupHai[i] == '8' && groupTile[j].groupHai[i + 1] == 'p') groupTile1[j].groupHaiInt[i / 2] = hp;
            if (groupTile[j].groupHai[i] == '9' && groupTile[j].groupHai[i + 1] == 'p') groupTile1[j].groupHaiInt[i / 2] = kp;
            if (groupTile[j].groupHai[i] == '0' && groupTile[j].groupHai[i + 1] == 'p') {
                groupTile1[j].groupHaiInt[i / 2] = gp;
                Dora++;
            }
            if (groupTile[j].groupHai[i] == '1' && groupTile[j].groupHai[i + 1] == 's') groupTile1[j].groupHaiInt[i / 2] = is;
            if (groupTile[j].groupHai[i] == '2' && groupTile[j].groupHai[i + 1] == 's') groupTile1[j].groupHaiInt[i / 2] = ns;
            if (groupTile[j].groupHai[i] == '3' && groupTile[j].groupHai[i + 1] == 's') groupTile1[j].groupHaiInt[i / 2] = ss;
            if (groupTile[j].groupHai[i] == '4' && groupTile[j].groupHai[i + 1] == 's') groupTile1[j].groupHaiInt[i / 2] = ys;
            if (groupTile[j].groupHai[i] == '5' && groupTile[j].groupHai[i + 1] == 's') groupTile1[j].groupHaiInt[i / 2] = gs;
            if (groupTile[j].groupHai[i] == '6' && groupTile[j].groupHai[i + 1] == 's') groupTile1[j].groupHaiInt[i / 2] = rs;
            if (groupTile[j].groupHai[i] == '7' && groupTile[j].groupHai[i + 1] == 's') groupTile1[j].groupHaiInt[i / 2] = shs;
            if (groupTile[j].groupHai[i] == '8' && groupTile[j].groupHai[i + 1] == 's') groupTile1[j].groupHaiInt[i / 2] = hs;
            if (groupTile[j].groupHai[i] == '9' && groupTile[j].groupHai[i + 1] == 's') groupTile1[j].groupHaiInt[i / 2] = ks;
            if (groupTile[j].groupHai[i] == '0' && groupTile[j].groupHai[i + 1] == 's') {
                groupTile1[j].groupHaiInt[i / 2] = gs;
                Dora++;
            }
            if (groupTile[j].groupHai[i] == '1' && groupTile[j].groupHai[i + 1] == 'z') groupTile1[j].groupHaiInt[i / 2] = east;
            if (groupTile[j].groupHai[i] == '2' && groupTile[j].groupHai[i + 1] == 'z') groupTile1[j].groupHaiInt[i / 2] = south;
            if (groupTile[j].groupHai[i] == '3' && groupTile[j].groupHai[i + 1] == 'z') groupTile1[j].groupHaiInt[i / 2] = west;
            if (groupTile[j].groupHai[i] == '4' && groupTile[j].groupHai[i + 1] == 'z') groupTile1[j].groupHaiInt[i / 2] = north;
            if (groupTile[j].groupHai[i] == '5' && groupTile[j].groupHai[i + 1] == 'z') groupTile1[j].groupHaiInt[i / 2] = bai;
            if (groupTile[j].groupHai[i] == '6' && groupTile[j].groupHai[i + 1] == 'z') groupTile1[j].groupHaiInt[i / 2] = fa;
            if (groupTile[j].groupHai[i] == '7' && groupTile[j].groupHai[i + 1] == 'z') groupTile1[j].groupHaiInt[i / 2] = zhong;
        }
    for (int i = 0; i < 12; i += 2) {
        if (dora[i] == '1' && dora[i + 1] == 'm') dora1[i / 2] = im;
        if (dora[i] == '2' && dora[i + 1] == 'm') dora1[i / 2] = nm;
        if (dora[i] == '3' && dora[i + 1] == 'm') dora1[i / 2] = sm;
        if (dora[i] == '4' && dora[i + 1] == 'm') dora1[i / 2] = ym;
        if (dora[i] == '5' && dora[i + 1] == 'm') dora1[i / 2] = gm;
        if (dora[i] == '6' && dora[i + 1] == 'm') dora1[i / 2] = rm;
        if (dora[i] == '7' && dora[i + 1] == 'm') dora1[i / 2] = shm;
        if (dora[i] == '8' && dora[i + 1] == 'm') dora1[i / 2] = hm;
        if (dora[i] == '9' && dora[i + 1] == 'm') dora1[i / 2] = km;
        if (dora[i] == '0' && dora[i + 1] == 'm') dora1[i / 2] = gm;
        if (dora[i] == '1' && dora[i + 1] == 'p') dora1[i / 2] = ip;
        if (dora[i] == '2' && dora[i + 1] == 'p') dora1[i / 2] = np;
        if (dora[i] == '3' && dora[i + 1] == 'p') dora1[i / 2] = sp;
        if (dora[i] == '4' && dora[i + 1] == 'p') dora1[i / 2] = yp;
        if (dora[i] == '5' && dora[i + 1] == 'p') dora1[i / 2] = gp;
        if (dora[i] == '6' && dora[i + 1] == 'p') dora1[i / 2] = rp;
        if (dora[i] == '7' && dora[i + 1] == 'p') dora1[i / 2] = shp;
        if (dora[i] == '8' && dora[i + 1] == 'p') dora1[i / 2] = hp;
        if (dora[i] == '9' && dora[i + 1] == 'p') dora1[i / 2] = kp;
        if (dora[i] == '0' && dora[i + 1] == 'p') dora1[i / 2] = gp;
        if (dora[i] == '1' && dora[i + 1] == 's') dora1[i / 2] = is;
        if (dora[i] == '2' && dora[i + 1] == 's') dora1[i / 2] = ns;
        if (dora[i] == '3' && dora[i + 1] == 's') dora1[i / 2] = ss;
        if (dora[i] == '4' && dora[i + 1] == 's') dora1[i / 2] = ys;
        if (dora[i] == '5' && dora[i + 1] == 's') dora1[i / 2] = gs;
        if (dora[i] == '6' && dora[i + 1] == 's') dora1[i / 2] = rs;
        if (dora[i] == '7' && dora[i + 1] == 's') dora1[i / 2] = shs;
        if (dora[i] == '8' && dora[i + 1] == 's') dora1[i / 2] = hs;
        if (dora[i] == '9' && dora[i + 1] == 's') dora1[i / 2] = ks;
        if (dora[i] == '0' && dora[i + 1] == 's') dora1[i / 2] = gs;
        if (dora[i] == '1' && dora[i + 1] == 'z') dora1[i / 2] = east;
        if (dora[i] == '2' && dora[i + 1] == 'z') dora1[i / 2] = south;
        if (dora[i] == '3' && dora[i + 1] == 'z') dora1[i / 2] = west;
        if (dora[i] == '4' && dora[i + 1] == 'z') dora1[i / 2] = north;
        if (dora[i] == '5' && dora[i + 1] == 'z') dora1[i / 2] = bai;
        if (dora[i] == '6' && dora[i + 1] == 'z') dora1[i / 2] = fa;
        if (dora[i] == '7' && dora[i + 1] == 'z') dora1[i / 2] = zhong;
    }
    for (int i = 0; i < 12; i += 2) {
        if (uradora[i] == '1' && uradora[i + 1] == 'm') uradora1[i / 2] = im;
        if (uradora[i] == '2' && uradora[i + 1] == 'm') uradora1[i / 2] = nm;
        if (uradora[i] == '3' && uradora[i + 1] == 'm') uradora1[i / 2] = sm;
        if (uradora[i] == '4' && uradora[i + 1] == 'm') uradora1[i / 2] = ym;
        if (uradora[i] == '5' && uradora[i + 1] == 'm') uradora1[i / 2] = gm;
        if (uradora[i] == '6' && uradora[i + 1] == 'm') uradora1[i / 2] = rm;
        if (uradora[i] == '7' && uradora[i + 1] == 'm') uradora1[i / 2] = shm;
        if (uradora[i] == '8' && uradora[i + 1] == 'm') uradora1[i / 2] = hm;
        if (uradora[i] == '9' && uradora[i + 1] == 'm') uradora1[i / 2] = km;
        if (uradora[i] == '0' && uradora[i + 1] == 'm') uradora1[i / 2] = gm;
        if (uradora[i] == '1' && uradora[i + 1] == 'p') uradora1[i / 2] = ip;
        if (uradora[i] == '2' && uradora[i + 1] == 'p') uradora1[i / 2] = np;
        if (uradora[i] == '3' && uradora[i + 1] == 'p') uradora1[i / 2] = sp;
        if (uradora[i] == '4' && uradora[i + 1] == 'p') uradora1[i / 2] = yp;
        if (uradora[i] == '5' && uradora[i + 1] == 'p') uradora1[i / 2] = gp;
        if (uradora[i] == '6' && uradora[i + 1] == 'p') uradora1[i / 2] = rp;
        if (uradora[i] == '7' && uradora[i + 1] == 'p') uradora1[i / 2] = shp;
        if (uradora[i] == '8' && uradora[i + 1] == 'p') uradora1[i / 2] = hp;
        if (uradora[i] == '9' && uradora[i + 1] == 'p') uradora1[i / 2] = kp;
        if (uradora[i] == '0' && uradora[i + 1] == 'p') uradora1[i / 2] = gp;
        if (uradora[i] == '1' && uradora[i + 1] == 's') uradora1[i / 2] = is;
        if (uradora[i] == '2' && uradora[i + 1] == 's') uradora1[i / 2] = ns;
        if (uradora[i] == '3' && uradora[i + 1] == 's') uradora1[i / 2] = ss;
        if (uradora[i] == '4' && uradora[i + 1] == 's') uradora1[i / 2] = ys;
        if (uradora[i] == '5' && uradora[i + 1] == 's') uradora1[i / 2] = gs;
        if (uradora[i] == '6' && uradora[i + 1] == 's') uradora1[i / 2] = rs;
        if (uradora[i] == '7' && uradora[i + 1] == 's') uradora1[i / 2] = shs;
        if (uradora[i] == '8' && uradora[i + 1] == 's') uradora1[i / 2] = hs;
        if (uradora[i] == '9' && uradora[i + 1] == 's') uradora1[i / 2] = ks;
        if (uradora[i] == '0' && uradora[i + 1] == 's') uradora1[i / 2] = gs;
        if (uradora[i] == '1' && uradora[i + 1] == 'z') uradora1[i / 2] = east;
        if (uradora[i] == '2' && uradora[i + 1] == 'z') uradora1[i / 2] = south;
        if (uradora[i] == '3' && uradora[i + 1] == 'z') uradora1[i / 2] = west;
        if (uradora[i] == '4' && uradora[i + 1] == 'z') uradora1[i / 2] = north;
        if (uradora[i] == '5' && uradora[i + 1] == 'z') uradora1[i / 2] = bai;
        if (uradora[i] == '6' && uradora[i + 1] == 'z') uradora1[i / 2] = fa;
        if (uradora[i] == '7' && uradora[i + 1] == 'z') uradora1[i / 2] = zhong;
    }
    for (int i = 0; i < 2; i += 2) {
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
    