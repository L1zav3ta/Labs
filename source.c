/*Тренирока работы на клавиатуре*/
/*РАБОТА СО СТАТИСТИКОЙ*/
/*в файле находит графу уровень - возвращает функцию уровня*/
/*Изменить статистику юзера */
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<time.h>
#include<random>
#include<Windows.h>
#define N 60
#define Abs(x) ((x) > 0) ? (x) : -(x)
#define MAX_NAME 21
#define COUNT_LEVEL 17
enum ConsoleColor {
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};
int Uppercase_letters(char c)
{
	switch (c)
	{
	case 'F':printf("%c", 128); break;
	case '<':printf("%c", 129); break;
	case 'D':printf("%c", 130); break;
	case 'U':printf("%c", 131); break;
	case 'L':printf("%c", 132); break;
	case 'T':printf("%c", 133); break;
	case ':':printf("%c", 134); break;
	case 'P':printf("%c", 135); break;
	case 'B':printf("%c", 136); break;
	case 'Q':printf("%c", 137); break;
	case 'R':printf("%c", 138); break;
	case 'K':printf("%c", 139); break;
	case 'V':printf("%c", 140); break;
	case 'Y':printf("%c", 141); break;
	case 'J':printf("%c", 142); break;
	case 'G':printf("%c", 143); break;
	case 'H':printf("%c", 144); break;
	case 'C':printf("%c", 145); break;
	case 'N':printf("%c", 146); break;
	case 'E':printf("%c", 147); break;
	case 'A':printf("%c", 148); break;
	case '{':printf("%c", 149); break;
	case 'W':printf("%c", 150); break;
	case 'X':printf("%c", 151); break;
	case 'I':printf("%c", 152); break;
	case 'O':printf("%c", 153); break;
	case '}':printf("%c", 154); break;
	case 'S':printf("%c", 155); break;
	case 'M':printf("%c", 156); break;
	case'\"':printf("%c", 157); break;
	case '>':printf("%c", 158); break;
	case 'Z':printf("%c", 159); break;
	case '~':printf("%c", 240); break;
	default:return 0;
	}
	return 1;
}
int Lowerercase_letters(char c)
{
	switch (c)
	{
	case 'f':printf("%c", 160); break;
	case ',':printf("%c", 161); break;
	case 'd':printf("%c", 162); break;
	case 'u':printf("%c", 163); break;
	case 'l':printf("%c", 164); break;
	case 't':printf("%c", 165); break;
	case ';':printf("%c", 166); break;
	case 'p':printf("%c", 167); break;
	case 'b':printf("%c", 168); break;
	case 'q':printf("%c", 169); break;
	case 'r':printf("%c", 170); break;
	case 'k':printf("%c", 171); break;
	case 'v':printf("%c", 172); break;
	case 'y':printf("%c", 173); break;
	case 'j':printf("%c", 174); break;
	case 'g':printf("%c", 175); break;
	case 'h':printf("%c", 224); break;
	case 'c':printf("%c", 225); break;
	case 'n':printf("%c", 226); break;
	case 'e':printf("%c", 227); break;
	case 'a':printf("%c", 228); break;
	case '[':printf("%c", 229); break;
	case 'w':printf("%c", 230); break;
	case 'x':printf("%c", 231); break;
	case 'i':printf("%c", 232); break;
	case 'o':printf("%c", 233); break;
	case ']':printf("%c", 234); break;
	case 's':printf("%c", 235); break;
	case 'm':printf("%c", 236); break;
	case'\'':printf("%c", 237); break;
	case '.':printf("%c", 238); break;
	case 'z':printf("%c", 239); break;
	case '`':printf("%c", 241); break;
	default: return 0;
	}
	return 1;
}
void speak(char str[])
{
	int l = N;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int j = 0; j < l&&str[j] != '\0'; j++)
	{
		if (str[j] == 1) {
			SetConsoleTextAttribute(hConsole, (WORD)((White << 4) | LightBlue));
			printf("%c", 1);
			SetConsoleTextAttribute(hConsole, (WORD)((White << 4) | Black));
			continue;
		}
		if (Uppercase_letters(str[j]))
			continue;
		if (Lowerercase_letters(str[j]))
			continue;
		printf("%c", str[j]);
	}
}
/*
Russian:
level_1:  ваол
level_2:  фыдж
level_3:  ваол фыдж
level_4:  прао
level_5:  фывап ролдж
level_6:  енит
level_7:  кгмь
level_8:  кенг мить
level_9:  кенг апро мить
level_10: ушсб
level_11: цщюч
level_12: цушщ чсбю
level_13: цукенгшщ ывапролд чсмитьбю
level_14: йфя зж. хъэ
level_15: йцфыяч ъхзэж.ю
level_16: level_9
level_17: ALL_LATTERS
*/
char level_1()
{
	short i = rand() % 4; /*В уровне 4 буквы*/
	switch (i)
	{
	default: return 0;
	case 0: return 'D';/*в*/ break;
	case 1: return 'F';/*а*/ break;
	case 2: return 'J';/*о*/ break;
	case 3: return 'K';/*л*/ break;
	};
}
char level_2()
{
	short i = rand() % 4; /*В уровне 4 буквы*/
	switch (i)
	{
	default: return 0;
	case 0: return 'A';/*ф*/ break;
	case 1: return 'S';/*ы*/ break;
	case 2: return 'L';/*д*/ break;
	case 3: return ':';/*ж*/ break;
	};
}
char level_3()
{
	short i = rand() % 8; /*В уровне 8 букв*/
	switch (i)
	{
	default: return 0;
	case 0: return 'A';/*ф*/ break;
	case 1: return 'S';/*ы*/ break;
	case 2: return 'L';/*д*/ break;
	case 3: return ':';/*ж*/ break;
	case 4: return 'D';/*в*/ break;
	case 5: return 'F';/*а*/ break;
	case 6: return 'J';/*о*/ break;
	case 7: return 'K';/*л*/ break;
	};
}
char level_4()
{
	short i = rand() % 4; /*В уровне 4 буквы*/
	switch (i)
	{
	default: return 0;
	case 0: return 'G';/*п*/ break;
	case 1: return 'H';/*р*/ break;
	case 2: return 'F';/*а*/ break;
	case 3: return 'J';/*о*/ break;
	};
}
char level_5()
{
	short i = rand() % 10; /*В уровне 10 букв*/
	switch (i)
	{
	default: return 0;
	case 0: return 'A';/*ф*/ break;
	case 1: return 'S';/*ы*/ break;
	case 2: return 'L';/*д*/ break;
	case 3: return ':';/*ж*/ break;
	case 4: return 'D';/*в*/ break;
	case 5: return 'F';/*а*/ break;
	case 6: return 'J';/*о*/ break;
	case 7: return 'K';/*л*/ break;
	case 8: return 'G';/*п*/ break;
	case 9: return 'H';/*р*/ break;
	};
}
char level_6()
{
	short i = rand() % 4; /*В уровне 4 буквы*/
	switch (i)
	{
	default: return 0;
	case 0: return 'T';/*е*/ break;
	case 1: return 'Y';/*н*/ break;
	case 2: return 'B';/*и*/ break;
	case 3: return 'N';/*т*/ break;
	};
}
char level_7()
{
	short i = rand() % 4; /*В уровне 4 буквы*/
	switch (i)
	{
	default: return 0;
	case 0: return 'R';/*к*/ break;
	case 1: return 'U';/*г*/ break;
	case 2: return 'V';/*м*/ break;
	case 3: return 'M';/*ь*/ break;
	};
}
char level_8()
{
	short i = rand() % 8; /*В уровне 8 букв*/
	switch (i)
	{
	default: return 0;
	case 0: return 'R';/*к*/ break;
	case 1: return 'T';/*е*/ break;
	case 2: return 'Y';/*н*/ break;
	case 3: return 'U';/*г*/ break;
	case 4: return 'V';/*м*/ break;
	case 5: return 'B';/*и*/ break;
	case 6: return 'N';/*т*/ break;
	case 7: return 'M';/*ь*/ break;
	};
}
char level_9()
{
	short i = rand() % 12; /*В уровне 12 букв*/
	switch (i)
	{
	default: return 0;
	case 0: return 'R';/*к*/ break;
	case 1: return 'T';/*е*/ break;
	case 2: return 'Y';/*н*/ break;
	case 3: return 'U';/*г*/ break;
	case 4: return 'V';/*м*/ break;
	case 5: return 'B';/*и*/ break;
	case 6: return 'N';/*т*/ break;
	case 7: return 'M';/*ь*/ break;
	case 8: return 'G';/*п*/ break;
	case 9: return 'H';/*р*/ break;
	case 10: return 'F';/*а*/ break;
	case 11: return 'J';/*о*/ break;
	};
}
char level_10()
{
	short i = rand() % 4; /*В уровне 4 буквы*/
	switch (i)
	{
	default: return 0;
	case 0: return 'E';/*у*/ break;
	case 1: return 'I';/*ш*/ break;
	case 2: return 'C';/*с*/ break;
	case 3: return '<';/*б*/ break;
	};
}
char level_11()
{
	short i = rand() % 4; /*В уровне 4 буквы*/
	switch (i)
	{
	default: return 0;
	case 0: return 'W';/*ц*/ break;
	case 1: return 'O';/*щ*/ break;
	case 2: return 'X';/*ч*/ break;
	case 3: return '>';/*ю*/ break;
	};
}
char level_12()
{
	short i = rand() % 8; /*В уровне 8 букв*/
	switch (i)
	{
	default: return 0;
	case 0: return 'W';/*ц*/ break;
	case 1: return 'E';/*у*/ break;
	case 2: return 'I';/*ш*/ break;
	case 3: return 'O';/*щ*/ break;
	case 4: return 'X';/*ч*/ break;
	case 5: return 'C';/*с*/ break;
	case 6: return '<';/*б*/ break;
	case 7: return '>';/*ю*/ break;
	};
}
char level_13()
{
	short i = rand() % 24; /*В уровне 24 буквы*/
	switch (i)
	{
	default: return 0;
	case 0: return 'W';/*ц*/ break;
	case 1: return 'E';/*у*/ break;
	case 2: return 'R';/*к*/ break;
	case 3: return 'T';/*е*/ break;
	case 4: return 'Y';/*н*/ break;
	case 5: return 'U';/*г*/ break;
	case 6: return 'I';/*ш*/ break;
	case 7: return 'O';/*щ*/ break;
	case 8: return 'S';/*ы*/ break;
	case 9: return 'S';/*в*/ break;
	case 10: return 'F';/*а*/ break;
	case 11: return 'G';/*п*/ break;
	case 12: return 'H';/*р*/ break;
	case 13: return 'J';/*о*/ break;
	case 14: return 'K';/*л*/ break;
	case 15: return 'L';/*д*/ break;
	case 16: return 'X';/*ч*/ break;
	case 17: return 'C';/*с*/ break;
	case 18: return 'V';/*м*/ break;
	case 19: return 'B';/*и*/ break;
	case 20: return 'N';/*т*/ break;
	case 21: return 'M';/*ь*/ break;
	case 22: return '<';/*б*/ break;
	case 23: return '>';/*ю*/ break;
	};
}
char level_14()
{
	short i = rand() % 9; /*В уровне 9 букв*/
	switch (i)
	{
	default: return 0;
	case 0: return 'Q';/*й*/ break;
	case 1: return 'A';/*ф*/ break;
	case 2: return 'Z';/*я*/ break;
	case 3: return 'P';/*з*/ break;
	case 4: return ':';/*ж*/ break;
	case 5: return '/';/*.*/ break;
	case 6: return '{';/*х*/ break;
	case 7: return '}';/*ъ*/ break;
	case 8: return '\"';/*э*/ break;
	};
}
char level_15()
{
	short i = rand() % 12; /*В уровне 12 букв*/
	switch (i)
	{
	default: return 0;
	case 0: return 'Q';/*й*/ break;
	case 1: return 'W';/*ц*/ break;
	case 2: return 'A';/*ф*/ break;
	case 3: return 'S';/*ы*/ break;
	case 4: return 'Z';/*я*/ break;
	case 5: return 'X';/*ч*/ break;
	case 6: return 'P';/*з*/ break;
	case 7: return ':';/*ж*/ break;
	case 8: return '/';/*.*/ break;
	case 9: return '{';/*х*/ break;
	case 10: return '\"';/*э*/ break;
	case 11: return '}';/*ъ*/ break;
	};
}
char level_17()
{
	short i = rand() % 33; /*В уровне 33 буквы (с '.' без 'ё')*/
	switch (i)
	{
	default: return 0;
	case 0: return 'W';/*ц*/ break;
	case 1: return 'E';/*у*/ break;
	case 2: return 'R';/*к*/ break;
	case 3: return 'T';/*е*/ break;
	case 4: return 'Y';/*н*/ break;
	case 5: return 'U';/*г*/ break;
	case 6: return 'I';/*ш*/ break;
	case 7: return 'O';/*щ*/ break;
	case 8: return 'S';/*ы*/ break;
	case 9: return 'D';/*в*/ break;
	case 10: return 'F';/*а*/ break;
	case 11: return 'G';/*п*/ break;
	case 12: return 'H';/*р*/ break;
	case 13: return 'J';/*о*/ break;
	case 14: return 'K';/*л*/ break;
	case 15: return 'L';/*д*/ break;
	case 16: return 'X';/*ч*/ break;
	case 17: return 'C';/*с*/ break;
	case 18: return 'V';/*м*/ break;
	case 19: return 'B';/*и*/ break;
	case 20: return 'N';/*т*/ break;
	case 21: return 'M';/*ь*/ break;
	case 22: return '<';/*б*/ break;
	case 23: return '>';/*ю*/ break;
	case 24: return 'Q';/*й*/ break;
	case 25: return 'A';/*ф*/ break;
	case 26: return 'Z';/*я*/ break;
	case 27: return 'P';/*з*/ break;
	case 28: return ':';/*ж*/ break;
	case 29: return '/';/*.*/ break;
	case 30: return '{';/*х*/ break;
	case 31: return '}';/*ъ*/ break;
	case 32: return '\"';/*э*/ break;
	};
}
struct user
{
	char name[MAX_NAME];
	struct user *next;
};
void Print_choose_user(user* &head, user* &now, char s[])
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	for (int i = 0; s[i] != '.'&&s[i] != '\0'; i++)
		printf("%c", s[i]);
	printf("\n\n");
	for (user *q = head; q != NULL; q = q->next)
	{
		if (q == now)
			SetConsoleTextAttribute(hConsole, (WORD)((LightGreen << 4) | Black));
		printf("\n%s\n", q);
		SetConsoleTextAttribute(hConsole, (WORD)((White << 4) | Black));
	}
}
user* Create_user_element(char s[])
{
	struct user *newuser = (struct user*)malloc(sizeof(struct user));
	if (newuser == NULL)
		return NULL;
	for (int i = 0;; i++)
	{
		newuser->name[i] = s[i];
		if (s[i] == '\0')
			break;
	}
	if (newuser->name[0] == '\0')
		return NULL;
	newuser->next = NULL;
	return newuser;
}
void Add_user_begin(user* &head, user* &newuser)
{
	newuser->next = head;
	head = newuser;
	return;
}
void Add_user_after(user* &head, user* &newuser, user* &after)
{
	if (newuser == NULL)
		return;
	if (after == NULL)
	{
		Add_user_begin(head, newuser);
		return;
	}
	newuser->next = after->next;
	after->next = newuser;
}
void Delete_user_element(user* &head, user *p)
{
	if (p == head)
		head = p->next;
	else
	{
		user *q = head;
		while (q && q->next != p)
			q = q->next;
		if (q == NULL)
			return;
		q->next = p->next;
	}
	free(p);
	return;
}
void Delete_user_all(user* &head)
{
	while (head != NULL)
		Delete_user_element(head, head);
	return;
}
user* Found_position_user(user* &head, char s[])
{
	//if(head!=NULL)/*надо, чтобы new был всегда в начале*/
	//	for(int i=0;s[i]!='\0';i++)
	//	{
	//		if( head->name[i] > s[i] )
	//			return NULL;
	//		if( head->name[i] < s[i] )
	//			break;
	//	}
	for (user *q = head; q != NULL; q = q->next)
	{
		if (q->next == NULL)
			return q;
		for (int i = 0; s[i] != '\0'; i++)
		{
			if (q->next->name[i] > s[i])
				return q;
			if (q->next->name[i] < s[i])
				break;
		}
	}
	return NULL;
}
void All_users(FILE *&fin, user* &head)
{
	if (fin != NULL)
		fclose(fin);
	fin = fopen("users.txt", "rt");
	char c = fgetc(fin), s[MAX_NAME];
	int i = 0;
	user *newuser = NULL, *after = NULL;
	while (c != EOF)
	{
		if (c == '\0' || c == '\n')
		{
			s[i] = '\0';
			newuser = Create_user_element(s);
			after = Found_position_user(head, s);
			Add_user_after(head, newuser, after);
			i = 0;
			c = fgetc(fin);
		}
		s[i] = c;
		i++;
		c = fgetc(fin);
	}
}
user* End_user(user* &head, user* &prev)
{
	user *q = head;
	if (q == NULL)
		return NULL;
	if (q->next == NULL)
	{
		prev = NULL;
		return head;
	}
	while (q->next->next != NULL) q = q->next;
	prev = q;
	return q->next;
}
user* Prev_user(user* &head, user* &prev)
{
	if (head->next == NULL)
		return head;
	if (prev == NULL)
		return End_user(head, prev);
	if (prev == head)
	{
		prev = NULL;
		return head;
	}
	user *q = head;
	while (q->next != prev) q = q->next;
	prev = q;
	return prev->next;
}
int Mooving(char c, user* &head, user* &now, user* &prev, user* &end)
{
	if (c == -32)
		c = _getch();
	switch (c)
	{
	default: return 0;
	case 80:
		if (now->next == NULL) { prev = NULL; now = head; break; }
		else { prev = now; now = now->next; break; }
	case 72:
		if (prev == NULL) { now = End_user(head, prev); break; }
		else { now = Prev_user(head, prev); break; }
	case 27: return 666;
	case 13: return 1;
	};
	return 0;
}
void Add_file_user(char s[], FILE* &fin, user* &head)
{
	if (fin != NULL)
		fclose(fin);
	fin = fopen("users.txt", "wt");
	for (user *q = head; q != NULL; q = q->next)
		for (int i = 0;; i++)
		{
			if (q->name[i] == '\0')
			{
				fputc('\n', fin);
				break;
			}
			fputc(q->name[i], fin);
		}
	for (int i = 0;; i++)
	{
		if (s[i] == '.' || s[i] == '\0')
		{
			if (i == 0)
				break;
			fputc('\n', fin);
			break;
		}
		fputc(s[i], fin);
	}
	return;
}
int Can_latter_name(char c)
{
	if (c < 0)
		_getch();
	if (c >= 'a'&&c <= 'z')
		return 1;
	if (c >= 'A'&&c <= 'Z')
		return 1;
	if (c >= '0'&&c <= '9')
		return 1;
	if (c == 13 || c == 27 || c == 8)
		return 1;
	return 0;
}
void Add_txt(char s[])
{
	int i = 0;
	while (s[i] != '\0'&&s[i] != '.')
		i++;
	s[i] = '.';
	s[i + 1] = 't';
	s[i + 2] = 'x';
	s[i + 3] = 't';
	s[i + 4] = '\0';
}
void Printing_new_name(char s[], int i)
{
	int j;
	system("cls");
	printf("\n\n\n        YOUR NAME\n     ");
	for (j = 0; j < MAX_NAME - 5; j++)
		printf("_");
	printf("\r     ");
	for (j = 0; j < (MAX_NAME - i - 5) / 2; j++)
		printf("_");
	for (int g = 0; j < (MAX_NAME - i - 5) / 2 + i; j++, g++)
		printf("%c", s[g]);
	return;
}
int New_name(char s[])
{
	int i = 0;
	while (i < MAX_NAME)
		s[i++] = '\0';
	i = 0;
	while (i == 0)
	{
		char c = '*';
		while (c != '!')
		{
			Printing_new_name(s, i);
			do c = _getch(); while (!Can_latter_name(c));
			printf("\n\n");
			switch (c)
			{
			case 8: if (c == 8 && i > 0) { i--; continue; } break;
			case 27: return 0;
			case 13: c = '!'; break;
			default: if (i >= MAX_NAME - 5) continue; if (c >= 'a'&&c <= 'z'&&i == 0) c -= 'a' - 'A'; s[i] = c; i++; break;
			};
		}
	}
	Add_txt(s);
	return 1;
}
int Repeat_name(user* &head, char s[])
{
	if (head->next == NULL)
		return 0;
	for (user *q = head->next; q != NULL; q = q->next)
	{
		if (q->name[0] < s[0])
			continue;
		if (q->name[0] > s[0])
			return 0;
		for (int i = 0;; i++)
		{
			if (s[i] == '\0' || s[i] == '.')
			{
				if (q->name[i] == '\0')
					return 1;
				else
					return 0;
			}
			if (q->name[i] == '\0')
				return 0;
			if (tolower(q->name[i]) == tolower(s[i]))
				continue;
			if (q->name[i] != s[i])
				break;
		}
	}
	return 0;
}
void New_file(char s[])
{
	FILE *fout = fopen(s, "wt");
	fprintf(fout, "1\n");
	for (int i = 0; i < COUNT_LEVEL; i++)
		fprintf(fout, "0 1 0 \n");
	fclose(fout);
	return;
}
int New_user(FILE* &fin, user* &head, char s[])
{
	while (1)
	{
		if (New_name(s) == 0)
			return 0;
		if (Repeat_name(head, s))
		{
			printf("\n      Name already exists.\n\n");/*Имя уже есть!*/
			system("pause");
			continue;
		}
		else
			break;
	}
	New_file(s);
	Add_file_user(s, fin, head);
	Delete_user_all(head);
	return 1;
}
user* Choose_list(user* &head, char s[])
{
	char c;
	user *now = head, *prev = NULL, *end = End_user(head, prev);
	Print_choose_user(head, now, s);
	int move;
	while (1)
	{
		if (_kbhit())
		{
			c = _getch();
			move = Mooving(c, head, now, prev, end);
			if (move == 666) return NULL;
			if (move == 1) return now;
			Print_choose_user(head, now, s);
		}
	}
	return now;
}
int Create_action(user* &action)
{
	user* newaction;
	newaction = Create_user_element("Delete profile");
	if (newaction == NULL) return 0;
	Add_user_begin(action, newaction);
	newaction = Create_user_element("Give statistic");
	if (newaction == NULL) return 0;
	Add_user_begin(action, newaction);
	newaction = Create_user_element("PLAY");
	if (newaction == NULL) return 0;
	Add_user_begin(action, newaction);
	return 1;
}
int ERROR_404(char s1[], char s2[])
{
	if (s1 == NULL || s2 == NULL)
	{
		printf("\nERROR 404 STRING NOT FOUND\n");
		system("pause");
		return 1;
	}
	return 0;
}
int str_str(char s1[], char s2[])/*возвращает : 1, если s1 больше s2; 0, если строки равны; -1, если s2 больше s1*/
{
	if (ERROR_404(s1, s2))
		return 0;
	for (int i = 0;; i++)
	{
		if (s1[i] < 0 || s2[i] < 0)
		{
			printf("\nERROR string!\n");
			system("pause");
			return 0;
		}
		if ((s1[i] == '\0' || s1[i] == '.') && (s2[i] == '\0' || s2[i] == '.'))
			return 0;
		if (s1[i] > s2[i])
			return 1;
		if (s2[i] > s1[i])
			return -1;
	}
}
void Delete_profile_users(FILE* &fin, user* &nowuser, char s[])
{
	if (fin != NULL)
		fclose(fin);
	fin = fopen("users.txt", "wt");
	user *q = nowuser;
	while (str_str(s, q->name) != 0) q = q->next;
	Delete_user_element(nowuser, q);
	Add_file_user("", fin, nowuser);
	fclose(fin);
	fin = fopen("users.txt", "rt");
}
void Delete_profile(char s[], FILE* &fin, FILE* &fuser, user* &nowuser)
{
	user *head;
	Delete_profile_users(fin, nowuser, s);
	char sdel[MAX_NAME + 4] = "DEL ";
	for (int i = 4; s[i - 4] != '.'; i++)
		sdel[i] = s[i - 4];
	Add_txt(sdel);
	fclose(fuser);
	system(sdel);
	system("pause");
	return;
}
struct statistic
{
	int lvl;
	int exp;
	double speed;
	int wr;
};
void Create_user_temp(char s[])
{
	FILE *fuser, *temp;
	fuser = fopen(s, "rt");
	temp = fopen("temp.txt", "wt");
	char c = fgetc(fuser);
	while (c != EOF)
	{
		fputc(c, temp);
		c = fgetc(fuser);
	}
	fclose(fuser);
	fclose(temp);
}
int Give_lvl()
{
	FILE *temp = fopen("temp.txt", "rt");
	int lvl;
	fscanf(temp, "%d", &lvl);
	fclose(temp);
	return lvl;
}
void Give_parameters(statistic& st)
{
	st.lvl = Give_lvl();
	FILE *temp = fopen("temp.txt", "rt");
	char c = fgetc(temp);
	for (int i = 0; i < st.lvl; i++)
		for (c = fgetc(temp); c != '\n'; c = fgetc(temp));
	fscanf(temp, "%d", &st.exp);
	fscanf(temp, "%lf", &st.speed);
	fscanf(temp, "%d", &st.wr);
	fclose(temp);
	return;
}
statistic User_statistic(char s[])
{
	Create_user_temp(s);
	statistic user_st;
	Give_parameters(user_st);
	return user_st;
}
void Give_statistic(char s[])
{
	statistic st = User_statistic(s);
	/*speak("\nDfi ehjdtym - ");*/ printf("\n Your lavel -%d", st.lvl);
	/*speak("\nJgsn - ");*/ printf("\nExp - %d", st.exp);
	/*speak("\nCrjhjcnm - ");*/ printf("\nSpeed - %.3lf", st.speed);
	/*speak("\nJib,rb - ");*/ printf("\nWrongs - %d\n\n", st.wr);
	system("pause");
}
int Profile_action(char s[], char c, FILE* &fin, FILE* &fuser, user* &nowuser)
{
	switch (c)
	{
	default: fclose(fuser); return 0;
	case 'D': Delete_profile(s, fin, fuser, nowuser); return 0;
	case 'P': fclose(fuser); return 1;
	case 'G': fclose(fuser); Give_statistic(s);  return 0;
	};
	fclose(fuser);
	return 0;
}
int Profile(char s[], FILE* &fin, user* &nowuser)
{
	Add_txt(s);
	FILE *fuser = fopen(s, "rt");
	All_users(fin, nowuser);
	user *action = NULL, *now = NULL;
	Create_action(action);
	now = Choose_list(action, s);
	if (now == NULL)
	{
		fclose(fuser);
		return 0;
	}
	if (!Profile_action(s, now->name[0], fin, fuser, nowuser))
		return 0;
	return 1;
}
int User_now(FILE *&fin, char s[], user *head)
{
	All_users(fin, head);
	user *now;
	while (1)
	{
		now = Choose_list(head, "Select user:");
		if (now == NULL)
			return NULL;
		for (int i = 0;; i++)
		{
			s[i] = now->name[i];
			if (s[i] == '\0')
				break;
		}
		if (s[0] == 'n')
			if (New_user(fin, head, s)) return 1; else continue;
		else
			return 1;
	}
	return 0;
}
void Printing(char lat[], char bridge[], int level, int wrongs)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	SetConsoleTextAttribute(hConsole, (WORD)((LightGreen << 4) | Black));
	printf("level %d\n", level);
	SetConsoleTextAttribute(hConsole, (WORD)((White << 4) | Black));
	speak(lat);
	printf("\n");
	SetConsoleTextAttribute(hConsole, (WORD)((White << 4) | Brown));
	speak(bridge);
	SetConsoleTextAttribute(hConsole, (WORD)((White << 4) | Black));
	if (wrongs > 0) printf("\n\nworngs:%d", wrongs);
	printf("\n\n");
}
char YOUR_level(int level)
{
	switch (level)
	{
	default: printf("level ERROR"); return '1';
	case 1: return level_1();
	case 2: return level_2();
	case 3: return level_3();
	case 4: return level_4();
	case 5: return level_5();
	case 6: return level_6();
	case 7: return level_7();
	case 8: return level_8();
	case 9: return level_9();
	case 10: return level_10();
	case 11: return level_11();
	case 12: return level_12();
	case 13: return level_13();
	case 14: return level_14();
	case 15: return level_15();
	case 16: return level_9();
	case 17: return level_17();
	}
}
int Latters(char lat[], int level)
{
	for (int i = 0; i < N; i++)
		lat[i] = ' ';
	lat[1] = 1;
	for (int i = 2; i < N - 1; i++)
	{
		for (int j = i; i < j + rand() % 5 + 2 && i < N - 1; i++)
		{
			lat[i] = YOUR_level(level);
			if (lat[i] == '1')
				return 1;
		}
	}
	return 0;
}
int Press(char lat[], char bridge[], int *i, int *j, int *wrongs, statistic& user_st)
{
	char c = _getch();
	if (c >= 'a'&&c <= 'z')
		c -= 'a' - 'A';
	switch (c)
	{
	case'[':c = '{'; break;
	case']':c = '}'; break;
	case';':c = ':'; break;
	case'\'':c = '\"'; break;
	case',':c = '<'; break;
	case'.':c = '>'; break;
	default: break;
	}
	if (c == lat[*i])
	{
		if (*i >= N - 1)
		{
			user_st.speed = (user_st.speed + double(*j) / N) / 2;/*среднее арифметическое между текущим и имеющимся*/
			user_st.wr = (user_st.wr + (*wrongs)) / 2;/*среднее арифметическое между текущим и имеющимся*/
			user_st.exp++;/*Удачная игра +1 к пройденным*/
			if ((user_st.speed <= 0.3) && (*wrongs <= 6 - (user_st.lvl / 6)) && user_st.exp > 9)
			{
				if (user_st.lvl == COUNT_LEVEL)
					return 1;
				printf("\nCONGRATULATIONS!\nNew level %d\n\n", user_st.lvl);
				user_st.lvl++;
				user_st.exp = 0;
				user_st.speed = 1;
				user_st.wr = 0;
			}
			return 1;
		}
		lat[*i - 1] = ' ';
		lat[*i] = 1;
		*i = *i + 1;
		Printing(lat, bridge, user_st.lvl, *wrongs);
	}
	else
		*wrongs = *wrongs + 1;
	return 0;
}
int Timet(char lat[], char bridge[], int *i, int *j, int *timer, int level, int wrongs)
{
	if (*i >= N)
		return 1;
	*timer = time(NULL);
	bridge[*j] = ' ';
	*j = *j + 1;
	Printing(lat, bridge, level, wrongs);
	if (*i <= *j)
		return 0;
	return 3;
}
void ReadySetGO(char lat[], char bridge[], int level)
{

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int timer = time(NULL);
	Printing(lat, bridge, level, 0);
	SetConsoleTextAttribute(hConsole, (WORD)((LightRed << 4) | Black));
	printf("READY");
	SetConsoleTextAttribute(hConsole, (WORD)((White << 4) | Black));
	while (time(NULL) - timer < 2);
	Printing(lat, bridge, level, 0);
	SetConsoleTextAttribute(hConsole, (WORD)((Yellow << 4) | Black));
	printf("SET");
	SetConsoleTextAttribute(hConsole, (WORD)((White << 4) | Black));
	while (time(NULL) - timer < 3);
	Printing(lat, bridge, level, 0);
	SetConsoleTextAttribute(hConsole, (WORD)((LightGreen << 4) | Black));
	printf("GO");
	SetConsoleTextAttribute(hConsole, (WORD)((White << 4) | Black));
	while (time(NULL) - timer < 4);
	fflush(stdin);
}
int Dinamic(char lat[], char bridge[], statistic& user_st)/*+ успел; - не успел; n - допущено n ошибок*/
{
	system("pause");
	ReadySetGO(lat, bridge, user_st.lvl);
	int timer = time(NULL), i = 2, j = 0, wrongs = 0;
	while (1)
	{
		while (_kbhit())
			if (Press(lat, bridge, &i, &j, &wrongs, user_st))
				return wrongs;
		if (time(NULL) - timer > 1)
		{
			switch (Timet(lat, bridge, &i, &j, &timer, user_st.lvl, wrongs))
			{
			case 1: return wrongs;
			case 0: return -wrongs;
			default:;
			};
		}
	}
	return 0;
}
void Change_user_statistic(char s[], statistic& user_st)
{
	FILE *fuser = fopen(s, "wt"), *temp = fopen("temp.txt", "rt");
	fprintf(fuser, "%d\n", user_st.lvl);
	char c = fgetc(temp);
	for (c = fgetc(temp); c != '\n'; c = fgetc(temp));
	for (int i = 1; i < user_st.lvl; i++)
	{
		for (c = fgetc(temp);; c = fgetc(temp))
		{
			fputc(c, fuser);
			if (c == '\n')
				break;
		}
	}
	fprintf(fuser, "%d %.6lf %d\n", user_st.exp, user_st.speed, user_st.wr);
	for (c = fgetc(temp); c != '\n'; c = fgetc(temp));
	for (int i = user_st.lvl; i < COUNT_LEVEL; i++)
		for (c = fgetc(temp);; c = fgetc(temp))
		{
			fputc(c, fuser);
			if (c == '\n')
				break;
		}
	fclose(temp);
	fclose(fuser);
	return;
}
int Name_user(char s[], int repeat)
{
	FILE *fin;
	user *head = NULL;
	fin = fopen("users.txt", "rt");
	while (1)
	{
		if (!repeat)
		{
			for (int i = 0; i < MAX_NAME; i++) s[i] = 0;
			if (!User_now(fin, s, head))
				break;
		}
		if (Profile(s, fin, head))
			break;
		else
			repeat = 0;
		Delete_user_all(head);
	}
	fclose(fin);
	if (s[0] == '\0')
		return 1;
	return 0;
}
void Traning()
{
	char s[MAX_NAME + 4];
	int repeat = 0;
	while (1)
	{
		if (Name_user(s, repeat))
			return;
		Add_txt(s);
		statistic user_st = User_statistic(s);
		char lat[N], bridge[N];
		for (int i = 0; i < N; i++) bridge[i] = 219;
		if (Latters(lat, user_st.lvl)) return;
		int check = Dinamic(lat, bridge, user_st);
		if (check < 0) { printf("\nYou lost\n"); system("pause"); continue; }
		printf("\nYou make %d wrongs.\n", Abs(check));
		Change_user_statistic(s, user_st);
		system("pause");
		repeat = 1;
	}
}
void main()
{
	system("color F0");
	srand(time(NULL));
	Traning();
	system("pause");
	return;
}
