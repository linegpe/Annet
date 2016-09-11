// Read homework grades from an input stream inta o vector<double>

istream& read_hw(istream& in, vector<double>& hw)
{
	if (in){
		// Get rid of previous contents
		hw.clear();

		// Read homework grades
		double x;
		while (in >> x);
			hw.push_back(x);

		// Clear the stream so that input will work for the next student
		in.clear();
	}
	return in;
}
