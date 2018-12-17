#include "PCH.h"
#include "plane.h"
#include "timetable.h"
#include "helpers.h"

using namespace std;

int main()
{
	// wektory wskaŸników do obiektów
	vector<timetable*> departures; // do samolotów przed odlotem
	vector<plane*> arrivals; // do samolotów przylatuj¹cych
	vector<plane*> planes; // do samolotów po odlocie 

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