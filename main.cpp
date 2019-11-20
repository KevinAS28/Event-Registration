#include <iostream> //input output
#include <string> //getline()

using namespace std; //sebenernya buruk, tapi untuk mempermudah sementara tidak apa2


//variabel-variabel penting
string username_admin = "ADMIN", password_admin = "NIMDA";
int max_user = 0; //deklarasi dulu. nanti tanya di input
string nama_app = "Event Organizer";
string welcome = "\nSelamat datang pada aplikasi " + nama_app + "\nUntuk memulai event, silahkan login terlebih dahulu\n";
string menu = "\nMasukan angka pada menu berikut: \n1. Registrasi Tamu\n2. Validasi Tamu\n3.Edit Tamu\n4. Exit\n\n";

void printstr(string str){
	for (char c : str){
		cout << (int)c << ", ";
		cout << "\n";
	}
}

int main(){
    cout << welcome;
    
    
    //LOGIN ADMIN
    string input_username, input_password;
    //selama loginnya salah, terus ulang tanya
    while ( !((input_username==username_admin) && (input_password==password_admin))){
        cout << "Username Admin: ";
        cin >> input_username;
        cout << "Password Admin: ";
        cin >> input_password;
        cout << "\n";    
    }


	//tanya maximal tamu yang akan datang
	cout << "Berapa tamu yang maksimal akan datang? ";
	cin >> max_user;
	

	//MENU
	string users[(const)max_user][3]; // store semua user . tiga dari nama, email, password (ada 3)
	int user_keberapa = 0;
	while (1){
		cout << menu;
		int pilihan_menu;
		cin >> pilihan_menu;
		
		if (pilihan_menu==1){
			//pilihan registrasi tamu
			
			 cout << "Nama: ";
			//pakai ignore() dan getline() agar bisa input spasi
			cin.ignore();
			getline(cin, users[user_keberapa][0]);
			
			cout << "Email: ";
			cin >> users[user_keberapa][1];
	
			cout << "Password: ";
			cin >> users[user_keberapa][2];		
			
			user_keberapa++;
		}
		
		if (pilihan_menu==2){
			string email, password;
			
			cout << "Email: ";
			cin >> email;
	
			cout << "Password: ";
			cin >> password;
			
			//cari email, password di users
			bool ketemu = false;
			for (string user[3] : users){
				if ((user[1]==email)){
					ketemu = true;
					if (user[2]==password){
						cout << "TAMU " << user[0] << " TELAH TERDAFTAR :)\n";
					}
					else{
						cout << "SALAH PASSWORD\n";
					}
				}
			}
			if (!ketemu){
				cout << "TAMU TIDAK TERDAFTAR\n";
			}
		}
		
		if (pilihan_menu==3){
			//Edit Tamu
			cout << "\n\n";
			//tampilkan semua tamu yang telah terdaftar
			int index = 0;
			
			for (string user[3] : users){
				if (user[0]==""){continue;} //kalo ga ada namanya, skip
				
				cout << "Nomor tamu: " << index+1 << "\n";
				for (string data: user){
					cout << data << "\n";
				}
				cout << "\n";
				index++;
			}
			cout << "\n\n";
			
			int edit_berdasarkan = 1; //jika 1 maka edit berdasarkan angka, jika 2 edit berdasarkan email
			cout << "Anda akan edit tamu berdasarkan: \n1.Angka\n2.Email\nPilihan: ";
			cin >> edit_berdasarkan;
			
			if (edit_berdasarkan==1){
				//dari angka
				
				int angka;
				cout << "Angka tamu: ";
				cin >> angka;
				
				angka-=1;
				string user[3] = users[angka];
				
				
				cout << "Nama \"" << user[0] << "\" akan diedit menjadi: ";
				cin.ignore();
				getline(cin, users[angka][0]);
				
				cout << "Email \"" << users[angka][1] << "\" akan diedit menjadi: ";
				cin >> users[angka][1];
		
				cout << "Password \"" << users[angka][2] << "\" akan diedit menjadi: ";
				cin >> users[angka][2];
			}
			else{
				//dari email
				string email;
				cout << "Email tamu yang telah terdaftar: ";
				cin >> email;
				
				int angka = 0;
				for (string user[3] : users){
					if (user[1]==email) {
						break;
					}
					angka++;
				}
				
				cout << "Nama \"" << users[angka][0] << "\" Akan diedit menjadi: ";
				cin.ignore();
				getline(cin, users[angka][0]);
				
				cout << "Email: ";
				cin >> users[angka][1];
		
				cout << "Password: ";
				cin >> users[angka][2];				
			}
		}
		
		if (pilihan_menu==4){
			cout << "\n\n\n GOOD BYE :) \n\n\n";
			break;
		}
		
	}
		

    return 0; //0 menandakan program baik-baik saja
}
