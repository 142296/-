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
struct Book getInput(struct Book book)           //���ؽṹ��ĺ���
{												//����ṹ����;
	//��ż������
	return book;
}
void get(Book* a)							//�����ֱַ�Ӳ���
{//��������;
}

int main()
{
	struct Book book;
	get(&book);
}