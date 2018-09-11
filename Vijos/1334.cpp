/*
f(C, Q, i) = max(f(C, Q, i - 1), f(C - x[i], Q - y[i], i - 1) + z[i])
其中C为体积上限，x[i]为物体体积
Q为质量上限，y[i]为物体质量
i为物体编号，z[i]为最大卡路里
*/
#include <cstdio>
#include <algorithm>
#include <memory.h>
#define MAX_N 53
#define MAX_C 403
#define MAX_Q 403
using namespace std;
int x[MAX_N], y[MAX_N], z[MAX_N];
int f[MAX_C][MAX_Q];
int main(){
	int C, Q, N;
	memset(f, 0, sizeof(f));
	scanf("%d%d%d", &C, &Q, &N);
	for (int i = 0;i < N;i++){
		scanf("%d%d%d", &x[i], &y[i], &z[i]);
	}
	for (int i = 0;i < N;i++){
		for (int c = C;c >= x[i];c--){
			for (int q = Q;q >= y[i];q--){
				f[c][q] = max(f[c][q], f[c - x[i]][q - y[i]] + z[i]);
			}
		}
	}
	printf("%d\n", f[C][Q]);
}