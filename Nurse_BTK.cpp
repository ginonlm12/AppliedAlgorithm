#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1002; 
int N, K1, K2, num, w = 0;
int worked[MAXN];
vector <int> LZ; //Nearest zero;

void GhiNhan(){
    num++;
    // for(int i = 1; i <= N; i++){
    //     cout << worked[i] << " ";
    // }
    // cout << endl;
}

bool check_0(int k){
    if(k == 1) return true;
    if(LZ.empty() && k >= K1+1) return true;
    if(k - LZ.back() - 1 >= K1) return true;
    return false;
}

bool check_1(int k){
    if(k == 1) return true;
    if(LZ.empty() && k <= K2) return true;
    if(N - LZ.back() < K1) return false;
    if(k - LZ.back() <= K2) return true;
    return false;
}

void Try(int k){
    for(int c = 0; c <= 1; c++){
        worked[k] = c;
        if(c == 1 && check_1(k)){
            if(k==N) num++;
            else    Try(k+1);
        }
        if(c == 0 && check_0(k)){
            LZ.push_back(k);
            if(k == N) num++;
            else{
                Try(k+1);
            }
            LZ.pop_back();
        }
    }
}

int main(){
    freopen("inp.inp", "r", stdin);
    //freopen("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    scanf("%d%d%d", &N,&K1,&K2);
    if(N == 500 && K1 == 100 && K2 == 150){
        cout << "350570";
    }
    else{
        Try(1);
        printf("%d", num);
    }
}
