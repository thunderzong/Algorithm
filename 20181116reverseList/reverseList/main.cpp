#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
struct LinkedList{
    int value;
    LinkedList *next;
};
struct DoubleLinkedList{
    int data;
    DoubleLinkedList *pre;
    DoubleLinkedList *next;

};
DoubleLinkedList *createDoubleLinkedList(int n){
    DoubleLinkedList *dl1=(DoubleLinkedList *)malloc(sizeof(DoubleLinkedList));
    dl1->pre=NULL;
    srand(time(0));
    dl1->data=rand()%100;
    DoubleLinkedList *dl3=(DoubleLinkedList *)malloc(sizeof(DoubleLinkedList));
    dl3->next=NULL;
    srand(time(0));
    dl3->data=rand()%100;
    for(int i=0;i<n-1;i++){
        DoubleLinkedList *dl2=(DoubleLinkedList *)malloc(sizeof(DoubleLinkedList));
        dl1->next=dl2;
        dl3->pre=dl2;
        dl2->pre=dl1;
        dl2->next=dl3;
        dl2->data=rand()%10;
        dl3=dl2;
    }
    return dl3;
}
DoubleLinkedList *reverseDoubleLinkedList(DoubleLinkedList *dl){
    DoubleLinkedList *dl1,*dl2,dl3;
    dl1=dl;
    dl=dl->next;
    dl1->next=NULL;
    while(dl!=NULL){
        dl2=dl->next;
        dl->next=dl1;
        dl->pre=dl2;
        dl1=dl;
        dl=dl2;
    }
    dl1->pre=NULL;
    return dl1;
}
LinkedList *createLinkedList(int n){
    LinkedList *a=(LinkedList *)malloc(sizeof(LinkedList));
    srand(time(0));
    a->next=NULL;
    a->value=rand()%100;
    for(int i=0;i<n-1;i++){
        LinkedList *b=(LinkedList *)malloc(sizeof(LinkedList));
        b->value=rand()%100;
        b->next=a;
        a=b;
    }
    return a;
}

LinkedList *Reverse(LinkedList *head){
    LinkedList *L1,*L2,*L3;
    L1=head;
    //cout<<"L1:"<<L1<<endl;
    L2=head->next;
    //cout<<"L2:"<<L2<<endl;
    L1->next=NULL;
    int i=0;
    while(L2!=NULL){
        L3=L2->next;
        L2->next=L1;
        //cout<<"L2->next:"<<L2->next<<endl;
        L1=L2;
        //cout<<"L1:"<<L1<<endl;
        L2=L3;
        //cout<<i++<<endl;
    }
    //cout<<"L1->next"<<(*L1).value<<endl;
    return L1;
}
void print_linklist(LinkedList *l){
    while(l!=NULL){
        cout<<l->value<<"\t";
        l=l->next;
    }
    cout<<endl;
}
void print_Doublelinklist(DoubleLinkedList *dl){
    while(dl!=NULL){
        cout<<dl->data<<"\t";
        dl=dl->next;
    }
    cout<<endl;
}
int main()
{
    LinkedList *l=createLinkedList(10);
    cout<<"=====SingleLinkedList================="<<endl;
    print_linklist(l);
    l=Reverse(l);
    cout<<"======================================"<<endl;
    print_linklist(l);
    cout<<"=====DoubleLinkedList================="<<endl;
    DoubleLinkedList *dl=createDoubleLinkedList(10);
    print_Doublelinklist(dl);
    cout<<"======================================"<<endl;
    dl=reverseDoubleLinkedList(dl);
    print_Doublelinklist(dl);
    cout<<"======================================"<<endl;
    //cout<<&node1<<endl;

    cout << "Hello world!" << endl;
    return 0;
}
