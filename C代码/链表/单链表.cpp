#include<iostream>
using namespace std;
struct make {
	int data;
	make* next;
};
int main()
{
	make* head, a, * out;
	make* ad, * temp;
	head = &a;
	a.data = -1;
	a.next = NULL;
	for (int i = 0; i < 10; i++)
	{
		ad = (make*)malloc(sizeof(make));
		temp = head;
		head = ad;
		ad->next = temp;
		ad->data = i;
	}
	out = head;
	make into;
	into.data = 5;
	while (out->next && out->next->data != into.data)
	{
		out = out->next;
	}
	//temp = out->next;
	//out->next = &into;   ¼ÓÈë
	//into.next = temp;
	out->next = out->next->next;    //É¾³ý
	out = head;
	while (out != NULL)
	{
		printf("%d\n", out->data);
		out = out->next;
	}
}