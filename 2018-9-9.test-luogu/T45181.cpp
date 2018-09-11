#include <cstdio>
#include <algorithm>
using namespace std;
char cmd[302]; 
const char commands[6] = "UDLR";
int command_dx(char c){
    if (c == 'U') return 0;
    else if (c == 'D') return 0;
    else if (c == 'L') return -1;
    else return 1;
}
int command_dy(char c){
    if (c == 'U') return 1;
    else if (c == 'D') return -1;
    else if (c == 'L') return 0;
    else return 0;
}
int algo(char* cmd, int k, int x, int y){ 
    if ((*cmd) == '\0') return 0;
    int ans = 0;
    if (k > 0){
       for (int i = 0;i < 4;i++){
           if (commands[i] != cmd[0]){
              ans = max(ans, algo(cmd + 1, k - 1, command_dx(commands[i]) + x, command_dy(commands[i]) + y));
           }
           else
               ans = max(ans, algo(cmd + 1, k, command_dx(commands[i]) + x, command_dy(commands[i]) + y));
       }
    }
    else{
         ans = max(ans, algo(cmd + 1, k, command_dx(cmd[0]) + x, command_dy(cmd[0]) + y));
    }
    //printf(">%d\n", ans + int(x == y));
    return ans + int(x == y == 0);
}
int main(){
    int K;
    scanf("%s%d", cmd, &K);
    printf("%d\n", algo(cmd, K, 0, 0));
}
