#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX 1000

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

enum Option
{
	EXIT,//0
	ADD,//1
	DEL,//2
	SEARCH,//3
	MODIFY,//4
	SHOW,//5
	SORT//6
};
//����ͨѶ¼
struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

struct Contact
{
	struct PeoInfo date[MAX];
	int size;
};

//����
//��ʼ��ͨѶ¼
void InitContact(struct Contact* ps);
//����
void AddContact(struct Contact* ps);
//��ӡ
void ShowContact(struct Contact* ps); 
//ɾ��
void DelContact(struct Contact* ps);
//����
void SearchContact(struct Contact* ps);
//�޸�
void ModifyContact(struct Contact* ps);
//����
void SortContact(struct Contact* ps);