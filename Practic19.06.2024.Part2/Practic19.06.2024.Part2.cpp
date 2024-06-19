#include <iostream>
#include <fstream>
#include <Windows.h>
#include <iomanip>

using namespace std;

void main()
{
	char answer;
	const int messageCount = 8;
	int i, j;

	enum {CHOICE = 3, INPUT_FILENAME,
		INPUT_DIMENSIONS, INPUT_ELEMENTS,
		FILE_ERROR};

	char msg[messageCount][80] =
	{
		"1. Вывести данные из текстового файла\n",
		"2. Записать данные в текстовый файл\n",
		"3. Выход из программы\n",
		"\nВаш выбор: ",
		"Введите имя обрабатываемого файла: ",
		"Введите размерность матрицы: ",
		"Введите элементы матрицы: ",
		"Невозсожно открыть файл\n"
	};

	// руссификатор строк
	for (i = 0; i < messageCount; i++) {
		CharToOemA(msg[i], msg[i]);
	}

	do {
		for (i = 0; i < 4; i++)
			cout << msg[i];

		cin >> answer;
	} while (answer < '1' || answer > '3');

	if (answer == '3') return;

	char fileName[80];
	int m, n, num;

	cout << "\n" << msg[INPUT_FILENAME];
	cin >> fileName;

	if (answer == '1') 
	{
		ifstream inFile(fileName, ios::in | ios::_Nocreate);
		if (!inFile) {
			cout << "\n" << msg[FILE_ERROR];
			return;
		}

		inFile >> m >> n;

		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				inFile >> num;
				cout << setw(6) << num;
			}
			cout << endl;
		}
		inFile.close();
	}
	else {
		ofstream outFile(fileName, ios::out);

		if (!outFile) {
			cout << "\n" << msg[FILE_ERROR];
			return;
		}

		cout << msg[INPUT_DIMENSIONS];
		cout << "M: ";
		cin >> m;
		cout << "N: ";
		cin >> n;

		outFile << m << ' ' << n << '\n';

		cout << msg[INPUT_ELEMENTS];
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				cout << "A[" << i << "][" << j << "] = ";
				cin >> num;
				outFile << num << " ";
			}
			outFile << "\n";
		}
		outFile.close();
	}

}
