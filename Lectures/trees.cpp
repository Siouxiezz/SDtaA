#include <iostream>
#include <string>
using namespace std;

struct Tree
{
    int m;
    Tree *left;
    Tree *right;
} *root = 0;

Tree* insert(Tree *root, int x)
{
    if (root == 0)
    {
        Tree *node = new Tree;
        node->m = x;
        node->left = 0;
        node->right = 0;
        return node;
    }

    if (x < root->m)
    {
        root->left = insert(root->left, x);
    }

     else if  (x > root->m) {
         root->right = insert(root->right, x);

    }


    return root;
}

void show(Tree *root)
{
    if (root != 0)
    {
        show(root->left); //спочатку ліве дерево виводить
        cout << root->m << " ";
        show(root->right); //заходить вправо
    }

}

Tree* search(Tree *root, int x)
{
    if (root == 0)
    {
        return 0;
    }

    if (root->m == x)
    {
        return root;
    }

    if (x < root->m)
    {
        return search(root->left, x);
    }
    else if (x > root->m)
    {
        return search(root->right, x);
    }
}

int main()
{
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 20);
    root = insert(root, 30);
    root = search(root, 30);
    cout << endl << root->m << " ";
    show(root);


    return 0;
}