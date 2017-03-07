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

void ReviewerAssigner::output()
{
	ofstream fout("Reviewer.txt");
	for (int i=0;i<(int)list.size();i++)
	{
		fout<<"Homework Reviewer for ("<<list[i].first.c_str()<<")"<<list[i].second.c_str()<<":"<<endl;
		int cnt=0;
		while (cnt<3)
		{
			int index = rand()%list.size();
			if (index == i)
			{
				continue;
			}else
			{
				fout<<">>#"<<cnt+1<<" ("<<list[index].first.c_str()<<") "<<list[index].second.c_str()<<endl;
				cnt++;
			}
		}
		fout<<endl;
	}
	fout.close();
}
