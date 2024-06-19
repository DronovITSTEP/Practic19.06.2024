#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <conio.h>

using namespace std;

#define MAX_PATH 260 // максимальная длина пути к файлу

#define NUM_COLS 18 // кол-во столбцов на экране
#define NUM_ROWS 24 // клд-во строк на экране


void main()
{
	setlocale(LC_ALL, "");
	//fstream();
	//
	//fstream(const char* name, // имя файла
	//	int mode, // режим открытия
	//	int filebuf); // защита файла
	//		// ios::in (0x01)
	//		// out (0x02)
	//		// ate (0x04)
	//		// app (0x08)
	//		// trunc (0x010)
	//		// _Nocreate
	//		// _Noreplace
	//		// binary
	//
	//fstream(int f); // дескриптор файла
	//
	//fstream(int f, // дескриптор файла
	//	char* buf, // буфер
	//	int len); // длина буфера

	//open();
	//close();

	//ifstream::read(char* buf, int len);
	//ofstream::write();

	//ofstream::put(char c);
	//ifstream:get(char* buf, int len);
	//getline();
	//ignore();
	//gcount();
	//peek();

	/*char path[MAX_PATH];
	cout << "Введите путь к файлу: ";
	cin.getline(path, MAX_PATH); //  вводим путь к файлу через консоль

	int counter = 0, i = 0, j = 0;
	char text[NUM_COLS];

	// открытие файла
	ifstream input(path, ios::in | ios::binary );

	if (!input) {
		cout << "Ошибка. Не удалось открыть файл\n";
		return;
	}

	cout.setf(ios::uppercase); // отображение данных в верхнем регистре

	while (!input.eof()) {
		for (i = 0; i < NUM_COLS && !input.eof(); i++) {
			input.get(text[i]);
		}

		if (i < NUM_COLS) i--;

		for (j = 0; j < i; j++) {
			if ((unsigned)text[j] < 0x10) 
			{
				cout << setw(2) << 0 << hex << (unsigned)text[j];
			}
			else
			{
				cout << setw(3) << hex << (unsigned)text[j];
			}
		}

		for (; j < NUM_COLS; j++) {
			cout << "    ";
		}
		cout << "\t";

		for (j = 0; j < i; j++) {
			if (text[j] > 31 && text[j] <= 255) {
				cout << text[j];
			}
			else {
				cout << ".";
			}
		}
		cout << "\n";

		if (++counter == NUM_ROWS) {
			counter = 0;
			cout << "Нажмите любую клавишу для продолжения..." << flush;
			_getch();
			cout << "\n";
		}
	}
	input.close();*/


}


