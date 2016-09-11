# include <iostream>
# include <string>

using std::cin;
using std::endl;
using std::cout;
using std::string;

int main()
{
	// Ask for person's name
	cout << "What is your name? ";

	// Read the name
	string name;
	cin >> name;

	// Build the message that we intend to write
	const string greeting = "Hello, " + name + "!";

	// The number of blanks surrounding the greeting
	const int pad = 1;

	// The number of rows and columns to write
	const int rows = pad * 3; // Removed * 2
	const string::size_type cols = greeting.size() + pad * 2 + 2;

	// Write a blank line to seperate the output from the input
	cout << endl;

	// Write rows of output
	// Invariant: we have written r rows so far
	for (int r = 0; r != rows; ++r) {
		string::size_type c = 0;

		// Invariant: we have written c characters so far in the current row
		while (c != cols) {

			// Is it time to write the greeting?
			if (r == pad && c == pad + 1) { // Removed + 1
				cout << greeting;
				c += greeting.size();
			} else {
			    
			    // Are we on the border?
				if (r == 0 || r == rows - 1 ||
					c == 0 || c == cols - 1)
					cout << "*";
				else 
					cout << " ";
				++c;
			}
		}
		cout << endl;
	}
	return 0;
}