#include <stdio.h>
#include "informatii.h"
#include <string.h>

void apelare_medii()
{
    initializare_medii("9amedii", c, 0);
    initializare_medii("9bmedii", c, 1);
    initializare_medii("9cmedii", c, 2);
    initializare_medii("10amedii", c, 3);
    initializare_medii("10bmedii", c, 4);
    initializare_medii("10cmedii", c, 5);
    initializare_medii("11amedii", c, 6);
    initializare_medii("11bmedii", c, 7);
    initializare_medii("11cmedii", c, 8);
    initializare_medii("12amedii", c, 9);
    initializare_medii("12bmedii", c, 10);
    initializare_medii("12cmedii", c, 11);
}

void initializare_medii(const char *filename, struct clasa c[], int x)
{
    FILE *fp;
    fp = fopen(filename, "r");
    for(int i = 0; i < 28; i++)
    {
        for(int j = 0; j < 14; j++)
        {
            fscanf(fp, "%d", &c[x].note[i][j]);
        }
    }
    fclose(fp);
}

void afisare_note_clasa(const char *filename, int x)
{
    FILE *fp = fopen(filename, "r");
    char nume[20], prenume[20], linie[20];
    printf("Introduceti numar aferent clasei(9A-1, 9B-2, 9C-3, 10A-4, 10B-5, 10C-6, 11A-7, 11B-8, 11C-9, 12A-10, 12B-11, 12C-12): \n");
    scanf("%d", &x);
    for(int i = 0; i < 28; i++)
    {
        printf("%d)", i+1);
        fscanf(fp, "%s", linie);
        printf("%s ", linie);
        fscanf(fp, "%s", linie);
        printf("%s:", linie);
        for(int j = 0; j < 14; j++)
        {
            printf("%d ", c[x - 1].note[i][j]);
        }
        printf("\n");
    }
    fclose(fp);
}

void afisare_orar()
{
    int a[7][6], k = 0;
    char linie[20], filename[10]= "orar", nume_clasa[4];
    printf("Introduceti clasa(9-12)(a,b,c): ");
    scanf("%s", nume_clasa);
    strcat(filename,nume_clasa);
    FILE *fp = fopen(filename, "r");
    int x = 8, y = 9;
    printf("\t\tOrar %s:\n", nume_clasa);
    for(int i = 0; i < 7; i++)
    {
        fscanf(fp,"%d%d%d%d%d%d", &a[i][0], &a[i][1], &a[i][2], &a[i][3], &a[i][4], &a[i][5]);
    }
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            if((i == 0) && (j == 0))
            {
                printf("   Ora  ");
            }
            else
            {
                if((i == 0) && (j != 0) && (j != 3))
                {
                    printf("\t");
                    materii(13+j, 1);
                }
                if((i == 0) && (j == 3))
                {
                    printf("\t");
                    materii(13+j ,0);
                }
                else
                {
                    if((i != 0) && (j != 0))
                    {
                        materii(a[i][j], 1);
                        printf("\t");
                    }
                }
                if(j==0 && i!=0)
                {
                    printf("%d:00-%d:00\t", x, y);
                    x = y;
                    y++;
                }
            }

        }
        printf("\n");
    }
}

void materii(int x, int ok)
{
    FILE *fp = fopen("Materii", "r");
    char linie[15];
    int y = 0;
    for(int i = 0; i < x; i++)
    {
        fgets(linie, sizeof(linie), fp);
    }
    fgets(linie, sizeof(linie), fp);
    for(int i = 0; i < strlen(linie)-1; i++)
    {
        printf("%c", linie[i]);
        y++;
    }
    if(y < 8 && ok)
    {
        printf("\t");
    }
    fclose(fp);
}

void adaugare_absente()
{
    printf("Introduceti clasa(9A-1, 9B-2, 9C-3, 10A-4, 10B-5, 10C-6, 11A-7, 11B-8, 11C-9, 12A-10, 12B-11, 12C-12): ");
    int nr_clasa;
    scanf("%d", &nr_clasa);
    printf("Introduceti numar elev: ");
    int nr_elev;
    scanf("%d", &nr_elev);
    int nr_absente;
    printf("Introduceti numar absente: ");
    scanf("%d", &nr_absente);
    c[nr_clasa - 1].absente[nr_elev - 1] += nr_absente;
}

void motivare_absente()
{
    printf("Introduceti clasa(9A-1, 9B-2, 9C-3, 10A-4, 10B-5, 10C-6, 11A-7, 11B-8, 11C-9, 12A-10, 12B-11, 12C-12): ");
    int nr_clasa;
    scanf("%d", &nr_clasa);
    printf("Introduceti numar elev: ");
    int nr_elev;
    scanf("%d", &nr_elev);
    int nr_absente;
    printf("Introduceti numarul de absente pe care doriti sa il motivati: ");
    scanf("%d", &nr_absente);
    c[nr_clasa - 1].absente[nr_elev - 1] -= nr_absente;
    printf("%d", nr_absente);
    printf("Absentele au fost motivate.\n");
    printf("%d", c[nr_clasa - 1].absente[nr_elev - 1]);
}

void golire_vector(int v[])
{
    for(int i = 0; i < 28; i++)
    {
        v[i] = 0;
    }
}

void medie_purtare()
{
    int mediep = 10;
    printf("Introduceti clasa(9A-1, 9B-2, 9C-3, 10A-4, 10B-5, 10C-6, 11A-7, 11B-8, 11C-9, 12A-10, 12B-11, 12C-12): ");
    int nr_clasa;
    scanf("%d", &nr_clasa);
    printf("Introduceti numar elev: ");
    int nr_elev;
    scanf("%d", &nr_elev);
    mediep -= c[nr_clasa - 1].absente[nr_elev - 1] / 10;
    printf("Media la purtare este: %d\n", mediep);
}

void initializare_absente()
{
    for(int i = 0; i < 12; i++)
    {
        golire_vector(c[i].absente);
    }
}
