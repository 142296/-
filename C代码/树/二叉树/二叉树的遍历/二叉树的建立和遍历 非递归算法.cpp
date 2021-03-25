#include<stdio.h>
#include<stdlib.h>

struct list {
	char data;
	int key;
	list* lchild, * rchild;
};
void creat_tree(list** tree_head)			//前序遍历赋值
{
	char c;
	scanf_s("%c", &c);
	if (c == '#')
	{
		(*tree_head) = NULL;
	}
	else {
		(*tree_head) = (list*)malloc(sizeof(list));
		(*tree_head)->data = c;
		(*tree_head)->key = 0;
		creat_tree(&(*tree_head)->lchild);
		creat_tree(&(*tree_head)->rchild);
	}
}
void show(list* tree_head) {
	printf("%c ", tree_head->data);
}
void visit1_tree(list* tree_head)				//前序遍历
{
	list* head[60];
	int top = -1, bot = -1;
	while (tree_head)
	{
		show(tree_head);
		if (tree_head->lchild)   //左子树不为空
		{
			top++;
			head[top] = tree_head->rchild;		//右子树入栈
			tree_head = tree_head->lchild;
		}
		else  //左子树为空
		{
			if (tree_head->rchild)		//右子树不为空
			{
				tree_head = tree_head->rchild;
			}
			else						//左右子树都为空 
			{
				if (top == bot)
					break;
				tree_head = head[top];				//弹栈
				top--;
			}
		}
	}
}
void visit2_tree(list* tree_head)				//中序遍历
{
	list* head[60], * temp;
	int top = -1, bot = -1;
	top++;
	head[top] = tree_head;
	while (1)
	{
		while ((temp = head[top]) && temp)			//取得栈顶元素并保证不为空
		{
			top++;
			head[top] = temp->lchild;			//左子树入栈
		}
		top--;									//弹出NULL元素
		if (top != bot)							//栈非空
		{
			show(head[top]);					//输出栈顶元素(必定没有左子树)
			head[top] = head[top]->rchild;		//栈顶元素的右子树代替栈顶元素     
		}
		if (top == bot)
			break;
	}
}
void visit3_tree(list* tree_head)				//后序遍历
{
	list* head[60], * temp = NULL;
	int top = -1, bot = -1;
	top++;
	head[top] = tree_head;
	while (1)
	{
		while ((temp = head[top]) && temp)
		{
			top++;
			head[top] = temp->lchild;
		}
		top--;
		if (top != bot)
		{
			while (top >= 0 && head[top]->key)
			{
				show(head[top]);
				head[top]->key = 0;		//key复原，不影响下次遍历
				top--;
			}
			if (top == bot)
				break;
			else
			{
				head[top]->key = 1;
				top++;
				head[top] = head[top - 1]->rchild;
			}
		}
	}
}
int main()
{
	list* tree_head;
	creat_tree(&tree_head);
	int n;
	list* move = tree_head;
	while (1)
	{
		printf("1.前序 2.中序 3.后序");
		printf("请输入选择:");
		scanf_s("%d", &n);
		switch (n) {
		case 1: visit1_tree(move); move = tree_head; break;
		case 2: visit2_tree(move); move = tree_head; break;
		case 3: visit3_tree(move); move = tree_head; break;
		default:break;
		}
		putchar('\n');

	}
}