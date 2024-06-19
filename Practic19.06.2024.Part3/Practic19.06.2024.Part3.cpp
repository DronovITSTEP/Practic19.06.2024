#include <iostream>
#include <fstream>
#include <string.h>
#include <Windows.h>

using namespace std;

void RussianMessage(const char* message) {
	char rmessage[256];
	CharToOemA(message, rmessage);
	cout << rmessage;
}
int RussianMenu() {
	RussianMessage("\nВведите 1 для добавления новой структуры файла\n");
	RussianMessage("\nВведите 2 для показа всех структур из файла\n");
	RussianMessage("\nВведите 3 для выхода\n");

	int choice;
	cin >> choice;
	return choice;
}

class Human {
	int age;
	char* name;
	char* surname;
public:
	Human(char* n, char* s, int a);
	Human();
	~Human();

	void Put(); // метод для ввода данных
	void Show(); // метод для показа данных
	void SaveToFile(); // метод для сохранения в файл
	static void ShowFromFile(); // метод для показа содержимого файла
};

Human::Human():age{0}, surname{nullptr}, name {nullptr}{}
Human::Human(char* n, char* s, int a){
	name = new char[strlen(n) + 1];
	if (!name) {
		RussianMessage("Ошибка при выделении памяти!\n");
		exit(1);
	}
	strcpy_s(name, strlen(n)+1, n);

	surname = new char[strlen(s) + 1];
	if (!surname) {
		RussianMessage("Ошибка при выделении памяти!\n");
		exit(1);
	}
	strcpy_s(surname, strlen(s) + 1, n);

	age = a;
}
Human::~Human() {
	delete[] name;
	delete[] surname;
}

void Human::Put() {
	char temp[1024];
	RussianMessage("\nВведите имя:\n");
	cin >> temp;

	if (name)
		delete[] name;

	name = new char[strlen(temp) + 1];
	if (!name) {
		RussianMessage("Ошибка при выделении памяти!\n");
		exit(1);
	}
	strcpy_s(name, strlen(temp) + 1, temp);

	RussianMessage("\nВведите фамилию:\n");
	cin >> temp;

	if (surname)
		delete[] surname;

	surname = new char[strlen(temp) + 1];
	if (!surname) {
		RussianMessage("Ошибка при выделении памяти!\n");
		exit(1);
	}
	strcpy_s(surname, strlen(temp) + 1, temp);

	RussianMessage("\nВведите возраст:\n");
	cin >> age;
}
void Human::Show() {
	RussianMessage("\nИмя: ");
	cout << name;
	RussianMessage("\nФамилия: ");
	cout << surname;
	RussianMessage("\nВозраст: ");
	cout << age;
}

void Human::SaveToFile() {
	int size;
	fstream f("human.txt", ios::out | ios::app | ios::binary);
	if (!f.is_open()) {
		RussianMessage("Файл не открылся для записи!\n");
		exit(1);
	}

	f.write((char*)&age, sizeof(age));

	size = strlen(name);
	f.write((char*)&size, sizeof(int));
	f.write((char*)name, size * sizeof(char));

	size = strlen(surname);
	f.write((char*)&size, sizeof(int));
	f.write((char*)surname, size * sizeof(char));

	f.close();
}
void Human::ShowFromFile() {
	fstream f("human.txt", ios::in | ios::binary);
	if (!f.is_open()) {
		RussianMessage("Файл не открылся для записи!\n");
		exit(1);
	}

	char* n, * s;
	int a;
	int temp;

	while (f.read((char*)&a, sizeof(int))) {
		RussianMessage("\nИмя:\n");
		f.read((char*)&temp, sizeof(int));
		n = new char[temp + 1];
		if (!n) {
			RussianMessage("Ошибка при выделении памяти!\n");
			exit(1);
		}
		f.read((char*)n, temp * sizeof(char));
		n[temp] = '\0';
		cout << n;

		RussianMessage("\nФамилия:\n");
		f.read((char*)&temp, sizeof(int));
		s = new char[temp + 1];
		if (!n) {
			RussianMessage("Ошибка при выделении памяти!\n");
			exit(1);
		}
		f.read((char*)s, temp * sizeof(char));
		s[temp] = '\0';
		cout << s;

		RussianMessage("\nВозраст:\n");
		cout << a << '\n';

		delete[] n;
		delete[] s;
	}
}

void main()
{
	Human* man;
	do {
		switch (RussianMenu())
		{
		case 1:
			man = new Human();
			man->Put();
			man->SaveToFile();
			delete man;
			break;
		case 2:
			Human::ShowFromFile();
				break;
		case 3:
			RussianMessage("До свидания!\n");
			return;
		default:
			RussianMessage("Неверный ввод!\n");
			break;
		}
	} while (true);
}
