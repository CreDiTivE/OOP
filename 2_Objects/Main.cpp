#include "Patient_array.h"
#include <ctime>

void main() 
{
	setlocale(LC_ALL,"Russian");
	srand(time(NULL));
	Patient_array patients(6);
	int choise;
	cout << "1 - пациенты с диагнозом <стоматит>" << endl
		 << "2 - пациенты номер мед. карты которых лежит в интервале 2 - 5" << endl
		 << "3 - пациенты фамилия которых начинается с буквы <К>:" << endl;
	cin >> choise;
	if (choise == 1)
		patients.findDiagnosis("стоматит");
	else if (choise == 2)
		patients.findMedicalCardNumber(2, 5);
	else if (choise == 3)
		patients.findSurnameFirstLetter("К");
	else
		cout << "Ошибка ввода" << endl;
	system("Pause");
}