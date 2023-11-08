#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+2;
int n;
pair<int, int> Job[MAXN];
bool slotted[MAXN];
int JB[MAXN];

int main(){
    freopen("inp.inp", "r", stdin);
    cin >> n;
    int T = 0;
    for(int i = 1; i<=n; i++){
        cin >> Job[i].first >> Job[i].second;
        if(T < Job[i].first - 1) T = Job[i].first - 1;
    }
    sort(Job+1, Job+n+1, [](pair<int, int> x, pair<int, int> y){
        return x.second > y.second;
    });

    // for(int i = 1; i<=n; i++){
    //     cout << Job[i].first << " " <<Job[i].second << endl;
    // }
    // cout << "----------------- " << endl;

    int profit = 0;
    for(int i = 1; i<=n; i++){
        int j = Job[i].first - 1; // The day before deadline
        while(j>=0){
            if(!slotted[j]){
                slotted[j] = true;
                JB[j] = i;
                profit += Job[i].second;
                break;
            }
            j --;
        }
    }
    for(int j = 0; j <= T; j++){
        if(JB[j] != 0){
            cout << j << ": " << Job[JB[j]].first << " " <<Job[JB[j]].second << endl;
        }
    }
    cout << profit;
}
