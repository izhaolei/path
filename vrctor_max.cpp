#include<iostream>
#include<vector>
#include<map>
using namespace std;
int maxvalue(std::vector<int> vec)
{
	vector<int>::iterator iter = vec.begin();

	map<int, int> key;

	for (; iter < vec.end(); iter++)
	{
		key[*(iter)]++;

	}
	int maxvalue = 0;
	int key1 = -1;
	map<int, int>::iterator iter1 = key.begin();
	for (; iter1 != key.end(); iter1++)
	{
		int temp = 0;
		temp = iter1->second;
		//cout << '(' << iter1->first << ' ' << iter1->second << ')' << '\t';
		if (temp >= maxvalue)
		{
			maxvalue = temp;
			key1 = iter1->first;
		}
	}
	return key1;
}
int main()
{
	vector<int> a = {1,2,3,2,4,2,3,6,2};


	cout << "max is: " << maxvalue(a);
	return 0;
}