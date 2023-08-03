#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

class GV{
	private:
		char hoTen[30], bangCap[15], chuyenNganh[20];
		int tuoi;
		float bacLuong;
	public:
		friend istream& operator >> (istream &is, GV &gv){
			cout<<"\t[-]HO VA TEN: ";
			fflush(stdin);
			is.getline(gv.hoTen, 30);
			cout<<"\t[-]TUOI: ";
			is>>gv.tuoi;
			cout<<"\t[-]BANG CAP: ";
			fflush(stdin);
			is.getline(gv.bangCap, 15);
			cout<<"\t[-]CHUYEN NGANH: ";
			is.getline(gv.chuyenNganh, 20);
			cout<<"\t[-]BAC LUONG: ";
			is>>gv.bacLuong;
			return is;
		}
		
		friend ostream& operator << (ostream &os, GV gv){
			os<<setw(30)<<left<<gv.hoTen
				<<setw(15)<<gv.tuoi
				<<setw(15)<<gv.bangCap
				<<setw(20)<<gv.chuyenNganh
				<<setw(20)<<gv.tinhLuong()<<endl;
			return os;
		}
		
		float tinhLuong(){
			return bacLuong*610;
		}
		
		bool operator == (GV gv){
			return strcmp(this->bangCap, gv.bangCap) == 0;
		}
		
		bool operator > (GV gv){
			return strcmp(this->bangCap, gv.bangCap) == 1;
		}
};

void nhapDS(GV *gv, int n){
	for(int i=0; i<n; i++){
		cout<<"NHAP THONG TIN GIAO VIEN THU "<<i+1<<endl;
		cin>>gv[i];
	}
}

void tieuDe(){
	cout<<setw(30)<<left<<"HO VA TEN"
		<<setw(15)<<"TUOI"
		<<setw(15)<<"BANG CAP"
		<<setw(20)<<"CHUYEN NGANH"
		<<setw(20)<<"LUONG CO BAN"<<endl;
}

void xuatDS(GV *gv, int n){
	tieuDe();
	for(int i=0; i<n; i++){
		cout<<gv[i];
	}
}

void sapXep(GV *gv, int n){
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(gv[i]>gv[j]){
				swap(gv[i], gv[j]);
			}
		}
	}
	xuatDS(gv, n);
}

int main(){
	int n;
	cout<<"Nhap so luong Giao vien: ";
	do{
		cin>>n;
		if(n<=0){
			cout<<"\tNhap lai: ";
		}
	}while(n<=0);
	GV *gv = new GV[n];
	nhapDS(gv, n);
	system("pause");
	system("cls");
	cout<<"\t\tDANH SACH GIAO VIEN\n";
	xuatDS(gv, n);
	cout<<"\n\n\tDANH SACH GIAO VIEN DUOC SAP XEP THEO BANG CAP\n";
	sapXep(gv, n);
	
	delete gv;
	return 0;
}

