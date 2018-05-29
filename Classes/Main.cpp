#include "Patient.h"

#include <iostream>
using namespace std;

void main() 
{
	setlocale(LC_ALL, "rus");

	Patient obj("Александр", "Ершов", "Игоревич", "Киев, Украина", 2, "Программирование 3 стадии");

	obj.display();

	obj.set_name("Тимофей");
	obj.set_surname("Алёшин");
	obj.set_lastname("Олегович");
	obj.set_address("Прага, Чехия");
	obj.set_medicalCardNumber(27);
	obj.set_diagnosis("Программирование n+1 стадии");

	cout << endl;
	obj.display();
	
	system("Pause");
}