#include<iostream>
#include<stdio.h>

using namespace std;

struct node{
    int data;
    struct node* next;
};

struct queue{
    struct node* front;
    struct node* rear;
};

struct node *q;

void create_queue(struct queue *q){
    q->rear=nullptr;
    q->front=nullptr;
}

void queue_insert(struct queue *q, int val){
    struct node *ptr;
    ptr = (struct node*) malloc(sizeof(struct node));
    ptr->data = val;
    if(q->front==nullptr){
        q->front=ptr;
        q->rear=ptr;
        q->front->next=q->rear->next=nullptr;}
    else{
        q->rear->next=ptr;
        q->rear=ptr;
        q->rear->next=nullptr;
    }
}

void display(struct queue *q){
    if(q->front==nullptr)
        printf("\n===Empty queue===\n");
    else{
        printf("\nFront");
        struct node *ptr = q->front;
        while(ptr!=nullptr){
            printf("<=>%d",ptr->data);
            ptr = ptr->next;
        }
        printf("<=>Rear\n");
    }
}

void queue_delete_element(struct queue *q){
    if(q->front==nullptr)
        printf("Underflow! Deletion not possible\n");
    else{
        struct node *ptr = q->front;
        q->front=q->front->next;
        printf("Value deleted : %d\n",ptr->data);
        free(ptr);
    }
}

int main(){
    struct queue *q;
    int x;
    create_queue(q);
    while(true){
        printf("1. Display queue\n2. Insert element\n3. Delete\n4. Exit\nInput : ");
        cin>>x;
        if(x==1)
            display(q);
        else if(x==2){
            printf("\nEnter element: ");
            cin>>x;
            queue_insert(q,x);
        }
        else if(x==3)
            queue_delete_element(q);
        else if(x==4)
            exit(0);
    }

    return 0;
}
