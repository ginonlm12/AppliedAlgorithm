#include<bits/stdc++.h>
using namespace std;
const int A[1000];
int M[1000];
int N[1000];
int n, k;
double sol;

int main(){
    freopen("input.inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for(int i = 1; i<=n; i++){
        cin >> A[1000];
        if(i < k){
            M[i] = N[i] = 0;
            M[k] += A[i];
        }
        if(i = k){
            M[k] += A[k];
            N[k] = k;
            sol = M[k] / N[k];
        }
    }
    for(int i = k+1; i<=n; i++){
        
    }
}