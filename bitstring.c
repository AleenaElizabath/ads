#include<stdio.h>
#include<stdlib.h>

int u_size;

int universal(int v,int U[])
{
    for(int i=0;i<u_size;i++)
    {
        if(U[i]==v)
        {
            return 1;
        }
    }
    return 0;
}

int duplicate(int v,int A[], int pos)
{
    for(int i=0;i<=pos;i++)
    {
        if(v==A[i])
            return 0;
    }
    return 1;
}


void bitstring(int U[],int set[],int size,int c[])
{
    for(int i=0;i<u_size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(set[j]==U[i])
            {
                c[i]=1;
                break;
            }                
            else
                c[i]=0;
        }
    }
}

void union_set(int seta[],int setb[],int u[])
{
    for(int i=0;i<u_size;i++)
    {
        if(seta[i]==1 || setb[i]==1)
            u[i]=1;
        else
            u[i]=0;
    }
}

void intersect_set(int seta[],int setb[],int u[])
{
    for(int i=0;i<u_size;i++)
    {
        if(seta[i]==1 && setb[i]==1)
            u[i]=1;
        else
            u[i]=0;
    }
}

void set_difference(int seta[],int setb[],int u[])
{
    for(int i=0;i<u_size;i++)
    {
        if(seta[i]==1 && setb[i]==0)
            u[i]=1;
        else
            u[i]=0;
    }
}


void main() {
    
    printf("Enter size of universal set: ");
    scanf("%d", &u_size);
    int U[u_size],A_bit[u_size],B_bit[u_size],set_union[u_size],inter[u_size],diffa[u_size];
    printf("Enter universal set elements: ");
    for(int i=0;i<u_size;i++)
        scanf("%d",&U[i]);
    int sa,sb;
    printf("Enter size of set A: ");
    scanf("%d",&sa);
    if(sa>u_size)
        sa=u_size;
    int A[sa],v;
    printf("Enter elements of A: ");
    for(int i=0;i<sa;i++)
    {   printf("Enter element %d: ",i);
        scanf("%d",&v);
        if(universal(v,U)==1&&duplicate(v,A,i-1)==1)
        {
            A[i]=v;
        }
        else
        {
            printf("\ninvalid input\n");
            i--;
        }
    }
        
    printf("Enter size of set B: ");
    scanf("%d",&sb);
    if(sb>u_size)
        sb=u_size;
    int B[sb];
    printf("Enter elements of B: ");
    for(int i=0;i<sb;i++)
    {   printf("Enter element %d: ",i);
        scanf("%d",&v);
        if(universal(v,U)==1&&duplicate(v,B,i-1)==1)
        {
            B[i]=v;
        }
        else
        {
            printf("\ninvalid input\n");
            i--;
        }
    }
    bitstring(U,A,sa,A_bit);
    bitstring(U,B,sb,B_bit);
    printf("\nBit string A: ");
    for(int i=0;i<u_size;i++)
        printf("%d ",A_bit[i]);
    printf("\nBit string B: ");
    for(int i=0;i<u_size;i++)
        printf("%d ",B_bit[i]);
    union_set(A_bit,B_bit,set_union);
    intersect_set(A_bit,B_bit,inter);
    printf("\nUnion: ");
    for(int i=0;i<u_size;i++)
        printf("%d ",set_union[i]);
        printf("\nIntersection: ");
    for(int i=0;i<u_size;i++)
        printf("%d ",inter[i]);
    set_difference(A_bit,B_bit,diffa);
    printf("\n A-B: ");
    for(int i=0;i<u_size;i++)
        printf("%d ",diffa[i]);
}