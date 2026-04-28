#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Tree
{
    long long pinNumb;
    string name;
    int cost;
    Tree* left;
    Tree* right;
} *root = 0;

Tree* createTree(Tree* root, int pin, string n, int c)
{
    if(root == nullptr)
    {
        Tree* node = new Tree;
        node -> pinNumb = pin;
        node -> name = n;
        node -> cost = c;
        node -> left = 0;
        node -> right = 0;
        return node;
    }

    if(pin < root -> pinNumb)
    {
        root -> left = createTree(root -> left, pin, n, c);
    } else if(pin > root -> pinNumb)
    {
        root -> right = createTree(root -> right, pin, n, c);
    }

    return root;
}

Tree* buildTreeFromFile()
{
    ifstream outputFile("D:/AtaP/SDtaA/Labs/lab09/Device_information.txt");

    if(!outputFile.is_open())
    {
        cout << "Error! Failed to open the file\n";
        cin.ignore();
        cin.get();
        return 0;
    }

    Tree* root = nullptr;
    long long pin; 
    int c;
    string n;

    while(outputFile >> pin >> n >> c)
    {
        root = createTree(root, pin, n, c);
    }

    outputFile.close();
    return root;
}

void calculateSum(Tree* root, double& sum, int& count)
{
    if(root == nullptr) 
    {
        return;
    }

    sum += root -> cost;
    count++;

    calculateSum(root -> left,  sum, count);
    calculateSum(root -> right, sum, count);

}

double averageCost(Tree* root)
{
    double sum = 0;
    int count = 0;

    calculateSum(root, sum, count);

    if(count == 0)
    {
        cout << "Tree is empty! ";
        return 0.0;
    }

    return (double)sum / count;
}

void nodesPerLevel(Tree* root)
{
    if(root == nullptr)
    {
        cout << "Tree is empty!\n";
        return;
    }

    Tree* q[100];
    int front = 0;
    int back  = 0;

    q[back++] = root;
    int level = 1;

    while(front < back)
    {
        int nodesOnLevel = back - front;
        cout << "Level " << level << ": " << nodesOnLevel << " node(s)\n";

        for(int i = 0; i < nodesOnLevel; i++)
        {
            Tree* node = q[front++];

            if (node->left  != nullptr) q[back++] = node->left;
            if (node->right != nullptr) q[back++] = node->right;
        }

        level++;
    }
}

Tree* findNode(Tree* root, int pin)
{
    if(root == nullptr)    
    {
        return nullptr;
    }

    if(pin == root -> pinNumb) 
    {
        return root;
    }

    if(pin < root -> pinNumb)
    {
        return findNode(root -> left,  pin);
    }else
    {
        return findNode(root -> right, pin);
    }
}

void freeTree(Tree* root)
{
    if(root == nullptr) 
    {
        return;
    }

    freeTree(root -> left);
    freeTree(root -> right);

    delete root;
}

void showTree(Tree *root) 
{
    if(root != 0) 
    {
        showTree(root -> left);
        cout << "Pin numb of your device: " << root -> pinNumb << endl;
        cout << "Name: " << root -> name << endl;
        cout << "How much it costs: " << root -> cost << endl;
        cout << "=========================================\n";
        showTree(root -> right);
    }
    
}

int main()
{

    root = buildTreeFromFile();

    if(root == nullptr)
    {
        cout << "Failed to build the tree. Exiting.\n";
        cin.ignore();
        cin.get();
        return 1;
    }

    cout << "======================================\n";

    cout << "=== All devices (sorted by pin) ===\n";
    showTree(root);

    cout << "Average cost: " << averageCost(root) << "\n";

    cout << "=== Nodes per level ===\n";
    nodesPerLevel(root);


    freeTree(root);

    cin.ignore();
    cin.get();

    return 0;
}