#include <iostream>
#include <cstdlib>
using namespace std;
struct Node{
    int value;
    Node *left;
    Node *right;
};
//递归方式遍历
void preOrder(Node *head){
    if(head==NULL){
        return ;
    }
    cout<<(*head).value<<"\t";
    preOrder(head->left);
    preOrder(head->right);
}
void middleOrder(Node *head){
    if(head==NULL){
        return ;
    }
    middleOrder(head->left);
    cout<<head->value<<"\t";
    middleOrder(head->right);
}
void laterOrder(Node *head){
    if(head==NULL){
        return ;
    }
    laterOrder(head->left);
    laterOrder(head->right);
    cout<<head->value<<"\t";
}
Node *createBinaryTree(){
    Node *node1=(Node *)malloc(sizeof(Node));
    node1->value=1;
    Node *node2=(Node *)malloc(sizeof(Node));
    node2->value=2;
    Node *node3=(Node *)malloc(sizeof(Node));
    node3->value=3;
    Node *node4=(Node *)malloc(sizeof(Node));
    node4->value=4;
    Node *node5=(Node *)malloc(sizeof(Node));
    node5->value=5;
    Node *node6=(Node *)malloc(sizeof(Node));
    node6->value=6;
    Node *node7=(Node *)malloc(sizeof(Node));
    node7->value=7;
    node1->left=node2;
    node1->right=node3;
    node2->left=node4;
    node2->right=node5;
    node3->left=node6;
    node3->right=node7;
    node4->left=NULL;
    node4->right=NULL;
    node5->left=NULL;
    node5->right=NULL;
    node6->left=NULL;
    node6->right=NULL;
    node7->left=NULL;
    node7->right=NULL;

    return node1;
}
int main()
{
    Node *head=createBinaryTree();
    cout<<"先序遍历:";
    preOrder(head);
    cout<<endl;
    cout<<"中序遍历:";
    middleOrder(head);
    cout<<endl;
    cout<<"后序遍历:";
    laterOrder(head);
    cout<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
