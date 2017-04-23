#include <iostream>
#include <set>
#include <string>
#include <fstream>
#include <map>
#include "sha256.h"
#include "Bloom_s.h"
#include "Hash.h"
#include "Tab_hash.h"
#include "Bloom_K.h"
using namespace std;


void leer_entrada(set<string> &S){
   ifstream fe("data/claus");
   string key;
   while(!fe.eof()) {
      fe >> key;
      S.insert(key);
   }
   fe.close();
}

void K_funciones(set<string> &S) {
	int prob = 0;
	int op;
	while (prob <= 0 or prob >= 1000) {
		cout <<"Escriba la maxima probabilidad de falsos positivos admitida, en tanto por mil:"<<endl;
		cout <<"Ejemplo: 10"<<endl;
		cout <<"Esto representa una probabilidad de falso positivo de 10 por mil,"<<endl;
		cout <<"o lo que es lo mismo 1%."<<endl;
		cin >> prob;
		if(prob <= 0) {
			cout <<"Valor erroneo, introduzca una probabilidad más elevada"<<endl;
		}
		else if (prob >= 1000) {
			cout <<"Valor erroneo, introduzca una probabilidad más baja"<<endl;
		}
	}
	cout <<"Elija el modo de generación de las k-funciones de hash:"<<endl;
	cout <<"1 - Polinómica con coeficientes aleatorios (Explicada en clase)"<<endl;
	cout <<"2 - Tabulation Hashing"<<endl;
	cin >> op;
	map<string, list<unsigned int> > m;
	if(op == 1) {
		Hash h(prob, S);
		m = h.hashFuncFam();
		Bloom_K B = Bloom_K(m, h.get_m());
		int contador=0, steps=0;
		string key;
		while (cin >> key) {
			if (B.falso_positivo(key, h.hashFuncFamKey(key))) ++contador;
			++steps;
		}
		cout <<"Cantidad de falsos positivos: "<<contador<<endl;
		double porcentaje = (double)contador /(double)steps *100;
		cout <<"Porcentaje de falsos positivos: "<< porcentaje <<"%"<<endl;
	}
	else {
		Tab_hash h (prob, S);
		m = h.tabHashFuncFam();
		Bloom_K B = Bloom_K(m, h.get_m());			
		int contador=0, steps=0;
		string key;
		while (cin >> key) {
			if (B.falso_positivo(key, h.tabHashFuncFamKey(key))) ++contador;
			++steps;
		}
		cout <<"Cantidad de falsos positivos: "<<contador<<endl;
		double porcentaje = (double)contador /(double)steps *100;
		cout <<"Porcentaje de falsos positivos: "<< porcentaje <<"%"<<endl;
	}
}

void SHA(set<string> &S) {
	map<string, string> m;
	for(set<string>::iterator i = S.begin(); i!= S.end(); ++i) {
		string key = *i;
		string crypt = sha256(key);
		m[key]=crypt;
	}
	Bloom_s B;
	B.insertar_elementos(m);
	int contador=0, steps=0;
	string key;
	while (cin >> key) {
		if (B.falso_positivo(key)) ++contador;
	   ++steps;
	}
	cout <<"Cantidad de falsos positivos: "<<contador<<endl;
	double porcentaje = (double)contador /(double)steps *100;
	cout <<"Porcentaje de falsos positivos: "<< porcentaje <<"%"<<endl;
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
