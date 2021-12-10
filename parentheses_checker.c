#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int stack[MAX],top=-1;
void main()
{
    char exp[MAX];
    char temp;
    int flag=1,i=0;
    printf("\nEnter Expression ");
    gets(exp);
    while(exp[i]!='\0')
    {
        if(exp[i]=='(' || exp[i]=='{')
        {
            push(exp[i]);
        }
        if(exp[i]==')' || exp[i]=='}')
        {
            if(top==-1)
            {
                flag=0;
                break;
            }
            else
            {
                temp=stack[top];
                top--;
                if(exp[i]==')'&&temp=='{')
                    flag=0;
                if(exp[i]=='}'&&temp=='(')
                    flag=0;
            }
        }
        i++;
    }
    if(top>=0)
        flag=0;
    if(flag==0)
        printf("\nExpression Not Valid");
    else
        printf("\nExpression Valid");
}
void push(char c)
{
    top++;
    stack[top]=c;
}
