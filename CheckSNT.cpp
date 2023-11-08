#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int dem = 0;
    bool check = true;
    if(n == 1) cout << "Cha phai gi";
    else if(n == 2) cout << "2 is a prime";
    else if(n == 3) cout << "3 is a prime";
    else{
        for(int i = 2; i<= sqrt(n); i++){
            if(n%i == 0){
                check = false;
                break;
            }
        }
    }
    if(check == false) cout << n << " not is a prime";
    else{
        cout << n << " is a prime";
    }
    // if(dem == 2) cout << n << " is a prime";
    // else{
    //     cout << n << " is not a prime";
    // }
}