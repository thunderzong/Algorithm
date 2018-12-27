#include <iostream>
#include <stack>
#include <cstdlib>
using namespace std;
struct Node {
    int value;
    Node *left;
    Node *right;
};
Node *createBinaryTree(){
    Node *node1=(Node *)malloc(sizeof(Node));
    Node *node2=(Node *)malloc(sizeof(Node));
    Node *node3=(Node *)malloc(sizeof(Node));
    Node *node4=(Node *)malloc(sizeof(Node));
    Node *node5=(Node *)malloc(sizeof(Node));
    Node *node6=(Node *)malloc(sizeof(Node));
    Node *node7=(Node *)malloc(sizeof(Node));

    node1->value=1;
    node2->value=2;
    node3->value=3;
    node4->value=4;
    node5->value=5;
    node6->value=6;
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
void preOrder(Node *head){
    cout<<"preorderTraverse:"<<endl;
    if(head!=NULL){
        Node *node1=NULL;
        stack<Node *>s;
        s.push(head);
        while(!s.empty()){
            node1=s.top();
            s.pop();
            cout<<node1->value<<"\t";
            if(node1->right!=NULL){
                s.push(node1->right);
            }
            if(node1->left!=NULL){
                s.push(node1->left);
            }
        }
    }
    cout<<endl;
}
void inorder(Node *head){
    cout<<"inorder:"<<endl;
    if(head!=NULL){
        stack<Node *>s;
        while(!s.empty() || head!=NULL){
            if(head!=NULL){//当前节点不空 节点压栈 节点向左
                s.push(head);
                head=head->left;
            }else{          //当前节点为空 从栈取出打印并弹出 节点向右
                head=s.top();
                s.pop();
                cout<<head->value<<"\t";
                head=head->right;
            }
        }
    }
    cout<<endl;
}
void postorder(Node *head){
    cout<<"postorder:"<<endl;
    if(head!=NULL){
        stack<Node *>s,s1;
        s.push(head);
        while(s.empty()!=true){//返回值为bool类型
            head=s.top();
            //cout<<head->value<<"\t";
            s.pop();
            s1.push(head);
            if(head->left!=NULL){
                s.push(head->left);
            }
            if(head->right!=NULL){
                s.push(head->right);
            }
        }
        while(s1.empty()!=true){
            Node *temp=s1.top();
            cout<<temp->value<<"\t";
            s1.pop();
        }
    }
    cout<<endl;
}
int main()
{
    Node *head=createBinaryTree();
    preOrder(head);
    inorder(head);
    postorder(head);
    cout << "Hello world!" << endl;
    return 0;
}
