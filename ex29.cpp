# include <iostream>
# include <string>

using namespace std;

int main()
{
	cout << "Give me a number! ";
	int a;
	cin >> a;
	cout << endl;
	cout << "Give me one more! ";
	int b;
	cin >> b;
	cout << endl;
	if (a<b){
		cout << b << " is larger than " << a;
		cout << endl;
	}
	if (a>b){
		cout << a << " is larger than " << b;
		cout << endl;
	}
	if (a==b){
		cout << "The two numbers you have given are identical!" << endl;
	}
}