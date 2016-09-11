# include <string>
# include <iostream>
# include <vector>

using std::endl;
using std::cout;
using std::vector;
using std::string;
using std::cin;

int main()
{
	// Ask user for input text
	cout << "This program counts how many times each word appears in a text." << endl;
	cout << "Please insert desired text: ";

	// Store every word as an element in a vector
	vector<string> text; 
	string x;

	while (cin >> x)
	{
		text.push_back(x);
	}
	return 0;
}