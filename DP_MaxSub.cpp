#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+2;
int a[MAXN], iMem[MAXN];
int n, pos = -1, res = INT_MIN, temp;

int MaxSub(int i){
    if(i == 1) return iMem[1] = a[1];
    if(iMem[i] != -1) return iMem[i];

    int re = max(a[i], a[i] + MaxSub(i-1));

    iMem[i] = re;
    return iMem[i];
}

int solve(){
    for(int i = 1; i<=n; i++){
        if(res < MaxSub(i)){
            res = MaxSub(i);
            pos = i;
        }
    }
    cout << res;
}

void Trace(int i){
    for(int j = i; j >= 1; j--){
        if(temp == a[j]){
            cout << a[j] <<" ";
            return ;
        }
        else if(temp == a[j] + iMem[j-1]){
            temp = temp - a[j];
            Trace(j-1);
            cout << a[j] <<" ";
            return ;
        }
    }
}

int main(){
    freopen("inp.inp", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 1;i <=n; i++){
        cin >> a[i];
    }
    memset(iMem, -1, sizeof(iMem));
    solve();
    
    temp = res;
    //cout << endl;
    //Trace(pos);
}