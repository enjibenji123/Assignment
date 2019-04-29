


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
   FILE *myFile = fopen("task1", "r");
   fseek( myFile, 6, SEEK_SET );
   while ( ( letter = fgetc(myFile)) != EOF)
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
   FILE *myFile1 = fopen("task1", "r");
   fseek( myFile1, 6, SEEK_SET );
   while ( ( letter = fgetc(myFile1)) != EOF)
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
   FILE *myFile = fopen("task2", "r");
   fseek( myFile, 6, SEEK_SET );
   while ( ( letter = fgetc(myFile)) != EOF)
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
   FILE *myFile1 = fopen("task2", "r");
   fseek( myFile1, 6, SEEK_SET );
   while ( ( letter = fgetc(myFile1)) != EOF)
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
    


  if (x == 3)
   {
  
    FILE *myFile = fopen("task3", "r");

    char charArray[26];
    char messageArray[26];
    int i;
    fseek( myFile, 30, SEEK_SET );
    for (i = 0; i < 26; i++)
     {
      fscanf(myFile, "%c" , &messageArray[i]);
     } 

    fseek( myFile, 4, SEEK_SET );
    for (i = 0; i < 26; i++)
     {
      fscanf(myFile, "%c" , &charArray[i]);
     } 
     
    for (i = 0; i < 50; i++)
    {
      int c = (messageArray[i]-'a');
      printf("%d", c);
      if (c > 0)
      {
         messageArray[i] = charArray[c]; 
      }
     
     
    }
  
     printf("%s", messageArray);
  
  
   }
   
   
   
   
   
   
   
   if (x == 4)
   {
  
    FILE *myFile = fopen("task4", "r");

    char charArray[26];
    char messageArray[26];
    int i;
    fseek( myFile, 30, SEEK_SET );
    for (i = 0; i < 26; i++)
     {
      fscanf(myFile, "%c" , &messageArray[i]);
     } 

    fseek( myFile, 4, SEEK_SET );
    for (i = 0; i < 26; i++)
     {
      fscanf(myFile, "%c" , &charArray[i]);
     } 

    for (i = 0; i < 50; i++)
    {
      int c = (messageArray[i]-'a');
      if (c > 0)
      {
        //printf("%d", c);
        int index = 0;  
        int l = 0;  
        while (  l < 26 )  
        {

         if (messageArray[i] == charArray[l])  
         {
             index = l;
         }  
         l++;
        }
        messageArray[i] = index + 'a';
      }      
    }
  
     printf("%s", messageArray);
  }
  
  
  
  
  if (x == 5)
  {
   char letter, asciichar;
   int num;
   FILE *myFile = fopen("task5", "r");
   while ( ( letter = fgetc(myFile)) != EOF)
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
  
   printf("  - This is the encrypted message.\n");
   int k;
   for(k=1; k<26; k++)
   {
    FILE *myFile1 = fopen("task5", "r");
    while ( ( letter = fgetc(myFile1)) != EOF)
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
     printf("  - This could be the message.\n"); 
    }
  
  }
}
