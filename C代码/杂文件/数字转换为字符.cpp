#include<stdio.h>
#include<math.h>
char* myitoa(int a, char* b)
{
    int i = 0, j = 0;
    if (a == 0)
    {
        b[i] = '0';
        i++;
    }
    else
    {
        while (fabs(a / pow(10, j)) >= 10)            //确定位数
        {
            j++;
        }
        if (a < 0)
        {
            b[i] = '-';
            a = -a;
            i++;
        }
        while (j >= 0)
        {
            b[i] = a / (int)(pow(10, j)) + 48;
            a = a - (a / (int)pow(10, j)) * (int)pow(10, j);
            i++;
            j--;
        }
    }
    b[i] = '\0';
    return b;
}
int main(void)
{
    char str[10];
    printf("%s\n", myitoa(11, str));
    printf("%s\n", myitoa(520, str));
    printf("%s\n", myitoa(-1234, str));

    return 0;
}