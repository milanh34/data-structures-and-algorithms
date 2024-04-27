#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int top = -1;
int stack[MAX];

void push(int stack[], int val){
    if(top == -1){
        top++;
        stack[top] = val;
    }
    else if(top == MAX -1){
        printf("Stack Overflow\n");
    }
    else{
        top++;
        stack[top] = val;
    }
}

void pop(int stack[]){
    if(top == -1){
        printf("Stack Underflow\n");
    }
    else{
        printf("Deleted Element is : %d\n",stack[top]);
        top--;
    }
}

void peek(int stack[]){
    if(top == -1){
        printf("stack is empty\n");
    }
    else{
        printf("Top Element is : %d\n",stack[top]);
    }
}

void display(int stack[]){
    int temp = top;
    if(temp == -1){
        printf("Stack is empty\n");
    }
    else{
        while(temp!=0){
            printf("%d\n",stack[temp]);
            temp--;
        }
        printf("%d\n",stack[0]);
    }
}

int main(){
    int choice,val;
    do{
        printf("1.Push | 2.Pop | 3.Peek | 4.Display | 5.Exit : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter data to push : ");
                scanf("%d",&val);
                push(stack,val);
                break;
            case 2:
                pop(stack);
                break;
            case 3:
                peek(stack);
                break;
            case 4:
                display(stack);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Input. Try again!\n");
                break;
        }
    }while(choice!=5);
    return 0;
}