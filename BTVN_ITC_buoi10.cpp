#include<iostream>
using namespace std;

struct date{
	int ngay, thang, nam;
};

class docGia{
	protected:
		string maSach, tenSach, tacGia, tenNguoiThue;
		int tuoi;
		date ngayThue, ngayTra;
	public:
		virtual void nhap(){
			cout<<"\t[-] MA SACH: ";
			cin>>maSach;
			fflush(stdin);
			cout<<"\t[-] TEN SACH: ";
			getline(cin, tenSach);
			cout<<"\t[-] TEN TAC GIA: ";
			getline(cin, tacGia);
			cout<<"\t[-] NGUOI THUE: ";
			getline(cin, tenNguoiThue);
			cout<<"\t[-] NGAY THUE: \n";
			do{
				cout<<"\t\t Ngay: ";
				cin>>ngayThue.ngay;
				cout<<"\t\t Thang: ";
				cin>>ngayThue.thang;
				if(ngayThue.ngay < 1 || ngayThue.ngay >31 || ngayThue.thang < 1 || ngayThue.thang > 12){
					cout<<"\tNHAP LAI:\n";
				}
			}while(ngayThue.ngay < 1 || ngayThue.ngay >31 || ngayThue.thang < 1 || ngayThue.thang > 12);
			cout<<"\t\t Nam: ";
			cin>>ngayThue.nam;
			bool check;
			do{
				check = false;
				do{
					cout<<"\t[-] NGAY TRA: \n";
					cout<<"\t\t Ngay: ";
					cin>>ngayTra.ngay;
					cout<<"\t\t Thang: ";
					cin>>ngayTra.thang;
					if(ngayTra.ngay < 1 || ngayTra.ngay >31 || ngayTra.thang < 1 || ngayTra.thang > 12){
						cout<<"\tNHAP LAI:\n";
					}
				}while(ngayTra.ngay < 1 || ngayTra.ngay >31 || ngayTra.thang < 1 || ngayTra.thang > 12);
				cout<<"\t\t Nam: ";
				cin>>ngayTra.nam;
				
				if(ngayTra.nam < ngayThue.nam){
					check = true;
				}else if(ngayTra.nam == ngayThue.nam){
					if(ngayTra.thang < ngayThue.thang){
						check = true;
					}else if(ngayTra.thang == ngayThue.thang){
						if(ngayTra.ngay <= ngayThue.ngay){
							check = true;
						}
					}
				}
			}while(check);
		}
		
		virtual void xuat(){
			cout<<"\t\t[-] MA SACH: "<<maSach
				<<"\n\t\t[-] TEN SACH: "<<tenSach
				<<"\n\t\t[-] TEN TAC GIA: "<<tacGia
				<<"\n\t\t[-] TEN NGUOI THUE: "<<tenNguoiThue
				<<"\n\t\t[-] TUOI: "<<tuoi
				<<"\n\t\t[-] NGAY THUE: "<<ngayThue.ngay<<"/"<<ngayThue.thang<<"/"<<ngayThue.nam
				<<"\n\t\t[-] NGAY TRA: "<<ngayTra.ngay<<"/"<<ngayTra.thang<<"/"<<ngayTra.nam<<endl;
		}
		
		void setTuoi(int x){
			this->tuoi = x;
		}
		
		int getTuoi(){
			return this->tuoi;
		}
		
		int demNgay(){
			return (ngayTra.nam - ngayThue.nam) * 365 + (ngayTra.thang - ngayThue.thang) * 30 + (ngayTra.ngay - ngayThue.ngay);
		}
		
		virtual bool phanLoai() = 0;
		
		string getTacGia(){
			return this->tacGia;
		}
};

class treEm : public docGia{
	private:
		string nguoiGiamHo;
	public:
		void nhap(){
			docGia::nhap();
			cout<<"\t[-] NGUOI GIAM HO: ";
			fflush(stdin);
			getline(cin, nguoiGiamHo);
		}
		
		void xuat(){
			docGia::xuat();
			cout<<"\t\t[-] NGUOI GIAM HO: "<<nguoiGiamHo<<endl;
		}
		
		bool phanLoai(){
			return true;
		}
};

class nguoiLon : public docGia{
	private:
		string CCCD;
	public:
		void nhap(){
			docGia::nhap();
			cout<<"\t[-] SO CAN CUOC CONG DAN: ";
			cin>>CCCD;
		}
		
		void xuat(){
			docGia::xuat();
			cout<<"\t\t[-] SO CCCD: "<<CCCD<<endl;
		}
		
		bool phanLoai(){
			return false;
		}
};

class quanLyDanhSach{
	private:
		docGia *a[50];
		int n;
	public:
		void nhapDS(){
			cout<<"Nhap so luong benh nhan: ";
			do{
				cin>>n;
				if(n<=0){
					cout<<"Khong hop le, nhap lai: ";
				}
			}while(n<=0);
			for(int i=0; i<n; i++){
				cout<<"NHAP THONG TIN DOC GIA THU "<<i+1<<endl;
				int x;
				cout<<"\t[-]NHAP TUOI: ";
				cin>>x;
				
				if(x < 16){
					a[i] = new treEm();
				}else{
					a[i] = new nguoiLon();
				}
				a[i]->setTuoi(x);
				a[i]->nhap();
			}
		}
		
		void xuatDS(){
			cout<<"DANH SACH DOC GIA\n";
			for(int i=0; i<n; i++){
				cout<<"\t[+] Thong tin doc gia thu "<<i+1<<(a[i]->getTuoi() >= 16 ? "(Nguoi lon)" : "(Tre em)")<<endl;
				a[i]->xuat();
				cout<<"Thue trong "<<a[i]->demNgay()<<" ngay\n\n";
			}
		}
		
		void tinhTien(){
			int tongTienTre = 0, tongTienGia=0;
			for(int i=0; i<n; i++){
				if(a[i]->phanLoai()){
					tongTienTre += 2000*a[i]->demNgay();
				}else{
					tongTienGia += 3000*a[i]->demNgay();
				}
			}
			cout<<"\n\t TONG TIEN DOC GIA TRE EM: "<<tongTienTre<<endl;
			cout<<"\t TONG TIEN DOC GIA NGUOI LON: "<<tongTienGia<<endl;
		}
		
		void sapXep(){
			for(int i=0; i<n-1; i++){
				for(int j=i+1; j<n; j++){
					if(a[i]->getTacGia() > a[j]->getTacGia()){
						swap(a[i], a[j]);
					}
				}
			}
			xuatDS();
		}
};

int main(){
	quanLyDanhSach *ql = new quanLyDanhSach();
	ql->nhapDS();
	system("pause");
	system("cls");
	ql->xuatDS();
	system("pause");
	system("cls");
	ql->tinhTien();
	system("pause");
	system("cls");
	cout<<"DA SAP XEP THEO TEN TAC GIA\n\n";
	ql->sapXep();
	
	delete ql;
	return 0;
}

