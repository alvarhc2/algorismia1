#include <iostream>
#include <limits>
#include "Bloom.h"
using namespace std;

int main() {
	Bloom b = Bloom();
	b.insertar_elemento("lol");
	bool b1= b.existe_elemento("lol");
	bool b2= b.existe_elemento("lel");
	bool b3= b.falso_positivo("lol");
	bool b4= b.falso_positivo("lel");
	cout <<b1<<" "<<b2<<" "<<b3<<" "<<b4<<endl;
}
