#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 100
struct S{
    char Parola[NMAX];
    int pos;
    int len;
};
typedef struct S fData;
int findS(char v[NMAX], fData *DT);
int main()
{
    FILE *fp;
    fData DataPar[NMAX];
    char frs [NMAX];
    int contP;

    fp=fopen("Input.txt","r");
    if(fp!=NULL)
    {
        fgets(frs,NMAX,fp);
        printf("%s",frs);
        fclose(fp);
    }

    contP=findS(frs, DataPar);

    for(int i=0; i<contP; i++)
    {
        printf(" parola %s ",DataPar[i].Parola);
        printf(" pos %d ",DataPar[i].pos);
        printf("len %d \n ",DataPar[i].len);
    }







}
int findS(char v[NMAX], fData *DT){
    int len=0;
    int k=0;
    int y=0;
    for(int i=0; i<strlen(v); i++)
    {
        if(v[i]==' ' && v[i+1]!=' ')
            continue;
        len++;
        if(v[i]!=' ' && (v[i+1]==' ' || v[i+1]=='\0'))
        {
            DT[k].len=len;
            DT[k].pos=i-len+1;
            for(int j=(i-len); j<i; j++)
            {
                DT[k].Parola[y]=v[j+1];
                printf("sto mettendo nella struct: %c \n", v[j+1]);
                y++;
            }
            y=0;

            len=0;
            k++;
            printf("%d \n", k);
        }
    }
    return k;
}
