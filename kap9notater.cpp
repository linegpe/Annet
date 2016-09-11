// Chapter 9
// Defining new types

// 9.2   Class types
// 9.2.1 Member functions

// We start by revisiting Student_info from chapter four and making small adjustments

struct Student_info {
	std::string name;
	double midterm, final;
	std::vector<double> homework;

	std::istream& read(std::istream&);		// Added now
	double grade() const;					// Added now
};

// We also need a new read function
istream& Student_info::read(instream& in)
{
	in >> name >> midterm >> final;
	read_hw(in, homework);
	return in;
}

// This functions would be put in a common file named Student_info.cpp, Student_info.C or Student_infp.c
// The declerations for these functions are now part of our Student_info structure, so they must be available to all uses of the Student_info class

// Three important differances between this new read function and the old read function from chapter 4:
// 1) The name of the function is Student_info::read, not just read
// 2) Because this function is a member of a Student_info object, we do not need to pass a Sudent_info object as an argument,
// or to define a Student_info object ar all.
// 3) We access the data elements of objects directly. For example, in chapter 4, we reffered to s.midterm, and not just midterm. 

double Student_info::grade() const
{
	return ::grade(midterm, final, homework)
}



// 9.3   Protection

// We are able to hide some of the implementation from the user, so that they cannot manipulate the program. This is done by

class Student_info {
public:
	// Interface goes here:
	double grade() const;
	std::istream& read(std::istream&)

private:
	// Implementation goes here
	std::strign name;
	double midterm, final;
	std::vector<double> homework;
};


// 9.3.1 Accessor functions

class Student_info {
public:
	double grade() const;
	std::istream& read(std::istream&);		// must change definition
	std::string name() const { return n; }	// added

private:
	std::string n;					// changed
	double midterm, final;
	std::vector<double> homework; 
};




// 9.4   The Student_info class

// So far we have

class Student_info {
public:
	std::string name() const { return n; }
	bool valid() const { return !homework.empty(); }
	std::istream& read(std::istream&);
	double grade() cons;
private:
	std::string n;
	doble midterm, final;
	std::vector<double> homework;
};
bool compare(const Student_info&, const Student_info&);


// 9.5   Constructors

// 9.6   Using the Student_info class

// Full program:

int main()
{
	vecot<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	// Read and store the data
	while (record.read(cin)) {
		maxlen = max(maxlen, record.name().size());
		students.push_back(record);
	}

	// Alpabetize the student records
	sort(students.begin(), students.ebd(), compare);

	// Write the names and grades
	for (vector<Student_info>::size_type i = 0;
		 i != students.size(), ++1) {
		cout << students[i].name()
			 << string(maxlen + 1 - students[i].name().size(), ' ');
		try {
			double final_grade = students[i].grade();
			streamsize prec = cout.precision();
			cout setpresicion(3) << final_grade << setpresicion(prec) << endl;
		} catch domain_error e {
			cout e.what() << endl;
		}
	}
	return 0;
}


