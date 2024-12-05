#include <iostream>
using namespace std;

struct Mahasiswa
{
    string nama;
    int nim;
    string jurusan;
    float ipk;
};

void inputData(Mahasiswa *&mahasiswa, int &jumlahMahasiswa)
{
    cout << "Masukkan Jumlah Mahasiswa: ";
    cin >> jumlahMahasiswa;
    cin.ignore();
    mahasiswa = new Mahasiswa[jumlahMahasiswa];

    for (int i = 0; i < jumlahMahasiswa; i++)
    {
        cout << endl;
        cout << "Data Mahasiswa ke-" << (i + 1) << ":" << endl;
        cout << "Masukkan Nama Mahasiswa: ";
        getline(cin, mahasiswa[i].nama);
        cout << "Masukkan NIM Mahasiswa: ";
        cin >> mahasiswa[i].nim;
        cin.ignore();
        cout << "Masukkan Jurusan Mahasiswa: ";
        getline(cin, mahasiswa[i].jurusan);
        cout << "Masukkan IPK Mahasiswa: ";
        cin >> mahasiswa[i].ipk;
        cin.ignore();
    }
}

void tampilData(Mahasiswa *mahasiswa, int jumlahMahasiswa)
{
    cout << "\nData Mahasiswa:" << endl;
    for (int i = 0; i < jumlahMahasiswa; i++)
    {
        cout << "\nData Mahasiswa ke-" << (i + 1) << ":" << endl;
        cout << "Nama Mahasiswa: " << mahasiswa[i].nama << endl;
        cout << "NIM Mahasiswa: " << mahasiswa[i].nim << endl;
        cout << "Jurusan Mahasiswa: " << mahasiswa[i].jurusan << endl;
        cout << "IPK Mahasiswa: " << mahasiswa[i].ipk << endl;
    }
}

void hitungRataipk(Mahasiswa *mahasiswa, int jumlahMahasiswa)
{
    if (jumlahMahasiswa > 0)
    {
        float totalipk = 0;
        for (int i = 0; i < jumlahMahasiswa; i++)
        {
            totalipk += mahasiswa[i].ipk;
        }

        float rataipk = totalipk / jumlahMahasiswa;
        cout << "\nRata-rata ipk: " << rataipk << endl;
    }
    else
    {
        cout << "Belum ada data mahasiswa untuk dihitung." << endl;
    }
}

int main()
{
    int pilih;
    int jumlahMahasiswa = 100;
    Mahasiswa *mahasiswa;

    do
    {
        cout << "\n===SELAMAT DATANG===" << endl;
        cout << "Silahkan Pilih Menu:" << endl;
        cout << "1. Input Data Mahasiswa" << endl;
        cout << "2. Tampilkan Data Mahasiswa" << endl;
        cout << "3. Hitung Rata-rata IPK" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore();

        switch (pilih)
        {
        case 1:
            inputData(mahasiswa, jumlahMahasiswa);
            system("cls");
            break;
        case 2:
            if (jumlahMahasiswa > 0)
            {
                tampilData(mahasiswa, jumlahMahasiswa);
            }
            else
            {
                cout << "Belum ada data mahasiswa yang diinput." << endl;
            }
            system("cls");
            break;
        case 3:
            hitungRataipk(mahasiswa, jumlahMahasiswa);
            system("cls");
            break;
        case 4:
            cout << "Terima Kasih" << endl;
            break;
        default:
            cout << "Pilihan tidak valid, silahkan coba lagi." << endl;
            break;
        }
    } while (pilih != 4);
}
