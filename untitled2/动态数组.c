// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
// //��̬����
// //����һϵ����ͬ�������͵�Ԫ�أ���δ洢��
// //1.ʹ�þ�̬���� int arr[10]����С�ǹ̶��ģ����ܶ�̬��ȥ����    ջ�����ڴ���Զ��ͷ�
// //2.ʹ�ö�̬���� int* p = �����ڴ��ַ   �������ڴ�����ֶ����룬�ֶ��ͷ�
// //��̬�����ڴ�ķ�����
// //1.ʹ�ÿ⺯��malloc/calloc/realloc
// //2.ʹ����ϼǵ��ͷ�free
// #define TRUE 1
// #define FALSE 0
// //Ϊ�˷���������������Ƕ���һ������foreach
//
// //�Զ�̬������й���˳���
// typedef struct SeqList {
//     int *data; //��������������
//     int capacity; //���������
//     int size; //��ǰ�洢��Ԫ�ظ���
// } Seqlist;
//
// //����˳���
// Seqlist *seqlist_new() {
//     Seqlist *list = malloc(sizeof(Seqlist));
//     if (list == NULL) {
//         printf("seqlist malloc failed\n");
//         return NULL;
//     }
//     list->capacity = 1; //��ʼʱ��Ҫ8��Ԫ��
//     list->size = 0;
//     list->data = calloc(list->capacity, sizeof(int));
//     if (list->data == NULL) {
//         printf("list->data calloc failed\n");
//         free(list); //����ʧ�ܣ������ͷŵ�ǰ�ڴ棬��Ҫ�ͷ�ǰ�������������ڴ�
//         return NULL;
//     }
//     return list;
// }
//
// //�������ݱ�
// void seqlist_del(Seqlist *list) {
//     free(list);
//     free(list->data);
// }
//
// //���ݺ���
// //�ؼ��Ǵ����������ʱ�ڴ棬�Ƚ����ݿ�������ʱ�ڴ棬����ָ��ָ����
// int seqlist_grow(Seqlist *list) {
//     int *p = calloc(2 * list->capacity, sizeof(int));
//     if (p == NULL) {
//         //���Ϳ���������ʾ����ʧ��
//         return FALSE;
//     }
//     memcpy(p, list->data, list->size * sizeof(int)); //ָ�뿽������list->data�е����ݿ�����p��
//     list->capacity *= 2;
//     free(list->data); //֮ǰ���ڴ治���˾�Ҫ�ͷ�
//     list->data = p;
//     return TRUE; //����boolֵ���Ϳ����ã���ʾ����ʧ��
// }
//
// //��������
// void seqlist_push(Seqlist *list, int v) {
//     if (list->size >= list->capacity) {
//         //����������������ݣ�ֻ������ʧ�ܲ���������ʧ��
//         if (!seqlist_grow(list)) {
//             printf("seqlist push failed\n");
//             return;
//         }
//     } //��飬Ŀǰ����ҪС���������
//     list->data[list->size] = v;
//     list->size++;
// }
//
// //��ȡ����
// int sealist_get(Seqlist *list, int index) {
//     if (index < list->size)
//         return list->data[index];
// }
//
// int main() {
//     //��̬�����ڴ�
//     //malloc������Ϊ��Ҫ������ڴ��ֽڴ�С���ɹ�����������ڴ��ַ��ʧ�ܷ���NULL�������Զ���ʼ����
//     //calloc:���Զ���ʼ���ڴ�Ϊ0
//     //ע�⣺���صľ�Ϊ����ָ��void������ǿ������ת��
//     Seqlist* list = seqlist_new();
//     for (int i = 0; i < 100; i++) {
//         seqlist_push(list, i);
//     }
//     for (int i = 0; i < list->size; i++) {
//         int value = sealist_get(list, i);
//         printf("%d ", value);
//     }
//     return 0;
// }
