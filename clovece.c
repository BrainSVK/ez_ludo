//
// Created by erikv on 7. 1. 2023.
//
#include <malloc.h>
#include "k_s_definitions.h"
#include <string.h>
#include <stdlib.h>
#include "clovece.h"
#define MAX_CLEINTS 4
#define HRACIA_PLOCHA 40
#define DOMCEK 4

int pocetHracov = 4;
char polickaHraciaTeam[40];
char polickaHraciaPanacik[40];
char polickaZacDomTeam[4][4];
char polickaZacDomPanacik[4][4];
char polickaDomTeam[4][4];
char polickaDomPanacik[4][4];

typedef struct Panacik {
    int kdeSom;
    int NaAkomPolicku;
} PANACIK;

typedef struct Hrac {
    int id;
    char* meno;
    PANACIK data[4];
} HRAC;

HRAC *hraci[MAX_CLEINTS];

typedef struct Clovece {
    HRAC * data;
} CLOVECE;

void queue_add_hrac(HRAC *cl) {
    for (int i = 0; i < MAX_CLEINTS; ++i) {
        if (!hraci[i]) {
            hraci[i] = cl;
            break;
        }
    }
}

void queue_remove_hrac(int uid) {
    for (int i = 0; i < MAX_CLEINTS; ++i) {
        if (hraci[i]) {
            if (hraci[i]->id == uid) {
                hraci[i] = NULL;
                break;
            }
        }
    }
}

void pridajHraca(int _uid,char* _meno) {
    HRAC * hrac = (HRAC *) malloc(sizeof(HRAC));
    hrac->id = _uid;
    hrac->meno = _meno;
    for (int i = 0; i < DOMCEK; ++i) {
        hrac->data[i].NaAkomPolicku = i;
        hrac->data[i].kdeSom = 1;
    }
    queue_add_hrac(hrac);
}


int getIdHraca(int index) {
    return hraci[index]->id;
}

void vypisStavHraca(int index,char* vykresli_) {
    sprintf(vykresli_,"Id hraca: %d\nMeno hraca: %s\nPanacikovia kde su %d %d %d %d\nPanacikovia pozicia %d %d %d %d\n",hraci[index]->id,hraci[index]->meno,hraci[index]->data[0].kdeSom, hraci[index]->data[1].kdeSom, hraci[index]->data[2].kdeSom, hraci[index]->data[3].kdeSom,hraci[index]->data[0].NaAkomPolicku, hraci[index]->data[1].NaAkomPolicku, hraci[index]->data[2].NaAkomPolicku, hraci[index]->data[3].NaAkomPolicku);
}

void vyhresliHraciuPlochu() {
    for (int i = 0; i < HRACIA_PLOCHA; ++i) {
        polickaHraciaTeam[i] = 'x';
        polickaHraciaPanacik[i] = 'x';
    }
}

void vykresliZacDomPlochu() {
    for (int i = 0; i < DOMCEK; ++i) {
        for (int j = 0; j < DOMCEK; ++j) {
            if (i == 0) {
                polickaZacDomTeam[i][j] = 'R';
            } else if (i == 1) {
                polickaZacDomTeam[i][j] = 'B';
            } else if (i == 2) {
                polickaZacDomTeam[i][j] = 'G';
            } else {
                polickaZacDomTeam[i][j] = 'Y';
            }
            polickaZacDomPanacik[i][j] = (j+1) + '0';
        }
    }
}

void vykresliDomPlochu() {
    for (int i = 0; i < DOMCEK; ++i) {
        for (int j = 0; j < DOMCEK; ++j) {
            polickaDomPanacik[i][j] = 'y';
            polickaDomTeam[i][j] = 'y';
        }
    }
}


char getPolickoHraciaTeam(int index) {
    return polickaHraciaTeam[index];
}

char getPolickoHraciaPanacik(int index) {
    return polickaHraciaPanacik[index];
}

char getPolickoZacDomTeam(int indexI, int indexJ) {
    return polickaZacDomTeam[indexI][indexJ];
}

char getPolickoZacDomPanacik(int indexI, int indexJ) {
    return polickaZacDomPanacik[indexI][indexJ];
}

