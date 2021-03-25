#include <iostream>
using namespace std;

const int MAXN =100001;

int N[MAXN << 1];
int findx(int x) {
	return x == N[x] ? x : N[x] = findx(N[x]);
}
void join(int x, int y) {
	int xx = findx(x);
	int yy = findx(y);
	if (xx != yy)
		N[xx] = yy;
}
int main() {
	int T;
	scanf_s("%d", &T);
	while (T--) {
		int n, m;
		scanf_s("%d%d", &n, &m);
		for (int i = 1; i <= 2 * n; i++) N[i] = i;
		while (m--) {
			char c;
			int a, b;
			while ((c = getchar()) != 'D' && c != 'A');
			scanf_s("%d%d",&a, &b);
			if (c == 'D') {
				join(a, b + n);
				join(b, a + n);
			}
			else {
				int aa = findx(a);
				int bb = findx(b);
				if (aa == bb)
					printf("In the same gang.\n"); 
				else if (aa == findx(b + n))
					printf("In different gangs.\n");
				else
					printf("Not sure yet.\n");
			}
		}

	}

}