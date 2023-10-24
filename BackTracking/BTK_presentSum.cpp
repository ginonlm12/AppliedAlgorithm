#include<bits/stdc++.h>
using namespace std;

int n, k, sum = 0, dem = 0;
int X[1001];
const int Q = 1e9 + 7;

void Try(int j, int k){
    for(int t = X[j-1]; t <= (n-sum)/(k-j+1); t++){
        X[j] = t;
        sum += t;
        if(j == k){
            if(sum == n){
                for(int i = 1; i<=k; i++){
                     cout << X[i] << " ";
                }
                cout << endl;
                dem++;
                if(dem >= Q){
                    dem = dem % Q;
                }
            }
        }
        else{
            Try(j+1, k);
        }
        sum -= t;
    }
}
int main(){
    cin >> n;
    X[0] = 1;
    
    for(int k = 1; k<=n; k++){
        Try(1, k);
    }
    cout << dem;
}