char getPolickoDomTeam(int indexI, int indexJ) {
    return polickaDomTeam[indexI][indexJ];
}

char getPolickoDomPanacik(int indexI, int indexJ) {
    return polickaDomPanacik[indexI][indexJ];
}

void pokusSaPohnutPanacikom(int index,int kolkoSomHodil) {
    int som = 0;
}

int hodKockou() {
    return (rand() % 6) + 1;
}

void vykresli(char* vykresli_) {
    sprintf(vykresli_,"**********************************\n"
                      "**|\033[31m%c%c\033[0m|\033[31m%c%c\033[0m|****|%c%c|%c%c|%c%c|**|\033[34m%c%c\033[0m|\033[34m%c%c\033[0m|****\n"
                      "**|\033[31m%c%c\033[0m|\033[31m%c%c\033[0m|****|%c%c|\033[34m%c%c\033[0m|%c%c|**|\033[34m%c%c\033[0m|\033[34m%c%c\033[0m|****\n"
                      "*************|%c%c|\033[34m%c%c\033[0m|%c%c|*************\n"
                      "*************|%c%c|\033[34m%c%c\033[0m|%c%c|*************\n"
                      "*|%c%c|%c%c|%c%c|%c%c|%c%c|\033[34m%c%c\033[0m|%c%c|%c%c|%c%c|%c%c|%c%c|*\n"
                      "*|%c%c|\033[31m%c%c\033[0m|\033[31m%c%c\033[0m|\033[31m%c%c\033[0m|\033[31m%c%c\033[0m|**|\033[32m%c%c\033[0m|\033[32m%c%c\033[0m|\033[32m%c%c\033[0m|\033[32m%c%c\033[0m|%c%c|*\n"
                      "*|%c%c|%c%c|%c%c|%c%c|%c%c|\033[33m%c%c\033[0m|%c%c|%c%c|%c%c|%c%c|%c%c|*\n"
                      "*************|%c%c|\033[33m%c%c\033[0m|%c%c|*************\n"
                      "*************|%c%c|\033[33m%c%c\033[0m|%c%c|*************\n"
                      "**|\033[33m%c%c\033[0m|\033[33m%c%c\033[0m|****|%c%c|\033[33m%c%c\033[0m|%c%c|****|\033[32m%c%c\033[0m|\033[32m%c%c\033[0m|**\n"
                      "**|\033[33m%c%c\033[0m|\033[33m%c%c\033[0m|****|%c%c|%c%c|%c%c|****|\033[32m%c%c\033[0m|\033[32m%c%c\033[0m|**\n"
                      "************************************\n",
            getPolickoZacDomTeam(0,0), getPolickoZacDomPanacik(0,0),getPolickoZacDomTeam(0,1), getPolickoZacDomPanacik(0,1),getPolickoHraciaTeam(38),getPolickoHraciaPanacik(38),getPolickoHraciaTeam(39), getPolickoHraciaPanacik(39),getPolickoHraciaTeam(0), getPolickoHraciaPanacik(0),getPolickoZacDomTeam(1,0), getPolickoZacDomPanacik(1,0),getPolickoZacDomTeam(1,1), getPolickoZacDomPanacik(1,1),
            getPolickoZacDomTeam(0,2), getPolickoZacDomPanacik(0,2),getPolickoZacDomTeam(0,3), getPolickoZacDomPanacik(0,3),getPolickoHraciaTeam(37),getPolickoHraciaPanacik(37),getPolickoDomTeam(1,0),getPolickoDomPanacik(1,0),getPolickoHraciaTeam(1), getPolickoHraciaPanacik(1),getPolickoZacDomTeam(1,2), getPolickoZacDomPanacik(1,2),getPolickoZacDomTeam(1,3), getPolickoZacDomPanacik(1,3),
            getPolickoHraciaTeam(36),getPolickoHraciaPanacik(36),getPolickoDomTeam(1,1),getPolickoDomPanacik(1,1),getPolickoHraciaTeam(2),getPolickoHraciaPanacik(2),
            getPolickoHraciaTeam(35),getPolickoHraciaPanacik(35),getPolickoDomTeam(1,2),getPolickoDomPanacik(1,2),getPolickoHraciaTeam(3),getPolickoHraciaPanacik(3),
            getPolickoHraciaTeam(30),getPolickoHraciaPanacik(30),getPolickoHraciaTeam(31),getPolickoHraciaPanacik(31),getPolickoHraciaTeam(32),getPolickoHraciaPanacik(32),getPolickoHraciaTeam(33),getPolickoHraciaPanacik(33),getPolickoHraciaTeam(34),getPolickoHraciaPanacik(34),getPolickoDomTeam(1,3),getPolickoDomPanacik(1,3),getPolickoHraciaTeam(4),getPolickoHraciaPanacik(4),getPolickoHraciaTeam(5),getPolickoHraciaPanacik(5),getPolickoHraciaTeam(6),getPolickoHraciaPanacik(6),getPolickoHraciaTeam(7),getPolickoHraciaPanacik(7),getPolickoHraciaTeam(8),getPolickoHraciaPanacik(8),
            getPolickoHraciaTeam(29),getPolickoHraciaPanacik(29),getPolickoDomTeam(0,0),getPolickoDomPanacik(0,0),getPolickoDomTeam(0,1),getPolickoDomPanacik(0,1),getPolickoDomTeam(0,2),getPolickoDomPanacik(0,2),getPolickoDomTeam(0,3),getPolickoDomPanacik(0,3),getPolickoDomTeam(2,3),getPolickoDomPanacik(2,3),getPolickoDomTeam(2,2),getPolickoDomPanacik(2,2),getPolickoDomTeam(2,1),getPolickoDomPanacik(2,1),getPolickoDomTeam(2,0),getPolickoDomPanacik(2,0),getPolickoHraciaTeam(9),getPolickoHraciaPanacik(9),
            getPolickoHraciaTeam(28),getPolickoHraciaPanacik(28),getPolickoHraciaTeam(27),getPolickoHraciaPanacik(27),getPolickoHraciaTeam(26),getPolickoHraciaPanacik(26),getPolickoHraciaTeam(25),getPolickoHraciaPanacik(25),getPolickoHraciaTeam(24),getPolickoHraciaPanacik(24),getPolickoDomTeam(3,3),getPolickoDomPanacik(3,3),getPolickoHraciaTeam(14),getPolickoHraciaPanacik(14),getPolickoHraciaTeam(13),getPolickoHraciaPanacik(13),getPolickoHraciaTeam(12),getPolickoHraciaPanacik(12),getPolickoHraciaTeam(11),getPolickoHraciaPanacik(11),getPolickoHraciaTeam(10),getPolickoHraciaPanacik(10),
            getPolickoHraciaTeam(23),getPolickoHraciaPanacik(23),getPolickoDomTeam(3,2),getPolickoDomPanacik(3,2),getPolickoHraciaTeam(15),getPolickoHraciaPanacik(15),
            getPolickoHraciaTeam(22),getPolickoHraciaPanacik(22),getPolickoDomTeam(3,1),getPolickoDomPanacik(3,1),getPolickoHraciaTeam(16),getPolickoHraciaPanacik(16),
            getPolickoZacDomTeam(3,0), getPolickoZacDomPanacik(3,0),getPolickoZacDomTeam(3,1), getPolickoZacDomPanacik(3,1),getPolickoHraciaTeam(21),getPolickoHraciaPanacik(21),getPolickoDomTeam(3,0),getPolickoDomPanacik(3,0),getPolickoHraciaTeam(17), getPolickoHraciaPanacik(17),getPolickoZacDomTeam(2,0), getPolickoZacDomPanacik(2,0),getPolickoZacDomTeam(2,1), getPolickoZacDomPanacik(2,1),
            getPolickoZacDomTeam(3,2), getPolickoZacDomPanacik(3,2),getPolickoZacDomTeam(3,3), getPolickoZacDomPanacik(3,3),getPolickoHraciaTeam(20),getPolickoHraciaPanacik(20),getPolickoHraciaTeam(19),getPolickoHraciaPanacik(19),getPolickoHraciaTeam(18), getPolickoHraciaPanacik(18),getPolickoZacDomTeam(2,2), getPolickoZacDomPanacik(2,2),getPolickoZacDomTeam(2,3), getPolickoZacDomPanacik(2,3)
    );
}

