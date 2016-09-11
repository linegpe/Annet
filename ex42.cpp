#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::istream;

// Read numbers into a vector
istream& read_nr(istream& in, vector<int>& nr)
{
	if (in)
		// Remove previous content
		nr.clear();

		// Read the numbers
		int x;
		while (in >> x) {
			nr.push_back(x);
	}
	return in;
}

int main()
{
	cout << "Insert numbers between 0 and 100: ";
	vector<int> numbers;
	read_nr(cin, numbers);

	int maxlen = 3;

	// Print the initial numbers and their squares
	for (int i = 0; i != numbers.size(); ++i) {
		cout << numbers[i] << "    " << numbers[i] * numbers[i];
		cout << endl;
	}

	return 0;
}