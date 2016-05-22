// Lab3.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <conio.h>
#include <cstdlib>
#include <fstream>

#define filename "studs.txt"

void filewrite(void); // ������ � ����
void fileread(void); // ������ �� �����
void fileedit(void); // �������������� �����
void filedelete(void); // �������� ���� �� �����
void fileexist(void); // �������� �� ������������� �����
void filecreate(void); // �������� �����

const int ch = 10; // ���-�� ���������
FILE *f;
struct stds { // ��������� ��� ��������� � ������
	char lname[50];
	int mark;
} student[ch];
/*
struct stds_sorted { // ��������� ��� ��������� � ������
	char lnam[50];
	int mar[1];
} student_sorted[ch];
*/

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	
	int choice;
	cout << "�������� ������ �����: \n";
	cout << "1. ������� ���� \n";
	cout << "2. �������� ������ � ���� \n";
	cout << "3. ��������� ������ �� ����� \n";
	cout << "4. ������������� ���� \n";
	cout << "5. ������� ���� \n";
	cout << "6. ����� \n\n";
	
	cout << "������� �����:";
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
		cout << "��� ����� �����. ������ ����� ������ \n";
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
		cout << "������� ������� �������� �" << i + 1 << ":";
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
		cout << "����� �� ����������. �������� ��� ������ ����.\n\n";
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
		cout << "����� �� ����������. �������� ��� ������ ����.\n\n";
		main();
	}
	cout << "������� ������� ��������?";
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
		cout << "���� ��� ����������.\n"; // ������� ��������� � ������ ��������?
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
		cout << "���� ��� ����������.\n\n";
		main();
	}

}
