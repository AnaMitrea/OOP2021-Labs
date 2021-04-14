#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
using namespace std;
ifstream fin("Text.txt");

string to_Lower(string& s)
{
	int len = size(s);
	for (int i = 0; i < len; i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i] = s[i] + 32;
		}
			
	}
	return s;
}

class CompareFreq
{
public:
	bool operator()(pair<string, int>& a, pair<string, int>& b)
	{
		if (a.second == b.second)
			return (a.first > b.first);
		return (a.second < b.second);
	}
};


int main()
{
	string str;
	string sep = " .,!?";
	map<string, int> words;
	getline(fin, str);
	if (!fin)
	{
		cerr << "Error! File couldn't be opened!" << endl;
		return 0;
	}

	cout << "[ Initial string ]" << endl << str << endl << endl;
	int len = size(str);
	int i = 0, j;
	while (i < len)
	{
		j = i;
		while (sep.find(str[j]) == string::npos && j < len)
		{
			j++;
		}
		string aux = str.substr(i, j - i); // sustrag cuvintele de lungime j-i de la pozitia i
		aux = to_Lower(aux);
	
		map<string, int>::iterator it;
		it = words.find(aux);
		if (it != words.end()) // daca s-a gasit deja cuvantul cresc frecventa
		{
			words[aux]++;
		}
		else
		{
			words.insert(pair<string, int>(aux, 1));
		}
		i = j;
		while (sep.find(str[i]) != string::npos && i < len)
		{
			i++;
		}
	}
	map<string, int>::iterator it;
	cout << "[ MAP ]" << endl;
	for (it = words.begin(); it != words.end(); it++)
	{
		cout << it->first << "  " << it->second << endl;
	}
	cout << endl;

	priority_queue<pair<string, int>, vector<pair<string, int>>, CompareFreq> myqueue;
	cout << "[ SORTED PRIORITY QUEUE ]" << endl;
	for (it = words.begin(); it != words.end(); it++)
	{
		myqueue.push(make_pair(it->first, it->second));
	}

	while (myqueue.empty() == false)
	{
		cout << myqueue.top().first << "  " << myqueue.top().second<< endl;
		myqueue.pop();
	}
	return 0;
}