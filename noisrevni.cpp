#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1000000+2;
int n, x[MAXN], num, i;
const int M = 1e9 + 7;

void Merge(int left, int right, int mid){
    int p = mid - left + 1;
    int q = right - mid;
    int L[p+1], R[q+1];

    for(int i = left; i<= left + p -1; i++){
        L[i-left+1] = x[i];
    }
    for(int i = mid+1; i<= mid + q; i++){
        R[i-mid] = x[i];
    }

    int i = 1, j = 1;
    for(int v = left; v <= right; v++){
        if(L[i] <= R[j] && i< p){
            x[v] = L[i];
            i++;
        }
        else if(L[i] <= R[j] && i == p){
            x[v] = L[i];
            while(v < right){
                x[++v] = R[j++];
            }
        }
        else if(L[i] > R[j] && j < q){
            num = (num + mid - left - i + 2)%M;
            x[v] = R[j];
            j++;
        }
        else if(L[i] > R[j] && j == q){
            num =  (num + mid - left - i + 2)%M;
            x[v] = R[j];
            while(v < right){
                x[++v] = L[i++];
            }
        }
    }
}

void MergeSort(int left, int right){
    if(right > left){
        int mid = (right + left) / 2;
        MergeSort(left, mid);
        MergeSort(mid+1, right);
        Merge(left, right, mid);
    }
}

int main(){
    freopen("inp.inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x[i];
    }
    MergeSort(1, n);
    cout << num;
}