#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <utility>
#include <string>

using namespace std;

int main() {
	int n, m;
	ofstream fs("claus");
	cout << "Inserte el número de palabras deseadas seguido del número ";
	cout << "de caracteres alfanumericos que desea que tenga cada palabra." << endl;
	cin >> n >> m;
	srand(time(NULL));
	for(int i = 0; i < n; ++i) {
		string par;
		for (int j = 0; j < m; ++j) {
			char a = (char)(rand()%10 + 48);
			char b = (char)(rand()%26 + 97);
			int d = rand()%2;
			if (d == 0) par += a;
			else par += b;
		}
		fs << par << endl;
	}
	fs.close();
}
