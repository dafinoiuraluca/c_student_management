#ifndef INFORMATII_H_INCLUDED
#define INFORMATII_H_INCLUDED

#include <stdlib.h>

struct clasa{
    int note[28][14];
    int orar[6][6];
    int absente[28];
}c[12];

extern void apelare_medii();
extern void initializare_medii(const char *, struct clasa *, int);
extern void afisare_note_clasa(const char *, int);
extern void afisare_orar();
extern void materii(int, int);
extern void adaugare_absente();
extern void motivare_absente();
extern void initializare_absente();
extern void golire_vector();
extern void medie_purtare();

#endif // INFORMATII_H_INCLUDED
