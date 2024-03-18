#include<stdio.h>
#include<stdlib.h>

int main(){
    int arr[100];
    int i,j,n,temp;
    printf("Enter no. of elements : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter Element %d : ",i+1);
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    printf("Sorted array is : \n");
    for(i=0;i<n;i++){
        printf(" %d ",arr[i]);
    }
    return 0;
}