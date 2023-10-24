#include<iostream>
using namespace std;

int main(){
   
bool M[100000] = {};
    int dem = 0;
    for(int i = 0; i < 100000; i++){
        if(M[i]) dem++;
    }
    cout << dem;
}