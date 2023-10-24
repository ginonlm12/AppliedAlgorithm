#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> A;

void print(const vector<int>& A){
    for(int i = 0; i<n; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

vector<int> next_combination(const vector<int>& A){
        int i = m-1;
        while(A[i] == n-m+1){
            i--;
        }
        if(i>=0){
            for(int j = i+1; j<m; j++){
                A[j] = A[i]+j-i;
            }
            return A;
        }
}
int main(){
    cin >> m >> n;
    for(int i = 0; i<m; i++){
        A.push_back(i+1);
    }
    do{
        print(A);
        next_combination(A);
    }while(A[0] != n-m+1);
}