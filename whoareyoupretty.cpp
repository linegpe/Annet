# include <iostream>
# include <string>

int main()
{
	std::cout << "What is your name? ";
	std::string name;
	std::cin >> name;

    // build the message
    const std::string greeting = name + " \<3";

    // build second nd fourth string
    const std::string spaces(greeting.size(), ' ');
    const std::string second = "* " + spaces + " *";

    // build first and fifth string
    const std::string first(second.size(), '*');

    // write it all
    std::cout << std::endl;
    std::cout << first << std::endl;
    std::cout << second << std::endl;
    std::cout << "* " << greeting << " *" << std::endl;
    std::cout << second << std::endl;
    std::cout << first << std::endl;
}