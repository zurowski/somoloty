#include "PCH.h"
#include "plane.h"
#include "airfield.h"
#include "timetable.h"
#include <new>
using namespace std;
int main()
{
	//plane samolot1("sam1",300,18000,300,20,20);

	//std::cout << samolot1;
	timetable sam1("sam1", 10, 0);
	cout << sam1;
	

	for (int aktczas = 0; aktczas < 24; aktczas++)
	{
		cout << "aktczas: " << aktczas << endl;
		if (sam1.timecomp(aktczas))
		{
			cout << aktczas << ": odlot" << endl;
			//plane* plane1 = new plane(sam1.getlabel(), 300, 18000, 300, 20, 20);
			plane* plane1 = new plane("plane1", 300, 18000, 300, 20, 20);
			//cout << plane1;
			//delete plane1;
			cout << "\nkoniec ifa\n";
		}
		cout << "\npo ifie\n";
		delete plane1;
	}
	cout << "po forze\n";
	delete plane1;

	
	return 0;
}