#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
int v[32];
int f[20002];
int main(){
	int C, n;
	memset(f, 0, sizeof(f));
	scanf("%d%d", &C, &n);
	for (int i = 0;i < n;i++)
		scanf("%d", &v[i]);
	for (int i = 0;i < n;i++){
		for (int c = C;c >= v[i];c--){
			f[c] = max(f[c], f[c - v[i]] + v[i]);
		}
	}
	printf("%d\n", C - f[C]);
}