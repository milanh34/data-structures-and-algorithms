#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int quick(int a[], int l, int u){
    int v,i,j,temp;
    v=a[l];
    i=l;
    j=u+1;
    do
    {
        do
        {
            i++;
        } while (a[i]<v&&i<=u);//check for smaller element than 1st element 
        do
        {
            j--;
        } while (v<a[j]);//check for biggest element than

        if (i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while (i<j);
    a[l]=a[j];
    a[j]=v;
    return j;
}

void divide(int a[], int l, int u){
    int k,j;
    if(l<u)
    {
        j=quick(a,l,u);
        divide(a,l,j-1);
        divide(a,j+1,u);
    }    
}
int main(){
    int a[100];
    int i,n,x;
    printf("Enter no. of elements : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter Element %d : ",i+1);
        scanf("%d",&a[i]);
    }
    divide(a,0,n-1);
    for(i=0;i<n;i++){
        printf("%d | ",a[i]);
    }
    return 0;
}