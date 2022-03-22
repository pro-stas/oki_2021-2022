#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
using namespace std;

struct typ_uczen {
   string imie;
   int klasa;
   bool czy_w_samorzadzie;
};

bool Czy_t1_ZLewejStrony (const typ_uczen &t1, const typ_uczen &t2) {
//najpierw ten ktory ma krtosze imie  (krtosze imie z lewej lewej strony)
 if (t1.imie.length() != t2.imie.length())
    return t1.imie.length() < t2.imie.length();
//najpierw ten ktpry w samorzadzie (1 z lewej strony)
 if (t1.czy_w_samorzadzie != t2.czy_w_samorzadzie)
    return t1.czy_w_samorzadzie > t2.czy_w_samorzadzie;
//w kazdym innym przapdku najpierw ten kto ma mniejsza klase (mniejsza klasa z lewej strony)
 return t1.klasa < t2.klasa;
}

int main() {
 typ_uczen uczen;
 vector<typ_uczen> uczniowie; 
 int i;

 uczen.imie = "Janina"; uczen.klasa = 7; uczen.czy_w_samorzadzie = true;
 uczniowie.push_back(uczen);
 uczen.imie = "Tadek"; uczen.klasa = 3; uczen.czy_w_samorzadzie = false;
 uczniowie.push_back(uczen);
 uczen.imie = "Piotr"; uczen.klasa = 7; uczen.czy_w_samorzadzie = false;
 uczniowie.push_back(uczen);

 cout << "Imię | klasa | czy w samorządzie?" "\n" "\n" "kolejność przed sortowaniem:" << "\n";
 for (i=0; i<uczniowie.size(); ++i) {
 	cout << uczniowie[i].imie << " | ";
 	cout << uczniowie[i].klasa << " | ";
 	if (uczniowie[i].czy_w_samorzadzie == 1) {
 		cout << "true" << "\n";
 	} else {
 		cout << "false" << "\n";
 	}
 } 
 cout << "\n";
 
 sort(uczniowie.begin(), uczniowie.end(), Czy_t1_ZLewejStrony);

 cout << "kolejność po sortowaniu:" << "\n";
 for (i=0; i<uczniowie.size(); ++i) {
 	cout << uczniowie[i].imie << " | ";
 	cout << uczniowie[i].klasa << " | ";
 	if (uczniowie[i].czy_w_samorzadzie == 1) {
 		cout << "true" << "\n";
 	} else {
 		cout << "false" << "\n";
 	}
 } 
 cout << "\n";


 return 0;
}


