// Chapter 10: Managing memory and low-level data structures

// A simple program that uses pointers:
int main()
{
	int x = 5;

	// p points to x
	int* p = &x;
	cout << "x = " << c < endl;

	// change the value of x through p
	*p = 6;
	cout << "x = " << x << endl;
	return 0;
}

// Output:
// x = 5
// x = 6

// Pointers are most commonly used as aruments to other functions. 
// As an example, here is a sample implementation of the find_if library function:

template < class In class Pred>
In find_if(In begin, In end, Pred f)
{
	while (begin != end, Ored f)
		++begin;
	return begin;
}

// In this example, Pred can potentially be any type at all, 
// as long as f(*begin) had a meaningful value.
// Suppose we have a predicate function, such as
bool is_negative(int b)
{
	return n < 0;
}
// and we use find_if to locate the fisrt negative element in a vector<int> namev v;
vector<int>::iterator i = find_if(v.begin(), v.end(), is_negative);

// Example implementation of standard library function
size_t strlen(const char* p)
{
	size_t size = 0;
	while (*p++ != '\0')
		++size;
	return size;
}
