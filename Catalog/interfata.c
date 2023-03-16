#include <stdio.h>
#include "interfata.h"

struct scoala {
    char nume_clasa[3];
    char profil[25];
    int numar_clasa;
};

struct clasa {
    int note[28][5];
    int orar[6][6];
    int absente[28];
}c[12];

void alegere_optiune()
{
    struct scoala clasa[12];
    struct clasa c;
    int op = 0;
    char filename[5];
    meniu_principal();
    printf("Introduceti optiunea\n");
    scanf("%d", &op);
    switch(op)
    {
        case 1:
            afisare_clase(clasa);
            printf("******************************************************************************************\n");
            alegere_optiune();
            break;
        case 2:
            printf("Introduceti nume clasa: \n");
            scanf("%s", filename);
            adaugare_elevi(filename);
            printf("******************************************************************************************\n");
            alegere_optiune();
            break;
        case 3:
            printf("Introduceti nume clasa: \n");
            scanf("%s", filename);
            afisare_elevi(filename);
            printf("******************************************************************************************\n");
            alegere_optiune();
            break;
        case 4:
            printf("Introduceti clasa si numar elev: \n");
            scanf("%s", filename);
            scanf("%d", &op);
            sterge_elev(filename, op);
            printf("******************************************************************************************\n");
            alegere_optiune();
            break;
        case 5:
            printf("Introduceti clasa: \n");
            scanf("%s", filename);
            cautare_elev(filename);
            printf("******************************************************************************************\n");
            alegere_optiune();
            break;
        case 6:
            printf("Introduceti clasa: \n");
            scanf("%s", filename);
            afisare_note_clasa(filename, 0);
            printf("******************************************************************************************\n");
            alegere_optiune();
            break;
         case 7:
            afisare_orar(filename);
            printf("******************************************************************************************\n");
            alegere_optiune();
            break;
        case 8:
            printf("Medie materie fara teza:\n");
            medie_materie();
            printf("******************************************************************************************\n");
            alegere_optiune();
            break;
        case 9:
            medie_teza();
            printf("******************************************************************************************\n");
            alegere_optiune();
            break;
        case 10:
            printf("Introduceti clasa si numar elev:\n");
            scanf("%s", filename);
            scanf("%d", &op);
            medie_generala(filename, op);
            printf("******************************************************************************************\n");
            alegere_optiune();
            break;
            case 11:
            adaugare_absente();
            printf("******************************************************************************************\n");
            alegere_optiune();
            break;
        case 12:
            motivare_absente();
            printf("******************************************************************************************\n");
            alegere_optiune();
            break;
        case 13:
            medie_purtare();
            printf("******************************************************************************************\n");
            alegere_optiune();
            break;
        default:
            printf("STOP\n");
            printf("******************************************************************************************\n");
            break;
    }
}

void meniu_principal()
{
    printf("0. STOP\n");
    printf("1. Afisare clase\n");
    printf("2. Adauga elev\n");
    printf("3. Afisare elevi\n");
    printf("4. Sterge elev\n");
    printf("5. Cauta elev\n");
    printf("6. Afisare note pe clasa\n");
    printf("7. Afisare orar\n");
    printf("8. Medie materie fara teza\n");
    printf("9. Medie materie cu teza\n");
    printf("10. Medie generala\n");
    printf("11. Adaugare absente\n");
    printf("12. Motivare absente\n");
    printf("13. Medie purtare\n");
}


