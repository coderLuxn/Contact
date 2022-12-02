#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"

void InitContact(struct Contact* ps)
{
	memset(ps->date, 0, sizeof(ps->date));
	ps->size = 0;
}

void AddContact(struct Contact* ps)
{
	if (ps->size == MAX)
	{
		printf("ͨѶ¼����");
	}
	else
	{
		printf("���������֣�");
		scanf("%s", ps->date[ps->size].name);
		printf("���������䣺");
		scanf("%d", &(ps->date[ps->size].age));
		printf("�������Ա�");
		scanf("%s", ps->date[ps->size].sex);
		printf("��������룺");
		scanf("%s", ps->date[ps->size].tele);
		printf("�������ַ��");
		scanf("%s", ps->date[ps->size].addr);
		ps->size++;
		printf("���ӳɹ�\n");
	}
}

void ShowContact(struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		int i = 0;
		for(i=0;i<ps->size;i++)
		{
			//1.�ȴ�ӡ����
			printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\t\n",
				"����", "����", "�Ա�", "����", "��ַ");
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-30s\t\n",
				ps->date[i].name,
				ps->date[i].age,
				ps->date[i].sex,
				ps->date[i].tele,
				ps->date[i].addr);
		}
	}
}

static int FindByContact(struct Contact* ps,char* name)//ֻ���ڲ�����
{
	int pos = 0;
	for (pos = 0; pos < ps->size; pos++)
	{
		if (0 == strcmp(name, ps->date[pos].name))
		{
			break;
		}
	}
	if (pos == ps->size)
	{
		return -1;
	}
	else
	{
		return pos;
	}
}

void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫɾ�������֣�");
	scanf("%s", name);
	int pos=FindByContact(ps, name);//�ҵ������±꣬�Ҳ�������-1
	//iѭ����û���ҵ�������
	if (pos==-1)
	{
		printf("û�и�����\n");
	}
	else
	{
		int j = 0;  
		for (j = pos; j <ps->size-1; j++)
		{
			ps->date[j] = ps->date[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�\n");
	}
}

void SearchContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ���ҵ����֣�");
	scanf("%s", name);
	int pos = FindByContact(ps, name);
	if (pos == -1)
	{
		printf("û���ҵ�\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\t\n", 
			"����", "����", "�Ա�", "����", "��ַ");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-30s\t\n",
			ps->date[pos].name,
			ps->date[pos].age,
			ps->date[pos].sex,
			ps->date[pos].tele,
			ps->date[pos].addr);
	}
}

void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ�޸ĵ����֣�");
	scanf("%s", name);
	int pos = FindByContact(ps, name);
	if (pos == -1)
	{
		printf("û���ҵ�\n");
	}
	else
	{
		printf("���������֣�");
		scanf("%s", ps->date[pos].name);
		printf("���������䣺");
		scanf("%d", &(ps->date[pos].age));
		printf("�������Ա�");
		scanf("%s", ps->date[pos].sex);
		printf("��������룺");
		scanf("%s", ps->date[pos].tele);
		printf("�������ַ��");
		scanf("%s", ps->date[pos].addr);
	}
}

//int int_cmp(const void* e1, const void* e2)
//{
//	//return strcmp(((struct Stu*)e1)->name , ((struct Stu*)e2)->name);
//	//((struct Stu*)e1)->age - ((struct Stu*)e2)->age
//	return ((struct Contact*)e1)->date->age- ((struct Contact*)e2)->date->age;
//}
//void SortContact(struct Contact* ps)
//{
//	//void qsort( 
//	//void *base,//��Ԫ�ص�ַ
//	//size_t num,//����sizeof(date) 
//	//size_t width, 
//	//int (cdecl *compare )(const void *elem1, const void *elem2 ) );
//     qsort(ps, ps->size, sizeof(ps->date[0]), int_cmp);
//}

int int_compare(const void* e1, const void* e2)
{
	return (((struct Contact*)e1)->date->age - ((struct Contact*)e2)->date->age);
}

void Swap(char* buf1, char* buf2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		int tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}

                                      //���
void bubble_sort(void* ps, int size, int width, 
	int(*compare)(const void* e1, const void* e2))
{
	int i = 0;//����
	for (i = 0; i < size;i++)
	{
		int j = 0;//һ�п����߶��ٴ�
		for (j = 0; j < size - 1 - i; j++)
		{
			//��һ���ֽں͵�width���ֽڱȽ�
			if (int_compare((char*)ps + j * width, (char*)ps + (j + 1) * width) > 0)
			{
				Swap((char*)ps + j * width, (char*)ps + (j + 1) * width,width);
			}
		}
	}
}

void SortContact(struct Contact* ps)
{
	bubble_sort(ps, ps->size, sizeof(ps->date[0]), int_compare);
}