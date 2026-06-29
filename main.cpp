//Tugas PROJEK MATA KULIAH ALGORITMA PEMROGRAMAN

// TIM 14
// NAMA ANGGOTA:
// APRILLIA RAHMASARI DISTIAH (2500018112)
// AISYAH DWI WINDARTI        (2500018115)
// ALLIFA MAULANI              (2500018129)

// PROGRAM STUDI INFORMATIKA
// FAKULTAS TEKNOLOGI INDUSTRI
// UNIVERSITAS AHMAD DAHLAN

// TAHUN 2025/2026

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Batas Maksimum Array Statis (Simulasi Database Terbatas)
const int MAX_BBM = 10;
const int MAX_PEGAWAI = 10;
const int MAX_TRANSAKSI = 50;

// ==================== STRUKTUR DATA ====================
struct BBM {
    string nama;
    double harga;
    double stok; // dalam Liter
};

struct Transaksi {
    string tanggal;
    string namaPetugas;
    string namaBBM;
    double liter;
    double totalBayar;
};

struct Pegawai {
    string username;
    string password;
    string nama;
};

// ==================== DATA GLOBAL (DATABASE AWAL) ====================
BBM daftarBBM[MAX_BBM] = {
    {"Pertalite", 10000, 1500.0},
    {"Pertamax", 12500, 1000.0},
    {"Pertamax Turbo", 14500, 500.0},
    {"Dexlite", 13000, 800.0}
};
int jumlahBBM = 4; // Menghitung total jenis BBM aktif

Pegawai daftarPegawai[MAX_PEGAWAI] = {
    {"petugas1", "123", "Budi Santoso"},
    {"petugas2", "123", "Siti Aminah"}
};
int jumlahPegawai = 2; // Menghitung total data pegawai aktif

Transaksi riwayatTransaksi[MAX_TRANSAKSI] = {
    {"18-06-2026", "Budi Santoso", "Pertalite", 5.0, 50000},
    {"18-06-2026", "Siti Aminah", "Pertamax", 10.0, 125000}
};
int jumlahTransaksi = 2; // Menghitung total data transaksi aktif

// ==================== DEKLARASI FUNGSI PROTOTYPE ====================
void menuUtama();
void loginAdmin();
void loginPetugas();
void menuPelanggan();

void dashboardAdmin();
void kelolaDataBBM();
void kelolaStokBBM();
void kelolaHargaBBM();
void lihatLaporanPenjualan();
void lihatLaporanStok();        // Fungsi Baru
void lihatLaporanKeuangan();    // Fungsi Baru
void kelolaDataPegawai();

void dashboardPetugas(Pegawai p);
void transaksiPengisianBBM(Pegawai p);
void cekTransaksiHarianPetugas(Pegawai p);

void lihatInformasiBBM();

// ==================== FUNGSI UTAMA (MAIN) ====================
int main() {
    menuUtama();
    return 0;
}

// ==================== IMPLEMENTASI FUNGSI MODUL ====================

void menuUtama() {
    int pilihan;
    do {
        cout << "\n=========================================\n";
        cout << "      SISTEM MANAJEMEN SPBU DIGITAL      \n";
        cout << "=========================================\n";
        cout << "Pilih Role Pengguna:\n";
        cout << "1. Admin\n";
        cout << "2. Petugas\n";
        cout << "3. Pelanggan\n";
        cout << "4. Keluar Aplikasi\n";
        cout << "-----------------------------------------\n";
        cout << "Masukkan pilihan (1-4): ";
        cin >> pilihan;

        switch(pilihan) {
            case 1: loginAdmin(); break;
            case 2: loginPetugas(); break;
            case 3: menuPelanggan(); break;
            case 4: cout << "\nTerima kasih telah menggunakan sistem SPBU.\n"; break;
            default: cout << "\nPilihan tidak valid. Silakan coba lagi.\n";
        }
    } while(pilihan != 4);
}


