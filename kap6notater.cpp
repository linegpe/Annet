// Chapter 6 notes - Using library algorithms
// + + + + + + + + + + + + + + +
// 6.1 Analyzing strings
// + + + + + + + + + + + + + + +

// Loop used to concatenate two character pictures (from chapter 5):
for (vector<string>::const_iterator it = bottom.begin()
	 it != botoom.end(); ++it)
	ret.push_back(*it);
// This is equivalent to inserting a copy of the elements of 'bottom' at the end of 'ret'

// It can be done much easier as 
ret.insert(ret.end(), bottom.begin(), bottom.end());

// An even more general solution is
copy(botoom.begin(), bottom.end(), back_inserter(ret));

// 'copy' is a generic algorithm and 'back_inserter' is an iterator adaptor

copy(begin, end, out);
// has the same effect as
while (begin != end)
	*out++ = *begin++;
// The only differance is that the 'while' body changes the values of the iterators, and 'copy' doesn't. 

// Note that
it = begin++;
// is equivalent to
it = begin;
++begin;
// This is only for iterators

// Likewise, 
*out++ = *begin++;
// is equivalent to
{ *out = *begin; ++out; ++begin;}

// 'back_inserter(ret)' is an iterator that, when used as a destination, appends elements to 'ret'. Therefore, 
copy(bottom.begin(), botoom.end(), back_inserter(ret));
// copies all the elements of 'bottom' and appends to the end of 'ret'.
// After the function, the size of 'ret' will have increased with bottom.size()

// + + + + + + + + + + + + + + +
// 6.1.1 Another way to split
// + + + + + + + + + + + + + + +

// Program extract:

// * * * * * * * * * * * * * * *
// true if the argument is whitespace, false otherwise
bool space(char c)
{
	return isspace(c);
}

// false if the argument is whitespace, true otherwise
bool not_space(char c)
{
	return !isspace(c);
}

vector<string> split(const string& str)
{
	typedef string::const_iterator iter;
	vector<string> ret;

	iter i = str.begin();
	while (i != str.end()) {
		// ignore leading blanks
		i = find_if(i, str.end(), not_space);

		// find end of next word
		iter j = find_if(i, str.end(), space);

		// copy the characters in [i, j)
		if (i != str.end())
			ret.push_back(string(i, j));
		i = j;
	}
	return ret;
}
// * * * * * * * * * * * * * * *

// + + + + + + + + + + + + + + +
// 6.1.2 Palindromes
// + + + + + + + + + + + + + + +

// Palindromes are words that are spelled the same way forwards and backwards.(eye, rotor, madam)
// A simple way to find palindromes in a text: 
bool is_palindrome(const string& s)
{
	return equal(s.begin(), s.end(), s.rbegin());
}

// + + + + + + + + + + + + + + +
// 6.1.3 Finding URLs
// + + + + + + + + + + + + + + +

// Program extract

// * * * * * * * * * * * * * * *
vector<string> find_urls(const string& s)
{
	vector<string> ret;
	typedef string::const_iterator iter;
	iter b = s.begin(), e = s.end();

	// Look through the entire input
	while (b != e) {
		// Look for one or more letters followed by ://
		b = url_beg(b, e);

		// If we found it
		if (b != e) {
			// Get the rest of the URL
			iter after = url_end(b, e);

			// Remember the URL
			ret.push_back(string(b, after));

			// Advance b and check for more URLs on this line
			b = after;
		}
	}
	return ret;
}
// * * * * * * * * * * * * * * *

