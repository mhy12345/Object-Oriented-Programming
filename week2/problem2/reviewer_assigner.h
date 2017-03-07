#ifndef _REVIEWER_ASSIGNER_H_
#define _REVIEWER_ASSIGNER_H_
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using std::ifstream;
using std::string;
using std::vector;
using std::pair;
using std::ofstream;
using std::endl;

class ReviewerAssigner
{
	private:
		vector<pair<string,string> > list;
	public:
		void load();
		void output();
};

#endif 
