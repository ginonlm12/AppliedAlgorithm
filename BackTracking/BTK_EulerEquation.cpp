#include<iostream>
using namespace std;
int sum, dem, n, M;
const int MAXN = 10001;
int a[MAXN], X[MAXN];

void GhiNhan(){
    dem++;
}

void Try(int k){
    for(int i = 1; i<= (M-sum)/a[k]; i++){
        X[k] = i;
        sum += a[k]*X[k];

        if(k == n){
            if(sum == M){
                GhiNhan();
            }
        }
        else{
            Try(k+1);
        }
        sum -= a[k]*X[k];
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> M;
    for(int i = 1; i<n+1; i++){
        cin >> a[i];
    }
    sum = 0; dem = 0;
    Try(1);
    cout << dem;
}