class MinStack {
private:
	stack<int> s;
	stack<int> Min;
public:
	/** initialize your data structure here. */
	MinStack()
	{

	}

	void push(int x)
	{
		s.push(x);
		if (Min.empty() || Min.top() >= x)
		{
			Min.push(x);
		}

	}

	void pop()
	{
		int temp = s.top();
		if (temp == Min.top())
		{
			Min.pop();
		}
		s.pop();

	}

	int top()
	{
		return s.top();

	}

	int getMin()
	{
		if (Min.empty())
		{
			return INT_MAX;
		}
		return Min.top();

	}
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack obj = new MinStack();
* obj.push(x);
* obj.pop();
* int param_3 = obj.top();
* int param_4 = obj.getMin();
*/