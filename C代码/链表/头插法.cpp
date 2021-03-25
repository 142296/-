#include<stdio.h>
#include<stdlib.h>

struct Contacts
{
	char name;
	int tel;
	Contacts* next;
};
void getinput(Contacts* contacts)
{
	getchar();
	printf("请输入名字首字母");
	scanf_s("%c", &contacts->name);
	getchar();
	printf("请输入电话:");
	scanf_s("%d", &contacts->tel);
	getchar();
}
void addmember(Contacts** head)         //指针通过地址改变地址上的东西	//要改变contacts地址上储存的东西 就要指针指向contacts的地址  
{                                       //*(*head) 储存&地址                //&contacts是contacts的地址
										//*head   储存contacts地址         //contacts地址上储存的是另一个地址  
	Contacts* contacts, * temp;              //定义要插入的结构
	contacts = (Contacts*)malloc(sizeof(Contacts));
	getinput(contacts);
	/*下面的注释     头指向新的结构体，
	新的结构体的尾指向前一个结构体*/
	temp = *head;                 //实际上是temp=&contacts  所以temp不会随*head改变而改变
	*head = contacts;				//即Contacts **head =contacts,**head即contacts地址上储存的东西(NULL)改变
	contacts->next = temp;
}
void out(Contacts* contacts)
{
	while (contacts != NULL)
	{
		printf("%c:%d", contacts->name, contacts->tel);
		contacts = contacts->next;
	}
}
void release(Contacts** contacts)        //指针通过地址改变地址上的东西	//要改变contacts地址上储存的东西 就要指针指向contacts的地址
{
	Contacts* temp = NULL;
	while ((*contacts)->next != NULL)
	{
		temp = (*contacts)->next;
		free(*contacts);
		*contacts = temp;
	}
}
int main()
{
	char ch;
	Contacts* contacts = NULL;                 //定义一个头
	while (1)
	{
		printf("是否要继续输入联系人");
		scanf_s("%c", &ch);
		if (ch == 'Y')
			addmember(&contacts);
		else
			break;

	}
	out(contacts);
	release(&contacts);
}