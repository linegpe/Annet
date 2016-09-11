# include <iostream>
# include <string>

using std::endl;
using std::cout;
using std::string;
using std::cin;

int main()
{
	// Number ot stars i horizontal line
	//const int rows = 5;

	// Ask the user what figure they want
	cout << "Hello! Welcome to the Figure Generator. If you want to make figures out of stars, you have come to the right place. Do you want to make a square or a rectangle? ";
	string figure;
	cin >> figure;

	if (figure == "square"){

		// Construct square

		// Ask user how long sides hw wishes
		cout << "Great! Then I only need to know how long you want your square's sides to be. Please insert number of stars in each side: ";
		int rows;
		cin >> rows;

		cout << endl;

		for (int r = 0; r != rows; ++r) {
			string::size_type c = 0;

			// Make as many columns as rows
			while (c != rows){

				// Are we on the border?
				if (r == 0 || r == rows - 1 || c == 0 || c == rows - 1) {
					cout << "* ";
				} else {
					cout << "  ";}
				c++;
				}
			cout << endl;
			}
		cout << endl;
		cout << "Ta-dah! A beautiful square with " << rows << " stars in each side. Thank you for using the Figure Generator :)";
		cout << endl;	
		}
	if (figure == "rectangle"){

		// Construct rectangle
	
		// Ask user how wide the rectangle should be
		cout << "Okay, cool! How wide do want your rectangle to be? Please enter the number of stars wanted: ";
		int cols;
		cin >> cols;

		// Ask user how tall the rectangle should be
		cout << endl;
		cout << "And how tall do you want it to be? Please enter the number of stars wanted: ";
		int rows;
		cin >> rows;

		for (int r = 0; r != rows; ++r) {
			string::size_type c = 0;

			// Make number of cols
			while (c != cols){

				// Are we on the border?
				if (r == 0 || r == rows-1 || c == 0 || c == cols - 1) {
					cout << "* ";
				} else {
					cout << "  ";
				}
				c++;
			}
		cout << endl;
	}
	} else{
	cout << "Sorry, I cannot understand what you mean. I am merely a computer without intelligense. If you vant me to function properly please type either \"square\" or \"rectangle\". ";
	}
	return 0;
}