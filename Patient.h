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
	Patient(char* name, char* surname, char* lastname, char* address, int medicalCardNumber, char* diagnosis);

	void  set_name(char* name);
	const char* get_name() const;

	void  set_surname(char* surname);
	const char* get_surname() const;

	void  set_lastname(char* lastname);
	const char* get_lastname() const;

	void  set_address(char* address);
	const char* get_address() const;

	void  set_medicalCardNumber(int medicalCardNumber);
	int	  get_medicalCardNumber() const;

	void set_diagnosis(char* diagnosis);
	const char* get_diagnosis() const;

	void display();

	~Patient();
};
