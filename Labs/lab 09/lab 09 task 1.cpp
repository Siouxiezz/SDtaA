#include <iostream>
#include <string>
#include <ctime>

using namespace std;

struct Tree
{
    int m;
    Tree* left;
    Tree* right;
} *root = 0;

Tree* insertManualy(Tree* root, int data)
{
    if(root == nullptr)
    {
        Tree* node = new Tree;
        node -> m = data;
        node -> left = 0;
        node -> right = 0;
        return node;
    }

    if(data < root -> m)
    {
        root -> left = insertManualy(root -> left, data);
    } else if(data > root -> m)
    {
        root -> right = insertManualy(root -> right, data);
    }

    return root;
}

Tree* insertAutomaticaly(Tree* root, int n, int a, int b)
{
    int data;

    if(a > b)
    {
        cout << "Error! a must be less than b." << endl;
        return root;
    }

    if(n <= (b - a + 1))
    {
        for(int i = 0; i < n; i++)
        {
            data = rand()%(b - a + 1) + a;
            root = insertManualy(root, data);
        }
    }else
    {
        cout << "Error! Your quantity of nodes are bigger than b - a.";
        return root;
    }

    return root;
}

void splitTree(Tree *root, Tree*& evenRoot, Tree*& oddRoot)
{
    if (root == nullptr)
    {
        return;
    }

    if(root -> m % 2 == 0)
    {
        evenRoot = insertManualy(evenRoot, root -> m);
    }
    else if(root -> m % 2 != 0)
    {
        oddRoot = insertManualy(oddRoot, root -> m);
    }

    splitTree(root->left, evenRoot, oddRoot);
    splitTree(root->right, evenRoot, oddRoot);
}

int treeDepth(Tree* root)
{
    int leftDepth = 0, rightDepth = 0;

    if(root == 0)
    {
        return 0;
    }

    leftDepth = treeDepth(root->left);
    rightDepth = treeDepth(root->right);

    if(leftDepth > rightDepth)
    {
        return leftDepth + 1;
    }else
    {
        return rightDepth + 1;
    }
}

void showTree(Tree *root) 
{
    if (root != 0) 
    {
        showTree(root -> left);
        cout << root -> m << " ";
        showTree(root -> right);
    }
    
}

void menu(){
	
	cout << "-------------------------------------" << endl;
	cout << "|               MENU                |" << endl;
	cout << "-------------------------------------" << endl;
	cout << "1. Insert Manually" << endl;
    cout << "2. Insert automatically" << endl;
    cout << "3. Show Tree" << endl;
    cout << "4. Split Tree" << endl;
    cout << "5. Show even tree" << endl;
    cout << "6. Show odd tree" << endl;
    cout << "7. Tree depth" << endl;
    cout << "8. Exit" << endl;
    cout << "-------------------------------------" << endl;
}

void waitforenter(){
    cout << "Press Enter to return to menu..." << endl;
    cin.ignore();
    cin.get();
    system("cls");
    menu();
}

int main()
{
    srand(time(nullptr));
    int n, data, command = 0, a = 0, b = 0;
    Tree* evenRoot = 0;
    Tree* oddRoot = 0;

    cout << "Enter n (1...19): ";
    cin >> n;
    system("cls");

    cout << "Enter a and b (only pos. numbers): ";
    cin >> a >> b;
    system("cls");
	menu();

    while(command!=8){
		
        cout << "Sellect an option: ";
        cin >> command;
		
        switch (command)
        {
            case 1: system("cls"); 
                for(int i = 0; i < n; i++) 
                {
                    cout << "Enter number " << i + 1 << " : "; 
                    cin >> data; 
                    root = insertManualy(root, data);
                }
                cout << endl;  waitforenter(); break;

            case 2: system("cls"); 
                root = insertAutomaticaly(root, n, a, b); 
                cout << endl;  waitforenter(); break;

            case 3: system("cls"); 
                showTree(root); 
                cout << endl;  waitforenter(); break;
            
            case 4: system("cls"); 
                splitTree(root, evenRoot, oddRoot); 
                cout << endl;  waitforenter(); break;

            case 5: system("cls"); 
                showTree(evenRoot); 
                cout << endl;  waitforenter(); break;

            case 6: system("cls"); 
                showTree(oddRoot); 
                cout << endl;  waitforenter(); break;

            case 7: system("cls"); 
                cout << "Tree depth: " << treeDepth(root);
                cout << endl;  waitforenter(); break;

            case 8:	return 0;
            default: cout << "Enter correct operation!" << endl;
        }
    }
	


    return 0;
}