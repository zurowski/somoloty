#include "PCH.h"
#include <timetable.h>

timetable::timetable(std::string label, int departure, int delay)
	:mlabel(label), mdeparture(departure), mdelay(delay)
{
	std::cout << "Timetable destructor called" << std::endl;
}

bool timetable::timecomp(int aktczas)
{
	if (getdep() == aktczas) return true;
	else return false;
}

std::ostream & operator<<(std::ostream & out, const timetable & obj)
{
	out << obj.mlabel << " | " << obj.mdeparture << " | " << obj.mdelay << std::endl;
	return out;
}
