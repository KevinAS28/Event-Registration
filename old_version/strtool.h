//github.com/KevinAS28

#include <vector>
#include <iostream>
#include <cstdio>
#include <sstream>
typedef std::vector<std::string> vstr;


//function find_str, not using from string object
//so it can be easy to transform it to c code
int find_str(std::string str, std::string tofind, int start=0){
	for (int i=start; i < str.length(); i++)
	{
		if (str[i]==tofind[0]){
			//possibility match
			int salah = 0;
			for (int a = 0; a < tofind.length(); a++){
				if (tofind[a]!=str[i+a]){
					salah = 1;
				}
			}
			if (!salah) return i;
		}
	}
	return -1; //not found
}

bool same_str(std::string str0, std::string str1){
	if (str0.size()!=str1.size()){
		return false;
	}
	for (int i = 0; i < str0.size(); i++){
		if (str0[i]!=str1[i]){
			return false;
		}
	}
	return true;
}

std::vector<int> str_to_intvec(std::string str){
	std::vector<int> vec = std::vector<int>();
	for (char c : str){
		vec.push_back((int)c);
	}
	return vec;
}

std::string intvec_to_str(std::vector<int> vecint){
	std::stringstream sstream;
	std::string str = "", temp = "";
	int i = 0;
	for (; i < (vecint.size())-1; i++){
		sstream = std::stringstream();
		sstream << vecint[i];
		sstream >> temp;
		str+=temp;
		str+=", ";
	}
	i++;
	sstream = std::stringstream();
	sstream << vecint[i];
	sstream >> temp;
	str+=temp;

	return str;
}

std::string sub_str(std::string &str, int start, int stop, int affect=0){
	int length = str.length();
	if (start>stop){
		printf("sub_str(): start (%d) is more than stop (%d).", start, stop);
		throw -1;
	}
	if (stop>length){
		printf("sub_str(): stop(%d) is more than string_length(%d)", stop, length);
		throw -1;
	}
	std::string to_return = "";
	for (;start < stop;start++){
		to_return += str[start];
		if (affect) str[start]=0;
	}
	return to_return;
}

vstr split_str(std::string str0, std::string str1)
{
	str0+=str1;
	vstr to_return;
	int pos = -1, temp;
	while (true){
		temp = pos;
		pos = find_str(str0, str1, pos+1);
		if (pos==-1) break;
		to_return.push_back(sub_str(str0, temp, pos));
		pos+=str1.length();
	}
	return to_return;
}

int count_chr(std::string str, char c){
	int total = 0;
	for (char ch:str){
		if (c==ch) total++;
	}
	return total;
}

//with " " 
vstr split_str_s(std::string str0, std::string str1, char surround='"')
{
	vstr to_return;
	int sy = (count_chr(str0, surround));
	if ((sy%2)!=0){
		std::cout << "split_str(): symbol("<< surround << ") not balance. found: "<< sy << "\n";
		return to_return;
	}
	int str0_length = str0.length();
	int str1_length = str1.length();
	str0+=str1;
	
	std::string temp = "";
	int open = 0;
	for (int i = 0; i < str0_length; i++){
		if (str0[i]==surround){
			open = !open ? 1 : 0;
			continue; //so the surround will not included
		}
		if ((str0[i]==str1[0])&&(!open)){
			int salah = 0, b=i;
			for (int a = 0; a < str1_length; a++){
				if (str0[b]!=str1[a]){
					salah = 1;
					break;
				}
				b++;
			}
			if(!salah){
				to_return.push_back(temp);
				temp="";
				i+=str1_length-1; //negative 1 because it will continue loop
				continue;
			}
		}
		temp+=str0[i];
	}
	to_return.push_back(temp);
	return to_return;
}