//-------------------------------------------------------------------
//-------------------------------------------------------------------
//-------------------------------------------------------------------
//-------------------------------------------------------------------
// username: admin
// password: admin123
//-------------------------------------------------------------------
//-------------------------------------------------------------------
//-------------------------------------------------------------------
//-------------------------------------------------------------------
// -------------------- MODUL ADMIN --------------------
void loginAdmin() {
    string username, password;
    cout << "\n--- LOGIN ADMIN ---\n";
    cout << "Username: "; cin >> username;
    cout << "Password: "; cin >> password;

    if(username == "admin" && password == "admin123") {
        cout << "\nLogin Berhasil! Selamat datang di Dashboard Admin.\n";
        dashboardAdmin();
    } else {
        cout << "\nUsername atau Password salah!\n";
    }
}

void dashboardAdmin() {
    int pilihan;
    do {
        cout << "\n=========================================\n";
        cout << "             DASHBOARD ADMIN             \n";
        cout << "=========================================\n";
        cout << "1. Kelola Data BBM (Lihat/Tambah)\n";
        cout << "2. Kelola Stok Bahan Bakar (Restock)\n";
        cout << "3. Kelola Harga BBM\n";
        cout << "4. Lihat Riwayat Transaksi Penjualan\n";
        cout << "5. Lihat Laporan Stok LOGISTIK\n";      // Menu Baru
        cout << "6. Lihat Laporan KEUANGAN\n";          // Menu Baru
        cout << "7. Kelola Data Pegawai\n";
        cout << "8. Logout\n";
        cout << "-----------------------------------------\n";
        cout << "Pilihan: "; cin >> pilihan;

        switch(pilihan) {
            case 1: kelolaDataBBM(); break;
            case 2: kelolaStokBBM(); break;
            case 3: kelolaHargaBBM(); break;
            case 4: lihatLaporanPenjualan(); break;
            case 5: lihatLaporanStok(); break;
            case 6: lihatLaporanKeuangan(); break;
            case 7: kelolaDataPegawai(); break;
            case 8: cout << "\nKeluar dari Dashboard Admin.\n"; break;
            default: cout << "\nPilihan tidak valid!\n";
        }
    } while(pilihan != 8);
}

void kelolaDataBBM() {
    cout << "\n--- FORM TAMBAH / LIHAT DATA BBM ---\n";
    cout << "Daftar BBM Saat Ini:\n";
    cout << left << setw(5) << "No" << setw(20) << "Nama BBM" << setw(15) << "Harga" << setw(10) << "Stok (L)" << endl;
    for(int i = 0; i < jumlahBBM; ++i) {
        cout << left << setw(5) << i+1 
             << setw(20) << daftarBBM[i].nama 
             << "Rp " << setw(12) << daftarBBM[i].harga 
             << setw(10) << daftarBBM[i].stok << endl;
    }
    
    char tambah;
    cout << "\nIngin menambah jenis BBM baru? (y/n): "; cin >> tambah;
    if(tambah == 'y' || tambah == 'Y') {
        if(jumlahBBM >= MAX_BBM) {
            cout << "\nGagal menambah data! Kapasitas database BBM penuh.\n";
            return;
        }

        string namaBaru;
        cout << "Masukkan Nama BBM Baru: "; cin.ignore(); getline(cin, namaBaru);

        // --- VALIDASI PENGECEKAN DUPLIKASI DATA NAMA ---
        bool sudahAda = false;
        for(int i = 0; i < jumlahBBM; ++i) {
            if(daftarBBM[i].nama == namaBaru) {
                sudahAda = true;
                break;
            }
        }

        if(sudahAda) {
            cout << "\n[PERINGATAN] Gagal menambahkan! Jenis BBM \"" << namaBaru << "\" sudah terdaftar di sistem.\n";
            return; 
        }

        daftarBBM[jumlahBBM].nama = namaBaru;
        cout << "Masukkan Harga per Liter: Rp "; cin >> daftarBBM[jumlahBBM].harga;
        cout << "Masukkan Stok Awal (Liter): "; cin >> daftarBBM[jumlahBBM].stok;
        jumlahBBM++;
        cout << "\nJenis BBM baru berhasil ditambahkan!\n";
    }
}

