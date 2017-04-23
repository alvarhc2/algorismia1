#ifndef BLOOM_K
#define BLOOM_K

#include <map>
#include <set>
#include <string>
#include <bitset>
#include <list>
#include <vector>
using namespace std;

class Bloom_K {
private:
	vector<char> bloom;
	set<string> elementos;
public:
	//Contructor
	Bloom_K(map<string, list<unsigned int> > hff, int m);
	bool existe_elemento(string key);
	//Devuelve true si es un falso positivo
	bool falso_positivo(string key, list<unsigned int> l);
};
#endif
