#include<bits/stdc++.h>
using namespace std;

const int M = 6; // M periods
const int N = 17; // N courses

int n, m, cur, res, sum;
int credit[N], Pre[N][N];
int load[M];
bool s_ort[N], t_aught[N];
vector <int> AA;
int SX[N];

void input(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        cin >> credit[i];
        sum += credit[i];
    }

    for(int i = 1; i<=n; i++){
        for(int j =1; j<=n; j++){
            cin >> Pre[i][j];
        }
    }
    int i=1,t;
    while(AA.size() < n){
        if(!s_ort[i]){
            t = 0;
            for(int j = 1; j<=n; j++){
                if(!s_ort[j] && Pre[j][i] == 1){
                    t ++;
                }
            }

            if(t == 0){
                AA.push_back(i);
                s_ort[i] = true;
            }
        }
        i++;
        if(i == n+1){
            i = 1;
        }
    }
}

bool check(int k , int i){
    for(int j = 1; j<=n; j++){
        if(Pre[j][AA[k]] == 1){
            if(!t_aught[j] || SX[j] > i-1 || SX[j] < 1){
                return false;
            }
        }
    }
    return true;
}

void Try(int k){ // Try to find period for AA[k]
    for(int i = 1; i<=m; i++){
        if(check(k,i)){
            SX[AA[k]] = i;
            load[i] += credit[AA[k]];
            t_aught[AA[k]] = true;

            cur = *max_element(load+1, load+i+1);
            if(k == n-1){
                // int t = res;
                res = min(res, cur);
                // if(res == cur && res < t){
                //     for(int i = 1; i<=n; i++){
                //         cout << SX[i] << " ";
                //     }
                //     cout << res << endl;
                // }
            }
            else{
                if(cur < res){
                    Try(k+1);
                }
            }

            SX[AA[k]] = 0;
            load[i] -= credit[AA[k]];
            t_aught[AA[k]] = false;
        }
    }
}


int main(){
    freopen("inp.inp", "r", stdin);

    input();
    cur = 0; res = INT_MAX;
    Try(0);
    cout << res;
    //for(int i = 0; i<AA.size(); i++){
    //    cout<< AA[i];
    //}
}