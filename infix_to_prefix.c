#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char stack[30],postfix[30];
int top=-1,topOut=-1;
int getPri(char);
char getChar();
void main()
{
    char str[30],infix[30];
    int len,j=0;
    printf("\nEnter Infix Expression ");
    scanf("%s",str);
    len=strlen(str);
    for(int a=len-1;a>=0;a--)
    {
        infix[j]=str[a];
        j++;
    }
    infix[len]='\0';
    int i=0,pri;
    while(infix[i]!='\0')
    {
        if(infix[i]=='*'||infix[i]=='/'||infix[i]=='+'||infix[i]=='-')
        {
            if(top==-1)
            {
                push(infix[i]);
            }
            else
            {
                if(getPri(infix[i])>getPri(getChar()))
                {
                    push(infix[i]);
                }
                else
                {
                    while(getPri(infix[i])<=getPri(getChar()))
                    {
                        pushOut(getChar());
                        pop();
                    }
                    push(infix[i]);
                }
            }
        }
        else
        {
            pushOut(infix[i]);
        }
        i++;
    }
    if(top!=-1)
    {
        while(top!=-1)
        {
            pushOut(stack[top]);
            pop();
        }
    }
    postfix[++topOut]='\0';
    char prefix[30];
    j=0;
    for(int a=len-1;a>=0;a--)
    {
        prefix[j]=postfix[a];
        j++;
    }
    prefix[len]='\0';
    printf("\nPrefix %s ",prefix);
}
void push(char c)
{
    top++;
    stack[top]=c;
}
void pushOut(char c)
{
    topOut++;
    postfix[topOut]=c;
}
int getPri(char c)
{
    if(c=='*'||c=='/')
    {
        return 2;
    }
    else if(c=='+'||c=='-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
    return -1;
}
char getChar()
{
    return stack[top];
}
void pop()
{
    stack[top]=NULL;
    top--;
}
