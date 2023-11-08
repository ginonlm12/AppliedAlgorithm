#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5+2;
int N, M;
bool visited[MAX];
vector<int> Adj[MAX];
int VisitNum;
int Color[MAX];

void input(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    int a, b;
    for(int i = 1; i<= M; i++){
        cin >> a >> b;
        Adj[a].push_back(b);
        Adj[b].push_back(a);
    }
}

bool BFS(){
    queue<int> Q;
    Q.push(1);
    visited[1] = true;
    VisitNum++;
    Color[1] = 1;

    while(!Q.empty()){
        int u = Q.front();
        Q.pop();

        for(int i = 0; i < Adj[u].size(); i++){
            if(visited[Adj[u][i]]){
                if(Color[Adj[u][i]] == Color[u]) return false;
            }
            else{
                VisitNum++;
                visited[Adj[u][i]] = true;
                Q.push(Adj[u][i]);
                Color[Adj[u][i]] = 1 - Color[u];
            }
        }
        if(VisitNum == N){
            return true;
        }
    }
    
    return true;
}

int main(){
    freopen("inp.inp", "r", stdin);
    
    input();
    cout << BFS();
}