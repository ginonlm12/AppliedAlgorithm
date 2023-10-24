#include<bits/stdc++.h>
using namespace std;
const int MAXN = 16; // Number of papers
const int MAXM = 11; // Number of reviewers

int b, k, n, m;
vector<int> L[MAXN];
bool check = true;
bool reviewed[MAXN][MAXM] // reviewed[i][j] = true if reviewer j reviews paper i
int reviewed[MAXN][MAXM]

void input(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> b;
    int a;
    for(int i = 1; i<=n; i++){
        cin >> k;
        if(k < b) check = false;
        for(int j = 1; j<=k; j++){
            cin >> a;
            L[i].push_back(a);
        }
    }
}
void Try_reviewers(int k, int i){ // Choose k-th reviewer for i-th paper

}

void Try_papers(int i){ // Calculate the branch and bound

}

int main(){
    freopen("inp.inp", "r", stdin);

    input();
    if(!check) cout << "-1";
    else{

    }
}