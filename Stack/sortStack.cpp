#include <stack>
#include <iostream>
using namespace std;
stack<int> sortStack(stack<int> s)
{
	stack<int> r;
	while (!s.empty())
	{
		int temp = s.top();
		s.pop();
		while (!r.empty()&&r.top() > temp)
		{
			s.push(r.top());
			r.pop();
		}
		r.push(temp);
	}
	return r;
}
int main()
{
	stack<int> s;
	s.push(1);
	s.push(-1);
	s.push(2);
	stack<int> r = sortStack(s);
	while (!r.empty())
	{
		cout << r.top() << endl;
		r.pop();
	}
}