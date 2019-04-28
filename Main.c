





#include <stdio.h>

int main() 
{
  int x;
  char c;
  scanf("%d\n", &x);
  if (x == 1)
  {
  FILE *text = fopen("task1", "r"); 
  while ( ( c = fgetc(text)) != EOF)
    {
    int xc = c;
    printf("\n%d", xc);    
    if ( 65 <= xc <= 90 )
     {
      xc = (xc + 32);   
     }
    char i = xc;
    printf("%c", i);
    }







  }
    printf("\ncypher rotation value = %d\n", x);
    
  
      
  
  

    
    
    
    
    
    
    
    
    
    
    

}
