#include <stdio.h>
#include <string.h>
#include "file.h"
#include "struct.h"

void readH(char  fileHero[])
{
    FILE* file;
     struct battle b;

    file = fopen(fileHero, "r");

    if (file == NULL)
    {
        printf("The file cannot be open , try another file.\n");
    }
    else
    {
       do
       {
           fscanf(file, "%d %c %d %c %d %c %d %c %s", &b.hp, &b.coma, &b.atk, &b.coma,&b.def, &b.coma, &b.med, &b.coma, b.name);
      
       }while(!feof(file));

        printf("Hero :\n");
        printf("%s\t", b.name);
        printf("HP:%d\t", b.hp);
        printf("ATK:%d\t", b.atk);
        printf("DEF:%d\t", b.def);
        printf("MED:%d\t", b.med);
        printf("\n");
        printf("\n");

    }   
    fclose(file);
}

void readE(char  fileEnemy[])
{
    FILE* file2;
     struct battle b;

    file2 = fopen(fileEnemy, "r");

    if (file2 == NULL)
    {
        printf("The file cannot be open , try another file.\n");
    }
    else
    {
       do
       {
           fscanf(file2, "%d %c %d %c %d %c %s", &b.hp, &b.coma, &b.atk, &b.coma,&b.def, &b.coma, b.name);
      
       }while(!feof(file2));

        printf("Enemies :\n");
        printf("%s\t", b.name);
        printf("HP:%d\t", b.hp);
        printf("ATK:%d\t", b.atk);
        printf("DEF:%d\t", b.def);
        printf("\n");
       

    }   
    fclose(file2);
}




