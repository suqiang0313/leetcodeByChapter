//#######################################
// C++动态类型转换
//dynamic_cast
// const_cast:操作不能在不同的种类间转换。相反，它仅仅把一个它作用的表达式转换成常量。它可以使一个本来不是const类型的数据转换成const类型的，或者把const属性去掉。
//static_cast:可以实现C++中内置基本数据类型之间的相互转换。
//reinterpret_cast:

#include <iostream>
using namespace std;
//class Base
//{
//public:
//	virtual void f()
//	{
//		cout << "hello world1" << endl;
//	}
//};
//class Child :public Base
//{
//public:
//	void f()
//	{
//		cout << "hello world2" << endl;
//	}
//};
//int main()
//{
//	Base * pt = new Base;
//	Base * p = new Child;
//	pt->f();
//	p->f();
//	pt = dynamic_cast<Base *> (p);
//	pt->f();
//	cout << "hello world" << endl;
//}#include<iostream>
#include<cstring>
using namespace std;
class A
{
public:
	virtual void f()
	{
		cout << "hello" << endl;
	};
};

class B :public A
{
public:
	void f()
	{
		cout << "hello2" << endl;
	};

};

class C
{
public:
	void pp()
	{
		return;
	}
};

int fun()
{
	return 1;
}
void change(const int * pt, int n)
{
	int * pc;
	pc = const_cast<int*> (pt);
	*pc = *pc + 10;

}
int main()
{
	//dynamic_cast 
	A* a1 = new B;//a1是A类型的指针指向一个B类型的对象
	A* a2 = new A;//a2是A类型的指针指向一个A类型的对象
	B* b;
	C* c;
	b = dynamic_cast<B*>(a1);//结果为not null，向下转换成功，a1之前指向的就是B类型的对象，所以可以转换成B类型的指针。
	if (b == NULL)
	{
		cout << "null" << endl;
	}
	else
	{
		cout << "not null" << endl;
		b->f();
	}
	b = dynamic_cast<B*>(a2);//结果为null，向下转换失败
	if (b == NULL)
	{
		cout << "null" << endl;
	}
	else
	{
		cout << "not null" << endl;
		b->f();
	}
	c = dynamic_cast<C*>(a1);//结果为null，向下转换失败
	if (c == NULL)
	{
		cout << "null" << endl;
	}
	else
	{
		cout << "not null" << endl;
		c->pp();
	}
	// const_cast操作不能在不同的种类间转换。相反，它仅仅把一个它作用的表达式转换成常量。它可以使一个本来不是const类型的数据转换成const类型的，或者把const属性去掉。
	int pop1 = 38383;
	const int pop2 = 2000;
	cout << "pop1, pop2:" << pop1 << "," << pop2 << endl;
	change(&pop1, -103);
	change(&pop2, -103);
	cout << "pop1, pop2:" << pop1 << "," << pop2 << endl;
	return 0;
}
