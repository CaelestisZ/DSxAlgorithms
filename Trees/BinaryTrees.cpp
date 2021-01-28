#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
    int data;
    struct Node *lchild;
    struct Node *rchild;
};

class Tree
{
public:
    Node *root;
    Tree()
    {
        root = NULL;
    }
    void createTree();
    void preorder(Node *p);
    void inorder(Node *p);
    void postorder(Node *p);
};

void Tree::createTree()
{
    struct Node *p, *t;
    queue<Node *> q;

    root = new Node;

    cout << "Enter the root node: ";
    cin >> root->data;
    root->lchild = NULL;
    root->rchild = NULL;
    q.emplace(root);

    while (!q.empty())
    {
        p = q.front();
        q.pop();
        int x;

        cout << "Enter the left child of " << p->data << ": ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.emplace(t);
        }

        cout << "Enter the right child of " << p->data << ": ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.emplace(t);
        }
    }
    q.clear();
}

void Tree::preorder(Node *p)
{
    if (p)
    {
        cout << p->data + " ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void Tree::inorder(Node *p)
{
    if (p)
    {
        inorder(p->lchild);
        cout << p->data + " ";
        inorder(p->rchild);
    }
}

void Tree::postorder(Node *p)
{
    if (p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        cout << p->data + " ";
    }
}

int main()
{
    Tree t;
    t.createTree();
    t.preorder(t.root);
    t.inorder(t.root);
    t.postorder(t.root);
    return 0;
}