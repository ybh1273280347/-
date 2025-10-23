#include<stdio.h>
#include<stdlib.h>

//�ǵݹ������������ͬʱѧϰ��������ģ��ջ�Ĳ���������ʵ�ʴ����и��ӳ���
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int *preorderTraversal(struct TreeNode *root, int *returnSize) {
    int *res = malloc(sizeof(int) * 2000); //ֻ��malloc������������ܷ���
    *returnSize = 0; //���ü������������������б����������
    if (root == NULL) {
        return res;
    } //����ǿ�����ֱ�ӷ��ؿ�����

    struct TreeNode *stk[2000]; //��������ģ��ջ
    struct TreeNode *node = root; //����һ��ָ�룬��ֹ�Ķ������
    int stk_top = 0; //����������ʽ����ջ��ָ��
    while (stk_top > 0 || node != NULL) {
        //���ջ�ǿգ�˵����û�����ꣻ���node�ǿգ�˵�����н��û�б��������ѭ��ʹÿ����㶼��������
        while (node != NULL) {
            res[(*returnSize)++] = node->val;
            stk[stk_top++] = node; //�൱�ڰѸý����ջ
            node = node->left;
        }
        node = stk[--stk_top]; //�൱�ڳ�ջ
        node = node->right;
    }
    return res;
}

//��������������߼�
//1.��ѭ������ÿ�����ֱ����
//2.����ÿ����㣺�ȷ��ʸý�㣨�������飩
//���ţ�������������ڣ�ָ��ָ����������ͬʱ���ýڵ���ջ
//ֱ����������ȫ�����������ݵ���һ����㣨��ջ��
//ָ��ýڵ��������
//������һ��ѭ��������һ�������в���

//�ݹ���ʽ��д����Ҫ���츨������
void inorderTraversal(struct TreeNode *root, int *res, int *returnSize) {
    if (root == NULL) return;
    inorderTraversal(root->left, res, returnSize);
    res[(*returnSize)++] = root->val;
    inorderTraversal(root->right, res, returnSize);
}

int *inorderTraversalRecursive(struct TreeNode *root, int *returnSize) {
    int *res = (int *) malloc(sizeof(int) * 100);
    *returnSize = 0;
    inorderTraversal(root, res, returnSize);
    return res;
}

//���������ǰ������Ĵ������ƣ�������������Ӹ���
//������Ϊ�����ǻ��ݸ����ʱ�������Ǵ����������ݣ�Ҳ�����Ǵ�����������

int *postorderTraversal(struct TreeNode *root, int *returnSize) {
    int *res = malloc(100 * sizeof(int));
    *returnSize = 0;
    if (root == NULL) {
        return res;
    }

    struct TreeNode *stack[100];
    int stack_top = 0;
    struct TreeNode *node = root;
    struct TreeNode *lastVisited = NULL; // ��¼��һ�����ʵĽڵ�

    while (stack_top > 0 || node != NULL) {
        // �����ߵ���ͷ
        while (node != NULL) {
            stack[stack_top++] = node;
            node = node->left;
        }

        // �鿴ջ���ڵ�
        struct TreeNode *topNode = stack[stack_top - 1];

        // ���������������û�б����ʹ�
        if (topNode->right != NULL && topNode->right != lastVisited) {
            // ת��������
            node = topNode->right;
        } else {
            // ���ʵ�ǰ�ڵ㣨�������Ҹ������������ʸ���
            stack_top--; // ����ջ��
            res[(*returnSize)++] = topNode->val;
            lastVisited = topNode; // ��¼�ոշ��ʵĽڵ�
        }
    }

    return res;
}

//���ǿ��Դ���������һ�������˼�룺����ǰ����������ǰһ�β���ʱ��״̬ʱ�������¼��ʷ״̬

//�������
//����һ����ά���飨����һά��������飩����returnSize��Ϊ����,*returnColumnSizes��Ϊ�洢ÿ��һά���鳤�ȵ�����
int **levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes) {
    // ���ٷ�������ռ䣬���Ϊ2000
    int **ans = malloc(sizeof(int *) * 2000);
    // *returnColumnSizes�����¼ÿһ��ڵ�ĸ���
    *returnColumnSizes = malloc(sizeof(int) * 2000);
    *returnSize = 0;
    // ����Ϊ�գ�ֱ�ӷ���ans
    if (root == NULL) return ans;

    // ģ���������
    struct TreeNode *queue[2000];
    // head��tail�ֱ�ָ����е�ͷ����β��
    int head = 0, tail = 0;

    // ��ʼ�Ƚ����ڵ����
    queue[tail++] = root;
    // ��������Ϊ����Ϊ�գ���tail==head
    while (head != tail) {
        /*
            ÿһ��ѭ�������Ὣ����ǰ��(����*returnSize��ʾ)�ڵ�ȫ����ӣ����ͷ��
            ��β���Ľڵ�����Ϊ��ǰ���ȫ���ڵ�
        */
        int len = tail - head;

        // ���ٵ�ǰ���һά����ռ�
        ans[*returnSize] = malloc(sizeof(int) * len);

        /*
            ��ǰ��Ľڵ����ͳ�����֮����Ҫ���ӣ����ڵ�ȫ�����ӣ������������
            һ���ȫ���ڵ㣬����ڳ���֮ǰ������ʱ����start��¼֮ǰ��headֵ����
            ��head����һ��ڵ����ʼλ�ã���tail��λ�ã����൱�ڵ�ǰ��ڵ���ӣ�
        */
        int start = head;
        head = tail;
        // start����ֵ���Ϊ��ǰ���ͷ����head����ֵ���Ϊ��ǰ���β��
        for (int i = start; i < head; i++) {
            // ������ʵ�ǰ��Ľڵ�ֵ
            ans[*returnSize][i - start] = queue[i]->val;
            // ������һ���ڵ�󣬽��˽ڵ�����Һ������
            if (queue[i]->left) queue[tail++] = queue[i]->left;
            if (queue[i]->right) queue[tail++] = queue[i]->right;
        }
        // *returnColumnSizes��ֵ������������1
        (*returnColumnSizes)[(*returnSize)++] = len;
    }
    return ans;
}
//����˼·���Ȱ�һ���е�����Ԫ����ӣ�Ȼ��Ӷ�ͷ��ʼ������ͳ�Ƶ�ǰ���Ԫ�ظ���
//���ŰѶ�ͷָ���Ƶ���β������һ����ʱָ��ָ��ԭ���Ķ�ͷ��������ͬʱ�õ�һ���ն��к�һ��ԭʼ����
//��ԭʼ���е�ֵ���η��������У�ÿ����һ����㣬�ͽ������������
//���len��ֵ��returnColumnSizes������+1