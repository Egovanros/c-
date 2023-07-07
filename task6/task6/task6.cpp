#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Ru");
	string input_file_name = "text.txt";
	string output_file_name = "result.txt";
	ifstream input_file("text.txt");
	ofstream output_file("result.txt");
	if (!input_file.is_open()) {
		cout << "Не удалось открыть входной файл" << endl;
		return 1;
	}
	if (!output_file.is_open()) {
		cout << "Не удалось открыть выходной файл" << endl;
		return 1;
	}
	string line;
	while (getline(input_file, line)) {
		istringstream iss(line);
		string word;
		while (iss >> word) {
			output_file << word << " [" << word.size() << "] ";
		}
		output_file << endl;
	}
	input_file.close();
	output_file.close();
	cout << "Текст успешно обработан" << endl;
	return 0;
}