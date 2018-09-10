#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
int w[103], v[103];
int f[1003];
int main(){
	int T, M;
	memset(f, 0, sizeof(f));
	scanf("%d%d", &T, &M);
	for (int i = 0;i < M;i++){
		scanf("%d%d", &w[i], &v[i]);
	}
	for (int i = 0;i < M;i++){
		for (int c = T;c >= w[i];c--){
			f[c] = max(f[c], f[c - w[i]] + v[i]);
		}
	}
	printf("%d\n", f[T]);
}
