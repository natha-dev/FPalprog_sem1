// program parkiran
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;

// Deklarasi Variable Global
int tot_biaya,tmp,pilih,jm_masuk,jm_keluar,durasi,biaya,harga_kendaraan,uang,kembalian,in_nop,jumlahParkir=0,selc_mobil,selc_motor,selc_bus,selc_truck;
string waktuString,nomorPlat,jenis_kendaraan[4] = {"Motor \t Rp.2000","Mobil \t Rp.4000","Truck \t Rp.6000","Bus   \t Rp.8000"};
char* waktu;

// membuat function kendaraan
void kendaraan(){
    // Menampilkan Array jenis_kendaraan
    for (int i = 0; i <= 3;i++){
        cout << "["<< i+1 <<"]" << jenis_kendaraan[i] << endl;
    }
}

void tanggal(){
    time_t now = time(0);
    waktu = ctime(&now);
    cout << "|         " << waktu;
}

void struk_parkir(){
    cout << "-----------------------------------------------\n";
	cout << "|             Struk Karcis Parkir             |\n";         
    tanggal();           
	cout << "-----------------------------------------------\n";
	cout << "|Jenis Kendaraan : " << left << setw(21) << jenis_kendaraan[pilih - 1] << "|\n";
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

        cout<<"Biaya Parkir \t\t: Rp." << biaya << endl;
        cout<<"Masukan Nominal Uang \t: ";
        cin >> uang;
        kembalian = uang - biaya;
        tot_biaya += biaya;

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
    cout<<"=========================================\n";
    cout<<"Pilih Kendaraan : ";
    cin >> pilih;

    jumlahParkir++;

    // membuat percabangan untuk memilih jenis kendaraan
    switch (pilih) {
        case 1:
            jenis_kendaraan[0];
            selc_motor += 1;
            harga_kendaraan = 2000;
            break;
        case 2:
            jenis_kendaraan[1];
            selc_mobil += 1;
            harga_kendaraan = 4000;
            break;
        case 3:
            jenis_kendaraan[2];
            selc_truck += 1;
            harga_kendaraan = 6000;
            break;
        case 4 :
            jenis_kendaraan[3];
            selc_bus += 1;
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
    int pilihan;
    cout << "Pilih Filter Pengurutan Data Parkir (1. Terbaru, 2. Terlama): ";
    cin >> pilihan;
  
	//mengurutkan data parkir berdasarkan waktu selesai parkir
    switch (pilihan) {
    case 1:
        for(int i=0; i<jumlahParkir; i++) {
            struk_parkir();
        }

        break;
    case 2:
        for(int i = jumlahParkir -1;i >= 0; i--){
            struk_parkir();
        } 

        break;
    default:
        cout<<"Pilih Filter Pengurutan";
        break;
    }

}

void totalhariini(){
    cout << "-----------------------------------------------\n";
	cout << "|            Total Parkir Hari Ini            |\n";    
    tanggal();                  
	cout << "-----------------------------------------------\n";
	cout << "|Motor : " << left << setw(37) << selc_motor << "|\n";
    cout << "|Mobil : " << left << setw(37) << selc_mobil << "|\n";
    cout << "|Bus : " << left << setw(37) << selc_bus << "|\n";
    cout << "|Truck : " << left << setw(37) << selc_truck << "|\n";
    cout << "|Total Parkir    : Rp." << left << setw(24) <<tot_biaya << "|\n";
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
                tampilkanDataParkir(); // bugs
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