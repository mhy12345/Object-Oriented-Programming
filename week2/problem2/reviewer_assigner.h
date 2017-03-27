#ifndef _REVIEWER_ASSIGNER_H_
#define _REVIEWER_ASSIGNER_H_
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
using std::ifstream;
using std::string;
using std::vector;
using std::pair;
using std::ofstream;
using std::endl;
using std::set;

class ReviewerAssigner
{
	private:
		vector<pair<string,string> > list;
		vector<set<int> > reviewer;
	public:
		void load();
		void output();
		void choose();
};

#endif 
