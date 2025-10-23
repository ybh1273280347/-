// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
//
// typedef struct Stack {
//     int *base; //ջ��ָ��
//     int *top; //ջ��ָ��
//     int capacity; //ջ���������
// } Stack;
//
// //ջ�ĳ�ʼ��
// Stack *stack_init() {
//     Stack *stack = malloc(sizeof(Stack)); //�����ˣ�����ֵ�Ƿ����ڴ�Ļ���ַ��Ҫ��Stack*������
//     if (!stack) {
//         return NULL;
//     }
//     stack->capacity = 2;
//     stack->base = malloc(sizeof(int) * stack->capacity);
//     if (!stack->base) {
//         free(stack); //��֮ǰ�������stack����
//         return NULL;
//     }
//     stack->top = stack->base;
//     return stack;
// }
//
// //��ջ
// //���ݺ���
// int stack_grow(Stack *stack) {
//     int *p = malloc(2 * sizeof(int) * stack->capacity);
//     if (!p) {
//         return 0;
//     }
//     memcpy(p, stack->base, sizeof(int) * stack->capacity);
//     int *old_base = stack->base;
//     stack->base = p; //stack->baseԭ��ָ����ڴ治��Ҫ��
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
// //��ջ
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
// //ȡջ��Ԫ��
// int stack_get(Stack *stack) {
//     if (stack->top == stack->base) {
//         printf("stack is empty\n");
//         return 0;
//     }
//     return *(stack->top - 1);
// }
//
// //����ջ
// void stack_destroy(Stack *stack) {
//     if (stack) {
//         //��Զ�ǵ��ȼ�������ȷ��ֻ�зǿ�ʱ���٣���ջû��Ҫ����
//         free(stack->base);
//         free(stack);
//     }
// }
//
// //ѭ������
// typedef struct Queue {
//     int capacity;
//     int *data;
//     int front;
//     int rear; //�����е�ָ��ʵ������������Ϊint���ͣ�����ѭ�����е�ʵ��
// } Queue;
//
// //��ʼ������
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
// //��ӣ��ڶ�β����һ����Ԫ�أ�
// int EnQueue(Queue *queue,int e) {
//     if (queue == NULL || (queue->rear + 1) % queue->capacity == queue->front) {
//         return 0;
//     }
//     queue->data[queue->rear] = e;
//     queue->rear = (queue->rear + 1) % queue->capacity; //ע����ѭ�������У�ÿ��+1������ѭ�������ϵģ�����Ҫȡģ
//     return 1;
// }
//
// //���ӣ�����ͷԪ��ɾ����
// int DeQueue(Queue *queue, int *e) {
//     if (queue == NULL || queue->front == queue->rear) {
//         //�ж϶ӿյ�����
//         return 0;
//     }
//     *e = queue->data[queue->front]; //�õ�Ҫɾ����Ԫ��
//     queue->front = (queue->front + 1) % queue->capacity;
//     return 1;
// }
//
// //ȡ��ͷԪ��
// int Queue_get(Queue *queue) {
//     if (queue == NULL)
//         return 0;
//     return queue->data[queue->front];
// }
//
// //���ٶ���
// int Queue_destroy(Queue *queue) {
//     if (queue == NULL)
//         return 0;
//     free(queue->data);//��������������������������
//     free(queue);
//     return 1;
// }
// int main() {
//     return 0;
// }
