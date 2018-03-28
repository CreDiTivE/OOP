#pragma once 
#include <iostream>
#include <string>
using namespace std;

class Patient
{
private:
	string name;
	string surname;
	string lastname;
	string address;
	int   medicalCardNumber;
	string diagnosis;

public:
	void  set_name(string);
	const string get_name() const;

	void  set_surname(string);
	const string get_surname() const;

	void  set_lastname(string);
	const string get_lastname() const;

	void  set_address(string);
	const string get_address() const;

	void  set_medicalCardNumber(int medicalCardNumber);
	int	  get_medicalCardNumber() const;

	void set_diagnosis(string);
	const string get_diagnosis() const;

	void display();

	Patient();
	Patient(string, string, string, string, int, string);
	~Patient();
};
