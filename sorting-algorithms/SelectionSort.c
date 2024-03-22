#include<stdio.h>
#include<stdlib.h>

int smallest(int arr[], int k, int n){
    int i,pos=k,small=arr[k];
    for(i = k+1; i < n ; i++){
        if(arr[i]<arr[k]){
            small=arr[i];
            pos=i;
        }
    }
    return pos;
}

void selectionsort(int arr[], int n){
    int i,pos,temp;
    for(i=0;i<n;i++){
        pos=smallest(arr,i,n);
        temp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = temp;
    }
}

int main(){
    int arr[100];
    int i,n,x,f=-1;
    printf("Enter no. of elements : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter Element %d : ",i+1);
        scanf("%d",&arr[i]);
    }
    selectionsort(arr,n);
    for(i=0;i<n;i++){
        printf(" %d ",arr[i]);
    }
    return 0;
}