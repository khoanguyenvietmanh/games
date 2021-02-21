#include<iostream>
#include<ctime>
#include<string>
#include<fstream>
#include<vector>
#include<Windows.h>
#include<iomanip>
#include<conio.h>
long long int points=0;
long long int life=0;
using namespace std;
char map[50][50];
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

void gotoxy(int x,int y)
{    
	HANDLE hConsoleOutput;    
	COORD Cursor_an_Pos = {x-1,y-1};   
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);    
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}

void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
//khai bao cau truc cua cac thanh phan cua game
struct nguoichoi
{
	int diem;
	string hoten;
};
typedef struct nguoichoi NguoiChoi;
struct toado
{
	int x;
	int y;
};
typedef struct toado TOADO;
struct xeplayer
{
	TOADO A;
};
typedef struct xeplayer XePlayer;
struct xedoithu
{
	TOADO B;
};
typedef struct xedoithu XeDoiThu;
struct vatpham
{
	TOADO C;
};
typedef struct vatpham VatPham;
struct duongdua
{
    XePlayer xe;
    XeDoiThu ecar[100];
    VatPham vp[100];
};
typedef struct duongdua DUONGDUA;
NguoiChoi arr[100];
void VeDuongDua_1(DUONGDUA &dd)
{
	for(int i=0;i<30;i++)
	{
		map[i][0]='|';
		map[i][29]='|';
		if(i%2==0)
		{
			map[i][14]='|';
		}
		for(int j=1;j<29 && j!=14;j++)
		{
			map[i][j]=' ';
		}
	}
}
void VeDuongDua_2(DUONGDUA &dd)
{

	for(int i=0;i<30;i++)
	{
		map[i][0]='|';
		map[i][29]='|';
		if(i%2!=0)
		{
			map[i][14]='|';
		}
		for(int j=1;j<29 && j!=14;j++)
		{
			map[i][j]=' ';
		}
	}
}
void VeXePlayer(DUONGDUA &dd)
{
	map[dd.xe.A.x][dd.xe.A.y]='X';
	map[dd.xe.A.x][dd.xe.A.y-1]='#';
	map[dd.xe.A.x][dd.xe.A.y+1]='#';
	map[dd.xe.A.x-1][dd.xe.A.y-1]='o';
	map[dd.xe.A.x-1][dd.xe.A.y+1]='o';
    map[dd.xe.A.x+1][dd.xe.A.y-1]='o';
	map[dd.xe.A.x+1][dd.xe.A.y+1]='o';
}
bool Kiemtradungdo(DUONGDUA dd)
{
	if(map[dd.xe.A.x][dd.xe.A.y-1]=='!')
	{
		return true;
	}
	else if(map[dd.xe.A.x][dd.xe.A.y+1]=='!')
	{
		return true;
	}
	else if(map[dd.xe.A.x-1][dd.xe.A.y-1]=='!')
	{
		return true;
	}
	else if(map[dd.xe.A.x-1][dd.xe.A.y+1]=='!')
	{
		return true;
	}
	else if(map[dd.xe.A.x+1][dd.xe.A.y-1]=='!')
	{
		return true;
	}
	else if(map[dd.xe.A.x+1][dd.xe.A.y+1]=='!')
	{
		return true;
	}
return false;
}
bool Kiemtraantien(DUONGDUA dd)
{
	if(map[dd.xe.A.x][dd.xe.A.y-1]=='$')
	{
		return true;
	}
	else if(map[dd.xe.A.x][dd.xe.A.y+1]=='$')
	{
		return true;
	}
	else if(map[dd.xe.A.x-1][dd.xe.A.y-1]=='$')
	{
		return true;
	}
	else if(map[dd.xe.A.x-1][dd.xe.A.y+1]=='$')
	{
		return true;
	}
	else if(map[dd.xe.A.x+1][dd.xe.A.y-1]=='$')
	{
		return true;
	}
	else if(map[dd.xe.A.x+1][dd.xe.A.y+1]=='$')
	{
		return true;
	}
	else if(map[dd.xe.A.x][dd.xe.A.y]=='$')
	{
		return true;
	}
return false;
}
bool Kiemtramangsong(DUONGDUA dd)
{
    if(map[dd.xe.A.x][dd.xe.A.y-1]=='L'|| map[dd.xe.A.x][dd.xe.A.y-1]=='E')
	{
		return true;
	}
	else if(map[dd.xe.A.x][dd.xe.A.y+1]=='L' || map[dd.xe.A.x][dd.xe.A.y+1]=='E')
	{
		return true;
	}
	else if(map[dd.xe.A.x-1][dd.xe.A.y-1]=='L' || map[dd.xe.A.x-1][dd.xe.A.y-1]=='I' || map[dd.xe.A.x-1][dd.xe.A.y-1]=='F' || map[dd.xe.A.x-1][dd.xe.A.y-1]=='E')
	{
		return true;
	}
	else if(map[dd.xe.A.x-1][dd.xe.A.y+1]=='L' || map[dd.xe.A.x-1][dd.xe.A.y+1]=='I' || map[dd.xe.A.x-1][dd.xe.A.y+1]=='F' || map[dd.xe.A.x-1][dd.xe.A.y+1]=='E')
	{
		return true;
	}
	else if(map[dd.xe.A.x+1][dd.xe.A.y-1]=='l' || map[dd.xe.A.x+1][dd.xe.A.y-1]=='I' || map[dd.xe.A.x+1][dd.xe.A.y-1]=='F' || map[dd.xe.A.x+1][dd.xe.A.y-1]=='E')
	{
		return true;
	}
	else if(map[dd.xe.A.x+1][dd.xe.A.y+1]=='L' || map[dd.xe.A.x+1][dd.xe.A.y+1]=='I' || map[dd.xe.A.x+1][dd.xe.A.y+1]=='F' || map[dd.xe.A.x+1][dd.xe.A.y+1]=='E')
	{
		return true;
	}
return false;
}
void Ghidanhsachnguoichoivaofile(ofstream &fileout,NguoiChoi &nc)
{
	int i=0;
	textcolor(12);
	fileout.open("Ten Nguoi Choi.txt",ios_base::app);
	fflush(stdin);
	cout<<"\nNhap vao ho ten cua ban:";
	fflush(stdin);
	getline(cin,nc.hoten);
	cout<<"\nDiem cua ban la:"<<nc.diem;
	fileout<<nc.hoten<<" - "<<nc.diem<<endl;
	system("pause");
	fileout.close();
}
void Dichuyenxe(DUONGDUA &dd,NguoiChoi &nc)
{
	if(GetAsyncKeyState(VK_LEFT))
	{
		
		if(dd.xe.A.y>2)
		{
		if(Kiemtradungdo(dd)==true)
		{
		    system("cls");
	        gotoxy(33,13);
	        textcolor(12);
			cout<<"BAN DA THUA CUOC";
			//Tao file de luu thong tin nguoi choi
			ofstream fileout;
			Ghidanhsachnguoichoivaofile(fileout,nc);
			exit(0);
	    }
        map[dd.xe.A.x][dd.xe.A.y]=' ';
	    map[dd.xe.A.x][dd.xe.A.y-1]=' ';
	    map[dd.xe.A.x][dd.xe.A.y+1]=' ';
	    map[dd.xe.A.x-1][dd.xe.A.y-1]=' ';
	    map[dd.xe.A.x-1][dd.xe.A.y+1]=' ';
	    map[dd.xe.A.x+1][dd.xe.A.y-1]=' ';
	    map[dd.xe.A.x+1][dd.xe.A.y+1]=' ';
	    dd.xe.A.y--;
	    VeXePlayer(dd);
	    }
	}
	else if(GetAsyncKeyState(VK_RIGHT))
	{
	if(dd.xe.A.y<=26)
	{
		if(Kiemtradungdo(dd)==true)
		{
		    system("cls");
	        gotoxy(33,13);
	        textcolor(12);
			cout<<"BAN DA THUA CUOC";
			//Tao file de luu thong tin nguoi choi
			ofstream fileout;
			Ghidanhsachnguoichoivaofile(fileout,nc);
			exit(0);
		}
	 map[dd.xe.A.x][dd.xe.A.y]=' ';
	 map[dd.xe.A.x][dd.xe.A.y-1]=' ';
	 map[dd.xe.A.x][dd.xe.A.y+1]=' ';
	 map[dd.xe.A.x-1][dd.xe.A.y-1]=' ';
	 map[dd.xe.A.x-1][dd.xe.A.y+1]=' ';
	 map[dd.xe.A.x+1][dd.xe.A.y-1]=' ';
	 map[dd.xe.A.x+1][dd.xe.A.y+1]=' ';
	 dd.xe.A.y++;
	 VeXePlayer(dd);
    }
	}
	else if(GetAsyncKeyState(VK_UP))
	{
	if(dd.xe.A.x>1)
	{
		if(Kiemtradungdo(dd)==true)
		{
			system("cls");
	        gotoxy(33,13);
	        textcolor(12);
			cout<<"BAN DA THUA CUOC";
			//Tao file de luu thong tin nguoi choi
			ofstream fileout;
			Ghidanhsachnguoichoivaofile(fileout,nc);
			exit(0);
		}
	map[dd.xe.A.x][dd.xe.A.y]=' ';
	map[dd.xe.A.x][dd.xe.A.y-1]=' ';
	map[dd.xe.A.x][dd.xe.A.y+1]=' ';
	map[dd.xe.A.x-1][dd.xe.A.y-1]=' ';
    map[dd.xe.A.x-1][dd.xe.A.y+1]=' ';
    map[dd.xe.A.x+1][dd.xe.A.y-1]=' ';
    map[dd.xe.A.x+1][dd.xe.A.y+1]=' ';
	dd.xe.A.x--;
	VeXePlayer(dd);
    }
	}
	else if(GetAsyncKeyState(VK_DOWN))
	{
	if(dd.xe.A.x<=27)
	{
		if(Kiemtradungdo(dd)==true)
		{
		    system("cls");
	        gotoxy(33,13);
	        textcolor(12);
			cout<<"BAN DA THUA CUOC";
			//Tao file de luu thong tin nguoi choi
			ofstream fileout;
			Ghidanhsachnguoichoivaofile(fileout,nc);
			exit(0);
		}
	map[dd.xe.A.x][dd.xe.A.y]=' ';
	map[dd.xe.A.x][dd.xe.A.y-1]=' ';
	map[dd.xe.A.x][dd.xe.A.y+1]=' ';
	map[dd.xe.A.x-1][dd.xe.A.y-1]=' ';
	map[dd.xe.A.x-1][dd.xe.A.y+1]=' ';
	map[dd.xe.A.x+1][dd.xe.A.y-1]=' ';
	map[dd.xe.A.x+1][dd.xe.A.y+1]=' ';
	dd.xe.A.x++;
	VeXePlayer(dd);
    }
    }
}
void VeXeDoiThu(DUONGDUA &dd)
{
	for(int i=0;i<5;i++) 
	{
	map[dd.ecar[i].B.x][dd.ecar[i].B.y]='!';
	map[dd.ecar[i].B.x][dd.ecar[i].B.y-1]='!';
	map[dd.ecar[i].B.x][dd.ecar[i].B.y+1]='!';
	map[dd.ecar[i].B.x-1][dd.ecar[i].B.y-1]='!';
	map[dd.ecar[i].B.x-1][dd.ecar[i].B.y+1]='!';
    map[dd.ecar[i].B.x+1][dd.ecar[i].B.y-1]='!';
	map[dd.ecar[i].B.x+1][dd.ecar[i].B.y+1]='!';
    }
}
void XoaXeDoiThu(DUONGDUA &dd)
{
	for(int i=0;i<5;i++)
	{
	map[dd.ecar[i].B.x][dd.ecar[i].B.y]=' ';
	map[dd.ecar[i].B.x][dd.ecar[i].B.y-1]=' ';
	map[dd.ecar[i].B.x][dd.ecar[i].B.y+1]=' ';
	map[dd.ecar[i].B.x-1][dd.ecar[i].B.y-1]=' ';
	map[dd.ecar[i].B.x-1][dd.ecar[i].B.y+1]=' ';
    map[dd.ecar[i].B.x+1][dd.ecar[i].B.y-1]=' ';
	map[dd.ecar[i].B.x+1][dd.ecar[i].B.y+1]=' ';
    }
}
void VeVatPhamTien(DUONGDUA &dd)
{
	for(int i=0;i<5;i++)
	{
	map[dd.vp[i].C.x][dd.vp[i].C.y]='$';
    }
}
void XoaVatPhamTien(DUONGDUA &dd)
{
	for(int i=0;i<5;i++)
	{
	map[dd.vp[i].C.x][dd.vp[i].C.y]=' ';
	}
}
void VeVatPhamMangSong(DUONGDUA &dd)
{
	map[dd.vp[5].C.x][dd.vp[5].C.y]='L';
	map[dd.vp[5].C.x][dd.vp[5].C.y+1]='I';
	map[dd.vp[5].C.x][dd.vp[5].C.y+2]='F';
	map[dd.vp[5].C.x][dd.vp[5].C.y+3]='E';
}
void XoaVatPhamMangSong(DUONGDUA dd)
{
	map[dd.vp[5].C.x][dd.vp[5].C.y]=' ';
	map[dd.vp[5].C.x][dd.vp[5].C.y+1]=' ';
	map[dd.vp[5].C.x][dd.vp[5].C.y+2]=' ';
	map[dd.vp[5].C.x][dd.vp[5].C.y+3]=' ';
}
void VeVatPhamThuBe(DUONGDUA &dd)
{
    map[dd.vp[6].C.x][dd.vp[6].C.y]='N';
	map[dd.vp[6].C.x][dd.vp[6].C.y+1]='A';
	map[dd.vp[6].C.x][dd.vp[6].C.y+2]='R';
	map[dd.vp[6].C.x][dd.vp[6].C.y+3]='R';
	map[dd.vp[6].C.x][dd.vp[6].C.y+4]='O';
	map[dd.vp[6].C.x][dd.vp[6].C.y+5]='W';
	
}
void XoaVatPhamThuBe(DUONGDUA &dd)
{
	map[dd.vp[6].C.x][dd.vp[6].C.y]=' ';
	map[dd.vp[6].C.x][dd.vp[6].C.y+1]=' ';
	map[dd.vp[6].C.x][dd.vp[6].C.y+2]=' ';
	map[dd.vp[6].C.x][dd.vp[6].C.y+3]=' ';
	map[dd.vp[6].C.x][dd.vp[6].C.y+4]=' ';
	map[dd.vp[6].C.x][dd.vp[6].C.y+5]=' ';
}
void Induongdua(DUONGDUA &dd)
{
	for(int i=0;i<30;i++)
	{
		cout<<"\t\t\t";
		for(int j=0;j<30;j++)
		{
			if(j==0 || j==29)
			{
				textcolor(191);
				map[i][j]=' ';
				cout<<map[i][j];
				textcolor(7);
			}
			else if(j==14)
			{
				cout<<map[i][j];
				map[i][j]=' ';
				
			}
			else if(map[i][j]=='X'|| map[i][j]=='#' || map[i][j]=='o')
			{
				textcolor(14);
				cout<<map[i][j];
				if(j==14)
				{
					cout<<map[i][j];
				}
				textcolor(7);
			}
			else if(map[i][j]=='!')
			{
				//map[i][j]=' ';
				textcolor(200);
				cout<<map[i][j];
				textcolor(7);
			}
			else if(map[i][j]=='$')
			{
				cout<<map[i][j];
			}
			else if(map[i][j]=='N' ||map[i][j]=='A'||map[i][j]=='R'||map[i][j]=='R'||map[i][j]=='O'||map[i][j]=='W')
		    {
		    	textcolor(10);
		    	cout<<map[i][j];
		    	textcolor(7);
			}
			else if(map[i][j]=='L'||map[i][j]=='I'||map[i][j]=='F'||map[i][j]=='E')
			{
				textcolor(13);
				cout<<map[i][j];
				textcolor(7);
			}
			else if(map[i][j]=='+')
			{
				textcolor(11);
				cout<<map[i][j];
				textcolor(7);
			}
			else
			{
				cout<<map[i][j];
			}
		}
		cout<<endl;
	}
}
//Ham ghi ra cac cau lenh phan Help
void Help(NguoiChoi &nc)
{
	cout<<"\n================================================================================";
	cout<<"ESC  -exit\n\n\n";
	cout<<"Q    -quit and save your achievement\n\n\n";
	cout<<"W    -quit and back to menu\n\n\n";
	cout<<"Enter-Pause";
	gotoxy(58,33);
	cout<<"LIFE:"<<life;
	gotoxy(58,37);
	cout<<"LEVEL:";
	gotoxy(58,41);
	cout<<"POINTS:"<<nc.diem;
	gotoxy(31,49);
	textcolor(14);
	cout<<"Space - Shoot Bullet";
	textcolor(7);
}
void XuLyGame(DUONGDUA &dd,NguoiChoi &nc)
{
	nc.diem=0;
	dd.xe.A.x=20;
	dd.xe.A.y=14;
	dd.ecar[0].B.x=3;
	dd.ecar[1].B.x=8;
	dd.ecar[2].B.x=14;
	dd.ecar[3].B.x=25;
	dd.ecar[0].B.y=13;
	dd.ecar[1].B.y=17;
	dd.ecar[2].B.y=5;
	dd.ecar[3].B.y=9;
	dd.ecar[4].B.x=2;
	dd.ecar[4].B.y=2;
	dd.vp[0].C.x=4;
	dd.vp[1].C.x=9;
	dd.vp[2].C.x=15;
	dd.vp[3].C.x=26;
	dd.vp[4].C.x=3;
	dd.vp[0].C.y=16;
	dd.vp[1].C.y=20;
	dd.vp[2].C.y=8;
	dd.vp[3].C.y=23;
	dd.vp[4].C.y=1;
	dd.vp[5].C.x=6;
	dd.vp[5].C.y=20;
	dd.vp[6].C.x=10;
	dd.vp[6].C.y=15;
	int a=0;
	while(true)
	{
		nc.diem++;
		a++;
		if(a%2==0)
		{
			VeDuongDua_1(dd);
		}
		else
		{
			VeDuongDua_2(dd);
		}
		XoaManHinh();
		VeXePlayer(dd);
		VeXeDoiThu(dd);
		VeVatPhamTien(dd);
		VeVatPhamThuBe(dd);
		VeVatPhamMangSong(dd);
		Induongdua(dd);
		Help(nc);
		Dichuyenxe(dd,nc);
		if(Kiemtradungdo(dd)==true)
		{
			system("cls");
			gotoxy(33,13);
	        textcolor(12);
			cout<<"BAN DA THUA CUOC";
			//Tao file de luu thong tin nguoi choi
			ofstream fileout;
		    Ghidanhsachnguoichoivaofile(fileout,nc);
		    break;
		}
		if(Kiemtraantien(dd)==true)
		{
			nc.diem++;
		}
		if(Kiemtramangsong(dd)==true)
		{
			life++;
		}
		XoaXeDoiThu(dd);
		for(int i=0;i<4;i++)
		{
			dd.ecar[i].B.x++;
		}
		srand(time(NULL));
		dd.ecar[4].B.y=2+rand()%26;
		dd.ecar[4].B.x++;
		if(dd.ecar[4].B.x==29)
		{
			dd.ecar[4].B.x=0;
		}
		for(int j=0;j<4;j++)
		{ 
		   if(dd.ecar[j].B.x==29)
			{
				points++;
				dd.ecar[j].B.x=0;
				srand(time(NULL));
				dd.ecar[j].B.y=2+rand()%26;
			}
		}
		XoaVatPhamTien(dd);
		for(int k=0;k<5;k++)
		{
			dd.vp[k].C.x++;
		}
		for(int v=0;v<5;v++)
		{
			if(dd.vp[v].C.x==29)
			{
				dd.vp[v].C.x=0;
			}
		}
		XoaVatPhamMangSong(dd);
		dd.vp[5].C.x++;
		if(dd.vp[5].C.x==29)
		{
			dd.vp[5].C.x=0;
			srand(time(0));
			dd.vp[5].C.y=2+rand()%26;
		}
		XoaVatPhamThuBe(dd);
		dd.vp[6].C.x++;
		if(dd.vp[6].C.x==29)
		{
			dd.vp[6].C.x=0;
			srand(time(0));
			dd.vp[6].C.y=2+rand()%26;
		}
		Sleep(10);
		if(a>=30)
		{
			a=0;
		}
		if(GetAsyncKeyState(VK_ESCAPE))
		{
			break;
		}
		else if(GetAsyncKeyState(VK_SHIFT))
		{
			ofstream fileout;
			NguoiChoi nc;
			fileout.open("TEN NGUOI CHOI.txt",ios_base::app);
			system("cls");
			Ghidanhsachnguoichoivaofile(fileout,nc);
			fileout.close();
			break;	
	    }
    }
}
//Ham tao ra Menu cho nguoi dung chon
void Hoanvi(NguoiChoi &a,NguoiChoi &b)
{
	NguoiChoi temp=a;
	a=b;
	b=temp;
}
void Sapxep(NguoiChoi arr[],int dem)
{
	for(int i=0;i<dem-1;i++)
	{
		for(int j=i+1;j<dem;j++)
		{
			if(arr[i].diem<arr[j].diem)
			{
				Hoanvi(arr[i],arr[j]);
			}
			
		}
	}
}
void Menu(DUONGDUA &dd,NguoiChoi &nc)
{
   textcolor(10);
   gotoxy(23,1);
   cout<<"# # # # # #  #         #       #";
   gotoxy(23,3);
   cout<<"#          # #         #     #   #";
   gotoxy(23,5);
   cout<<"#          # #         #   #       #";
   gotoxy(23,7);
   cout<<"#          # #         # #           #";
   gotoxy(23,9);
   cout<<"#          # #         # # # # # # # #";
   gotoxy(23,11);
   cout<<"#          # #         # #           #";
   gotoxy(23,13);
   cout<<"# # # # # #   # # # # #  #           #";
   textcolor(14);
   gotoxy(32,14);
   cout<<"#      # # # # #";
   gotoxy(32,16);
   cout<<" #    #  #";
   gotoxy(32,18);
   cout<<"  #  #   #";
   gotoxy(32,20);
   cout<<"   #     # # # #";
   gotoxy(32,22);
   cout<<"  #  #   #";
   gotoxy(32,24);
   cout<<" #    #  #";
   gotoxy(32,26);
   cout<<"#      # # # # #";
   textcolor(7);
   //Lam Menu
   gotoxy(34,30);
   cout<<"1.Choi game";
   gotoxy(34,34);
   cout<<"2.Xem danh sach diem cao nhat";
   gotoxy(34,38);
   cout<<"3.Thoat game";
   gotoxy(1,42);
   cout<<"TOI LUA CHON:";
   int luachon;
   cin>>luachon;
   switch(luachon) 
   {
   	 case 1:system("cls");
   	        gotoxy(1,20);
   	        textcolor(12);
   	        cout<<"Luu y:-Ban phai co gang ne nhung chiec xe doi thu co mau do de song dai nhat co the";
   	        gotoxy(1,24);
   	        cout<<"      -An duoc cac vat pham tren duong se giup ban song sot lau hon vao dat diem cao hon";
			gotoxy(1,28);
			cout<<"      -Khi ban ban no se pha huy moi thu tren duong di ke ca vat pham tien va mang song.Vi vay hay can nhac khi ban";
			gotoxy(27,45);
			system("pause");
			system("cls");
			fflush(stdin);  
	        XuLyGame(dd,nc);
   	        break;
   	 case 2:system("cls");
            gotoxy(32,1);  	 	
		    cout<<"DANH SACH TOP PLAYER\n";
		    ifstream filein1;
		    filein1.open("TEN NGUOI CHOI.txt",ios_base::in);
		    NguoiChoi arr[100];
		    int i=0;
		    int dem=0;
		    char x;
		    while(!filein1.eof())
		    {
		    getline(filein1,arr[i].hoten,'-');
		    filein1>>arr[i].diem;
		    filein1>>x;
		    i++;
		    dem++;
		    }
		    Sapxep(arr,dem);
		    for(int i=0;i<dem;i++)
		    {
		    	cout<<"\n=================================================================";
		    	cout<<"\nTen nguoi choi:"<<arr[i].hoten;
		    	cout<<"\nDiem:"<<arr[i].diem;
		    }
		    filein1.close();
   	        break;
   }
}
int main()
{
	resizeConsole(600,800);
	DUONGDUA dd;
	NguoiChoi nc;
	Menu(dd,nc);
	return 0;
}
