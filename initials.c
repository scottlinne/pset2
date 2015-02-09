#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>


int main(void)
{
   // prompt user for their name
    char* name = GetString();
    
    // output initials in uppercase with no spaces
    printf("%c", toupper(name[0]));
    for(int i = 0; i < strlen(name); i++)
    {
      
      if(name[i] == ' ')
      {
       printf("%c", toupper(name[i+1]));
       }  
    }
    printf("\n");
}
