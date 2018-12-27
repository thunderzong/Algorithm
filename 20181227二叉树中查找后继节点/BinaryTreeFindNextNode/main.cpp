#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;
    Node *parent;
    Node (int data)
    {
        this->value=data;
    }

};
Node *getLeftMost(Node *node);
Node *getSuccessorNode(Node *node)
{
    if(node==NULL)
    {
        return node;
    }
    if(node->right!=NULL)
    {
        return getLeftMost(node->right);
    }else
    {
        Node *parent=node->parent;
        while(parent!=NULL && parent->left !=node)
        {
            node = parent;
            parent=node->parent;
        }
        return parent;
    }
}

Node *getLeftMost(Node *node)
{
    if(node==NULL)
    {
        return node;
    }
    while(node->left!=NULL)
    {
        node=node->left;
    }
    return node;
}


int main()
{
    Node *head=new Node(6);
    head->parent=NULL;
    head->left=new Node(3);
    head->parent=head;
    head->left->left=new Node(1);
    head->left->left->parent=head->left;
    head->left->left->right=new Node(2);
    head->left->left->left=NULL;

    head->left->left->right->parent=head->left->left;
    head->left->left->right->left=NULL;
    head->left->left->right->right=NULL;


    head->left->right=new Node(4);
    head->left->right->parent = head->left;
    head->left->right->left=NULL;
    head->left->right->right = new Node(5);
    head->left->right->right->parent = head->left->right;
    head->left->right->right->left=NULL;
    head->left->right->right->right=NULL;

    head->right = new Node(9);
    head->right->parent = head;
    head->right->left = new Node(8);
    head->right->left->parent = head->right;
    head->right->left->left = new Node(7);
    head->right->left->left->parent = head->right->left;
    head->right->left->left->left=NULL;
    head->right->left->left->right=NULL;


    head->right->right = new Node(10);
    head->right->right->parent = head->right;
    head->right->right->left=NULL;
    head->right->right->right=NULL;


    Node *test=head->left->left;
    //cout<<test->value<<endl;
    //Node *result=getSuccessorNode(test);

    cout<<test->value<<"  next:  "<<getSuccessorNode(test)->value<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
