#include "Patient_array.h"
#include <ctime>

void main() 
{
	setlocale(LC_ALL,"Russian");
	srand(time(NULL));
	Patient_array patients(6);
	int choise;
	cout << "1 - �������� � ��������� <��������>" << endl
		 << "2 - �������� ����� ���. ����� ������� ����� � ��������� 2 - 5" << endl
		 << "3 - �������� ������� ������� ���������� � ����� <�>:" << endl;
	cin >> choise;
	if (choise == 1)
		patients.findDiagnosis("��������");
	else if (choise == 2)
		patients.findMedicalCardNumber(2, 5);
	else if (choise == 3)
		patients.findSurnameFirstLetter("�");
	else
		cout << "������ �����" << endl;
	system("Pause");
}