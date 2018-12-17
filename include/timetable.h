#ifndef TIMETABLE_H
#define TIMETABLE_H

class timetable {
private:
	std::string mlabel;
	int mdeparture, mdelay;

public:
	timetable(std::string label, int departure, int delay);
	~timetable() { //std::cout << "Timetable destructor called" << std::endl; 
	}
	friend std::ostream& operator <<(std::ostream& out, const timetable& obj);
	friend bool operator ==(const timetable& obj1, const timetable& obj2);
	friend bool operator <(const timetable& obj1, const timetable& obj2);
	bool timecomp(int aktczas);
	
	
	int const getdep() { return mdeparture; }
	int const getdeley() { return mdelay; }
	std::string const getlabel() { return mlabel; }
	
	void incrementdelay() { mdelay++; }
};
	

#endif