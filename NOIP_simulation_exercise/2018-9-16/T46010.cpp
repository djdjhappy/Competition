#include <stdio.h>
#include <memory.h>
int num[54];//每个位代表此处可能有的状态个数
int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		for (int j = 0;j < 52;j++){
			num[j] = 1;
		}
		int N;
		long int ans = 1;
		scanf("%d", &N);
		for (int i = 0;i < N;i++){
			int x;scanf("%d", &x);
			int pow = 0;
			while(x >>= 1) pow += 1;
			num[pow] += 1;
		}
		for (int j = 0;j < 52;j++){
			ans *= num[j];
		}
		printf("%ld\n", ans);
	}
}