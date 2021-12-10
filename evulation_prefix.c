#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX 100
float stack[MAX];
int top=-1;
void push(float val);
float pop();
float evaluatePrefix(char exp[]);
int main()
{
    float val;
    char exp[100];
    char rev1[100];
    printf("\nEnter Prefix Expression ");
    gets(exp);
    strrev(exp);
    val=evaluatePrefix(exp);
    printf("\nEvaluation Prefix result= %.2f ",val);
}
float evaluatePrefix(char exp[])
{
    int i=0;
    float op1,op2,value;
    while(exp[i]!='\0')
    {
        if(isdigit(exp[i]))
        {
            push((float)(exp[i]-'0'));
        }
        else
        {
            op2=pop();
            op1=pop();
            switch(exp[i])
            {
                case '+':
                    value=op2+op1;
                    break;
                case'-':
                    if(op2>=op1)
                    {
                        value=op2-op1;
                    }
                    else
                    {
                        value=op1-op2;
                    }
                    break;
                case '/':
                    if(op1>=op2)
                    {
                        value=op1/op2;
                    }
                    else
                    {
                        value=op2/op1;
                    }
                    break;
                case '*':
                    value=op2*op1;
                    break;
            }
            push(value);
        }
        i++;
    }
    return pop();
}
void push(float val)
{
    if(top==MAX-1)
    {
        printf("\nOverflow");
    }
    else
    {
        top++;
        stack[top]=val;
    }
}
float pop()
{
    float va=-1;
    if(top==-1)
    {
        printf("\nUnderflow");
    }
    else
    {
        va=stack[top];
        stack[top]=-1;
        top--;
    }
    return va;
}
