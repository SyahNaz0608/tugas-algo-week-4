# Sistem Pendataan KTP (C++)

Program *Command Line Interface* (CLI) berbasis C++ untuk mengelola data Kartu Tanda Penduduk (KTP). Aplikasi ini menyimulasikan operasi input, pembacaan, dan penghapusan data KTP menggunakan struktur data `struct` dan *dynamic array* (`std::vector`).

Tampilan *output* data dirancang agar menyerupai tata letak blangko KTP fisik.

## Fitur Utama

- **Input Data KTP**: Mengisi 18 atribut data KTP secara berurutan (Provinsi, NIK, Nama, Gol. Darah, dll) menggunakan perulangan array untuk efisiensi kode.
- **Tampilkan Data KTP**: Mencetak seluruh data yang tersimpan di dalam memori dengan *layout* visual (ASCII art) yang rapi dan mirip dengan KTP asli.
- **Hapus Data**: Menghapus data spesifik dari memori berdasarkan nomor indeks.

## Prasyarat

- *Compiler* C++ (contoh: GCC/G++, Clang, atau MSVC).
- Mendukung standar C++11 atau lebih baru (karena menggunakan *range-based for loop*).

## Panduan Penggunaan

1. Input: `1` Isi formulir KTP baris demi baris. Tekan Enter tanpa teks untuk mengosongkan kolom.
2. Tampil: `2` Melihat daftar KTP. Catat "Nomor Data" `=== DATA KE-1 ===` jika ingin melakukan penghapusan.
3. Hapus: Ketik `3` lalu masukkan `Nomor Data` yang ingin dihapus dari sistem.
4. Keluar: Ketik `4` untuk mengakhiri sesi. Memori data akan otomatis dihapus oleh sistem setelah program ditutup.

## Penjelasan Kode

1. Library yang digunakan

    - `<iostream>` : Mengelola input/output standar (`cin` & `cout`).
    - `<vector>` : Mengelola dynamic array yang ukurannya bisa bertambah atau berkurang otomatis saat data ditambah atau dihapus.
    - `<string>` : Menangani tipe data teks untuk mendukung spasi dan karakter khusus pada input.

2. Variabel Global & Struktur Data

    - `const int JUMLAH_KOLOM = 18;` : Menetapkan jumlah pasti atribut KTP untuk membatasi perulangan.
    - `const string LABEL[]` : Array statis yang menyimpan nama tiap kolom (Provinsi, NIK, dll). Berfungsi menghilangkan penulisan hardcode saat meminta input.
    - `struct KTP` : Struktur data yang membungkus array `string data[18]`. Setiap indeks array ini dipetakan secara presisi agar selaras dengan `LABEL`.

3. Fungsi `tambahData` : Merekam entri baru ke dalam sistem.

    - `cin.ignore()` : Menghapus sisa enter (`\n`) dari menu sebelumnya agar fungsi baca teks tidak terlewati otomatis.
    - Menggunakan `for` loop untuk mencetak label dari array `LABEL` dan membaca input pengguna dengan `getline()`.
    - `db.push_back(k)` : Menambahkan `struct KTP` yang sudah terisi ke posisi paling akhir di dalam `vector`.

4. Fungsi `tampilkanData` : Mencetak data dalam format menyerupai kartu KTP fisik.

    - Memvalidasi isi memori dengan `db.empty()`.
    - Menggunakan *range-based* for loop `for (const auto& k : db)` untuk membaca setiap elemen vektor dengan efisien.
    - Mencetak variabel berdasarkan pemetaan indeks (contoh: `k.data[0]` untuk Provinsi, `k.data[6]` untuk Golongan Darah) di dalam kerangka ASCII art.

5. Fungsi `hapusData` : Menghilangkan satu entri spesifik.

    - Meminta input `index` berupa nomor urut data.
    - Memvalidasi batasan indeks: `if (index >= 1 && index <= db.size())`.
    - Menggunakan `db.erase(db.begin() + index - 1)` untuk menghapus elemen. Dikurangi 1 karena nomor urut tampilan dimulai dari 1, sedangkan indeks memori (array) dimulai dari 0.

6. Fungsi Utama `main` : Pusat kendali operasional program.

    - Mendeklarasikan `vector<KTP> db` sebagai wadah memori lokal (*database* sementara).
    - Menjalankan menu interaktif dalam blok `do-while` hingga pengguna memilih opsi `4` (Keluar).
