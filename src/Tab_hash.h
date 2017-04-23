#ifndef TAB_HASH
#define TAB_HASH

#include <map>
#include <set>
#include <list>
#include <string>
#include <vector>

using namespace std;

class Tab_hash {
private:
	map<string, list<unsigned int> > thff;
	vector<vector< vector<unsigned int> > > Tab;
	int m;
	int pot2(int m);
	int calc_m(int p, int n);
	int calc_k(int m, int n);
public:
	//Contructor
	Tab_hash(int p, set<string> w);
	map<string, list<unsigned int> > tabHashFuncFam();
	list<unsigned int> tabHashFuncFamKey(string key);
	int get_m();
};
#endif
