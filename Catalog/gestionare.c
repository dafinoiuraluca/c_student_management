#include <stdio.h>
#include "gestionare.h"
#include <string.h>



void afisare_clase()
{
    char a[25];
    int x = 9;
    for(int i = 0; i < 12; i++)
    {
        if(i % 3 == 0)
        {
            strcpy(a, "A ");
            strcat(a, "Matematica-Informatica");
            printf("%d%s\n", x, a);
            a[0] = '\0';
        }
        if(i % 3 == 1)
        {
            strcpy(a, "B ");
            strcat(a, "Stiintele Naturii");
            printf("%d%s\n", x, a);
            a[0] = '\0';
        }
        if(i % 3 == 2)
        {
            strcpy(a, "C ");
            strcat(a, "Stiinte Sociale");
            printf("%d%s\n", x, a);
            a[0] = '\0';
            x++;
        }
    }
}

void adaugare_elevi(const char *filename)
{
    char nume[20], prenume[20];
    int i, nr;
    printf("Introduceti numar de elevi: ");
    scanf("%d",&nr);
    FILE *fp;
    fp = fopen( filename ,"a");
    if(fp == NULL)
    {
        printf("Erroare!");
        exit(1);
    }
    for (i = 0; i < nr; i++)
    {
        printf("Student%d\nIntroduceti nume: ", i + 1);
        scanf("%s", nume);
        printf("Introduceti prenume: ", i + 1);
        scanf("%s", prenume);
        fprintf(fp ,"%s\n", nume);
        fprintf(fp ,"%s\n", prenume);
    }
    fclose(fp);
}

void afisare_elevi(const char *filename)
{
    char linie[20], aux[20];
    int k = 1;
    FILE *fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("Eroare!");
        exit(1);
    }
    for(int j = 0; j < 28; j++)
    {
        printf("%d)", j + 1);
        fgets(linie, sizeof(linie), fp);
        for(int i = 0; i < strlen(linie) - 1; i++)
        {
            printf("%c", linie[i]);
        }
        printf(" ");
        fgets(linie, sizeof(linie), fp);
        for(int i = 0; i < strlen(linie) - 1; i++)
        {
            printf("%c", linie[i]);
        }
        printf("\n");
    }
    fclose(fp);
}

void sterge_elev(const char *filename, int x)
{
    char linie[20];
    FILE *fp, *temp;
    fp = fopen(filename,"r");
    temp = fopen("temp.txt", "w");
    for(int i = 0; i < x - 1; i++)
    {
        fgets(linie, sizeof(linie), fp); //ia prima linie
        fputs(linie, temp);
        fgets(linie, sizeof(linie), fp); //ia urmatoarea linie
        fputs(linie, temp);
    }
    fgets(linie, sizeof(linie), fp); //citeste numele pe care vrem sa il stergem
    fgets(linie, sizeof(linie), fp);
    while(x < 28)
    {
        x++;
        fgets(linie, sizeof(linie), fp);
        fputs(linie, temp);
        fgets(linie, sizeof(linie), fp);
        fputs(linie, temp);
    }
    fclose(fp);
    fclose(temp);
    remove(filename);
    rename("temp.txt", filename);
    printf("Elevul a fost sters.\n");
    return 0;
}

void cautare_elev(const char* filename)
{
    int ok = 1;
    char nume[10], prenume[10], linie[10];
    float medie = 0;
    printf("Introduceti nume elev:");
    scanf("%s", nume);
    printf("Introduceti prenume elev:");
    scanf("%s", prenume);
    FILE *fp;
    fp = fopen(filename,"r");
    while(ok)
    {
        char aux[10];
        fscanf(fp, "%s", aux); //citeste string din fisier - aux
        if(strcmp(nume, aux) == 0)
        {
            fscanf(fp, "%s", aux);
            if(strcmp(prenume, aux) == 0)
            {
                printf("Elevul %s %s este in clasa %s si are media generala: %d \n", nume, prenume, filename, medie);
                break;
            }
            else
            {
                fgets(linie, sizeof(linie), fp); //mai citeste o linie
            }
        }
        else
        {
            fgets(linie, sizeof(linie), fp);
            fgets(linie, sizeof(linie), fp);
            /* for(int i = 0; i < strlen(linie) - 1; i++)
            {
                aux[i] = linie[i];
            } */
        }
    }
    fclose(fp);
    return 0;
}
