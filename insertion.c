#include<stdio.h>
int main()
{
int a[25],i,n,m,o;
printf("Enter the size of the array :");
scanf("%d",&n);
printf("Enter the array elements :");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("Enter the element to be inserted: ");
scanf("%d",&m);
printf("Enter the location:");
scanf("%d",&o);
for(i=n-1;i>=o;i--)
{
a[i+1]=a[i];
a[m-1]=o;

printf("Resultant array is :\n");
for(i=0;i<=n;i++)
{
printf("%d",a[i]);
return 0;
}}
}








