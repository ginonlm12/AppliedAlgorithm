#include<bits/stdc++.h>
using namespace std;
const unsigned int MAXN = 1e6+1;

int n, m;
int RMQ[MAXN][MAXN];
int A[MAXN];
vector<pair<int, int> > P;

void input(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    cin >> m;
    int a, b;
    for(int i = 1; i <= m; i++){
        cin >> a >> b;
        P.push_back(make_pair(a, b));
    }
}

void compute_RMQ() {
    for (int i = 0; i < n; i++) {
        RMQ[i][i] = A[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            RMQ[i][j] = min(RMQ[i][j - 1], A[j]);
        }
    }
}

int main(){
    freopen("inp.inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    input();
    compute_RMQ();
    int sum = 0;

    for (const pair<int, int>& p : P) {
        int first_element = p.first;
        int second_element = p.second;

        sum += RMQ[first_element][second_element];
    }

    cout << sum;

    return 0;
}
