#include <iostream>
#include <fstream>

static void printReplaced(std::ostream &output_stream, std::string line, std::string str1, std::string str2)
{
	size_t posOld = 0, posNew;

	while ((posNew = line.find(str1, posOld)) != std::string::npos) {
		output_stream << line.substr(posOld, posNew - posOld) << str2;
		posOld = posNew + str1.length();
	}
	output_stream << line.substr(posOld, line.length()) << std::endl;
}

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "Wrong number of arguments" << std::endl;
		return 1;
	}

	std::string input_file = (std::string)argv[1];
	std::string output_file = input_file + ".replace";
	std::string str1 = (std::string)argv[2];
	std::string str2 = (std::string)argv[3];
	if (str1.length() == 0) {
		std::cout << "String to replace can't be empty" << std::endl;
		return 1;
	}

	std::ifstream input_stream;
	std::ofstream output_stream;
	input_stream.open(input_file.c_str());
	if (!input_stream.is_open()) {
		std::cout << "Can't open file " << input_file << std::endl;
		return 1;
	}
	output_stream.open(output_file.c_str());
	if (!output_stream.is_open()) {
		std::cout << "Can't open file " << output_file << std::endl;
		return 1;
	}

	std::string line;
	while (std::getline(input_stream, line))
		printReplaced(output_stream, line, str1, str2);
	return 0;
}
