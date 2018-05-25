/* Àâòîð: Åðøîâ À.È.
* Ôàéë çàãîëîâîê êëàññà-ïîòîìêà "Ãîðîä" */

#pragma once
#include "Place.h"

struct travel
{
	int numOfAirports;     // êîëè÷åñòâî àýðîïîðòîâ
	int numOfPorts;		   // êîëè÷åñòâî ïîðòîâ
	int numOfBusStations;  // êîëè÷åñòâî àâòîáóñíûõ ñòàíöèé
	int numOfRailstations; // êîëè÷åñòâî æåëåçíîäîðîæíûõ âîêçàëîâ
};

class City:public Place
{
private:
	travel transport; // òðàíñïîðò
	string mayor;     // ìýð ãîðîäà

public:
	City();  // êîíñòðóêòîð ïî óìîë÷åíèþ
	City(string _name, double _square, int _population, travel _transport, string _mayor); // êîíñòðóêòîð ñ ïàðàìåòðàìè
	~City(); // äåñòðóêòîð

	void  set_transport(travel _transport);	 // ñåòòåð ñòðóêòóðû "òðàíñïîðò"
	const travel get_transport() const;      // ãåòòåð ñòðóêòóðû òðàíñïîðò
	void  set_mayor(string _mayor);			 // ñåòòåð ïîëÿ "ìýð"
	const string get_mayor() const;		     // ãåòòåð ïîëÿ "ìýð"

	ostream& display(ostream& os);			 // âûâîä â ïîòîê
	istream& input(istream& is);			 // ââîä â ïîòîê
	ofstream& save_to_file(ofstream& of);	 // ñîõðàíåíèå â ôàéë
	ifstream& load_from_file(ifstream & in); // çàãðóçêà èç ôàéëà

	friend ostream& operator << (ostream& os, City& city);	 // ïåðåãðóçêà îïåðàòîðà âûâîäà èç ïîòîêà íà ýêðàí
	friend istream& operator >> (istream& is, City& city);	 // ïåðåãðóçêà îïåðàòîðà ââîäà â ïîòîê
	friend ofstream& operator << (ofstream& of, City& city); // ïåðåãðóçêà îïåðàòîðà âûâîäà èç ïîòîêà â ôàéë
	friend ifstream& operator >> (ifstream& in, City& city); // ïåðåãðóçêà îïåðàòîðà ââîäà â ïîòîê èç ôàéëà
};
