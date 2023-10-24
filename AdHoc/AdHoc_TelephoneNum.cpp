#include<iostream>
#include <string>
using namespace std;

int main(){
    freopen("Adhoc_TNum.inp","r",stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >>T;
    cin.ignore(); 
    for(int i=0; i<T; i++){
        string SLine;
        getline(cin, SLine);
        int cur = 0;
        for(int j=0; j< SLine.size(); j++){
            if(SLine[j]=='a' || SLine[j]=='d' || SLine[j]=='g' || SLine[j]=='j' ||SLine[j]=='m' ||SLine[j]=='p' || SLine[j]=='t' ||SLine[j]=='w' || SLine[j]==' '){
                cur = cur+1;
            }
            if(SLine[j]=='b' || SLine[j]=='e' || SLine[j]=='h' || SLine[j]=='k' ||SLine[j]=='n' ||SLine[j]=='q' || SLine[j]=='u' ||SLine[j]=='x'){
                cur = cur+2;
            }
            if(SLine[j]=='c' || SLine[j]=='f' || SLine[j]=='i' || SLine[j]=='l' ||SLine[j]=='o' ||SLine[j]=='r' || SLine[j]=='v' ||SLine[j]=='y'){
                cur = cur+3;
            }
            if(SLine[j]=='z'){
                cur = cur+4;
            }
        }
        cout << "Case #"<<i+1<<": " << cur <<endl;
    }
}