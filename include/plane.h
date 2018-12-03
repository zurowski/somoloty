#ifndef PLANE_H
#define PLANE_H


class plane {
private:
	double mspeed, mheight, mheading;
	int mx, my;
	std::string mlabel;
public:
	plane(std::string label, double speed, double height, double heading, int x, int y);
	~plane() {std::cout << "Plane destructor called" << std::endl;}
	friend std::ostream& operator <<(std::ostream& out, const plane& obj);

};

#endif