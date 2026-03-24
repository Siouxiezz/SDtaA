#include <iostream>
using namespace std;

struct stackMark
{
    int m;
    stackMark *next;
} *root = 0;

//Спробувати зробити push типом void
//Спробувати і інші функції зробити типом void, які можна використовувати для стеку


//na root + stackMark
stackMark* push (stackMark *root, int value)
{
    stackMark *c = new stackMark;
    c->m = value;
    c->next = root;
    root = c;
}

//dod v end
/*stackMark* addlast (stackMark *root, int value)
{
    stackMark *c1 = new stackMark;
    c1->m = value;
    c1->next = 0;
    last->next = c1;
    last = c1;
    if (root == 0)
        root = last;
    return root;
}*/

//dod v middle
/*stackMark* addMiddle(stackMark* root, int aftervalue, int value)
{
    stackMark *q = root;
    while (q != 0 && q->m != aftervalue)
    {
        q = q->next;
        if (q == 0)
        {
            cout << "No aftervalue";
            return root;
        }
    }
    stackMark *c = new stackMark;
    c->m = value;
    c -> next = q->next;
    q->next = c;
}*/

//delete root
stackMark* deleteroot (stackMark *root)
{
    stackMark *q;
    q = root; //q вказфіник. вивільняю обєкт куди вказує кю
    root = root->next;
    if (root == 0)
    {
        cout << "Nothing to delete";
    }
    delete q;
    return root;
}
//del last
stackMark* deletelast (stackMark *root)
{
    if (root == 0)
    {
        cout << "Nothing to delete";
        return 0;
    }
    stackMark *q = root;
}
void showStack (stackMark *root)
{
    stackMark *q = root;
    if (q == NULL)
    {
        cout << "The stack is empty" << endl;
        return;
    }

    while (q !=0)
    {
        cout << q -> m << " ";
        q = q -> next;
    }
    cout << endl;
}

int top(stackMark* root)
{
    return root->m;

}

int main ()
{
    showStack(root);
    root=push(root,90);

    cout << top(root);
} 
//
// Created by Настя Верстяк on 17.03.2026.
//