
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Ben Harris, c3318216.
//Assignment 1
//Below is a block of code which should be able to encrypt and decrypt text using both a rotation cypher and a substitution cypher.
//To select which function to use you must run a certain task.
//Task 1 : Cypher encryption of a message with a key : This task takes a message and a rotation value and encrypts your original message by cycling the letters in the alphabet. The task then returns the encrypted message.
//Task 2 : Cypher decryption of a message with a key : This task takes an encrypted message and a rotation value and decrpts the message by cycling back the letters in the alphabet. The task the returns the decrypted message.
//Task 3 : Substitution encryption of a message with a key : This task takes a message and encrypts it with a substituted alphabet. The task then returns the encrypted message.
//Task 4 : Substitution decryption of a message with a key : This task takes an encrytped message and decrypts it using the substituted alphabet key. The task then returns the decrypted message.
//Task 5 : Cypher decyption of a message without a key : This task takes an encrypted message with no key. The task the returns the decrypted message 25 more times with one answer being the decrypted message.

int main() 
{
 int x;                 
 scanf("%d\n", &x);     //scan file for number of file and assign to x to help choose which task to use.
 
 
 //Task 1 : Cypher encryption of a message with a key : This task takes a message and a rotation value and encrypts your original message by cycling the letters in the alphabet. The task then returns the encrypted message.
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
   FILE *myFile = fopen("task1", "r");           //Opens and reads my file 
   fseek( myFile, 6, SEEK_SET );
   while ( ( letter = fgetc(myFile)) != EOF)     //Gets each character from file unt reaching end of file
    {     
     if (letter >= 'a' && letter <= 'z')         //Checks for lower case letters 
      {
       num = letter - 'a' + 'A';                 //Converts lower case letters to upper case equivilent
      } 
     else
      {
       num = letter;   
      }
 
     asciichar = num + 0;                        //Converts num to character, ready for printing
     printf("%c", asciichar);
    } 
  
   printf("  - This is the original message.\n");
   FILE *myFile1 = fopen("task1", "r");             //Opens and reads my file 
   fseek( myFile1, 6, SEEK_SET );
   while ( ( letter = fgetc(myFile1)) != EOF)         //Gets each character from file unt reaching end of file
    {
     if (letter >= 'a' && letter <= 'z')             //Checks for lower case letters
       {
        num = letter - 'a';   
        num = (num + k)%(26);                         //Converts lower case letters to upper case equivilent & also rotates number through alphabet by amount k
        num = num + 'A';
       }  
     else if (letter >= 'A' && letter <= 'Z')
       {
        num = letter - 'A'; 
        num = (num + k)%(26);                        //rotates number through alphabet by amount k
        num = num + 'A';
       }
     else
       {
        num = letter;  
       }
      asciichar = num + 0;                        //Converts num to character, ready for printing
      printf("%c",asciichar);
    }
   
   printf("  - This is the encrypted message.\n"); 
   printf("\ncypher rotation value = %d\n", k);
  }
 
 
 
 
//Task 2 : Cypher decryption of a message with a key : This task takes an encrypted message and a rotation value and decrpts the message by cycling back the letters in the alphabet. The task the returns the decrypted message. 
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
   FILE *myFile = fopen("task2", "r");                   //Opens and reads my file 
   fseek( myFile, 6, SEEK_SET );
   while ( ( letter = fgetc(myFile)) != EOF)             //Gets each character from file unt reaching end of file
    {     
     if (letter >= 'a' && letter <= 'z')                 //Checks for lower case letters
      {
       num = letter - 'a' + 'A';                         //Converts lower case letters to upper case equivilent
      } 
     else
      {
       num = letter;   
      }
 
     asciichar = num + 0;                                   //Converts num to character, ready for printing
     printf("%c", asciichar);
    } 
  
   printf("  - This is the original message.\n");
   FILE *myFile1 = fopen("task2", "r");                    //Opens and reads my file 
   fseek( myFile1, 6, SEEK_SET );
   while ( ( letter = fgetc(myFile1)) != EOF)              //Gets each character from file unt reaching end of file
    {
     if (letter >= 'a' && letter <= 'z')                  //Checks for upper case letters
       {
        num = letter - 'a';  
        num = (num - k)%(26);                            //Converts lower case letters to upper case equivilent & also rotates number backward through alphabet by amount k
        if (num < 0)
         {
          num = 26 + num;
         } 
        num = num + 'A';
       }  
     else if (letter >= 'A' && letter <= 'Z')
       {
        num = letter - 'A';
        num = (num - k)%(26);                               //rotates number backward through alphabet by amount k
        if (num < 0)
         {
          num = 26 + num;
         } 
        num = num + 'A';
       }
     else
       {
        num = letter;  
       }
      asciichar = num + 0;                                   //Converts num to character, ready for printing
      printf("%c",asciichar);
    }
   
   printf("  - This is the decrypted message.\n"); 
   printf("\ncypher rotation value = %d\n", k);
  }
    


