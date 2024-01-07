#include "CSV.h"



MyCSV::CSV::CSV(std::string path)
{
	
	fin.open(path, std::ifstream::binary);
	if (fin.is_open())
	{

		std::string unused;
		bool temp = true;
		while (std::getline(fin, unused) && unused != "\0")
		{
			rowCount++;
			if (temp)
			{
				columnCount++;
			}
			for (size_t i = 0; i < unused.length(); i++)
			{

				if (unused[i] == ',' && temp)
				{
					columnCount++;
				}
			}

			temp = false;
		}

		table_mx = new std::string *[rowCount];
		for (size_t i = 0; i < rowCount; i++)
		{
			table_mx[i] = new std::string[columnCount];
		}

		fin.clear();
		fin.seekg(0);
		unused = "";
		for (size_t r = 0; r < rowCount; r++)
		{
			if (columnCount <= 1)
			{
				for (size_t c = 0; c < columnCount; c++)
				{

					fin >> unused;
					std::cout << unused << std::endl;
					table_mx[r][c] = unused;
					unused = "";
				}
			}
			else
			{
				std::getline(fin, unused);
				for (size_t c = 0; c < columnCount; c++)
				{
					std::string temp = "";
					if (c <columnCount - 1)
					{
						for (size_t i = 0; i < unused.find_first_of(','); i++)
						{
							temp += unused[i];

						}
						unused = &unused[unused.find_first_of(',')+1];

						table_mx[r][c] = temp;
					}
					else

					{
						for (size_t i = 0; i < unused.length(); i++)
						{
							temp += unused[i];

						}

						table_mx[r][c] = temp;
					}
					
					
				}
				
				unused = "";
			}
				
		}
			

		//table_mx[0][0] = "sdaasd";

		unused = "";
		std::cout << "row - " << rowCount <<
			"\ncolumn - " << columnCount << std::endl;


		for (size_t r = 0; r < rowCount; r++)
		{
			for (size_t c = 0; c < columnCount; c++)
			{
				if (c < columnCount - 1)
				{
					std::cout << table_mx[r][c] << ", ";
				}
				else
				{
					std::cout << table_mx[r][c];
				}
				
			}
			
			std::cout << std::endl;
		}
	
	}
	else
	{
		std::cout << "failed!";
	}
}

MyCSV::CSV::~CSV()
{
	fin.close();
	delete table_mx;
}
