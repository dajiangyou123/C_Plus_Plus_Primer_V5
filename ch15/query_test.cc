#include <iostream>
#include "textquery.h"
#include "queryresult.h"
#include "query_all.h"

using namespace std;

ostream& operator<<(ostream &os, const Query &query)
{
	return os << query.rep();
}

void runQueries(std::ifstream &infile)
{
	TextQuery tq(infile);

	/*while(true)
	{
		std::cout << "enter word to look for, or q to quit: ";
		string s;

		if(!(std::cin>>s) || s == "q")
			break;

		print(std::cout, tq.query(s)) << std::endl;
	}*/
	Query q = Query("fiery") & Query("bird") | Query("wind");
	cout << q <<endl;
	print(cout,q.eval(tq)) << endl;
}

int main()
{
	std::ifstream infile("data");
	runQueries(infile);
	return 0;
}
