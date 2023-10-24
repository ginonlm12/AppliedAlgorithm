#include<bits/stdc++.h>
using namespace std;
int N, T, dem, sum;
char Char[8] = {'A', 'S','H','O', 'U', 'I', 'C', 'T'};
int x[8] = {0, 10010, 1000, 1000, 100, 100, 10, 2};
bool used[10];
map<char, int> Q;

bool check(int k, int i){
    if(k == 1 && i == 0) return false; 
    if(k == 2 && i == 0) return false; 
    if(used[i]) return false;
    return true;
}
void GhiNhan(){
    dem++; cout << dem << ". ";
    cout << "HUST = " << Q[Char[2]] << Q[Char[4]] << Q[Char[1]] << Q[Char[7]] << " ";
    cout << "SOICT = " << Q[Char[1]] << Q[Char[3]] << Q[Char[5]] << Q[Char[6]] << Q[Char[7]] << endl;
}
void Try(int k){
    for(int i = 0; i<= min((N - sum)/x[k], 9); i++){
        if(check(k, i)){
            used[i] = true;
            sum += x[k] * i;
            Q[Char[k]] = i;
            if(k == 7){
                if(sum == N) GhiNhan();
            }
            else{
                Try(k+1);
            }
            sum -= x[k] * i;
            used[i] = false;
        }
    }
}
int main(){
    freopen("input.inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> T;
    for(; T>0; T--){
        cin >> N;
        if(N > 106236 || N < 12772){
            cout << 0;
        }
        else{
            if(N%2 != 0){
                cout << 0;
            }
            else{
                dem = 0;
                sum = 0;
                Try(1);
                cout << "The number of satisfied solution is: " << dem;
            }
            cout << endl;
        }
    }
}