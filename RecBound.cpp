#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1002;
int n;
int xmax, xmin, ymax, ymin;
int x_1[MAXN], y_1[MAXN], x_2[MAXN], y_2[MAXN];

void input(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x_1[i];
        cin >> y_1[i];
        cin >> x_2[i];
        cin >> y_2[i]; 
    }
}

int solve(){
    xmin = min(*min_element(x_1 + 1, x_1 + n + 1), *min_element(x_2 + 1, x_2 + n + 1));
    ymin = min(*min_element(y_1 + 1, y_1 + n + 1), *min_element(y_2 + 1, y_2 + n + 1));
    xmax = max(*max_element(x_1 + 1, x_1 + n + 1), *max_element(x_2 + 1, x_2 + n + 1));
    ymax = max(*max_element(y_1 + 1, y_1 + n + 1), *max_element(y_2 + 1, y_2 + n + 1));
    
    int area = (xmax - xmin) * (ymax - ymin);
    return area;
}

int main(){
    input();
    cout << solve();
}
