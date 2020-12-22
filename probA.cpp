#include <stdio.h>
#include <stdlib.h>

struct Data1
{
    int angka1;
    Data1* next1;
}*head1 = NULL, *tail1 = NULL;

struct Data2
{
    int angka2;
    Data2* next;
}*head = NULL, *tail = NULL;

struct Data1* initialize(int angka)
{
    struct Data1* newData = (Data1*)malloc(sizeof(Data1));

    newData->angka1 = angka;
    newData->next1 = NULL;

    return newData;
}

struct Data2* createNode(int angka)
{
    struct Data2* newNode = (Data2*)malloc(sizeof(Data2));
    
    newNode->angka2 = angka;
    newNode->next = NULL;

    return newNode;
}

void pushHead(int angka)
{
    struct Data2* newNode = createNode(angka);

    if (!head ) head = tail = newNode;
    else 
    {
        newNode->next  = head;
        head =  newNode;
    }
}

void pushTail(int angka)
{
    struct Data2* newNode = createNode(angka);

    if (!head) head = tail = newNode;
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void pushMid(int angka)
{
    struct Data2* newNode = createNode(angka);
    if (!head) head = tail = newNode;
    else if (newNode->angka2 < head->angka2) pushHead(angka);
    else if (newNode->angka2 > tail->angka2 ) pushTail(angka);
    else
    {
        struct Data2 *curr = head;
        while (curr)
        {
            if (newNode->angka2 < curr->next->angka2) break;
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }   
}

void pushTail1(int angka)
{
    struct Data1* newData = initialize(angka);
    if (!head1) head1 = tail1 = newData;
    else
    {
        tail1->next1 = newData;
        tail1 = newData;
    }
}

void print()
{
    struct Data2* curr = head;
    while (curr)
    {
        printf("%d ", curr->angka2);
        curr = curr->next;
    }
    puts("");
}

void print2()
{
    struct Data1* curr = head1;
    while (curr)
    {
        printf("%d ", curr->angka1);
        curr = curr->next1;
    }
    puts("");
}

void popHead()
{
    if (!head1) return;
    else 
    {
        struct Data1* curr = head1;
        head1 = head1->next1;
        free(curr);
        curr = NULL;
    }
}

void merge()
{
    struct Data1* curr = head1;
    while(curr)
    {
        pushMid(curr->angka1);
        curr=  curr->next1;
        popHead();
    }
}

int main()
{
    pushTail1(10);
    pushTail1(100);
    pushTail1(1000);
    print2();
    pushTail(9);
    pushTail(99);
    pushTail(999);
    print();
    merge();
    print();


    return 0;
}
