#include <iostream>
using namespace std;

class node
{
public:
    int noMhs;
    node *next;
};

class linkedlist
{ node *START;

public:
linkedlist()
    {
        START = NULL;
    }

 void addnode()
    {
        int nim;
        cout << "\nMasukkan Nomor Mahasiswa";
        cin >> nim;
    
        node *nodebaru = new node;
        nodebaru->noMhs = nim;

        if (START == NULL || nim <= START ->noMhs)
        {
            if ((START != NULL) && (nim == START->noMhs))
            {
                cout << "\nDuplikasi nomhs tidak diijinkan|n";
                return;
            }
            nodebaru->next = START;
            START = nodebaru;
            return;
        }

        node *previous = START;
        node *current = START;

 while ((current != NULL) && (nim >= current->noMhs))
    {
        if (nim == current->noMhs)
        {
            cout << "\nDuplikasi noMhs tidak diijinkan\n";
            return;
        }
        previous = current;
        current = current->next;
    }
        nodebaru->next = current;
        previous->next = nodebaru;
    }

    bool listempty()
    {
        return (START == NULL);
    }

    bool search(int nim, node ** previous, node **current)
    {
        *previous = START;
        *current = START;

        while ((*current != NULL) && (nim != (*current)->noMhs))
        {
            *previous = *current;
            *current = (*current)->next;
        }

        return (*current != NULL);   
    }

   bool delnode(int nim)
    {
        node *current, *previous;
        if (!search (nim, &previous, &current))
            return false;

        if (current == START)
            START = START->next;
         else
            previous->next = current->next;

        delete current;
        return true;
    }

    void traverse()
    {
        if (listempty())
        {
            cout << "\nList Kosong\n";
        }
        else
        {
            cout <<"\nData didalam list adalah:\n";
            node *currentnode = START;
            while (currentnode != NULL)
            {
                cout << currentnode->noMhs << endl;
                currentnode = currentnode->next;
            }
            cout << endl;    
        }
    }
};

int main()
{
    linkedlist mhs;
    int pil;
    char ch;
    int nim;

    do
    {
        cout << endl;
        cout << "menu";
        cout << endl;
        cout << "1. Menambah data kedalam list" << endl;
        cout << "2. Menghapus data dari dalam list" << endl;
        cout << "3. Menampilkan semuda data didalam list" << endl;
        cout << "4. Menampilkan semua data didalam list secara terbalik" << endl;
        cout << "5. Mencari data dalam list" << endl;
        cout << "6. keluar" << endl;
        cout << endl
        << "Masukkan pilihan (1-5): ";
        cin >> ch;
        switch (ch)
     {
        case 1 :
        {
            mhs.addnode();
        }
        break;

        case 2 :
        {
            if (mhs.listempty())
            {
                cout << endl;
                cout << "list kosong" << endl;
                break;
            }
            cout << endl
                 << "\nMasukkan no mahasiswa yang akan dihapus : ";
                cin >> nim;
            if (mhs.delnode(nim) == false)
                cout << endl
                     << "Data tidak ditemukan" << endl
            << "Data tidak ditemukan" << endl;

            else 
            {
                cout << endl
                    << "Data dengan nomor mahasiswa" << nim
                    << "berhasil dihapus" << endl;
            }
        }
        break;
        
        case '3':
        {
            mhs.traverse();
        }
        break;

        case '4':
        {
            if (mhs.listempty() == true)
            {
                cout << "\nList Kosong\n";
                break;
            }
            node *previous, *current;
            cout << endl
                 << "Masukkan no mahasiswa yang dicari : ";
            cin >> nim;
            if (mhs.search(nim, &previous, &current) == false)
                cout << endl
                     << "Data tidak ditemukan" << endl;
            else
            {
                cout << endl
                     << "Data ditemukan" << endl;
                cout << "\nNo Mahasiswa: " << current->noMhs << endl;
                cout << "\n";
            }
        }

        break;

        case '5':
        {
        }
        break;
        default:
        {
            cout << "Pilihan salah !" << endl;
        }
        break;
        }
    } while (ch != '5');
}