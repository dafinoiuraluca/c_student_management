#include <stdio.h>
#include "medii.h"

struct clasa{
    int note[28][14];
    int orar[6][6];
    int absente[28];
}c[12];

void medie_materie()
{
    int numar_note;
    float nota, suma, medie;
    printf("Introduceti numarul de note:");
    scanf("%d", &numar_note);
    suma = 0;
    printf("Introduceti %d numere: ", numar_note);
    for(int i = 0; i < numar_note; i++)
    {
        scanf("%f", &nota);
        suma = suma + nota;
    }
    medie = suma/numar_note;
    printf("Media este = %0.2f\n", medie);
}

void medie_teza()
{
    int numar_note;
    int nota_teza = 0, medie2 = 0;
    float nota = 0.0f, suma = 0.0f, medie1 = 0.0f;
    printf("Introduceti nota teza:");
    scanf("%d", &nota_teza);
    printf("Introduceti numarul de note:");
    scanf("%d", &numar_note);
    printf("Introduceti %d numere: ", numar_note);
    for(int i = 0; i < numar_note; i++)
    {
        scanf("%f", &nota);
        suma += nota;
    }
    medie1 = suma/numar_note;
    medie2 = (nota_teza + 3 * medie1) / 4;
    printf("\nMedia este = %d\n", medie2);
}

void medie_generala(const char* filename, int k)
{
    float media = 0.0;
    int a[14] = {0};
    FILE *fp, *ptr;
    fp = fopen(filename, "r");
    strcat(filename, "medii");
    ptr = fopen(filename, "r");
    char linie[20];
    for(int i = 0; i < k - 1; i++)
    {
        fgets(linie, sizeof(linie), ptr);
        fgets(linie, sizeof(linie), fp);
        fgets(linie, sizeof(linie), fp);
    }
    char nume[20];
    char prenume[20];
    fscanf(fp, "%s", nume);
    fscanf(fp, "%s", prenume);
    for(int i = 0; i < 14; i++)
    {
        fscanf(ptr, "%d", &a[i]);
        media += a[i];
    }
    fclose(fp);
    media = media / 14;
    printf("Elevul %s %s are media generala %.2f\n", nume, prenume, media);
}

