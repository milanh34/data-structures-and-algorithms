#include<stdio.h>
#include<conio.h>
#define size 10

int largest(int arr[], int n){
    int i, max=arr[0];
    for(i=1;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}

void bucketsort(int arr[], int n){
    int bucket[size][size], bucket_count[size], i, j, k, remainder, large, pass, divisor=1, NOP=0;
    large=largest(arr,n);
    while(large>0){
        NOP++;
        large/=size;
    }
    for(pass=0;pass<NOP;pass++){
        for(i=0;i<size;i++){
            bucket_count[i]=0;
        }
        for(i=0;i<n;i++){
            remainder=(arr[i]/divisor)%size;
            bucket[remainder][bucket_count[remainder]] = arr[i];
            bucket_count[remainder]+=1;
        }
        i=0;
        for(k=0;k<size;k++){
            for(j=0;j<bucket_count[k];j++){
                arr[i] = bucket[k][j];
                i++;
            }
        }
        divisor*=size;
    }
}

int main(){
    int i,n,a[100];
    printf("Enter no. of elements : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter element %d : ", i+1);
        scanf("%d",&a[i]);
    }
    bucketsort(a,n);
    printf("Sorted array is\n");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}