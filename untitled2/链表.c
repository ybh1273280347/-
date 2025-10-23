// #include<stdio.h>
// #include<stdlib.h>
//
// typedef struct LNode {
//     int data;
//     struct LNode *next;
// } LNode, *LinkList;
//
// //初始化链表
// LinkList list_init() {
//     LinkList L = malloc(sizeof(LNode));
//     L->data = 0;
//     L->next = NULL;
//     return L;
// }
//
// //取值
// int list_get(LinkList L, int i, int *e) {
//     //在带头结点的单链表L中根据序号i获取元素的值，用e返回L中第i个数据元素的值
//     //开局先检测参数传递是否合规（万能开头）
//     if (L == NULL || i < 1 || e == NULL) {
//         return 0;
//     }
//     LinkList p = L->next;
//     int j = 1; //如果要一直查找到链表结尾，就不需要计数器j，如果只要遍历到某个特定位置，就需计数器
//     while (p && j < i) {
//         p = p->next;
//         ++j;
//     }
//     if (!p)
//         return 0;
//     *e = p->data;
//     return 1;
// }
//
// //查找，从首元结点出发，依次按值查找
// LinkList list_search(LinkList L, int e) {
//     if (L == NULL) {
//         return NULL;
//     }
//     LinkList p = L->next;
//     while (p && p->data != e) {
//         p = p->next;
//     }
//     return p;
// }
//
// //插入
// int list_insert(LinkList L, int i, int e) {
//     //在链表的第i个位置，插入值e
//     if (L == NULL || i < 1) {
//         return 0;
//     }
//     int j = 1;
//     LinkList temp = L;
//     while (temp && j < i) {
//         temp = temp->next;
//         j++;
//     }
//     if (!temp) {
//         return 0;
//     }
//     LinkList p = malloc(sizeof(LNode));
//     if (!p)
//         return 0;
//     p->data = e;
//     p->next = temp->next;
//     temp->next = p;
//     return 1;
// }
//
// //删除
// int list_delete(LinkList L, int i) {
//     if (L == NULL || i < 1) {
//         return 0;
//     }
//     LinkList p = L;
//     int j = 1;
//     while (p && j < i) {
//         p = p->next; //移动到第i-1个位置
//         j++;
//     }
//     if (p == NULL || p->next == NULL) //防止p本身非法，或要删除的结点不存在
//         return 0;
//     LinkList p2 = p->next;
//     p->next = p2->next;
//     free(p2);
//     return 1;
// }
//
// //遍历链表
// //先获取链表的长度
// int list_len(LinkList L) {
//     if (L == NULL)
//         return 0;
//     LinkList p = L->next;
//     int len = 0;
//     while (p) {
//         p = p->next;
//         len++;
//     }
//     return len;
// }
//
// int list_read(LinkList L) {
//     if (L == NULL)
//         return 0;
//     LinkList p = L->next;
//     int len = list_len(L);
//     for (int i = 0; i < len; i++) {
//         printf("%d->", p->data);
//         p = p->next;
//     }
//     printf("NULL\n");
//     return 1;
// }
//
// int main() {
//     //利用头插法创建链表
//     LinkList L = list_init();
//     for (int i = 0; i < 10; i++) {
//         list_insert(L, 1, i);
//     }
//     list_read(L);
//     //利用尾插法创建链表
//     LinkList L2 = list_init();
//     for (int i = 0; i < 10; i++) {
//         int len = list_len(L2);
//         list_insert(L2, len + 1, i);
//     }
//     list_read(L2);
//     return 0;
// }
