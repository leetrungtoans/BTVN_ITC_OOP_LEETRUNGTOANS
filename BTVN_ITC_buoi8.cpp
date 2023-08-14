
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Nguoi{
	protected:
		string name;
		int birth;
	public:
		friend istream& operator >> (istream& in, Nguoi &a){
			cout<<"Nhap ho va ten: ";
			fflush(stdin);
			getline(in, a.name);
			cout<<"Nhap nam sinh: ";
			in>>a.birth;
			return in;
		}
		
		friend ostream& operator << (ostream& out, Nguoi a){
			out<<"Ho va ten: "<<a.name
				<<"\nNam sinh: "<<a.birth<<endl;
			return out;
		}
};

class thiSinh : public Nguoi{
	private:
		string ID;
		float Toan, ly, hoa;
	public:
		friend istream& operator >> (istream &in, thiSinh &a){
			in>>(Nguoi&)a;
			cout<<"Nhap so bao danh: ";
			in>>a.ID;
			cout<<"Nhap diem Toan: ";
			do{
				in>>a.Toan;
				if(a.Toan<0 || a.Toan>10){
					cout<<"\tNhap lai: ";
				}
			}while(a.Toan<0 || a.Toan>10);
			cout<<"Nhap diem ly: ";
			do{
				in>>a.ly;
				if(a.ly<0 || a.ly>10){
					cout<<"\tNhap lai: ";
				}
			}while(a.ly<0 || a.ly>10);
			cout<<"Nhap diem hoa: ";
			do{
				in>>a.hoa;
				if(a.hoa<0 || a.hoa>10){
					cout<<"\tNhap lai: ";
				}
			}while(a.hoa<0 || a.hoa>10);
			return in;
		}
		
		friend ostream& operator << (ostream& out, thiSinh a){
			out<<(Nguoi)a;
			out<<"So bao danh: "<<a.ID
				<<"\nDiem Toan: "<<a.Toan
				<<"\nDiem ly: "<<a.ly
				<<"\nDiem hoa: "<<a.hoa
				<<"\nTong diem: "<<a.tongDiem()<<endl;
			return out;
		}
		
		float tongDiem(){
			return this->Toan + this->ly + this->hoa;
		}
		
		string getID(){
			return this->ID;
		}
		
		float getToan(){
			return this->Toan;
		}
		
		float getLy(){
			return this->ly;
		}
		
		float getHoa(){
			return this->hoa;
		}
};

void nhapDS(thiSinh *a, int &n){
	cout<<"\tNhap danh sach gom "<<n<<" thi sinh\n";
	for(int i=0; i<n; i++){
		cout<<"\nNhap thong tin thi sinh thu "<<i+1<<endl;
		cin>>a[i];
	}
}

void xuatDS(thiSinh *a, int n){
	for(int i=0; i<n; i++){
		cout<<a[i]<<endl;
	}
}

void sort(thiSinh *a, int &n){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(a[i].tongDiem() > a[j].tongDiem()){
				swap(a[i], a[j]);
			}
		}
	}
	cout<<"\n\tDANH SACH THI SINH SAP XEP THEO TONG DIEM\n\n";
	xuatDS(a, n);
}

void searchID(thiSinh *a, int &n){
	bool check = false;
	string search;
	cout<<"Nhap so bao danh can tim: ";
	cin>>search;
	for(int i=0; i<n; i++){
		if(a[i].getID() == search){
			check = true;
		}
	}
	if(check){
		for(int i=0; i<n; i++){
			if(a[i].getID() == search){
				cout<<"\n\tThong tin thi sinh co so bao danh "<<search<<" la: \n";
				cout<<a[i];
			}
		}
	}else{
		cout<<"\n\tKhong co thi sinh nao co so bao danh "<<search<<" ca.\n";
	}
}

void passExam(thiSinh *a, int &n){
	int count = 0;
	for(int i=0; i<n; i++){
		if(a[i].getToan() >= 5 && a[i].getLy() >= 5 && a[i].getHoa() >= 5){
			count++;
		}
	}
	cout<<"\n\nCo "<<setprecision(2)<<fixed<<((float)count/n)*100<<"% thi sinh dat yeu cau.\n";
}

int main(){
	int n;
	cout<<"Nhap so luong thi sinh du thi: ";
	do{
		cin>>n;
		if(n<=0){
			cout<<"\tNhap lai: ";
		}
	}while(n<=0);
	thiSinh *a = new thiSinh[n];
	nhapDS(a, n);
	system("pause");
	system("cls");
	cout<<"\tDanh sach thi sinh du thi\n\n";
	xuatDS(a, n);
	system("pause");
	system("cls");
	sort(a, n);
	searchID(a, n);
	passExam(a, n);
	
	delete a;
	return 0;
}

