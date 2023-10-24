#include<iostream>
#include <climits>
using namespace std;
const int MAX = 25;
int n; // The number of cities
int dist[MAX][MAX]; // The distance between cities
int X[MAX]; // The order of traversal
bool visited[MAX];
int distMin = INT_MAX;
int distCur = 0;
int cmin = INT_MAX;

void input(){
	cin >> n;
	for(int i = 0; i<= 2*n; i++){
		for(int j = 0; j<= 2*n; j++){
			cin >> dist[i][j];
			if(i != j) cmin = min(cmin, dist[i][j]);
		}
	}
}


void Try(int a){ // The a-th city of traversal
	for(int i = 1; i<= n; i++){
		if(!visited[i]){
			X[a] = i;
			visited[i] = true;
			if(a == 1) distCur += dist[X[a-1]][i] + dist[i][i+n];
			if(a > 1) 	distCur += dist[X[a-1]+n][i] + dist[i][i+n];
			
			if(a == n){
				distCur += dist[X[n]+n][0];
				distMin = min(distCur, distMin);
				distCur -= dist[X[n]+n][0];
			}
			else{
				if(distCur + cmin * (2*n - 2*a + 1) < distMin){
					Try(a+1);
				}
			}
			
			if(a == 1) distCur -= dist[X[a-1]][i] + dist[i][i+n];
			if(a > 1) 	distCur -= dist[X[a-1]+n][i] + dist[i][i+n];
			visited[i] = false;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	input();
	X[0] = 0;
	visited[0] = 1;
	Try(1);
	cout << distMin;
}
