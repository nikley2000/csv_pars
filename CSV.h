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

	private:
		std::ifstream fin;
		short rowCount = 0;
		short columnCount = 0;
		std::string **table_mx;
		
	};

}




