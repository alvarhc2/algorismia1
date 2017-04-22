#ifndef _BLOOM_HH_
#define _BLOOM_HH_

#include <map>
#include <set>
#include <string>
using namespace std;

class Bloom_s {
private:
	map<string,bool> M;
	set<string> elementos;
public:
	//Contructor
	Bloom_s();
	void insertar_elementos(map<string,string> m);
	bool existe_elemento(string key);
	bool falso_positivo(string key);
};
#endif
