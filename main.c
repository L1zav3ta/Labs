//������������ ������ �1. ������: ������; ����: 7; �������: 2;
//�������: ������� ���� �� �������� ����� "�" � �������� ����� "b";
//���������: ��������� ��������� ���-13��;

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include "lameKing.h"

void main() {
	setlocale(LC_ALL, "Rus");
	int *arr, begin, finish, strs, countElstr, el, countEl;

	printf_s("\n������� ���-�� ����� ����\n");
	if (scanf_s("%d", &strs) != 1) {
		printf_s("\n������ ����� �����\n\n");
		system("pause");
		return;
	}

	printf_s("\n������� ���-�� ��������� � ������\n");
	if (scanf_s("%d", &countElstr) != 1) {
		printf_s("\n������ ����� �����\n\n");
		system("pause");
		return;
	}

	if (strs == 0 || countElstr == 0) {
		printf_s("\n��������� �� �������, ���������, �� ��� �� ������ 0\n\n");
		system("pause");
		return;
	}

	countEl = countElstr * strs;									// ����� ��������� �� ����
	printf_s("\n����� ��������� � ����:	�� 1 �� %d\n\n", countEl);

	//������ � ��������� ����������:
	printf_s("\n������� ��������� ���������\n");
	if (scanf_s("%d", &begin) != 1) {								// ���� ������� �� �����
		printf_s("\n������ ����� �����\n\n");
		system("pause");
		return;
	}
	if ((begin <= 0) || (begin > countEl)) {
		printf_s("\n����� �� ����� ����\n\n");
		system("pause");
		return;
	}

	//������ � �������� ����������:
	printf_s("\n������� �������� ���������\n");
	if (scanf_s("%d", &finish) != 1) {							// ���� ������� �� ����� 
		printf_s("\n������ ����� �����\n\n");
		system("pause");
		return;
	}
	if ((finish <= 0) || (finish > countEl)) {
		printf_s("\n����� �� ����� ����\n\n");
		system("pause");
		return;
	}

	if (begin == finish) {
		printf_s("\n�� ��� � �������� �����\n\n");
		system("pause");
		return;
	}

	if (countElstr == 1) {
		printf_s("\n������ �� ����� �� ���������!\n\n");
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

	printf_s("\n������ ������ �� ����:\t");

	stepKing(arr, strs, countElstr, begin, finish);

	printf_s("\n\n");

	free(arr);
	system("pause");
	return;
}