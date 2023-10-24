#include<bits/stdc++.h>
using namespace std;

void Swap(int &X, int &Y){
    int Temp =  X;
    X = Y;
    Y = Temp;
}

int main(){
    int A = 4;
    int B = 6;
    int C = 5;
    int D = 7;
    Swap(A,B);
    Swap(C+1,D);

    cout << A << " " << B << " " << C << " " << D;
}