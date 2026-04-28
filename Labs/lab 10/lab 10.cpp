#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int NO_EDGE = -1;

int n;
vector<vector<int>> matrix;

struct ListNode
{
    int vertex;
    int weight;
    ListNode* next;
};

vector<ListNode*> adjList;

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
        ListNode* cur = adjList[i];
        while(cur != 0)
        {
            ListNode* tmp = cur;
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
                ListNode* node = new ListNode;
                node->vertex = j;
                node->weight = matrix[i][j];
                node->next = adjList[i];
                adjList[i] = node;
            }
        }
    }
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

void showAdjList()
{
    cout << "Adjacency list:" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << i + 1 << " -> ";
        ListNode* cur = adjList[i];
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

vector<vector<int>> floydWarshall()
{
    const int BIG = 10000000;

    vector<vector<int>> dist(n, vector<int>(n, BIG));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(matrix[i][j] != NO_EDGE)
                dist[i][j] = matrix[i][j];

    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(dist[i][k] != BIG && dist[k][j] != BIG)
                    if(dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(dist[i][j] == BIG)
                dist[i][j] = NO_EDGE;

    return dist;
}

void averagePathLength()
{
    vector<vector<int>> dist = floydWarshall();

    double sum = 0;
    int count = 0;

    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(dist[i][j] != NO_EDGE)
            {
                sum += dist[i][j];
                count++;
            }

    if(count == 0)
        cout << "No paths found." << endl;
    else
        cout << "Average path length: " << sum / count << endl;
}

void findIsolated()
{
    bool found = false;

    for(int i = 0; i < n; i++)
    {
        int connections = 0;
        int nearestVertex = -1;
        int nearestDist = -1;

        for(int j = 0; j < n; j++)
        {
            if(matrix[i][j] != NO_EDGE && matrix[i][j] != 0)
            {
                connections++;
                if(nearestDist == NO_EDGE || matrix[i][j] < nearestDist)
                {
                    nearestDist = matrix[i][j];
                    nearestVertex = j;
                }
            }
        }

        if(connections == 1)
        {
            found = true;
            cout << "Vertex " << i + 1 << " is isolated. "
                 << "Nearest vertex: " << nearestVertex + 1
                 << ", distance: " << nearestDist << endl;
        }
    }

    if(!found)
        cout << "No isolated vertices found." << endl;
}

void countIsolated()
{
    vector<int> isolated;

    for(int i = 0; i < n; i++)
    {
        int connections = 0;
        for(int j = 0; j < n; j++)
            if(matrix[i][j] != NO_EDGE && matrix[i][j] != 0)
                connections++;

        if(connections == 1)
            isolated.push_back(i + 1);
    }

    if(isolated.empty())
    {
        cout << "No isolated vertices found." << endl;
        return;
    }

    cout << "Isolated vertices: ";
    for(int i = 0; i < (int)isolated.size(); i++)
        cout << isolated[i] << (i < (int)isolated.size() - 1 ? ", " : "\n");

    cout << "Count: " << isolated.size() << endl;
}

void maxRouteThreeCities()
{
    vector<vector<int>> dist = floydWarshall();

    int maxDist = -1;
    int cityA = -1, cityB = -1, cityC = -1;
    int distAB = 0, distBC = 0;

    for(int a = 0; a < n; a++)
        for(int b = 0; b < n; b++)
            for(int c = 0; c < n; c++)
            {
                if(a == b || b == c || a == c) continue;
                if(dist[a][b] == NO_EDGE || dist[b][c] == NO_EDGE) continue;

                int total = dist[a][b] + dist[b][c];
                if(total > maxDist)
                {
                    maxDist = total;
                    cityA = a; cityB = b; cityC = c;
                    distAB = dist[a][b];
                    distBC = dist[b][c];
                }
            }

    if(cityA == -1)
        cout << "Route not found." << endl;
    else
        cout << "Route with max path: ("
             << cityA + 1 << ") --- " << distAB
             << " --- (" << cityB + 1 << ") --- " << distBC
             << " --- (" << cityC + 1 << ")" << endl;
}

vector<int> hamilPath;
vector<bool> visited;

bool hamiltonianDFS(int cur, int count)
{
    if(count == n)
        return true;

    for(int next = 0; next < n; next++)
    {
        if(!visited[next] && matrix[cur][next] != NO_EDGE && matrix[cur][next] != 0)
        {
            visited[next] = true;
            hamilPath[count] = next;
            if(hamiltonianDFS(next, count + 1))
                return true;
            visited[next] = false;
        }
    }
    return false;
}

void checkHamiltonian()
{
    hamilPath.assign(n, -1);
    visited.assign(n, false);

    for(int start = 0; start < n; start++)
    {
        fill(visited.begin(), visited.end(), false);
        visited[start] = true;
        hamilPath[0] = start;

        if(hamiltonianDFS(start, 1))
        {
            cout << "Hamiltonian path exists: ";
            for(int i = 0; i < n; i++)
                cout << hamilPath[i] + 1 << (i < n - 1 ? " -> " : "\n");
            return;
        }
    }
    cout << "Hamiltonian path does not exist." << endl;
}

void menu()
{
    cout << "-------------------------------------" << endl;
    cout << "|               MENU                |" << endl;
    cout << "-------------------------------------" << endl;
    cout << "1. Adjacency matrix" << endl;
    cout << "2. Check if graph is complete" << endl;
    cout << "3. Adjacency list" << endl;
    cout << "4. Average path length" << endl;
    cout << "5. Isolated vertices (with distance)" << endl;
    cout << "6. Count isolated vertices" << endl;
    cout << "7. Route through 3 cities (max path)" << endl;
    cout << "8. Hamiltonian path" << endl;
    cout << "9. Exit" << endl;
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

    addEdge(0, 1, 6); 
    addEdge(0, 2, 2); 
    addEdge(2, 3, 9); 
    addEdge(2, 4, 8); 
    addEdge(3, 4, 4); 
    addEdge(3, 5, 4); 

    buildAdjList();

    menu();

    int command = 0;
    while(command != 9)
    {
        cout << "Sellect an option: ";
        cin >> command;

        switch(command)
        {
            case 1: system("cls"); showMatrix();          cout << endl; waitforenter(); break;
            case 2: system("cls"); checkComplete();       cout << endl; waitforenter(); break;
            case 3: system("cls"); showAdjList();         cout << endl; waitforenter(); break;
            case 4: system("cls"); averagePathLength();   cout << endl; waitforenter(); break;
            case 5: system("cls"); findIsolated();        cout << endl; waitforenter(); break;
            case 6: system("cls"); countIsolated();       cout << endl; waitforenter(); break;
            case 7: system("cls"); maxRouteThreeCities(); cout << endl; waitforenter(); break;
            case 8: system("cls"); checkHamiltonian();    cout << endl; waitforenter(); break;
            case 9: return 0;
            default: cout << "Enter correct operation!" << endl;
        }
    }

    return 0;
}