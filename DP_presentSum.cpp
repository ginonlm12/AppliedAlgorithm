#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1001;

int dp[MAXN][MAXN];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        dp[i][1] = 1;
    }

    for (int i = 1; i <= n; i++){
        for (int j = 2; j <= i; j++){
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - j][j]) % MOD;
        }
    }

    int dem = 0;
    for (int k = 1; k <= n; k++) {
        dem = (dem + dp[n][k]) % MOD;
    }

    cout << dem << endl;

    return 0;
}
