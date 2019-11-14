#include <iostream>
#include "csv.h"

std::string for_vector = "i,read,this,with,vector,parser\nso,i,pull,it,from,\"csv.data_vector();\"";
std::string for_map = "the,first,row,is,column,\"when using map reader\"\ni,read,this,with,map,parser\nso,i,pull,it,from,\"csv.data_map();\"";
int main(){	
	FILE * csv_stream = fopen("house.csv", "r"); 

	//parse csv from existing string using vector parser
	std::cout << "Reading from string using vector parser: \n";
	CSV csv0 = CSV(for_vector); // vector parse is the default.
	for (int row_index = 0; row_index < csv0.vector_data.size(); row_index++){
		std::cout << row_index << ". ";
		vstr rowData = csv0.vector_data[row_index];
		for (int col_index = 0; col_index < rowData.size(); col_index++){
			std::string data = rowData[col_index];
			std::cout << data << " ";
		}
		std::cout << "\n";
	}

	//parse csv from existing string using map parser
	std::cout << "\nReading from string using map parser: \n";
	CSV csv1 = CSV(for_map, "m"); // "m" is map parser.
	vstr column_name = csv1.column_names;
	for (int row_index = 0; row_index < csv1.map_data.size(); row_index++){
		std::cout << row_index << ". ";
		mapss rowData = csv1.map_data[row_index];
		for (int col_index = 0; col_index < rowData.size(); col_index++){
			std::string data = rowData[column_name[col_index]];
			std::cout << column_name[col_index] << " : " << data << ", ";
		}
		std::cout << "\n";
	}

	//parse csv from house.csv using vector parser
	// std::cout << "\nReading from house.csv using vector parser: \n";
	// FILE * myfile = fopen("house.csv", "r");
	// CSV csv2 = CSV(myfile); // vector parse is the default.
	// for (int row_index = 0; row_index < 3; row_index++){
	// 	std::cout << row_index << ". ";
	// 	vstr rowData = csv2.vector_data[row_index];
	// 	for (int col_index = 0; col_index < rowData.size(); col_index++){
	// 		std::string data = rowData[col_index];
	// 		std::cout << data << " ";
	// 	}
	// 	std::cout << "\n";
	// }

	std::cout << "\nReading from house.csv using map parser... why you not try it with your own? :v \n";

	return 0;
}