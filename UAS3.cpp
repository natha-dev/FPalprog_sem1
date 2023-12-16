// program parkiran
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <algorithm>

using namespace std;

struct Parkir {
    int jenisKendaraan;
    string nomorPlat;
    int jm_masuk;
    int jm_keluar;
    int biaya;
    int uang;
    int kembalian;
};

const int MAX_PARKIR = 100; // set maksimal jumlah data
Parkir dataParkir[MAX_PARKIR];

// Deklarasi Variable Global
int jenisKendaraan,tot_biaya,pilih,jm_masuk,jm_keluar,durasi,biaya,harga_kendaraan,uang,kembalian,jumlahParkir=0,selc_mobil,selc_motor,selc_bus,selc_truck;
string nomorPlat;
char* waktu;

string getJenisKendaraanString(int jenisKendaraan) {
    switch (jenisKendaraan) {
        case 1:
            return "Motor";
        case 2:
            return "Mobil";
        case 3:
            return "Truk";
        case 4:
            break;
        default :
            cout << "Opsi Kendaraan tidak Valid\n";
    }
}

void tanggal(){
    time_t now = time(0);
    waktu = ctime(&now);
    cout << "|         " << waktu;
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

        dataParkir[jumlahParkir++] = {jenisKendaraan,nomorPlat, jm_masuk, jm_keluar,biaya,uang,kembalian};

        cout << "-----------------------------------------------\n";
        cout << "|             Struk Karcis Parkir             |\n";
        cout << "-----------------------------------------------\n";
        cout << "|Jenis Kendaraan : " << left << setw(27) << getJenisKendaraanString(jenisKendaraan) << "|\n";
        cout << "|Nomor Plat      : " << left << setw(27) << nomorPlat << "|\n";
        cout << "|Jam Masuk       : " << left << setw(27) << jm_masuk << "|\n";
        cout << "|Jam Keluar      : " << left << setw(27) << jm_keluar << "|\n";
        cout << "-----------------------------------------------\n";
        cout << "|Biaya Perjam    : Rp." << left << setw(24) <<harga_kendaraan << "|\n";
        cout << "|Biaya Parkir    : Rp." << left << setw(24) <<biaya << "|\n";
        cout << "-----------------------------------------------\n";
        cout << "|Bayar           : " << left << setw(27) << uang << "|\n";
        cout << "|Kembalian       : " << left << setw(27) << kembalian << "|\n";
        cout << "-----------------------------------------------\n";

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
    cout << "[1]Motor    \tRp.2000 perJam\n";
    cout << "[2]Mobil \tRp.4000 perJam\n";
    cout << "[3]Truk \tRp.6000 perJam\n";
    cout << "[4]Bus \t\tRp.8000 perJam\n";
    cout << "Masukan Jenis Kendaraan : ";
    cin >> jenisKendaraan;

    switch (jenisKendaraan) {
        case 1:
            selc_motor += 1;
            harga_kendaraan = 2000;
            break;
        case 2:
            selc_mobil += 1;
            harga_kendaraan = 4000;
            break;
        case 3:
            selc_truck += 1;
            harga_kendaraan = 6000;
            break;
        case 4:
            selc_bus += 1;
            harga_kendaraan = 8000;
            break;
        default :
            cout << "Opsi Kendaraan tidak Valid\n";
    }

    menghitung_biaya();

}

void pencarianNomorKendaraan(){
    string searchPlat;
    cout << "Masukkan Plat Kendaraan yang Dicari: ";
    cin >> searchPlat;

    for (int i = 0; i < jumlahParkir; ++i){
        if (dataParkir[i].nomorPlat.find(searchPlat) != string::npos){
            cout << "-----------------------------------------------\n";
            cout << "|             Struk Karcis Parkir             |\n";
            cout << "-----------------------------------------------\n";
            cout << "|Jenis Kendaraan : " << left << setw(27) << getJenisKendaraanString(dataParkir[i].jenisKendaraan) << "|\n";
            cout << "|Nomor Plat      : " << left << setw(27) << dataParkir[i].nomorPlat << "|\n";
            cout << "|Jam Masuk       : " << left << setw(27) << dataParkir[i].jm_masuk << "|\n";
            cout << "|Jam Keluar      : " << left << setw(27) << dataParkir[i].jm_keluar << "|\n";
            cout << "-----------------------------------------------\n";
            cout << "|Biaya Perjam    : Rp." << left << setw(24) <<harga_kendaraan << "|\n";
            cout << "|Biaya Parkir    : Rp." << left << setw(24) <<dataParkir[i].biaya << "|\n";
            cout << "-----------------------------------------------\n";
            cout << "|Bayar           : " << left << setw(27) << dataParkir[i].uang << "|\n";
            cout << "|Kembalian       : " << left << setw(27) << dataParkir[i].kembalian << "|\n";
            cout << "-----------------------------------------------\n";
        }
    }

}

void struct_parkir(){
    for (int i = 0; i < jumlahParkir; ++i) {
        cout << "-----------------------------------------------\n";
        cout << "|             Struk Karcis Parkir             |\n";
        cout << "-----------------------------------------------\n";
        cout << "|Jenis Kendaraan : " << left << setw(27) << getJenisKendaraanString(dataParkir[i].jenisKendaraan) << "|\n";
        cout << "|Nomor Plat      : " << left << setw(27) << dataParkir[i].nomorPlat << "|\n";
        cout << "|Jam Masuk       : " << left << setw(27) << dataParkir[i].jm_masuk << "|\n";
        cout << "|Jam Keluar      : " << left << setw(27) << dataParkir[i].jm_keluar << "|\n";
        cout << "-----------------------------------------------\n";
        cout << "|Biaya Perjam    : Rp." << left << setw(24) <<harga_kendaraan << "|\n";
        cout << "|Biaya Parkir    : Rp." << left << setw(24) <<dataParkir[i].biaya << "|\n";
        cout << "-----------------------------------------------\n";
        cout << "|Bayar           : " << left << setw(27) << dataParkir[i].uang << "|\n";
        cout << "|Kembalian       : " << left << setw(27) << dataParkir[i].kembalian << "|\n";
        cout << "-----------------------------------------------\n";
    }
}

bool compareByTime(const Parkir &a, const Parkir &b) {
    return a.jm_masuk < b.jm_masuk;
}

bool compareByPlat(const Parkir &a, const Parkir &b) {
    return a.nomorPlat < b.nomorPlat;
}


void tampilkanDataParkir() {
    int pilihan;
    cout << "[1] Default \n";
    cout << "[2] Waktu \n";
    cout << "[3] Plat \n";
    cout << "Pilih Filter Pengurutan Data Parkir : ";
    cin >> pilihan;

    switch (pilihan) {
        case 1 :
            struct_parkir();
            break;
        case 2:
            sort(dataParkir, dataParkir + jumlahParkir, compareByTime);
            struct_parkir();
            break;
        case 3:
            sort(dataParkir, dataParkir + jumlahParkir, compareByPlat);
            struct_parkir();
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
    cout << "|Bus : " << left << setw(39) << selc_bus << "|\n";
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