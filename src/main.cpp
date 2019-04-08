using namespace std;
#include "Matrice.h"
#include "Vecteur.h"

int main() {
	Matrice<int> lul(3, 4);
	Matrice<int> lol(3, 4);
	vector<int> lal = { 2, 3, 4, 5 };
	Vecteur<int> lel = lal;
	cout << lel;
	lul.at(2) = lel;
	lol.at(2) = lel;
	lul.at(0).at(2) = 213;
	lol.at(0).at(2) = 213;
	cout << lul << endl;
	lul = lul * 3;
	cout << lul << endl;
	lul = lol * lul;
	cout << lul << endl;
	system("PAUSE");
}
