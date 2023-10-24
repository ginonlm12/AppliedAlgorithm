#include<bits/stdc++.h>
using namespace std;
int A[1001];
int iMem[1001];

int ans = 1, pos = -1, n;

int LIS(int i){
    int res = 1;
    if(iMem[i] != -1) return iMem[i];
    else{
        for(int j = 1; j<i; j++){
            if(A[i] > A[j]) res = max(1, 1+LIS(j));
        }
        iMem[i] = res;
    }
    return iMem[i];
}

void solve(){
    for(int i = 1; i<=n; i++){
        if(ans < LIS(i)){
            ans = LIS(i);
            pos = i;
        }
    }
}

void Trace(int i){
    for(int j = 1; j < i; j++){
        if(A[j] < A[i] && iMem[i] == iMem[j]+1){
            Trace(j);
            break;
        }
    }
    cout << A[i] << " ";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    memset(iMem, -1, sizeof(iMem));
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> A[i];
    }

    solve();
    Trace(pos);
    cout << endl << ans;
}