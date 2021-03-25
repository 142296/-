#include<stdio.h>

struct Date {
	int year;
	int month;
	int day;
};
struct Book
{
	char title[128];
	char author[40];
	float price;
	struct Date date;
	char pubilsher[40];
};
struct Book getInput(struct Book book)           //返回结构体的函数
{												//传入结构返回;
	//操偶作代码
	return book;
}
void get(Book* a)							//传入地址直接操作
{//操作代码;
}

int main()
{
	struct Book book;
	get(&book);
}