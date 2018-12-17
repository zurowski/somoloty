#ifndef HELPERS_H
#define HELPERS_H

void godzina(int &aktczas, std::vector<timetable*>& departures, std::vector<plane*>& arrivals, std::vector<plane*>& planes);


void settimetable(std::vector<timetable*>& wektor);
void const showtimetable(std::vector<timetable*>& dep);

void const showtimetable(const std::vector<plane*>& arr);
void newplane(std::vector<plane*>& wektor, int aktczas);

#endif