#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> a[1000];
bool visited[1000];

void input(ifstream &in) {
    in >> n;
    in >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        in >> x;
        in >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    in.close();
    memset(visited, false, sizeof(visited));
}

void bfs(int u, ofstream &out) {
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()) {
        int v = q.front();
        cout << v << " ";
        out << v << " ";
        q.pop();
        for(int i : a[v]) {
            if (!visited[i]){
                q.push(i);
                visited[i] = true;;
            }
        }
    }
    out.close();
}

void dfs(int u, ofstream &out) {
    cout << u << " ";
    out << u << " ";
    visited[u] = true;
    for(int i : a[u]) {
        if (!visited[i]) {
            dfs(i, out);
        }
    }
    
}
int main() {
    ifstream in;
    in.open("/Users/vuhuyhung/Desktop/input.txt", ios_base::in);
    ofstream out;
    out.open("output.txt", ios_base::out);
    input(in);
    bfs(1, out);
    return 0;
}
