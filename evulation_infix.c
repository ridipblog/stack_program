#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX 10
char exp[MAX];
char operator_stack[MAX];
int operand_stack[MAX],operator_top=-1,operand_top=-1;
int eval();
char pop_operator();
int is_operator(char);
int precedence(char);
void main()
{
    printf("\Enter A Infix Expresion : ");
    gets(exp);
    printf("your Expresion : %s\n",exp);
    printf("\nAfter Evuluate Expresion %d ",eval());
}
int infix_eval()
{
    int x,y;
    char op;
    y=pop_operand();
    x=pop_operand();
    op=pop_operator();
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
    return 0;
}
int eval()
{
    int i=0;
    while(exp[i]!='\0')
    {
        if(isdigit(exp[i]))
        {
            push_operand((int)(exp[i]-'0'));
        }
        else if(is_operator(exp[i]))
        {
            while(precedence(exp[i])<=precedence(operator_stack[operator_top]))
            {
                int r;
                r=infix_eval();
                push_operand(r);
            }
            push_operator(exp[i]);
        }
        i++;
    }
    while(operator_top!=-1)
    {
        int r=infix_eval();
        push_operand(r);
    }
    return pop_operand();
}
int is_operator(char c)
{
    return(c=='+'||c=='-'||c=='*'||c=='/'||c=='^');
}
int precedence(char c)
{
    switch(c)
    {
        case '+':
            return 1;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 2;
        case '^':
            return 3;
    }
}
void push_operator(char c)
{
    if(operator_top==MAX-1)
    {
        printf("\nOperator Stack Is Overflow");
    }
    else
    {
        operator_top++;
        operator_stack[operator_top]=c;
    }
}
void push_operand(int c)
{
    if(operand_top==MAX-1)
    {
        printf("\nOperand Stack Is Overlflow");
    }
    else
    {
        operand_top++;
        operand_stack[operand_top]=c;
    }
}
char pop_operator()
{
    return operator_stack[operator_top--];
}
int pop_operand()
{
    int value=operand_stack[operand_top];
    operand_top--;
    return value;
}
