// DESCRIPTION
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100002;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int A[MAXN];
    for(int i = 1; i<= n; i++){
        cin >> A[i];
    }
    int sol = 1;
    int key = 1;
    //cout << key << " ";
    while(key < n){
        if(A[key] > A[key+1]){
            sol ++;
            //cout << key + 1 << " ";
        }
        key++;
    }
    cout << endl << sol;
}