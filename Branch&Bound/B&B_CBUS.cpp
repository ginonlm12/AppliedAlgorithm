#include<iostream>
#include <climits>
using namespace std;
const int MAX = 40;
int passengers = 0; // The number of passengers
int n, k; // The number of cities and the largerst number of passengers
int dist[MAX][MAX]; // The distance between cities
int X[MAX]; // The order of traversal
bool visited[MAX];
int distMin = INT_MAX;
int distCur = 0;
int cmin = INT_MAX;

void input(){
	cin >> n >> k;
	for(int i = 0; i<= 2*n; i++){
		for(int j = 0; j<= 2*n; j++){
			cin >> dist[i][j];
			if(i != j) cmin = min(cmin, dist[i][j]);
		}
	}
	X[0] = 0;
	visited[0] = 1;
}

bool Check(int a, int i){
	if(i <= n && passengers == k) return false;
	if(i > n && !visited[i-n]) return false;
	if(dist[X[a-1]][i] == 0) return false;
	if(visited[i]) return false;
	return true;
}

void Try(int a){ // The a-th city of traversal
	for(int i = 1; i<= 2*n; i++){
		if(Check(a, i)){
			X[a] = i;
			visited[i] = true;
			if(i <=n) passengers++;
			else passengers--;
			distCur += dist[X[a-1]][i];
			
			if(a == 2*n){
				distCur += dist[X[2*n]][0];
				distMin = min(distCur, distMin);
				if(distMin == distCur){
					cout << distCur << endl;
                    for(int i = 0; i<= 2*n; i++){
                        cout << X[i] << " ";
                    }
                    cout << endl;
                }
				distCur -= dist[X[2*n]][0];
			}
			else{
				if(distCur + cmin * (2*n - a) < distMin){
					Try(a+1);
				}
			}
			
			distCur -= dist[X[a-1]][i];
			if(i <=n) passengers--;
			else passengers++;
			visited[i] = false;
		}
	}
}

int main(){
    freopen("inp.inp", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	input();
	Try(1);
	cout << distMin;
}
