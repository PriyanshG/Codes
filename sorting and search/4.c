#include<stdio.h>
#include<stdlib.h>
int main()
{   int flag=0;
    char w[100],word[100];int nl,c=0;
    printf("Enter line number you wanna delete.");

    fflush(stdin);
    scanf("%d",&nl);
    FILE *fp=fopen("abc.txt","r");
    FILE *f=fopen("temp.txt","w");
    if(fp==NULL)
    {
        printf("CANNOT OPEN");
        exit(0);
    }
    if(f==NULL)
    {
        printf("CANNOT OPEN");
        exit(0);
    }
char ch;
    while((ch=getc(fp))!=EOF)
    {
        if(ch=='\n')
            c++;
    if(c!=(nl-1))
    {flag=1;
      fputc(ch,f);


    }
    }




    fclose(fp);
    fclose(f);
remove("abc.txt");
  rename("temp.txt","abc.txt");

}
