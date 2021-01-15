#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
#include "file.h"
#include "match.h"
#include "newSleep.h"
#include "lines.h"

/*
** Main method read the file , the user has provided in the terminal
** It also, calls the method findBracketAndDisplay which hence , output the 
** result in the terminal  
*/

int main(int argc,  char**argv)
{
      
	char lines[50][150];
	int numLines = 0;
     
	if(argc!=2)
	{
	     printf("Arguments are missing!!\n");
	}
	else
	 {
	     numLines = read(argv[1],lines );
		findBracketAndDisplay(lines,numLines);
	 }
	return 0;   
}

