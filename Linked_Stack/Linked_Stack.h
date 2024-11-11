#pragma once

typedef int element;

typedef struct stackNode {
    element data;
    struct stackNode *link;
} stackNode;

extern stackNode* top;

int isStackEmpty(void);
void push(element item);
element pop(void);
element peek(void);
void printStack(void);
