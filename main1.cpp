#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "strtool.h"
#include <sstream>

std::string admin = "ADMIN", adminpw="123";

std::string input(std::string msg){
    std::string inp;
    std::cout << msg;
    std::cin >> inp;
    return inp;
}

std::string menu = "\nEvent Program Registration\nplease input the number below\n\n1. Register Guest\n2. Validate Guest\n3. exit\n\nmasukan anda: ";

typedef void(*voidfptr)();

std::stringstream sstream;


class UserData;

std::vector<UserData*> users = std::vector<UserData*>();

class UserData{
public:
    std::string user, code, nama;
    UserData(std::string n): nama(n){
        user = split_str(n, " ")[0];
        int ran = users.size();
        sstream = std::stringstream();
        sstream << ran;
        sstream >> this->code;
        code = user+(this->code);
    }
};

void register_user(){
    std::string nama, stop="STOP";
    std::cout << "Ketik " << stop << " Untuk Berhenti dan ganti spasi dengan uderscore\n";
    while (1){
        nama = input("Nama Lengkap: ");
        if (nama==stop) {break;}
        
        UserData* user = new UserData(nama);
        std::cout << nama << " telah terdaftar dengan kode: " << (*user).code << "\n\n";
        users.push_back(user);
    }
    std::cout << "\n\n";
    // for (UserData dat : users){
    //     std::cout << dat.nama << "\n";
    // }
}

void validate_guest(){
    std::string kode , stop="STOP";
    std::cout << "Ketik " << stop << " Untuk Berhenti\n";

    while (1){
        bool found = false;
        kode = input("KODE: ");
        if (kode==stop) {break;}
        for (UserData* user : users){
            std::string usercode =(*user).code;
            usercode = sub_str(usercode, 1, usercode.size());
            // std::cout << intvec_to_str(str_to_intvec(usercode)) << "\n";
            // std::cout << intvec_to_str(str_to_intvec((kode))) << "\n";
            std::cout << "\n";
            if (same_str(usercode, kode)){
                found = true;
                std::cout << "User: " << (*user).nama << " Telah Terdaftar :)\n";
                break;
            }
        }
        if  (!found){
            std::cout << "kode tidak terdaftar\n\n";
        }
    }    
}

bool stop = 0;

void exit(){
    std::cout << "Bye :)\n";
    stop = 1;
}

voidfptr menus[] = {&register_user, &validate_guest,  &exit};
std::string temp = "";

int main(){
    
    
    //LOGIN AS ADMIN
    std::string user, pass;
    while ( (user!=admin) || (adminpw!=pass)){
        std::cout << "\n\n";
        user = input("USERNAME: ");
        pass = input("PASSWORD: ");
    }
    std::cout << "Login Success\n";
    
    
    //MENU
    
    while (!stop){
        std::cout << menu ;
        std::cin >> temp;
        std::cout << "\n\n";
        int input_menu = stoi(temp)-1;
        (*(menus[input_menu]))();
    }
    return 0;
}