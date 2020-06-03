#pragma once

#include <iostream>

// ���� ������
#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101

// ��� ������ �����
typedef int T;

// �������� ��������� �����
typedef struct MyStack {
    T value;
    struct MyStack *next;
} MyStack_t;

// ������� ������� �������� � ����
void push(MyStack_t **head, T value);

// ������� �������� �������� �� �����
void pop(MyStack_t **head);

// ������� �������� ����� �� �������
bool isEmpty(MyStack_t **head);

// ������� ������������ �������� �������
T top(const MyStack_t *head);