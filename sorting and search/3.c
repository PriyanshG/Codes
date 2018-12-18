#include<stdio.h>
#include<stdlib.h>
int main()
{   int flag=0;
    char w[100],word[100];int nl,c=0;
    printf("Enter desired line ");
    gets(word);
    printf("Enter number of line after which u wanna add line");
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
    {fputc(ch,f);
        if(ch=='\n')
            c++;
    if(c==nl && flag==0)
    {flag=1;
      fputs(word,f);
      fputs("\n",f);

    }
    }




    fclose(fp);
    fclose(f);
remove("abc.txt");
  rename("temp.txt","abc.txt");

}
