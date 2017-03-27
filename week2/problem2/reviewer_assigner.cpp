#include "reviewer_assigner.h"

void ReviewerAssigner::load()
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

void ReviewerAssigner::choose()
{
	for (int i=0;i<(int)list.size();i++)
	{
		int cnt=0;
		set<int> S;
		while (cnt<3)
		{
			int index = rand()%list.size();
			if (index == i || S.find(index)!=S.end())
			{
				continue;
			}else
			{
				S.insert(index);
				cnt++;
			}
		}
		reviewer.push_back(S);
	}
}

void ReviewerAssigner::output()
{
	ofstream fout("Reviewer.txt");
	for (int i=0;i<(int)list.size();i++)
	{
		fout<<"Homeword Reviewers for "<<list[i].first<<endl;
		for (set<int> :: iterator it1 =reviewer[i].begin();it1!=reviewer[i].end();it1++)
		{
			fout<<list[*it1].first<<endl;
		}
	}
	fout.close();
}
