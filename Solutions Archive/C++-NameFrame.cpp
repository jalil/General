#include <iostream>
#include <string>

std::string frameName(void) {
	std::string name, greeting;
	
	std::cout << "What is your name?\n  -->  ";
	std::cin >> name;
	
	greeting = "Hello, " + name + "!";
	
	std::string secondAndFourth(greeting.size(), ' ');
	secondAndFourth = '*' + secondAndFourth + '*';
	
	std::string firstAndFifth(secondAndFourth.size(), '*');
	
	return firstAndFifth + '\n' +  secondAndFourth + '\n' + '*' + greeting + '*' + '\n'  + secondAndFourth + '\n' + firstAndFifth;

}

int main(int argc, const char *argv[]) {
	std::string nameFrame = frameName();
	std::cout << nameFrame << std::endl;
	return 0;
}
