#include <time.h> 
#include <stdio.h>
 
int main()
{
	int i,number;
   srand((unsigned) time(NULL)); 
  
   for (i=0; i<10; i++)
   {
     number = rand() % 12 + 1;
     printf("%d\n", number);
   }
    
   return 0;
}
	
