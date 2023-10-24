#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000000+1;
int n, M, A[MAX], dem;

void input(){
    cin >> n >> M; 
    for(int i = 1; i<=n; i++){
        cin >> A[i];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    input();

    sort(A+1, A+n+1);

    int left = 1; 
    int right = n; 
    dem = 0;

    while (left < right) {
        int sum = A[left] + A[right];

        if (sum == M) {
            dem++;
            left++; 
            right--; 
        } else if (sum < M) {
            left++;
        } else {
            right--; 
        }
    }

    cout << dem;

    return 0;
}
