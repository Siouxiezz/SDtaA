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
    {
        matrix[i][i] = 0;
    }
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
                node -> vertex = j;
                node -> weight = matrix[i][j];
                node -> next = adjList[i];
                adjList[i] = node;
            }
        }
    }
}

void checkComplete()
{
    bool complete = true;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i != j && matrix[i][j] == NO_EDGE)
            {
                complete = false;
                break;
            }
        }
    }

    if(complete)
        cout << "Graph is complete." << endl;
    else
        cout << "Graph is not complete." << endl;
}


void showMatrix()
{
    cout << "Adjacency matrix: \n";

    for(int i = 0; i < n; i++)
    {
        cout << i + 1 << "    ";
    }
    cout << endl;

    for(int i = 0; i < n; i++)
    {
        cout << i + 1 << "  [ ";
        for(int j = 0; j < n; j++)
        {
            if(matrix[i][j] == NO_EDGE)
            {
                cout << " -   ";
            }else
            {
                cout << matrix[i][j] << "    ";
            }
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
        Graph* current = adjList[i];

        if(current == 0)
        {
            cout << "(no connections)";
        }
        while(current != 0)
        {
            cout << current -> vertex + 1 << "(" << current -> weight << ")";
            if(current -> next != 0) cout << " -> ";
            current = current -> next;
        }
        cout << endl;
    }
}

void countEdges()
{
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(matrix[i][j] != NO_EDGE)
            {
                count++;
            }
        }
    }

    cout << "Total edges: " << count << endl;
}

void equalNumberOfConnections()
{
    int connect[n];
    bool found = false;

    for(int i = 0; i < n; i++)
    {
        connect[i] = 0;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(matrix[i][j] != NO_EDGE && matrix[i][j] != 0)
            {
                connect[i]++;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(connect[i] == connect[j])
            {
                cout << "Vertices " << i + 1 << " and " << j + 1
                     << " have the same connections: " << connect[i] << endl;
                found = true;
            }
        }
    }

    if(!found)
    {
        cout << "There are no verticies with the same connections.\n";
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
                maxW = matrix[i][j];
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
    cout << "4. Count edges" << endl;
    cout << "5. Find verticies with the same connections" << endl;
    cout << "6. Find longest edge" << endl;
    cout << "7. Exit" << endl;
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

    while(command != 7)
    {
        cout << "Sellect an option: ";
        cin >> command;

        switch(command)
        {
            case 1: system("cls"); showMatrix(); cout << endl; waitforenter(); break;
            case 2: system("cls"); checkComplete(); cout << endl; waitforenter(); break;
            case 3: system("cls"); showAdjList(); cout << endl; waitforenter(); break;
            case 4: system("cls"); countEdges(); cout << endl; waitforenter(); break;
            case 5: system("cls"); equalNumberOfConnections(); cout << endl; waitforenter(); break;
            case 6: system("cls"); longestEdge(); cout << endl; waitforenter(); break;
            case 7: return 0;
            default: cout << "Enter correct operation!" << endl;
        }
    }

    return 0;
}