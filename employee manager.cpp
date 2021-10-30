#include<iostream>
#include<string>
#include<math.h>
#include<conio.h>
#include<fstream>
using namespace std;
class person{
	public:
		int id;
		int birthday;
		string name,quequan;
		virtual void input(){ // Nhap thong tin nhan vien
			cout<<"nhap ten: ";
			cin.ignore();
			getline(cin,name);
			cout<<"nhap id: ";
			cin>>id;
			cout<<"nhap que quan: ";
			cin.ignore();
			getline(cin,quequan);
			cout<<"nhap nam sinh: ";
			cin>>birthday;
			}
		virtual void output(){
			cout<<"NAME: "<<name<<endl;
			cout<<"ID: "<<id<<endl;
			cout<<"QUE QUAN: "<<quequan<<endl;
			cout<<"NAM SINH: "<<birthday<<endl;
		}
		virtual double thuong()=0;
};
class employee:public person{
	public:
		int idnv,sohlam;
		int luong;
		void input1(){ ///Nhap ma so nhan vien, luong, san pham ban duoc
			person::input();
			cout<<"nhap id nv: ";
			cin>>idnv;
			cout<<"nhap luong: ";
			cin>>luong;
			cout<<"nhap so gio nhan vien da lam: ";
			cin>>sohlam;
		}
		void output1(){
			person::output();
			cout<<"ID NV: "<<idnv<<endl;
			cout<<"Luong: "<<luong<<endl;
			cout<<"SO H LAM DUOC: "<<sohlam<<endl;
		}
		double thuong(){ //Tinh tien luong nhan vien
			if(sohlam>=30)
			return (luong*sohlam);
			else
			return luong;
		}		
};
class accountant:public person{
	public:
		int idkt,ntc,sohlam;
		int luong;
		void input2(){
			person::input(); //Nhap thong tin ke toan
			cout<<"nhap id nv ke toan: ";
			cin>>idkt;
			cout<<"nhap so ngay tang ca: ";
			cin>>ntc;
			cout<<"nhap so gio lam cua ke toan: ";
			cin>>sohlam;
			cout<<"nhap luong: ";
			cin>>luong;
		}
		void output2(){
			person::output();
			cout<<"IDKT: "<<idkt<<endl;
			cout<<"SO NGAY TANG CA: "<<ntc<<endl;
			cout<<"SO H LAM DUOC: "<<sohlam<<endl;
			cout<<"LUONG: "<<luong<<endl;
		}
		double thuong(){// Tinh tien thuong ke toan
			if(ntc>=5)
			return (luong*(ntc+sohlam));
			else 
			return luong;
		}
};
class listPerson{
	public:
		int n;
	employee s1;
	void inputList1(){
		s1.input1();
	}
	void out1(){
		ofstream f;
		f.open("D:\\test.txt",ios::out); //Xuat thong tin nhan vien nam sinh, que quan,so san pham, thuong
		f<<"ten: "<<s1.name<<"\nID: "<<s1.id<<"\nnam sinh: "<<s1.birthday<<"\nidnv: "<<s1.idnv<<"\nque quan: "<<s1.quequan<<"\nso h lam duoc: "<<s1.sohlam<<"\nluong: "<<s1.thuong()<<endl;
		f<<"---------------------"<<endl;
		f.close();
}
	void outputList1(){
		s1.output1();
	}
	void display(){
	cout<<"TIEN LUONG + THUONG: "<<endl<<s1.thuong(); //Xuat tien luong
	}
double MaxSalary1(){
		 return s1.thuong();
}
	int tim(){
		return s1.id;
	}
	accountant s2;
	void inputList2(){
		s2.input2();
	}
	void outputList2(){
		s2.output2();
		s2.thuong();
	}
	void display1(){
		cout<<"TIEN LUONG + THUONG: "<<endl<<s2.thuong();//Xuat tien luong
	}
double MaxSalary2(){
		return s2.thuong();
	}
	int tim1(){
		return s2.id;
		}
	void out2(){
		ofstream f;
		f.open("D:\\test1.txt",ios::out); //Xuat thong tin ke toan nam sinh, que quan,so ngay tang ca, thuong
		f<<"ten: "<<s2.name<<"\nID: "<<s2.id<<"\nnam sinh: "<<s2.birthday<<"\nidkt: "<<s2.idkt<<"\nque quan: "<<s2.quequan<<"\nso ngay tang ca: "<<s2.ntc<<"\nso gio lam duoc: "<<s2.sohlam<<"\nluong: "<<s2.thuong()<<endl;
		f<<"---------------------"<<endl;
		f.close();
}
};
class MaxPerson{
	public:
		int n;
	employee s1;
	double thuongList1(){
		s1.thuong();
	}
			
};
void menu(){
	cout<<"========QUAN LY NHAN VIEN========\n";
	cout<<"1.Nhap nv ban hang \n";
	cout<<"2.Nhap nv ke toan \n";
	cout<<"3.Xuat nhan vien ban hang \n";
	cout<<"4.Xuat nhan vien ke toan \n";
	cout<<"5.Tong tien \n";
	cout<<"6.Tim nhan vien ban hang\n";
	cout<<"7.Tim nhan vien ke toan \n";
	cout<<"8.Luong cao nhat cua nhan vien hang \n";
	cout<<"9.Thoat\n";
}
int main(){
	listPerson s3[5];
	MaxPerson s2[5];
	int n;
	int n1;
	ofstream f;
	float x;
	float x1=0;
	float max=0;
	float j=0;
	menu();
	int chon;
	do{
		cout<<"Moi ban chon so : ";
		cin>>chon;
		switch(chon){
				case 1:
				{
		
				cout<<"So nguoi muon nhap: ";
				cin>>n;
				cout<<"------------NHAP THONG TIN BAN HANG------------"<<endl;
				for(int i=0;i<n;i++){
					s3[i].inputList1();
					s3[i].out1();
						cout<<"------------------------"<<endl;
				}
				system("pause");
				system("cls");
				menu();
				break;
				}	
			
			case 2:
			{
			
				cout<<"So nguoi muon nhap: ";
				cin>>n1;
				cout<<"-----------NHAP THONG TIN KE TOAN-------------"<<endl;
				for(int i=0;i<n1;i++){
					s3[i].inputList2();
					cout<<"------------------------"<<endl;
				}
				system("pause");
				system("cls");
				menu();
				break;
			}
			case 3:
			{
				cout<<"--------------------------NHAN VIEN BAN HANG----------------------"<<endl;
				for(int i=0;i<n;i++){
					s3[i].outputList1();
						cout<<"==="<<endl;
					s3[i].display();
						cout<<"\n-----------------"<<endl;
				}
				system("pause");
				system("cls");
				menu();
				break;
			}
			case 4:
			{	
				cout<<"--------------------------NHAN VIEN KE TOAN----------------------"<<endl;
				for(int i=0;i<n1;i++){
					s3[i].outputList2();
						cout<<"==="<<endl;
					s3[i].display1();
						cout<<"\n-----------------"<<endl;
				}
				system("pause");
				system("cls");
				menu();	
				break;
			}
			case 5:
			{
				/// Tong tien phai thanh toan
				for(int i=0;i<n;i++){
					 x1=x1+s3[i].MaxSalary1();
				}
				for(int i=0;i<n1;i++){
					 x1=x1+s3[i].MaxSalary2();
				}
					cout<<"Tong tien phai tra la: "<<x1<<endl;
				system("pause");
				system("cls");
				break;
			}
			case 6:
			{
				cout<<"Nhap id tim: ";
				cin>>x;
				cout<<"-------NGUOI CAN TIM LA--------"<<endl;
				for(int i=0;i<n;i++){
					if(x==s3[i].tim()){
						s3[i].outputList1();
							cout<<"===";
								s3[i].display();
									cout<<" "<<endl;
										s3[i].out1();			
					}
					else	
					cout<<"Khong tim thay "<<endl;
				}
				system("pause");
				system("cls");
				menu();
				break;
			}
			case 7:
			{
				cout<<"Nhap id tim: ";
				cin>>x;
				cout<<"-------NGUOI CAN TIM LA--------"<<endl;
				for(int i=0;i<n1;i++){
					if(x==s3[i].tim1()){
						s3[i].outputList2();
							cout<<"===";
								s3[i].display1();
									cout<<" "<<endl;
									s3[i].out2();		
				}
					else
					cout<<"Khong tim thay "<<endl;
				}
				system("pause");
				system("cls");
				menu();
				break;
			}
			case 8:{
				max=s2[0].thuongList1();
				for (int i=1;i<n;i++){	
					if (s2[i].thuongList1()>max)//Tim luong cao nhat cua nhan vien ban hang
						max=s2[i].thuongList1();
							s3[i].out1();
				}
				for (int i=0;i<n;i++) {
					if (s2[i].thuongList1()==max)//so sanh voi max vua tim duoc de in ra danh sach nhan vien ban hang do do
						s3[i].out1();
				}
				system("pause");
				system("cls");
				menu();
				break;
				
			}
			case 9:
			{
				system("pause");
			}
		}
		
	}while(chon!=0);
	getche();
}