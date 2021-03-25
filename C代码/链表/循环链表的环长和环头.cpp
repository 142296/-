#include<bits/stdc++.h>			//计算链环的长度和环的起点
struct cir {					//快慢指针
	int data;
	cir* next;
};
int main()
{
	cir *move,* head = new cir();
	move = head;
	for (int i = 1; i < 50; i++)
	{
		cir* link = new cir();
		link->data = i;;
		link->next = NULL;
		move->next = link;
		move = link;
	}
	cir* move1=head;
	for (int i = 0; i < 10; i++)
		move1 = move1->next;
	move->next = move1;
	cir* fast, *slow;
	fast = slow = head;
	int f = 0, s = 0;
	do{
		fast = fast->next->next;
		slow = slow->next;
		f += 2;
		s += 1;
	} while (fast != slow);
	int n = f - s;				//环长
	int x = 49 - n;		//环外长
	int y = s - x;		//前半环
	int z = 49 - s;		//后半环
	//s*2==f
	//(x+y)*2==x+y+圈数*(y+z)
	//x+y==圈数*(y+z)
	//x==(圈数-1)*(y+z)+z
	//y+z为环长n
	//所以
	//x == z;

}