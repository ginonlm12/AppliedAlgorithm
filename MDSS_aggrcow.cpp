#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100001;
int n, C;
int x[MAXN];
int S[MAXN];

bool check(int d){
    S[1] = 1;
    for(int i = 2; i<= C; i++){
        S[i] = -1;
        int k = S[i-1];
        for(int j = k; j <= n; j++){
            if(x[j] - x[k] >= d){
                S[i] = j;
                break;
            }
        }
        if(S[i] == -1) return false;
    }
    return true;
}

int solution(){
    int maxD = x[n] - x[1];
    int minD = 0;
    int res = 0;
    while(maxD >= minD){
        int d = (maxD + minD) / 2;
        if(check(d)){
            res = d;
            minD = d + 1;
        }
        else{
            maxD = d - 1;
        }
    }
    return res;
}

int main(){
    freopen("inp.inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T > 0){
        cin >> n >> C;
        for(int i = 1; i<=n; i++){
            cin >> x[i];
        }
        sort(x+1, x+n+1);
        cout << solution() << endl;
        T --;
    }
}