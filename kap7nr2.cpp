// Not working yet

# include <iostream>
# include <string>
# include <vector>
# include <map>

using namespace std;

// This program counts how many times each word appears in a text and in which line

// Find all the lines that refer to each word in the input
map<string, vector<int> >
	xref(istream&, in,
		 vector<string> find_words(const string&) = split)
{
	string line;
	int line_number = 0;
	map<string, vector<int> > ret;		// Very important to keep the space between the two '>'

	// Read the next line
	while (getline(in, line)) {
		++line_number;

		// Break the input line into words
		vector<string> words = find_words(line);

		// Remember that each word occurs in the correct line
		for (vector<string>::const_iterator it = words.begin();
			 it != words.end(); ++it) 
			ret[*it].push_back(line_number);
	}
	return ret
} 

// And the main program:

int main()
{
	// Call xref using using split by default
	map<string, vector<int> > ret = xref(cin);

	// Write the result
	for (map<string, vector<int> >:: const_iterator it = ret.begin();
		 it != ret.end(); ++it) {
		// Write the word
		cout << it->first << " occurs in line(s): ";

		// Followed by one or more line numbers
		vector<int>::const_iterator line_it = it->second.begin();
		cout << *line_it;		// Write the first line number

		++line_it;

		// Write the rest of the line numbers, if any
		while (line_it != it->second.end()) {
			cout << ", " << *line_it;
			++ line_it;
		}
		// Write a new line to separate each word from the next
		cout << endl;
	}
	return 0;
}