#include<iostream>

using namespace std;

const int N = 100010, M = 1000010;

int n, m;
char s[M], p[N];
int ne[N];

int main() {

    cin >> n >> p + 1 >> m >> s + 1;
    //求next数组过程
    for (int i = 2, j = 0; i <= n; i++) {
        while (j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) j++;
        ne[i] = j;
    }
    //KMP匹配过程
    for (int i = 1, j = 0; i <= m; i++) {
        while (j && s[i] != p[j + 1]) j = ne[j];
        if (p[j + 1] == s[i]) j++;

        if (j == n) {
            printf("%d ", i - n);
            j = ne[j];
        }
    }
    return 0;
}
作者：zwhy
链接：https ://www.acwing.com/activity/content/code/content/1463244/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。