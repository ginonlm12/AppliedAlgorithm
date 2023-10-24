#include<iostream>
#include<vector>

using namespace std;
const int MAXN = 32; // The maximum number of courses
const int MAXM = 12; // The maximum number of teachers
int n, m, k, res, rmax; // The numbers of courses (n) and teachers (m)

vector<int> T[MAXM]; // The list of teacher that can teach courses i

int X[MAXN];
int Load[MAXM]; // The numbers of course teacher i teach
bool conflict[MAXN][MAXN]; // The numbers of course that are conflict;

void input(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    int a, b;
    for(int i = 1; i<= n; i++){
        cin >> b;
        for(int j = 0; j<b; j++){
            cin >> a;
            T[a].push_back(i);
        }
    }
    cin >> k;
    for(int i = 1; i<=k; i++){
        cin >> a >> b;
        conflict[a][b] = true;
        conflict[b][a] = true;
    }
}

bool check(int k, int t){
    for(int i = 1; i< k; i++){
        if(conflict[i][k] && X[i] == t){
            return false;
        }
    }
    return true;
}

void Try(int k){
    for(int i = 0; i < T[k].size(); i++){
        int t = T[k][i]; // Choose the teacher to teach subject k;
        if(check(k,t)){
            
            Load[t]++;
            X[k] = t;
            if(k == n){
                res = 0;
                for(int i = 1; i<=m; i++){
                    res = max(Load[i], res);
                }
                rmax = min(rmax, res);
            }
            else{
                res = 0;
                for(int i = 1; i<=m; i++){
                    res = max(Load[i], res);
                }
                if(res < rmax){
                    Try(k+1);
                }
            }

            Load[t]--;
        }
    }
}

int main(){
    freopen("input.inp", "r", stdin);

    rmax = 100;
    res = 0;
    input();
    cout << rmax;
}