#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 100
#define S_NMAX 5
void ricerca(FILE *fp, char v[NMAX]);
void conta_Lettere(char v[NMAX], char z[NMAX], int r[NMAX]);
int main(){
    FILE *fp;
    char frs[NMAX];
    char frsOcc[NMAX];
    int frsC[NMAX]={1};
    fp=fopen("Input.txt", "r");
    if(fp!=NULL){
        ricerca(fp, frs);
        fclose(fp);
    }
    conta_Lettere(frs, frsOcc, frsC);
}
void ricerca(FILE *fp, char v[NMAX]){
    int i=0;
    int cS=0;
    do{
        fscanf(fp, "%c", &v[i]);
        v[i+1]='\0';
        if(v[i]=='\n')
            cS++;
        i++;
        if(v[i]==EOF)
            break;
      }while(cS<S_NMAX);
      printf("Le stringhe lette dal file sono %d e sono: \n%s\n",cS, v);
}
void conta_Lettere(char v[NMAX], char z[NMAX], int c[NMAX]){
    for(int i=0; i<strlen(v); i++){
        for(int j=1; j<strlen(v); j++)
        {
            if(v[i]==v[j])
            {
                c[i]++;
                z[i]=v[i];
            }
        }
    }
    for(int i=0; i<strlen(z); i++)
        printf("%c %d\t",z[i],c[i]);
        printf("%s",z);
}





