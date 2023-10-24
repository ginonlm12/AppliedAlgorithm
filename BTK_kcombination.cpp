#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000+1;
int n,k;
int used[MAXN];
int A[MAXN];

void input(){
    cin >> k >> n;
}
void GhiNhan(){
    for(int i = 1; i< k; i++){
        cout << A[i] << " ";
    }
    cout << A[k] << endl;
}
void Try(int i){
    for(int j = 1; j<=n; j++){
        if(i == 1 || j > A[i-1] && i>1){
    
            A[i] = j;
            if(i == k){
                GhiNhan();
            }
            else{
                Try(i+1);
            }
            
        }
    }
}

int main(){
    input();
    Try(1);
}