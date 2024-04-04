#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int coeff;
    int power;
    struct Node *next;
}node;

node *createnode(){
    node *temp;
    temp = (node*)malloc(sizeof(node));
    temp->next = NULL;
    return temp;
}

node *createpoly(node *head){
    int n, i=0, val1, val2;
    node *temp, *temp1;
    temp=head;
    printf("Enter no. of nodes : ");
    scanf("%d",&n);
    while(i!=n){
        temp1=createnode();
        printf("Enter power for node %d : ",i+1);
        scanf("%d",&val1);
        printf("Enter coefficient for node %d : ",i+1);
        scanf("%d",&val2);
        temp1->power = val1;
        temp1->coeff = val2;
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

node *addnode(node *add, int pow, int coef){
    node *temp, *temp1;
    temp = add;
    temp1 = createnode();
    temp1->power = pow;
    temp1->coeff = coef;
    if(temp == NULL){
        add = temp1;
    }
    else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = temp1;
    }
    return add;
}

node *addition(node *poly1, node *poly2){
    node *add = NULL, *poly2start, *poly1start, *addstart, *temp;
    int coef, found;
    poly2start = poly2;
    poly1start = poly1;
    while(poly1!=NULL){
        poly2 = poly2start;
        while(poly2!=NULL){
            if(poly1->power == poly2->power){
                coef = poly1->coeff + poly2->coeff;
                add = addnode(add, poly1->power,coef);
            }
            poly2=poly2->next;
        }
        poly1=poly1->next;
    }
    poly1=poly1start;
    addstart = add;
    while(poly1!=NULL){
        found = 0;
        add = addstart;
        temp = add;
        while(temp!=NULL){
            if(poly1->power == temp->power){
                found = 1;
            }
            temp = temp->next;
        }
        if(found != 1){
            add = addnode(add, poly1->power, poly1->coeff);
        }
        poly1=poly1->next;
    }
    poly2=poly2start;
    addstart = add;
    while(poly2!=NULL){
        found = 0;
        add = addstart;
        temp = add;
        while(temp!=NULL){
            if(poly2->power == temp->power){
                found = 1;
            }
            temp = temp->next;
        }
        if(found != 1){
            add = addnode(add, poly2->power, poly2->coeff);
        }
        poly2=poly2->next;
    }
    return add;
}

node *subtraction(node *poly1, node *poly2){
    node *sub = NULL, *poly2start, *poly1start, *substart, *temp;
    int coef, found;
    poly2start = poly2;
    poly1start = poly1;
    while(poly1!=NULL){
        poly2 = poly2start;
        while(poly2!=NULL){
            if(poly1->power == poly2->power){
                coef = poly1->coeff - poly2->coeff;
                sub = addnode(sub, poly1->power,coef);
            }
            poly2=poly2->next;
        }
        poly1=poly1->next;
    }
    poly1=poly1start;
    substart = sub;
    while(poly1!=NULL){
        found = 0;
        sub = substart;
        temp = sub;
        while(temp!=NULL){
            if(poly1->power == temp->power){
                found = 1;
            }
            temp = temp->next;
        }
        if(found != 1){
            sub = addnode(sub, poly1->power, poly1->coeff);
        }
        poly1=poly1->next;
    }
    poly2=poly2start;
    substart = sub;
    while(poly2!=NULL){
        found = 0;
        sub = substart;
        temp = sub;
        while(temp!=NULL){
            if(poly2->power == temp->power){
                found = 1;
            }
            temp = temp->next;
        }
        if(found != 1){
            sub = addnode(sub, poly2->power, poly2->coeff);
        }
        poly2=poly2->next;
    }
    return sub;
}

void display(node *head){
    node *temp;
    temp=head;
    if(temp==NULL)
        printf("No Polynomial\n");
    else{
        while(temp!=NULL){
            printf("%dx^%d + ",temp->coeff,temp->power);
            temp=temp->next;
        }
        printf("\n");
    }
}

int main(){
    node *poly1 = NULL;
    node *poly2 = NULL;
    node *add = NULL;
    node *sub = NULL;
    printf("For Polynomial 1, ");
    poly1 = createpoly(poly1);
    printf("\nFor Polynomial 2, ");
    poly2 = createpoly(poly2);
    printf("\nPolynomial 1 : ");
    display(poly1);
    printf("\nPolynomial 2 : ");
    display(poly2);
    printf("\nAddition : ");
    add = addition(poly1,poly2);
    display(add);
    printf("\nSubtraction : ");
    sub = subtraction(poly1,poly2);
    display(sub);
}