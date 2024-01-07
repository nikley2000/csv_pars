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
						temp.pop_back();
						table_mx[r][c] = temp;
					}
					
					
				}
				
				unused = "";
			}
				
		}
			

		//table_mx[0][0] = "sdaasd";

		unused = "";
		std::cout << "row - " << rowCount <<
			"\ncolumn - " << columnCount << "\n" << std::endl;

	
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

std::string** MyCSV::CSV::getTablePtr() const
{
	return table_mx;
}

std::string& MyCSV::CSV::operator() (const int index1, const int index2)
{
	return table_mx[index1][index2];
}

size_t  MyCSV::CSV::getRow() const
{
	return rowCount;
}
 
size_t MyCSV::CSV::getColumn() const
{
	return columnCount;
}


std::ostream& operator << (std::ostream& stream, const MyCSV::CSV& csv)
{

	for (size_t r = 0; r < csv.getRow(); r++)
	{
		for (size_t c = 0; c < csv.getColumn(); c++)
		{
			if (c < csv.getColumn())
			{
				stream << csv.getTablePtr()[r][c];
				for (size_t i = csv.getTablePtr()[r][c].length(); i < 12; i++)
				{
					stream << ' ';
				}
			}
			/*else
			{
				std::cout << csv.getTablePtr()[r][c];
			}*/

		}

		stream << "\n";

	}
	return stream;
}