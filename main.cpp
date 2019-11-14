#include <iostream>
#include <string>
#include <vector>

std::string admin = "ADMIN", adminpw="123";

std::string input(std::string msg){
    std::string inp;
    std::cout << msg << "\n";
    std::cin >> inp;
    return inp;
}

int main(){
    std::string user, pass;

    while ( (user!=admin) && (adminpw!=pass)){
        std::cout << "\n\n";
        user = input("USERNAME: ");
        user = input("PASSWORD: ");
    }
    

    return 0;
}