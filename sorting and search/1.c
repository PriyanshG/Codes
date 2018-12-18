#include<stdio.h>
#include<stdlib.h>>
int main()
{
    char ch;int c=0;
    FILE *fp=fopen("abc.txt","r");
    if(fp==NULL)
    {
        printf("CANNOT OPEN");
        exit(0);
    }
    while((ch=getc(fp))!=EOF)
    {if(ch=='\n')
      c++;

    }
    printf("%d",c);
    fclose(fp);

}
