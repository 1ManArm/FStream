#include <iostream>
#include <fstream>
#include <string>
#include "Functions.h"

//seekg - seek get pointer
// ios::beg -> beginning
//seekp - seek put pointer
// ios::cur -> current

int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	std::string path = "file.txt";
	//Класс fstream
	std::fstream file; //объект класса fstream, позволяющий одновременно записывать и считывать данные из файла
	/*file.open(path, std::ios::in | std::ios::app); //открытие файла с режимами in и app
	// | - битовое "или"

	if (file.is_open()) {
		std::cout << "Файл открыт.\n";
		//Добавление записи в файл
		std::cout << "Запись в файл.\nВведите строку -> ";
		std::string str;
		std::getline(std::cin, str);
		file << str << "\n";
		std::cout << "Запись добавлена в файл.\n";

		file.seekg(0, std::ios::beg); //перемещение курсора для считывания данных в начало файла

		//Чтение из файла
		std::cout << "Содержимое файла:\n";
		char sym;
		while (file.get(sym))
			std::cout << sym;
	}
	else
		std::cout << "Ошибка открытия файла.\n";

	file.close();*/

	//Задание "Ввод в позицию файла"
	/*std::cout << "Содержимое файла:\n";
	print_file(path);

	std::cout << "Введите строку -> ";
	std::string substr;
	std::getline(std::cin, substr);

	std::cout << "Введите позицию -> ";
	std::cin >> n;
	std::cin.ignore();

	if (insert_file(path, substr, n)) {
		std::cout << "Вставка выполнена успешно!\n";
		std::cout << "Содержимое файла:\n";
		print_file(path);
		std::cout << std::endl;
	}
	else
		std::cout << "Ошибка вставки!\n";*/

	//Задание "Дата из файла"
	std::cout << "Задача 1.\nСодержимое файла:\n";
	std::string date_path = "date.txt";
	std::string date;
	print_file(date_path);
	file.open(date_path, std::ios::in);

	if (file.is_open()) {
		std::cout << "Файл открыт.\n";
		file.seekg(0, std::ios::beg);
		std::cout << "Содержимое файла:\n";
		char sym;
		while (file.get(sym))
			date+=sym;
	}
	else
		std::cout << "Ошибка открытия файла.\n";

	file.close();

	unsigned int month_index = date.find('.') + 1;
	unsigned int year_index = date.rfind('.') + 1;
	unsigned int day_index = 0;

	unsigned int day = std::stoi(date.substr(0, month_index));
	unsigned int month = std::stoi(date.substr(month_index, year_index - 1 - month_index));
	unsigned int year = std::stoi(date.substr(year_index));

	std::cout << "День: " << day << std::endl;
	std::cout << "Месяц: " << month << std::endl;
	std::cout << "Год: " << year << std::endl;

	return 0;
}