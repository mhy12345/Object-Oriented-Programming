#include "SearchEngine.h"
#include "KMPSearchStrategy.h"
#include "KRSearchStrategy.h"
#include <cstdio>
const int SearchEngine::maxn = 1000;
const int SearchEngine::maxm = 30;

SearchEngine::SearchEngine(StrategyName KR)
{
	choose_strategy(KR);
}

void SearchEngine::choose_strategy(StrategyName KR)//改变当前策略
{
	if (SS)delete SS;
	switch(KR)
	{
		case (SearchEngine::KMP):
			SS = new KMPSearchStrategy();
			fprintf(stderr,"Strategy switch into KMP\n");
			break;
		case (SearchEngine::KR):
			SS = new KRSearchStrategy();
			fprintf(stderr,"Strategy switch into KR\n");
			break;
	}
	match = new char[maxn];
	pattern = new char[maxm];
}

void SearchEngine::load_match(const char* filename)
{
	FILE *fin = fopen(filename,"r");
	int n = 0;
	char ch;
	while (n<maxn && ~(ch = fgetc(fin)))
		if (ch!=' ' && ch!='\n' && ch!='\r' && ch!='\t')
		match[n++] = ch;
	fclose(fin);

}

void SearchEngine::load_pattern(const char* filename)
{
	FILE *fin = fopen(filename,"r");
	int n = 0;
	char ch;
	while (n<maxn && ~(ch = fgetc(fin)))
		if (ch!=' ' && ch!='\n' && ch!='\r' && ch!='\t')
			pattern[n++] = ch;
	fclose(fin);
}

void SearchEngine::do_search()//运行匹配
{
	SS->compile(pattern);
	//SS->print();
	printf("Matches count:%d\n",SS->match(match));
}
