///union_find http://blog.csdn.net/u013486414/article/details/38682057
#include <iostream>
using namespace std;
const int MAXSIZE = 50;
int uset[MAXSIZE];
int Rank[MAXSIZE];
void makeset(int size)
{
	for (int i = 0; i < size;i++)
	{
		uset[i] = i;
		Rank[i] = 0;
	}
}
int find(int x)
{
	if (x != uset[x])
	{
		x = uset[x];
		return find(x);
	}
	return x;
}
void unionSet(int x, int y)
{
	if ((x = find(x)) == (y = find(y)))
	{
		return;
	}
	if (Rank[x] > Rank[y])
	{
		uset[y] = x;
	}
	else
	{
		uset[x] = y;
		if (Rank[x] == Rank[y])
		{
			Rank[y] += 1;
		}
	}
}
int main()
{
	makeset(10);

}