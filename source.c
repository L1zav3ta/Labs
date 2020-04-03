//лабораторная работа №1. Фигура: король; поле: 7; задание: 2;
//найти путь из заданной точки "а" в заданную точку "b";
//выполнила Медведева Елизавета ИВТ-13БО;

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Функция ищет, в какой строке указанный элемент:
int searchCurrStr( int countStrs, int countElInStr, int elem) {		//кол-во строк, кол-во эл-в в строке, элемент поиска
	int currStr, idxR, idxL;					// currStr - бегунок по строкам

	for (currStr = 1; currStr <= countStrs; currStr++) {
		idxL = countElInStr * (currStr - 1); 
		idxR = idxL + countElInStr - 1;

		if ((elem >= idxL) && (elem <= idxR))
			return currStr;
	}
}

// Функция хода короля для поля:
void stepKing(int *A, int strs, int countElInStr, int S, int F) {		// массив, кол-во строк,кол-во эл-в в строке, начальное положение, конечное положение  
	int strBegin, strFinish, currStr, curEl, i, idxR, idxL, changeStr;

	changeStr = countElInStr-1;
	strBegin = searchCurrStr(strs, countElInStr, S);
	strFinish = searchCurrStr(strs, countElInStr, F);
	currStr = strBegin;
	idxL = countElInStr * (currStr - 1);
	idxR = idxL + countElInStr - 1;
	curEl = S;
	
	printf_s("%d	", curEl);						//выводим текущий элемент на экран

	if (currStr == strFinish) {						//если король на финишной строке

		if (curEl < F) 
			stepKing(A, strs, countElInStr, ++curEl, F);
		if (curEl > F)
			stepKing(A, strs, countElInStr, --curEl, F);
		if (curEl == F)
			return;
	}			

	if (currStr < strFinish)  {						//если король выше финиша 
		
		if (curEl != idxR){						//если король не в крайней правой клетке  ->|
			curEl++;
			printf_s("%d	", curEl);
			curEl += changeStr;
			stepKing(A, strs, countElInStr, curEl, F);
		}

		if (curEl == idxR) {						//если король в крайней правой клетке |_>
			curEl += changeStr;
			stepKing(A, strs, countElInStr, curEl, F);
		}
	}

	if (currStr > strFinish) {						//если король ниже финиша

		if (curEl != idxL) {						//если король не в левой крайней клетке
			curEl--;
			printf_s("%d	", curEl);
			curEl -= changeStr;
			stepKing(A, strs, countElInStr, curEl, F);
		}

		if (curEl == idxL) {						//если король в левой клетке
			curEl -= changeStr;
			stepKing(A, strs, countElInStr, curEl, F);
		}
	}

	return;
}

void main() {
	setlocale(LC_ALL, "Rus");
	int *A, i,j,k, begin, finish, strs, countElstr, el, countEl;

	printf_s("\nВведите кол-во строк поля\n");
	if (scanf_s("%d", &strs) != 1 ) {
		printf_s("Ошибка ввода числа\n");
		system("pause");
		return;
	}
	
	printf_s("\nВведите кол-во элементов в строке\n");
	if (scanf_s("%d", &countElstr) != 1 ) {
		printf_s("Ошибка ввода числа\n");
		system("pause");
		return;
	}

	if (strs == 0 || countElstr == 0) {
		printf_s("Элементов не найдено\n");
		system("pause");
		return;
	}
	
	countEl = countElstr * strs;							// Всего элементов на поле
	printf_s("Всего элементов в поле:	от 1 до %d\n\n", countEl);

	//работа с начальным положением:
	printf_s("\nВведите начальное положение\n");  
	if (scanf_s("%d", &begin)!=1){							// Если введено не число
		printf_s("Ошибка ввода числа\n");
		system("pause");
		return;
	}
	if ((begin <= 0) || (begin > countEl)) {
		printf_s("Выход за рамки поля\n\n");
		system("pause");
		return;
	}

	//работа с конечным положением:
	printf_s("\nВведите конечное положение\n");
	if (scanf_s("%d", &finish) != 1) {						// Если введено не число 
		printf_s("Ошибка ввода числа\n");
		system("pause");
		return;
	}
	if ((finish <= 0) || (finish > countEl)) {
		printf_s("Выход за рамки поля\n\n");
		system("pause");
		return;
	}

	if (begin == finish) {
		printf_s("Вы уже в конечной точке\n\n");
		system("pause");
		return;
	}

	if (countElstr == 1) {
		printf_s("\nКороль не ходит по диагонали!\n\n");
		system("pause");
		return;
	}
	begin --;
	finish --;

	if (!(A = (int*)malloc(countEl * sizeof(int))))
		return;
	el = 0;
	for (i = 0; i < countEl; i++)
		A[i] = ++el;

	printf_s("\nКороль прошел по пути:\t");

	stepKing( A, strs, countElstr, begin, finish);

	printf_s("\n\n");

	free(A);
	system("pause");
	return;
}
