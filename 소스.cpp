#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> Split(string list, char SplitChar)
{
	vector<string> ReturnList;

	int Snum = 0;
	for (int i = 0; i < list.length(); i++)
	{
		if (list[i] == SplitChar && Snum == i)
		{
			Snum++;
		}
		else if (list[i] == SplitChar)
		{
			string tmp = "";
			for (int j = Snum; j < i; j++)
			{
				tmp += list[j];
			}
			Snum = i + 1;
			ReturnList.push_back(tmp);
		}
		else if (i == list.length() - 1)
		{
			string tmp = "";
			for (int j = Snum; j <= i; j++)
			{
				tmp += list[j];
			}
			ReturnList.push_back(tmp);
		}
	}
	return ReturnList;
}

int main()
{
	string answer = "";
	vector<string> list = Split("-1 -2 -3 -4", ' ');
	int MaxNum = stoi(list[0]);
	int MaxNumIndex = 0;
	int MinNum = stoi(list[0]);
	int MinNumIndex = 0;
	for (int i = 0; i < list.size(); i++)
	{
		int tmp = stoi(list[i]);
		if (tmp >= MaxNum)
		{
			MaxNum = tmp;
			MaxNumIndex = i;
		}
		if (tmp <= MinNum)
		{
			MinNum = tmp;
			MaxNumIndex = i;
		}
	}
	answer = list[MinNumIndex] + ' ' + list[MaxNumIndex];
	cout << MaxNumIndex;
}