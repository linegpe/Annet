# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <ios>
# include <iomanip>

using std::vector;
using std::domain_error;
using std::sort;
using std::streamsize;
using std::endl;
using std::cout;
using std::cin;
using std::istream;
using std::setprecision;
using std::string;

// Compute the median of a vector<double>
// Note that calling this function copies the entire argument vector
double median(vector<double> vec)
{
	typedef vector<double>::size_type vec_sz;

	vec_sz size = vec.size();
	if (size == 0)
		throw domain_error("median of an empty vector");
	
	sort(vec.begin(), vec.end());

	vec_sz mid = size/2;

	return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}

// Compute a student's overall grade form midterm and final exam grades and homework grade
double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// Compute a student's overall grade form midtem and final exam grades
// and vector of homework grades.
// This function doeas not copy its argument, because median does so for us.
double grade(double midterm, double final, const vector<double>& hw)
{
	if (hw.size() == 0)
		throw domain_error("student has done no homework");
	return grade(midterm, final, median(hw));
}

// Read homework grades from an input stream into a vector<double>
istream& read_hw(istream& in, vector<double>& hw)
{
	if (in){
		// Get rid of previous contents
		hw.clear();

		// Read homework grades
		double x;
		while (in >> x);
			hw.push_back(x);
		// Clear the stream so that input will work for the next student
		in.clear();
	}
	return in;
}
 
int main()
{
	// Ask for and read the sudent's name
	cout << "Please enter your first name: ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;

	// Ask for and read the midterm and final grades
	cout << "Please enter your midterm and final exam grades, "
			"followed by end-of-file: ";
	double midterm, final;
	cin >> midterm, final;

	// Ask for homework grades
	cout << "Please enter your homework grades, "
			"followed by end-of-file: ";

	vector<double> homework;

	// Read the homework grades
	read_hw(cin, homework);

	// Compute and generate the final grade, if possible
	try{
		double final_grade = grade(midterm, final, homework);
		streamsize prec = cout.precision();
		cout << "Your final grade is " << setprecision(3)
		<< final_grade << setprecision(prec) << endl;
	} catch (domain_error) {
		cout << endl << "You must enter your grades. "
						"Please try again. " << endl;
		return 1;
	}
	return 0;
}