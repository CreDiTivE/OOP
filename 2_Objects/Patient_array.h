#pragma once 
#include "Patient.h"

class Patient_array
{
private:
	int numOfPatients;
	Patient **patients;
public:
	Patient_array();
	Patient_array(int);
	~Patient_array();

	void display();
	void findDiagnosis(string _diagnosis);
	void findMedicalCardNumber(int start, int end);
	void findSurnameFirstLetter(string letter);
};