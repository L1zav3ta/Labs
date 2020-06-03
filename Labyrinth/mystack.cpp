#include "mystack.h"

void push(MyStack_t **head, T value) {
    MyStack_t *tmp = new MyStack_t;

    if (tmp == NULL) 
        exit(STACK_OVERFLOW);

    tmp->next = *head;
    tmp->value = value;
    *head = tmp;
}

void pop(MyStack_t **head) {
    MyStack_t *out;
    T value;

    if (*head == NULL)
        exit(STACK_UNDERFLOW);

    out = *head;
    *head = (*head)->next;
    value = out->value;

    delete[] out;
}

bool isEmpty(MyStack_t **head) {
    if (*head == NULL) 
        return true;
    else
        return false;
}

T top(const MyStack_t *head) {
    if (head == NULL)
        exit(STACK_UNDERFLOW);

    return head->value;
}
