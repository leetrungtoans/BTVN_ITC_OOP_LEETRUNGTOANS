#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;

class GV{
	private:
		char ht[30], bc[15], cn[20];
		int t;
		float bl;
	public:
		void nhap(){
			fflush(stdin);
			cout<<"\t[-]HO VA TEN: ";
			cin.getline(ht, 30);
			cout<<"\t[-]TUOI: ";
			cin>>t;
			fflush(stdin);
			cout<<"\t[-]BANG CAP: ";
			cin.getline(bc, 15);
			cout<<"\t[-]CHUYEN NGANH: ";
			cin.getline(cn, 20);
			cout<<"\t[-]BAC LUONG: ";
			cin>>bl;
		}
		
		void xuat(){
			cout<<setw(30)<<left<<ht
				<<setw(15)<<t
				<<setw(20)<<bc
				<<setw(20)<<cn
				<<setw(20)<<tinhLuong()<<endl;
		}
		
		float tinhLuong(){
			return bl*610.0;
		}
		
		char* getCn(){
			return this->cn;
		}
};

void tieuDe(){
	cout<<setw(30)<<left<<"HO VA TEN"
		<<setw(15)<<"TUOI"
		<<setw(20)<<"BANG CAP"
		<<setw(20)<<"CHUYEN NGANH"
		<<setw(20)<<"LUONG CO BAN"<<endl;
}

void nhapDS(GV *gv, int n){
	for(int i=0; i<n; i++){
		cout<<"NHAP THONG TIN GIAO VIEN THU "<<i+1<<endl;
		gv[i].nhap();
	}
}

void xuatDS(GV *gv, int n){
	tieuDe();
	for(int i=0; i<n; i++){
		gv[i].xuat();
	}
}

void gvNgheo(GV *gv, int n){
	bool check = false;
	for(int i=0; i<n; i++){
		if(gv[i].tinhLuong()<2000){
			check = true;
		}
	}
	if(check){
		cout<<"\n\t\tDANH SACH GIAO VIEN CO LUONG < 2000\n";
		tieuDe();
		for(int i=0; i<n; i++){
			if(gv[i].tinhLuong()<2000){
				gv[i].xuat();
			}
		}
	}else cout<<"\n\t\tKhong co giao vien co luong < 2000";
}

void sapXep(GV *gv, int n){
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(strcmpi(gv[i].getCn(), gv[j].getCn()) == 1){
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
	cout<<"\t\t\tDANH SACH GIAO VIEN\n";
	xuatDS(gv, n);
	gvNgheo(gv, n);
	cout<<"\n\t\tDANH SACH GIAO VIEN SAP XEP THEO CHUYEN NGANH\n";
	sapXep(gv, n);
	
	delete gv;
	return 0;
}

