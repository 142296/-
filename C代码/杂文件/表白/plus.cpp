#include<stdio.h>
#include<math.h>
#include<time.h>
#include<string.h>
int main()
{
    printf("\n\n\n\n");
    printf("\t\tºô£¬");
    int begin = clock();
    while (clock() - begin <= 800);
    begin = clock();
    char a[] = "ÈÕ³£ÏëÄã 2020-12-6 20:51:17";
    int length = strlen(a);
    for (int i = 0, j = 0; i < length; j++)
    {
        while (clock() - begin <= 600);
        begin = clock();
        printf("%c%c", a[i], a[i + 1]);
        i += 2;
        while (clock() - begin <= 200);
        begin = clock();
        printf("%c%c", a[i], a[i + 1]);
        i += 2;
        if (j % 2)
        {
            printf("%c", a[i]);
            i++;
        }
    }
    float y, x, z;
    for (double y = 2.5; y >= -1.6; y = y - 0.2)
    {

        for (double x = -3; x <= 4.8; x = x + 0.1)
        {

            if (pow((x * x + y * y - 1), 3) <= (3.6 * x * x * y * y * y))
            {
                printf("*"); while (clock() - begin <= 30);
                begin = clock();
            }
            else
                printf(" ");
        }

        printf("\n");
    }

    getchar();
}