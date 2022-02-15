#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *lchild, *rchild;
} TreeNode;

typedef struct Tree {
    TreeNode *root;
    int n;
} Tree;

TreeNode *newNode(int val) {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->val = val;
    node->lchild = node->rchild = NULL;
    return node;
}

Tree *initTree() {
    Tree *t = (Tree *)malloc(sizeof(Tree));
    t->root = NULL;
    t->n = 0;
    return  t;
}

void clearNode(TreeNode *node) {
    if (node == NULL) return;
    clearNode(node->lchild);
    clearNode(node->rchild);
    free(node);
    return;
}

void clearTree(Tree *t) {
    if (t == NULL) return;
    clearNode(t->root);
    free(t);
    return;
}

TreeNode *insertNode(TreeNode *node, int val, int *flag) {
    if (node == NULL) {
        *flag = 1;
        return newNode(val);
    }
    if (node->val == val) return node;
    if (node->val > val) node->lchild = insertNode(node->lchild, val, flag);
    else node->rchild = insertNode(node->rchild, val, flag);
    return node;
}

void insertTree(Tree *t, int val) {
    if (t == NULL) return;
    int flag;
    t->root = insertNode(t->root, val, &flag);
    t->n += flag;
    return;
}

void outputNode(TreeNode *node) {
    if (node == NULL) return;
    printf("%d", node->val);
    if (node->lchild == NULL && node->rchild == NULL) return;
    printf("/(");
    outputNode(node->lchild);
    printf(",");
    outputNode(node->rchild);
    printf(")");
    return;
}

void output(Tree *t) {
    if (t == NULL) return;
    printf("tree = %d: ", t->n);
    outputNode(t->root);
    return;
}

void preOrderNode(TreeNode *node) {
    if (node == NULL) return;
    printf("%d ", node->val);
    preOrderNode(node->lchild);
    preOrderNode(node->rchild);
    return;
}

void preOrder(Tree *t) {
    printf("pre order: ");
    if (t == NULL) return;
    preOrderNode(t->root);
    printf("\n");
    return;
}

void inOrderNode(TreeNode *node) {
    if (node == NULL) return;
    inOrderNode(node->lchild);
    printf("%d ", node->val);
    inOrderNode(node->rchild);
    return;
}

void inOrder(Tree *t) {
    printf("in order: ");
    if (t == NULL) return;
    inOrderNode(t->root);
    printf("\n");
    return;
}

void postOrderNode(TreeNode *node) {
    if (node == NULL) return;
    printf("%d ", node->val);
    postOrderNode(node->lchild);
    postOrderNode(node->rchild);
    return;
}

void postOrder(Tree *t) {
    if (t == NULL) return;
    printf("post order: ");
    postOrderNode(t->root);
    printf("\n");
    return;
}

int main() {
    srand(time(0));
    Tree *t = initTree();
    for (int i = 0; i < 10; i++) {
        int val = rand() % 100;
        insertTree(t, val);
        output(t);
        printf("\n");
    }

    preOrder(t);
    inOrder(t);
    postOrder(t);
    clearTree(t);
    return 0;
}
