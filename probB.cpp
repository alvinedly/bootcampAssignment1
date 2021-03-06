#include <stdio.h>
#include <stdlib.h>

struct Node{
    int num;
    Node *next;
}*head=NULL, *tail=NULL;

Node *createNode(int num){
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->num=num;
    newNode->next=NULL;
    return newNode;
}

void pushTail(int num){
    Node *temp=createNode(num);
    if(!head){
        head=tail=temp;
    } else {
        tail->next=temp;
        tail=temp;
    }
}

int detectCycle(){
    Node *slow=head, *fast=head;
    while(slow && fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast){
            return 1;
        }
    }
    return 0;
}

int main(){
    pushTail(1);
    pushTail(3);
    pushTail(5);
    pushTail(7);
    pushTail(9);
    
    head->next->next->next->next->next=head;
    
    detectCycle();

    if(detectCycle()){
        puts("Terdapat cycle");
    } else {
        puts("Tidak ada cycle");
    }
    return 0;
}
