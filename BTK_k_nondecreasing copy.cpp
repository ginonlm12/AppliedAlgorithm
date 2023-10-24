#include<bits/stdc++.h>
using namespace std;

int n, k, sum = 0;
int X[41];

void Try(int j){
    for(int t = X[j-1]; t <= (n-sum)/(k-j+1); t++){
        X[j] = t;
        sum += t;
        if(j == k){
            if(sum == n){
                for(int i = 1; i<=k; i++){
                    cout << X[i] << " ";
                }
                cout << endl;
            }
        }
        else{
            Try(j+1);
        }
        sum -= t;
    }
}
int main(){
    cin >> k >> n;
    X[0] = 1;
    Try(1);
}