#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 10

void rStr(char v[NMAX]);
int main()
{

    char frs[NMAX];
    rStr(frs);
    int len=strlen(frs);
    fflush(stdout);
}
void rStr(char v[NMAX])
{
    FILE *fp;
    fp=fopen("Input.txt", "r");
    int i=0;
    int strn=0;
    do
    {

        if(v[i]!='\n')
        {
            v[i]=getc(fp);
            printf("%c",v[i]);
        }

         if(v[i]=='\n')
        {
            printf("n STRINGHE %d \n",strn);
            strn++;
        }

        i++;
    }while(v[i]!=EOF);
}
