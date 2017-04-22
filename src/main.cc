#include <iostream>
#include <set>
#include <string>
#include <map>
#include "sha256.h"
#include "Bloom_s.h"
using namespace std;


void leer_entrada(set<string> &S){
}

void K_funciones(set<string> S) {
	
}

void SHA(set<string> S) {
	map<string, string> m;
	for(set<string>::iterator i = S.begin(); i!= S.end(); ++i) {
		string key = *i;
		string crypt = sha256(key);
		m[key]=crypt;
	}
	Bloom_s B;
	B.insertar_elementos(m);
}


int main() {
	cout <<"Leyendo entrada..."<<endl;
	set<string> S;
	leer_entrada(S);
	cout <<"Entrada procesada adecuadamente"<<endl<<endl;
	cout <<"Elija el modo de encriptacion deseado:"<<endl;
	cout <<"1 - K funciones de hash"<<endl;
	cout <<"2 - SHA256"<<endl;
	int op;
	cin >> op;
	while (op != 1 and op != 2) {
		cout <<op<<" no es correcto. Vuelva a elegir: "<<endl;
		cout <<"1 - K funciones de hash"<<endl;
		cout <<"2 - SHA256"<<endl;
		cin >> op;
	}
	if (op ==1) K_funciones(S);
	else 	SHA(S);
}
