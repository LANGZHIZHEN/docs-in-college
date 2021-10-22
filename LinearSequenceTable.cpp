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
    student *baseAddress; //链表的首地址，因为是数组存储，只需要保存首地址即可
    int length;           //链表的长度
    int listSize;         //链表当前被分配的容量
} SqList;
void InitList(SqList &L)
{
    L.baseAddress = new student[INIT_SIZE]; //动态分配空间，查一下new的用法
    L.length = 0;
    L.listSize = INIT_SIZE;
}
void Insert(SqList &L, student &item, int index)
{
    if (index < 0 || index > L.length)
    {
        cout << " 插入位置不合法，请重新输入" << endl;
        return;
    }
    if (L.length >= L.listSize)
    {
        student *newAddress = new student[L.listSize + INIT_SIZE]; //如果当前链表的容量已经满了
        for (int i = 0; i < L.length; i++)
        {
            newAddress[i] = L.baseAddress[i]; //迁移数据到新的链表
        }
        L.listSize = L.listSize + INIT_SIZE;
        L.baseAddress = newAddress;
        L.length++;
    }
    for (int i = L.length - 1; i >= index; i--)
    {
        L.baseAddress[i + 1] = L.baseAddress[i]; //将index后面的元素向后移，给新元素腾地方
    }
    L.baseAddress[index] = item;
    L.length++;
}
void Delete(SqList &L, int index)
{
    if (index < 0 || index >= L.length)
    {
        cout << "删除位置不合法，请重新输入" << endl;
    }
    for (int i = index; i < L.length; i++)
    {
        L.baseAddress[i - 1] = L.baseAddress[i]; //让index后一个元素覆盖前一个元素，就等于删除了
    }
    L.length--;
}
void print(SqList &L)
{
    for (int i = 0; i < L.length; i++)
    {
        cout << "学号:" << L.baseAddress[i].id << "姓名:" << L.baseAddress[i].name << endl;
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
        cout << "请输入命令(插入-insert|删除-delete)" << endl;
        cin >> order;
        if (order[0] == 'i')
        {
            cout << "请输入学号" << endl;
            cin >> id;
            cout << "请输入姓名" << endl;
            cin >> name;
            cout << "请输出插入位置" << endl;
            cin >> index;
            student item;
            item.id = id;
            item.name = name;
            Insert(L, item, index);
            print(L);
        }
        else
        {
            cout << "请输入删除的位置" << endl;
            cin >> index;
            Delete(L, index);
            print(L);
        }
    }
}