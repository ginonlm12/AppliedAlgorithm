#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 2;
int a[MAXN], iMem[MAXN];
int n, res = INT_MIN;
int startIdx = 1, endIdx = 1;

int MaxSE(int i) {
    if (i == 1) return iMem[1] = a[1];
    if (iMem[i] != -1) return iMem[i];

    int re = max(a[i], a[i] + MaxSE(i - 1));

    iMem[i] = re;
    return iMem[i];
}

void findMaxSE() {
    int maxSum = INT_MIN;
    int curStart = 1;
    int curSum = 0;
    for (int i = 1; i <= n; i++) {
        if (curSum + a[i] < a[i]) {
            curStart = i;
            curSum = a[i];
        } else {
            curSum += a[i];
        }
        if (curSum > maxSum && curSum % 2 == 0) {
            maxSum = curSum;
            startIdx = curStart;
            endIdx = i;
        }
    }
}

int solve() {
    findMaxSE();
    if (startIdx == 1 && endIdx == 1) {
        return -1;
    }
    return endIdx - startIdx + 1;
}

int main() {
    freopen("inp.inp", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    memset(iMem, -1, sizeof(iMem));
    int result = solve();
    if (result == -1) {
        cout << "-1";
    } else {
        cout << result;
    }
}
