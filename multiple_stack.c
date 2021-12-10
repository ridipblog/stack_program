#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stack[MAX],topa=-1,topb=MAX;
void pushA(int stack[])
{
    int val;
    while(1)
    {
        printf("\n0 for exit");
        printf("\nEnter Data");
        scanf("%d",&val);
        if(val==0)
        {
            break;
        }
        else
        {
            if(topa==topb-1)
            {
                printf("\nOverflow");
            }
            else
            {
                topa++;
                stack[topa]=val;
            }
        }
    }
}
void pushB(int stack[])
{
    int val;
    while(1)
    {
        printf("\n0 for exit");
        printf("\nEnter Data");
        scanf("%d",&val);
        if(val==0)
        {
            break;
        }
        else
        {
            if(topa==topb-1)
            {
                printf("\nOverflow");
            }
            else
            {
                topb--;
                stack[topb]=val;
            }
        }
    }
}
void popA(int stack[])
{
    if(topa==-1)
    {
        printf("\nUnserflow");
    }
    else
    {
        printf("\nRemove %d ",stack[topa]);
        stack[topa]=NULL;
        topa--;

    }
}
void popB(int stack[])
{
    if(popB==MAX)
    {
        printf("\nUnderflow");
    }
    else
    {
        printf("\nRemove %d ",stack[topb]);
        stack[topb]=NULL;
        topb++;
    }
}
void displayA(int stack[])
{
    if(topa==-1)
    {
        printf("\nUserflow");
    }
    else
    {
        for(int i=topa;i>=0;i--)
        {
            printf("\n%d ",stack[i]);
        }
    }
}
void displayB(int stack[])
{
    if(topb==MAX)
    {
        printf("\nUnserflow");
    }
    else
    {
        for(int i=topb;i<MAX;i++)
        {
            printf("\n%d ",stack[i]);
        }
    }
}
int main()
{
    int option;
    while(1)
    {
        printf("\nEnter Choose ");
        printf("\n1 for push A");
        printf("\n2 for push B");
        printf("\n3 for pop A");
        printf("\n4 for pop B");
        printf("\n5 for display A");
        printf("\n6 for display B");
        printf("\n0 for exit ");
        scanf("%d",&option);
        if(option==1)
        {
            pushA(stack);
        }
        else if(option==2)
        {
            pushB(stack);
        }
        else if(option==3)
        {
            popA(stack);
        }
        else if(option==4)
        {
            popB(stack);
        }
        else if(option==5)
        {
            displayA(stack);
        }
        else if(option==6)
        {
            displayB(stack);
        }
        else if(option==0)
        {
            break;
        }
    }
}
