#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int iProfit[4];
    int T; cin >>T;
    for(int i = 0; i<T; i++){
        cin >> iProfit[0] >> iProfit[1] >> iProfit[2] >> iProfit[3];
        sort(iProfit, iProfit+4);

        int sum = 0;
        if(iProfit[0] <= 0) sum+=iProfit[0];
        if(iProfit[1] <= 0) sum+=iProfit[1];
        cout << sum;
    }
}