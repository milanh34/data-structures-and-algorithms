#include<stdio.h>
#include<stdlib.h>
void sort(int a[],int n)
{
    int i,j,temp;
    for (i=1;i<n;i++)
    {
        temp=a[i];
        for (j=i-1;j>=0&&a[j]>temp;j--)
        {
            a[j+1]=a[j];
        }
        a[j+1]=temp;
    }
}
int main()
{
    int i,n,a[100];
    printf("Enter no. of elements : ");
    scanf("%d",&n);
    for ( i = 0; i < n; i++)
    {
        printf("Enter element %d : ", i+1);
        scanf("%d",&a[i]);
    }
    sort(a,n);
    printf("Sorted array is\n");
    for ( i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}