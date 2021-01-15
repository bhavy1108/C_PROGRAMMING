#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include"newSleep.h"
#include "file.h"
#include <string.h>


int main(int argc, char** argv)
{
    char fileHero[30];
    char fileEnemy[30];
    double sleep = 0.0;


    if (argc < 4 )
    {
        printf("Missing arguments!\n");
    }
    else 
    {
        strcpy(fileHero, argv[1]);
        strcpy(fileEnemy,argv[2]);
        sleep = atof(argv[3]);

        printf("WELCOME TO AUTO RPG\n\n");

      /* function call of the 2 readfile*/

          readH(fileHero);
          readE(fileEnemy);

          printf("sleep : %f\n",sleep);

    }
     return 0;

}