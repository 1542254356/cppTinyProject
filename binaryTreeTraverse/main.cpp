#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;
    Node(int v):val(v),left(NULL),right(NULL){}
};

void build(Node*& node)
{
    int val;
    cin>>val;
    if(val == -1)
    {
        node = NULL;
        return;
    }
    node = new Node(val);
    build(node->left);
    build(node->right);
}

void preOrder(Node* node)
{
    if(node != NULL)
    {
        cout<<node->val<<' ';

        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(Node* node)
{
    if(node != NULL)
    {
        inOrder(node->left);
        cout<<node->val<<' ';
        inOrder(node->right);
    }
}

void postOrder(Node* node)
{
    if(node != NULL)
    {
        postOrder(node->left);
        postOrder(node->right);
        cout<<node->val<<' ';
    }
}

void ZOrder(Node* node)
{
    queue<Node*> que;
    que.push(node);

    while(!que.empty())
    {
        Node* tNode = que.front();
        que.pop();
        if(tNode != NULL)
        {
            cout<<tNode->val<<' ';
            if(tNode->left != NULL)
            {
                que.push(tNode->left);
            }
            if(tNode->right != NULL)
            {
                que.push(tNode->right);
            }
        }
    }
}

// 1 2 1 2 -1 -1 3 -1 -1 -1 3 -1 -1

int main()
{
    cout<<"示例输入：  1 2 1 2 -1 -1 3 -1 -1 -1 3 -1 -1   "<<endl;

    Node* tree;
    build(tree);

    cout<<"前序遍历：";
    preOrder(tree);
    cout<<endl;

    cout<<"中序遍历：";
    inOrder(tree);
    cout<<endl;

    cout<<"后序遍历：";
    postOrder(tree);
    cout<<endl;

    cout<<"层序遍历：";
    ZOrder(tree);
    cout<<endl;

    return 0;
}
