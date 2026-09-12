#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int JUMLAH_KOLOM = 18;
const string LABEL[JUMLAH_KOLOM] = {
    "Provinsi", "Kota/Kabupaten", "NIK", "Nama", "Tempat/Tgl Lahir", 
    "Jenis Kelamin", "Gol. Darah", "Alamat", "RT/RW", "Kel/Desa", 
    "Kecamatan", "Agama", "Status Perkawinan", "Pekerjaan", 
    "Kewarganegaraan", "Berlaku Hingga", "Tempat Pembuatan", "Tanggal Pembuatan"
};

struct KTP {
    string data[JUMLAH_KOLOM];
};

void tambahData(vector<KTP>& db) {
    KTP k;
    cin.ignore();
    cout << "\n=== INPUT DATA ===\n";
    for (int i = 0; i < JUMLAH_KOLOM; i++) {
        cout << LABEL[i] << " : ";
        getline(cin, k.data[i]);
    }
    db.push_back(k);
    cout << "-> Data disimpan!\n";
}

void tampilkanData(const vector<KTP>& db) {
    if (db.empty()) {
        cout << "\n-> Data kosong!\n";
        return;
    }
    int nomor = 1;
    for (const auto& k : db) {
        cout << "\n=== DATA KE-" << nomor++ << " ===\n";
        cout << "=======================================================\n";
        cout << "                 PROVINSI " << k.data[0] << "\n";
        cout << "                 " << k.data[1] << "\n\n";
        cout << " NIK               : " << k.data[2] << "\n";
        cout << " Nama              : " << k.data[3] << "\n";
        cout << " Tempat/Tgl Lahir  : " << k.data[4] << "\n";
        cout << " Jenis Kelamin     : " << k.data[5] << "      Gol. Darah : " << k.data[6] << "\n";
        cout << " Alamat            : " << k.data[7] << "\n";
        cout << "     RT/RW         : " << k.data[8] << "\n";
        cout << "     Kel/Desa      : " << k.data[9] << "\n";
        cout << "     Kecamatan     : " << k.data[10] << "\n";
        cout << " Agama             : " << k.data[11] << "\n";
        cout << " Status Perkawinan : " << k.data[12] << "\n";
        cout << " Pekerjaan         : " << k.data[13] << "\n";
        cout << " Kewarganegaraan   : " << k.data[14] << "\n";
        cout << " Berlaku Hingga    : " << k.data[15] << "\n\n";
        cout << "                                  " << k.data[16] << "\n";
        cout << "                                  " << k.data[17] << "\n";
        cout << "=======================================================\n";
    }
}

void hapusData(vector<KTP>& db) {
    if (db.empty()) {
        cout << "\n-> Data kosong, tidak ada yang bisa dihapus!\n";
        return;
    }
    
    int index;
    cout << "\nMasukkan nomor data yang ingin dihapus (1 - " << db.size() << "): ";
    cin >> index;

    if (index >= 1 && index <= db.size()) {
        db.erase(db.begin() + index - 1);
        cout << "-> Data ke-" << index << " berhasil dihapus!\n";
    } else {
        cout << "-> Nomor data tidak valid!\n";
    }
}

int main() {
    vector<KTP> db;
    int pilihan;

    do {
        cout << "\n1. Input | 2. Tampil | 3. Hapus | 4. Keluar\nPilih: ";
        cin >> pilihan;

        if (pilihan == 1) tambahData(db);
        else if (pilihan == 2) tampilkanData(db);
        else if (pilihan == 3) hapusData(db);
        
    } while (pilihan != 4);

    return 0;
}
