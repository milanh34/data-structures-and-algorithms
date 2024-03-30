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

node *createlist(node *head){
    int n, i=0, val;
    node *temp, *temp1;
    temp=head;
    if(head!=NULL){
        printf("List already created\n");
        return head;
    }
    printf("Enter no. of nodes : ");
    scanf("%d",&n);
    while(i!=n){
        temp1=createnode();
        printf("Enter data for node %d : ",i+1);
        scanf("%d",&val);
        temp1->data = val;
        if(temp==NULL){
            head = temp1;
            temp = temp1;
        }
        else{
            temp->next = temp1;
            temp=temp->next;
        }
        i++;
    }
    return head;
}

node *insertbeg(node *head, int val){
    node *New;
    New=createnode();
    New->data=val;
    if(head==NULL){
        head=New;
        printf("Linked List was Empty. Created Now\n");
        return head;
    }
    else{
        New->next=head;
        head=New;
        return head;
    }
}

node *insertend(node *head, int val){
    node *New, *temp;
    temp=head;
    New=createnode();
    New->data=val;
    if(head==NULL){
        head=New;
        printf("Linked List was Empty. Created Now\n");
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

node *insertbefore(node *head, int val){
    node *New, *temp, *tempprev;
    int prev;
    temp=head;
    New=createnode();
    New->data=val;
    printf("Before which node do you wish to insert the node? ");
    scanf("%d",&prev);
    if(head==NULL){
        head=New;
        printf("Linked List was Empty. Created Now\n");
        return head;
    }
    else{
        tempprev=temp;
        if(temp->data == prev){
            New->next = head;
            head = New;
            return head;
        }
        while(temp->next!=NULL && temp->data!=prev){
            tempprev=temp;
            temp=temp->next;
        }
        if(temp->next == NULL && temp->data!=prev){
            temp->next=New;
            printf("Element not found. Inserted at the end\n");
        }
        else{
            tempprev->next = New;
            New->next = temp;
        }
        return head;
    }
}

node *insertafter(node *head, int val){
    node *New, *temp, *tempprev;
    int after;
    temp=head;
    New=createnode();
    New->data=val;
    printf("After which node do you wish to insert the node? ");
    scanf("%d",&after);
    if(head==NULL){
        head=New;
        printf("Linked List was Empty. Created Now\n");
        return head;
    }
    else{
        tempprev=temp;
        while(temp->next!=NULL && temp->data!=after){
            tempprev=temp;
            temp=temp->next;
        }
        if(temp->next == NULL && temp->data!=after){
            temp->next=New;
            printf("Element not found. Inserted at the end\n");
        }
        else{
            tempprev=temp->next;
            temp->next = New;
            New->next = tempprev;
        }
        return head;
    }
}

node *deletebeg(node *head){
    node *temp;
    temp=head;
    if(temp==NULL){
        printf("Linked List is Empty\n");
    }
    else{
        temp=head->next;
        free(head);
        head=temp;
    }
    return head;
}

node *deleteend(node *head){
    node *temp, *tempprev;
    temp=head;
    if(temp==NULL){
        printf("Linked List is Empty\n");
    }
    else{
        tempprev=temp;
        while(temp->next!=NULL){
            tempprev=temp;
            temp=temp->next;
        }
        tempprev->next = NULL;
        free(temp);
    }
    return head;
}

node *deletebefore(node *head, int val){
    node *temp, *tempprev, *temp1;
    temp=head;
    if(temp==NULL){
        printf("Linked List is Empty\n");
    }
    else{
        tempprev=temp;
        if(temp->data == val){
            printf("Nothing before this value\n");
            return head;
        }
        if(temp->next->data == val){
            head = head->next;
            free(temp);
            return head;
        }
        while(temp->next!=NULL && temp->data!=val){
            temp1 = tempprev;
            tempprev=temp;
            temp=temp->next;
        }
        if(temp->next == NULL && temp->data!=val){
            printf("Element not found. Nothing Deleted\n");
        }
        else{
            temp1->next = temp;
            free(tempprev);
        }
    }
    return head;
}

node *deleteafter(node *head, int val){
    node *temp, *tempprev;
    temp=head;
    if(temp==NULL){
        printf("Linked List is Empty\n");
    }
    else{
        tempprev=temp;
        if(temp->data == val){
            tempprev = temp;
            tempprev->next = temp->next->next;
            tempprev = temp->next;
            free(tempprev);
            return head;
        }
        while(temp->next!=NULL && temp->data!=val){
            tempprev=temp;
            temp=temp->next;
        }
        if(temp->next == NULL && temp->data!=val){
            printf("Element not found. Nothing Deleted\n");
        }
        else if(temp->next == NULL && temp->data==val){
            printf("Nothing after this value\n");
        }
        else{
            tempprev = temp->next;
            temp->next = tempprev->next;
            free(tempprev);
        }
    }
    return head;
}

void display(node *head){
    node *temp;
    temp=head;
    if(temp==NULL)
        printf("Linked List is Empty\n");
    else{
        while(temp!=NULL){
            printf("%d | ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

int main(){
    node *head=NULL;
    int choice,val;
    do{
        printf("1.CreateList | 2.InsertBeg | 3.InsertEnd | 4.InsertBefore | 5.InsertAfter | 6.DeleteBeg | 7.DeleteEnd | 8.DeleteBefore | 9.DeleteAfter | 10.Display | 11.Exit : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                head = createlist(head);
                break;
            case 2:
                printf("Enter data to insert : ");
                scanf("%d",&val);
                head = insertbeg(head, val);
                break;
            case 3:
                printf("Enter data to insert : ");
                scanf("%d",&val);
                head = insertend(head, val);
                break;
            case 4:
                printf("Enter data to insert : ");
                scanf("%d",&val);
                head = insertbefore(head, val);
                break;
            case 5:
                printf("Enter data to insert : ");
                scanf("%d",&val);
                head = insertafter(head, val);
                break;
            case 6:
                head = deletebeg(head);
                break;
            case 7:
                head = deleteend(head);
                break;
            case 8:
                printf("Before which value to delete data? ");
                scanf("%d",&val);
                head = deletebefore(head, val);
                break;
            case 9:
                printf("After which value to delete data? ");
                scanf("%d",&val);
                head = deleteafter(head, val);
                break;
            case 10:
                display(head);
                break;
            case 11:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Input. Try again!\n");
                break;
        }
    }while(choice!=11);
    return 0;
}