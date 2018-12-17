#include "PCH.h"
#include <timetable.h>
#include <plane.h>

timetable::timetable(std::string label, int departure, int delay)
	:mlabel(label), mdeparture(departure), mdelay(delay)
{
	if (departure < 0) throw "Departure time is negative! \n";	
	if (delay < 0) throw "Delay time is negative! \n";
	//std::cout << "Timetable constructor called" << std::endl;
}

bool timetable::timecomp(int aktczas)						//sprawdzanie czy czas na odlot
{
	if ((getdep() + getdeley()) == aktczas) return true;
	else return false;
}

std::ostream & operator<<(std::ostream & out, const timetable & obj) // wypisywanie danych o samolocie, chyba nieuzywane 
{
	out << obj.mlabel << " | " << obj.mdeparture << " | " << obj.mdelay << std::endl;
	return out;
}

bool operator==(const timetable & obj1, const timetable & obj2)		// operator porownania, uzywane do ustawiania tabeli odlotow
{
	return ((obj1.mdeparture + obj1.mdelay) == (obj2.mdeparture + obj2.mdelay));
}

bool operator <(const timetable& obj1, const timetable& obj2)	// operator mniejszosci, uzywane do sortowania tablicy odlotow
{
	return ((obj1.mdeparture + obj1.mdelay) < (obj2.mdeparture + obj2.mdelay));
}


