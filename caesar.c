/*
cs50 2015
Scott Linne
pset2 Caesar cipher
encrypt a text string by k characters

*/


#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{


if(argc !=2 || atoi(argv[1]) < 0 )
{
    printf("Enter a non-negative integer: Usage ./caesar k\n");
    return 1;
}


int k = atoi(argv[1]);
char* p = GetString();


for(int i = 0; i < strlen(p); i++)
{
   // print space characters litterally, do not encipher
    if(p[i] == ' ')
    {
        printf(" ");
    }
    
    // if the character is not an alphacharacter, do not encipher it, print it literally
    else if(!isalpha(p[i]))
    {
      printf("%c", p[i]);
    }
    
    // encipher alpha characters only
    else
    {
        // formula to enciper uppercase characters
        if(isupper(p[i]))
        {
        // set alpha characters to start from zero (A - A would be zero)
        int letter = p[i]-'A';
        // caesar cipher formula letter value plus cipher
        int cipher = ((letter +k)%26)+'A';
          printf("%c", cipher);
        }
        // formula to encipher lowercase characters
        if(islower(p[i]))
        {
        // set alpha characters to start from zero (a - a would be zero)
        int letter = p[i]-'a';
         // caesar cipher formula letter value plus cipher
        int cipher = ((letter +k)%26)+'a';
          printf("%c", cipher);
        }

      
    }
}
    printf("\n");

}
