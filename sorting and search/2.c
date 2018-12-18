#include<stdio.h>
#include<stdlib.h>
int main()
{
    char w[100],word[100];int c=0;
    printf("Enter desired word ");
    scanf("%s",word);

    FILE *fp=fopen("abc.txt","r");
    if(fp==NULL)
    {
        printf("CANNOT OPEN");
        exit(0);
    }
    while(fscanf(fp,"%s",w)!=EOF)
    {
        if(!strcmp(w,word))
            c++;
    }
    printf("\n Nummber of time \"%s\" is repeated %d.",word,c);
    fclose(fp);

}
