// #include<stdio.h>
// #include<stdlib.h>
//
// typedef struct LNode {
//     int data;
//     struct LNode *next;
// } LNode, *LinkList;
//
// //��ʼ������
// LinkList list_init() {
//     LinkList L = malloc(sizeof(LNode));
//     L->data = 0;
//     L->next = NULL;
//     return L;
// }
//
// //ȡֵ
// int list_get(LinkList L, int i, int *e) {
//     //�ڴ�ͷ���ĵ�����L�и������i��ȡԪ�ص�ֵ����e����L�е�i������Ԫ�ص�ֵ
//     //�����ȼ����������Ƿ�Ϲ棨���ܿ�ͷ��
//     if (L == NULL || i < 1 || e == NULL) {
//         return 0;
//     }
//     LinkList p = L->next;
//     int j = 1; //���Ҫһֱ���ҵ������β���Ͳ���Ҫ������j�����ֻҪ������ĳ���ض�λ�ã����������
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
// //���ң�����Ԫ�����������ΰ�ֵ����
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
// //����
// int list_insert(LinkList L, int i, int e) {
//     //������ĵ�i��λ�ã�����ֵe
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
// //ɾ��
// int list_delete(LinkList L, int i) {
//     if (L == NULL || i < 1) {
//         return 0;
//     }
//     LinkList p = L;
//     int j = 1;
//     while (p && j < i) {
//         p = p->next; //�ƶ�����i-1��λ��
//         j++;
//     }
//     if (p == NULL || p->next == NULL) //��ֹp����Ƿ�����Ҫɾ���Ľ�㲻����
//         return 0;
//     LinkList p2 = p->next;
//     p->next = p2->next;
//     free(p2);
//     return 1;
// }
//
// //��������
// //�Ȼ�ȡ����ĳ���
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
//     //����ͷ�巨��������
//     LinkList L = list_init();
//     for (int i = 0; i < 10; i++) {
//         list_insert(L, 1, i);
//     }
//     list_read(L);
//     //����β�巨��������
//     LinkList L2 = list_init();
//     for (int i = 0; i < 10; i++) {
//         int len = list_len(L2);
//         list_insert(L2, len + 1, i);
//     }
//     list_read(L2);
//     return 0;
// }
