#include "Patient.h"

#include <iostream>
using namespace std;

void main() 
{
	setlocale(LC_ALL, "rus");
	char* name = "Àëåêñàíäð";
	char* surname = "Åðøîâ";
	char* lastname = "Èãîðåâè÷";
	char* address = "Êèåâ, Óêðàèíà";
	int medicalCardNumber = 19;
	char* diagnosis = "Ïðîãðàììèðîâàíèå 1 ñòàäèè";

	Patient obj(name, surname, lastname, address, medicalCardNumber, diagnosis);

	obj.display();
	
	char* new_name = "Òèìîôåé";
	char* new_surname = "Àë¸øèí";
	char* new_lastname = "Îëåãîâè÷";
	char* new_address = "Ïðàãà, ×åõèÿ";
	int new_medicalCardNumber = 27;
	char* new_diagnosis = "Ïðîãðàììèðîâàíèå 2 ñòàäèè";

	obj.set_name(new_name);
	obj.set_surname(new_surname);
	obj.set_lastname(new_lastname);
	obj.set_address(new_address);
	obj.set_medicalCardNumber(new_medicalCardNumber);
	obj.set_diagnosis(new_diagnosis);

	cout << endl;
	obj.display();
	
	system("Pause");
}
