#include<stdio.h>
#include<stdlib.h>

struct list {
	char data;
	list* lchild, * rchild;
};
void creat_tree(list** tree_head)				//前序遍历赋值
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
		creat_tree(&(*tree_head)->lchild);
		creat_tree(&(*tree_head)->rchild);
	}
}
void show(list* tree_head, int level) {
	printf("%c 在%d 层\n", tree_head->data, level);
}
void visit1_tree(list* tree_head, int level)				//前序遍历
{
	if (tree_head)
	{
		show(tree_head, level);
		visit_tree(tree_head->lchild, level + 1);
		visit_tree(tree_head->rchild, level + 1);
	}
}
void visit2_tree(list* tree_head, int level)				//中序遍历
{
	if (tree_head)
	{
		visit_tree(tree_head->lchild, level + 1);
		show(tree_head, level);
		visit_tree(tree_head->rchild, level + 1);
	}
}
void visit3_tree(list* tree_head, int level)				//后序遍历
{
	if (tree_head)
	{
		visit_tree(tree_head->lchild, level + 1);
		visit_tree(tree_head->rchild, level + 1);
		show(tree_head, level);
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
		switch (n)
			case 1: visit1_tree(move, 1); move = tree_head; break;
			case 2: visit2_tree(move, 1); move = tree_head; break;
			case 3: visit3_tree(move, 1); move = tree_head; break;
			default:break;
	}
}