


#include <stdio.h>

int main() 
{
  int x;  
  scanf("%d\n", &x);
  if (x == 1)
  {
   char letter, asciinum;
   int num;
   FILE *text = fopen("task1", "r"); 
   while ( ( letter = fgetc(text)) != EOF)
    {     
     if (letter >= 'A' && letter <= 'Z')
      {
       num = letter - 'A' + 'a';
      } 
     else
      {
       num = letter;   
      }
 
     asciinum = num + 0;
     printf("%c", asciinum);
    }



    printf("\ncypher rotation value = %d\n", x);
   }
   
    
  
      
  
  

    
    

}
