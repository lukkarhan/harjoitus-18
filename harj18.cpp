/* Teht�v�: Harjoitus 18
Tekij�: Hanna Lukkarinen, IIO13S1
Pvm: 26.11.2013

Kuvaus: Tee ohjelma, joka kysyy viiden koiran nimet ja i�t.
Tiedot tallennetaan tietuetaulukkoon.
a) j�rjest� tiedot ik� -kent�n mukaan suuruusj�rjestykseen
(pienimm�st� suurimpaan). Ohjelma tulostaa lopuksi
jarjestetyn taulukon n�yt�lle.
b) j�rjest� tiedot nimi -kent�n mukaan aakkosj�rjestyksess�
Ohjelma tulostaa lopuksi jarjestetyn taulukon n�ytolle.

Lajittelu tulee toteuttaa siten, ett� se toimisi samoin
my�s 50 tai 5000 koiran tapauksessa. */

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
		cout<<"Koiran ik�: ";
		cin>>ws>>koirat[i].ika;
		cout<<endl;
	}

	do {
		cout<<"Koirien j�rjest�minen"
			<<"\n1 - Aakkosj�rjestys"
			<<"\n2 - Ik�j�rjestys (nuorimmasta vanhimpaan)";
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