#include<bits/stdc++.h>
using namespace std;
int n;
vector<string> key;

int find(string K){
    int i = 0;
    for(const string& str: key){
        if(str == K){
            i = 1;
        }
    }
    return i;
}

int insert(string K){
    if(find(K) == 1){
        return 0;
    }
    else{
        key.push_back(K);
        return 1;
    }
}

int main(){
    freopen("inp.inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string str, mtr;
    //cin >> n;
    while(true){
        cin >> str;
        key.push_back(str);
        if(str == "*"){
            break;
        }
    }
    while(true){
        cin >> str;
        if(str == "***"){
            break;
        }
        if(str == "find"){
            cin >> mtr;
            cout << find(mtr) << endl;
        }
        if(str == "insert"){
            cin >> mtr;
            cout << insert(mtr) << endl;
        }
    }
}