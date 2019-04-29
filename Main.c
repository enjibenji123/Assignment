


#include <stdio.h>

int main() 
{
 int x;  
 scanf("%d\n", &x);
  
 if (x == 1)
  {
   int k;
   scanf("%d\n", &k);
   if (k < 0)
    {
     k = k * - 1;   
    }   
   char letter, asciichar;
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
 
     asciichar = num + 0;
     printf("%c", asciichar);
    } 
  
   printf("  - This is the original message.\n");
   FILE *text1 = fopen("task1", "r");
   while ( ( letter = fgetc(text1)) != EOF)
    {
     if (letter >= 'A' && letter <= 'Z')
       {
        num = letter - 'A';   
        num = (num + k)%(26);
        num = num + 'a';
       }  
     else if (letter >= 'a' && letter <= 'z')
       {
        num = letter - 'a'; 
        num = (num + k)%(26);
        num = num + 'a';
       }
     else
       {
        num = letter;  
       }
      asciichar = num + 0; 
      printf("%c",asciichar);
    }
   
   printf("  - This is the encrypted message.\n"); 
   printf("\ncypher rotation value = %d\n", k);
  }
 
 
 
 if (x == 2)
  {
   int k;
   scanf("%d\n", &k);
   if (k < 0)
    {
     k = k * - 1;   
    }   
   char letter, asciichar;
   int num;
   FILE *text = fopen("task2", "r");
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
 
     asciichar = num + 0;
     printf("%c", asciichar);
    } 
  
   printf("  - This is the original message.\n");
   FILE *text1 = fopen("task2", "r");
   while ( ( letter = fgetc(text1)) != EOF)
    {
     if (letter >= 'A' && letter <= 'Z')
       {
        num = letter - 'A';  
        num = (num - k)%(26);
        if (num < 0)
         {
          num = 26 + num;
         } 
        num = num + 'a';
       }  
     else if (letter >= 'a' && letter <= 'z')
       {
        num = letter - 'a';
        num = (num - k)%(26);
        if (num < 0)
         {
          num = 26 + num;
         } 
        num = num + 'a';
       }
     else
       {
        num = letter;  
       }
      asciichar = num + 0; 
      printf("%c",asciichar);
    }
   
   printf("  - This is the decrypted message.\n"); 
   printf("\ncypher rotation value = %d\n", k);
  }
    
  
}
