#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;
#define MAX_M 100003
#define MAX_N 504
int u[MAX_M], v[MAX_M], w[MAX_M];
int dist[MAX_M];
bool visited[MAX_M];
int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		int N, M, K;//N:节点数,M:边数,K:源
		memset(dist, -1, sizeof(dist));
		memset(visited, false, sizeof(visited));
		scanf("%d%d%d", &N, &M, &K);
		K -= 1;//消除偏移量
		dist[K] = 0;
		for (int i = 0;i < M;i++){
			scanf("%d%d%d", &u[i], &v[i], &w[i]);
			u[i] -= 1;
			v[i] -= 1;
			//printf("==%d %d %d\n", u[i], v[i], w[i]);
		}
		while (1){
			int a = -1, cost = -1;
			for (int b = 0;b < N;b++){
				if (!visited[b]){
					if (cost == -1){
						a = b;
						cost = dist[b];
					}
					else if (dist[b] < cost){
						a = b;
						cost = dist[b];
					}
				}
			}
			if (a == -1) break;//找不到没有被visit的节点，完成
			visited[a] = true;
			for (int i = 0;i < M;i++){
				if (u[i] == a){
					if (dist[v[i]] == -1) 
						if (dist[a] != -1) dist[v[i]] = dist[a] + w[i];
					else{
						if (dist[a] != -1)
							dist[v[i]] = min(dist[v[i]], dist[a] + w[i]);
					}
				}
			}
		}
		for (int i = 0;i < N;i++){
			printf("%d ", dist[i]);
		}
		printf("\n");
		int ans = 0;
		for (int i = 0;i < N;i++){
			if (dist[i] == -1){
				ans = dist[i];
				break;
			}
			else if (dist[i] > ans) ans = dist[i];//找到最大时间
		}
		printf("%d\n", ans);
	}
}