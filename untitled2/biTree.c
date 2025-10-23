#include<stdio.h>
#include<stdlib.h>

//非递归遍历二叉树，同时学习了用数组模拟栈的操作，这在实际代码中更加常用
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int *preorderTraversal(struct TreeNode *root, int *returnSize) {
    int *res = malloc(sizeof(int) * 2000); //只有malloc创建的数组才能返回
    *returnSize = 0; //设置计数器，便于主函数中遍历结果数组
    if (root == NULL) {
        return res;
    } //如果是空树，直接返回空数组

    struct TreeNode *stk[2000]; //创建数组模拟栈
    struct TreeNode *node = root; //创建一个指针，防止改动根结点
    int stk_top = 0; //以索引的形式设置栈顶指针
    while (stk_top > 0 || node != NULL) {
        //如果栈非空，说明还没回溯完；如果node非空，说明还有结点没有遍历；这个循环使每个结点都被操作了
        while (node != NULL) {
            res[(*returnSize)++] = node->val;
            stk[stk_top++] = node; //相当于把该结点入栈
            node = node->left;
        }
        node = stk[--stk_top]; //相当于出栈
        node = node->right;
    }
    return res;
}

//梳理这个函数的逻辑
//1.外循环：对每个结点分别操作
//2.对于每个结点：先访问该结点（存入数组）
//接着：如果左子树存在，指针指向左子树，同时将该节点入栈
//直到左子树被全部遍历，回溯到上一个结点（出栈）
//指向该节点的右子树
//进行下一次循环，对下一个结点进行操作

//递归形式的写法，要构造辅助函数
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

//中序遍历与前序遍历的代码相似，但后序遍历更加复杂
//这是因为当我们回溯根结点时，可能是从左子树回溯，也可能是从右子树回溯

int *postorderTraversal(struct TreeNode *root, int *returnSize) {
    int *res = malloc(100 * sizeof(int));
    *returnSize = 0;
    if (root == NULL) {
        return res;
    }

    struct TreeNode *stack[100];
    int stack_top = 0;
    struct TreeNode *node = root;
    struct TreeNode *lastVisited = NULL; // 记录上一个访问的节点

    while (stack_top > 0 || node != NULL) {
        // 向左走到尽头
        while (node != NULL) {
            stack[stack_top++] = node;
            node = node->left;
        }

        // 查看栈顶节点
        struct TreeNode *topNode = stack[stack_top - 1];

        // 如果右子树存在且没有被访问过
        if (topNode->right != NULL && topNode->right != lastVisited) {
            // 转向右子树
            node = topNode->right;
        } else {
            // 访问当前节点（后序：左右根，所以最后访问根）
            stack_top--; // 弹出栈顶
            res[(*returnSize)++] = topNode->val;
            lastVisited = topNode; // 记录刚刚访问的节点
        }
    }

    return res;
}

//我们可以从中提炼出一个经典的思想：当当前操作依赖于前一次操作时的状态时，必须记录历史状态

//层序遍历
//返回一个二维数组（看作一维数组的数组），用returnSize作为索引,*returnColumnSizes作为存储每个一维数组长度的数组
int **levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes) {
    // 开辟返回数组空间，最大为2000
    int **ans = malloc(sizeof(int *) * 2000);
    // *returnColumnSizes数组记录每一层节点的个数
    *returnColumnSizes = malloc(sizeof(int) * 2000);
    *returnSize = 0;
    // 若树为空，直接返回ans
    if (root == NULL) return ans;

    // 模拟队列数组
    struct TreeNode *queue[2000];
    // head、tail分别指向队列的头部和尾部
    int head = 0, tail = 0;

    // 初始先将根节点入队
    queue[tail++] = root;
    // 结束条件为队列为空，即tail==head
    while (head != tail) {
        /*
            每一次循环，都会将树当前层(可用*returnSize表示)节点全部入队，因此头部
            到尾部的节点数即为当前层的全部节点
        */
        int len = tail - head;

        // 开辟当前层的一维数组空间
        ans[*returnSize] = malloc(sizeof(int) * len);

        /*
            当前层的节点个数统计完成之后，需要出队，若节点全部出队，队列里存在下
            一层的全部节点，因此在出队之前，用临时变量start记录之前的head值，移
            动head到下一层节点的起始位置（即tail的位置），相当于当前层节点出队，
        */
        int start = head;
        head = tail;
        // start被赋值后变为当前层的头部，head被赋值后变为当前层的尾部
        for (int i = start; i < head; i++) {
            // 逐个访问当前层的节点值
            ans[*returnSize][i - start] = queue[i]->val;
            // 访问完一个节点后，将此节点的左右孩子入队
            if (queue[i]->left) queue[tail++] = queue[i]->left;
            if (queue[i]->right) queue[tail++] = queue[i]->right;
        }
        // *returnColumnSizes赋值，并将层数加1
        (*returnColumnSizes)[(*returnSize)++] = len;
    }
    return ans;
}
//总体思路：先把一层中的所有元素入队，然后从队头开始遍历，统计当前层的元素个数
//接着把队头指针移到队尾，并用一个临时指针指向原来的队头，这样就同时得到一个空队列和一个原始队列
//将原始队列的值依次放入数组中，每遍历一个结点，就将左右子树入队
//最后将len赋值给returnColumnSizes，层数+1