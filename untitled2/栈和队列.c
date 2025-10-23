// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
//
// typedef struct Stack {
//     int *base; //栈底指针
//     int *top; //栈顶指针
//     int capacity; //栈的最大容量
// } Stack;
//
// //栈的初始化
// Stack *stack_init() {
//     Stack *stack = malloc(sizeof(Stack)); //别忘了，返回值是分配内存的基地址，要用Stack*来接收
//     if (!stack) {
//         return NULL;
//     }
//     stack->capacity = 2;
//     stack->base = malloc(sizeof(int) * stack->capacity);
//     if (!stack->base) {
//         free(stack); //把之前分配过的stack销毁
//         return NULL;
//     }
//     stack->top = stack->base;
//     return stack;
// }
//
// //入栈
// //扩容函数
// int stack_grow(Stack *stack) {
//     int *p = malloc(2 * sizeof(int) * stack->capacity);
//     if (!p) {
//         return 0;
//     }
//     memcpy(p, stack->base, sizeof(int) * stack->capacity);
//     int *old_base = stack->base;
//     stack->base = p; //stack->base原先指向的内存不需要了
//     stack->top = p + stack->capacity;
//     stack->capacity *= 2;
//     free(old_base);
//     return 1;
// }
//
// int push_stack(Stack *stack, int e) {
//     if (stack->top - stack->base == stack->capacity) {
//         if (!stack_grow(stack)) {
//             printf("failed to grow stack\n");
//             return 0;
//         }
//     }
//     *stack->top++ = e;
//     return 1;
// }
//
// //出栈
// int pop_stack(Stack *stack, int *e) {
//     if (stack->top == stack->base) {
//         printf("stack is empty\n");
//         return 0;
//     }
//     stack->top--;
//     *e = *stack->top;
//     return 1;
// }
//
// //取栈顶元素
// int stack_get(Stack *stack) {
//     if (stack->top == stack->base) {
//         printf("stack is empty\n");
//         return 0;
//     }
//     return *(stack->top - 1);
// }
//
// //销毁栈
// void stack_destroy(Stack *stack) {
//     if (stack) {
//         //永远记得先检查参数，确保只有非空时销毁，空栈没必要销毁
//         free(stack->base);
//         free(stack);
//     }
// }
//
// //循环队列
// typedef struct Queue {
//     int capacity;
//     int *data;
//     int front;
//     int rear; //队列中的指针实际上是索引，为int类型，方便循环队列的实现
// } Queue;
//
// //初始化队列
// Queue *queue_init() {
//     Queue *queue = malloc(sizeof(Queue));
//     if (!queue)
//         return NULL;
//     queue->capacity = 10;
//     queue->front = 0;
//     queue->rear = 0;
//     queue->data = malloc(sizeof(int) * queue->capacity);
//     if (!queue->data)
//         return NULL;
//     return queue;
// }
//
// //入队（在队尾加入一个新元素）
// int EnQueue(Queue *queue,int e) {
//     if (queue == NULL || (queue->rear + 1) % queue->capacity == queue->front) {
//         return 0;
//     }
//     queue->data[queue->rear] = e;
//     queue->rear = (queue->rear + 1) % queue->capacity; //注意在循环队列中，每次+1都是在循环意义上的，所以要取模
//     return 1;
// }
//
// //出队（将队头元素删除）
// int DeQueue(Queue *queue, int *e) {
//     if (queue == NULL || queue->front == queue->rear) {
//         //判断队空的条件
//         return 0;
//     }
//     *e = queue->data[queue->front]; //得到要删除的元素
//     queue->front = (queue->front + 1) % queue->capacity;
//     return 1;
// }
//
// //取队头元素
// int Queue_get(Queue *queue) {
//     if (queue == NULL)
//         return 0;
//     return queue->data[queue->front];
// }
//
// //销毁队列
// int Queue_destroy(Queue *queue) {
//     if (queue == NULL)
//         return 0;
//     free(queue->data);//先销毁数据域，再销毁整个队列
//     free(queue);
//     return 1;
// }
// int main() {
//     return 0;
// }
