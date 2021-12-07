/*
Autor: Igor Wlodarczyk
Grupa: PN/P 13:15
Temat: Laboratorium 4 zadanie 1a
Data: 07.12.2021
*/

#include <stdio.h>
#include <iostream>
using namespace std;

void Czytaj_Rownanie(float &a, float &b, float &c);
// funkcja wczytuje wspolczynniki jednego rownania a*x+b*y=c
void Wypisz_Rozwiazanie(int N, float x, float y);
// funkcja wypisuje rozwiazanie ukladu rownan lub inny komunikat
float Oblicz_Wyznacznik(float p1, float p2, float p3, float p4);
// funkcja oblicza wyznacznik
int Oblicz_Rozwiazanie(float a1, float b1, float c1, float a2, float b2, float c2, float &x, float &y);
// funkcja oblicza rozwiazanie ukladu rownan i zwraca:
// 2 - nieskonczenie wiele rozwiazan
// 1 - jest jedno rozwiazanie
// 0 - brak rozwiazan


int main()
{
printf("Autor: Igor Wlodarczyk\n");
float a1, b1, c1;
float a2, b2, c2;
float x, y;
int N;

Czytaj_Rownanie(a1, b1, c1);
Czytaj_Rownanie(a2, b2, c2);
N = Oblicz_Rozwiazanie(a1, b1, c1, a2, b2, c2, x, y);
Wypisz_Rozwiazanie(N, x, y);

return 0;
}

void Czytaj_Rownanie(float &a, float &b, float &c)
{
	printf("Podaj wspolczynniki a, b, c rownania\n");
	scanf("%f %f %f", &a, &b, &c);
}

float Oblicz_Wyznacznik(float p1, float p2, float p3, float p4)
{
	return p1 * p4 - p2 * p3;
}

int Oblicz_Rozwiazanie(float a1, float b1, float c1, float a2, float b2, float c2, float &x, float &y)
{
	float w, wx, wy;
	w = Oblicz_Wyznacznik(a1, b1, a2, b2);
	wx = Oblicz_Wyznacznik(c1, b1, c2, b2);
	wy = Oblicz_Wyznacznik(a1, c1, a2, c2);
	
	if(w!=0)
	{
		x = wx / w;
		y = wy / w;
		return 1;
	} else if(w==0 && wx == 0 && wy == 0)
	{
		return 2;
	} else return 0;
}

void Wypisz_Rozwiazanie(int N, float x, float y)
{
	switch(N)
	{
		case 0:
			printf("Brak rozwiazan (rownanie sprzeczne)\n");
			break;
		case 1:
			printf("Rozwiazania ukladu to:\nx = %.2f\ny = %.2f\n", x, y);
			break;
		case 2:
			printf("Nieskonczenie wiele rozwiazan\n");
	}
}
