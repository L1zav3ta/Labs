#pragma once

#include <iostream>

// Коды ошибок
#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101

// Тип данных стека
typedef int T;

// Описание структуры стека
typedef struct MyStack {
    T value;
    struct MyStack *next;
} MyStack_t;

// Функция вставки элемента в стек
void push(MyStack_t **head, T value);

// Функция удаления элемента из стека
void pop(MyStack_t **head);

// Функция проверки стека на пустоту
bool isEmpty(MyStack_t **head);

// Функция возвращающая значение вершины
T top(const MyStack_t *head);