#include <iostream>
using namespace std;
const int INIT_SIZE = 100;
const int INCREASE = 10;
typedef struct
{
    string id;
    string name;
} student;
typedef struct
{
    student *baseAddress; //������׵�ַ����Ϊ������洢��ֻ��Ҫ�����׵�ַ����
    int length;           //����ĳ���
    int listSize;         //����ǰ�����������
} SqList;
void InitList(SqList &L)
{
    L.baseAddress = new student[INIT_SIZE]; //��̬����ռ䣬��һ��new���÷�
    L.length = 0;
    L.listSize = INIT_SIZE;
}
void Insert(SqList &L, student &item, int index)
{
    if (index < 0 || index > L.length)
    {
        cout << " ����λ�ò��Ϸ�������������" << endl;
        return;
    }
    if (L.length >= L.listSize)
    {
        student *newAddress = new student[L.listSize + INIT_SIZE]; //�����ǰ����������Ѿ�����
        for (int i = 0; i < L.length; i++)
        {
            newAddress[i] = L.baseAddress[i]; //Ǩ�����ݵ��µ�����
        }
        L.listSize = L.listSize + INIT_SIZE;
        L.baseAddress = newAddress;
        L.length++;
    }
    for (int i = L.length - 1; i >= index; i--)
    {
        L.baseAddress[i + 1] = L.baseAddress[i]; //��index�����Ԫ������ƣ�����Ԫ���ڵط�
    }
    L.baseAddress[index] = item;
    L.length++;
}
void Delete(SqList &L, int index)
{
    if (index < 0 || index >= L.length)
    {
        cout << "ɾ��λ�ò��Ϸ�������������" << endl;
    }
    for (int i = index; i < L.length; i++)
    {
        L.baseAddress[i - 1] = L.baseAddress[i]; //��index��һ��Ԫ�ظ���ǰһ��Ԫ�أ��͵���ɾ����
    }
    L.length--;
}
void print(SqList &L)
{
    for (int i = 0; i < L.length; i++)
    {
        cout << "ѧ��:" << L.baseAddress[i].id << "����:" << L.baseAddress[i].name << endl;
    }
}
int main()
{
    SqList L;
    InitList(L);
    string name, id, order;
    int index;
    while (1)
    {
        cout << "����������(����-insert|ɾ��-delete)" << endl;
        cin >> order;
        if (order[0] == 'i')
        {
            cout << "������ѧ��" << endl;
            cin >> id;
            cout << "����������" << endl;
            cin >> name;
            cout << "���������λ��" << endl;
            cin >> index;
            student item;
            item.id = id;
            item.name = name;
            Insert(L, item, index);
            print(L);
        }
        else
        {
            cout << "������ɾ����λ��" << endl;
            cin >> index;
            Delete(L, index);
            print(L);
        }
    }
}