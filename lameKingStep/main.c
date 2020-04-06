//лабораторная работа №1. Фигура: король; поле: 7; задание: 2;
//задание: вывести путь из заданной точки "а" в заданную точку "b";
//выполнила: Медведева Елизавета ИВТ-13БО;

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include "lameKing.h"

void main() {
	setlocale(LC_ALL, "Rus");
	int *arr, begin, finish, strs, countElstr, el, countEl;

	printf_s("\nВведите кол-во строк поля\n");
	if (scanf_s("%d", &strs) != 1) {
		printf_s("\nОшибка ввода числа\n\n");
		system("pause");
		return;
	}

	printf_s("\nВведите кол-во элементов в строке\n");
	if (scanf_s("%d", &countElstr) != 1) {
		printf_s("\nОшибка ввода числа\n\n");
		system("pause");
		return;
	}

	if (strs == 0 || countElstr == 0) {
		printf_s("\nЭлементов не найдено, проверьте, не был ли введен 0\n\n");
		system("pause");
		return;
	}

	countEl = countElstr * strs;									// Всего элементов на поле
	printf_s("\nВсего элементов в поле:	от 1 до %d\n\n", countEl);

	//работа с начальным положением:
	printf_s("\nВведите начальное положение\n");
	if (scanf_s("%d", &begin) != 1) {								// Если введено не число
		printf_s("\nОшибка ввода числа\n\n");
		system("pause");
		return;
	}
	if ((begin <= 0) || (begin > countEl)) {
		printf_s("\nВыход за рамки поля\n\n");
		system("pause");
		return;
	}

	//работа с конечным положением:
	printf_s("\nВведите конечное положение\n");
	if (scanf_s("%d", &finish) != 1) {							// Если введено не число 
		printf_s("\nОшибка ввода числа\n\n");
		system("pause");
		return;
	}
	if ((finish <= 0) || (finish > countEl)) {
		printf_s("\nВыход за рамки поля\n\n");
		system("pause");
		return;
	}

	if (begin == finish) {
		printf_s("\nВы уже в конечной точке\n\n");
		system("pause");
		return;
	}

	if (countElstr == 1) {
		printf_s("\nКороль не ходит по диагонали!\n\n");
		system("pause");
		return;
	}

	begin--;
	finish--;

	if (!(arr = (int*)malloc(countEl * sizeof(int))))
		return;
	el = 0;
	for (int i = 0; i < countEl; i++)
		arr[i] = ++el;

	printf_s("\nКороль прошел по пути:\t");

	stepKing(arr, strs, countElstr, begin, finish);

	printf_s("\n\n");

	free(arr);
	system("pause");
	return;
}