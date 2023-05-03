#define _CRT_SECURE_NO_WARNINGS 1
#define _WINSOCK_DEPRECATED_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define other_symbols_number 1
#define symbols_number 9
#define text_length 1000

#pragma region functions
int read(char *chaine, int longueur)
{
    char *positionEntree = NULL;
 
    if (fgets(chaine, longueur, stdin) != NULL) 
    {
        positionEntree = strchr(chaine, '\n'); 
        if (positionEntree != NULL) 
        {
            *positionEntree = '\0'; 
        }
        return 1; 
    }
    else
    {
        return 0;
    }
}

char *cryptographie_function(char *letter, char *word)
{
    srand(time(NULL));
    char crypted_symbol[text_length] = "";
    char *pointer_crypted_symbol = crypted_symbol;
    char *word_pointer = word;
    char space[1] = " "; 

    int b = 0, c = 0;
    char symbols[symbols_number] = {'^', '~', '$', '#','@','!','&','*','+',};

    int associated_number[symbols_number] = {1, 2, 5, 10, 20, 50, 100,200, 500};

    //alfabet from a to z
    switch(letter[0])
    {
        case 'a':
        b = 300;
        break;
        case 'b':
        b = 310;
        break;
        case 'c':
        b = 320;
        break;
        case 'd':
        b = 330;
        break;
        case 'e':
        b = 340;
        break;
        case 'f':
        b = 350;
        break;
        case 'g':
        b = 360;
        break;
        case 'h':
        b = 370;
        break;
        case 'i':
        b = 380;
        break;
        case 'j':
        b = 390;
        break;
        case 'k':
        b = 400;
        break;
        case 'l':
        b = 410;
        break;
        case 'm':
        b = 420;
        break;
        case 'n':
        b = 430;
        break;
        case 'o':
        b = 440;
        break;
        case 'p':
        b = 450;
        break;
        case 'q':
        b = 460;
        break;
        case 'r':
        b = 470;
        break;
        case 's':
        b = 480;
        break;
        case 't':
        b = 490;
        break;
        case 'u':
        b = 500;
        break;
        case 'v':
        b = 510;
        break;
        case 'w':
        b = 520;
        break;
        case 'x':
        b = 530;
        break;
        case 'y':
        b = 540;
        break;
        case 'z':
        b = 550;
        break;
        default:
        break;
    }
    

    //Capital alfabet from a to z
    switch(letter[0])
    {
        case 'A':
        b=305;
        break;
        case 'B':
        b = 315;
        break;
        case 'C':
        b=325;
        break;
        case 'D':
        b=335;
        break;
        case 'E':
        b=345;
        break;
        case 'F':
        b=355;
        break;
        case 'G':
        b=365;
        break;
        case 'H':
        b=375;
        break;
        case 'I':
        b=385;
        break;
        case 'J':
        b=395;
        break;
        case 'K':
        b=405;
        break;
        case 'L':
        b=415;
        break;
        case 'M':
        b=425;
        break;
        case 'N':
        b=435;
        break;
        case 'O':
        b=445;
        break;
        case 'P':
        b=455;
        break;
        case 'Q':
        b=465;
        break;
        case 'R':
        b=475;
        break;
        case 'S':
        b=485;
        break;
        case 'T':
        b = 495;
        break;
        case 'U':
        b = 505;
        break;
        case 'V':
        b= 515;
        break;
        case 'W':
        b = 525;
        break;
        case 'X':
        b = 535;
        break;
        case 'Y':
        b = 545;
        break;
        case 'Z':
        b = 555;
        break;
        default:
        break;
    }


    //symbols
    switch(letter[0])
    {
        case ' ':
        b = 100;
        break;
        case ',':
        b = 110;
        break;
        case '.':
        b = 120;
        break;
        case '!':
        b = 130;
        break;
        case '/':
        b = 140;
        break;
        case '-':
        b = 150;
        break;
    }

    while(b!= 0)
    {       
        c = rand() % symbols_number;
       
        if(b - associated_number[c] >= 0)
        {  
            
            strncat(pointer_crypted_symbol, &symbols[c], 1);
            b -= associated_number[c];          
        }
    }
    //printf("%d", b);

   
    strcat(crypted_symbol, "?");

    strcat(word_pointer, pointer_crypted_symbol);


    return word;
}

