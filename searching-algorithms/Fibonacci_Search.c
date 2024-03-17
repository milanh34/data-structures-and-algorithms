#include<stdio.h>
int min(int x, int b) {
    if (x > b)
        return b;
    else
        return x;
}
int main() {
    int i, n, j, temp, A[100], b, a, c, offset = 0, key;
    printf("///Fibonacci Search\n");
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter element %d : ", i + 1);
        scanf("%d", &A[i]);
    }
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(A[j]<A[i]){
                temp=A[i];
                A[i]=A[j];
                A[j]=temp;
            }
        }
    }
    printf("Sorted Array is : ");
    for(i=0;i<n;i++){
        printf(" %d ",A[i]);
    }
    printf("\nEnter the element to be found : ");
    scanf("%d", &key);
    b = 1;
    a = 0;
    c = b + a;
    while (c < n) {
        a = b;
        b = c;
        c = b + a;
    }
    while (b > 1) {
        i = min(offset + a, n);
        if (A[i] < key) {
            c = b;
            b = a;
            a = c - b;
            offset = i;
        } else if (A[i] > key) {
            c = a;
            b = b - c;
            a = c - b;
        } else {
            printf("Value is at position %d", i+1);
            return 0;
        }
    }
    printf("Element not found");
    return 0;
}
