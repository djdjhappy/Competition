//f(C, i) = max(f(C, i - 1), f(C - v[i], i - 1) + v[i] * p[i])
#include <cstdio>
#include <algorithm>
#include <memory.h>
#define MAX_N 30003
#define MAX_m 27
using namespace std;
int v[MAX_m], p[MAX_m];
int f[MAX_N];
int main(){
	int N, m;
	memset(f, 0, sizeof(f));
	scanf("%d%d", &N, &m);
	for (int i = 0;i < m;i++){
		scanf("%d%d", &v[i], &p[i]);
	}
	for (int i = 0;i < m;i++){
		for (int c = N;c >= v[i];c--){
			f[c] = max(f[c], f[c - v[i]] + v[i] * p[i]);
		}
	}
	printf("%d\n", f[N]);
}