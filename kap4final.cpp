#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"

using std::cin;				using std::setprecision;
using std::cout;			using std::sort;
using std::domain_error;	using std::streamsize;
using std::endl;			using std::string;
using std::max;				using std::vector;

int main()
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;		// The length of the longest name

	// Read and store all the student's data
	// Invariant: 'students' contain all the student records read so far
	//			  'maxlen' contains the lengt of the longest name in 'students'
	while (read(cin, record)) {
		// Find the length of the longest name
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}

	// Afabetize the student's records
	sort(students.begin(), students.end(), compare);

	// Write the names and grades
	for (vector<Student_info>::size_type i = 0;
		 i != students.size(); ++i) {

		// Write the name, padded on the right to 'maxlen' + 1 characters
		cout << students[i].name 
			 << string (maxlen + 1 - students[i].name.size(), ' ');

		// Compute and write the grading
		try {
			double final_grade = grade(students[i]);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				 << setprecision(prec);
		} catch (domain_error e) {
			cout << e.what();
		}
		cout << endl;
	}
	return 0;
}