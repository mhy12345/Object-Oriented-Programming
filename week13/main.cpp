#include "SearchEngine.h"

int main()
{
	SearchEngine SE;
	SE.choose_strategy(SearchEngine::KR);
	SE.load_match("match.txt");
	SE.load_pattern("pattern.txt");
	SE.do_search();
	SE.choose_strategy(SearchEngine::KMP);
	SE.load_match("match.txt");
	SE.load_pattern("pattern.txt");
	SE.do_search();
}
