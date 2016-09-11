# include <iostream>
# include <string>

int main()
{
	// ask for name
	std::cout << "Who the hell are you? ";

	// read name
	std::string name;
	std::cin >> name;

	// great
	std::cout << "Oh, right... Hello, " << name << "! :) " <<std::endl;
	return 0;
}