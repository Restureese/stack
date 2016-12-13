#include <iostream>
#include <cstdlib>

using namespace std;

const int MAX = 5;

typedef int element;
struct StackRecord{
	int top;
	element StackInfo[MAX];
	element StackArray[MAX]; //array stack
};

typedef StackRecord Stack;

void initStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S,element value,element info);
element pop(Stack &S);
void printStack(Stack S);
void ListBuku();
void hitungWaktu(Stack S);
void Waktu(Stack S,int total);

int perHal;

int main(){
	element hal;
	int book;
	int menit,jam,totWaktu;
	int pilih;
	int jmlBuku;
	string ulang;
	Stack buku;
	initStack(buku);

	do{
		ulang:
		cout<<"==========================================================================="<<endl;
		cout<<"\t\"Menghitung Banyak Waktu Yang Dibutuhkan Untuk Membaca Buku\""<<endl;
		cout<<"\t\t\"Dalam Sebuah Tumpukan Buku Perpustakaan\""<<endl;
		cout<<"==========================================================================="<<endl;
		cout<<"1. Pinjam Buku"<<endl;
		cout<<"2. Hitung Halaman Yang Sudah Terbaca"<<endl;
		cout<<"3. Tampilkan Waktu"<<endl;
		cout<<"0. Keluar"<<endl;
		cout<<"==========================================================================="<<endl;
		cout<<"Pilih Menu : ";
		cin>>pilih;
		switch(pilih){
			case 1:
				cout<<"Masukkan jumlah Buku [MAX 5]: ";
				cin>>jmlBuku;
				for(int x = 0; x < jmlBuku;x++){
					ListBuku();
					cout<<"Pilih Buku Yang Akan Dipinjam : ";
					cin>>book;
					if(book==1)
						push(buku,1127,1);
					else if(book==2)
						push(buku,1220,2);
					else if(book==3)
						push(buku,567,3);
					else if(book==4)
						push(buku,982,4);
					else if(book==5)
						push(buku,748,5);
					else
					 	cout<<"Buku Yang Anda Pilih Tidak Tersedia"<<endl;
				}
				system("clear");
				goto ulang;
				break;
			case 2:
				cout<<"Masukkan Jam\t: ";
				cin>>jam;
				cout<<"Masukkan Menit\t: ";
				cin>>menit;
				totWaktu = jam * 60 + menit;
				Waktu(buku,totWaktu);
				system("clear");
				goto ulang;
				break;
			case 3:
				cout<<"Masukkan waktu rata - rata membaca per halaman : ";
				cin>>perHal;
				hitungWaktu(buku);
				system("clear");
				goto ulang;
				break;
			case 0:
				cout<<"Terima Kasih ^_^"<<endl;
				break;
			default:
				cout<<"Menu Yang anda pilih tidak tersedia"<<endl;
		}
	}while(pilih != 0);

	return 0;
}

void initStack(Stack &S){
	S.top = -1;
}

bool isEmpty(Stack S){
	return S.top == -1;
}

bool isFull(Stack S){
	return S.top == MAX - 1;
}

void push(Stack &S,element value,element info){
	if(isFull(S)){
		cout<<"Stack Penuh !"<<endl;
	}else{
		S.top++;
		S.StackInfo[S.top] = info;
		S.StackArray[S.top] = value;
	}
}

element pop(Stack &S){
	element temp;
	if(isEmpty(S)){
		cout<<"Stack Masih Kosong !"<<endl;
	}else{
		temp = S.StackArray[S.top];
		S.top--;
	}
	return temp;
}

void printStack(Stack S){
	element value;
	if(isEmpty(S)){
		cout<<"Stack Masih Kosong!"<<endl;
	}else{
		while(S.top!=-1){
			value = pop(S);
			cout<<"||"<<value<<"||"<<endl;
		}
		cout<<"===="<<endl;
	}
}

void ListBuku(){
	cout<<"1. Algortima Pemrograman 1127 Halaman"<<endl;
	cout<<"2. Make Your Aplication With Pyhon 1220 Halaman"<<endl;
	cout<<"3. Tutorial Membuat Web Dengan Django 567 Halaman"<<endl;
	cout<<"4. Object Oriented Programming 982 Halaman"<<endl;
	cout<<"5. Linux Administation 748 Halaman"<<endl;
}

void hitungWaktu(Stack S){
	int total = 0;
	int jam = 0;
	int menit = 0; //menit
	while(S.top != -1){
		total += pop(S);

	}
	total*=perHal;

	jam = total / 60;
	menit = total % 60;
	cout<<jam<<" Jam "<<menit<<" menit"<<endl;
}

void Waktu(Stack S,int total){
	if(total< S.StackArray[S.top]*perHal){
		cout<<"Masih Membaca Buku No-"<<S.StackInfo[S.top]<<endl;
		cout<<"Tersisa "<<S.StackArray[S.top] - (total/perHal)<<" Halaman"<<endl;
	}else{
		total -= S.StackArray[S.top]*perHal;
		S.top--;
		Waktu(S,total);
	}
}