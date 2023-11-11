#include<bits/stdc++.h>
using namespace std;
const long long MAXN = 1e6+2;
long long a[MAXN], Odd[MAXN], Even[MAXN], iMem[MAXN];
long long n, pos = -1, res = INT_MIN, temp;

long long SOLVE(){
    for(int i = 1; i<=n; i++){
        if(a[i] %2 == 0){
            Even[i] = max(a[i], a[i] + Even[i-1]);
            Odd[i] = Odd[i-1] + a[i];
        }
        else{
            Odd[i] = max(a[i], a[i] + Even[i-1]);
            Even[i] = Odd[i-1] + a[i];
        }
        res = max(res, Even[i]);
    }
    return res;
}

int main(){
    //freopen("inp.inp", "r", stdin);
    //freopen("oup.oup", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    Odd[0] = INT_MIN;
    Even[0] = INT_MIN;
    for(int i = 1;i <=n; i++){
        cin >> a[i];
    }
    cout << SOLVE();
}
