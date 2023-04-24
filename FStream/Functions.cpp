#include <iostream>
#include <fstream>
#include <string>

bool print_file(std::string file_path) {
	static std::ifstream in;
	in.open(file_path);

	if (in.is_open()) {
		char sym;
		while (in.get(sym))
			std::cout << sym;
		std::cout << std::endl;
		in.close();
		return true;
	}

		in.close();
		return false;
}

bool insert_file(std::string file_path, std::string str, int position) {
	std::string file_text;
	
	std::fstream file;
	file.open(file_path, std::ios::in);

	if (file.is_open()) {
		char sym;
		while (file.get(sym))
			file_text += sym;
	}
	else {
		file.close();
		return false;
	}
	file.close();

	file_text.insert(position, str);

	file.open(file_path, std::ios::out);
	if (file.is_open()) {
		file << file_text;
		file.close();
		return true;
	}
	file.close();
	return false;
}

//bool read_file(std::string file_path) {

//}