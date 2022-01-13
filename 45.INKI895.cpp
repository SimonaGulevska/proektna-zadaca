//Simona Gulevska INKI895 45.Kodiranje i dekodiranje na tekst spored daden kluc
#include<iostream>
#include<cstring>
using namespace std;
//deklaracii na funkcii za kodiranje i dekodiranje
void KodiranjeString (char VnesenTekst [], int dolVnesenTeks, int broj);
void DekodiranjeString (char VnesenTekst [], int dolVnesenTeks, int broj);
int main ()
{
	char VnesenTekst [400],vnesentextpom [100];
	char broj [20], izbor;
	int dolVnesenTeks, cifra, brcifri= 0, brojac=0;
	//vnesuvanje na tekst za kodiranje so kontrola za tocen vnes
	while(true)
	{
		cout<<"\n Vnesete tekst za kodiranje: = ";
		cin.getline (VnesenTekst,400);
		dolVnesenTeks=strlen (VnesenTekst);
		brojac=0;
		for (int i=0; i<dolVnesenTeks; i++)
	if (!isalpha (VnesenTekst[i]) && !isdigit (VnesenTekst[i]) && VnesenTekst[i]!=' ')
				brojac=brojac+1;
		if (brojac!=0)
			cout<<" GRESKA!!! Mora povtoren vnes!!!! ";
		else
		//izlez od ciklusot koga ke se vnesi tocen vlez
			break;
	}
	//ciklus za korekcija na vnesen broj
	while(true)
	{
		cout<<"\n Vnesete broj so pomalku od 10 cifri: = ";
		cin.getline (broj,20);
		brojac=strlen(broj);
		int pombroj=0;
		for (int i=0; i<brojac; i++)
		if (isdigit(broj[i]))
			pombroj++;
		if (pombroj==brojac && brojac<=10)
			break;
		else
			cout<<" GRESKA VNESOVTE POGOLEM BROJ!!!! ";
	}
	//meni so moznost za izbor
	do
	{
		cout<<"\n a. Kodiranje na vnesen tekst ";
		cout<<"\n b. Dekodiranje na kodiraniot tekst ";
		cout<<"\n c. Dekodiranje vnesen tekst ";
		cout<<"\n d. Izlez ";
		cout<<"\n Vnesete izbor: ";
		cin>>izbor;
		switch(izbor)
		{
			case 'a':
					//povik na funkcija za kodiranje
					 KodiranjeString (VnesenTekst, dolVnesenTeks, brojac);
					 break;
			case 'b':
					//povik na funkcija za dekodiranje
					 DekodiranjeString (VnesenTekst, dolVnesenTeks, brojac);
					 break;
			case 'c': 
                    //povik na fukcija za dekodiranje
                    DekodiranjeString (vnesentextpom, dolVnesenTeks, brojac);
                    break;
			default: cout<<"\n POGRESEN IZBOR "<<endl;
		}
	}
while (izbor!='d');
	return 0;
}
void KodiranjeString (char VnesenTekst [], int dolVnesenTeks, int broj)
{
	for (int i=0; i<dolVnesenTeks; i++)
	{
		int ascibroj=(int)VnesenTekst[i];
		if (isalpha (VnesenTekst[i]))
		{
		//kontrola dali bukvata e golema
			if (ascibroj>=65 && ascibroj<=90)
			{
				if (ascibroj+broj<=90)

					VnesenTekst[i]=(char)((int)VnesenTekst[i]+broj);
				else
				VnesenTekst[i]=(char)(65+((int)VnesenTekst[i]+broj)-90-1);
			}
			//kontrola dali bukvata e mala
			if (ascibroj>=97 && ascibroj<=122)
			{
				if (ascibroj+broj<=122)
			VnesenTekst[i]=(char)((int)VnesenTekst[i]+broj);
				else
			VnesenTekst[i]=(char)(97+((int)VnesenTekst[i]+broj)-122-1);
				}
			}
		}
	cout<<endl;
	for (int i=0; i<dolVnesenTeks; i++)
		cout<<VnesenTekst[i];
	cout<<endl;
}
void DekodiranjeString (char VnesenTekst [], int dolVnesenTeks, int broj)
{
	for (int i=0; i<dolVnesenTeks; i++)
	{
		//se definria kodot na ascii brojot
			int ascibroj=(int)VnesenTekst[i];
		if (isalpha(VnesenTekst[i]))
		{
		//kontrola dali bukvata e golema
			if (ascibroj>=65 && ascibroj<=90)
			{
				if (ascibroj-broj>=65)

					VnesenTekst[i]=(char)((int)VnesenTekst[i]-broj);
				else
			VnesenTekst[i]=(char)(90-(65-((int)VnesenTekst[i]-broj))+1);
			}
			//kontrola dali bukvata e mala
			if (ascibroj>=97 && ascibroj<=122)
			{
				if (ascibroj-broj>=97)
					VnesenTekst[i]=(char)((int)VnesenTekst[i]-broj);
				else
			VnesenTekst[i]=(char)(122-(97-((int)VnesenTekst[i]-broj))+1);
			}
		}
	}
	cout<<endl;
	for (int i=0; i<dolVnesenTeks; i++)
		cout<<VnesenTekst[i];
	cout<<endl;
}
