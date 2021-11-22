/*
Autor: Igor Wlodarczyk
Grupa: PN/P 13:15
Temat: Laboratorium 1
Data: 14.10.2021
*/

#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

void zadanie1()
{
	cout<<"Podaj wspolczynniki a,b,c: "<<endl;
	float a,b,c;
	cin>>a>>b>>c;
	if (a!=0)
	{
		   float delta;
		   delta = b*b-4*a*c;
		   if (delta>0)
		   {
		   	float x1=(-b-sqrt(delta))/(2*a);
		   	float x2=(-b+sqrt(delta))/(2*a);
		   	cout<<"Rozwiazania rownanania kwadratowego to: "<<x1<<", "<<x2<<endl;
		   }	else if (delta==0)
		   {
		   	float x0=-b/(2*a);
		   	cout<<"Rozwiazanie rownania kwadratowego to: "<<x0<<endl;
		   } else cout<<"Brak pierwiastkow rownania kwadratowego (delta<0)"<<endl;
	} else cout<<"Nie jest to rownanie kwadratowe (a=0)"<<endl;
	
}

void zadanie2()
{
	int dzien, miesiac, rok;
	printf ("Podaj kolejno dzien, miesiac, rok\n");
	scanf("%d %d %d", &dzien,&miesiac, &rok );
	if (miesiac>0 && miesiac <13)
	{
			int dni[]={31,29,31,30,31,30,31,31,30,31,30,31};
		if (rok%4!=0 || rok%100==0 && rok%400!=0)
		{
		dni[1]=28;
		} 
		
		if (dzien < dni[miesiac-1]+1 && dzien >0)
		{
			printf ("Data %d-%d-%d jest poprawna!\n", dzien, miesiac, rok);
		} else printf ("Data %d-%d-%d nie jest poprawna!\n", dzien, miesiac, rok);
	} else printf ("Data %d-%d-%d nie jest poprawna!\n", dzien, miesiac, rok);
	
}

void zadanie3()
{
	int n=3;
	float tab[n];
	printf("Podaj dlugosci bokow\n");
	scanf("%f %f %f",&tab[0],&tab[1],&tab[2]);

	int i, j;

	for (i=0; i<n; i++)
	{
		for (j=1; j<n-i; j++)
		{
			if (tab[j-1]>tab[j])
			{
				swap(tab[j-1],tab[j]);
			}
		}
	}

	if(tab[2]<tab[0]+tab[1])
	{
		float suma = tab[0]*tab[0]+tab[1]*tab[1];
		float mno = tab[2]*tab[2];
		if(tab[0]==tab[1] && tab[0]==tab[2]) 
		{
			if (mno>suma)
			{
				printf ("Mozna utworzyc trojkat rownoboczny rozwartokatny\n");
			} else 
			{
				if (mno==suma)
				{
				printf ("Mozna utworzyc trojkat rownoboczny prostokatny\n");	
				} else 
				{
					if(mno<suma)
					{
					printf ("Mozna utworzyc trojkat rownoboczny ostrokatny\n");	
					}
				}
			}
			
		} else if (tab[0]==tab[1] || tab[0]==tab[2] || tab[1]==tab[2])
		{
			if (mno>suma)
			{
				printf ("Mozna utworzyc trojkat rownoramienny rozwartokatny\n");
			} else 
			{
				if (mno==suma)
				{
				printf ("Mozna utworzyc trojkat rownoramienny prostokatny\n");	
				} else 
				{
					if(mno<suma)
					{
					printf ("Mozna utworzyc trojkat rownoramienny ostrokatny\n");	
					}
				}
			}
		} else
		{
			if (mno>suma)
			{
				printf ("Mozna utworzyc trojkat rozwartokatny\n");
			} else 
			{
				if (mno==suma)
				{
				printf ("Mozna utworzyc trojkat prostokatny\n");	
				} else 
				{
					if(mno<suma)
					{
					printf ("Mozna utworzyc trojkat ostrokatny\n");	
					}
				}
			}
		}
	} else printf("Z podanych odcinkow nie mozna utworzyc trojkata\n");
	
}

void zadanie4()
{
	float max1, min1, n;
	printf ("Podaj minimalny promien: ");
	scanf ("%f", &min1);
	printf ("Podaj maksymalny promien: ");
	scanf ("%f", &max1);
	printf ("Podaj liczbe wierszy: ");
	scanf ("%f", &n);
	
	printf ("=========================================\n");
	printf ("| Lp | promien | obwod kola | pole kola |\n");
	printf ("=========================================\n");
	
	float skok=(max1-min1)/(n-1);
	float obwod, pole;
	float promien = min1;
	for(int i=0; i<n; i++)
	{
		obwod = 2*M_PI*promien;
		pole= M_PI*promien*promien;
		printf ("| %2d | %7.2f | %10.2f | %9.2f |\n", (i+1),promien, obwod, pole );
		promien=promien+skok;
		printf ("=========================================\n");
	}
	
}

int main()
{
	printf ("Autor: Igor Wlodarczyk PN/P 13:15\n");
	printf ("\n");
	printf ("Zadanie 1 \n");
zadanie1();	
	printf ("\n");
	printf ("Zadanie 2 \n");
zadanie2();	
	printf ("\n");
	printf ("Zadanie 3 \n");
zadanie3();	
	printf ("\n");
	printf ("Zadanie 4 \n");
zadanie4();	
}