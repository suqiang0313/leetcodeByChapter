#include <iostream>
using namespace std;
template<class T>
class twostack
{
private:
	size_t _top1;
	size_t _top2;
	size_t capacity;
	T * _a;
	void _CheckCapacity()
	{
		if (_a == NULL)
		{
			capacity = capacity + 3;
			_a = new T[capacity];
			_top1 = 0;
			_top2 = capacity - 1;
			return;
		}
		if (_top1 == _top2)
		{
			size_t oldcapacity = capacity;
			capacity = capacity * 2;
			T* tmp = new T[capacity];
			for (int i = 0; i < _top1;i++)
			{
				tmp[i] = _a[i];

			}
			for (int j = oldcapacity - 1,i=capacity-1; j > _top2;j--,i--)
			{
				tmp[i] = _a[j];
			}
			delete[] _a;
			_a = tmp;
			_top2 += capacity / 2;
		}
	}
public:
	twostack() :_a(NULL), _top1(0), _top2(0), capacity(0)
	{
		_CheckCapacity();
	}
	~twostack()
	{
		if (_a)
		{
			delete []_a;
		}
	}
	void push1(const T &t)
	{
		_CheckCapacity();
		_a[_top1++] = t;
	}
	void push2(const T &t)
	{
		_CheckCapacity();
		_a[_top2--] = t;
	}
	void pop1()
	{
		if (_top1 > 0)
		{
			_top1--;
		}
	}
	void pop2()
	{
		if (_top2 <capacity - 1)
		{
			_top2++;
		}
	}
	size_t Size1()
	{
		return _top1 - 1;
	}
	size_t Size2()
	{
		return capacity - 1 - _top2;
	}
	bool empty1()
	{
		return _top1 == 0;
	}
	bool empty2()
	{
		return _top2 == capacity - 1;
	}
	T& top1()
	{
		if (_top1 != 0)
		{
			return _a[_top1 - 1];
		}
	}
	T& top2()
	{
		if (_top2 < capacity - 1)
		{
			return _a[_top2 + 1];
		}
	}
};
void TestTwoStack()
{
	twostack<int> s;
	s.push1(1);
	s.push1(2);
	s.push1(3);
	s.push1(4);
	s.push1(5);
	s.push2(1);
	s.push2(2);
	s.push2(3);
	s.push2(4);
	s.push2(5);
	cout << "s1:" << s.Size1() << endl;;
	cout << "s2:" << s.Size2() << endl;
	while (!s.empty1())
	{
		cout << s.top1() << endl;
		s.pop1();
	}
	while (!s.empty2())
	{
		cout << s.top2() << endl;
		s.pop2();
	}
}
int main()
{
	TestTwoStack();
}