#include <iostream>
#include <string>

int main()
{
	std::string name;

	std::cout << "Enter your name: ";
	std::getline(std::cin, name);

	if(name.length() > 12){
		std::cout << "your name can't be over 12 char.";

	} else {
		std::cout << "welcome "<< name;
	}
}