// Let's take a closer look at url_beg and url_end
// We start by looking at url_end
string::const_iterator
url_end(string::const_iterator b, string::const_iterator e)
{
	return find_if(b, e, not_url_char)
}
// This function forwrds its work to the library find_if function.
// We will have to write not_url_char, which will return 'true' when passed a character that cannot be a URL:
bool not_url_char(char c)
{
	// Characters, in addition to alphanumerics, that can appear in a URL
	static const string url_ch = "~;/?:@=&$-_.+!*'(),";

	// See whether c can appear in a URL and return the negative
	return !(isalnum(c) ||
			 find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

// Now we can look at url.beg:
string::const_iterator
url_beg(string::const_iterator b, string::const_iterator e)
{
	static const string sep = "://";

	typedef string::const_iterator iter;

	// 'i' marks where the seperator was found
	iter i = b;

	while ((i = search(i, e, sep.begin(), sep.end())) !=e) {

		// Make sure the seperator is not at the beginning or end of the line
		if (i != b && isalpha(beg[-1]))
			--beg;

		// Is there at least one appropriate character before and after the separator?
		if (beg != i && !not_url_char(i[sep.size()]))
			return beg;
		}

		// The seperator we found was not part of a URL; advance 'i' past this separator
		i += sep.size();
	}
	return e
}



// 6.2 Comparing Grading Schemes

// 6.2.1 Working with student records



// We have to write a function that checks whether all the homework is done or not
bool did_all_hw(const Student_info& s)
{
	return ((find(s.homework.beign(), s.homework.end(), 0))
		== s.homework.end());
}
// This function looks in the homework function to see if any of the results are 0
// More program extract:

vector<Student_info> did, dint;
Student_info student;

// Read all the records, separating them based on whether all homework was done
while (read(cin, student)) {
	if (did_all_hw(student))
		did.push_back(student);
	else 
		didnt.push_back(student);
}

// Check that both groups contain data
if (did.empty()) {
	cout << "No student did all the homework!" << endl;
	return 1;
}
it (didnt.empty()) {
	cout << "Every student did all the homework!" << endl;
	return 1;
}



// 6.2.2 Analyzing all the grades


// Compute grades. 
double grade_aux(const Student_info& s)
{
	try {
		return grade(s);
	} catch (domain_error) {
		return grade(s.midterm, s.final, 0);
	}
}

double median_analysis(const vector<Student_info>& students)
{
	vector<double> grades;

	transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
	return median(grades);
}

// Write a function that can analyses and compares two sets of students:
void write_analysis(ostream& out, const string& name, 
					double analysis(const vector<Student_info>&),
					const vector<Student_info>& did,
					const vector<Student_info>& didnt)
{
	out << name << ": median(did) = " << analysis(did) <<
				   ", median(didnt) = " << analysis(didnt) << endl;
}

// The rest of the program
int main()
{
	// Students who did and didn't do all their homework
	vector<Student_info> did, didnt;

	// Read the student records and partition them
	Student_info student;
	while (read(cin, student)) {
		if (did_all_hw(student))
			did.push_back(student);
		else 
			didnt.push_back(student);
	}
	
	// Verify that the analyses will show us something
	if (did.empty()) {
		cout << "No student did all the homework!" << endl;
		return 1;
	}
	if (didnt.empty()) {
		cout << "Every student did all the homework!" << endl;
		return 1;
	}

	// Do the analyses
	write_analysis(cout, "median", median_analysis, did, didnt);
	write_analysis(cout, "average", average_analysis, did, didnt);
	write_analysis(cout, "median of homework turned in",
				   optimistic_median_analysis, did, didnt);

	return 0;
}




// 6.2.3 Grading based on avegare homework grade 



// We can use 'accumulate' from the <numeric> header:
double average(const vector<double>& v)
{
	return accumulate(v.begin(), v.end(), 0.0) / v.size();
}
// 'accumulate' is used to generate the sum of elements in the range

// Make an average-function:
double average_grade(const Student_info& s)
{
	return grade(s.midterm, s.final, average(s.homework));
}

double average_grade(const vector<Student_info>& students)
{
	vector<double> grades;

	transform(students.begin(), students.end(),
			  back_inserter(grades), average_grade);
	return median(grades);
}




// 6.2.4 Median of the completed homework



// Making an optimistis median:

// Median of the nonzero elements of s.homework, or 0 if no such elements exist
double optimistic_median(const Student_info& s)
{
	vector<double> nonzero;
	remove_copy(s.homework.begin(), s.homework.end(),
				back_inserter(nonzero), 0);

	if (nonzero.empty())
		return grade(s.midterm, s.final, 0);
	else
		return grade(s.midterm, s.final, median(nonzero));
}



// 6.3   Classifying students, revisited
// 6.3.1 A two-pass solution


vector<Student_info>
extract_fails(vector<Student_info>& students) {
	vector<Student_info> fail;
	remove_copy_if(students.begin(), students.end(),
				   back_inserter(fail), pgrade);
	students.erase(remove_if(students.begin(), students.end(),
							 fgrade), students.end());
	return fail;
}

bool pgrade(const Student_info& s)
{
	return !fgrade(s);
}



// 6.3.2 A single-pass solution


vector<Student_info>
extract_fails(vector<Student_info>& students)
{
	vector<Student_info>::iterator iter =
		stable_partition(students.begin(), students.end(), pgrade);
	vector<Student_info> fail(iter, students.end());
	students.erase(iter, students.end());

	return fail 
}