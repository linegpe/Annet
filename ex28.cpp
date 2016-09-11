# include <iostream>
# include <string>

int main()
{
	int i = 0;
	int sum = 0;
	while (i < 10000){
		i += 1;
		sum += i;
	}
	std::cout << sum << std::endl;
	return 0;
}