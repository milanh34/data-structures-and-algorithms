#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int front = -1;
int rear = -1;
int queue[MAX];

void renqueue(int queue[], int val){
    if(front == -1 && rear == -1){
        front++;
        rear++;
        queue[rear] = val;
    }
    else if(front == (rear+1)%MAX){
        printf("Queue Overflow at rear end\n");
    }
    else{
        rear=(rear+1)%MAX;
        queue[rear] = val;
    }
}

void fenqueue(int queue[], int val){
    if(front == -1 && rear == -1){
        front++;
        rear++;
        queue[front] = val;
    }
    else if(front == (rear+1)%MAX){
        printf("Queue Overflow at front end\n");
    }
    else if(front==0){
        front = MAX -1;
        queue[front] = val;
    }
    else{
        front--;
        queue[front] = val;
    }
}

void fdequeue(int queue[]){
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
        front=(front+1)%MAX;
    }
}

void rdequeue(int queue[]){
    if(front == -1 && rear == -1){
        printf("Queue Underflow\n");
    }
    else if(front == rear){
        printf("Deleted Element is : %d\n",queue[rear]);
        front = -1;
        rear = -1;
    }
    else if(rear==0){
        printf("Deleted Element is : %d\n",queue[rear]);
        rear= MAX -1;
    }
    else{
        printf("Deleted Element is : %d\n",queue[rear]);
        rear--;
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
            temp=(temp+1)%MAX;
        }
        printf("%d\n",queue[rear]);
    }
}

int main(){
    int choice,val;
    do{
        printf("1.Rear Enqueue | 2.Front Enqueue | 3.Rear Dequeue | 4.Front Dequeue | 5.Peek | 6.Display | 7.Exit : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter data to enqueue : ");
                scanf("%d",&val);
                renqueue(queue,val);
                break;
            case 2:
                printf("Enter data to enqueue : ");
                scanf("%d",&val);
                fenqueue(queue,val);
                break;
            case 3:
                rdequeue(queue);
                break;
            case 4:
                fdequeue(queue);
                break;
            case 5:
                peek(queue);
                break;
            case 6:
                display(queue);
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Input. Try again!\n");
                break;
        }
    }while(choice!=7);
    return 0;
}