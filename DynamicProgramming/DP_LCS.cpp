#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10001;
int n, m;
int iMem[MAXN][MAXN];
int X[MAXN], Y[MAXN];
int pos_i, pos_j;


int SOLVE(){
    for(int i = 0; i<=n; i++){
        iMem[0][i] = 0;
    }
    for(int i = 0; i<=n; i++){
        iMem[i][0] = 0;
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            iMem[i][j] = max(iMem[i][j-1], iMem[i-1][j]);
            if(X[i] == Y[j]){
                iMem[i][j] = max(iMem[i][j], 1+iMem[i-1][j-1]);
            }
        }
    }
    cout << iMem[n][m];
}

int main(){
    freopen("inp.inp", "r", stdin);
    //freopen("oup.oup", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(iMem, -1, sizeof(iMem));

    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        cin >> X[i];
    }
    for(int i = 1; i<=m; i++){
        cin >> Y[i];
    }
    SOLVE();
}
