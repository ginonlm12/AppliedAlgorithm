#include<bits/stdc++.h>
using namespace std;

int n;
unordered_set<string> key;

int find(string K) {
    return key.count(K);
}

int insert(string K) {
    return key.insert(K).second;
}

int main() {
    freopen("inp.inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string str, mtr;
    
    while (true) {
        cin >> str;
        if (str == "*") {
            break;
        }
        key.insert(str);
    }

    while (true) {
        cin >> str;
        if (str == "***") {
            break;
        }
        if (str == "find") {
            cin >> mtr;
            cout << find(mtr) << endl;
        }
        if (str == "insert") {
            cin >> mtr;
            cout << insert(mtr) << endl;
        }
    }
}
