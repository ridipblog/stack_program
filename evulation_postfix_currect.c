#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX 10
char exp[MAX];
int stack[MAX],top=-1;
void push(int);
int pop();
int is_operator(char);
int postfix_eval(char);
void main()
{
    printf("Enter Your Postfix Expresion ");
    gets(exp);
    printf("Your Postfix Expresion %s \n",exp);
    printf("After Evulation %d ",eval());
}
int eval()
{
    int i=0;
    while(exp[i]!='\0')
    {
        if(isdigit(exp[i]))
        {
            push((int)(exp[i]-'0'));
        }
        else if(is_operator(exp[i]))
        {
            int r;
            r=postfix_eval(exp[i]);
            push(r);
        }
        i++;
    }
    return pop();
}
int postfix_eval(char op)
{
    int x,y;
    y=pop();
    x=pop();
    switch(op)
    {
        case '+':
            return x+y;
        case '-':
            return x-y;
        case '*':
            return x*y;
        case '/':
            return x/y;

    }
}
int is_operator(char c)
{
    return (c=='-'||c=='+'||c=='*'||c=='/');
}
void push(int c)
{
    top++;
    stack[top]=c;
}
int pop()
{
    return stack[top--];
}
