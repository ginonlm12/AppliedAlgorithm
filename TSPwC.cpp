#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1001;
int Dist[MAXN][MAXN];
int Route[MAXN];
int n, k;
vector <int> CON[MAXN];

void input(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for(int i = 1; i<= n; i++){
        cin >> Route[i];
    }
    for(int i = 1; i<= n; i++){
        for(int j = 1; j <=n; j++){
            cin >> Dist[i][j];
        }
    }
    cin >> k;
    int a, b;
    for(int i = 1; i<= k; i++){
        cin >> a >> b;
        CON[b].push_back(a);
    }
}

int SOLVE(){
    int C = 0, L;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<= i; j++){
            L = CON[Route[i]].size();
            for(int t = 0; t < L; t++){
                if(CON[Route[i]][t] == Route[j]){
                    C++;
                }
            }
        }
    }
    if(C != k) return -1;
    else{
        int sum = 0;
        for(int i = 1; i<n; i++){
            sum += Dist[Route[i]][Route[i+1]];
        }
        sum += Dist[Route[n]][Route[1]];
        return sum;
    }
}
int main(){

    input();
    cout << SOLVE();
}