#include <iostream>
using namespace std;
int main()
{
	char c = 'c';
	char & b = c;
	char * p = &c;
	cout << &c << "£º" << &b << endl;
	cout << p << endl;
}