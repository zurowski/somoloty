#include "PCH.h"
#include "plane.h"
#include "airfield.h"
#include "timetable.h"

using namespace std;

int main()
{
	vector<timetable*> samoloty;
	vector<plane*> planes;

	samoloty.push_back(new timetable("sam0", 10, 0));
	samoloty.push_back(new timetable("sam1", 15, 0));
	samoloty.push_back(new timetable("sam2", 20, 0));


	for (int aktczas = 0; aktczas < 24; aktczas++)
	{
		//cout << "aktczas: " << aktczas << endl;
		for (int i = 0; i < samoloty.size(); i++)
		{
			if (samoloty[i]->timecomp(aktczas))
			{
				cout << aktczas << ":00 odlot samolotu: " << samoloty[i]->getlabel() << endl;
				planes.push_back(new plane(samoloty[i]->getlabel(), 300, 18000, 300, 20, 20));
				delete samoloty[i];
			}
		}
	}



	for (int i = 0; i < planes.size(); i++)
	{
		cout << endl << *planes[i] ;
		delete planes[i];
	}
	
	return 0;
}