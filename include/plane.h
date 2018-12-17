#ifndef PLANE_H
#define PLANE_H


class plane {
private:
	double mspeed, mheight;
	int mtime;
	std::string mlabel;
public:
	plane(std::string label, double height, double speed, int time);
	~plane() {//std::cout << "Plane destructor called" << std::endl;
	}
	friend std::ostream& operator <<(std::ostream& out, const plane& obj);
	void incrementtime();
	void decrementtime();
	bool const checktime();
	bool checkifarrived();

	std::string const getlabel() { return mlabel; }
	int const gettime() { return mtime; }
	double const getspeed() { return mspeed; }
	double const getheight() { return mheight; }
};

#endif