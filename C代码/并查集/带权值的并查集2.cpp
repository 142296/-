#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 0xffffff;
const int maxn = 100001;
int fa[maxn];
int sum[maxn];
int n, m;
int Find(int x) {
    if (fa[x] == x) return x;
    int t = fa[x];
    fa[x] = Find(fa[x]);
    sum[x] = (sum[x] + sum[t]) % 2;
    return fa[x];
}
void Merge(int x, int y) {
    int xx = Find(x);
    int yy = Find(y);
    if (xx != yy) {
        fa[xx] = yy;
        sum[xx] = (sum[y] + sum[x] + 1) % 2;
    }

}
int main() {
    int T, a, b;
    scanf_s("%d", &T);
    while (T--) {
        memset(sum, 0, sizeof(sum));    //数组初始化为0
        scanf_s("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) fa[i] = i;
        while (m--) {
            char ch;
            while ((ch = getchar()) != 'D' && ch != 'A');
            scanf_s("%d %d", &a, &b);
            if (ch == 'A') {
                int x = Find(a), y = Find(b);
                if (n == 2) printf("In different gangs.\n");
                else if (x == y) {
                    if (sum[a] != sum[b]) printf("In different gangs.\n");
                    else printf("In the same gang.\n");
                }
                else printf("Not sure yet.\n");
            }
            else {
                Merge(a, b);

            }
        }
    }
    return 0;
}

