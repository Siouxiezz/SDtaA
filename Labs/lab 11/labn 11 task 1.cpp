#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int NO_EDGE = -1;

int n;
vector<vector<int>> matrix;

struct Graph
{
    int vertex;
    int weight;
    Graph* next;
};

vector<Graph*> adjList;

void initMatrix()
{
    matrix.assign(n, vector<int>(n, NO_EDGE));
    for(int i = 0; i < n; i++)
        matrix[i][i] = 0;
}

void addEdge(int u, int v, int w)
{
    matrix[u][v] = w;
    matrix[v][u] = w;
}

void buildAdjList()
{
    for(int i = 0; i < n; i++)
    {
        Graph* cur = adjList[i];
        while(cur != 0)
        {
            Graph* tmp = cur;
            cur = cur->next;
            delete tmp;
        }
        adjList[i] = 0;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = n - 1; j >= 0; j--)
        {
            if(matrix[i][j] != NO_EDGE && matrix[i][j] != 0)
            {
                Graph* node = new Graph;
                node->vertex = j;
                node->weight = matrix[i][j];
                node->next = adjList[i];
                adjList[i] = node;
            }
        }
    }
}

void checkComplete()
{
    bool complete = true;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(i != j && matrix[i][j] == NO_EDGE)
            {
                complete = false;
                break;
            }

    if(complete)
        cout << "Graph is complete." << endl;
    else
        cout << "Graph is not complete." << endl;
}


void showMatrix()
{
    cout << "Adjacency matrix:" << endl;
    cout << "     ";
    for(int i = 0; i < n; i++)
        cout << i + 1 << "    ";
    cout << endl;

    for(int i = 0; i < n; i++)
    {
        cout << i + 1 << "  [ ";
        for(int j = 0; j < n; j++)
        {
            if(matrix[i][j] == NO_EDGE)
                cout << " -   ";
            else
                cout << matrix[i][j] << "    ";
        }
        cout << "]" << endl;
    }
}

void showAdjList()
{
    cout << "Adjacency list:" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << i + 1 << " -> ";
        Graph* cur = adjList[i];
        if(cur == 0)
            cout << "(no connections)";
        while(cur != 0)
        {
            cout << cur->vertex + 1 << "(" << cur->weight << ")";
            if(cur->next != 0) cout << " -> ";
            cur = cur->next;
        }
        cout << endl;
    }
}

void longestEdge()
{
    int maxW = -1, u = -1, v = -1;

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(matrix[i][j] != NO_EDGE && matrix[i][j] > maxW)
            {
                matrix[i][j] = maxW;
                u = i;
                v = j;
            }
        }
    }

    if(u == -1)
    {
        cout << "No edges were found." << endl;
    }else
    {
        cout << "Longes edge: " << u + 1 << " - " << v + 1 << ", weight: " << maxW << endl;
    }
}

void menu()
{
    cout << "-------------------------------------" << endl;
    cout << "|               MENU                |" << endl;
    cout << "-------------------------------------" << endl;
    cout << "1. Adjacency matrix" << endl;  
    cout << "2. Check if graph is complete" << endl;
    cout << "3. Adjacency list" << endl;
    cout << "4. Find longest edge" << endl;
    cout << "5. Exit" << endl;
    cout << "-------------------------------------" << endl;
}

void waitforenter()
{
    cout << "Press Enter to return to menu... ";
    cin.ignore();
    cin.get();
    system("cls");
    menu();
}

int main()
{
    n = 6;

    initMatrix();

    adjList.assign(n, nullptr);

    addEdge(2, 0, 3);
    addEdge(2, 1, 6); 
    addEdge(2, 4, 2);
    addEdge(2, 3, 5);
    addEdge(3, 1, 1);
    addEdge(2, 5, 8);

    buildAdjList();

    menu();

    int command = 0;

    while(command != 5)
    {
        cout << "Sellect an option: ";
        cin >> command;

        switch(command)
        {
            case 1: system("cls"); showMatrix(); cout << endl; waitforenter(); break;
            case 2: system("cls"); checkComplete(); cout << endl; waitforenter(); break;
            case 3: system("cls"); showAdjList(); cout << endl; waitforenter(); break;
            case 4: system("cls"); longestEdge(); cout << endl; waitforenter(); break;
            case 5: return 0;
            default: cout << "Enter correct operation!" << endl;
        }
    }

    return 0;
}