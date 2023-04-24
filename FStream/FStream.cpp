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
	//����� fstream
	std::fstream file; //������ ������ fstream, ����������� ������������ ���������� � ��������� ������ �� �����
	/*file.open(path, std::ios::in | std::ios::app); //�������� ����� � �������� in � app
	// | - ������� "���"

	if (file.is_open()) {
		std::cout << "���� ������.\n";
		//���������� ������ � ����
		std::cout << "������ � ����.\n������� ������ -> ";
		std::string str;
		std::getline(std::cin, str);
		file << str << "\n";
		std::cout << "������ ��������� � ����.\n";

		file.seekg(0, std::ios::beg); //����������� ������� ��� ���������� ������ � ������ �����

		//������ �� �����
		std::cout << "���������� �����:\n";
		char sym;
		while (file.get(sym))
			std::cout << sym;
	}
	else
		std::cout << "������ �������� �����.\n";

	file.close();*/

	//������� "���� � ������� �����"
	/*std::cout << "���������� �����:\n";
	print_file(path);

	std::cout << "������� ������ -> ";
	std::string substr;
	std::getline(std::cin, substr);

	std::cout << "������� ������� -> ";
	std::cin >> n;
	std::cin.ignore();

	if (insert_file(path, substr, n)) {
		std::cout << "������� ��������� �������!\n";
		std::cout << "���������� �����:\n";
		print_file(path);
		std::cout << std::endl;
	}
	else
		std::cout << "������ �������!\n";*/

	//������� "���� �� �����"
	std::cout << "������ 1.\n���������� �����:\n";
	std::string date_path = "date.txt";
	std::string date;
	print_file(date_path);
	file.open(date_path, std::ios::in);

	if (file.is_open()) {
		std::cout << "���� ������.\n";
		file.seekg(0, std::ios::beg);
		std::cout << "���������� �����:\n";
		char sym;
		while (file.get(sym))
			date+=sym;
	}
	else
		std::cout << "������ �������� �����.\n";

	file.close();

	unsigned int month_index = date.find('.') + 1;
	unsigned int year_index = date.rfind('.') + 1;
	unsigned int day_index = 0;

	unsigned int day = std::stoi(date.substr(0, month_index));
	unsigned int month = std::stoi(date.substr(month_index, year_index - 1 - month_index));
	unsigned int year = std::stoi(date.substr(year_index));

	std::cout << "����: " << day << std::endl;
	std::cout << "�����: " << month << std::endl;
	std::cout << "���: " << year << std::endl;

	return 0;
}