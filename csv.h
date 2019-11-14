//github.com/KevinAS28
//CSV parser v 0.2
//parsing csv format from file name or string

//CSV class:

#ifndef __csv
#define __csv 
#include <string> //cpp standard library
#include <vector> //cpp standard library
#include "strtool.h" 
#include <map> //cpp standard library


typedef std::vector<std::string> vstr;
typedef std::vector<vstr> vvstr;
typedef std::map<std::string, std::string> mapss;
typedef std::vector<mapss> DataMap;

class CSV;
typedef void (CSV::*readerFunc)(std::string, std::string, std::string);


class CSV{
public:
	//data stored will be here. get your data here after parsing corresponding your parser type.
	vvstr vector_data = vvstr(); //vector
	DataMap map_data = DataMap(); //map

	//if you using map parser, here is the column names
	vstr column_names = vstr();

	//configuration
	// int pass_error = 1;

	std::map<std::string, readerFunc> readerMapper = std::map<std::string, readerFunc>();
	FILE * csv_file;
	std::string column_splitter = ",";
	std::string row_splitter = "\n";

	//default of parser type
	std::string type = "v";
	
	
	CSV(){
		//initialize the reader map;
		this->readerMapper["v"] = &CSV::vectorReader; //vector
		this->readerMapper["m"] = &CSV::mapReader; //map
	}

	CSV(std::string data):CSV(){
		std::string type=this->type, row_splitter=this->row_splitter, column_splitter=this->column_splitter;
		this->reader(data, type, row_splitter, column_splitter);
	}
	CSV(std::string data, std::string type):CSV(){
		row_splitter=this->row_splitter, column_splitter=this->column_splitter;
		this->reader(data, type, row_splitter, column_splitter);
	}		
	CSV(std::string data, std::string type, std::string row_splitter,std::string column_splitter):CSV(){
		this->reader(data, type, row_splitter, column_splitter);
	}


	CSV(FILE * the_file):CSV(){
		std::string type=this->type, row_splitter=this->row_splitter, column_splitter=this->column_splitter, data = this->readFile(the_file);
		this->reader(data, type, row_splitter, column_splitter);
	}
	CSV(FILE * the_file, std::string type):CSV(){
		std::string data = this->readFile(the_file), row_splitter=this->row_splitter, column_splitter=this->column_splitter;
		this->reader(data, type, row_splitter, column_splitter);
	}
	CSV(FILE * the_file, std::string type, std::string row_splitter,  std::string column_splitter):CSV(){
		std::string data = this->readFile(the_file);
		this->reader(data, type, row_splitter, column_splitter);
	}	



	std::string readFile(FILE *the_file){
		std::string data = "";
		while (true){
			int d = getc(the_file);
			if (d==EOF)break;
			data+=d;
		}		
		return data;
	}

	void reader(std::string data, std::string type, std::string row_splitter,std::string column_splitter){
		this->type = type;
		readerFunc func = (this->readerMapper[type]);
		(this->*func)(data, row_splitter, column_splitter);
	}


	void vectorReader(std::string data, std::string row_splitter ,std::string column_splitter){
		vstr line = split_str_s(data, row_splitter);
		this->column_splitter = column_splitter;
		for (std::string i : line){
			vstr dat = split_str_s(i, column_splitter);
			this->vector_data.push_back(dat);
		}
	}



	void mapReader(std::string data, std::string row_splitter, std::string column_splitter){
		vstr line = split_str_s(data, row_splitter);
		if (line.size() <= 1){
			printf("CSV() -> mapReader(): the row num data should be > 1. because the first row is column name");
		}
		this->column_splitter = column_splitter;
		vstr column = split_str_s(line[0], column_splitter);
		this->column_names = column;
		std::map<std::string, std::string> toadd;
		for (int a = 1; a < line.size(); a++){
			vstr dat = split_str_s(line[a], column_splitter);

			//check the error. 
			// if (dat.size()!=column.size()){
			// 	printf("%d %d %d\n", a, dat.size(), column.size());
			// 	if (pass_error){
			// 		continue;
			// 	}
			// }
			
			toadd = std::map<std::string, std::string>();
			for  (int b = 0; b < column.size(); b++){

				toadd[column[b]] = dat[b];
			}
			this->map_data.push_back(toadd);
		}
	}


};

#endif