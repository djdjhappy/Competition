#include <cstdio>
#define MAX_ARR 32
using namespace std;
char arr[MAX_ARR][MAX_ARR];
char word[MAX_ARR];
int main(){
    int M, N, K;
    scanf("%d%d", &N, &M);
    for (int n = 0;n < N;n++){
        scanf("%s", arr[n]);
    }
    scanf("%d", &K);
    for (int k = 0;k < K;k++){
        int len = 0, Yes = 0;
        scanf("%s", word);
        for (;word[len] != '\0';++len);
        for (int n = 0;n < N;n++){
            for (int m = 0;m <= M - len;m++){
                bool eq = true;
                for (int i = 0;i < len;i++){
                    if (word[i] != arr[n][m + i]){
                       eq = false;
                       break;
                    }
                }
                if (eq){
                   printf("YES\n");
                   Yes = 1;
                   break;
                }
            }
            
            if (Yes) break;
        }
        if (!Yes)
            for (int m = 0;m < M;m++){
                for (int n = 0;n <= N - len;n++){
                    bool eq = true;
                    for (int i = 0;i < len;i++){
                        if (word[i] != arr[n + i][m]){
                           eq = false;
                           break;
                        }
                    }
                    if (eq){
                       printf("YES\n");
                       Yes = 1;
                       break;
                    }
                }
                
                if (Yes) break;
            }
        if (!Yes) printf("NO\n");
    }
    
}
