//#######################################
// C++��̬����ת��
//dynamic_cast
// const_cast:���������ڲ�ͬ�������ת�����෴����������һ�������õı��ʽת���ɳ�����������ʹһ����������const���͵�����ת����const���͵ģ����߰�const����ȥ����
//static_cast:����ʵ��C++�����û�����������֮����໥ת����
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
	A* a1 = new B;//a1��A���͵�ָ��ָ��һ��B���͵Ķ���
	A* a2 = new A;//a2��A���͵�ָ��ָ��һ��A���͵Ķ���
	B* b;
	C* c;
	b = dynamic_cast<B*>(a1);//���Ϊnot null������ת���ɹ���a1֮ǰָ��ľ���B���͵Ķ������Կ���ת����B���͵�ָ�롣
	if (b == NULL)
	{
		cout << "null" << endl;
	}
	else
	{
		cout << "not null" << endl;
		b->f();
	}
	b = dynamic_cast<B*>(a2);//���Ϊnull������ת��ʧ��
	if (b == NULL)
	{
		cout << "null" << endl;
	}
	else
	{
		cout << "not null" << endl;
		b->f();
	}
	c = dynamic_cast<C*>(a1);//���Ϊnull������ת��ʧ��
	if (c == NULL)
	{
		cout << "null" << endl;
	}
	else
	{
		cout << "not null" << endl;
		c->pp();
	}
	// const_cast���������ڲ�ͬ�������ת�����෴����������һ�������õı��ʽת���ɳ�����������ʹһ����������const���͵�����ת����const���͵ģ����߰�const����ȥ����
	int pop1 = 38383;
	const int pop2 = 2000;
	cout << "pop1, pop2:" << pop1 << "," << pop2 << endl;
	change(&pop1, -103);
	change(&pop2, -103);
	cout << "pop1, pop2:" << pop1 << "," << pop2 << endl;
	return 0;
}
