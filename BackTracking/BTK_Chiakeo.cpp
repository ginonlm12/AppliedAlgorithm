// Nguyen Hoang Lam 20210517
#include<iostream>
using namespace std;
int N,n, count;
int x[1000];
void GhiNhan(){
    count++;
    //cout << "Cach chia keo thu "<<count<<" la: ";
    for(int i = 1; i<=n; i++){
        cout << x[i]<<" ";
    }
    cout << endl;
}
int Sum(int k){
    int Sum = 0;
    for(int y =1; y <k; y++){
        Sum += x[y];
    }
    return Sum;
}
int Try(int k){
    for(int y = 1; y <= N - Sum(k) - n + k; y++){
            x[k] = y;
            if(k == n-1) {
                x[n] = N - Sum(n);
                GhiNhan();
            }
            else Try(k+1);
    }
}
int main(){
    count = 0;
    cin >> n >> N;
    Try(1);
}