#ifndef HASH
#define HASH

#include <map>
#include <set>
#include <list>
#include <string>

using namespace std;

class Hash {
private:
	map<string, list<unsigned int> > hff;
	bool es_primer(int n);
	int prim(int n);
	int calc_m(int p, int n);
	int calc_k(int m, int n);
public:
	//Contructor
	Hash(int p, set<string> w);
	map<string, list<unsigned int> > hashFuncFam();
};
#endif
