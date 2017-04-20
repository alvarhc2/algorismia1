#ifndef _BLOOM_HH_
#define _BLOOM_HH_

#include <unordered_map>
#include <set>
#include <string>
using namespace std;

class Bloom {
private:
	unordered_map<string,bool> M;
	set<string> elementos;
public:
	//Contructor
	Bloom();
	void insertar_elemento(string pos);
	bool existe_elemento(string pos);
	bool falso_positivo(string pos);
};
#endif
