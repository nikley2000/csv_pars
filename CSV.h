#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

namespace MyCSV {
	class CSV
	{
	public:
		CSV(std::string path);
		~CSV();

		std::string** getTablePtr() const;
		std::string& operator() (const int index1,const int index2);
		size_t getRow() const;
		size_t getColumn() const;
	private:
		std::ifstream fin;
		short rowCount = 0;
		short columnCount = 0;
		std::string **table_mx;
		
	};

	
	
}



std::ostream& operator << (std::ostream& stream, const MyCSV::CSV& csv);
