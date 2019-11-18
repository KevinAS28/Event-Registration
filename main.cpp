#include <iostream> //input output
#include <string> //getline()

using namespace std; //sebenernya buruk, tapi untuk mempermudah sementara tidak apa2


//variabel-variabel penting
std::string username_admin = "ADMIN", password_admin = "NIMDA";
int max_user = 0; //deklarasi dulu. nanti tanya di input
std::string nama_app = "Event Organizer";
std::string welcome = "\nSelamat datang pada aplikasi " + nama_app + "\nUntuk memulai event, silahkan login terlebih dahulu\n";
std::string menu = "\nMasukan angka pada menu berikut: \n1. Registrasi Tamu\n2. Validasi Tamu\n3.Edit Tamu\n4. Exit\n\n";

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


	//tanya maximal tamu yang akan datang
	std::cout << "Berapa tamu yang maksimal akan datang? ";
	std::cin >> max_user;
	

	//MENU
	std::string users[(const)max_user][3]; // store semua user . tiga dari nama, email, password (ada 3)
	int user_keberapa = 0;
	while (1){
		std::cout << menu;
		int pilihan_menu;
		std::cin >> pilihan_menu;
		
		if (pilihan_menu==1){
			//pilihan registrasi tamu
			
			std:: cout << "Nama: ";
			//pakai ignore() dan getline() agar bisa input spasi
			std::cin.ignore();
			std::getline(std::cin, users[user_keberapa][0]);
			
			std::cout << "Email: ";
			std::cin >> users[user_keberapa][1];
	
			std::cout << "Password: ";
			std::cin >> users[user_keberapa][2];		
			
			user_keberapa++;
		}
		
		if (pilihan_menu==2){
			std::string email, password;
			
			std::cout << "Email: ";
			std::cin >> email;
	
			std::cout << "Password: ";
			std::cin >> password;
			
			//cari email, password di users
			bool ketemu = false;
			for (std::string user[3] : users){
				if ((user[1]==email)){
					ketemu = true;
					if (user[2]==password){
						std::cout << "TAMU " << user[0] << " TELAH TERDAFTAR :)\n";
					}
					else{
						std::cout << "SALAH PASSWORD\n";
					}
				}
			}
			if (!ketemu){
				std::cout << "TAMU TIDAK TERDAFTAR\n";
			}
		}
		
		if (pilihan_menu==3){
			//Edit Tamu
			std::cout << "\n\n";
			//tampilkan semua tamu yang telah terdaftar
			int index = 0;
			
			for (std::string user[3] : users){
				if (user[0]==""){continue;} //kalo ga ada namanya, skip
				
				std::cout << "Nomor tamu: " << index+1 << "\n";
				for (std::string data: user){
					std::cout << data << "\n";
				}
				std::cout << "\n";
				index++;
			}
			std::cout << "\n\n";
			
			int edit_berdasarkan = 1; //jika 1 maka edit berdasarkan angka, jika 2 edit berdasarkan email
			std::cout << "Anda akan edit tamu berdasarkan: \n1.Angka\n2.Email\nPilihan: ";
			std::cin >> edit_berdasarkan;
			
			if (edit_berdasarkan==1){
				//dari angka
				
				int angka;
				std::cout << "Angka tamu: ";
				std::cin >> angka;
				
				angka-=1;
				std::string user[3] = users[angka];
				
				
				std::cout << "Nama \"" << user[0] << "\" akan diedit menjadi: ";
				std::cin.ignore();
				std::getline(std::cin, users[angka][0]);
				
				std::cout << "Email \"" << users[angka][1] << "\" akan diedit menjadi: ";
				std::cin >> users[angka][1];
		
				std::cout << "Password \"" << users[angka][2] << "\" akan diedit menjadi: ";
				std::cin >> users[angka][2];
			}
			else{
				//dari email
				std::string email;
				std::cout << "Email tamu yang telah terdaftar: ";
				std::cin >> email;
				
				int angka = 0;
				for (std::string user[3] : users){
					if (user[1]==email) {
						break;
					}
					angka++;
				}
				
				std::cout << "Nama \"" << users[angka][0] << "\" Akan diedit menjadi: ";
				std::cin.ignore();
				std::getline(std::cin, users[angka][0]);
				
				std::cout << "Email: ";
				std::cin >> users[angka][1];
		
				std::cout << "Password: ";
				std::cin >> users[angka][2];				
			}
		}
		
		if (pilihan_menu==4){
			std::cout << "\n\n\n GOOD BYE :) \n\n\n";
			break;
		}
		
	}
		

    return 0; //0 menandakan program baik-baik saja
}
