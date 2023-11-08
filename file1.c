#include <stdio.h>
#include <ctype.h>
int main(){

FILE *fp = fopen("C_up.txt", "r");
FILE *upcase= fopen("Upper.txt", "w");
char string[1000];
char ch;
int i=0;
do{
    ch = fgetc(fp);
    string[i++]=ch;   
}while(ch!=EOF);

char convert[1000];
    for (int i = 0; i < sizeof(string); i++)
    {
        convert[i] = toupper(string[i]);
    }
    fputs(convert, upcase);
    printf("String with all uppercase is: %s\n", upcase);
fclose(fp);
fclose(upcase);


}