//Task 3 : Substitution encryption of a message with a key : This task takes a message and encrypts it with a substituted alphabet. The task then returns the encrypted message.
  if (x == 3)
   {
  
    FILE *myFile = fopen("task3", "r");               //Opens and reads my file 

    char charArray[26];                             //Creates an array of char and of size 26 for key
    char messageArray[50];                          //Creates an array of char and of size 50 for message
    int i;
    fseek( myFile, 30, SEEK_SET );                 //Set cursor position in file ready to read message
    for (i = 0; i < 50; i++)
     {
      fscanf(myFile, "%c" , &messageArray[i]);        //Scans and reads message to be encrypted
     } 

    fseek( myFile, 4, SEEK_SET );                     //Set cursor position in file ready to read key
    for (i = 0; i < 26; i++)
     {
      fscanf(myFile, "%c" , &charArray[i]);           //Scans and reads key
     } 
     
    for (i = 0; i < 50; i++)                          //cycles through characters in message
    {  
      int c = (messageArray[i]-'A');                   //Set c equal to number of letter in alphabet i.e a=0
      if ((32 < c) && ( c < 64 ))                     //Checks for lower case letters 
      {
          c = c - 32;                                  //Converts lower case letters to upper case equivilent
      }
      if (c > 0)                                     //Makes sure only characters over 0 are transfered
      {
         messageArray[i] = charArray[c];                //Sets character to substitution character i,e a = charArray[c]
      }
     
     
    }
  
     printf("%s", messageArray);
  
  
   }
   
   
   
   
   
   
  //Task 4 : Substitution decryption of a message with a key : This task takes an encrytped message and decrypts it using the substituted alphabet key. The task then returns the decrypted message. 
   if (x == 4)
   {
  
    FILE *myFile = fopen("task4", "r");                          //Opens and reads my file 

    char charArray[26];                                     //Creates an array of char and of size 26 for key
    char messageArray[50];                                 //Creates an array of char and of size 50 for message
    int i;
    fseek( myFile, 30, SEEK_SET );                         //Set cursor position in file ready to read message
    for (i = 0; i < 50; i++)
     {
      fscanf(myFile, "%c" , &messageArray[i]);             //Scans and reads message to be decrypted
     } 

    fseek( myFile, 4, SEEK_SET );                         //Set cursor position in file ready to read key
    for (i = 0; i < 26; i++)
     {
      fscanf(myFile, "%c" , &charArray[i]);               //Scans and reads key
     } 

    for (i = 0; i < 50; i++)                              //cycles through characters in message
    {
      int c = (messageArray[i]-'A');                        //Set c equal to number of letter in alphabet i.e a=0
      if ((32 < c) && ( c < 58 ))                           //Checks for lower case letters 
      {
          c = c - 32;                                        //Converts lower case letters to upper case equivilent
          messageArray[i] = c + 'A';
      }
      if (c > 0)                                           //Makes sure only characters over 0 are transfered
      {
        int index = 0;  
        int l = 0;  
        while (  l < 26 )                                 //Cycles through characters in key
        {

         if (messageArray[i] == charArray[l])                 //Looks for Character in key
         {
             index = l;                                      //Index is set to value of chacter in key
             l = 26;                                        // Character found so loop can end
         }  
         l++;
        }
        messageArray[i] = index + 'A';                   //Decrypts text
      }      
    }
  
     printf("%s", messageArray);
  }
  
  
  
 //Task 5 : Cypher decyption of a message without a key : This task takes an encrypted message with no key. The task the returns the decrypted message 25 more times with one answer being the decrypted message. 
  if (x == 5)
  {
   char letter, asciichar;
   int num;
   FILE *myFile = fopen("task5", "r");                           //Opens and reads my file 
   while ( ( letter = fgetc(myFile)) != EOF)                    //Gets each character from file unt reaching end of file
    {     
     if (letter >= 'a' && letter <= 'z')                       //Checks for lower case letters
      {
       num = letter - 'a' + 'A';                             //Converts lower case letters to upper case equivilent
      } 
     else
      {
       num = letter;   
      }
 
     asciichar = num + 0;                                      //Converts num to character, ready for printing
     printf("%c", asciichar);
    } 
  
   printf("  - This is the encrypted message.\n");
   int k;
   for(k=1; k<26; k++)                                        //cycles through 25 different rotations to find the decrypted message
   {
    FILE *myFile1 = fopen("task5", "r");                       //Opens and reads my file 
    while ( ( letter = fgetc(myFile1)) != EOF)                 //Gets each character from file unt reaching end of file
     {
      if (letter >= 'a' && letter <= 'z')                     //Checks for lower case letters
        {
         num = letter - 'a';   
         num = (num + k)%(26);                               //Converts lower case letters to upper case equivilent
         num = num + 'A';
        }  
      else if (letter >= 'A' && letter <= 'Z')
        {
         num = letter - 'A'; 
         num = (num + k)%(26);
         num = num + 'A';
        }
      else
        { 
         num = letter;  
        }
       asciichar = num + 0;                                //Converts num to character, ready for printing
       printf("%c",asciichar);
     }
     printf("  - This could be the message.\n"); 
    }
  
  }
}
