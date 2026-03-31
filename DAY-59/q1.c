#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    if (inorderSize == 0 || postorderSize == 0)
        return NULL;

    int rootVal = postorder[postorderSize - 1];

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = rootVal;
    root->left = NULL;
    root->right = NULL;

    int rootIdx = 0;
    for (int i = 0; i < inorderSize; i++) {
        if (inorder[i] == rootVal) {
            rootIdx = i;
            break;
        }
    }

    int leftSize = rootIdx;
    int rightSize = inorderSize - rootIdx - 1;

    root->left = buildTree(inorder, leftSize, postorder, leftSize);
    root->right = buildTree(inorder + rootIdx + 1, rightSize, postorder + leftSize, rightSize);

    return root;
}

void preorder(struct TreeNode* root, int* first) {
    if (!root) return;
    if (!*first) printf(" ");
    printf("%d", root->val);
    *first = 0;
    preorder(root->left, first);
    preorder(root->right, first);
}

int main() {
    int n;
    scanf("%d", &n);

    int* inorder = malloc(n * sizeof(int));
    int* postorder = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &postorder[i]);

    struct TreeNode* root = buildTree(inorder, n, postorder, n);

    int first = 1;
    preorder(root, &first);
    printf("\n");

    free(inorder);
    free(postorder);

    return 0;
}