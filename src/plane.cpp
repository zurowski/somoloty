#include "PCH.h"
#include "plane.h"
#include "timetable.h"

plane::plane(std::string label, double height, double speed, int time)
	:mlabel(label), mspeed(speed), mheight(height), mtime(time)
{
	//std::cout << "Plane constructor called" << std::endl;
}

void plane::incrementtime()				//samoloty po odlocie sie oddalaja ( przyspiesza i sie wznosi
{
	mheight += 5000;
	mspeed += 200;
	++mtime;
}

void plane::decrementtime()				// samoloty przylatajace sie znizaja i zwalniaja
{
	mheight -= 5000;
	mspeed -= 200;
}
bool const plane::checktime()			//jesli samolot po starcie sie juz dosc oddalil
{
	if (mtime == 3) return true;
	else return false;
}

bool plane::checkifarrived() // chyba do wywalenia
{
	if (mtime == 0) return true;
	else return false;
}

std::ostream & operator<<(std::ostream & out, const plane & obj)	// operator wypisywania samolotow w powietrzu
{
	out << "\nRADAR CONTACT:\nPlane: " << obj.mlabel << "\nHeight: " << obj.mheight << " m \nSpeed: " << obj.mspeed
		<< " km/h  \n"; //Time in the air: " << obj.mtime<< std::endl;
	return out;
}