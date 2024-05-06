#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int front = -1;
int rear = -1;
int queue[MAX];

void enqueue(int queue[], int val){
    if(front == -1 && rear == -1){
        front++;
        rear++;
        queue[rear] = val;
    }
    else if(rear == MAX -1){
        printf("Queue Overflow\n");
    }
    else{
        rear++;
        queue[rear] = val;
    }
}

void dequeue(int queue[]){
    if(front == -1 && rear == -1){
        printf("Queue Underflow\n");
    }
    else if(front == rear){
        printf("Deleted Element is : %d\n",queue[front]);
        front = -1;
        rear = -1;
    }
    else{
        printf("Deleted Element is : %d\n",queue[front]);
        front++;
    }
}

void peek(int queue[]){
    if(front == -1 || rear == -1){
        printf("Queue is empty\n");
    }
    else{
        printf("Top Element is : %d\n",queue[front]);
    }
}

void display(int queue[]){
    int temp = front;
    if(front == -1 || rear == -1){
        printf("Queue is empty\n");
    }
    else{
        while(temp!=rear){
            printf("%d | ",queue[temp]);
            temp++;
        }
        printf("%d\n",queue[rear]);
    }
}

int main(){
    int choice,val;
    do{
        printf("1.Enqueue | 2.Dequeue | 3.Peek | 4.Display | 5.Exit : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter data to enqueue : ");
                scanf("%d",&val);
                enqueue(queue,val);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                peek(queue);
                break;
            case 4:
                display(queue);
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