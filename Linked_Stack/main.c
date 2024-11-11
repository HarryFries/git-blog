#include "Linked_Stack.h"
#include <stdio.h>

int main(void) {
    element item;
    top = NULL;

    printf("Enter a number to push on the stack: ");
    scanf("%d", &item);
    push(item);
    printStack();

    push(1); printStack();
    push(2); printStack();
    push(3); printStack();

    item = peek(); printStack();
    printf("Peeked item: %d\n", item);

    item = pop(); printStack();
    printf("Popped item: %d\n", item);

    item = pop(); printStack();
    printf("Popped item: %d\n", item);

    getchar(); return 0;
}