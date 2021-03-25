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
	printf("��������������ĸ");
	scanf_s("%c", &contacts->name);
	getchar();
	printf("������绰:");
	scanf_s("%d", &contacts->tel);
	getchar();
}
void addmember(Contacts** head)         //ָ��ͨ����ַ�ı��ַ�ϵĶ���	//Ҫ�ı�contacts��ַ�ϴ���Ķ��� ��Ҫָ��ָ��contacts�ĵ�ַ  
{                                       //*(*head) ����&��ַ                //&contacts��contacts�ĵ�ַ
										//*head   ����contacts��ַ         //contacts��ַ�ϴ��������һ����ַ  
	Contacts* contacts, * temp;              //����Ҫ����Ľṹ
	contacts = (Contacts*)malloc(sizeof(Contacts));
	getinput(contacts);
	/*�����ע��     ͷָ���µĽṹ�壬
	�µĽṹ���βָ��ǰһ���ṹ��*/
	temp = *head;                 //ʵ������temp=&contacts  ����temp������*head�ı���ı�
	*head = contacts;				//��Contacts **head =contacts,**head��contacts��ַ�ϴ���Ķ���(NULL)�ı�
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
void release(Contacts** contacts)        //ָ��ͨ����ַ�ı��ַ�ϵĶ���	//Ҫ�ı�contacts��ַ�ϴ���Ķ��� ��Ҫָ��ָ��contacts�ĵ�ַ
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
	Contacts* contacts = NULL;                 //����һ��ͷ
	while (1)
	{
		printf("�Ƿ�Ҫ����������ϵ��");
		scanf_s("%c", &ch);
		if (ch == 'Y')
			addmember(&contacts);
		else
			break;

	}
	out(contacts);
	release(&contacts);
}