#include "sha256.h"
#include "Bloom_s.h"
#include <iostream>
#include <cmath>
#include <utility>
#include <cstdlib>

Bloom_s::Bloom_s(){}

void Bloom_s::insertar_elementos(map<string,string> m){
   for(map<string,string>::iterator i = m.begin(); i != m.end(); ++i){
		pair<string,string> p = *i;
		m[p.first]=m[p.second];
		elementos.insert(p.first);
	}
}
bool Bloom_s::existe_elemento(string key){
	return elementos.find(key) != elementos.end();
}
bool Bloom_s::falso_positivo(string key){
	string s= sha256(key);
	bool b = M[s];
	return (b and elementos.find(key) == elementos.end());
}
