#include<bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

node* getnewnode(int);

node* Insert(node* root, int data)
{
    if (root == NULL)
    {
        root = getnewnode(data);
    }
    else if (data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    else
        root->right = Insert(root->right, data);

    return root;
}

node* getnewnode(int data)
{
    node* newnode = new node;

    newnode->data = data;

    newnode->left = NULL;

    newnode->right = NULL;

    return newnode;
}

bool Search (node* root, int data)
{
    if (root == NULL)

        return false;

    else if (root->data == data)

        return true;

    else if (data < root->data)

        return Search (root->left, data);

    else

        return Search (root->right, data);
}


node* findmin(node* root)
{
    while (root->left) root = root->left;

    return root;
}

int findnumberofnodes(node* root)
{
    if (root == NULL) return 0;

    int leftnodes = findnumberofnodes(root->left);
    int rightnodes = findnumberofnodes(root->right);

    return (leftnodes + rightnodes)+1;
}

int findnumberofleaves(node* root)
{
    int leftleaves = 0, rightleaves = 0;

    if (root->left == NULL && root->right == NULL) return 1;
    else if (root->left == NULL && root->right != NULL)
    {
        rightleaves = findnumberofleaves(root->right);
    }
    else if (root->left != NULL && root->right == NULL)
    {
        leftleaves = findnumberofleaves(root->left);
    }
    else
    {
        leftleaves = findnumberofleaves(root->left);
        rightleaves = findnumberofleaves(root->right);
    }

    return (leftleaves + rightleaves);
}
void preorder(node* root)
{
    if (root == NULL) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

node* clone(node* root)
{
    if (root == NULL)
        return root;
    
    node* temp = new node();
    temp->data = root->data;

    temp->left = clone(root->left);
    temp->right = clone(root->right);

    return temp;
}

void inorder(node* root)
{
    if (root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(node* root)
{
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int findheight(node* root)
{
    if (root == NULL)
        return -1;

    int leftheight = findheight(root->left);
    int rightheight = findheight(root->right);

    return max(leftheight,rightheight)+1;
}


node* deletenode(node* root , int value)
{
    if (root == NULL)
        return root;

    else if (value > root->data)
    {
        root->right = deletenode(root->right, value);
    }
    else if(value < root->data)
    {
        root->left = deletenode(root->left, value);
    }
    else
    {
        //case 1 -> delete leaf node
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }

        //case 2 -> if only one child
        else if (root->left == NULL)
        {
            node* temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL)
        {
            node* temp = root;
            root = root->left;
            delete temp;
        }

        // if both children are present
        else
        {
            node* temp = findmin(root->right);
            root->data = temp->data;

            root->right = deletenode(root->right, temp->data);
        }
    }

    return root;
}

void levelorder(node* root)
{
    if (root == NULL) return;

    queue<node*> q;

    q.push(root);
    while(!q.empty())
    {
         node* temp = q.front();
         cout << temp->data<< " ";

         if (temp->left != NULL)
            q.push(temp->left);
         if (temp->right != NULL)
            q.push(temp->right);

         q.pop();
    }

    cout << endl;
    return;
}

void printgivenlevel(node*, int);
void printlevelorder(node* root)
{
    if (root == NULL) return;

    int height = findheight(root);

    for(int i= 0; i<=height; i++)
    {
        printgivenlevel(root,i);
    }
    cout << endl;
}

void printgivenlevel(node* root, int i)
{
    if (root == NULL) return;

    else if(i == 0) cout << root->data<< " ";

    else if (i > 0)
    {
        printgivenlevel(root->left, i-1);
        printgivenlevel(root->right, i-1);
    }
}

int main()
{
    node* root = NULL;

    root = Insert(root, 5);
    root = Insert(root, 3);
    root = Insert(root, 7);
    root = Insert(root, 2);
    root = Insert(root, 4);
    root = Insert(root, 6);
    root = Insert(root, 8);
    root = Insert(root, 1);
    root = Insert(root, 9);

    inorder(root); cout << endl;

    levelorder(root);


    return 0;
}
