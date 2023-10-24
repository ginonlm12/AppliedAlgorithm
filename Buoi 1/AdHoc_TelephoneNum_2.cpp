#include<iostream>
#include <string>
using namespace std;
string sKey[12]={"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz", "", " ", ""};

int main(){
    freopen("AdHoc_TNum.inp","r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int T;
    cin >> T;
    cin.ignore();

    for(int t=0;t<T; t++){
        string SLine;
        getline(cin, SLine);
        int res = 0;
        for(int i = 0; i< SLine.size(); i++){
            int cur;
            for(int j = 0; j<12; j++){
                for(int k = 0; k<sKey[j].size(); k++){
                    if(SLine[i] == sKey[j][k]){
                        cur=k+1;
                    }
                }
            }
            res+=cur;
        }
        cout << "Case #" << t+1 << ": " << res << endl;
    }

}