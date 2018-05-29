class Patient
{
private:
	char* name;
	char* surname;
	char* lastname;
	char* address;
	int   medicalCardNumber;
	char* diagnosis;

public:
	Patient() :name(new char[1]), surname(new char[1]), lastname(new char[1]), address(new char[1]), medicalCardNumber(0), diagnosis(new char[1]) { 
		name[0] = '\0'; 
		surname[0] = '\0';
		lastname[0] = '\0';
		address[0] = '\0';
		diagnosis[0] = '\0';
	};
	Patient(char* name, char* surname, char* lastname, char* address, int medicalCardNumber, char* diagnosis);

	void  set_name(char* name);
	const char* get_name() const { return name; };

	void  set_surname(char* surname);
	const char* get_surname() const { return surname; };

	void  set_lastname(char* lastname);
	const char* get_lastname() const { return lastname; };

	void  set_address(char* address);
	const char* get_address() const { return address; };

	void  set_medicalCardNumber(int _medicalCardNumber) { medicalCardNumber = _medicalCardNumber; };
	int	  get_medicalCardNumber() const { return medicalCardNumber; };

	void set_diagnosis(char* diagnosis);
	const char* get_diagnosis() const { return diagnosis; };

	void display();

	~Patient();
};
