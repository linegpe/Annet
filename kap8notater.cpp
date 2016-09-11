// Chapter 8

// Writing Generic Functions

// 8.1   What is a generic function?
// 8.1.1 Medians of unknown type

template <class T>
T median(vector<T> V)
{
	typedef typename vector<T>::size_type vec_sz;

	vec_sz size = v.size();
	if (size == 0)
		throw domain_error("median of an emty vector");

	sort(v.begin(), v.end());

	vec_sz mid = size/2;

	return size % 2 == 0 ? (v[mid] + v[mid-1]) / 2 : v[mid];
}



// 8.1.2 Template instantiation

// When we call 'median' on behalf of a 'vector<int>', the implementation will effectively
// generate and compile an instance of the functon that replaces every use of T by 'int'.



// 8.2   Data-structure independence
// 8.2.2 Sequential read-only access


template <class In, class X> In find(In begin, In end, const X& x)
{
	while (beign != end && *begin != x)
		++begin;
	return begin;
}

// Another version (more similar to Lisp og ML):
template <class In, class X> In find(In begin, In end, const X& x)
{
	if (begin == end || *begin == x)
		return begin;
	begin++;
	return find()
}


// 8.2.3 Sequential write-only access

// Consider the copy functon:
template<class In, class Out>
Out copy(In begin, In end, Out dest)
{
	while (begin != end)
		*dest++ = *begin++;
	return dest;
}
// This function takes three iterators; the first two denote the sequence from which to copy,
// and the third denotes the beginning of the destination sequence.


// 8.2.4 Sequential read-write access

// We can make this by using 'replace' from <algorithm>:

template<class For, class X>
void replace(For beg, For end, const X& x, const X& y)
{
	while (beg != end) {
		if (*beg == x)
			*beg = y;
		++beg;
	}
}
// This function examines the elements in the range [beg, end) and replaces every element that is equal to x by y.
// The type For needs to support all the operations supported by an input iterator,
// as well as all the operations supported by an output iterator.


// 8.2.5 Reversible access

// Some functions need to get at a container's elements in reverse order.  
// This can be done by using 'reverse' from <algorithm>.

template <class Bi>
void reverse(Bi begin, Bi end)
{
	while (begin != end) {
		--end;
		if (begin != end)
			swap(*begin++, *end);
	}
}
// This is called a bibdirectional iterator 


// 8.2.6 Random access

// This can be used for binary search, among other things:

template <class Ran, class X>
bool binary_search(Ran begin, Ran end, const X& x)
{
	while (begin != end) {
		// Find the midpoint of the range
		Ran mid = begin + (end - begin / 2);
		
		// See which part of the range contains x; keep looking only in that part
		if (x < *mid)		
			end = mid;
		else if (*mid < x)
			begin = mid + 1;
		// If we got here, then *mid == x so we're done
		else return true;
	}
	return false;}
}


// 8.3   Output and input iterators

// Stream iterators are defined in the <iterator> header


// 8.4   Using iterators for flexibility

// Improvement to previous split function (not nessecary to return a vector):
template <class Out>
void split(const string& str, Out os) {
	typedef string::const_iterator iter;

	iter i = str.begin();
	while (i != str.end()) {
		// Ignore leading blanks
		i = find_if(i, str.end(), not_space);

		// Find end of next word
		iter j = find_if(i, str.end(), space);

		// Copy the characters in [i,j)
		if (i != str.end())
			*os++ = string(i, j);

		i = j;
	}
}