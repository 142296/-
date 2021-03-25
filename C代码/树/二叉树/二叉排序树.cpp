#include<bits/stdc++.h>
using namespace std;
struct binary_sort_tree
{
	int num;
	binary_sort_tree* left;
	binary_sort_tree* right;
};

int Count = 0;
void mid_visit(binary_sort_tree* head)
{
	if (head)
	{
		mid_visit(head->left);
		printf("%-3d", head->num);
		mid_visit(head->right);
	}
}
int main()
{
	srand(time(0));
	binary_sort_tree* head,*move;
	head = new binary_sort_tree();

	while (Count < 100)
	{
		int n = rand() % 100;
		move = head;
		while (move)
		{
			if (n < move->num)
			{
				if (move->left)
					move = move->left;
				else
				{
					move->left = new binary_sort_tree();
					move = move->left;
					move->num = n;
				}
			}
			else if (n > move->num)
			{
				if (move->right)
					move = move->right;
				else
				{
					move->right = new binary_sort_tree();
					move = move->right;
					move->num = n;
				}
			}
			else
				break;
		}
		Count++;
	}
	move = head;
	mid_visit(move);
}