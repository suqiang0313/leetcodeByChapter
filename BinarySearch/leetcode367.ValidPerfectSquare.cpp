class Solution {
public:
	bool isPerfectSquare(int num)
	{
		if (num < 0)
		{
			return false;
		}
		long long l = 0;
		long long  r = num/2+1;
		while (l + 1 < r)
		{
			long long  m = l + (r - l) / 2;
			long long result = m*m;
			if (result== num)
			{
				return true;
			}
			else
			{
				if (result< num)
				{
					l = m;
				}
				else
				{
					r = m;
				}
			}
		}
		if (l*l == num || r*r == num)
		{
			return true;
		}
		return false;

	}
};