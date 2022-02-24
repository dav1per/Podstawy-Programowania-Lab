/*
Autor: Igor Wlodarczyk
Grupa: PN 13:15 TP
Data: 8.10.2021
Tytu³: Lab0
*/


#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;
void wizytowka1()
{
	cout<<"Imie i nazwisko: Igor Wlodarczyk"<<endl;
	cout<<"Adres: Szkolna 1a, Bialystok, Polska"<<endl;
	cout<<"Numer telefonu: 111 222 333"<<endl;
	cout<<"Adres email: igorw2000@gmail.com"<<endl;
	
}

void wizytowka2()
{
	printf("Imie i nazwisko: Krzysztof Polak\n");
	printf("Adres: Koszykowa 2, Bialystok, Polska\n");
	printf("Numer telefonu: 123 654 333\n");
	printf("Adres email: kpolak21@gmail.com\n");
}

void zmienne1()
{
	cout<<"Podaj wartosci trzech zmiennych"<<endl;
	int a, b, c;
	cin>>a>>b>>c;
	cout<<"Suma: "<<a+b+c<<endl;
	cout<<"Iloczyn: "<<a*b*c<<endl;
	cout<<"Srednia: "<<(a+b+c)/3<<endl;
}

void zmienne2()
{
	printf("Podaj wartosci trzech zmiennych\n");
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf ("Suma: %d\n", a+b+c);
	printf ("Iloczyn: %d\n", a*b*c);
	printf ("Srednia: %f\n", (a+b+c)/3);
	
}

void kolo1()
{
	printf("Podaj promien kola\n");
	double r;
	scanf("%lf", &r);
	printf ("Pole kola to: %lf\n", r*r*M_PI);
	printf ("Obwod kola to: %lf\n", 2*r*M_PI);
	
}

void kolo2()
{
	cout<<"Podaj promien kola"<<endl;
	double r;
	cin>>r;
	cout<<"Pole kola to: "<<r*r*M_PI<<endl;
	cout<<"Obwod kola to: "<<2*r*M_PI<<endl;
}

int main()
{
	printf("Igor Wlodarczyk PN 13:15\n\n");
	int menu = 1;
	int n;
	while (menu==1)
	{
		printf ("Wybierz pozycje z menu (1-7)\n");
		printf ("1.Wizytowka (iostream)\n");
		printf ("2.Wizytowka (stdio.h)\n");
		printf ("3.Trzy zmienne (iostream)\n");
		printf ("4.Trzy zmienne (stdio.h)\n");
		printf ("5.Kolo (stdio.h)\n");
		printf ("6.Kolo (iostream)\n");
		printf ("7.Koniec\n\n");
		scanf ("%d",&n);
		switch (n)
		{
			case 1:
				wizytowka1();
				break;
			case 2:
				wizytowka2();
				break;
			case 3:
				zmienne1();
				break;
			case 4:
				zmienne2();
				break;
			case 5:
				kolo1();
				break;
			case 6:
				kolo2();
				break;
			case 7:
				menu=0;
				break;
			
		}
		printf("\n\n");
	}
	
return 0;
}
