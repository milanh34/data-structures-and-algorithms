#include<stdio.h>
#include<stdlib.h>

int main(){
    int arr[100];
    int i,n,x,f=-1;
    printf("Enter no. of elements : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter Element %d : ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Which number do you wish to search? ");
    scanf("%d",&x);
    for(i=0;i<n;i++){
        if(arr[i]==x){
            f=i;
            break;
        }
    }
    if(f!=-1)
        printf("%d found at position %d",x,f+1);
    else
        printf("Element not found!");
    return 0;
}