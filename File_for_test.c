#define _CRT_SECURE_NO_WARNINGS 1
#define _WINSOCK_DEPRECATED_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>

#define symbols_number 10
#define DEST_SIZE 40

int read(char *text, int length)
{

    char *position = NULL;

    if(fgets(text, length, stdin) != NULL)
    {
        
        position = strchr(text, '\n');

        if(position != NULL)
        {
            *position = '\0';
        }
        return 1;
    }

    else
    {
        return 0;
    }

}


int read2(char *text, int length)
{
    if(fgets(text,length, stdin) != NULL)
    {
        char symbol[1] = "\n";

        for(int k= 0; k< strlen(text); k++)
        {
            if(text[k] == symbol[0])
            {
                text[k] = '\0';
                
            }

        }
        return 1;
    }

    else {
        return 0;
    }
}


void test(char *word)
{
    char test_word[]= "alpha";
    char *pointer_test = test_word;

    char *pointer = word;
    strcat(pointer, pointer_test);
}



int main()
{
    
    int combination = 0;

    int numbers_to_combine = 3;

    char table[numbers_to_combine] = {'1', '2', '3'};

    vector<char combine[]> a;


    for(int k(0); k < table.length(); k++)
    {


    }





   
 
}
