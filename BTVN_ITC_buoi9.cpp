#include<iostream>
#include<string>
using namespace std;

struct date{
	int ngay, thang, nam;
};

//bool namNhuan(int nam){
//	return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
//}
//
//bool check

class benhNhan{
	protected:
		string maHS, hoTen, chuanDoan;
		date ngaySinh;
	public:
		void nhap(){
			cout<<"\t[-]MA HO SO: ";
			cin>>maHS;
			cout<<"\t[-]HO VA TEN: ";
			fflush(stdin);
			getline(cin, hoTen);
			
			cout<<"\t[-]NGAY SINH: \n";
			cout<<"\t\t[-]Ngay: ";
			cin>>ngaySinh.ngay;
			cout<<"\t\t[-]Thang: ";
			cin>>ngaySinh.thang;
			cout<<"\t\t[-]Nam: ";
			cin>>ngaySinh.nam;
			
			cout<<"\t[-]CHUAN DOAN BENH: ";
			fflush(stdin);
			getline(cin, chuanDoan);
		}
		
		virtual void xuat(){
			cout<<"\t[-]MA HO SO: "<<maHS
				<<"\n\t[-]HO VA TEN: "<<hoTen
				<<"\n\t[-]NGAY SINH: "<<ngaySinh.ngay<<"/"<<ngaySinh.thang<<"/"<<ngaySinh.nam
				<<"\n\t[-]CHUAN DOAN BENH: "<<chuanDoan<<endl;
		}
		
		date getNgaySinh(){
			return this->ngaySinh;
		}
};

class noiTru : public benhNhan{
	private:
		date ngayNV, ngayRV;
		string tenKhoa;
		int soGiuong;
	public:
		void nhap(){
			benhNhan::nhap();
			cout<<"\t[-]NGAY NHAP VIEN: \n";
			cout<<"\t\t[-]Ngay: ";
			cin>>ngayNV.ngay;
			cout<<"\t\t[-]Thang: ";
			cin>>ngayNV.thang;
			cout<<"\t\t[-]Nam: ";
			cin>>ngayNV.nam;
			
			cout<<"\t[-]NGAY XUAT VIEN: \n";
			cout<<"\t\t[-]Ngay: ";
			cin>>ngayRV.ngay;
			cout<<"\t\t[-]Thang: ";
			cin>>ngayRV.thang;
			cout<<"\t\t[-]Nam: ";
			cin>>ngayRV.nam;
			
			cout<<"\t[-]TEN KHOA: ";
			fflush(stdin);
			getline(cin, tenKhoa);
			cout<<"\t[-]SO GIUONG: ";
			cin>>soGiuong;
		}
		
		void xuat(){
			benhNhan::xuat();
			cout<<"\t[-]NGAY NHAP VIEN: "<<ngayNV.ngay<<"/"<<ngayNV.thang<<"/"<<ngayNV.nam
				<<"\n\t[-]NGAY XUAT VIEN: "<<ngayRV.ngay<<"/"<<ngayRV.thang<<"/"<<ngayRV.nam
				<<"\n\t[-]TEN KHOA: "<<tenKhoa
				<<"\n\t[-]SO GIUONG: "<<soGiuong<<endl;
		}
};

class ngoaiTru : public benhNhan{
	private:
		date ngayChuyen;
		string noiChuyen;
	public:
		void nhap(){
			benhNhan::nhap();
			
			cout<<"\t[-]NGAY CHUYEN: \n";
			cout<<"\t\t[-]Ngay: ";
			cin>>ngayChuyen.ngay;
			cout<<"\t\t[-]Thang: ";
			cin>>ngayChuyen.thang;
			cout<<"\t\t[-]Nam: ";
			cin>>ngayChuyen.nam;
			
			cout<<"\t[-]Noi chuyen: ";
			fflush(stdin);
			getline(cin, noiChuyen);
		}
		
		void xuat(){
			benhNhan::xuat();
			cout<<"\t[-]NGAY CHUYEN: "<<ngayChuyen.ngay<<"/"<<ngayChuyen.thang<<"/"<<ngayChuyen.nam
				<<"\n\t[-]NOI CHUYEN: "<<noiChuyen<<endl;
		}
};

void nhapNoiTru(noiTru *a, int n){
	for(int i=0; i<n; i++){
		
	}
}

int main(){
	int n;
	
	benhNhan *a = new benhNhan[20];
	
	menuNhap(a, n);
	system("pause");
	system("cls");
	menuXuat(a, n);
	
	delete a;
	return 0;
}

