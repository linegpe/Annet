# include <iomanip>
# include <ios>
# include <iostream>
# include <string>

using namespace std;

int main()
{
	// Ask for and read student's name
	cout << "Please enter your first name: ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;

	// Ask for and read the midterm and final grades
	cout << "Please enter your midterm and final exam grades: ";
	double midterm, final;
	cin >> midterm >> final;

	// Ask for the homework grades
	cout << "Enter all your homework grades, "
			"followed by the end-of-file: ";

	// The number and sum of grades read so far
	int count = 0;
	double sum = 0;

	// A variable into which to read
	double x;

	// Invariant:
	// We have read count grades so fra, and the sum of the first count grades
	while (cin >> x) {
		++count;
		sum += x;
	}

	// Write the result
	streamsize prec = cout.precision();
	cout << "Your final grade is " << setprecision(3)
		 << 0.2 * midterm + 0.4 * final + 0.4 * sum /count
		 << setprecision(prec) << endl;
	return 0;
}