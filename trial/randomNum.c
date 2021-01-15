#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

	int r_num;
	int l_value = 0; 
	int  u_value = 9;
	
	
	srand(time(NULL));
	
	/* random  number in specific range -  (0-9) */
	r_num = ( rand() % ( u_value + 1) ) +  l_value ;
	
	printf("%d\n", r_num);
	
	
	return 0 ;
}	

/*
int getReward(void)
{

   int r;
   int s;
   
   int lower = 0;
   int upper = 9;
   
   srand(time(NULL));
   
   /* generate random number 0 to 9 */
   
   r = (rand() % ( upper  + 1 )) + lower;
   
   if (( r >=0 )&& ( r <= 2))
   {
   
   	s = 1;
   }
   else if ((r >= 3) && (r <= 6))
   {
   
   	s = 3;
   }
   else (( r >= 7) && (r <= 9))
   {
   	s = 2;
   }	
   return s;
 }
 */  	
   	
	