void kelolaStokBBM() {
    cout << "\n--- TABEL STOK BBM ---\n";
    cout << left << setw(5) << "No" << setw(20) << "Nama BBM" << setw(15) << "Stok Saat Ini (L)" << endl;
    for(int i = 0; i < jumlahBBM; ++i) {
        cout << left << setw(5) << i+1 << setw(20) << daftarBBM[i].nama << setw(15) << daftarBBM[i].stok << endl;
    }
    
    int nomor;
    double tambahanStok;
    cout << "\nPilih nomor BBM untuk restock (0 untuk batal): "; cin >> nomor;
    if(nomor > 0 && nomor <= jumlahBBM) {
        cout << "Masukkan jumlah pasokan stok baru (Liter): "; cin >> tambahanStok;
        daftarBBM[nomor-1].stok += tambahanStok;
        cout << "\nStok " << daftarBBM[nomor-1].nama << " berhasil diperbarui!\n";
    }
}

void kelolaHargaBBM() {
    cout << "\n--- KELOLA HARGA BBM ---\n";
    for(int i = 0; i < jumlahBBM; ++i) {
        cout << i+1 << ". " << daftarBBM[i].nama << " (Harga Sekarang: Rp " << daftarBBM[i].harga << ")\n";
    }
    int nomor;
    double hargaBaru;
    cout << "Pilih nomor BBM yang akan diubah harganya (0 untuk batal): "; cin >> nomor;
    if(nomor > 0 && nomor <= jumlahBBM) {
        cout << "Masukkan Harga Baru untuk " << daftarBBM[nomor-1].nama << ": Rp "; cin >> hargaBaru;
        daftarBBM[nomor-1].harga = hargaBaru;
        cout << "\nHarga " << daftarBBM[nomor-1].nama << " berhasil diubah!\n";
    }
}

void lihatLaporanPenjualan() {
    cout << "\n=============================================================\n";
    cout << "                RIWAYAT PENJUALAN HARIAN                     \n";
    cout << "=============================================================\n";
    cout << left << setw(12) << "Tanggal" << setw(15) << "Petugas" << setw(15) << "BBM" << setw(10) << "Liter" << setw(15) << "Total Pendapatan" << endl;
    cout << "-------------------------------------------------------------\n";
    double totalSemua = 0;
    for(int i = 0; i < jumlahTransaksi; ++i) {
        cout << left << setw(12) << riwayatTransaksi[i].tanggal 
             << setw(15) << riwayatTransaksi[i].namaPetugas 
             << setw(15) << riwayatTransaksi[i].namaBBM 
             << setw(10) << riwayatTransaksi[i].liter 
             << "Rp " << riwayatTransaksi[i].totalBayar << endl;
        totalSemua += riwayatTransaksi[i].totalBayar;
    }
    cout << "-------------------------------------------------------------\n";
    cout << "TOTAL PENDAPATAN HARIAN: Rp " << totalSemua << "\n";
    cout << "=============================================================\n";
}

// ==================== FUNGSI BARU: LAPORAN STOK LOGISTIK ====================
void lihatLaporanStok() {
    cout << "\n=============================================================\n";
    cout << "                LAPORAN STOK & LOGISTIK BBM                 \n";
    cout << "=============================================================\n";
    cout << left << setw(5) << "No" << setw(20) << "Nama Produk" << setw(18) << "Sisa Stok (L)" << setw(15) << "Status" << endl;
    cout << "-------------------------------------------------------------\n";
    
    for(int i = 0; i < jumlahBBM; ++i) {
    string status = "AMAN";
    if(daftarBBM[i].stok <= 200.0) {
        status = "KRITIS (Butuh Restock!)"; // Diperbaiki: menggunakan '=' bukan '<<'
    } else if(daftarBBM[i].stok <= 600.0) {
        status = "WASPADA (Menipis)";
    }
    
    cout << left << setw(5) << i+1 
         << setw(20) << daftarBBM[i].nama 
         << setw(18) << daftarBBM[i].stok 
         << status << endl;
    }
    cout << "=============================================================\n";
    cout << "*Catatan: Segera lakukan pengisian (Restock) jika status Waspada/Kritis.\n";
}

