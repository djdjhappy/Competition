#include <stdio.h>
const int num[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int main(){
	int d, ans = 0;
	while ((d = getchar()) != '\n'){
		ans += num[d - '0'];
	}
	printf("%d\n", ans);
}
