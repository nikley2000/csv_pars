#include <iostream>
#include "CSV.h"
#include <string>

using namespace std;



int main()
{
	setlocale(LC_ALL, "ru");
	MyCSV::CSV csv("table.csv");
	std::cout << csv;

	return 0;
}