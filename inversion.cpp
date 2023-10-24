#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >>n;
    int dem = 0;
    int A[1000001];
    for(int i = 0; i<n; i++){
        cin >> A[i];
    }
    int m = 1e9 + 7;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if(A[i] > A[j]){
                dem ++;
            }
        }
        if(dem > m){
            dem = dem % m;
        }
    }
    cout << (dem);
}