#include<bits/stdc++.h>
using namespace std;

stack <int> CHUONG;
queue <int> HanhLang;
const int MAXN = 1e5+2;
int n;
string S;

int main(){
    freopen("input.inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int P[MAXN];
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> P[i];
    }
    for(int i = n; i>=1; i--){
        CHUONG.push(P[i]);
    }
    cin >> S;
    int a;
    for(int i = 0; i< S.size(); i++){
        if(S[i] == 'C' && !CHUONG.empty()){
            a = CHUONG.top();
            CHUONG.pop();
            HanhLang.push(a);
        }
        if(S[i] == 'H' && !HanhLang.empty()){
            a = HanhLang.front();
            HanhLang.pop();
            CHUONG.push(a);
        }
    }

    for(int i = 1; i<=n; i++){
        P[i] = CHUONG.top();
        CHUONG.pop();
        cout << P[i] << " ";
    }
}