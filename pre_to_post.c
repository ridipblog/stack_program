#include<stdio.h>
#include<stdlib.h>
char stack[25],postfix[25];
int top=-1,topOut=-1;
int getPri(char);
char getChar();
void main()
{
    int i=0,pri;
    char infix[25];
    printf("\nEnter Infix Expression ");
    scanf("%s",infix);
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
                        printf("\n%c ",getChar());
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
    //printf("\n%s",stack);
    if(top!=-1)
    {
        while(top!=-1)
        {
            pushOut(stack[top]);
            pop();
        }
    }
    postfix[++topOut]='\0';
    printf("\n%s",postfix);
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
