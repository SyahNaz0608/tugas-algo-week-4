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

## Cara Instalasi & Menjalankan