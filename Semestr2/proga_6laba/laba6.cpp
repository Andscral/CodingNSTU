//������: ���-341
//������������ ������ �6

//������ 5(������� ������)

/*#include <stdio.h>
#include <stdlib.h>

// ��������� ��� ������� ������
struct Node 
{
    int data[4];
    struct Node* child[2];
};

// ������� ��� ��������� �������� �� ������ �� ����������� ������
int get(struct Node* root, int index) 
{
    if (root == NULL) {
        return -1; // ��������� ������� ������
    }

    if (index < 4) {
        return root->data[index]; // ���������� �������� �� ������� �������
    }

    return get(root->child[index % 2], index / 2); // ���������� ���� �������� � �������
}

// ������� ��� ��������� �������� � ������ �� ����������� ������
void insert(struct Node** root, int index, int value) 
{
    if (*root == NULL) {
        // ������� ����� �������
        *root = (struct Node*)malloc(sizeof(struct Node));
        for (int i = 0; i < 4; ++i) {
            (*root)->data[i] = -1; // �������������� ������ � -1
        }
        (*root)->child[0] = NULL;
        (*root)->child[1] = NULL;
    }

    if (index < 4) {
        (*root)->data[index] = value; // �������� �������� � ������� �������
    }
    else {
        insert(&((*root)->child[index % 2]), index / 2, value); // ���������� �������� �������� � �������
    }
}

int main() 
{
    struct Node* root = NULL;

    // ��������� �������� � ������
    insert(&root, 0, 10);
    insert(&root, 1, 20);
    insert(&root, 2, 30);
    insert(&root, 3, 40);
    insert(&root, 4, 50);
    insert(&root, 5, 60);
    insert(&root, 6, 70);
    insert(&root, 7, 80);

    // ��������� �������� �� ������
    printf("%d\n", get(root, 0)); // 10
    printf("%d\n", get(root, 1)); // 20
    printf("%d\n", get(root, 2)); // 30
    printf("%d\n", get(root, 3)); // 40
    printf("%d\n", get(root, 4)); // 50
    printf("%d\n", get(root, 5)); // 60
    printf("%d\n", get(root, 6)); // 70
    printf("%d\n", get(root, 7)); // 80

    return 0;
}*/

//������ 1(������� ������)

/*#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

void insertNode(struct Node** root, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    if (*root == NULL) {
        *root = newNode;
        return;
    }

    struct Node* current = *root;
    struct Node* parent = NULL;

    while (current != NULL) {
        parent = current;
        if (value < current->data) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    if (value < parent->data) {
        parent->left = newNode;
    }
    else {
        parent->right = newNode;
    }
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    insertNode(&root, 5);
    insertNode(&root, 3);
    insertNode(&root, 6);
    insertNode(&root, 2);
    insertNode(&root, 4);

    printf(" answer = ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}*/