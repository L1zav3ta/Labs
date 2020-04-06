//функции необходимые для работы

#include <stdio.h>
#include <stdlib.h>

/* Функция в каждой текущей i-й строке ищет крайние элементы 
	и, если нужный нам элемент находится между этими крайними, значит он в i-й строке :*/

int searchCurrStr(int countStrs, int countElInStr, int elem) {		//кол-во строк, кол-во эл-в в строке, элемент поиска
	int currStr, idxR, idxL;										// currStr - бегунок по строкам

	for (currStr = 1; currStr <= countStrs; currStr++) {
		idxL = countElInStr * (currStr - 1);
		idxR = idxL + countElInStr - 1;

		if ((elem >= idxL) && (elem <= idxR))
			return currStr;
	}
}

/* Функция проверяет равенство строк
	1)если строки равны, функция ходит по ней в зависимости где элемент финиша
	2)если король будет строкой выше, то спускаемся вниз до строки финиша и там уже переходим к п.1)
	3)если король строкой ниже, то поднимаемся вверх до строки финиша и переходим к п.1)
*/

void stepKing(int *A, int strs, int countElInStr, int S, int F) {	
	// массив, кол-во строк,кол-во эл-в в строке, начальное положение, конечное положение  
	int strBegin, strFinish, currStr, curEl, idxR, idxL, changeStr;	

	changeStr = countElInStr - 1;										//нужен для поднятия/спуска на строку
	strBegin = searchCurrStr(strs, countElInStr, S);
	strFinish = searchCurrStr(strs, countElInStr, F);
	currStr = strBegin;
	idxL = countElInStr * (currStr - 1);
	idxR = idxL + countElInStr - 1;
	curEl = S;
	 
	printf_s("%d	", curEl+1);										//выводим текущий элемент на экран

	if (currStr == strFinish) {											//если король на финишной строке

		if (curEl < F)
			stepKing(A, strs, countElInStr, ++curEl, F);
		if (curEl > F)
			stepKing(A, strs, countElInStr, --curEl, F);
		if (curEl == F)
			return;
	}

	if (currStr < strFinish) {											//если король выше финиша 

		if (curEl != idxR) {											//если король не в крайней правой клетке  ->|
			curEl++;
			printf_s("%d	", curEl+1);
			curEl += changeStr;
			stepKing(A, strs, countElInStr, curEl, F);
		}

		if (curEl == idxR) {											//если король в крайней правой клетке |_>
			curEl += changeStr;
			stepKing(A, strs, countElInStr, curEl, F);
		}
	}

	if (currStr > strFinish) {											//если король ниже финиша

		if (curEl != idxL) {											//если король не в левой крайней клетке
			curEl--;
			printf_s("%d	", curEl+1);
			curEl -= changeStr;
			stepKing(A, strs, countElInStr, curEl, F);
		}

		if (curEl == idxL) {											//если король в левой клетке
			curEl -= changeStr;
			stepKing(A, strs, countElInStr, curEl, F);
		}
	}

	return;
}