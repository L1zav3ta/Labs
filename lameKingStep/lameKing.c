//������� ����������� ��� ������

#include <stdio.h>
#include <stdlib.h>

/* ������� � ������ ������� i-� ������ ���� ������� �������� 
	�, ���� ������ ��� ������� ��������� ����� ����� ��������, ������ �� � i-� ������ :*/

int searchCurrStr(int countStrs, int countElInStr, int elem) {		//���-�� �����, ���-�� ��-� � ������, ������� ������
	int currStr, idxR, idxL;										// currStr - ������� �� �������

	for (currStr = 1; currStr <= countStrs; currStr++) {
		idxL = countElInStr * (currStr - 1);
		idxR = idxL + countElInStr - 1;

		if ((elem >= idxL) && (elem <= idxR))
			return currStr;
	}
}

/* ������� ��������� ��������� �����
	1)���� ������ �����, ������� ����� �� ��� � ����������� ��� ������� ������
	2)���� ������ ����� ������� ����, �� ���������� ���� �� ������ ������ � ��� ��� ��������� � �.1)
	3)���� ������ ������� ����, �� ����������� ����� �� ������ ������ � ��������� � �.1)
*/

void stepKing(int *A, int strs, int countElInStr, int S, int F) {	
	// ������, ���-�� �����,���-�� ��-� � ������, ��������� ���������, �������� ���������  
	int strBegin, strFinish, currStr, curEl, idxR, idxL, changeStr;	

	changeStr = countElInStr - 1;										//����� ��� ��������/������ �� ������
	strBegin = searchCurrStr(strs, countElInStr, S);
	strFinish = searchCurrStr(strs, countElInStr, F);
	currStr = strBegin;
	idxL = countElInStr * (currStr - 1);
	idxR = idxL + countElInStr - 1;
	curEl = S;
	 
	printf_s("%d	", curEl+1);										//������� ������� ������� �� �����

	if (currStr == strFinish) {											//���� ������ �� �������� ������

		if (curEl < F)
			stepKing(A, strs, countElInStr, ++curEl, F);
		if (curEl > F)
			stepKing(A, strs, countElInStr, --curEl, F);
		if (curEl == F)
			return;
	}

	if (currStr < strFinish) {											//���� ������ ���� ������ 

		if (curEl != idxR) {											//���� ������ �� � ������� ������ ������  ->|
			curEl++;
			printf_s("%d	", curEl+1);
			curEl += changeStr;
			stepKing(A, strs, countElInStr, curEl, F);
		}

		if (curEl == idxR) {											//���� ������ � ������� ������ ������ |_>
			curEl += changeStr;
			stepKing(A, strs, countElInStr, curEl, F);
		}
	}

	if (currStr > strFinish) {											//���� ������ ���� ������

		if (curEl != idxL) {											//���� ������ �� � ����� ������� ������
			curEl--;
			printf_s("%d	", curEl+1);
			curEl -= changeStr;
			stepKing(A, strs, countElInStr, curEl, F);
		}

		if (curEl == idxL) {											//���� ������ � ����� ������
			curEl -= changeStr;
			stepKing(A, strs, countElInStr, curEl, F);
		}
	}

	return;
}