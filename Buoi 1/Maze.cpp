#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 1;
int a[MAXN][MAXN];
int d[MAXN][MAXN];
int visited[MAXN][MAXN];
int m, n, r, c;
queue<pair<int, int> > q;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int solve(){
    q.push(make_pair(r,c));
    visited[r][c] = true;
    d[r][c] = 1;
    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        int x = cur.first;
        int y = cur.second;
        for(int i=0; i<4; i++){
            x = cur.first + dx[i];
            y = cur.second + dy[i];
            if(x<=0 || y<=0 || x>n || y>m) return d[cur.first][cur.second];
            if(a[x][y] == 0 && visited[x][y] == false){
                q.push(make_pair(x,y));
                visited[x][y] = true;
                d[x][y] = d[cur.first][cur.second] + 1;
            }
        }
    }
    return -1;
}

void input(){
    cin >> n >> m >> r >> c;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    freopen("AdHoc_TNum.inp", "r", stdin);
    input();
    cout << solve();
}