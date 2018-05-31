#define _CRT_SECURE_NO_WARNINGS
#include "Bus.h"

Bus::Bus() {
	driver[0] = '\0';
	bus_number[0] = '\0';
	route_number[0] = '\0';
}

Bus::Bus(char* _driver, char* _bus_number, char* _route_number) {
	strcpy(driver, _driver);
	strcpy(bus_number, _bus_number);
	strcpy(route_number, _route_number);
}

void Bus::changeName(char* _driver) {
	if (_driver == NULL) return;
	strcpy(this->driver, _driver);
}

bool Bus::loadFromCSV(char* str, List<Bus> &base) {
	if (str == NULL) return false;
	sscanf(str, "%[A-z0-9];%[A-z0-9];%[A-z0-9]", &(this->driver), &(this->bus_number), &(this->route_number));
	base.push_front(*this);
	return true;
}

bool Bus::isEqual(const Bus bus) {
	if (strcmp(driver, bus.driver) == 0 && strcmp(bus_number, bus.bus_number) == 0 && strcmp(route_number, bus.route_number) == 0)
		return true;
	return false;
}

ostream& operator <<(ostream& stream, Bus &obj)
{
	stream << "" << obj.driver << "; " << obj.bus_number << "; " << obj.route_number << "\n";
	return stream;
};