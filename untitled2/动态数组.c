// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
// //动态数组
// //对于一系列相同数据类型的元素，如何存储？
// //1.使用静态数组 int arr[10]，大小是固定的，不能动态地去调整    栈区：内存会自动释放
// //2.使用动态数组 int* p = 给的内存地址   堆区：内存必须手动申请，手动释放
// //动态申请内存的方法：
// //1.使用库函数malloc/calloc/realloc
// //2.使用完毕记得释放free
// #define TRUE 1
// #define FALSE 0
// //为了方便后续遍历，我们定义一个函数foreach
//
// //对动态数组进行管理：顺序表
// typedef struct SeqList {
//     int *data; //数据域，申请数组
//     int capacity; //数组的容量
//     int size; //当前存储的元素个数
// } Seqlist;
//
// //创建顺序表
// Seqlist *seqlist_new() {
//     Seqlist *list = malloc(sizeof(Seqlist));
//     if (list == NULL) {
//         printf("seqlist malloc failed\n");
//         return NULL;
//     }
//     list->capacity = 1; //初始时需要8个元素
//     list->size = 0;
//     list->data = calloc(list->capacity, sizeof(int));
//     if (list->data == NULL) {
//         printf("list->data calloc failed\n");
//         free(list); //分配失败，无需释放当前内存，但要释放前面分配过的所有内存
//         return NULL;
//     }
//     return list;
// }
//
// //销毁数据表
// void seqlist_del(Seqlist *list) {
//     free(list);
//     free(list->data);
// }
//
// //扩容函数
// //关键是创建更大的临时内存，先将数据拷贝到临时内存，再让指针指向他
// int seqlist_grow(Seqlist *list) {
//     int *p = calloc(2 * list->capacity, sizeof(int));
//     if (p == NULL) {
//         //！就可以用来表示操作失败
//         return FALSE;
//     }
//     memcpy(p, list->data, list->size * sizeof(int)); //指针拷贝，把list->data中的数据拷贝到p中
//     list->capacity *= 2;
//     free(list->data); //之前的内存不用了就要释放
//     list->data = p;
//     return TRUE; //引入bool值，就可以用！表示操作失败
// }
//
// //插入数据
// void seqlist_push(Seqlist *list, int v) {
//     if (list->size >= list->capacity) {
//         //如果容量不够，扩容，只有扩容失败才是真正的失败
//         if (!seqlist_grow(list)) {
//             printf("seqlist push failed\n");
//             return;
//         }
//     } //检查，目前长度要小于最大容量
//     list->data[list->size] = v;
//     list->size++;
// }
//
// //获取数据
// int sealist_get(Seqlist *list, int index) {
//     if (index < list->size)
//         return list->data[index];
// }
//
// int main() {
//     //动态申请内存
//     //malloc：参数为需要申请的内存字节大小，成功返回申请的内存地址，失败返回NULL（不会自动初始化）
//     //calloc:会自动初始化内存为0
//     //注意：返回的均为万能指针void，无需强制类型转换
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
