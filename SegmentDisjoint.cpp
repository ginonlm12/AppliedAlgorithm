#include <bits/stdc++.h>
using namespace std;
#define N 100001
pair<int, int> ab[N]; int n;
int main(int argc, char const *argv[]){
    freopen("inp.inp", "r", stdin);
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> ab[i].first >> ab[i].second;
    }
    
    sort(ab+1, ab+n+1, [](pair<int, int> x, pair<int, int> y) {
        return x.second < y.second;
    });

    int nbSegments = 0, end = 0;
    for(int i=1; i<=n; i++){
        if (ab[i].first <= end) continue;
        else {
            nbSegments++;
            end = ab[i].second;
            cout << ab[i].first << " " << ab[i].second << endl;
        }
    }
    //cout << nbSegments;
}