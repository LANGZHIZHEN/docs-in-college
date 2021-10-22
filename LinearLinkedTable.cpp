#include <iostream>
using namespace std;
typedef struct LNode
{
    string id;
    string name;
    LNode *next;
} LNode, *LinkedList;
void InitList(LinkedList &L)
{
    L = (LinkedList) new LNode;
    L->next = NULL;
}
void Insert(LinkedList &L, string id, string name)
{
    LNode *p = new LNode;
    p->id = id;
    p->name = name;
    p->next = L->next;
    L->next = p;
}
void Delete(LinkedList &L, string id)
{
    LNode *p = L;
    while (p->next->id != id)
        p = p->next;
    LNode *s = p->next;
    p->next = s->next;
    free(s);
}
void print(LinkedList &L)
{
    LNode *p = L->next;
    while (p != NULL)
    {
        cout << "Ñ§ºÅ:" << p->id << "ÐÕÃû:" << p->name << endl;
        p = p->next;
    }
}
int main()
{
    LinkedList L;
    InitList(L);
    string name, id, order;
    while (1)
    {
        cout << "ÇëÊäÈëÃüÁî(²åÈë-insert|É¾³ý-delete)" << endl;
        cin >> order;
        if (order == "insert")
        {
            cout << "ÇëÊäÈëÑ§ºÅ" << endl;
            cin >> id;
            cout << "ÇëÊäÈëÐÕÃû" << endl;
            cin >> name;
            Insert(L, id, name);
            print(L);
        }
        else if (order == "delete")
        {
            cout << "ÇëÊäÈëÉ¾³ýµÄÑ§ºÅ" << endl;
            cin >> name;
            Delete(L, name);
            print(L);
        }
        else
        {
            cout << "ÇëÖØÐÂÊäÈë" << endl;
        }
    }
}