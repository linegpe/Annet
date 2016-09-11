# include <iomanip>
# include <ios>
# include <iostream>
# include <string>
# include <algorithm>
# include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

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
	vector<double> homework;
	double x;

	// Invariant: homework contains all the homework grades read so far
	while (cin >> x)
		homework.push_back(x);

	// Check that the student entered som homework grades
	typedef vector<double>::size_type vec_sz;
	vec_sz size = homework.size();
	if (size == 0){
		cout << endl << "You must enter your grades. "
						"Please try again. " << endl;
		return 1;
	}

	// Sort the grades
	sort(homework.begin(),homework.end());

	// Compute the median homework grade
	vec_sz mid = size/2;
	double median;
	median = size % 2 == 0  ? (homework[mid] + homework[mid-1]) / 2
							: homework[mid];

	// Compute and write the final grade
	streamsize prec = cout.precision();
	cout << "Your final grade is " << setprecision(3)
		 << 0.2 * midterm + 0.4 * final + 0.4 * median
		 << setprecision(prec) << endl;
	return 0;
}