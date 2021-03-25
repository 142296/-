#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	double result = sqrt(3.0);
	cout << "对根号三保留小数点后0~9位，";
	for (int i = 0; i <= 9; i++)
	{
		cout.precision(i);   //以下的数保留i位
		cout << result << endl;
	}
	cout << result;
}