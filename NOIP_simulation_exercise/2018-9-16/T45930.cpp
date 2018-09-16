#include <stdio.h>
const int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main(){
	int m1, d1, m2, d2;
	int ans = 0;
	scanf("%d%d%d%d", &m1, &d1, &m2, &d2);
	while (m2 != m1){
		ans += days[m2 - 1];
		m2--;
	}
	ans += d2 - d1;
	printf("%d\n", ans);
}