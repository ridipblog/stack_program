#include<stdio.h>
#include<stdlib.h>
int stack[10];
int top=-1;
void push(int val)
{
    stack[++top]=val;
}
int pop()
{
    int val=stack[top];
    top--;
    return val;
}
int main()
{
    int arr[10],n,val;
    printf("\nEnter Number Of Element ");
    scanf("%d",&n);
    printf("\nEnter Elements ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        push(arr[i]);
        printf("\n%d",stack[i]);
    }
    for(int i=0;i<n;i++)
    {
        val=pop();
        arr[i]=val;
    }
    for(int i=0;i<n;i++)
        printf("\n%d",arr[i]);
}
