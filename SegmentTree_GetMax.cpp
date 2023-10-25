#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+2;
int n, m;
int A[MAXN];
int Tree[4*MAXN];

void BuildTree(int id, int l, int r){
    if(l == r){
        Tree[id] = A[r];
        return ;
    }
    
    int mid = (l+r)/2;
    BuildTree(2*id, l, mid);
    BuildTree(2*id + 1, mid+1, r);

    Tree[id] = max(Tree[2*id], Tree[2*id+1]);
}
void UpdateTree(int id, int l, int r, int i, int val){
    if (i < l || i > r){
        return ;
    }
    if(l == r){
        Tree[id] = val;
        return ;
    }

    int mid = (l+r)/2;
    UpdateTree(2*id, l, mid, i, val);
    UpdateTree(2*id+1, mid+1, r, i, val);

    Tree[id] = max(Tree[2*id], Tree[2*id+1]);
}

int MaxSegment(int id, int l, int r, int u, int v){
    if(u > r || v < l){
        return INT_MIN;
    }
    if(l == r){
        return Tree[id];
    }

    int mid = (l+r)/2;
    return max(MaxSegment(2*id, l, mid, u, v), MaxSegment(2*id+1, mid+1, r, u, v));
}
int main(){
    freopen("inp.inp", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string S;
    int a, b; 

    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> A[i];
    }
    BuildTree(1, 1, n);
    cin >> m;
    while(m--){
        cin >> S;
        if(S == "get-max"){
            cin >> a >> b;
            cout << MaxSegment(1, 1, n, a, b) << endl;
        }
        if(S == "update"){
            cin >> a >> b;
            UpdateTree(1, 1 ,n, a, b);
        }
    }
}