#define _CRT_SECURE_NO_WARNINGS
#include "List.h"

typedef _iterator<Bus> iterator;

// загрузки из csv
bool LoadFromCSV(const char *filename, List<Bus> &base) {
	FILE* file;
	if ((file = fopen(filename, "r")) == NULL) {
		return false;
	}
	char str[127];
	while (fgets(str, 127, file)) {
		Bus bus_obj;
		bus_obj.loadFromCSV(str, base);
	}
	fclose(file);
	return true;
}

void main()
{
	setlocale(LC_ALL, "rus");
	Bus bus1("Vitaliy", "AE1245VI", "24");
	Bus bus2("Dmitriy", "AC8924KI", "1");
	Bus bus3("Sergey", "AR0000AM", "99");
	List<Bus> lst1;
	List<Bus> lst2;
	List<Bus>::iterator it1 = lst1.begin();
	List<Bus>::iterator it2 = lst1.begin();
	LoadFromCSV("data.csv", lst1);

	lst1.Print();
	printf("Размер списка = %d \t", lst1.size());
	printf("\nУдаление 'Vitaliy'\n\n");
	lst1.remove(bus1);
	lst1.Print();
	printf("Удаление с начала списка\n\n");
	lst1.pop_front();
	lst1.Print();
	printf("Размер списка = %d \t", lst1.size());
	printf("\nsplice 'Dmitriy' во второй список\n\n");
	it1 = lst1.find(bus2);
	lst1.splice(it1, lst2);
	lst2.Print();
	printf("Размер второго списка = %d \t", lst2.size());
	cout << endl;

	system("pause");
}