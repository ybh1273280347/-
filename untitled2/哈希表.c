#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
//设置哈希集合，只存储键，不存储值
//声明链表
struct List {
    int val;
    struct List *next;
};

//做头插
void listPush(struct List *head, int x) {
    struct List *tmp = malloc(sizeof(struct List));
    tmp->val = x;
    tmp->next = head->next;
    head->next = tmp;
}

//删除链表中的值为x的结点
void listDelete(struct List *head, int x) {
    for (struct List *it = head; it->next; it = it->next) {
        if (it->next->val == x) {
            struct List *tmp = it->next;
            it->next = tmp->next;
            free(tmp);
            break;
        }
    }
}

//检查链表中是否含有某个值
bool listContains(struct List *head, int x) {
    for (struct List *it = head; it->next; it = it->next) {
        if (it->next->val == x) {
            return true;
        }
    }
    return false;
}

//销毁链表，注意链表是有多个内存的，要逐一释放
void listFree(struct List *head) {
    while (head->next) {//只要首元结点不是空，就释放它
        struct List *tmp = head->next;
        head->next = tmp->next;
        free(tmp);
    }
}

//只要是一个质数就行，创建769个抽屉
const int base = 769;
//建立哈希函数
int hash(int key) {
    return key % base;
}

//声明哈希表，表中用指针的形式声明了一个链表数组
typedef struct {
    struct List *data;
} MyHashSet;

//初始化哈希表
MyHashSet *myHashSetCreate() {
    MyHashSet *ret = malloc(sizeof(MyHashSet));
    ret->data = malloc(sizeof(struct List) * base); //链表中存储了base个抽屉
    //对每个抽屉初始化
    for (int i = 0; i < base; i++) {
        ret->data[i].val = 0; //这里要注意，data后加了索引就相当于对指针解引用了了，用.运算符而不是->
        ret->data[i].next = NULL;
    }
    return ret;
}

//用用映射值表示抽屉的索引
void myHashSetAdd(MyHashSet *obj, int key) {
    int h = hash(key);
    if (!listContains(&(obj->data[h]), key)) {
        listPush(&(obj->data[h]), key);
    }
}

//移除某个键
void myHashSetRemove(MyHashSet *obj, int key) {
    int h = hash(key);
    listDelete(&(obj->data[h]), key);
}

bool myHashSetContains(MyHashSet *obj, int key) {
    int h = hash(key);
    return listContains(&(obj->data[h]), key);
}
//链表数组需要逐个遍历销毁
void myHashSetFree(MyHashSet *obj) {
    for (int i = 0; i < base; i++) {
        listFree(&(obj->data[i]));//free只能销毁指针，而这里只是数组元素
    }//释放数组中的每个链表元素
    free(obj->data);//释放数组名
    free(obj);//释放哈希结构体
}

int main() {
    return 0;
}
