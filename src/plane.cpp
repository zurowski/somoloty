#include "PCH.h"
#include "plane.h"

plane::plane(std::string label, double speed, double height, double heading, int x, int y)
	:mlabel(label), mspeed(speed), mheight(height), mheading(heading), mx(x), my(y)
{
}


std::ostream & operator<<(std::ostream & out, const plane & obj)
{
	out << "Plane: " << obj.mlabel << "\nSpeed: " << obj.mspeed << " km/h \nHeight: " << obj.mheight
		<< " m \nHeading: " << obj.mheading << std::endl;
	return out;
}
