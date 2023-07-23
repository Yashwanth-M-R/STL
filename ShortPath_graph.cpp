#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

//Adding Edges
void addEdge(vector<vector<int>>& v1, int u, int v) {
    v1[u].push_back(v);
    v1[v].push_back(u);
}

//Breadth First Search Algorithm is implemented using this function
vector<int> BFS_Search(const vector<vector<int>>& v1, int s, int end) {
    queue<int> q;
    vector<bool> visit(v1.size(), false);
    vector<int> parent(v1.size(), -1);

    q.push(s);
    visit[s] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == end) {
            break;
        }

        for (int neighbor : v1[current]) {
            if (!visit[neighbor]) {
                q.push(neighbor);
                visit[neighbor] = true;
                parent[neighbor] = current;
            }
        }
    }
    vector<int> shortestPath;
    int current = end;
    while (current != -1) {
        shortestPath.push_back(current);
        current = parent[current];
    }
    reverse(shortestPath.begin(), shortestPath.end());
    return shortestPath;
}


int main()
{
    int v, e;
    cout << "Enter the number of vertices: ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> e;
    vector<vector<int>> v1(v);
    cout << "Enter the edges " <<endl;
    for (int i = 0; i < e;i++) {
        int x, y;
        cin >> x >> y;
        addEdge(v1, x, y);
    }
    int s, end;
    cout << "Enter the source and destination vertices";
    cin >> s >> end;
    vector<int> shortestPath = BFS_Search(v1, s, end);
    cout << "Shortest path from " << s << " to " << end << ": ";
    for (int v : shortestPath) {
    cout << v << " ";
    }
    cout <<endl;
    return 0;
}