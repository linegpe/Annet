# include <string>
# include <iostream>
# include <vector>
# include "grade.h"

using std::vector;

// Predicate to determine whether a student failed
bool fgrade(const Student_info& s)
{
	return grade(s) < 60;
}

// Separate passing and failing student records: first try
vector<Student_info> extract_fails(vector<Student_info>& students)
{
	vector<Student_info> pass, fail;

	for (vector<Student_info>::size_type i = 0;
		 i != students.size(); ++i)
		if (fgrade(students[i]))
			fail.push_back(students[i]);
		else
			pass.push_back(students[i]);

	students = pass;
	return fail;
}