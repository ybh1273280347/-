#include <stdio.h>
#include <stdlib.h>
//设置哈希映射（既存储键，也存储值）
//由于哈希映射由两个值决定，所以链表中同时存储了键值和映射值
struct List {
    int key;
    int val;
    struct List* next;
};

void listPush(struct List* head, int key, int val) {
    struct List* tmp = malloc(sizeof(struct List));
    tmp->key = key;
    tmp->val = val;
    tmp->next = head->next;
    head->next = tmp;
}

void listDelete(struct List* head, int key) {
    for (struct List* it = head; it->next; it = it->next) {
        if (it->next->key == key) {
            struct List* tmp = it->next;
            it->next = tmp->next;
            free(tmp);
            break;
        }
    }
}
//返回键所在位置对应的指针
struct List* listFind(struct List* head, int key) {
    for (struct List* it = head; it->next; it = it->next) {
        if (it->next->key == key) {
            return it->next;
        }
    }
    return NULL;
}

void listFree(struct List* head) {
    while (head->next) {
        struct List* tmp = head->next;
        head->next = tmp->next;
        free(tmp);
    }
}

const int base = 769;
//是一定要用哈希函数的，而且通常是用取模运算
int hash(int key) {
    return key % base;
}

typedef struct {
    struct List* data;
} MyHashMap;

MyHashMap* myHashMapCreate() {
    MyHashMap* ret = malloc(sizeof(MyHashMap));
    ret->data = malloc(sizeof(struct List) * base);
    for (int i = 0; i < base; i++) {
        ret->data[i].key = 0;
        ret->data[i].val = 0;
        ret->data[i].next = NULL;
    }
    return ret;
}

void myHashMapPut(MyHashMap* obj, int key, int value) {
    int h = hash(key);
    struct List* rec = listFind(&(obj->data[h]), key);//得到key所在的结点
    if (rec == NULL) {//如果链表中没有key
        listPush(&(obj->data[h]), key, value);
    } else {
        rec->val = value;//如果有key,就把这个地方的映射值修改成value
    }
}

int myHashMapGet(MyHashMap* obj, int key) {
    int h = hash(key);
    struct List* rec = listFind(&(obj->data[h]), key);
    if (rec == NULL) {
        return -1;
    } else {
        return rec->val;
    }
}
//把哈希表中含有key的结点移除掉
void myHashMapRemove(MyHashMap* obj, int key) {
    int h = hash(key);
    listDelete(&(obj->data[h]), key);
}

void myHashMapFree(MyHashMap* obj) {
    for (int i = 0; i < base; i++) {
        listFree(&(obj->data[i]));
    }
    free(obj->data);
    free(obj);
}