#include<stdio.h>
int main()
{
int a[5],i,n,f,c=0;
printf("Enter the size of the array: ");
scanf("%d",&n);
printf("enter the array elements : ");

for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("Enter the elements to search:");
scanf("%d",&f);
for(i=0;i<n;i++)
{
if(a[i]==f)
{
c=1;
printf("Elment is found at %d",i);
}
}
if(!c)
{
printf("Element not found");
}
}





