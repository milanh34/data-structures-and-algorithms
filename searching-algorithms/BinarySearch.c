#include<stdio.h>
#include<stdlib.h>

int main(){
    int arr[100];
    int i,j,n,x,f=-1,beg,end,mid;
    printf("Enter no. of elements : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter Element %d : ",i+1);
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                x=arr[i];
                arr[i]=arr[j];
                arr[j]=x;
            }
        }
    }
    printf("Sorted array is : \n");
    for(i=0;i<n;i++){
        printf(" %d ",arr[i]);
    }
    printf("\nWhich number do you wish to search? ");
    scanf("%d",&x);
    beg=0;
    end=n-1;
    mid=(beg+end)/2;
    while(beg<=end){
        mid=(beg+end)/2;
        if(arr[mid]==x){
            f=1;
            break;
        }
        else if(x>arr[mid]){
            beg=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    if(f!=-1)
        printf("Element found");
    else
        printf("Element not found!");
    return 0;
}