/*
Autor: Igor Wlodarczyk
Grupa: PN/P 13:15
Temat: Laboratorium 3
Data: 16.11.2021
*/

#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <cstdlib>

#define ROZMIAR 5

float tab[ROZMIAR];

void wczytywanie()
{
	int i;
	for(i=0; i<ROZMIAR; i++)
	{
		printf("Tab[%d] = ", i);
		scanf("%f", &tab[i]);
	}
}

void wyswietlanie()
{
	int i;
	printf("Tab = [  ");
	for(i=0; i<ROZMIAR; i++)
	{
	printf("%.1f  ", tab[i]);	
		
	}
	printf("]\n");
}

void statystyki()
{	
	int i;
	int i_dodatnie=0, i_ujemne=0;
	float suma_dodatnie=0, suma_ujemne=0;
	float srednia_dodatnie, srednia_ujemne;
	
	for (i=0; i<ROZMIAR; i++)
	{
		if(tab[i]>0)
		{
			i_dodatnie++;
			suma_dodatnie+=tab[i];
		} else if(tab[i]<0)
		{
			i_ujemne++;
			suma_ujemne+=tab[i];
		}
	}
	
	printf("Ilosc liczb dodatnich: %d\n", i_dodatnie);
	printf("Ilosc liczb ujemnych: %d\n", i_ujemne);
	printf("Suma liczb dodatnich: %.2f\n", suma_dodatnie);
	printf("Suma liczb ujemnych: %.2f\n", suma_ujemne);
	
	if(i_dodatnie>0)
	{
		srednia_dodatnie=suma_dodatnie/i_dodatnie;
		printf("Srednia liczb dodatnich: %.2f\n", srednia_dodatnie);
	} else printf("Srednia liczb dodatnich: brak liczb dodatnich w tablicy\n");
	
	if(i_ujemne>0)
	{
		srednia_ujemne=suma_ujemne/i_ujemne;
		printf("Srednia liczb ujemnych: %.2f\n", srednia_ujemne);
	} else printf("Srednia liczb ujemnych: brak liczb ujemnych w tablicy\n");
}

void sortowanie()
{
	int i, j;
	float a,b;
	for(i=0; i<ROZMIAR; i++)
	{
		for(j=1; j<ROZMIAR-i; j++)
		{
			if(tab[j-1]>tab[j])
			{
				a = tab[j-1];
				b = tab[j];
				tab[j-1] = b;
				tab[j] = a;
			}
		}
	}
	printf("Tablica zostala posortowana\n");
}

void uporzadkowanie()
{
	int i;
	bool jednakowa_wartosc = true;
	bool uporzadkowane_rosnaco = true;
	bool uporzadkowane_niemalejaco = true;
	bool uporzadkowane_nierosnaco = true;
	bool uporzadkowane_malejaco = true;
	for (i=1; i<ROZMIAR; i++)
	{
		if(tab[i-1]!=tab[i])
		{
			jednakowa_wartosc = false;
		}
		
		if(tab[i-1]>=tab[i])
		{
			uporzadkowane_rosnaco = false;
		}
		
		if(tab[i-1]>tab[i])
		{
			uporzadkowane_niemalejaco = false;
		}
		
		if(tab[i-1]<tab[i])
		{
			uporzadkowane_nierosnaco = false;
		}
		
		if(tab[i-1]<=tab[i])
		{
			uporzadkowane_malejaco = false;
		}
	}
	
	if(jednakowa_wartosc == false && uporzadkowane_rosnaco==false && uporzadkowane_niemalejaco==false && uporzadkowane_nierosnaco==false && uporzadkowane_malejaco==false)
	{
		printf("Elementy tablicy sa nieuporzadkowane\n");
	}
	
	if(jednakowa_wartosc==true)
	{
		printf("Wszystkie elementy tablicy maja jednakowa wartosc\n");
	}
	
	if(uporzadkowane_rosnaco==true)
	{
		printf("Elementy tablicy sa uporzadkowane rosnaco\n");
	}
	
	if(uporzadkowane_niemalejaco==true)
	{
		printf("Elementy tablicy sa uporzadkowane niemalejaco\n");
	}
	
	if(uporzadkowane_nierosnaco==true)
	{
		printf("Elementy tablicy sa uporzadkowane nierosnaco\n");
	}
	
	if(uporzadkowane_malejaco==true)
	{
		printf("Elementy tablicy sa uporzadkowane malejaco\n");
	}
}

void losowe()
{
	srand(time(NULL));
	int min, max;
	int i;
	printf("Podaj zakres losowanych liczb\n");
	printf("min: ");
	scanf("%d", &min);
	printf("max: ");
	scanf("%d", &max);
	for (i=0; i<ROZMIAR; i++)
	{
		tab[i]=min+(max-min)*rand()/((double)RAND_MAX);
	}
	
	printf("Tablica zostala wypelniona losowymi liczbami\n");
}
void menu_wyswietl()
{
	printf("Menu \n");
	printf("1. Wczytywanie elementow tablicy\n");
	printf("2. Wypisywanie elementow tablicy\n");
	printf("3. Liczby dodatnie i ujemne\n");
	printf("4. Uporzadkowanie elementow tablicy\n");
	printf("5. Wypelnienie tablicy liczbami losowymi\n");
	printf("6. Sortowanie elementow tablicy\n");
	printf("7. Koniec\n");
	printf("8. Wyswietl menu\n");
	printf("--------------------------------------------\n");
}

int main()
{
		printf("Autor: Igor Wlodarczyk\n");
int n;
bool menu = true;
menu_wyswietl();
while (menu == true)
{
	n=getch();
	switch(n)
	{
		case '1':
			wczytywanie();
				printf("--------------------------------------------\n");
			break;
		case '2':
			wyswietlanie();
				printf("--------------------------------------------\n");
			break;
		case '3':
			statystyki();
				printf("--------------------------------------------\n");
			break;
		case '4':
			uporzadkowanie();
				printf("--------------------------------------------\n");
			break;
		case '5':
			losowe();
				printf("--------------------------------------------\n");
			break;
		case '6':
			sortowanie();
				printf("--------------------------------------------\n");
			break;
		case '7':
			menu=false;
			break;
		case '8':
			menu_wyswietl();
			break;
				
	}
}




}

