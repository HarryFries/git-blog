#include <stdio.h>
#include <stdlib.h>

// 이진 트리 노드 구조체 정의
typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

#define MAX_QUEUE 100
Node* queue[MAX_QUEUE];
int front = 0, rear = 0;
int visited[MAX_QUEUE] = {0};

// 새로운 노드 생성 함수
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void enqueue(Node* node) {
    if ((rear + 1) % MAX_QUEUE == front) return; // 큐가 가득 찼을 때
    queue[rear] = node;
    rear = (rear + 1) % MAX_QUEUE;
}

Node* dequeue() {
    if (front == rear) return NULL; // 큐가 비었을 때
    Node* node = queue[front];
    front = (front + 1) % MAX_QUEUE;
    return node;
}

void printQueue() {
    printf("현재 큐: ");
    int i = front;
    while (i != rear) {
        printf("%c ", queue[i]->data);
        i = (i + 1) % MAX_QUEUE;
    }
    printf("\n");
}

void BFS(Node* root) {
    if (root == NULL) return;
    
    printf("\n시작 노드 %c 방문 및 추가\n", root->data);
    enqueue(root);
    visited[root->data - 'A'] = 1;
    printQueue();

    while (front != rear) {
        Node* current = dequeue();
        printf("\n큐에서 %c 뺌\n", current->data);
        printQueue();

        // 왼쪽 자식을 큐에 넣기
        if (current->left && !visited[current->left->data - 'A']) {
            printf("%c의 왼쪽 자식 %c 추가\n", current->data, current->left->data);
            enqueue(current->left);
            visited[current->left->data - 'A'] = 1;
            printQueue();
        } else if (current->left) {
            printf("%c의 왼쪽 자식 %c는 이미 방문했습니다.\n", current->data, current->left->data);
        }

        // 오른쪽 자식을 큐에 넣기
        if (current->right && !visited[current->right->data - 'A']) {
            printf("%c의 오른쪽 자식 %c 추가\n", current->data, current->right->data);
            enqueue(current->right);
            visited[current->right->data - 'A'] = 1;
            printQueue();
        } else if (current->right) {
            printf("%c의 오른쪽 자식 %c는 이미 방문했습니다.\n", current->data, current->right->data);
        }

        // 인접 노드가 없거나 모두 방문한 경우
        if ((current->left == NULL || visited[current->left->data - 'A']) &&
            (current->right == NULL || visited[current->right->data - 'A'])) {
            printf("%c의 인접 노드가 없거나 모두 방문했습니다.\n", current->data);
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
    
    BFS(root);
    return 0;
}
