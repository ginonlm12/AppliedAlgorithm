#include<bits/stdc++.h>
using namespace std;

#define N 31 // Max number of subject
#define M 11 // Max number of teacher

int n,m,k,d,res,f;
bool teach[M][N]; // teach[j][k] = true iff teacher j can teach subject k
bool conflict[N][N]; // conflict[i][j] = true iff subject i and j conflict
int sol[N]; // sol[i] = j iff teacher j teaches subject i
int nbTeach[M]; //nbTeach[j] = number of subjects teacher j teaches

void input(){
    cin >> m >> n;
    int r, a;
    for(int i = 1; i<=m; i++){
        nbTeach[i] = 0;
        cin >> r, a;
        for(int j = 0; j<r; j++){
            cin >> a;
            teach[i][a] = true;
        }    
    }
    cin >> k;
    int t1, t2;
    for(int i = 0; i<k; i++){
        cin >> t1 >> t2;
        conflict[t1][t2] = true;
        conflict[t2][t1] = true;
    }
}

bool check(int i, int k){
    if(!teach[i][k]) return false;
    else{
        for(int r = 1; r<=n; r++){
            if(sol[r] == i && conflict[r][k]){
                return false;
            }
        }
    }
    return true;
}

void Try(int k){// Choose teacher for the k-th subject
    for(int i = 1; i<=m; i++){
        if(check(i,k)){
            sol[k] = i;
            for(int j = 1; j<=n; j++){
                if(sol[j]!=0) nbTeach[sol[j]]++;
            }
            d = *max_element(nbTeach, nbTeach+m+1);
            for (int i = 1; i<=m; i++) nbTeach[i] = 0;
            if(k == n){
                if(d<res) res = d;
            }
            else{
                if(d<res){
                    Try(k+1);
                }
            }
            sol[k] = 0;
        }
    }
}
int main(){
    freopen("inp.inp", "r", stdin);
    input();
    res = 100;
    Try(1);
    if(res != 100) cout << res;
    else cout << -1;
    return 0;
}