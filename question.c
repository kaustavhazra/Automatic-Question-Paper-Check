#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct student
    {

        int no,no1;
      char ans[7],ques[5],ques1[5];
    };

int main()
{
    struct student s1;
    FILE *fp,*fp1,*fp2;

    char ch,n,i;
    fp=fopen("questionpaper.txt","r");
    fp1=fopen("anspaper.txt","w+");
    if(fp==NULL)
    {
        printf("\nerror");
        return 1;
    }
while(!feof(fp))
    {
       ch=fgetc(fp);
static int count=0;
        printf("%c",ch);
        if(ch=='.')
        {
            printf("\nans:");
            scanf("%c",&n);
            fflush(stdin);
            count++;
            if(n=='a')
                {
            fprintf(fp1,"%d\t%c\n",count,n);
                }
                if(n=='b')
                {
            fprintf(fp1,"%d\t%c\n",count,n);
                }
                if(n=='c')
                {
            fprintf(fp1,"%d\t%c\n",count,n);
                }
                if(n=='d')
                {
                    printf("\n skip this question.");
                    printf("\nans:");
                    scanf("%c",&n);
                    fflush(stdin);
                    fprintf(fp1,"%d\tskip\n",count);
                }


        }

    }
rewind(fp1);
while(!feof(fp1))
    {
    int cnt=fscanf(fp1,"%d %s",&s1.no,s1.ans);
    if(cnt==-1)
        continue;
    printf("%d\t%s\n",s1.no,s1.ans);
    }



    fclose(fp);
    fclose(fp1);

     printf("\n\n\tif you want to change the answer then enter y:");
    scanf("%c",&i);
    fflush(stdin);

    if(i=='y')
        {
            fp=fopen("questionpaper.txt","r");
            fp2=fopen("anspaper1.txt","w+");

            while(!feof(fp))
            {
                ch=fgetc(fp);
                static int count=0;
                printf("%c",ch);
                if(ch=='.')
                {
                    printf("\nans:");
                    scanf("%c",&n);
                    fflush(stdin);
                    count++;
                    if(n=='a')
                        {
                            fprintf(fp2,"%d\t%c\n",count,n);
                        }
                    if(n=='b')
                        {
                            fprintf(fp2,"%d\t%c\n",count,n);
                        }
                    if(n=='c')
                        {
                            fprintf(fp2,"%d\t%c\n",count,n);
                        }
                    if(n=='d')
                        {
                            printf("\n skip this question.");
                            printf("\nans:");
                            scanf("%c",&n);
                            fflush(stdin);
                            fprintf(fp2,"%d\tskip\n",count);
                        }
                }
            }
            fclose(fp);
            fclose(fp2);
        }

    if(i=='y')
    {
        remove("anspaper.txt");
        rename("anspaper1.txt","anspaper.txt");
    }
if(i=='y'){
    fp=fopen("anspaper.txt","r");
    while(!feof(fp))
    {
    int cnt=fscanf(fp,"%d %s",&s1.no,s1.ans);
    if(cnt==-1)
        continue;
    printf("%d\t%s\n",s1.no,s1.ans);
    }
fclose(fp);
}




//FOR FINAL ANS
    fp=fopen("anssheet.txt","r");
    fp1=fopen("anspaper.txt","r");
    if(fp==NULL)
    {
        printf("\nerror");
        return 1;
    }
    printf("\n\n\n\tMARKS");
        printf("\n\n\nQuestion no\tYour ans\tOrginal ans");
    while(!feof(fp)&&!feof(fp1))
    {
       int cnt=fscanf(fp,"%d%s",&s1.no,s1.ques);
       if (cnt==-1)
        continue;

        int cnt1=fscanf(fp1,"%d%s",&s1.no1,s1.ques1);
       if (cnt1==-1)
        continue;

        if(s1.no==s1.no1)
            {
            if(strcmp(s1.ques,s1.ques1)==0)
            {

                printf("\n   [%d]\t\tcorrect\t\t  %s",s1.no,s1.ques);
            }
            if(strcmp(s1.ques,s1.ques1)!=0)
                {
                    printf("\n   [%d]\t\twrong.\t\t  %s",s1.no,s1.ques);
                }
            }

    }


    fclose(fp);
    fclose(fp1);
getch();
}

