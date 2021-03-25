#include<bits/stdc++.h>
using namespace std;
struct tree {
	int a;
	int ch;
	tree* lchild;
	tree* rchild;
};
int cacl(tree* root)
{
	int a, b;
	a = root->lchild->a;
	b = root->rchild->a;
	switch (root->a)
	{
	case '+':return a + b;
	case '-':return a - b;
	case '*':return a * b;
	case '/':return a / b;
	default:return root->a;
	}
}
void visit(tree** root)
{
	if ((*root)->lchild && (*root)->rchild)
	{
		visit(&(*root)->lchild);
		visit(&(*root)->rchild);
		if (!(*root)->lchild->ch && !(*root)->rchild->ch)	//左右孩子都是数字
		{
			(*root)->a = cacl(*root);
			(*root)->lchild = NULL;
			(*root)->rchild = NULL;
			(*root)->ch = 0;
		}
	}
}
tree* creat(string s, int l, int r)
{
	tree* p;
	int k, flag = 0, pos, key = 1;
	for (int i = l; i < r && key; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			key = 0;
	}
	if (l == r || key)
	{
		int sum = 0, fa = 1;
		p = (tree*)malloc(sizeof(tree));
		for (; r >= l; r--)
		{
			sum += (s[r] - '0') * fa;
			fa *= 10;
		}
		p->ch = 0;
		p->a = sum;
		p->lchild = NULL;
		p->rchild = NULL;
		return p;
	}
	for (k = r; k >= l; k--)
	{
		if (s[k] == '+' || s[k] == '-')
		{
			flag = 1;
			pos = k;
			break;
		}

	}
	if (flag == 0)
	{
		for (k = r; k >= l; k--)
		{
			if (s[k] == '*' || s[k] == '/')
			{
				flag = 1;
				pos = k;
				break;
			}
		}
	}
	if (flag != 0)
	{
		p = (tree*)malloc(sizeof(tree));
		p->a = s[pos];
		p->ch = 1;
		p->lchild = creat(s, l, pos - 1);
		p->rchild = creat(s, pos + 1, r);
		return p;
	}
}

int main()
{
	string s;
	cin >> s;
	tree* root;
	root = creat(s, 0, s.length() - 1);
	visit(&root);
	printf("%d", root->a);
}