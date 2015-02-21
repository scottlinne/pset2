/*
Scott Linne
CS50 2015
Pset2 Vigenere Cipher
Encrypt a string using a keyword entered at the command line

*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
   
    // check that there are two command line arguments, if not, exit program with message
    if(argc != 2)
    {
        printf("usage: ./vigenere [keyword]\n");
        return 1;
    }    
    
    // store argument 1 keyword in variable named keyword
    string keyword = argv[1];
    for(int i = 0; i < strlen(keyword); i++)
    {
        // check if the keyword has any non-alpha characters, and if so exit program with message.
        if(!isalpha(keyword[i]))
        {
            printf("please enter a keyword with alpha characters only\n");
            return 1;
        }
     
    }
    
    // get plaintext string from user and store in variable p
    string p = GetString();
    
    // encrypt plaintext string using the letters from the user's keyword
    // initiliaze a counter variable j for the keyword
    int j = 0;
    for(int i = 0; i < strlen(p); i++)
    {
        // convert keyword letters to uppercase and set alphabet to start at 0
        int k = toupper(keyword[j]) - 'A';
        
        // if the plaintext letter is uppercase
        if(isupper(p[i]))
        {
          // int k = toupper(keyword[j]) - 'A';
           int letter = p[i] - 'A';
           int cipher = ((letter + k)%26) + 'A';
           printf("%c", cipher);
           j++;
           if(j == strlen(keyword))
            {
                j = 0;
            }
        }
        
        // if the plaintext letter is lowercase
        else if (islower(p[i]))
        {
            int letter = p[i] - 'a';
            int cipher = ( (letter + k)%26) + 'a';
            printf("%c", cipher);
            j++;
            if(j == strlen(keyword))
            {
                j = 0;
            }
        
        }
        
        // if the plaintext character is not a letter, do not encipher
       else
       {
        printf("%c", p[i]);
       }
    }
    // just to go to new line
    printf("\n");
}
