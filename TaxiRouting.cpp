#include<bits/stdc++.h>
using namespace std;

const int MAXN = 12;

int n, cmin;

int res, cur;
int C[2*MAXN][2*MAXN];
int visited[MAXN];
int city[MAXN];

void input(){
    cin >> n;
    cmin = INT_MAX;
    for(int i = 0; i<= 2*n; i++)
        for(int j = 1; j<= 2*n; j++){
            cin >> C[i][j];
            if(i!=j && C[i][j] < cmin) cmin = C[i][j];
        }
}

void Try(int k){

    for(int i = 1; i<=n; i++){
        if(!visited[i]){
            city[k] = i;
            visited[i] = 1;
            
            if(k == 1) cur += C[0][i];
            else cur += C[city[k-1]+n][i];
            
            cur += C[i][i+n];

            // cout << cur << endl;
            if(k == n){
                cur += C[i+n][0];
                res = min(res, cur);
            } else{
                if(cur + 2*(n-k)*cmin < res) Try(k+1);
            }
            visited[i] = 0;
            if(k == n) cur -= C[i+n][0];
            if(k == 1) cur -= C[0][i];
            else cur -= C[city[k-1]+n][i];
            cur -= C[i][i+n];
        }
    }
}
int main(){
    freopen("inp.inp", "r", stdin);
    input();
    res = 100, cur = 0;
    for (int i =1; i<=n; i++) visited[i] = 0;
    Try(1);
    cout << res;
}