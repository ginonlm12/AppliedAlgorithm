#include<iostream>
using namespace std;
const int MAXN = 12;
int n, k;
int passengers = 0; //
int C[2*MAXN][2*MAXN];
bool visited[2*MAXN];
int cmin = 1e6, res = 0, rmin = 1e6;
int X[2*MAXN];

void input(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 0; i<= 2*n; i++){
		for(int j = 0; j<= 2*n; j++){
			cin >> C[i][j];
			if(i != j) cmin = min(cmin, C[i][j]);
		}
	}
}

bool check(int a, int i){
    if(visited[i]) return false;
    if(i <= n){
        if(passengers == k) return false;
    }
    if(i > n){
        if(!visited[i-n]) return false;
    }
    if(C[X[a-1]][i] == 0) return false;
    return true;
}

void Try(int a){
    for(int i = 1; i<= 2*n; i++){
        if(check(a,i)){
            X[a] = i;
            // cout << "X[" << a << "] = " << i <<endl;
            visited[i] = true;
            res += C[X[a-1]][i];
            if(i <= n) passengers++;
            else passengers--;

            if(a == 2*n){
                res += C[X[2*n]][0];
                rmin = min(res, rmin);
                // if(rmin == res){
                //     cout << res << e;
                //     for(int i = 0; i<= 2*n; i++){
                //         cout << X[i] << " ";
                //     }
                //     cout << endl;
                // }
                res -= C[X[2*n]][0];
            }
            else{
                if(res + (2*n - a)*cmin < rmin){
                    Try(a+1);
                }
            }

            visited[i] = false;
            res -= C[X[a-1]][i];
            if(i <= n) passengers--;
            else passengers++;
        }
    }
}

int main(){
    freopen("input.inp", "r", stdin);
    input();
    visited[0] = true;
    X[0] = 0;
    Try(1);
    cout << rmin;
}