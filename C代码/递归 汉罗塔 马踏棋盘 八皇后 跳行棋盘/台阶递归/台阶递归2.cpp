#include<iostream>
using namespace std;
int sum = 0;
long count1 = 0;
const long Max = 33335;
int a[Max];
int recurison(int n);
int main()
{
    int n;
    cin >> n;
    if (n <= 0)
        cout << 0 << endl;
    else if (n < 4)
        cout << 1 << endl;
    else
    {
        for (int i = 1; i <= n; i += 3)//把最后一步所走的台阶数的可能情况存入数组a中
            a[count1++] = i;
        recurison(n);
        cout << sum << endl;
    }
    return 0;
}
int recurison(int n)
{
    if (n < 0)
        return 0;
    if (n >= 0 && n < 4) return 1;
    else
        for (int i = 0; i < count1; i++)
        {
            sum += recurison(n - a[i]) % 100003;
            sum %= 100003;
        }
    return 0;
}
