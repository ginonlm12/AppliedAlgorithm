#include<bits/stdc++.h>
using namespace std;
int n, L;

void convert(string K) {
    int m = K.size();
    string result = string(L - m, '0') + K;
    cout << result << endl;
}

int main(){
    freopen("inp.inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string K;
    cin >> n >> L;
    for(int i = 0; i<n; i++){
        cin >> K;
        convert(K);
    }
}