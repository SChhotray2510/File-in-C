/**
 * Read a paragraph from a text file.
 * File shall be read using FILE *fp = fopen("","r");
 * 1. Write a function that converst all the text to uppercase
 * 2. Write a function that converts capitalizes the start of each word.
 * 3. Write a function that converst all the text to sentence case(Only first letter in a line is capitalized).
 */
#include <stdio.h>
#include <ctype.h>
int main()
{
    FILE *fp = fopen("text", "r");
    FILE *allup = fopen("AllUpText", "w");
    FILE *firstLetter = fopen("firstLetterCapText", "w");
    FILE *sentence = fopen("sentencecase", "w");
    char string[1000];
    char ch;
    int i = 0;
    do
    {
        ch = fgetc(fp);
        string[i++] = ch;
    } while (ch != EOF);
    printf("The original string is: %s\n", string);
    char allupstring[1000];
    for (int i = 0; i < sizeof(string); i++)
    {
        allupstring[i] = toupper(string[i]);
    }
    fputs(allupstring, allup);
    printf("String with all uppercase is: %s\n", allupstring);

    char cap[1000];
    for (int i = 0; i < sizeof(string); i++)
    {
        if (i == 0)
        {
            cap[i] = toupper(string[i]);
            continue;
        }

        if (string[i - 1] == ' ' || string[i - 1] == '\n')
        {
            cap[i] = toupper(string[i]);
        }
        else
        {
            cap[i] = string[i];
        }
    }
    fputs(cap, firstLetter);
    printf("String with all first letters of words capitalized: %s\n", cap);

    char sentenceCase[1000];
    for (int i = 0; i < sizeof(string); i++)
    {
        if (i == 0 || string[i - 2] == '.' || string[i - 1] == '\n')
        {
            sentenceCase[i] = toupper(string[i]);
        }
        else
        {
            sentenceCase[i] = (string[i]);
        }
    }
    fputs(sentenceCase, sentence);
    printf("String with sentence cased: %s\n", sentenceCase);
}