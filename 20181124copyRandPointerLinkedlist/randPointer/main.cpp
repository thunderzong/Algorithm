#include <iostream>
#include <cstdlib>
#include <map>
using namespace std;
struct Node{
    int value;
    Node *next;
    Node *rand;
};
Node *copyListRand(Node * head){
    map<Node *,Node *>m;
    Node * cur=head;
    while(cur!=NULL){
        Node *n=(Node *)malloc(sizeof(Node));
        n->value=cur->value;
        m.insert({cur,n});
        cur=cur->next;
    }
    cur=head;
    while(cur!=NULL){
        m[cur]->next=m[cur->next];
        m[cur]->rand=m[cur->rand];
        cur=cur->next;
    }
    return m[head];
}
void print_list(Node *n1){
    Node *head=n1;
    while(head!=NULL){
        cout<<head->value<<endl;
        head=head->next;
    }
}
int main()
{
    Node *n1=(Node *)malloc(sizeof(Node));

    Node *n2=(Node *)malloc(sizeof(Node));

    Node *n3=(Node *)malloc(sizeof(Node));

    n1->value=1;
    n1->next=n2;
    n1->rand=n3;

    n2->value=2;
    n2->next=n3;
    n2->rand=n1;

    n3->value=3;
    n3->next=NULL;
    n3->rand=n2;

    print_list(n1);
    cout<<"*********************"<<endl;
    Node *test=copyListRand(n1);
    print_list(test);
    cout << "!!!please enter a rand button!!!" << endl;
    return 0;
}
