#include<stdio.h>
#include<stdlib.h>
#define MAX 100

void merge(int a[], int beg, int mid, int end){
    int c[MAX];
    int i,j,k;
    i=beg;
    j=mid+1;
    k=0;
    while(i<=mid && j<=end){
        if(a[i]<a[j]){
            c[k]=a[i];
            k++;
            i++;
        }
        else{
            c[k]=a[j];
            k++;
            j++;
        }
    }
    while(i<=mid){
        c[k]=a[i];
        k++;
        i++;
    }
    while(j<=end){
        c[k]=a[j];
        k++;
        j++;
    }
    for(i=beg,j=0;i<=end;i++,j++){
        a[i]=c[j];
    }
}

void divide(int a[],int i, int j)
{
    int k;
    if(i<j){
        k=(i+j)/2;
        divide(a,i,k);
        divide(a,k+1,j);
        merge(a,i,k,j);
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