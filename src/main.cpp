

using namespace std;
#include "Matrice.h"
#include "Vecteur.h"

int main() {
Matrice<int> lul(3,4);
lul.at(2) = {2,3,4,5};
lul.at(0).at(2) = 21381923;
cout << lul << endl;
lul = lul*3;
cout << lul << endl;
}
