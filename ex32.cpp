// Unfinished

# include <iostream>
# include <string>
# include <vector>
# include <algorithm>

using std::cout;
using std::cin;
using std::vector;
using std::endl;
using std::sort;


void print(vector<double> vec, vector<double>::size_type  vec_size)
{
	for (int i = 0; i < vec_size; ++i)
	{
		cout << vec[i] << endl;
	}
}

int main()
{
	// Ask for the numbers and store them in a vector
	cout << "Give me some numbers "
			"(to terminate, press any letter): ";
	vector<double> numbers;
	double x;
	while (cin >> x)
		numbers.push_back(x);

	// Check that some numbers have been entered
	typedef vector<double>::size_type vec_sz;
	vec_sz size = numbers.size();
	if (size == 0){
		cout << "No numbers given. Please try again. " << endl;
	}

	// Sort the numbers
	sort(numbers.begin(), numbers.end());

	// Divide in two groups
	// vec_sz mid = size/2;
	cout << size << endl;
	print(numbers, size);
	return 0;
}

