#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}node;

node *createnode(){
    node *temp;
    temp = (node*)malloc(sizeof(node));
    temp->next = NULL;
    return temp;
}

node *insertend(node *head, int val){
    node *New, *temp;
    temp=head;
    New=createnode();
    New->data=val;
    if(head==NULL){
        head=New;
        return head;
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=New;
        return head;
    }
}

node *deletebeg(node *head){
    node *temp;
    temp=head;
    if(temp==NULL){
        printf("Queue is Empty\n");
    }
    else{
        temp=head->next;
        free(head);
        head=temp;
    }
    return head;
}

void peek(node *head){
    if(head==NULL)
        printf("Queue is Empty\n");
    else
        printf("%d\n",head->data);
}

void display(node *head){
    node *temp;
    temp=head;
    if(temp==NULL)
        printf("Queue is Empty\n");
    else{
        while(temp!=NULL){
            printf("%d\n",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

int main(){
    node *head=NULL;
    int choice,val;
    do{
        printf("1.Enqueue | 2.Dequeue | 3.Peek | 4.Display | 5.Exit : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter data to enqueue : ");
                scanf("%d",&val);
                head = insertend(head, val);
                break;
            case 2:
                head = deletebeg(head);
                break;
            case 3:
                peek(head);
                break;
            case 4:
                display(head);
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