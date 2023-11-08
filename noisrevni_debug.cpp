#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1000000+2;
int n, x[MAXN], num, i;
const int M = 1e9 + 7;

void Merge(int left, int right, int mid){
    // cout << left << "-----" << mid << "-----" << right << endl;
    // cout << "Before: ";
    // for(int v = left; v <= right; v++){
    //     cout << x[v] << " ";
    // }
    // cout << endl;

    int p = mid - left + 1;
    int q = right - mid;
    int L[p+1], R[q+1];

    for(int i = left; i<= mid; i++){
        L[i-left+1] = x[i];
    }
    for(int i = mid+1; i<= right; i++){
        R[i-mid] = x[i];
    }

    int i = 1, j = 1;
    for(int v = left; v <= right; v++){
        if(L[i] <= R[j] && i< p){
            x[v] = L[i];
            // cout << "a   " << "x[" << v <<"] = " << x[v] << endl;
            i++;
        }
        else if(L[i] <= R[j] && i == p){
            x[v] = L[i];
            //cout << "b   " << "x[" << v <<"] = " << x[v] << endl;
            while(v<= right - 1){
                x[++v] = R[j++];
                //cout << "c   " << "x[" << v <<"] = " << x[v] << endl;
            }
        }
        else if(L[i] > R[j] && j < q){
            num = (num + mid - left - i + 2)%M;
            // cout << "b   " << mid - left - i + 2 << " num = " << num << endl;
            // for(int t = left + i - 1; t <= mid; t++){
            //     cout << "h   "<<"(" << L[t - left + 1] << ", " << R[j] <<")" << endl;
            // }
            x[v] = R[j];
            j++;
            //cout << "d   " << "x[" << v <<"] = " << x[v] << endl;
        }
        else if(L[i] > R[j] && j == q){
            num =  (num + mid - left - i + 2)%M;

            // cout << "a   " << mid - left - i + 2 <<  " num = " << num << endl;
            // for(int t = left + i - 1; t <= mid; t++){
            //     cout << "g   "<<"(" << L[t - left + 1] << ", " << R[j] <<")" << endl;
            // }
            x[v] = R[j];
            //cout << "e   " << "x[" << v <<"] = " << x[v] << endl;
            v++;
            while(v<= right){
                x[v] = L[i];
                //cout << "f   " << "x[" << v <<"] = " << x[v] << endl;
                i++;
                v++;
            }
        }
    }
    // cout << "After: ";
    // for(int v = left; v <= right; v++){
    //     cout << x[v] << " ";
    // }
    // cout << endl;
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