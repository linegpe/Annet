// Chapter 7
// Using associative containers

// 7.1 Containers that support efficient look-up

// We can use an "associative container".
// One expample is the associative array, where we can store date with keys. 
// In C++ this array is called a map and is contained in the <map> header


// 7.2 Counting words

// Small program to count how many times each word appeares in a text:
int main()
{
	string s;
	map<string, int> counters; // Store each word and associated counter

	// Read the input, keeping track of each word and how often we see it
	while (cin >> s)
		++ counters[s];

	// Write the words and associated counts
	for (map<string, int>::const_iterator it = counters.begin();
		 it != counters.end(); ++it) {
		cout << it->first << "\t" << it->second << endl;
	}
	return 0;
 }



// 7.3 Generating a cross-reference table
 

// We want to change our program to be able to tell where each word appeares in the text

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


// 7.4   Generating sentences
// 7.4.1 Representing the rules

// We can represent the rules like
typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;


// 7,4,2 Reading the grammar 


// A function to read the grammar represented

// Read a grammar from a given input stream
Grammar read_grammar(istream& in)
{
	Grammar ret;
	string line;

	// Read the input
	while (getline(in, line)) {
		
		// Split the input into words
		vector<string> entry = split(line);

		if (!entry.empty())
			// Use the category to store the associated rule
			ret[entry[0]].push_back(
				Rule(entry.begin() + 1, entry.end()));
	}
	return ret;
}



// 7.4.3 Generating the sentence


// We want to define our sentence generator in terms of an auxiliary function:
vector<string> gen_sentence(const Grammar& g)
{
	vector<string> ret;
	gen_aux(g, "<sentence>", ret);
	return ret;
}

// We also need a function to check whether a word is a category (e.g. in brackets):
bool bracketed(const string& s)
{
	return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

void gen_aux(const Grammar& g, const string& word, vector<string>& ret)
{
	if (!bracketed(word)) {
		ret.push_back(word);
	} else {
		// Locate the rule that corresponds to 'word'
		Grammar::const_iterator it = g.find(word);
		if (it == g.end())
			throw logic_error("empty rule");

		// Fetck the set of possible rules
		const Rule_collection& c = it->second;

		// From which we select one at random
		const Rule& r = c[nrand(c.size())];

		// Recursively expand the selected rule
		for (Rule::const_iterator& i = r.begin(); i != r.end(); ++i)
			gen_aux(g, *i, ret);
	}
}

// And so the main program
int main()
{
	// Generating the sentence
	vector<string> sentence = gen_sentence(read_grammar(cin));

	// Write the first word, if any
	vector<string>::const_iterator it = sentence.begin();
	if (!sentence.empty()) {
		cout << *it;
		++it;
	}

	// Wrtie the rest of the words, each preceded by a space
	while (it != sentence.end()) {
		cout << " " << *it;
		++it 
	}
	cout << endl;
	return 0;
}



// 7.4.4 Selecting a random element


// Return a random integer in the range [0,n)
int nrand(int n)
{
	if (n <= 0 || n > RAND_MAX)
		throw domain_error("Argument to nrand is out of range");

	const int bucket_size = RAND_MAX / n;
	int r;

	do r = rand() / bucket_size;  // Same as normal while, except condition is at the end: 'do' statement 'while' (condition)
	while (r >= n );

	return r;
}
