#ifndef _TEAM_ASSIGNER_H_
#define _TEAM_ASSIGNER_H_
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
using std::ifstream;
using std::string;
using std::vector;
using std::pair;
using std::ofstream;
using std::endl;

class TeamAssigner
{
	private:
		vector<pair<string,string> > list;
	public:
		void load();
		void output();
};

#endif 
