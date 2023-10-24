#include<bits/stdc++.h>
using namespace std;

stack<char> parent;

int main(){
    freopen("inp.inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int check = 1;
    string s;
    getline(cin, s);
    for(int i = 0; i<s.size(); i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            parent.push(s[i]);
        }
        else if (!parent.empty()){
            char T = parent.top();
            parent.pop();
            if(!(T == '(' && s[i] == ')' || T == '{' && s[i] == '}' || T == '[' && s[i] == ']')){
                check = 0;
                break;
            }
        }
        else{
            check = 0;
            break;
        }
    }
    if (!parent.empty()) {
        check = 0;
    }
    cout << check;
}