#include<bits/stdc++.h>
using namespace std;
int N, M;
vector<int> Adj[10000+2];
int visited[10000+2], Count = 0;

void dfs(int u) {
    visited[u] = 1;
    for (int v : Adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("inp.inp", "r", stdin);

    cin >> N >> M;
    int a,b;
    for(int i = 0; i<M; i++){
        cin >> a >> b;
        Adj[b].push_back(a);
        Adj[a].push_back(b);
    }
    for(int i = 1; i<= N; i++){
        if(visited[i] == 0){
            Count ++;
            dfs(i);
        }
    }
    cout << Count;
}