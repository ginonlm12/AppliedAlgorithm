#include<bits/stdc++.h>
using namespace std;
const int MAXN = 20;
int Cost[MAXN+1][MAXN+1];
int n, f, g, visited[MAXN+1], ires[MAXN+1];
double cmin, f0;

int Try(int k){
    for(int i = 2; i<=n; i++){
        if(!visited[i]){
            ires[k] = i;
            visited[i] = 1;
            f =  f + Cost[ires[k-1]][i];
            if(k == n){
                if(f + Cost[i][ires[1]] < f0){
                    f0 = f + Cost[i][ires[1]];
                }
            }
            else{
                g = f + cmin*(n-k+1);
                if(g < f0){
                    Try(k+1);
                }
            }
            f = f - Cost[ires[k-1]][i];
            visited[i] = 0;
        }
    }
}

int main(){
    freopen("inp.inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n; 
    cmin = INFINITY;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cin >> Cost[i][j];
            if(cmin > Cost[i][j] && Cost[i][j] > 0) cmin = Cost[i][j];
        }
    }
    for(int i = 2; i<=n; i++){
        visited[i] = 0;
    }
    f0 = INFINITY;
    f = 0;
    ires[1] = 1;
    visited[1] = 1;
    Try(2);
    cout << f0;
}