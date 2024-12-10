#include <stdio.h>
void main()
{
    printf("ARRAY CREATION\n");
    int i,len1,ch;
    printf("Enter the length of array:");
    scanf("%d",&len1);
    int arr1[100];
    printf("Enter the elements of array:");
    for ( i = 0; i < len1; i++)
    {
        scanf("%d",&arr1[i]);
    }
    void display()
    {
        printf("Array:\n");
        for ( i = 0; i < len1; i++)
        {
            printf("%d, ",arr1[i]);
        }
    }
    void search()
    {
        int val,flag;
        printf("ENTER THE VALUE TO SEARCH:");
        scanf("%d",&val);
        for ( i = 0; i < len1; i++)
        {
            if(arr1[i]==val)
            {
                flag=1;
                break;
            }
        }
        if (flag==1)
        {
            printf("Element found at %d",i);
        }
        else{
            printf("Element not found");
        }
    }
    void insert()
    {
        int val,pos;
        printf("Enter the value to insert:");
        scanf("%d",&val);
        printf("Enter the position of the new value:");
        scanf("%d",&pos);
        if (pos>len1)
        {
            for ( i = 0; i < 100; i++)
            {
                if (i==pos)
                {
                    arr1[i]=val;
                }                
            }
            
        }
        else
        {
            for (i = 0; i <=len1; i++)
            {
                if (i==pos)
                {
                    arr1[i]=val;
                }
                
            }
            
        }
    }
    void delete()
    {
        int val;
        printf("Enter the value to be deleted");
        for(i=0;i<100;i++)
        {
            if (arr1[i]==val)
            {
                arr1[i]=arr[i+1];
            }
        }
    }
    void sort(){
        int i,k;
        for (i = 0; i <len1; i++)
        {
            if (arr1[i]>arr1[i+1])
            {
                k=arr1[i];
                arr1[i]=arr1[i+1];
                arr1[i+1]=k;
            }
        }
        printf("Array sorted");
    }
    while (ch!=6)
    {
        printf("\nArray operation:\n1.display\n2.search\n3.insert\n4.Delete\n5.Sort\n6.Exit\n");
        printf("Enter your choice(1/2/3/4/5/6):");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                display();
                break;
            case 2:
                search();
                break;
            case 3:
                insert();
                break;
            case 4:
                delete();
                break;
            case 5:
                sort();
                break;
            case 6:
                printf("Exit!!");
                break;
            default:
                printf("Invalid input");
                break;
        }
    }
}