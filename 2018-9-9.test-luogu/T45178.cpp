#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int a, b, c, x, y, ans = 0;
    cin >> a >> b >> c >> x >> y;
    for (int l = 0;x >= l;l++){
        for (int m = 0;x - l >= m;m++){
            for (int n = 0;x - l - m >= n;n++){
                if (a * l + b * m + c * n == y){
                      if (l + m + n == x)
                         ans++;
                }
            }
        }
    }
    cout << ans << endl;
}
