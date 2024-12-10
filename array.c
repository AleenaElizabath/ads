#include <stdio.h>
void main(){
    int i,j,len1,len2,len3;
    printf("Enter the length of 1st array:");
    scanf("%d",&len1);
    printf("Enter the length of 2nd array:");
    scanf("%d",&len2);
    len3=len1+len2;
    int arr1[len1],arr2[len2],arr3[len3];
    printf("Enter the elements of array 1:");
    for ( i = 0; i < len1; i++)
    {
        scanf("%d",&arr1[i]);
    }
    printf("Enter the elements of array 2:");
    for ( i = 0; i < len2; i++)
    {
        scanf("%d",&arr2[i]);
    }
    printf("1st Array:\n");
    for ( i = 0; i < len1; i++)
    {
        printf("%d, ",arr1[i]);
    }
    printf("\n2nd Array:\n");
    for ( i = 0; i < len2; i++)
    {
        printf("%d, ",arr2[i]);
    }
    for ( i = 0; i < len1; i++)
    {
        arr3[i]=arr1[i];
    }
    for ( i =0; i < len2; i++)
    {
        arr3[i + len1]=arr2[i];
    }
    printf("\nCombined Array:\n");
    for ( i = 0; i < len3; i++)
    {
        printf("%d, ",arr3[i]);
    }
}