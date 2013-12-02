/* Tehtävä: Harjoitus 18
Tekijä: Hanna Lukkarinen, IIO13S1
Pvm: 26.11.2013

Kuvaus: Tee ohjelma, joka kysyy viiden koiran nimet ja iät.
Tiedot tallennetaan tietuetaulukkoon.
a) järjestä tiedot ikä -kentän mukaan suuruusjärjestykseen
(pienimmästä suurimpaan). Ohjelma tulostaa lopuksi
jarjestetyn taulukon näytälle.
b) järjestä tiedot nimi -kentän mukaan aakkosjärjestyksessä
Ohjelma tulostaa lopuksi jarjestetyn taulukon näytolle.

Lajittelu tulee toteuttaa siten, että se toimisi samoin
myäs 50 tai 5000 koiran tapauksessa. */

#include <iostream>
using namespace std;
const int MAX = 5;

struct KOIRA
{
	char nimi[15];
	int ika;
};

void main()
{

	int valinta, i;
	KOIRA koirat[MAX+1];

	for (i = 0; i < MAX; i++)
	{
		cout<<"Anna "<<i+1<<". koiran nimi: ";
		cin>>ws;
		cin.getline(koirat[i].nimi,20);
		cout<<"Koiran ikä: ";
		cin>>ws>>koirat[i].ika;
		cout<<endl;
	}

	do {
		cout<<"Koirien järjestäminen"
			<<"\n1 - Aakkosjärjestys"
			<<"\n2 - Ikäjärjestys (nuorimmasta vanhimpaan)";
		cin>>valinta;
	} while(valinta != 1 && valinta != 2);

	for (i = 0; i<(MAX-1); i++)
	{

		if(strcmp(koirat[i].nimi, koirat[i+1].nimi) > 0 && valinta == 1)
		{
			KOIRA* tilap = new KOIRA;
			*tilap = koirat[i];
			koirat[i] = koirat[i+1];
			koirat[i+1] = *tilap;
			i = -1;
			delete tilap;
			tilap = NULL;
		}
		else if(koirat[i].ika > koirat[i+1].ika && valinta == 2)
		{
			KOIRA* tilap = new KOIRA;
			*tilap = koirat[i];
			koirat[i] = koirat[i+1];
			koirat[i+1] = *tilap;
			i = -1;
			delete tilap;
			tilap = NULL;
		}
	}

	for(i = 0; i < MAX; i++)
	{
		cout<<koirat[i].nimi<<", "<<koirat[i].ika<<endl;
	}
}