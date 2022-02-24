/*
Autor: Igor Wlodarczyk
Grupa: PN/P 13:15
Temat: Laboratorium 6
Data: 28.01.2022
*/
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <string.h>

using namespace std;
struct Towar
{
	char nazwa[20];
	float cena;
	int ilosc;	
};

void nowa_tablica(int &Rozmiar, Towar **Tab);
void wyswietl(int Rozmiar, Towar **Tab);
void dodaj_towar(int &Rozmiar, Towar **Tab);
void usun_towar(int &Rozmiar, Towar **Tab);
void usun_tablice(int &Rozmiar, Towar **Tab);

int main()
{
	int Rozmiar = 0;
	Towar* Tab = NULL;
	
	bool menu = true;
	char z;
	while(menu)
	{
		printf("Autor: Igor Wlodarczyk\n");
		printf("Menu\n");
		printf("1. Utworz tablice\n");
		printf("2. Wyswietl zawartosc\n");
		printf("3. Dodaj towar\n");
		printf("4. Usun towar\n");
		printf("5. Usun tablice\n");
		printf("6. Koniec\n");
		z = getch();
		switch(z)
		{
			case '1':
				nowa_tablica(Rozmiar, &Tab);
				break;
			case '2':
				wyswietl(Rozmiar, &Tab);
				break;
			case '3':
				dodaj_towar(Rozmiar, &Tab);
				break;
			case '4':
				usun_towar(Rozmiar, &Tab);
				break;
			case '5':
				usun_tablice(Rozmiar, &Tab);
				break;
			case '6':
				menu = false;
				break;
				
		}
				if(z>='1' && z<='6')
		{
			char znak = 0;
			printf("Wcisnij 'p', aby przejsc dalej\n");
			while(znak!='p')
			{
				znak = getch();
			}
		}
		
		system("cls");
	}
}

void nowa_tablica(int &Rozmiar, Towar **Tab)
{
	if(*Tab!=NULL)
	{
		free(*Tab);
		printf("Poprzednia tablica zostala usunieta\n");
		Rozmiar = 0;
	}
	int n=0;
	printf("Ile towarow chcesz wprowadzic do tablicy? \n");
	scanf("%d", &n);
	fflush(stdin);
	*Tab = (Towar*)malloc(n*sizeof(Towar));
	for(int i=0; i<n; i++)
	{
		printf("Towar nr: %d\n", i+1);
		Rozmiar++;
		printf("Nazwa: ");
		cin.getline((*Tab)[i].nazwa, 20);
		fflush(stdin);
		printf("Cena: ");
		scanf("%f", &((*Tab)[i].cena));
		fflush(stdin);
		printf("Ilosc: ");
		scanf("%d", &((*Tab)[i].ilosc));
		fflush(stdin);
	}
}

void wyswietl(int Rozmiar, Towar **Tab)
{
	if(*Tab==NULL)
	{
		printf("Nie utworzono zadnej tablicy\n");
	}else
	{
		printf("---------------------------------------------------\n");
		printf("|Ilosc towarow: %2d                                |\n", Rozmiar);
		printf("---------------------------------------------------\n");
		printf("| NR  |     NAZWA TOWARU     |   CENA   |  ILOSC  |\n");
		printf("---------------------------------------------------\n");
		for(int i=0; i<Rozmiar; i++)
		{
			printf("|%4d | %20s | %8.2f | %7d |\n", i+1, (*Tab)[i].nazwa, (*Tab)[i].cena, (*Tab)[i].ilosc);
		}
		printf("---------------------------------------------------\n");
	}
	
}

void dodaj_towar(int &Rozmiar, Towar **Tab)
{
	Rozmiar++;
	*Tab = (Towar*)realloc(*Tab, Rozmiar*sizeof(Towar));
	printf("Towar nr: %d\n", Rozmiar);
	printf("Nazwa: ");
	cin.getline((*Tab)[Rozmiar-1].nazwa, 20);
	fflush(stdin);
	printf("Cena: ");	
	scanf("%f", &((*Tab)[Rozmiar-1].cena));
	fflush(stdin);
	printf("Ilosc: ");
	scanf("%d", &((*Tab)[Rozmiar-1].ilosc));
	fflush(stdin);
}
void usun_towar(int &Rozmiar, Towar **Tab)
{
	int nr;
	printf("Ktory towar chcesz usunac? Podaj nr: ");
	scanf("%d", &nr);
	fflush(stdin);
	for(int i=nr-1; i<Rozmiar-1; i++)
	{
		   strcpy((*Tab)[i].nazwa, (*Tab)[i+1].nazwa);	
		   (*Tab)[i].cena=(*Tab)[i+1].cena;	
		   (*Tab)[i].ilosc=(*Tab)[i+1].ilosc;	
	} 
	Rozmiar--;
	*Tab = (Towar*)realloc(*Tab, Rozmiar*sizeof(Towar));
	
}
void usun_tablice(int &Rozmiar, Towar **Tab)
{
	free(*Tab);
	*Tab=NULL;
	Rozmiar = 0;
	printf("Tablica zostala usunieta\n");
	
}