// ==================== FUNGSI BARU: LAPORAN KEUANGAN DETAIL ====================
void lihatLaporanKeuangan() {
    double totalPendapatan = 0;
    double totalVolumeBBM = 0;
    
    cout << "\n=============================================================\n";
    cout << "                    LAPORAN KEUANGAN SPBU                    \n";
    cout << "=============================================================\n";
    
    // Rincian Penjualan per Kategori BBM
    cout << "A. RINGKASAN PENDAPATAN PRODUK:\n";
    cout << "-------------------------------------------------------------\n";
    cout << left << setw(20) << "Nama BBM" << setw(18) << "Volume Terjual" << setw(20) << "Total Omset" << endl;
    cout << "-------------------------------------------------------------\n";
    
    for(int i = 0; i < jumlahBBM; ++i) {
    double volTerjual = 0;
    double omsetProduk = 0;
    
    for(int j = 0; j < jumlahTransaksi; ++j) {
        if(riwayatTransaksi[j].namaBBM == daftarBBM[i].nama) {
            volTerjual += riwayatTransaksi[j].liter;
            omsetProduk += riwayatTransaksi[j].totalBayar;
        }
    }
    
    // --- BAGIAN YANG DIPERBAIKI ---
    // Mengatur agar angka desimal volTerjual hanya menampilkan 1 digit di belakang koma
    cout << left << setw(20) << daftarBBM[i].nama 
         << fixed << setprecision(1) << setw(10) << volTerjual << setw(8) << "Liter"
         << "Rp " << fixed << setprecision(0) << omsetProduk << endl;
         
    totalPendapatan += omsetProduk;
    totalVolumeBBM += volTerjual;
}
    
    // Analisis Statistik Keuangan Makro
    cout << "-------------------------------------------------------------\n";
    cout << "B. STATISTIK KEUANGAN GLOBAL:\n";
    cout << "1. Total Transaksi Terjadi   : " << jumlahTransaksi << " Transaksi\n";
    cout << "2. Total Volume BBM Terjual  : " << totalVolumeBBM << " Liter\n";
    cout << "3. TOTAL PENDAPATAN KOTOR    : Rp " << totalPendapatan << "\n";
    
    if(jumlahTransaksi > 0) {
        cout << "4. Rata-rata per Transaksi   : Rp " << (totalPendapatan / jumlahTransaksi) << "\n";
    } else {
        cout << "4. Rata-rata per Transaksi   : Rp 0\n";
    }
    cout << "=============================================================\n";
}

void kelolaDataPegawai() {
    cout << "\n--- KELOLA DATA PEGAWAI ---\n";
    cout << "Daftar Pegawai Aktif:\n";
    cout << left << setw(5) << "No" << setw(15) << "Username" << setw(20) << "Nama Pegawai" << endl;
    for(int i = 0; i < jumlahPegawai; ++i) {
        cout << left << setw(5) << i+1 << setw(15) << daftarPegawai[i].username << setw(20) << daftarPegawai[i].nama << endl;
    }
    
    char tambah;
    cout << "\nTambah pegawai baru? (y/n): "; cin >> tambah;
    if(tambah == 'y' || tambah == 'Y') {
        if(jumlahPegawai >= MAX_PEGAWAI) {
            cout << "\nGagal menambah data! Kapasitas database pegawai penuh.\n";
            return;
        }
        cout << "Username Baru: "; cin >> daftarPegawai[jumlahPegawai].username;
        cout << "Password: "; cin >> daftarPegawai[jumlahPegawai].password;
        cout << "Nama Lengkap Pegawai: "; cin.ignore(); getline(cin, daftarPegawai[jumlahPegawai].nama);
        jumlahPegawai++;
        cout << "\nPegawai baru berhasil didaftarkan!\n";
    }
}

