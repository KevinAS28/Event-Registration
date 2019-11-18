#include <iostream> //input output
#include <string>

using namespace std; //sebenernya buruk, tapi untuk mempermudah sementara tidak apa2


//variabel-variabel penting
std::string username_admin = "ADMIN", password_admin = "NIMDA";
int max_user; //deklarasi dulu. nanti tanya di input
std::string nama_app = "Event Organizer";
std::string welcome = "Selamat datang pada aplikasi " + nama_app + "\nUntuk memulai event, silahkan login terlebih dahulu\n";

void printstr(std::string str){
	for (char c : str){
		std::cout << (int)c << ", ";
		std::cout << "\n";
	}
}

int main(){
    std::cout << welcome;
    //LOGIN ADMIN
    std::string input_username, input_password;
    //selama loginnya salah, terus ulang tanya
    while ( !((input_username==username_admin) && (input_password==password_admin))){
        std::cout << "Username Admin: ";
        std::cin >> input_username;
        std::cout << "Password Admin: ";
        std::cin >> input_password;
        std::cout << "\n";    
    }



    return 0; //0 menandakan program baik-baik saja
}
