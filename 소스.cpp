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
	vector<string> aaa = Split("   aaa bbb ccc", ' ');
	for (int i = 0; i < aaa.size(); i++)
	{
		cout << aaa[i] << endl;
	}
}