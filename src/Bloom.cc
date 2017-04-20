#include "sha256.h"
#include "Bloom.h"
#include <iostream>
#include <cmath>
#include <utility>
#include <cstdlib>

Bloom::Bloom(){}

void Bloom::insertar_elemento(string pos){
    string s= sha256(pos);
	M.insert(pair<string,bool>(s,true));
	elementos.insert(pos);
}
bool Bloom::existe_elemento(string pos){
	return elementos.find(pos) != elementos.end();
}
bool Bloom::falso_positivo(string pos){
	string s= sha256(pos);
	bool b = M[s];
	return (b and elementos.find(pos) == elementos.end());
}