// -------------------- MODUL PETUGAS --------------------
void loginPetugas() {
    string username, password;
    cout << "\n--- LOGIN PETUGAS ---\n";
    cout << "Username: "; cin >> username;
    cout << "Password: "; cin >> password;

    bool ditemukan = false;
    for(int i = 0; i < jumlahPegawai; ++i) {
        if(daftarPegawai[i].username == username && daftarPegawai[i].password == password) {
            ditemukan = true;
            cout << "\nLogin Berhasil! Selamat bekerja, " << daftarPegawai[i].nama << ".\n";
            dashboardPetugas(daftarPegawai[i]);
            break;
        }
    }
    if(!ditemukan) {
        cout << "\nUsername atau Password Petugas salah!\n";
    }
}

void dashboardPetugas(Pegawai p) {
    int pilihan;
    do {
        cout << "\n=========================================\n";
        cout << "            HALAMAN PETUGAS              \n";
        cout << "            " << p.nama << "\n";
        cout << "=========================================\n";
        cout << "1. Transaksi Pengisian BBM (Layani Pelanggan)\n";
        cout << "2. Cek Transaksi Harian Saya\n";
        cout << "3. Logout\n";
        cout << "-----------------------------------------\n";
        cout << "Pilihan: "; cin >> pilihan;

        switch(pilihan) {
            case 1: transaksiPengisianBBM(p); break;
            case 2: cekTransaksiHarianPetugas(p); break;
            case 3: cout << "\nPetugas keluar sistem.\n"; break;
            default: cout << "\nPilihan tidak valid!\n";
        }
    } while(pilihan != 3);
}

void transaksiPengisianBBM(Pegawai p) {
    cout << "\n--- HALAMAN TRANSAKSI PENGISIAN BBM ---\n";
    cout << "Pilih Jenis BBM Pelanggan:\n";
    for(int i = 0; i < jumlahBBM; ++i) {
        cout << i+1 << ". " << daftarBBM[i].nama << " (Rp " << daftarBBM[i].harga << "/L) - Stok: " << daftarBBM[i].stok << " L\n";
    }
    int nomor;
    cout << "Pilihan BBM (nomor): "; cin >> nomor;
    if(nomor <= 0 || nomor > jumlahBBM) {
        cout << "\nPilihan tidak valid!\n";
        return;
    }

    BBM& bbmDipilih = daftarBBM[nomor-1];
    double liter;
    cout << "Masukkan Jumlah Liter Pengisian: "; cin >> liter;

    if(liter > bbmDipilih.stok) {
        cout << "\nTransaksi Gagal! Stok tidak mencukupi.\n";
        return;
    }

    double totalBayar = liter * bbmDipilih.harga;
    cout << "Total yang harus dibayar: Rp " << totalBayar << endl;
    
    // Form Pembayaran
    double uangBayar;
    cout << "\n--- FORM PEMBAYARAN ---\n";
    cout << "Masukkan Uang Pembayaran: Rp "; cin >> uangBayar;

    if(uangBayar < totalBayar) {
        cout << "Uang tidak cukup! Transaksi dibatalkan.\n";
        return;
    }

    if(jumlahTransaksi >= MAX_TRANSAKSI) {
        cout << "Database transaksi penuh! Transaksi gagal disimpan.\n";
        return;
    }

    // Proses sukses & Potong Stok
    bbmDipilih.stok -= liter;
    double kembalian = uangBayar - totalBayar;

    // Catat Transaksi Tradisional ke Array
    riwayatTransaksi[jumlahTransaksi].tanggal = "18-06-2026";
    riwayatTransaksi[jumlahTransaksi].namaPetugas = p.nama;
    riwayatTransaksi[jumlahTransaksi].namaBBM = bbmDipilih.nama;
    riwayatTransaksi[jumlahTransaksi].liter = liter;
    riwayatTransaksi[jumlahTransaksi].totalBayar = totalBayar;
    jumlahTransaksi++;

    // Cetak Struk Transaksi
    cout << "\n=========================================\n";
    cout << "             STRUK TRANSAKSI SPBU        \n";
    cout << "=========================================\n";
    cout << "Tanggal   : 18-06-2026\n";
    cout << "Petugas   : " << p.nama << "\n";
    cout << "BBM       : " << bbmDipilih.nama << "\n";
    cout << "Harga/L   : Rp " << bbmDipilih.harga << "\n";
    cout << "Jumlah    : " << liter << " Liter\n";
    cout << "-----------------------------------------\n";
    cout << "Total     : Rp " << totalBayar << "\n";
    cout << "Bayar     : Rp " << uangBayar << "\n";
    cout << "Kembali   : Rp " << kembalian << "\n";
    cout << "=========================================\n";
    cout << "      Terima Kasih & Selamat Jalan       \n";
    cout << "=========================================\n";
}

