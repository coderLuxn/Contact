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
//创建通讯录
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

//声明
//初始化通讯录
void InitContact(struct Contact* ps);
//增加
void AddContact(struct Contact* ps);
//打印
void ShowContact(struct Contact* ps); 
//删除
void DelContact(struct Contact* ps);
//查找
void SearchContact(struct Contact* ps);
//修改
void ModifyContact(struct Contact* ps);
//排序
void SortContact(struct Contact* ps);