char *cryptographie(char *text_to_cryptographie)
{

char letter[1] = "";

static char crypted_word[text_length];

char alfabet[27] = {'a', 'b', 'c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z', ' '} ;

char space[1] = " ";


for (int f = 0; f < strlen(text_to_cryptographie); f++)
{

    for(int k=0; k<strlen(alfabet)-2; k++)
    {
    
        if(text_to_cryptographie[f] == alfabet[k])
        {            
            letter[0] = alfabet[k];

            cryptographie_function(letter, crypted_word);            
        }     

    }

}
  
    return crypted_word;
}

char *decryptographie(char *text_to_cryptographie)
{
    int associated_number[symbols_number] = {1, 2, 5, 10, 20, 50, 100, 200, 500};
    char symbols[symbols_number] = {'^', '~', '$', '#', '@', '!', '&', '*', '+'};
    unsigned decode = 0;
    char decrypted_word[text_length] = "";
    char space[1] = "?";
    char space2[1] = ">";
    
    char *pointer_decrypted_word = decrypted_word;

    char *pointer_text_to_cryptographie = text_to_cryptographie;

    for (int k = 0; k < strlen(text_to_cryptographie); k++)
    {
        for (int f = 0; f < symbols_number; f++)
        {

            if (text_to_cryptographie[k] == symbols[f])
            {

                decode += associated_number[f];   
            }

            if (text_to_cryptographie[k] == space[0])
            {
                switch (decode)
                {
                case 100:
                    strcat(decrypted_word, " ");
                    decode = 0;
                    break;

                case 300:
                    strcat(decrypted_word, "a");
                    decode = 0;
                    break;
                case 310:
                    strcat(decrypted_word, "b");
                    decode = 0;
                    break;
                case 320:
                    strcat(decrypted_word, "c");
                    decode = 0;
                    break;
                case 330:
                    strcat(decrypted_word, "d");
                    decode = 0;
                    break;
                case 340:
                    strcat(decrypted_word, "e");
                    decode = 0;
                    break;
                case 350:
                    strcat(decrypted_word, "f");
                    decode = 0;
                    break;
                case 360:
                    strcat(decrypted_word, "g");
                    decode = 0;
                    break;
                case 370:
                    strcat(decrypted_word, "h");
                    decode = 0;
                    break;
                case 380:
                    strcat(decrypted_word, "i");
                    decode = 0;
                    break;
                case 390:
                    strcat(decrypted_word, "j");
                    decode = 0;
                    break;
                case 400:
                    strcat(decrypted_word, "k");
                    decode = 0;
                    break;
                case 410:
                    strcat(decrypted_word, "l");
                    decode = 0;
                    break;
                case 420:
                    strcat(decrypted_word, "m");
                    decode = 0;
                    break;
                case 430:
                    strcat(decrypted_word, "n");
                    decode = 0;
                    break;
                case 440:
                    strcat(decrypted_word, "o");
                    decode = 0;
                    break;
                case 450:
                    strcat(decrypted_word, "p");
                    decode = 0;
                    break;
                case 460:
                    strcat(decrypted_word, "q");
                    decode = 0;
                    break;
                case 470:
                    strcat(decrypted_word, "r");
                    decode = 0;
                    break;
                case 480:
                    strcat(decrypted_word, "s");
                    decode = 0;
                    break;
                case 490:
                    strcat(decrypted_word, "t");
                    decode = 0;
                    break;
                case 500:
                    strcat(decrypted_word, "u");
                    decode = 0;
                    break;
                case 510:
                    strcat(decrypted_word, "v");
                    decode = 0;
                    break;
                case 520:
                    strcat(decrypted_word, "w");
                    decode = 0;
                    break;
                case 530:
                    strcat(decrypted_word, "x");
                    decode = 0;
                    break;
                case 540:
                    strcat(decrypted_word, "y");
                    decode = 0;
                    break;
                case 550:
                    strcat(decrypted_word, "z");
                    decode = 0;
                    break;
                default:
                    break;
                }
                switch (decode)
                {

                case 305:
                    strcat(decrypted_word, "A");
                    decode = 0;
                    break;
                case 315:
                    strcat(decrypted_word, "B");
                    decode = 0;
                    break;
                case 325:
                    strcat(decrypted_word, "C");
                    decode = 0;
                    break;
                case 335:
                    strcat(decrypted_word, "D");
                    decode = 0;
                    break;
                case 345:
                    strcat(decrypted_word, "E");
                    decode = 0;
                    break;
                case 355:
                    strcat(decrypted_word, "F");
                    decode = 0;
                    break;
                case 365:
                    strcat(decrypted_word, "G");
                    decode = 0;
                    break;
                case 375:
                    strcat(decrypted_word, "H");
                    decode = 0;
                    break;
                case 385:
                    strcat(decrypted_word, "I");
                    decode = 0;
                    break;
                case 395:
                    strcat(decrypted_word, "J");
                    decode = 0;
                    break;
                case 405:
                    strcat(decrypted_word, "K");
                    decode = 0;
                    break;
                case 415:
                    strcat(decrypted_word, "L");
                    decode = 0;
                    break;
                case 425:
                    strcat(decrypted_word, "M");
                    decode = 0;
                    break;
                case 435:
                    strcat(decrypted_word, "N");
                    decode = 0;
                    break;
                case 445:
                    strcat(decrypted_word, "O");
                    decode = 0;
                    break;
                case 455:
                    strcat(decrypted_word, "P");
                    decode = 0;
                    break;
                case 465:
                    strcat(decrypted_word, "Q");
                    decode = 0;
                    break;
                case 475:
                    strcat(decrypted_word, "R");
                    decode = 0;
                    break;
                case 485:
                    strcat(decrypted_word, "S");
                    decode = 0;
                    break;
                case 495:
                    strcat(decrypted_word, "T");
                    decode = 0;
                    break;
                case 505:
                    strcat(decrypted_word, "U");
                    decode = 0;
                    break;
                case 515:
                    strcat(decrypted_word, "V");
                    decode = 0;
                    break;
                case 525:
                    strcat(decrypted_word, "W");
                    decode = 0;
                    break;
                case 535:
                    strcat(decrypted_word, "X");
                    decode = 0;
                    break;
                case 545:
                    strcat(decrypted_word, "Y");
                    decode = 0;
                    break;
                case 555:
                    strcat(decrypted_word, "Z");
                    decode = 0;
                    break;
                default:
                    break;
                }
            }
        }

    }
    strcpy(pointer_text_to_cryptographie, pointer_decrypted_word);

        return text_to_cryptographie;
}


#pragma endregion functions


int main(int argc, char *argv[])
{   

char text_to_cryptographie[text_length] = "";
char crypted_word[text_length] = "";
char *pointer_crypted_word = crypted_word;

char crypted_word_copie[text_length] = "";
char *pointer_crypted_word_copie = crypted_word_copie; 


char decrypted_word[text_length] = "";
char *pointer_decrypted_word = decrypted_word;


printf("Enter your text for cryptographie \n");

read(text_to_cryptographie, text_length);//read the output of the user



strcat(pointer_crypted_word, cryptographie(text_to_cryptographie));//cryptographie of the text

strcat(pointer_crypted_word_copie, pointer_crypted_word);//make a copie of crypted_word 

strcat(pointer_decrypted_word, decryptographie(crypted_word_copie));//put decrypted word in char decrypted_word



printf("crypted word is : %s\n", crypted_word);


printf("decrypted word is : %s\n", decrypted_word);

}

