// program parkiran
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;

// Deklarasi Variable Global
int tmp,pilih,jm_masuk,jm_keluar,durasi,biaya,harga_kendaraan,uang,kembalian,in_nop,jumlahParkir=0;
string waktuString,nomorPlat,jenis_kendaraan[4] = {"Motor \t Rp.2000","Mobil \t Rp.4000","Truck \t Rp.6000","Bus   \t Rp.8000"};

// membuat function kendaraan
void kendaraan(){
    // Menampilkan Array jenis_kendaraan
    for (int i = 0; i <= 3;i++){
        cout << "["<< i+1 <<"]" << jenis_kendaraan[i] << endl;
    }
}

void waktu(){
    // Mendapatkan waktu saat ini
    time_t currentTime = time(0);
    tm *localTime = localtime(&currentTime);

    // Membuat objek ostringstream untuk menyimpan output waktu
    ostringstream oss;

    // Menyimpan output waktu ke dalam ostringstream
    oss << "|       " << asctime(localTime);

    // Mendapatkan string dari ostringstream
    waktuString = oss.str();

    cout<<waktuString << left << setw(21) << "|\n";
}

void struk_parkir(){
    cout << "-----------------------------------------------\n";
	cout << "|             Struk Karcis Parkir             |\n";                     
    waktu();
	cout << "-----------------------------------------------\n";
	cout << "|Jenis Kendaraan : " << left << setw(21) << jenis_kendaraan[pilih] << "|\n";
    cout << "|Nomor Plat      : " << left << setw(27) << nomorPlat << "|\n";
    cout << "|Jam Masuk       : " << left << setw(27) << jm_masuk << "|\n";
    cout << "|Jam Keluar      : " << left << setw(27) << jm_keluar << "|\n";
    cout << "-----------------------------------------------\n";
    cout << "|Biaya Parkir    : Rp." << left << setw(24) <<biaya << "|\n";
    cout << "-----------------------------------------------\n";
    cout << "|Bayar           : " << left << setw(27) << uang << "|\n";
    cout << "|Kembalian       : " << left << setw(27) << kembalian << "|\n";
    cout << "-----------------------------------------------\n";
}

void menghitung_biaya(){
    cout << "Nomor Plat Kendaraan \t: ";
    cin >> nomorPlat;

    cout << "Jam Masuk Kendaraan  \t: ";
    cin >> jm_masuk;

    cout << "Jam Keluar Kendaraan \t: ";
    cin >> jm_keluar;

    if(jm_masuk > 0 && jm_keluar <= 24){
        durasi = jm_keluar - jm_masuk;
        biaya = durasi * harga_kendaraan;

        cout<<"Masukan Nominal Uang \t: ";
        cin >> uang;
        kembalian = uang - biaya;

       struk_parkir();

        if(biaya > uang){
            cout<<"Uang Kurang\n";
            menghitung_biaya();
        }

    } else {
        cout<<"Masukan Waktu 1 - 24\n";
        menghitung_biaya();
    }
}

// membuat function pembayaranKarcis
void pembayaranKarcis(){
    cout<<"=========================================\n";
    kendaraan();
    cout<<"Pilih Kendaraan : ";
    cin >> pilih;

    jumlahParkir++;

    // membuat percabangan untuk memilih jenis kendaraan
    switch (pilih) {
        case 1:
            jenis_kendaraan[0];
            harga_kendaraan = 2000;
            break;
        case 2:
            jenis_kendaraan[1];
            harga_kendaraan = 4000;
            break;
        case 3:
            jenis_kendaraan[2];
            harga_kendaraan = 6000;
            break;
        case 4 :
            jenis_kendaraan[3];
            harga_kendaraan = 8000;
            break;
        default :
            cout << "Opsi Kendaraan tidak Valid\n";
            pembayaranKarcis();
    }

    menghitung_biaya();
    
}

void pencarianNomorKendaraan(){
    string searchPlat;
    cout << "Masukkan Plat Kendaraan yang Dicari: ";
    cin >> searchPlat;
    int h,j,ditemukan = 0; // deklarasi variable

    for (h=0; h<jumlahParkir; h++){
        if (nomorPlat == searchPlat){
            ditemukan = 1;
            
            struk_parkir();

        }
    }
    if (ditemukan==0){
        cout<<"Plat tidak ditemukan" << endl;
    }

}

void tampilkanDataParkir() {
    cout << "\nData Parkir:\n";
    for (int i = 0; i < jumlahParkir; ++i) {
        struk_parkir();
    }
}

void urutkanDataParkir() {
    int pilihan;
    cout << "Pilih Filter Pengurutan (1. Terbaru, 2. Terlama): ";
    cin >> pilihan;
  
	//mengurutkan data parkir berdasarkan waktu selesai parkir

}

void totalhariini(){
    cout << "-----------------------------------------------\n";
	cout << "|       Total Parkir Hari Ini (tanggal)             |\n";                     
	cout << "-----------------------------------------------\n";
	cout << "|Motor : " << left << setw(21) <<  << "|\n";
    cout << "|Mobil : " << left << setw(21) <<  << "|\n";
    cout << "|Bus : " << left << setw(21) <<  << "|\n";
    cout << "|Truck : " << left << setw(21) <<  << "|\n";
    cout << "|Total Parkir    : Rp." << left << setw(24) <<biaya << "|\n";
    cout << "-----------------------------------------------\n";
}

int main(){

    int menu;

    do {
        cout << "\nMenu:\n";
        cout << "1. Pembayaran Karcis Parkir\n";
        cout << "2. Pencarian Nomor Kendaraan\n";
        cout << "3. Tampilkan Data Parkir\n";
        cout << "4. Total Parkir Hari Ini\n";
        cout << "5. Keluar\n";
        cout << "\n";
        cout << "Pilih menu: ";
        cin >> menu;

        switch (menu) {
            case 1:
                pembayaranKarcis();
                break;
            case 2:
                pencarianNomorKendaraan();
                break;
            case 3:
                tampilkanDataParkir();
                break;
            case 4:
                totalhariini();
                break;
            case 5:
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
                break;
        }
    } while (menu != 5);

    return 0;
    

}