void cekTransaksiHarianPetugas(Pegawai p) {
    cout << "\n--- TRANSAKSI HARIAN OLEH: " << p.nama << " ---\n";
    cout << left << setw(15) << "BBM" << setw(10) << "Liter" << setw(15) << "Total" << endl;
    cout << "-----------------------------------------\n";
    double total = 0;
    for(int i = 0; i < jumlahTransaksi; ++i) {
        if(riwayatTransaksi[i].namaPetugas == p.nama) {
            cout << left << setw(15) << riwayatTransaksi[i].namaBBM << setw(10) << riwayatTransaksi[i].liter << "Rp " << riwayatTransaksi[i].totalBayar << endl;
            total += riwayatTransaksi[i].totalBayar;
        }
    }
    cout << "-----------------------------------------\n";
    cout << "Total Kontribusi Anda Hari Ini: Rp " << total << "\n";
}

// --------------------------------------------
//              MODUL PELANGGAN
// --------------------------------------------

void menuPelanggan() {
    int pilihan;
    do {
        cout << "\n=========================================\n";
        cout << "             MODUL PELANGGAN             \n";
        cout << "=========================================\n";
        cout << "1. Lihat Halaman Informasi BBM & Harga\n";
        cout << "2. Lakukan Pengisian & Pembayaran\n";
        cout << "3. Kembali ke Menu Utama\n";
        cout << "-----------------------------------------\n";
        cout << "Pilihan: "; cin >> pilihan;

        switch(pilihan) {
            case 1: lihatInformasiBBM(); break;
            case 2: {
                int tipePelayanan;
                cout << "\nPilih Metode Pelayanan:\n";
                cout << "1. Melalui Petugas (Dilayani)\n";
                cout << "2. Mandiri (Self-Service)\n";
                cout << "Masukkan pilihan (1-2): ";
                cin >> tipePelayanan;

                if (tipePelayanan == 1) {
                    cout << "\n--- PILIH PETUGAS YANG MELAYANI ---\n";
                    for(int i = 0; i < jumlahPegawai; ++i) {
                        cout << i+1 << ". " << daftarPegawai[i].nama << endl;
                    }
                    int pilihPetugas;
                    cout << "Pilih nomor petugas: "; cin >> pilihPetugas;

                    if (pilihPetugas > 0 && pilihPetugas <= jumlahPegawai) {
                        transaksiPengisianBBM(daftarPegawai[pilihPetugas-1]);
                    } else {
                        cout << "\nPetugas tidak valid! Transaksi dibatalkan.\n";
                    }
                } 
                else if (tipePelayanan == 2) {
                    Pegawai selfService = {"-", "self", "Mesin Mandiri"};
                    transaksiPengisianBBM(selfService);
                } 
                else {
                    cout << "\nPilihan metode tidak valid!\n";
                }
                break;
            }
            case 3: cout << "\nKembali ke menu utama.\n"; break;
            default: cout << "\nPilihan tidak valid!\n";
        }
    } while(pilihan != 3);
}

void lihatInformasiBBM() {
    cout << "\n=========================================\n";
    cout << "            HALAMAN INFORMASI BBM        \n";
    cout << "=========================================\n";
    cout << left << setw(5) << "No" << setw(20) << "Jenis BBM" << setw(15) << "Harga Per Liter" << endl;
    cout << "-----------------------------------------\n";
    for(int i = 0; i < jumlahBBM; ++i) {
        cout << left << setw(5) << i+1 << setw(20) << daftarBBM[i].nama << "Rp " << daftarBBM[i].harga << endl;
    }
    cout << "=========================================\n";
}
