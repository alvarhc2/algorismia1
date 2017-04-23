#include "Bloom_K.h"
#include <iostream>

Bloom_K::Bloom_K(map<string, list<unsigned int> > hff, int m) {
	vector<char> aux(m, 0);
	bloom = aux;
	map<string, list<unsigned int> >::iterator itm = hff.begin();
	while(itm != hff.end()) {
		elementos.insert((*itm).first);
		list<unsigned int>::iterator it = hff[(*itm).first].begin();
		while(it != hff[(*itm).first].end()) {
			if(bloom[*it] == 0) {
				bloom[*it] = 1;
			}
			++it;
		}
		++itm;
	}
}

bool Bloom_K::existe_elemento(string key) {
	return elementos.find(key) != elementos.end();
}

bool Bloom_K::falso_positivo(string key, list<unsigned int> l) {
	bool negative = false;
	list<unsigned int>::iterator it = l.begin();
	while(it != l.end() and not negative) {
		if(bloom[*it] == 0) negative = true;
		++it;
	}
	if(negative) return false;
	else {
		return elementos.find(key) == elementos.end();
	}
}
