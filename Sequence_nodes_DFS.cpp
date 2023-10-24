#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10000+1;
int n, m; 
int edge[MAXN][MAXN];
int visited[MAXN];
vector<int> sequence;

void input(){
    cin >> n >> m;
    int a,b;
    for(int i = 1; i<= m; i++){
        cin >> a >> b;
        edge[a][b] = 1;
        edge[b][a] = 1;
    }
}

void DFS(int u) {
    visited[u] = 1;
    sequence.push_back(u);
    for (int v = 1; v<=n; v++){
        if (edge[u][v] == 1 && !visited[v]) {
            DFS(v);
        }
    }
}


int main(){
    freopen("inp.inp", "r", stdin);
    input();
    DFS(1);
    for(int i = 1; i<= n; i++){
        if(visited[i] == 0){
            DFS(i);
        }
    }
    for (int i = 0; i <= n-1; i++) {
        cout << sequence[i] << " ";
    }
}