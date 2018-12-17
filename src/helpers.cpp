#include "PCH.h"
#include "plane.h"
#include "timetable.h"
#include "helpers.h"

void godzina(int &aktczas, std::vector<timetable*>& departures, std::vector<plane*>& arrivals, std::vector<plane*>& planes)
{														// symuluje jedna godzinê z dnia 
	for (int c = 0; c < arrivals.size(); c++)//samoloty przylatujace
	{
		arrivals[c]->decrementtime();					// wszystkie samoloty sie zblizaja 
		std::cout << *arrivals[c] << std::endl;
		if (arrivals[c]->gettime() == aktczas) {		// jesli czas przybycia == aktczas
			std::cout << arrivals[c]->getlabel() << ": Arrived! \n";
			delete arrivals[c];							// usun dany obiekt
			arrivals.erase(arrivals.begin() + 0);		//przeczysc wektor
			c--;										// bo teraz wektor jest krótszy i obiekty przeskoczy³y o jeden w lewo
		}
	}

	for (int b = 0; b < planes.size(); b++) //samoloty po odlocie
	{
		planes[b]->incrementtime();						//samoloty sie oddalaja
		std::cout << *planes[b] << std::endl;
		if (planes[b]->checktime()) {					//jesli sa juz daleko ( czas == 3 )
			std::cout << planes[b]->getlabel() << ": Radar contact lost \n";
			delete planes[b];
			planes.erase(planes.begin() + b);
			b--;
		}
	}

	int d = 0;
	for (auto& a : departures) //odloty
	{
		if (a->timecomp(aktczas))								// jesli godzina odlotu == akt czas
		{
			std::cout << a->getlabel() << " took off!" << std::endl;
			planes.push_back(new plane(a->getlabel(), 0, 0, 0)); // stworz obiekt 'lec¹cy' ze starym labelem i domyslnymi wart. pocz.
			delete a;											// usun obiekt timetable	
			departures.erase(departures.begin() + d);
		}
		d++;
	}
	newplane(arrivals, aktczas);								//sprawdz czy przylatuje nowy samolot (wpisywane recznie)
}


bool compare(timetable* obj1, timetable* obj2) { return (*obj1 < *obj2); }	// funkcja pomocnicza do sortowania, mowi jak porownywac, '<' przeciazony

void settimetable(std::vector<timetable*>& wektor)				//przygotowanie tablicy odlotow z wpisanych danych
{
	std::sort(wektor.begin(), wektor.end(), compare);			//sortowanie od najmniejszego czasu odlotu (dep + delay)
	
	for (int i = 0; i < wektor.size() - 1; i++)
	{
		for (int a = i+1; a < wektor.size(); a++)
		{
			if (*wektor[i] == *wektor[a])		// jesli czas odlotu dówch jest taki sam
			{
				wektor[a]->incrementdelay();					// to dodaj +1 delay tego drugiego
			}
		}
	}
}

void const showtimetable(std::vector<timetable*>& dep)		// pokaz tablice odlotow
{
	bool opoznienia = false;								//jesli jest jakies opoznienie to wypisz ze sorry
	std::cout << std::left << "\nTIMETABLE: \n\nDEPARTURES:\n";
	std::cout << std::setw(10) << "PLANE ID: " << std::setw(10) << "| DEPARTURE: " << std::setw(12) << "| DELAY: " << std::endl;
	for (auto& b : dep)
	{
		if (b->getdeley() > 0) opoznienia = true;
		std::cout << std::setw(10) << b->getlabel() << "| " << std::setw(2) << std::right << b->getdep()
			<< std::setw(9) << std::left << ":00" << "| " << b->getdeley() << ":00" << std::endl;
	}
	if (dep.size() == 0) std::cout << "\nNO DEPARTURES PLANNED\n";
	if (opoznienia) std::cout << "\nWE APOLOGIZE FOR THE DELAYS\n";
}


void const showtimetable(const std::vector<plane*>& arr)	// pokaz tablice przylotow
{

	std::cout << "\nARRIVALS:\n";
	std::cout << std::setw(10) << "PLANE ID: " << std::setw(10) << "| ARRIVAL: " << std::setw(12) << "| DELAY: " << std::endl;
	for (auto& c : arr)
	{
		std::cout << std::setw(10) << c->getlabel() << "| " << std::setw(2) << std::right << c->gettime()
			<< std::setw(7) << std::left << ":00" << "| " << "00:00" << std::endl;
	}
	if (arr.size() == 0) std::cout << "\nNO ARRIVALS PLANNED\n\n";
}

void newplane(std::vector<plane*>& wektor, int aktczas)		//nowy samolot przylatujacy
{
	char znak;
	std::string tekst{ "" };
	std::cout << "Any new arrivals?";
	std::cin >> znak;
	if (znak == 'y')									// jesli wpiszesz 'y' yo nowy przylot
	{
		std::cout << "\nArriving plane's ID: ";			//dodaj label
		std::cin >> tekst;
		wektor.push_back(new plane(tekst, 15000, 600, aktczas + 3));	// stworz obiekt z labelem + domyslne wartosci
	}
}
