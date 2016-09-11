# include <iostream>
# include <map>

using namespace std;


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