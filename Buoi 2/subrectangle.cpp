#include <bits/stdc++.h>
using namespace std;
const int JISOO = 1e3+2;
int n, m;
int **A = new int*[JISOO];

int input(){
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        A[i] =  new int[m+2];
        for(int j = 1; j<=m; j++){
            cin >> A[i][j];
        }
    }
}

int SOLVE_SubProblem(int *A){
    int res = 0; 
    int R[JISOO];
    stack<int> Right;
    for(int i = 1; i<=m+1; i++){
        while(!Right.empty() && A[i] < A[Right.top()]){
            R[Right.top()] = i;
            Right.pop();
        }
        Right.push(i);
    }
    int L[JISOO];
    stack<int> Left;
    for(int i = m; i>=0; i--){
        while(!Left.empty() && A[i] < A[Left.top()]){
            L[Left.top()] = i;
            Left.pop();
        }
        Left.push(i);
    }
    for(int i = 1; i<=m; i++){
        res = max(res, (R[i] - L[i] - 1) * A[i]);
    }
    return res;
}

int SOLVE(int **A){
    int B[JISOO];
    B[0] = -1;
    B[m+1] = -1;

    for(int j = 1; j<=m; j++){
        B[j] = A[1][j];
    }
    int cur = SOLVE_SubProblem(B);

    for(int i = 2; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(A[i][j]==1){
                B[j] = 1 + B[j];
            }
            else{
                B[j] = 0;
            }
        }
        cur = max(cur, SOLVE_SubProblem(B));
    }
    return cur;
}

int main(){
    freopen("inp.inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    input();
    cout << SOLVE(A);

}