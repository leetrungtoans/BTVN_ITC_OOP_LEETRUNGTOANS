#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;

class Nguoi{
	private:
		char ten[30];
		int tuoi;
		float diemTB;
	public:
		Nguoi(){
			strcpy(this->ten, "");
			this->tuoi = 0;
			this->diemTB = 0.0;
		}
		
		Nguoi(char *ten, int tuoi, float diemTB){
			strcpy(this->ten, ten);
			this->tuoi = 0;
			this->diemTB = 0.0;
		}
		
		~Nguoi(){}
		
		void nhap(){
			fflush(stdin);
			cout<<"\t[-]HO VA TEN: ";
			cin.getline(ten, 30);
			cout<<"\t[-]TUOI: ";
			cin>>tuoi;
			cout<<"\t[-]DIEM TRUNG BINH: ";
			do{
				cin>>diemTB;
				if(diemTB<0 || diemTB>10){
					cout<<"\tNhap lai: ";
				}
			}while(diemTB<0 || diemTB>10);
		}
		
		void xuat(){
			cout<<setw(30)<<left<<ten
				<<setw(15)<<tuoi
				<<setw(20)<<diemTB
				<<setw(20)<<xetDh()<<endl;
		}
		
		char *xetDh(){
			if(diemTB >= 8){
				return "Gioi";
			}else if(diemTB>=7){
				return "Kha";
			}else if(diemTB>=5){
				return "Trung binh";
			}else{
				return "Kem";
			}
		}
		
		char* getTen(){
			return this->ten;
		}
		
		void setDiemTB(float diemTB){
			this->diemTB = diemTB;
		}
		
		float getDiemTB(){
			return this->diemTB;
		}
};

void nhapDS(Nguoi *ng, int n){
	for(int i=0; i<n; i++){
		cout<<"Nhap thong tin nguoi thu "<<i+1<<endl;
		ng[i].nhap();
	}
}

void tieuDe(){
	cout<<setw(30)<<left<<"HO VA TEN"
		<<setw(15)<<"TUOI"
		<<setw(20)<<"DIEM TRUNG BINH"
		<<setw(20)<<"DANH HIEU"<<endl;
}

void xuatDS(Nguoi *ng, int n){
	tieuDe();
	for(int i=0; i<n; i++){
		ng[i].xuat();
	}
}

void sapXepTen(Nguoi *ng, int n){
	for(int i=0 ;i<n; i++){
		for(int j=i+1; j<n; j++){
			if(strcmp(ng[i].getTen(), ng[j].getTen()) == 1){
				swap(ng[i], ng[j]);
			}
		}
	}
	xuatDS(ng, n);
}

void searchName(Nguoi *ng, int n){
	bool check = false;
	for(int i=0; i<n; i++){
		if(strcmpi(ng[i].getTen(), "Nguyen Van A") == 0){
			ng[i].setDiemTB(10);
			check = true;
		}
	}
	if(check){
		cout<<"\nSua diem thanh cong.\n";
		tieuDe();
		for(int i=0; i<n; i++){
			if(strcmpi(ng[i].getTen(), "Nguyen Van A") == 0){
				ng[i].xuat();
			}
		}
	}else{
		cout<<"\nKhong co ai trong danh sach co ten Nguyen Van A.\n";
	}
}

int main(){
	int n;
	cout<<"Nhap so luong nguoi: ";
	do{
		cin>>n;
		if(n<=0){
			cout<<"\tNhap lai: ";
		}
	}while(n<=0);
	Nguoi *ng = new Nguoi[n];
	nhapDS(ng, n);
	system("pause");
	system("cls");
	cout<<"\tDANH SACH DA NHAP\n";
	xuatDS(ng, n);
	cout<<"\n\tDANH SACH SAP XEP\n";
	sapXepTen(ng, n);
	searchName(ng, n);

	return 0;
}

