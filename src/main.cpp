#include "PCH.h"
#include "plane.h"
#include "timetable.h"
#include "helpers.h"

using namespace std;

int main()
{
	// wektory wska�nik�w do obiekt�w
	vector<timetable*> departures; // do samolot�w przed odlotem
	vector<plane*> arrivals; // do samolot�w przylatuj�cych
	vector<plane*> planes; // do samolot�w po odlocie 

	try {
		departures.push_back(new timetable("sam0", 5, 2));
		departures.push_back(new timetable("sam1", 5, 2));
		departures.push_back(new timetable("sam2", 5, 2));
		departures.push_back(new timetable("sam3", 5, 2));
		departures.push_back(new timetable("sam4", 5, 2));
		departures.push_back(new timetable("sam5", 5, 6));

		
		settimetable(departures); 

		for (int aktczas = 0; aktczas < 24; aktczas++) //dzien 
		{
			cout << "\n\nAktualny czas: " << aktczas << endl;
			showtimetable(departures);
			showtimetable(arrivals);

			godzina(aktczas, departures, arrivals,planes);
			system("CLS");
		}
	}
	catch (char const* a)
	{
		cerr << a;

	}
	return 0;
}