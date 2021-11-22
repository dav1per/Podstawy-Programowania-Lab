/*
Autor: Igor Wlodarczyk
Grupa: PN/P 13:15
Temat: Laboratorium 2
Data: 31.10.2021
*/


#include <iostream>
#include <stdio.h>
#include <math.h>
#include <ctime>
#include <cstdlib>


using namespace std;

void zadanie1()
{
	int k,w,i,j,a;
	printf ("Program drukuje tabliczke mnozenia\n");
	printf("Podaj liczbe wierszy: ");
	scanf("%d", &w);
	printf("Podaj liczbe kolumn: ");
	scanf("%d", &k);
	
	printf("    |");
	for (a=1; a<=k; a++)
	{
		printf("%5d", a);
	}
	printf("\n");
	printf("----|");
	for (a=1; a<=k; a++)
	{
		printf("-----");
	}
	printf("\n");
	
	for(i=1; i<=w; i++)
	{
		printf("%3d |", i);
		for (j=1; j<=k; j++)
		{
			printf("%5d", i*j);
		}
		printf("\n");
	}
}

void zadanie2()
{
	unsigned long liczba;
	cout<<"Podaj liczbe dla ktorej chcesz obliczyc sume cyfr: ";
	cin>>liczba;
	int suma=0;
	while (liczba>0)
	{
		suma+=liczba%10;
		liczba/=10;
	}
	
	cout<<"Suma cyfr to: "<<suma<<endl;
}

void zadanie3()
{
	int a,b,c,max;
	int nwd;
	int nww;
	cout<<"Podaj a i b"<<endl;
	cin>>a>>b;
	
	max=a;
	if (b>a)
	{
		max=b;
	}
	
	for (c=1; c<=max; c++)
	{
		if(a%c==0 && b%c==0)
		{
			nwd=c;
		}
	}
	cout<<"Najwiekszy wspolny dzielnik liczb "<<a<<" i "<<b<<" to: "<<nwd<<endl;
	nww=0;
	bool koniec=false;
	while (koniec==false)
	{
		nww++;
		if(nww%a==0 && nww%b==0)
		{
			koniec=true;
		}

	}
	cout<<"Najmniejsza wspolna wielokrotnosc liczb "<<a<<" i "<<b<<" to: "<<nww<<endl;

	
}

void zadanie4()
{
double eps;
double wyraz1, s1=0;
printf("Podaj dokladnosc eps\n");
scanf (" %lf", &eps);
//szereg 1
double k=1;
wyraz1 = 1;
while (fabs(wyraz1/(2*k-1))>=eps)
{
	s1+=wyraz1/(2*k-1);
	k++;
	wyraz1*=-1;
}

printf("Suma szeregu S1 to: %f\n", 4*s1);	
//szereg 2
double wyraz2, s2=0;
double j=1;
wyraz2=1;
while (wyraz2>=eps)
{
	   	s2+=wyraz2;
		j++;
		wyraz2/=j;
}
printf("Suma szeregu S2 to: %f\n", s2+1);	
}

void zadanie5()
{
	srand (time(NULL));
	cout<<"Podaj przedzial wartosci [a,b], z ktorego maja byc losowane liczby calkowite oraz ilosc liczb"<<endl;
	float los;
	int i,a,b,n;
	cout<<"a: "; cin>>a;
	cout<<"b: "; cin>>b;
	cout<<"Ilosc liczb: "; cin>>n;
	/// dodatnie
	float suma1=0, k1=0;
	/// ujemne
	float suma2=0, k2=0;
	for (i=0; i<n; i++)
	{
		los = a + rand()%(b - a +1);
		cout<<los<<endl;
		if(los>0)
		{
			suma1+=los;
			k1++;
		} else if (los<0)
		{
			suma2+=los;
			k2++;
		}
	}
	cout<<endl;
	cout<<"Podsumowanie"<<endl;
	if (k1>0)
	{
		cout<<"Suma liczb dodatnich: "<<suma1<<endl;
		cout<<"Ilosc liczb doatnich: "<<k1<<endl;
		cout<<"Srednia liczb dodatnich: "<<(suma1/k1)<<endl;
	} else cout<<"Brak liczb dodatnich"<<endl;
	
	if (k2>0)
	{
		cout<<"Suma liczb ujemnych: "<<suma2<<endl;
		cout<<"Ilosc liczb ujemnych: "<<k2<<endl;
		cout<<"Srednia liczb ujemnych: "<<(suma2/k2)<<endl;
	} else cout<<"Brak liczb ujemnych"<<endl;
	
	
	
}


int main()
{
	cout<<"Autor: Igor Wlodarczyk";
	int n;
	bool menu=true;
	while(menu==true)
	{
		cout<<endl<<endl;
		cout<<"Menu (1-6)"<<endl;
		cout<<"1. Zadanie 1 (tabliczka mnozenia)"<<endl;
		cout<<"2. Zadanie 2 (suma cyfr)"<<endl;
		cout<<"3. Zadanie 3 (nwd i nww)"<<endl;
		cout<<"4. Zadanie 4 (sumy szeregow)"<<endl;
		cout<<"5. Zadanie 5 (liczby losowe)"<<endl;
		cout<<"6. Koniec"<<endl;
		cin>>n;
		switch(n)
		{
		case 1:
			cout<<endl;
			zadanie1();
			break;
		case 2:
			cout<<endl;
			zadanie2();
			break;
		case 3:
			cout<<endl;
			zadanie3();
			break;
		case 4:
			cout<<endl;
			zadanie4();
			break;
		case 5:
			cout<<endl;
			zadanie5();
			break;
		case 6:
			menu=false;
			break;
		}
		
	}
	
}