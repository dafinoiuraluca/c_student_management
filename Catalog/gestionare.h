#ifndef GESTIONARE_H_INCLUDED
#define GESTIONARE_H_INCLUDED

#include <stdlib.h>

struct scoala {
    char nume_clasa[3];
    char profil[25];
    int numar_clasa;
};

extern void afisare_clase();
extern void adaugare_elevi(const char *);
extern void afisare_elevi(const char *);
extern void sterge_elev(const char *, int);
extern void cautare_elev(const char *);

#endif // GESTIONARE_H_INCLUDED
