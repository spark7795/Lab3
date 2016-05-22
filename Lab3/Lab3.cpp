// Lab3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <conio.h>
#include <cstdlib>
#include <fstream>

#define filename "studs.txt"

void filewrite(void); // Запись в файл
void fileread(void); // Чтение из файла
void fileedit(void); // Редактирование файла
void filedelete(void); // Удаление инфы из файла
void fileexist(void); // Проверка на существование файла
void filecreate(void); // Создание файла

const int ch = 10; // Кол-во студентов
FILE *f;
struct stds { // Структура для студентов и баллов
	char lname[50];
	int mark;
} student[ch];
/*
struct stds_sorted { // Структура для студентов и баллов
	char lnam[50];
	int mar[1];
} student_sorted[ch];
*/

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	
	int choice;
	cout << "Выберите нужную опцию: \n";
	cout << "1. Создать файл \n";
	cout << "2. Записать данные в файл \n";
	cout << "3. Прочитать данные из файла \n";
	cout << "4. Редактировать файл \n";
	cout << "5. Удалить файл \n";
	cout << "6. Выход \n\n";
	
	cout << "Введите цифру:";
	cin >> choice;
	switch (choice) {
	case 1: {
		filecreate();
		break;

	}
	case 2: {
		filewrite();
		break;

	}
	case 3: {
		fileread();
		break;
	}
	case 4: {
		fileedit();
		break;

	}
	case 5: {
		filedelete();
		break;
	}
	case 6: {
		return 0;
	}
	default: {
		system("cls");
		cout << "Нет такой опции. Сделай выбор заново \n";
		main();

	}
	}
	system("pause");
    return 0;
}

void filewrite()
{
	fileexist();

	for (int i=0;i<ch;i++)
	{
		cout << "Введите фамилию студента №" << i + 1 << ":";
		cin >> student[i].lname;
		int temp = rand() % 4 + 2;
		cout << temp;
		student[i].mark = temp;
	}
	for (int i = 0;i < ch;i++) fwrite(&student[i], sizeof(struct stds), 1, f);
	fclose(f);
}

void fileread(void)
{
	if ((f = fopen(filename, "r")) == NULL) {
		system("cls");
		cout << "Файла не существует. Создайте для начала файл.\n\n";
		main();
	}
	else {
		int num = 0,i;
		for ( i = 0;i < ch;i++) {
			if (fread(&student[i], sizeof(struct stds), 1, f) != ferror(f)) num++;
			else break;
		}
		for (i = 0;i < ch;i++) {
			cout << student[i].lname << "\t" << student[i].mark << "\n";
		}
	}

}

void fileedit(void)
{
	if ((f = fopen(filename, "r")) == NULL) {
		system("cls");
		cout << "Файла не существует. Создайте для начала файл.\n\n";
		main();
	}
	cout << "Сколько человек добавить?";
	int pp, i;
	cin >> pp;
	for(i=0;i<pp;i++)



}

void filedelete(void)
{
	fileexist();
}

void fileexist(void)
{
	ofstream outfile;
	FILE *f = fopen(filename, "r");
	if (f == NULL) outfile.open(filename);
	else {
		system("cls");
		cout << "Файл уже существует.\n"; // Вывести сообщение о успехе создания?
		//main();
	}


}

void filecreate(void)
{
	ofstream outfile;
	FILE *f = fopen(filename, "r");
	if (f == NULL) outfile.open(filename);
	else {
		system("cls");
		cout << "Файл уже существует.\n\n";
		main();
	}

}
