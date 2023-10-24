#include <bits/stdc++.h>
using namespace std;

#define maxN 12

int n, cm;
//cm = minimum distance between two bus stop
int f,  f_min;
int c[2*maxN][2*maxN];
bool transported[maxN]; 
int a[maxN];

void input() {
    scanf("%d", &n);
	cm = 1e9;
	for (int j = 0; j<=2*n; j++)
		for (int k = 0; k<=2*n; k++) {
			scanf("%d", &c[j][k]);
			if (c[j][k] < cm && k!=j) cm =c[j][k];
		}
}

void Try(int k) {
    // thá»­ vá»‹ trÃ­ thá»© k
    for (int j = 1; j<=n; j++) // chá»n j lÃ  khÃ¡ch káº¿ tiáº¿p
		if (!transported[j]) { 
			a[k] = j;
			transported[j]=1;
            // Ä‘i taxi Ä‘áº¿n j
            if (k==1) f += c[0][j];
			else f += c[a[k-1]+n][j];
            // Ä‘i tá»« j -> j+n
            f += c[j][j+n];
            
            //cout << f << endl;
			if (k==n) {
                f += c[j+n][0]; // vá» 0
                f_min = min(f_min, f);
            } else {
				if (f+cm*(n-k)*2 < f_min) Try(k+1);
			}
			transported[j]=0; // tra cac bien ve trang thai cu
            if (k==n) f -= c[j+n][0];
			if (k==1) f -= c[0][j];
            else f -= c[a[k-1]+n][j];
            f -= c[j][j+n];
		}
}

int main() {
    freopen("inp.inp", "r", stdin);
	input();
	f=0; f_min =1e9;	
	for (int i =1; i<=n; i++) transported[i] =false;
    Try(1);
	cout<<f_min;
	return 0;
}
