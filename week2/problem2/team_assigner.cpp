#include "team_assigner.h"

void TeamAssigner::load()
{
	ifstream fin("ContactEmail.txt");
	string foo,bar;
	fin>>foo>>bar;
	while (fin>>foo>>bar)
	{
		list.push_back(make_pair(foo,bar));
	}
	fin.close();
}

void TeamAssigner::output()
{
	ofstream fout("Team.txt");
	random_shuffle(list.begin(),list.end());
	int gcnt=0;
	while (!list.empty())
	{
		fout<<"Group #"<<++gcnt<<endl;
		int cnt;
		if (list.size()<=4)
			cnt=list.size();
		else
			cnt=3;
		for (int i=1;i<=cnt;i++)
		{
			fout<<">> #"<<i<<" ("<<list.back().first<<") "<<list.back().second<<endl;
			list.pop_back();
		}
	}
}
