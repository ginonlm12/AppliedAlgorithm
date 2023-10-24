#include <bits/stdc++.h> 
using namespace std;
int main() { 
    unsigned long long a,b;
    cin >> a >> b;
    unsigned long long a1 = a%10;
    //cout << a1 << " ";
    unsigned long long a2 = (a-a1)/10;
    //cout << a2 << " ";
    unsigned long long b1 = b%10;
    //cout << b1 << " ";
    unsigned long long b2 = (b-b1)/10;
    //cout << b2 << " ";
    unsigned long long c1 = (a1+b1)%10;
    unsigned long long c2 = (a1+b1-c1)/10;
    if(a2+b2+c2>0) cout << a2+b2+c2;
    cout << c1;
    return 0;
}