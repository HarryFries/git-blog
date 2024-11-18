#include <stdio.h>
#include <stdlib.h>

// 이진 트리 노드 구조체 정의
typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

#define MAX_STACK 100
Node* stack[MAX_STACK];
int top = -1;
int visited[MAX_STACK] = {0};

// 새로운 노드 생성 함수
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void push(Node* node) {
    if (top == MAX_STACK - 1) return;
    stack[++top] = node;
}

Node* pop() {
    if (top == -1) return NULL;
    return stack[top--];
}

void printStack() {
    printf("현재 스택: ");
    for(int i = 0; i <= top; i++) {
        printf("%c ", stack[i]->data);
    }
    printf("\n");
}

void DFS(Node* root) {
    if (root == NULL) return;
    
    printf("\n시작 노드 %c 방문 및 push\n", root->data);
    push(root);
    visited[root->data - 'A'] = 1;
    printStack();

    while (top > -1) {
        Node* current = stack[top];
        
        // 왼쪽 자식이 있고 방문하지 않았다면
        if (current->left && !visited[current->left->data - 'A']) {
            printf("\n%c의 왼쪽 자식 %c를 push\n", current->data, current->left->data);
            push(current->left);
            visited[current->left->data - 'A'] = 1;
            printStack();
        }
        // 오른쪽 자식이 있고 방문하지 않았다면
        else if (current->right && !visited[current->right->data - 'A']) {
            printf("\n%c의 오른쪽 자식 %c를 push\n", current->data, current->right->data);
            push(current->right);
            visited[current->right->data - 'A'] = 1;
            printStack();
        }
        // 양쪽 자식을 모두 방문했거나 자식이 없다면
        else {
            printf("\n%c는 더 이상 방문할 자식이 없으므로 pop\n", current->data);
            pop();
            printStack();
        }
    }
}

int main(void) {
    // 이진 트리 생성
    Node* root = createNode('A');
    root->left = createNode('B');
    root->right = createNode('C');
    root->left->left = createNode('D');
    root->left->right = createNode('E');
    root->right->left = createNode('F');
    
    /*
         A
       /   \
      B     C
     / \   /
    D   E F
    */
    
    DFS(root);
    return 0;
}
