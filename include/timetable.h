#ifndef TIMETABLE_H
#define TIMETABLE_H

class timetable {
private:
	std::string mlabel;
	int mdeparture, mdelay;

public:
	timetable(std::string label, int departure, int delay);
	~timetable() { std::cout << "Timetable destructor called" << std::endl; }
	friend std::ostream& operator <<(std::ostream& out, const timetable& obj);
	bool timecomp(int aktczas);

	int getdep() { return mdeparture; }
	std::string const getlabel() { return mlabel; }
};

#endif