#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10001;

int n,m;
int STime[MAXN];
int duration[MAXN];
bool Done[MAXN];
int L[MAXN];
vector<int> CON[MAXN];
int TotalMin;

void input(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        cin >> duration[i];
    }
    int a,b;
    for(int i = 0; i< m; i++){
        cin >> a >> b;
        CON[b].push_back(a);
    }
}

void SOLVE(){
    int Kdone = 0;
    int time, quantity;
    while(Kdone < n){
        for(int i = 1; i<=n; i++){
            if(!Done[i]){
                time = 0;
                quantity = 0;
                for(int j = 0; j<L[i]; j++){
                    if(!Done[CON[i][j]]) break;
                    else{
                        time = max(time, STime[CON[i][j]] + duration[CON[i][j]]);
                        quantity++;
                    }
                }
                if(quantity == L[i]){
                    STime[i] = time;
                    Done[i] = true;
                    cout << i << " " << STime[i] << " " << STime[i] + duration[i] << endl;
                    Kdone ++;
                    TotalMin = max(STime[i] + duration[i], TotalMin);
                }
            }
        }
    }
}

int main(){
    freopen("inp.inp", "r", stdin);

    TotalMin = 0;
    input();    
    for(int i = 1; i<= n; i++){
        L[i] = CON[i].size();
    }
    SOLVE();
    cout << TotalMin;
}