#include<iostream>
#include<conio.h>
#include<iomanip>
#include<fstream>
#include<stdlib.h>
#include<windows.h>
#include<string>
#include<ctime>

using namespace std;

int main();
int MainMenuH();
void ServiceCenter();
void FoodService();
void FoodConerMain();
void DecorateTopic();
void LoadingBar();
int timeANDdate();

char pw[20]="sachintha", q=178,g=219,l=201,m=205,r=186,z=187,s=200,t=188,ri=254,n1=177,n2=176,bd1=176,bd2=221;

int gotoxy (int x, int y)
{
   COORD sach;
   sach.X=x;
   sach.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),sach);
}


class Hotel
{
private:
    int RoomNo,customerPhone,RoomId;
    char RoomName[20],CustomerName[20],CustomerAddress[40];
    float RoomCost,CustomerAdvanseP,CPayment,calculate;

public:
    void adddata();
    void UpdateDetail();
    int BookRoom();
    int check(int);
    void DeleteDetail();
    void releseRoom();
    void writedata();
};

int Hotel :: BookRoom()
{
    Hotel h;
    system("cls");
    gotoxy(2,1);
    timeANDdate();

    char ch[10];
    int k=13,Flag,rNo;
    char d[25]="BOOKING ROOM";
    int j;

        gotoxy(48,6);
        for(j=0;j<15;j++)
        {
            Sleep(50);
            cout<<bd2;
        }
        cout<<" ";
        for(j=0;j<13;j++)
        {
           Sleep(50);
           cout<<d[j];
        }
       for(j=0;j<15;j++)
        {
           Sleep(50);
           cout<<bd2;
        }

    ifstream inFile;
	inFile.open("Hrecord.dat",ios::binary | ios::in);

	if(!inFile)
    {
        system("cls");
        gotoxy(75,27);
        cout<<"Record Not Found....!!!";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        if(getch()==13)
        {
            MainMenuH();
        }
        else
        {
            MainMenuH();
        }
    }
    else
    {

            gotoxy(40,10);
            cout<<"==========================================================\n";
            gotoxy(40,11);
            cout<<"Room No              Room Name                   Room Cost"<<endl;
            gotoxy(40,12);
            cout<<"==========================================================\n";

                if(!inFile)
                {
                    cout<<"\t\t\t\t\t\t File Does Not Found!!!";
                }

                while(inFile.read(reinterpret_cast<char *>(&h),sizeof(Hotel)))
                {
                        gotoxy(40,k);
                        cout<<h.RoomNo<<setw(18)<<" "<<h.RoomName<<setw(27)<<h.RoomCost<<endl;
                        k+=2;
                }
                inFile.close();
            gotoxy(40,k);
            cout<<"==========================================================\n";

            ofstream fout;
            fout.open("booking.dat",ios::binary | ios::out | ios::app);

                    cout<<"\n\t\t\t\t><. Enter the room number you need to book: ";
                    cin>>rNo;

                    Flag = check(rNo);

                    if(Flag==1)
                    {
                        cout<<"\n\t\t\t\t\t\t Sorry, Room is already booked";
                    }
                    else if(Flag==0)
                    {
                        cout<<"\n\n\t\t\t\t\t\t    "<<bd1<<bd1<<bd1<<bd1<<bd1<<bd1<<bd1<<bd1<<bd1<<bd1<<bd1<<" Fill Up The Form "<<bd1<<bd1<<bd1<<bd1<<bd1<<bd1<<bd1<<bd1<<bd1<<bd1<<bd1<<endl;
                        cout<<"\n\t\t\t\t\t\t\tName: ";
                        cin>>h.CustomerName;
                        cout<<"\t\t\t\t\t\t\tAddress: ";
                        cin>>h.CustomerAddress;
                        cout<<"\t\t\t\t\t\t\tPhone No: ";
                        cin>>h.customerPhone;
                        h.RoomId=rNo;

                        fout.write(reinterpret_cast<char *>(&h),sizeof(Hotel));
                        cout<<"\n\t\t\t\t\t\t\t\t Room is booked...!!!";
                    }
                    else if(Flag==2)
                    {
                        cout<<"\n\t\t\t\t\t\tCan't Find ";
                    }

                    cout<<"\n\n\t\t\t\t\t\t\tPress any key to continue.....!!";
                    getch();
                    fout.close();

            cout<<"\n\n\t\t\t\t\t\tIf you want to book another room, press <y>...";
            gotoxy(168,48);
            cout<<"Press ENTER to return main menu..";
            switch (getch())
            {
            case 'y':
            case 'Y':
                system("cls");
                h.BookRoom();
                break;
            case 13:
                system("cls");
                MainMenuH();
                break;
            default:
                system("cls");
                MainMenuH();
                break;
            }
    }
}


int Hotel::check(int rNo)
{
    Hotel h;

    int flag=0;

    ifstream fin("booking.dat",ios::in),fread("Hrecord.dat",ios::in);

    while(fread.read(reinterpret_cast<char *>(&h),sizeof(Hotel)))
    {
        if(h.RoomNo==rNo)
        {
            while(fin.read(reinterpret_cast<char *>(&h),sizeof(Hotel)))
            {
                if(h.RoomId==rNo)
                {

                    flag=1;
                    break;

                }

            }
        }
        else
        {
            flag=2;
        }
    }

    fin.close();
    return(flag);

}

void Hotel :: releseRoom()
{
    Hotel h;
    system("cls");
    DecorateTopic();
    gotoxy(2,1);
    timeANDdate();
    int rNo,Flag;
    float tot=0;

    //cout<<"\n";
    ifstream fin,InFile;
    gotoxy(67,31);
    cout<<"   Enter the room number you want to release: ";
    cin>>rNo;

    fin.open("booking.dat",ios::binary | ios::in);
    if(!fin)
    {
        system("cls");
        gotoxy(75,27);
        cout<<"Record Not Found....!!!";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        if(getch()==13)
        {
            MainMenuH();
        }
        else
        {
            MainMenuH();
        }
    }
    else
    {

        ofstream fout;
        fout.open("tempbooking.dat",ios::binary | ios::app);
        fin.seekg(0,ios::beg);

           while(fin.read(reinterpret_cast<char *>(&h),sizeof(Hotel)))
           {
               if(rNo!=h.RoomId)
               {
                   fout.write(reinterpret_cast<char *>(&h),sizeof(Hotel));
               }

           }
        fin.close();
        fout.close();

        remove("booking.dat");
        rename("tempbooking.dat","booking.dat");
        gotoxy(70,32);
        cout<<"RELEASED ROOM..!!!";

        gotoxy(70,38);
        cout<<"If you want to release another room, Press <y>...";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        switch (getch())
        {
        case 'y':
        case 'Y':
            system("cls");
            h.releseRoom();
            break;
        case 13:
            system("cls");
            MainMenuH();
            break;
        default:
            system("cls");
            MainMenuH();
            break;
        }
    }

}

void Hotel::adddata()
{
    cout<<"\n\t\t\t\t><. Enter The Room Name: ";
    cin>>RoomName;
    cout<<"\n\t\t\t\t><. Enter The Room Cost: ";
    cin>>RoomCost;

}

void Hotel :: writedata()
{
    int i,j,RNo;
    system("cls");
    gotoxy(2,1);
    timeANDdate();
    Hotel h;

    char ch[10];
    int k=13;

    ifstream inFile;
	inFile.open("Hrecord.dat",ios::binary | ios::in);

	gotoxy(40,10);
	cout<<"==========================================================\n";
	gotoxy(40,11);
    cout<<"Room No              Room Name                   Room Cost"<<endl;
    gotoxy(40,12);
    cout<<"==========================================================\n";


        while(inFile.read(reinterpret_cast<char *>(&h),sizeof(Hotel)))
        {
            //cout<<endl;
            gotoxy(40,k);
            cout<<h.RoomNo<<setw(18)<<" "<<h.RoomName<<setw(27)<<h.RoomCost<<endl;
            k+=2;
        }
        inFile.close();
    gotoxy(40,k);
    cout<<"==========================================================\n";

        ofstream outFile;

        outFile.open("Hrecord.dat",ios::binary | ios::app);
        inFile.open("Hrecord.dat",ios::binary | ios::in);

        cout<<"\n\t\t\t\t><. Enter The Room Number: ";
        cin>>RNo;

        while(inFile.read(reinterpret_cast<char *>(&h),sizeof(Hotel)))
        {
            if(RNo==h.RoomNo)
            {
                cout<<"\n\t\t\t\t\t\tSorry!!! You cant Enter This No";
                getch();
                h.writedata();
            }
        }

        h.RoomNo=RNo;
        h.adddata();
        cout<<endl<<endl;
        outFile.write(reinterpret_cast<char *> (&h), sizeof(Hotel));
        outFile.close();

    cout<<"\n\n\n\t\t\t\t\t\t If You Want To add another Room, press <y>..";
    gotoxy(168,48);
    cout<<"Press ENTER to return main menu..";
    switch (getch())
    {
    case 'y':
    case 'Y':
        h.writedata();
        break;
    case 13:
        system("cls");
        MainMenuH();
        break;
    default:
        system("cls");
        MainMenuH();
        break;
    }
}


void Hotel :: UpdateDetail()
{
    Hotel h;
    system("cls");
    gotoxy(2,1);
    timeANDdate();

    char ch[10];
    int k=13,Flag,rNo;

    ifstream inFile;
	inFile.open("Hrecord.dat",ios::binary | ios::in);

	if(!inFile)
    {
        system("cls");
        gotoxy(75,27);
        cout<<"Record Not Found....!!!";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        if(getch()==13)
        {
            MainMenuH();
        }
        else
        {
            MainMenuH();
        }
    }
    else
    {

        gotoxy(40,10);
        cout<<"==========================================================\n";
        gotoxy(40,11);
        cout<<"Room No              Room Name                   Room Cost"<<endl;
        gotoxy(40,12);
        cout<<"==========================================================\n";


            while(inFile.read(reinterpret_cast<char *>(&h),sizeof(Hotel)))
            {
                //cout<<endl;
                gotoxy(40,k);
                cout<<h.RoomNo<<setw(18)<<" "<<h.RoomName<<setw(27)<<h.RoomCost<<endl;
                k+=2;
            }
            inFile.close();
        gotoxy(40,k);
        cout<<"==========================================================\n";

        int d,i;

            cout<<"\n\t\t\t\t><.Enter The Room Number You Want to update: ";
            cin>>d;

            fstream File;
            File.open("Hrecord.dat",ios::binary | ios::in | ios::out);
            if(!File)
            {
                cout<<"Doesn't Found File!!!";
            }
            while(File.read(reinterpret_cast<char *>(&h),sizeof(Hotel)))
            {
                if(d==h.RoomNo)
                {
                    system("cls");
                    gotoxy(20,7);
                    cout<<l<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<z;
                    gotoxy(20,8);
                    cout<<r<<endl;                                              gotoxy(60,8);cout<<r;
                    gotoxy(20,9);
                    cout<<r<<">. The Room Number is  : "<<h.RoomNo<<endl;            gotoxy(60,9);cout<<r;
                    gotoxy(20,10);
                    cout<<r<<">. The Room Name is    : "<<h.RoomName<<endl;            gotoxy(60,10);cout<<r;
                    gotoxy(20,11);
                    cout<<r<<">. The Room Cost is    : "<<h.RoomCost<<endl;            gotoxy(60,11);cout<<r;
                    gotoxy(20,12);
                    cout<<r<<endl;                                              gotoxy(60,12);cout<<r;
                    gotoxy(20,13);
                    cout<<s<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<t;

                    gotoxy(20,14);
                    cout<<"\n\t\t\t\t><. Enter The Room Number: ";
                    cin>>h.RoomNo;
                    h.adddata();

                    int pos=(-1)*static_cast<int>(sizeof(h));
                    File.seekp(pos,ios::cur);
                    File.write(reinterpret_cast<char *> (&h),sizeof(Hotel));
                    cout<<"\n\n\t\t\t\t\t\tRECORD UPDATE!!!!"<<endl;
                }

            }
            File.close();


        cout<<"\n\n\n\t\t\t\t\t\t You Want To Update Again then press <y>..";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        switch(getch())
        {
        case 'Y':
        case 'y':
            h.UpdateDetail();
            break;
        case 13:
            system("cls");
            MainMenuH();
            break;
        default:
            system("cls");
            MainMenuH();
            break;
        }
    }
}

void Hotel :: DeleteDetail()
{
    Hotel h;
    system("cls");
    gotoxy(2,1);
    timeANDdate();

    char ch[10];
    int k=13,Flag,rNo;

    ifstream inFile;
	inFile.open("Hrecord.dat",ios::binary | ios::in);

	if(!inFile)
    {
        system("cls");
        gotoxy(75,27);
        cout<<"Record Not Found....!!!";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        if(getch()==13)
        {
            MainMenuH();
        }
        else
        {
            MainMenuH();
        }
    }
    else
    {

        gotoxy(40,10);
        cout<<"==========================================================\n";
        gotoxy(40,11);
        cout<<"Room No              Room Name                   Room Cost"<<endl;
        gotoxy(40,12);
        cout<<"==========================================================\n";


            while(inFile.read(reinterpret_cast<char *>(&h),sizeof(Hotel)))
            {
                //cout<<endl;
                gotoxy(40,k);
                cout<<h.RoomNo<<setw(18)<<" "<<h.RoomName<<setw(27)<<h.RoomCost<<endl;
                k+=2;
            }
            inFile.close();
        gotoxy(40,k);
        cout<<"==========================================================\n";
        int rmId;

            cout<<"\n\t\t\t\t     Enter the Id You want to Delete: ";
            cin>>rmId;
            //ifstream inFile;
            inFile.open("Hrecord.dat",ios::binary | ios::in);

            if(!inFile)
            {
                cout<<"File Does Not Found";
                h.DeleteDetail();
            }

            ofstream outFile;
            outFile.open("tempHrecord.dat",ios::binary | ios::out | ios::app);
            inFile.seekg(0,ios::beg);

            while(inFile.read(reinterpret_cast<char *>(&h),sizeof(Hotel)))
            {
                if(rmId!=h.RoomNo)
                {
                    outFile.write(reinterpret_cast<char *>(&h),sizeof(Hotel));
                }
            }

            outFile.close();
            inFile.close();
                remove("Hrecord.dat");
                rename("tempHrecord.dat","Hrecord.dat");
                cout<<"\n\n\t\t\t\t\t\t\tRecord Deleted Successfully!!!!"<<endl<<endl;


        cout<<"\n\n\n\t\t\t\t\t\t You Want To Delete Again, press <y>..";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        switch(getch())
        {
        case 'Y':
        case 'y':
            h.DeleteDetail();
            break;
        case 13:
            system("cls");
            MainMenuH();
            break;
        default:
            system("cls");
            MainMenuH();
            break;
        }
    }
}


//**************************************************************************
//**************************************************************************
class FoodConer
{
public:
    virtual void getdata()=0;
};


class CofeeShop : public FoodConer
{
private:
    int CofeeCode;
    char CofeeName[20];
    float CofeePrice;
public:
    void getdata()
    {
        system("cls");
        BuyCofee();
    }
    void addCofee();
    void BuyCofee();
    void UpdateDetailCofee();
    void WriteCoffe();
    void DeleteDetailCofee();
};

void CofeeShop :: BuyCofee()
{
    system("cls");
    gotoxy(2,1);
    timeANDdate();
    CofeeShop Cobj;
    int temCid,Flag;
    float calc=0,countCalc=0,Ccont;
    int k=13,HmT,i;
    char d[25]="C O F E E   S H O P",prize;
    int j;

        gotoxy(48,6);
        for(j=0;j<15;j++)
        {
            Sleep(50);
            cout<<bd2;
        }
        cout<<" ";
        for(j=0;j<21;j++)
        {
           Sleep(50);
           cout<<d[j];
        }
       for(j=0;j<15;j++)
        {
           Sleep(50);
           cout<<bd2;
        }

    ifstream inCofee;
	inCofee.open("Cofee.dat",ios::binary | ios::in);

	if(!inCofee)
    {
        system("cls");
        gotoxy(75,27);
        cout<<"Record Not Found....!!!";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        if(getch()==13)
        {
            MainMenuH();
        }
        else
        {
            MainMenuH();
        }
    }
    else
    {

        gotoxy(40,10);
        cout<<"========================================================================================\n";
        gotoxy(40,11);
        cout<<"Coffee No                 Coffee Name                            Coffee Cost"<<endl;
        gotoxy(40,12);
        cout<<"========================================================================================\n";


            while(inCofee.read(reinterpret_cast<char *>(&Cobj),sizeof(CofeeShop)))
            {
                //cout<<endl;
                gotoxy(40,k);
                cout<<Cobj.CofeeCode<<setw(23)<<" "<<Cobj.CofeeName<<" "<<setw(36)<<Cobj.CofeePrice<<endl<<endl;
                k+=2;
            }
            inCofee.close();
        gotoxy(40,k);
        cout<<"========================================================================================\n";

        inCofee.open("Cofee.dat",ios::binary | ios::in);

//        cout<<"\n\t\t\t\t><. How Many Type You Want?: ";
//        cin>>HmT;
//        for(i=0; i<HmT; i++)
//        {
//            temCid = 0, Ccont = 0;
            cout<<"\n\t\t\t\t\t\t><. Enter the coffee code you want to buy: ";
            cin>>temCid;
            cout<<"\n\t\t\t\t\t\t><. How many coffees: ";
            cin>>Ccont;


            while(inCofee.read(reinterpret_cast<char *>(&Cobj),sizeof(CofeeShop)))
            {
                if(temCid==Cobj.CofeeCode)
                {
                    prize = Cobj.CofeePrice;
                    calc+=Ccont*float(prize);
                }
            }
            inCofee.close();
            cout<<"\n\t\t\t\t\t\tYOUR BILL IS: "<<calc;
//        }
        cout<<"\n\n\t\t\t\t\t\tIf you want to buy another coffee, press <y>..";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        switch(getch())
        {
        case 'Y':
        case 'y':
            Cobj.BuyCofee();
            break;
        case 13:
            system("cls");
            MainMenuH();
            break;
        default:
            system("cls");
            MainMenuH();
            break;
        }
    }
}

void CofeeShop :: addCofee()
{
    cout<<"\n\t\t\t\t     Enter The Cofee Name: ";
    cin>>CofeeName;
    cout<<"\n\t\t\t\t     Enter Cofee Price: ";
    cin>>CofeePrice;
}

void CofeeShop :: WriteCoffe()
{
    system("cls");
    gotoxy(2,1);
    timeANDdate();
    int i,CNo;
    CofeeShop Cobj;
    int k=13;
    ifstream inCofee;
	inCofee.open("Cofee.dat",ios::binary | ios::in);

	gotoxy(40,10);
	cout<<"========================================================================================\n";
	gotoxy(40,11);
    cout<<"Cofee No                 Cofee Name                              Cofee Cost"<<endl;
    gotoxy(40,12);
    cout<<"========================================================================================\n";


        while(inCofee.read(reinterpret_cast<char *>(&Cobj),sizeof(CofeeShop)))
        {
            //cout<<endl;
            gotoxy(40,k);
            cout<<Cobj.CofeeCode<<setw(23)<<" "<<Cobj.CofeeName<<setw(36)<<Cobj.CofeePrice<<endl<<endl;
            k+=2;
        }
        inCofee.close();
    gotoxy(40,k);
    cout<<"========================================================================================\n";

        ofstream outFile;
        ifstream inFile;
        outFile.open("Cofee.dat",ios::binary | ios::out | ios::app);
        inFile.open("Cofee.dat",ios::binary | ios::in);

        cout<<"\n\t\t\t\t     Enter The Cofee Code: ";
        cin>>CNo;

        while(inFile.read(reinterpret_cast<char *>(&Cobj),sizeof(CofeeShop)))
        {
            if(CNo==Cobj.CofeeCode)
            {
                cout<<"\n\t\t\t\t\t\tSorry!!! You cant Enter This Code";
                getch();
                Cobj.WriteCoffe();
            }
        }

        Cobj.CofeeCode=CNo;
        Cobj.addCofee();
        cout<<endl<<endl;
        outFile.write(reinterpret_cast<char *> (&Cobj), sizeof(CofeeShop));
        outFile.close();

    cout<<"\n\n\t\t\t\t\t\t If you want to add another Coffee, Press <y>..";
    gotoxy(168,48);
    cout<<"Press ENTER to return main menu..";
    switch (getch())
    {
    case 'y':
    case 'Y':
        Cobj.WriteCoffe();
        break;
    case 13:
        system("cls");
        MainMenuH();
        break;
    default:
        system("cls");
        MainMenuH();
        break;
    }
}

void CofeeShop :: UpdateDetailCofee()
{
    system("cls");
    gotoxy(2,1);
    timeANDdate();
    CofeeShop Cobj;
    int k=13;
    ifstream inCofee;
	inCofee.open("Cofee.dat",ios::binary | ios::in);

	if(!inCofee)
    {
        system("cls");
        gotoxy(75,27);
        cout<<"Record Not Found....!!!";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        if(getch()==13)
        {
            MainMenuH();
        }
        else
        {
            MainMenuH();
        }
    }
    else
    {

        gotoxy(40,10);
        cout<<"========================================================================================\n";
        gotoxy(40,11);
        cout<<"Cofee No                 Cofee Name                              Cofee Cost"<<endl;
        gotoxy(40,12);
        cout<<"========================================================================================\n";


            while(inCofee.read(reinterpret_cast<char *>(&Cobj),sizeof(CofeeShop)))
            {
                //cout<<endl;
                gotoxy(40,k);
                cout<<Cobj.CofeeCode<<setw(23)<<" "<<Cobj.CofeeName<<setw(36)<<Cobj.CofeePrice<<endl<<endl;
                k+=2;
            }
            inCofee.close();
        gotoxy(40,k);
        cout<<"========================================================================================\n";

        int d,i;

            cout<<"\n\n\t\t\t\t\t\t    Enter the coffee number you want to update: ";
            cin>>d;


            fstream File;
            File.open("Cofee.dat",ios::binary | ios::in | ios::out | ios::app);
            if(!File)
            {
                cout<<"\t\t\t\t\t\t Doesn't Found File!!!";
            }
            while(File.read(reinterpret_cast<char *>(&Cobj),sizeof(CofeeShop)))
            {
                if(d==Cobj.CofeeCode)
                {
                    system("cls");
                    gotoxy(20,7);
                    cout<<l<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<z;
                    gotoxy(20,8);
                    cout<<r<<endl;                                              gotoxy(60,8);cout<<r;
                    gotoxy(20,9);
                    cout<<r<<"The Coffee Code is: "<<Cobj.CofeeCode<<endl;            gotoxy(60,9);cout<<r;
                    gotoxy(20,10);
                    cout<<r<<"The Coffee Name is: "<<Cobj.CofeeName<<endl;            gotoxy(60,10);cout<<r;
                    gotoxy(20,11);
                    cout<<r<<"The Coffee Prize is: "<<Cobj.CofeePrice<<endl;            gotoxy(60,11);cout<<r;
                    gotoxy(20,12);
                    cout<<r<<endl;                                              gotoxy(60,12);cout<<r;
                    gotoxy(20,13);
                    cout<<s<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<t;

                    gotoxy(20,14);
                    cout<<"\t\t\t\t\t\t Enter The Coffee Code: ";
                    cin>>Cobj.CofeeCode;
                    Cobj.addCofee();

                    int pos=(-1)*static_cast<int>(sizeof(Cobj));
                    File.seekp(pos,ios::cur);
                    File.write(reinterpret_cast<char *> (&Cobj),sizeof(CofeeShop));
                    cout<<"RECORD UPDATED!"<<endl;
                }

            }
            File.close();

        cout<<"\n\n\t\t\t\t\t\t You Want To Update Again then press <y>..";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        switch(getch())
        {
        case 'Y':
        case 'y':
            Cobj.UpdateDetailCofee();
            break;
        case 13:
            system("cls");
            MainMenuH();
            break;
        default:
            system("cls");
            MainMenuH();
            break;
        }
    }
}

void CofeeShop :: DeleteDetailCofee()
{
    CofeeShop Cobj;
    system("cls");
    gotoxy(2,1);
    timeANDdate();
    int k=13;
    ifstream inCofee;
	inCofee.open("Cofee.dat",ios::binary | ios::in);

	if(!inCofee)
    {
        system("cls");
        gotoxy(75,27);
        cout<<"Record Not Found....!!!";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        if(getch()==13)
        {
            MainMenuH();
        }
        else
        {
            MainMenuH();
        }
    }
    else
    {

        gotoxy(40,10);
        cout<<"========================================================================================\n";
        gotoxy(40,11);
        cout<<"Cofee No                 Cofee Name                              Cofee Cost"<<endl;
        gotoxy(40,12);
        cout<<"========================================================================================\n";


            while(inCofee.read(reinterpret_cast<char *>(&Cobj),sizeof(CofeeShop)))
            {
                //cout<<endl;
                gotoxy(40,k);
                cout<<Cobj.CofeeCode<<setw(23)<<" "<<Cobj.CofeeName<<setw(36)<<Cobj.CofeePrice<<endl<<endl;
                k+=2;
            }
            inCofee.close();
        gotoxy(40,k);
        cout<<"========================================================================================\n";

        int CId;
            cout<<"\n\t\t\t\t\t\t Enter the Coffee code you want to Delete: ";
            cin>>CId;
            ifstream inFile;
            inFile.open("Cofee.dat",ios::binary);

            if(!inFile)
            {
                cout<<"\t\t\t\t\t\t File Does Not Found";
                Cobj.DeleteDetailCofee();
            }

            ofstream outFile;
            outFile.open("tempCofee.dat",ios::binary | ios::out | ios::app);
            inFile.seekg(0,ios::beg);

            while(inFile.read(reinterpret_cast<char *>(&Cobj),sizeof(CofeeShop)))
            {
                if(CId!=Cobj.CofeeCode)
                {
                    outFile.write(reinterpret_cast<char *>(&Cobj),sizeof(CofeeShop));
                }
            }

            outFile.close();
            inFile.close();
            remove("Cofee.dat");
            rename("tempCofee.dat","Cofee.dat");
            cout<<"\t\t\t\t\t\t Record Deleted Successfully!!!!"<<endl<<endl;

        cout<<"\n\n\t\t\t\t\t\t You Want To Delete Again then press <y>..";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        switch(getch())
        {
        case 'Y':
        case 'y':
            system("cls");
            Cobj.DeleteDetailCofee();
            break;
        case 13:
            system("cls");
            MainMenuH();
            break;
        default:
            system("cls");
            MainMenuH();
            break;
        }
    }
}


class FruitJuice : public FoodConer
{
private:
    int JuiceCode;
    char JuiceName[20];
    float JuicePrice;
public:
    void getdata()
    {
        system("cls");
        BuyJuice();
    }
    void addFruitJuice();
    void BuyJuice();
    void WriteJuices();
    void UpdateDetailFruit();
    void DeleteDetailFruit();
};

void FruitJuice :: BuyJuice()
{
    gotoxy(2,1);
    timeANDdate();
    FruitJuice Fobj;
    int temFid;
    float calc=0,countCalc=0,Fcont;
    int k=13,HmT,i;
    char d[25]="F R U I T   J U I C E";
    int j;

        gotoxy(48,6);
        for(j=0;j<15;j++)
        {
            Sleep(50);
            cout<<bd2;
        }
        cout<<" ";
        for(j=0;j<23;j++)
        {
           Sleep(50);
           cout<<d[j];
        }
       for(j=0;j<15;j++)
        {
           Sleep(50);
           cout<<bd2;
        }

    ifstream inFruit;
	inFruit.open("Fruit.dat",ios::binary | ios::in);

	if(!inFruit)
    {
        system("cls");
        gotoxy(75,27);
        cout<<"Record Not Found....!!!";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        if(getch()==13)
        {
            MainMenuH();
        }
        else
        {
            MainMenuH();
        }
    }
    else
    {

        gotoxy(40,10);
        cout<<"========================================================================================\n";
        gotoxy(40,11);
        cout<<"Fruit Juice No             Fruit Juice Name                 Fruit Juice Cost"<<endl;
        gotoxy(40,12);
        cout<<"========================================================================================\n";


            while(inFruit.read(reinterpret_cast<char *>(&Fobj),sizeof(FruitJuice)))
            {
                gotoxy(40,k);
                cout<<Fobj.JuiceCode<<setw(23)<<" "<<Fobj.JuiceName<<setw(33)<<Fobj.JuicePrice<<endl<<endl;
                k+=2;
            }
            inFruit.close();
        gotoxy(40,k);
        cout<<"========================================================================================\n";

        ifstream inFruite;
        inFruite.open("Fruit.dat",ios::binary | ios::in);

        //cout<<"How Many Type You Want?: ";
        //cin>>HmT;
        //for(i=0; i<HmT; i++)
        //{
            cout<<"\n\n\t\t\t\t\t\tEnter the juice code you want to buy: ";
            cin>>temFid;
            cout<<"\t\t\t\t\t\tHow many Juice: ";
            cin>>Fcont;
            while(inFruite.read(reinterpret_cast<char *>(&Fobj),sizeof(FruitJuice)))
            {
                if(temFid==Fobj.JuiceCode)
                {
                    calc=+Fcont*Fobj.JuicePrice;
                }
            }
        //}
        inFruite.close();
        cout<<"\n\t\t\t\t\t\tYOUR BILL IS: "<<calc;
        cout<<"\n\n\t\t\tIf you want to buy another juice, press <y>..";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        switch(getch())
        {
        case 'Y':
        case 'y':
            Fobj.BuyJuice();
            break;
        case 13:
            system("cls");
            MainMenuH();
            break;
        default:
            system("cls");
            MainMenuH();
            break;
        }
    }
}

void FruitJuice :: addFruitJuice()
{
    cout<<"\t\t\t\t\t\t Enter The Juice Name: ";
    cin>>JuiceName;
    cout<<"\t\t\t\t\t\t Enter Juice Price: ";
    cin>>JuicePrice;
}

void FruitJuice :: WriteJuices()
{
    system("cls");
    gotoxy(2,1);
    timeANDdate();
    int i,j,FNo;
    FruitJuice Fobj;
    int k=13;

    ifstream inFruit;
	inFruit.open("Fruit.dat",ios::binary | ios::in);

	gotoxy(40,10);
	cout<<"========================================================================================\n";
	gotoxy(40,11);
    cout<<"Fruit Juice No             Fruit Juice Name                 Fruit Juice Cost"<<endl;
    gotoxy(40,12);
    cout<<"========================================================================================\n";


        while(inFruit.read(reinterpret_cast<char *>(&Fobj),sizeof(FruitJuice)))
        {
            gotoxy(40,k);
            cout<<Fobj.JuiceCode<<setw(23)<<" "<<Fobj.JuiceName<<setw(33)<<Fobj.JuicePrice<<endl<<endl;
            k+=2;
        }
        inFruit.close();
    gotoxy(40,k);
    cout<<"========================================================================================\n";

        ofstream outFile;
        ifstream inFile;
        outFile.open("Fruit.dat",ios::binary | ios::out | ios::app);
        inFile.open("Fruit.dat",ios::binary | ios::in);

        cout<<"\t\t\t\t\t\t Enter The Fruit Code: ";
        cin>>FNo;

        while(inFile.read(reinterpret_cast<char *>(&Fobj),sizeof(FruitJuice)))
        {
            if(FNo==Fobj.JuiceCode)
            {
                cout<<"\t\t\t\t\t\t Sorry!!! You cant Enter This Code";
                getch();
                Fobj.WriteJuices();
            }
        }

        Fobj.JuiceCode=FNo;
        Fobj.addFruitJuice();
        cout<<endl<<endl;
        outFile.write(reinterpret_cast<char *> (&Fobj), sizeof(FruitJuice));
        outFile.close();

    cout<<"\n\n\t\t\t\t\t\t If you want to add another juice, Press <y>..";
    gotoxy(168,48);
    cout<<"Press ENTER to return main menu..";
    switch (getch())
    {
    case 'y':
    case 'Y':
        Fobj.WriteJuices();
        break;
    case 13:
        system("cls");
        MainMenuH();
        break;
    default:
        system("cls");
        MainMenuH();
        break;
    }
}

void FruitJuice :: UpdateDetailFruit()
{
    system("cls");
    gotoxy(2,1);
    timeANDdate();
    FruitJuice Fobj;
    int k=13;

    ifstream inFruit;
	inFruit.open("Fruit.dat",ios::binary | ios::in);

	if(!inFruit)
    {
        system("cls");
        gotoxy(75,27);
        cout<<"Record Not Found....!!!";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        if(getch()==13)
        {
            MainMenuH();
        }
        else
        {
            MainMenuH();
        }
    }
    else
    {

        gotoxy(40,10);
        cout<<"========================================================================================\n";
        gotoxy(40,11);
        cout<<"Fruit Juice No             Fruit Juice Name                 Fruit Juice Cost"<<endl;
        gotoxy(40,12);
        cout<<"========================================================================================\n";


            while(inFruit.read(reinterpret_cast<char *>(&Fobj),sizeof(FruitJuice)))
            {
                gotoxy(40,k);
                cout<<Fobj.JuiceCode<<setw(23)<<" "<<Fobj.JuiceName<<setw(33)<<Fobj.JuicePrice<<endl<<endl;
                k+=2;
            }
            inFruit.close();
        gotoxy(40,k);
        cout<<"========================================================================================\n";

        int d;

            cout<<"\n\n\t\t\t\t\t\t Enter juice code you want to update : ";
            cin>>d;

            fstream File;
            File.open("Fruit.dat",ios::binary | ios::in | ios::out | ios::app);
            if(!File)
            {
                cout<<"\t\t\t\t\t\t Doesn't Found File!!!";
            }
            while(File.read(reinterpret_cast<char *>(&Fobj),sizeof(FruitJuice)))
            {
                if(d==Fobj.JuiceCode)
                {
                    system("cls");
                    gotoxy(20,7);
                    cout<<l<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<z;
                    gotoxy(20,8);
                    cout<<r<<endl;                                              gotoxy(60,8);cout<<r;
                    gotoxy(20,9);
                    cout<<r<<"The Juice Code is: "<<Fobj.JuiceCode<<endl;            gotoxy(60,9);cout<<r;
                    gotoxy(20,10);
                    cout<<r<<"The Juice Name is: "<<Fobj.JuiceName<<endl;            gotoxy(60,10);cout<<r;
                    gotoxy(20,11);
                    cout<<r<<"The Juice Prize is: "<<Fobj.JuicePrice<<endl;            gotoxy(60,11);cout<<r;
                    gotoxy(20,12);
                    cout<<r<<endl;                                              gotoxy(60,12);cout<<r;
                    gotoxy(20,13);
                    cout<<s<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<t;

                    gotoxy(20,14);
                    cout<<"Enter The Juice Code: ";
                    cin>>Fobj.JuiceCode;
                    Fobj.addFruitJuice();

                    int pos=(-1)*static_cast<int>(sizeof(Fobj));
                    File.seekp(pos,ios::cur);
                    File.write(reinterpret_cast<char *> (&Fobj),sizeof(FruitJuice));
                    cout<<"RECORD UPDATED SUCCESSFULLY!!!!"<<endl;
                }

            }
            File.close();

        cout<<"\n\n\t\t\t\t\t\t You Want To Update Again,Press <y>..";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        switch(getch())
        {
        case 'Y':
        case 'y':
            Fobj.UpdateDetailFruit();
            break;
        case 13:
            system("cls");
            MainMenuH();
            break;
        default:
            system("cls");
            MainMenuH();
            break;
        }
    }
}

void FruitJuice :: DeleteDetailFruit()
{
    FruitJuice Fobj;
    system("cls");
    gotoxy(2,1);
    timeANDdate();
    int k=13;

    ifstream inFruit;
	inFruit.open("Fruit.dat",ios::binary | ios::in);

	if(!inFruit)
    {
        system("cls");
        gotoxy(75,27);
        cout<<"Record Not Found....!!!";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        if(getch()==13)
        {
            MainMenuH();
        }
        else
        {
            MainMenuH();
        }
    }
    else
    {

        gotoxy(40,10);
        cout<<"========================================================================================\n";
        gotoxy(40,11);
        cout<<"Fruit Juice No             Fruit Juice Name                 Fruit Juice Cost"<<endl;
        gotoxy(40,12);
        cout<<"========================================================================================\n";


            while(inFruit.read(reinterpret_cast<char *>(&Fobj),sizeof(FruitJuice)))
            {
                gotoxy(40,k);
                cout<<Fobj.JuiceCode<<setw(23)<<" "<<Fobj.JuiceName<<setw(33)<<Fobj.JuicePrice<<endl<<endl;
                k+=2;
            }
            inFruit.close();
        gotoxy(40,k);
        cout<<"========================================================================================\n";
        int FId;

            cout<<"\n\t\t\t\t\t\t Enter the juice code you want to Delete: ";
            cin>>FId;
            ifstream inFile;
            inFile.open("Fruit.dat",ios::binary | ios::in);

            if(!inFile)
            {
                cout<<"\t\t\t\t\t\t File Does Not Found";
                Fobj.DeleteDetailFruit();
            }

            ofstream outFile;
            outFile.open("tempFruit.dat",ios::binary | ios::out | ios::app);
            inFile.seekg(0,ios::beg);

            while(inFile.read(reinterpret_cast<char *>(&Fobj),sizeof(FruitJuice)))
            {
                if(FId!=Fobj.JuiceCode)
                {
                    outFile.write(reinterpret_cast<char *>(&Fobj),sizeof(FruitJuice));
                }
            }

            outFile.close();
            inFile.close();
            remove("Fruit.dat");
            rename("tempFruit.dat","Fruit.dat");
            cout<<"Record Deleted Successfully!!!!"<<endl<<endl;

        cout<<"\n\n\t\t\t\t\t\t You Want To Delete Again then press <y>..";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        switch(getch())
        {
        case 'Y':
        case 'y':
            system("cls");
            Fobj.DeleteDetailFruit();
            break;
        case 13:
            system("cls");
            MainMenuH();
            break;
        default:
            system("cls");
            MainMenuH();
            break;
        }
    }
}


class BrekFast : public FoodConer
{
private:
    int BrekfastCode;
    char BrekfastName[20];
    float BrekfastPrice;
public:
    void getdata()
    {
        system("cls");
        BuyBrekfast();
    }
    void addBrekfast();
    void BuyBrekfast();
    void WriteBrekfast();
    void UpdateDetailBrekfast();
    void DeleteDetailBrekfast();
};

void BrekFast :: BuyBrekfast()
{
    gotoxy(2,1);
    timeANDdate();
    BrekFast Bobj;
    int temBid,HmT,i;
    float calc=0,countCalc=0,Bcont;
    int k=13;
    char d[25]="B R E A K F A S T";
    int j;

        gotoxy(48,6);
        for(j=0;j<15;j++)
        {
            Sleep(50);
            cout<<bd2;
        }
        cout<<" ";
        for(j=0;j<19;j++)
        {
           Sleep(50);
           cout<<d[j];
        }
       for(j=0;j<15;j++)
        {
           Sleep(50);
           cout<<bd2;
        }

    ifstream inBrekfast;
	inBrekfast.open("Brekfast.dat",ios::binary | ios::in);

	if(!inBrekfast)
    {
        system("cls");
        gotoxy(75,27);
        cout<<"Record Not Found....!!!";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        if(getch()==13)
        {
            MainMenuH();
        }
        else
        {
            MainMenuH();
        }
    }
    else
    {

        gotoxy(40,10);
        cout<<"========================================================================================\n";
        gotoxy(40,11);
        cout<<"Breakfast No             Breakfast Name                              Breakfast Cost"<<endl;
        gotoxy(40,12);
        cout<<"========================================================================================\n";


            while(inBrekfast.read(reinterpret_cast<char *>(&Bobj),sizeof(BrekFast)))
            {
                gotoxy(40,k);
                cout<<Bobj.BrekfastCode<<setw(23)<<" "<<Bobj.BrekfastName<<setw(33)<<Bobj.BrekfastPrice<<endl<<endl;
                k+=2;
            }
            inBrekfast.close();
        gotoxy(40,k);
        cout<<"========================================================================================\n";

        inBrekfast.open("Brekfast.dat",ios::binary | ios::in);

        //cout<<"How Many Type You Want?: ";
        //cin>>HmT;
        //for(i=0; i<HmT; i++)
        //{
            cout<<"\n\n\t\t\t\t\t\tEnter the breakfast code you want to buy: ";
            cin>>temBid;
            cout<<"\t\t\t\t\t\tHow many portions: ";
            cin>>Bcont;
            while(inBrekfast.read(reinterpret_cast<char *>(&Bobj),sizeof(BrekFast)))
            {
                if(temBid==Bobj.BrekfastCode)
                {
                    calc=+Bcont*Bobj.BrekfastPrice;
                }
            }
        //}
        inBrekfast.close();
        cout<<"\n\t\t\t\t\t\tYOUR BILL AMOUNT IS: "<<calc;
        cout<<"\n\n\t\t\t\t\t\tIf you want to buy another breakfast, press <y>..";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        switch(getch())
        {
        case 'Y':
        case 'y':
            Bobj.BuyBrekfast();
            break;
        case 13:
            system("cls");
            MainMenuH();
            break;
        default:
            system("cls");
            MainMenuH();
            break;
        }
    }
}

void BrekFast :: addBrekfast()
{
    cout<<"\t\t\t\t\t\t Enter The Brekfast Name: ";
    cin>>BrekfastName;
    cout<<"\t\t\t\t\t\t Enter Brekfast Price: ";
    cin>>BrekfastPrice;
}

void BrekFast :: WriteBrekfast()
{
    system("cls");
    gotoxy(2,1);
    timeANDdate();
    int BNo,k=13;
    BrekFast Bobj;

        ofstream outFile;
        ifstream inFile;
        outFile.open("Brekfast.dat",ios::binary | ios::out | ios::app);
        inFile.open("Brekfast.dat",ios::binary | ios::in);

        gotoxy(40,10);
        cout<<"========================================================================================\n";
        gotoxy(40,11);
        cout<<"Breakfast No             Breakfast Name                 Breakfast Cost"<<endl;
        gotoxy(40,12);
        cout<<"========================================================================================\n";


            while(inFile.read(reinterpret_cast<char *>(&Bobj),sizeof(BrekFast)))
            {
                gotoxy(40,k);
                cout<<Bobj.BrekfastCode<<setw(23)<<" "<<Bobj.BrekfastName<<setw(33)<<Bobj.BrekfastPrice<<endl<<endl;
                k+=2;
            }
            inFile.close();
        gotoxy(40,k);
        cout<<"========================================================================================\n";

        inFile.open("Brekfast.dat",ios::binary |ios::in);

        cout<<"\t\t\t\t\t\t Enter The Breakfast Code: ";
        cin>>BNo;

        while(inFile.read(reinterpret_cast<char *>(&Bobj),sizeof(BrekFast)))
        {
            if(BNo==Bobj.BrekfastCode)
            {
                cout<<"\t\t\t\t\t\t Sorry, You can't enter this code";
                getch();
                Bobj.WriteBrekfast();
            }
        }

        Bobj.BrekfastCode=BNo;
        Bobj.addBrekfast();
        cout<<endl<<endl;
        outFile.write(reinterpret_cast<char *> (&Bobj), sizeof(BrekFast));
        outFile.close();

    cout<<"\n\n\t\t\t\t\t\t If you want to order another breakfast, press <y>..";
    gotoxy(168,48);
    cout<<"Press ENTER to return main menu..";
    switch (getch())
    {
    case 'y':
    case 'Y':
        Bobj.WriteBrekfast();
        break;
    case 13:
        system("cls");
        MainMenuH();
        break;
    default:
        system("cls");
        MainMenuH();
        break;
    }
}

void BrekFast :: UpdateDetailBrekfast()
{
    system("cls");
    gotoxy(2,1);
    timeANDdate();
    BrekFast Bobj;
    int k=13;

    ifstream inBrekfast;
	inBrekfast.open("Brekfast.dat",ios::binary | ios::in);

	if(!inBrekfast)
    {
        system("cls");
        gotoxy(75,27);
        cout<<"Record Not Found....!!!";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        if(getch()==13)
        {
            MainMenuH();
        }
        else
        {
            MainMenuH();
        }
    }
    else
    {

        gotoxy(40,10);
        cout<<"========================================================================================\n";
        gotoxy(40,11);
        cout<<"Breakfast No             Breakfast Name                 Breakfast Cost"<<endl;
        gotoxy(40,12);
        cout<<"========================================================================================\n";


            while(inBrekfast.read(reinterpret_cast<char *>(&Bobj),sizeof(BrekFast)))
            {
                gotoxy(40,k);
                cout<<Bobj.BrekfastCode<<setw(23)<<" "<<Bobj.BrekfastName<<setw(33)<<Bobj.BrekfastPrice<<endl<<endl;
                k+=2;
            }
            inBrekfast.close();
        gotoxy(40,k);
        cout<<"========================================================================================\n";

        int d;

            cout<<"\n\n\t\t\t\t\t\t Enter breakfast code you want to update: ";
            cin>>d;

            fstream File;
            File.open("Brekfast.dat",ios::binary | ios::in | ios::out | ios::app);
            if(!File)
            {
                cout<<"File Doesn't Found!";
            }
            while(File.read(reinterpret_cast<char *>(&Bobj),sizeof(BrekFast)))
            {
                if(d==Bobj.BrekfastCode)
                {
                    system("cls");
                    gotoxy(20,7);
                    cout<<l<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<z;
                    gotoxy(20,8);
                    cout<<r<<endl;                                              gotoxy(60,8);cout<<r;
                    gotoxy(20,9);
                    cout<<r<<"Breakfast Code is: "<<Bobj.BrekfastCode<<endl;            gotoxy(60,9);cout<<r;
                    gotoxy(20,10);
                    cout<<r<<"Breakfast Name is: "<<Bobj.BrekfastName<<endl;            gotoxy(60,10);cout<<r;
                    gotoxy(20,11);
                    cout<<r<<"Breakfast Price is: "<<Bobj.BrekfastPrice<<endl;            gotoxy(60,11);cout<<r;
                    gotoxy(20,12);
                    cout<<r<<endl;                                              gotoxy(60,12);cout<<r;
                    gotoxy(20,13);
                    cout<<s<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<t;

                    gotoxy(20,14);
                    cout<<"\t\t\t\t\t\t Enter The Breakfast Code: ";
                    cin>>Bobj.BrekfastCode;
                    Bobj.addBrekfast();

                    int pos=(-1)*static_cast<int>(sizeof(Bobj));
                    File.seekp(pos,ios::cur);
                    File.write(reinterpret_cast<char *> (&Bobj),sizeof(BrekFast));
                    cout<<"RECORD UPDATED!"<<endl;
                }

            }
            File.close();

        cout<<"\n\n\t\t\t\t\t\t If you want to update again, press <y>..";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        switch(getch())
        {
        case 'Y':
        case 'y':
            Bobj.UpdateDetailBrekfast();
            break;
        case 13:
            system("cls");
            MainMenuH();
            break;
        default:
            system("cls");
            MainMenuH();
            break;
        }
    }
}

void BrekFast :: DeleteDetailBrekfast()
{
    int i,j;
    BrekFast Bobj;
    system("cls");
    gotoxy(2,1);
    timeANDdate();
    int k=13;
    ifstream inBrekfast;
	inBrekfast.open("Brekfast.dat",ios::binary | ios::in);

	if(!inBrekfast)
    {
        system("cls");
        gotoxy(75,27);
        cout<<"Record Not Found....!!!";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        if(getch()==13)
        {
            MainMenuH();
        }
        else
        {
            MainMenuH();
        }
    }
    else
    {

        gotoxy(40,10);
        cout<<"========================================================================================\n";
        gotoxy(40,11);
        cout<<"Breakfast No             Brekafast Name                 Breakfast Cost"<<endl;
        gotoxy(40,12);
        cout<<"========================================================================================\n";


            while(inBrekfast.read(reinterpret_cast<char *>(&Bobj),sizeof(BrekFast)))
            {
                gotoxy(40,k);
                cout<<Bobj.BrekfastCode<<setw(23)<<" "<<Bobj.BrekfastName<<setw(33)<<Bobj.BrekfastPrice<<endl<<endl;
                k+=2;
            }
            inBrekfast.close();
        gotoxy(40,k);
        cout<<"========================================================================================\n";

        int BId;

            cout<<"\n\t\t\t\t\t\t Enter the Breakfast code you want to delete: ";
            cin>>BId;
            ifstream inFile;
            inFile.open("Brekfast.dat",ios::binary | ios::in);

            if(!inFile)
            {
                cout<<"File Does Not Found";
                Bobj.DeleteDetailBrekfast();
            }

            ofstream outFile;
            outFile.open("tempBrekfast.dat",ios::binary | ios::out | ios::app);
            inFile.seekg(0,ios::beg);

            while(inFile.read(reinterpret_cast<char *>(&Bobj),sizeof(BrekFast)))
            {
                if(BId!=Bobj.BrekfastCode)
                {
                    outFile.write(reinterpret_cast<char *>(&Bobj),sizeof(BrekFast));
                }
            }

            outFile.close();
            inFile.close();
            remove("Brekfast.dat");
            rename("tempBrekfast.dat","Brekfast.dat");
            cout<<"Record Deleted Successfully!!!!"<<endl<<endl;

        cout<<"\n\n\t\t\t\t\t\t If you want to delete again, press <y>..";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        switch(getch())
        {
        case 'Y':
        case 'y':
            system("cls");
            Bobj.DeleteDetailBrekfast();
            break;
        case 13:
            system("cls");
            MainMenuH();
            break;
        default:
            system("cls");
            MainMenuH();
            break;
        }
    }
}

class Lunch : public FoodConer
{
private:
    int lunchCode;
    char lunchName[20];
    float lunchPrice;
public:
    void getdata()
    {
        system("cls");
        Buylunch();
    }
    void addlunch();
    void Buylunch();
    void Writelunch();
    void UpdateDetaillunch();
    void DeleteDetaillunch();
};

void Lunch :: Buylunch()
{
    gotoxy(2,1);
    timeANDdate();
    Lunch Lobj;
    int temLid,HmT,i;
    float calc=0,countCalc=0,Lcont;
    int k=13;
    char d[25]="L U N C H";
    int j;

        gotoxy(48,6);
        for(j=0;j<15;j++)
        {
            Sleep(50);
            cout<<bd2;
        }
        cout<<" ";
        for(j=0;j<11;j++)
        {
           Sleep(50);
           cout<<d[j];
        }
       for(j=0;j<15;j++)
        {
           Sleep(50);
           cout<<bd2;
        }

    ifstream inlunch;
	inlunch.open("lunch.dat",ios::binary | ios::in);

	if(!inlunch)
    {
        system("cls");
        gotoxy(75,27);
        cout<<"Record Not Found....!!!";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        if(getch()==13)
        {
            MainMenuH();
        }
        else
        {
            MainMenuH();
        }
    }
    else
    {

        gotoxy(40,10);
        cout<<"========================================================================================\n";
        gotoxy(40,11);
        cout<<"Lunch No                         Lunch Name                                  Lunch Cost"<<endl;
        gotoxy(40,12);
        cout<<"========================================================================================\n";


            while(inlunch.read(reinterpret_cast<char *>(&Lobj),sizeof(Lunch)))
            {
                gotoxy(40,k);
                cout<<Lobj.lunchCode<<setw(23)<<" "<<Lobj.lunchName<<setw(33)<<Lobj.lunchPrice<<endl<<endl;
                k+=2;
            }
            inlunch.close();
        gotoxy(40,k);
        cout<<"========================================================================================\n";

        inlunch.open("lunch.dat",ios::binary | ios::in);

        //cout<<"How Many Type You Want?: ";
        //cin>>HmT;
        //for(i=0; i<HmT; i++)
        //{
            cout<<"\n\n\t\t\t\t\t\tEnter the lunch code you want to buy: ";
            cin>>temLid;
            cout<<"\t\t\t\t\t\tHow many portions: ";
            cin>>Lcont;
            while(inlunch.read(reinterpret_cast<char *>(&Lobj),sizeof(Lunch)))
            {
                if(temLid==Lobj.lunchCode)
                {
                    calc=+Lcont*Lobj.lunchPrice;
                }
            }
        //}
        inlunch.close();
        cout<<"\n\t\t\t\t\t\tYOUR BILL AMOUNT IS: "<<calc;
        cout<<"\n\n\t\t\t\t\t\tIf you want to buy another lunch, press <y>...";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        switch(getch())
        {
        case 'Y':
        case 'y':
            Lobj.Buylunch();
            break;
        case 13:
            system("cls");
            MainMenuH();
            break;
        default:
            system("cls");
            MainMenuH();
            break;
        }
    }
}

void Lunch :: addlunch()
{
    cout<<"\t\t\t\t\t\t Enter The Lunch Name: ";
    cin>>lunchName;
    cout<<"\t\t\t\t\t\t Enter Lunch Price: ";
    cin>>lunchPrice;
}

void Lunch :: Writelunch()
{
    system("cls");
    gotoxy(2,1);
    timeANDdate();
    int LNo,k=13;
    Lunch Lobj;

        ofstream outFile;
        ifstream inFile;
        outFile.open("lunch.dat",ios::binary | ios::app);
        inFile.open("lunch.dat",ios::binary | ios::in);

        gotoxy(40,10);
        cout<<"========================================================================================\n";
        gotoxy(40,11);
        cout<<"Lunch No                         Lunch Name                                  Lunch Cost"<<endl;
        gotoxy(40,12);
        cout<<"========================================================================================\n";


            while(inFile.read(reinterpret_cast<char *>(&Lobj),sizeof(Lunch)))
            {
                gotoxy(40,k);
                cout<<Lobj.lunchCode<<setw(23)<<" "<<Lobj.lunchName<<setw(33)<<Lobj.lunchPrice<<endl<<endl;
                k+=2;
            }
            inFile.close();
        gotoxy(40,k);
        cout<<"========================================================================================\n";

        inFile.open("lunch.dat",ios::binary | ios::in);

        cout<<"\t\t\t\t\t\t Enter The Lunch Code: ";
        cin>>LNo;

        while(inFile.read(reinterpret_cast<char *>(&Lobj),sizeof(Lunch)))
        {
            if(LNo==Lobj.lunchCode)
            {
                cout<<"Sorry!!! You cant Enter This Code";
                getch();
                Lobj.Writelunch();
            }
        }

        Lobj.lunchCode=LNo;
        Lobj.addlunch();
        cout<<endl<<endl;
        outFile.write(reinterpret_cast<char *> (&Lobj), sizeof(Lunch));
        outFile.close();

    cout<<"\n\n\t\t\t\t\t\t If you want to add another lunch the you press <y>..";
    gotoxy(168,48);
    cout<<"Press ENTER to return main menu..";
    switch (getch())
    {
    case 'y':
    case 'Y':
        Lobj.Writelunch();
        break;
    case 13:
        system("cls");
        MainMenuH();
        break;
    default:
        system("cls");
        MainMenuH();
        break;
    }
}

void Lunch :: UpdateDetaillunch()
{
    system("cls");
    gotoxy(2,1);
    timeANDdate();
    Lunch Lobj;
    int k=13;
    ifstream inlunch;
	inlunch.open("lunch.dat",ios::binary | ios::in);

	if(!inlunch)
    {
        system("cls");
        gotoxy(75,27);
        cout<<"Record Not Found....!!!";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        if(getch()==13)
        {
            MainMenuH();
        }
        else
        {
            MainMenuH();
        }
    }
    else
    {

        gotoxy(40,10);
        cout<<"========================================================================================\n";
        gotoxy(40,11);
        cout<<"Lunch No                         Lunch Name                                  Lunch Cost"<<endl;
        gotoxy(40,12);
        cout<<"========================================================================================\n";


            while(inlunch.read(reinterpret_cast<char *>(&Lobj),sizeof(Lunch)))
            {
                gotoxy(40,k);
                cout<<Lobj.lunchCode<<setw(23)<<" "<<Lobj.lunchName<<setw(33)<<Lobj.lunchPrice<<endl<<endl;
                k+=2;
            }
            inlunch.close();
        gotoxy(40,k);
        cout<<"========================================================================================\n";

        int d;

            cout<<"\n\n\t\t\t\t\t\t Enter lunch number you want to update: ";
            cin>>d;

            fstream File;
            File.open("Brekfast.dat",ios::binary | ios::in | ios::out | ios::app);
            if(!File)
            {
                cout<<"File Doesn't Found !!!";
            }
            while(File.read(reinterpret_cast<char *>(&Lobj),sizeof(Lunch)))
            {
                if(d==Lobj.lunchCode)
                {
                    system("cls");
                    gotoxy(20,7);
                    cout<<l<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<z;
                    gotoxy(20,8);
                    cout<<r<<endl;                                              gotoxy(60,8);cout<<r;
                    gotoxy(20,9);
                    cout<<r<<"The Lunch Code is: "<<Lobj.lunchCode<<endl;            gotoxy(60,9);cout<<r;
                    gotoxy(20,10);
                    cout<<r<<"The Lunch Name is: "<<Lobj.lunchName<<endl;            gotoxy(60,10);cout<<r;
                    gotoxy(20,11);
                    cout<<r<<"The Lunch Prize is: "<<Lobj.lunchPrice<<endl;            gotoxy(60,11);cout<<r;
                    gotoxy(20,12);
                    cout<<r<<endl;                                              gotoxy(60,12);cout<<r;
                    gotoxy(20,13);
                    cout<<s<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<t;

                    gotoxy(20,14);
                    cout<<"\t\t\t\t\t\t Enter The Lunch Code: ";
                    cin>>Lobj.lunchCode;
                    Lobj.addlunch();

                    int pos=(-1)*static_cast<int>(sizeof(Lobj));
                    File.seekp(pos,ios::cur);
                    File.write(reinterpret_cast<char *> (&Lobj),sizeof(Lunch));
                    cout<<"RECORD UPDATED SUCESSFULY!!!!"<<endl;
                }

            }
            File.close();

        cout<<"\n\n\t\t\t\t\t\t You Want To Update Again then press <y>..";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        switch(getch())
        {
        case 'Y':
        case 'y':
            Lobj.UpdateDetaillunch();
            break;
        case 13:
            system("cls");
            MainMenuH();
            break;
        default:
            system("cls");
            MainMenuH();
            break;
        }
    }
}

void Lunch :: DeleteDetaillunch()
{

    Lunch Lobj;
    system("cls");
    gotoxy(2,1);
    timeANDdate();
    int k=13;

    ifstream inlunch;
	inlunch.open("lunch.dat",ios::binary | ios::in);

	if(!inlunch)
    {
        system("cls");
        gotoxy(75,27);
        cout<<"Record Not Found....!!!";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        if(getch()==13)
        {
            MainMenuH();
        }
        else
        {
            MainMenuH();
        }
    }
    else
    {

        gotoxy(40,10);
        cout<<"========================================================================================\n";
        gotoxy(40,11);
        cout<<"Lunch No                         Lunch Name                                  Lunch Cost"<<endl;
        gotoxy(40,12);
        cout<<"========================================================================================\n";


            while(inlunch.read(reinterpret_cast<char *>(&Lobj),sizeof(Lunch)))
            {
                gotoxy(40,k);
                cout<<Lobj.lunchCode<<setw(23)<<" "<<Lobj.lunchName<<setw(33)<<Lobj.lunchPrice<<endl<<endl;
                k+=2;
            }
            inlunch.close();
        gotoxy(40,k);
        cout<<"========================================================================================\n";


        int LId;

            cout<<"\n\t\t\t\t\t\t Enter the Lunch Code You want to Delete: ";
            cin>>LId;
            ifstream inFile;
            inFile.open("lunch.dat",ios::binary | ios::in);

            if(!inFile)
            {
                cout<<"File Does Not Found";
                Lobj.DeleteDetaillunch();
            }

            ofstream outFile;
            outFile.open("templunch.dat",ios::binary | ios::out | ios::app);
            inFile.seekg(0,ios::beg);

            while(inFile.read(reinterpret_cast<char *>(&Lobj),sizeof(Lunch)))
            {
                if(LId!=Lobj.lunchCode)
                {
                    outFile.write(reinterpret_cast<char *>(&Lobj),sizeof(Lunch));
                }
            }

            outFile.close();
            inFile.close();
            remove("lunch.dat");
            rename("templunch.dat","lunch.dat");
            cout<<"Record Deleted Successfully!!!!"<<endl<<endl;

        cout<<"\n\n\t\t\t\t\t\t You Want To Delete Again then press <y>..";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        switch(getch())
        {
        case 'Y':
        case 'y':
            system("cls");
            Lobj.DeleteDetaillunch();
            break;
        case 13:
            system("cls");
            MainMenuH();
            break;
        default:
            system("cls");
            MainMenuH();
            break;
        }
    }
}

class Dinner : public FoodConer
{
private:
    int dinnerCode;
    char dinnerName[20];
    float dinnerPrice;
public:
    void getdata()
    {
        system("cls");
        Buydinner();
    }
    void adddinner();
    void Buydinner();
    void Writedinner();
    void UpdateDetaildinner();
    void DeleteDetaildinner();
};

void Dinner :: Buydinner()
{

    gotoxy(2,1);
    timeANDdate();
    Dinner Dobj;
    int temDid,HmT,i;
    float calc=0,countCalc=0,Dcont;
    int k=13;
    char d[25]="D I N N E R";
    int j;

        gotoxy(48,6);
        for(j=0;j<15;j++)
        {
            Sleep(50);
            cout<<bd2;
        }
        cout<<" ";
        for(j=0;j<13;j++)
        {
           Sleep(50);
           cout<<d[j];
        }
       for(j=0;j<15;j++)
        {
           Sleep(50);
           cout<<bd2;
        }

    ifstream indinner;
	indinner.open("dinner.dat",ios::binary | ios::in);

	if(!indinner)
    {
        system("cls");
        gotoxy(75,27);
        cout<<"Record Not Found....!!!";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        if(getch()==13)
        {
            MainMenuH();
        }
        else
        {
            MainMenuH();
        }
    }
    else
    {

        gotoxy(40,10);
        cout<<"========================================================================================\n";
        gotoxy(40,11);
        cout<<"Dinner No                        Dinner Name                             Dinner Cost"<<endl;
        gotoxy(40,12);
        cout<<"========================================================================================\n";


            while(indinner.read(reinterpret_cast<char *>(&Dobj),sizeof(Dinner)))
            {
                gotoxy(40,k);
                cout<<Dobj.dinnerCode<<setw(25)<<" "<<Dobj.dinnerName<<setw(33)<<Dobj.dinnerPrice<<endl<<endl;
                k+=2;
            }
            indinner.close();
        gotoxy(40,k);
        cout<<"========================================================================================\n";

        indinner.open("dinner.dat",ios::binary | ios::in);

        //cout<<"How Many Type You Want?: ";
        //cin>>HmT;
        //for(i=0; i<HmT; i++)
        //{
            cout<<"\n\n\t\t\t\t\t\tEnter the dinner code you want to buy: ";
            cin>>temDid;
            cout<<"\t\t\t\t\t\tHow many portions: ";
            cin>>Dcont;
            while(indinner.read(reinterpret_cast<char *>(&Dobj),sizeof(Dinner)))
            {
                if(temDid==Dobj.dinnerCode)
                {
                    calc=+Dcont*Dobj.dinnerPrice;
                }
            }
        //}
        indinner.close();
        cout<<"\n\t\t\t\t\t\tYOUR BILL AMOUNT IS: "<<calc;
        cout<<"\n\n\t\t\t\t\t\tIf You Want To add another Dinner the you press <y>..";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        switch(getch())
        {
        case 'Y':
        case 'y':
            Dobj.Buydinner();
            break;
        case 13:
            system("cls");
            MainMenuH();
            break;
        default:
            system("cls");
            MainMenuH();
            break;
        }
    }
}

void Dinner :: adddinner()
{
    cout<<"\t\t\t\t\t\t Enter The Dinner Name: ";
    cin>>dinnerName;
    cout<<"\t\t\t\t\t\t Enter Dinner Price: ";
    cin>>dinnerPrice;
}

void Dinner :: Writedinner()
{
    system("cls");
    gotoxy(2,1);
    timeANDdate();
    int DNo,k=13;
    Dinner Dobj;

        ofstream outFile;
        ifstream inFile;
        outFile.open("dinner.dat",ios::binary | ios::out | ios::app);
        inFile.open("dinner.dat",ios::binary | ios::in);

        gotoxy(40,10);
        cout<<"========================================================================================\n";
        gotoxy(40,11);
        cout<<"Dinner No                        Dinner Name                             Dinner Cost"<<endl;
        gotoxy(40,12);
        cout<<"========================================================================================\n";


            while(inFile.read(reinterpret_cast<char *>(&Dobj),sizeof(Dinner)))
            {
                gotoxy(40,k);
                cout<<Dobj.dinnerCode<<setw(25)<<" "<<Dobj.dinnerName<<setw(33)<<Dobj.dinnerPrice<<endl<<endl;
                k+=2;
            }
            inFile.close();
        gotoxy(40,k);
        cout<<"========================================================================================\n";

        inFile.open("dinner.dat",ios::binary | ios::in);

        cout<<"\t\t\t\t\t\t Enter Dinner Code: ";
        cin>>DNo;

        while(inFile.read(reinterpret_cast<char *>(&Dobj),sizeof(Dinner)))
        {
            if(DNo==Dobj.dinnerCode)
            {
                cout<<"Sorry! You can't Enter This Code";
                getch();
                Dobj.Writedinner();
            }
        }

        Dobj.dinnerCode=DNo;
        Dobj.adddinner();
        cout<<endl<<endl;
        outFile.write(reinterpret_cast<char *> (&Dobj), sizeof(Dinner));
        outFile.close();

    cout<<"\n\n\t\t\t\t\t\tIf you want to add another Dinner, Press <y>..";
    gotoxy(168,48);
    cout<<"Press ENTER to return main menu..";
    switch (getch())
    {
    case 'y':
    case 'Y':
        Dobj.Writedinner();
        break;
    case 13:
        system("cls");
        MainMenuH();
        break;
    default:
        system("cls");
        MainMenuH();
        break;
    }
}

void Dinner :: UpdateDetaildinner()
{
    system("cls");
    gotoxy(2,1);
    timeANDdate();
    Dinner Dobj;
    int k=13;

    ifstream indinner;
	indinner.open("dinner.dat",ios::binary | ios::in);

	if(!indinner)
    {
        system("cls");
        gotoxy(75,27);
        cout<<"Record Not Found....!!!";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        if(getch()==13)
        {
            MainMenuH();
        }
        else
        {
            MainMenuH();
        }
    }
    else
    {

        gotoxy(40,10);
        cout<<"========================================================================================\n";
        gotoxy(40,11);
        cout<<"Dinner No                        Dinner Name                             Dinner Cost"<<endl;
        gotoxy(40,12);
        cout<<"========================================================================================\n";


            while(indinner.read(reinterpret_cast<char *>(&Dobj),sizeof(Dinner)))
            {
                gotoxy(40,k);
                cout<<Dobj.dinnerCode<<setw(25)<<" "<<Dobj.dinnerName<<setw(33)<<Dobj.dinnerPrice<<endl<<endl;
                k+=2;
            }
            indinner.close();
        gotoxy(40,k);
        cout<<"========================================================================================\n";

        int d;

            cout<<"\n\n\t\t\t\t\t\t Enter the Dinner Number you want to update: ";
            cin>>d;

            fstream File;
            File.open("dinner.dat",ios::binary | ios::in | ios::out | ios::app);
            if(!File)
            {
                cout<<"File Doesn't Found!";
            }
            while(File.read(reinterpret_cast<char *>(&Dobj),sizeof(Dinner)))
            {
                if(d==Dobj.dinnerCode)
                {
                    system("cls");
                    gotoxy(20,7);
                    cout<<l<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<z;
                    gotoxy(20,8);
                    cout<<r<<endl;                                              gotoxy(60,8);cout<<r;
                    gotoxy(20,9);
                    cout<<r<<"The Dinner Code is: "<<Dobj.dinnerCode<<endl;            gotoxy(60,9);cout<<r;
                    gotoxy(20,10);
                    cout<<r<<"The Dinner Name is: "<<Dobj.dinnerName<<endl;            gotoxy(60,10);cout<<r;
                    gotoxy(20,11);
                    cout<<r<<"The Dinner Price is: "<<Dobj.dinnerPrice<<endl;            gotoxy(60,11);cout<<r;
                    gotoxy(20,12);
                    cout<<r<<endl;                                              gotoxy(60,12);cout<<r;
                    gotoxy(20,13);
                    cout<<s<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<t;

                    gotoxy(20,14);
                    cout<<"Enter The Dinner Code: ";
                    cin>>Dobj.dinnerCode;
                    Dobj.adddinner();

                    int pos=(-1)*static_cast<int>(sizeof(Dobj));
                    File.seekp(pos,ios::cur);
                    File.write(reinterpret_cast<char *> (&Dobj),sizeof(Dinner));
                    cout<<"RECORD UPDATED SUCCESSFULLY!"<<endl;
                }

            }
            File.close();

        cout<<"\n\n\t\t\t\t\t\t If you want to update again, press <y>..";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        switch(getch())
        {
        case 'Y':
        case 'y':
            Dobj.UpdateDetaildinner();
            break;
        case 13:
            system("cls");
            MainMenuH();
            break;
        default:
            system("cls");
            MainMenuH();
            break;
        }
    }
}

void Dinner :: DeleteDetaildinner()
{
    Dinner Dobj;
    system("cls");
    gotoxy(2,1);
    timeANDdate();
    int k=13;

    ifstream indinner;
	indinner.open("dinner.dat",ios::binary | ios::in);

	if(!indinner)
    {
        system("cls");
        gotoxy(75,27);
        cout<<"Record Not Found....!!!";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        if(getch()==13)
        {
            MainMenuH();
        }
        else
        {
            MainMenuH();
        }
    }
    else
    {

        gotoxy(40,10);
        cout<<"========================================================================================\n";
        gotoxy(40,11);
        cout<<"Dinner No             Dinner Name                 Dinner Cost"<<endl;
        gotoxy(40,12);
        cout<<"========================================================================================\n";


            while(indinner.read(reinterpret_cast<char *>(&Dobj),sizeof(Dinner)))
            {
                gotoxy(40,k);
                cout<<Dobj.dinnerCode<<setw(25)<<" "<<Dobj.dinnerName<<setw(33)<<Dobj.dinnerPrice<<endl<<endl;
                k+=2;
            }
            indinner.close();
        gotoxy(40,k);
        cout<<"========================================================================================\n";


        int DId;

            cout<<"\n\t\t\t\t\t\t Enter the Dinner Code you want to Delete: ";
            cin>>DId;
            ifstream inFile;
            inFile.open("dinner.dat",ios::binary | ios::in);

            if(!inFile)
            {
                cout<<"File Does Not Found";
                Dobj.DeleteDetaildinner();
            }

            ofstream outFile;
            outFile.open("tempdinner.dat",ios::binary | ios::out | ios::app);
            inFile.seekg(0,ios::beg);

            while(inFile.read(reinterpret_cast<char *>(&Dobj),sizeof(Dinner)))
            {
                if(DId!=Dobj.dinnerCode)
                {
                    outFile.write(reinterpret_cast<char *>(&Dobj),sizeof(Dinner));
                }
            }

            outFile.close();
            inFile.close();
            remove("dinner.dat");
            rename("tempdinner.dat","dinner.dat");
            cout<<"Record Deleted Successfully!!!!"<<endl<<endl;

        cout<<"\n\n\t\t\t\t\t\t If you want to delete again, Press <y>..";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        switch(getch())
        {
        case 'Y':
        case 'y':
            system("cls");
            Dobj.DeleteDetaildinner();
            break;
        case 13:
            system("cls");
            MainMenuH();
            break;
        default:
            system("cls");
            MainMenuH();
            break;
        }
    }
}

class PastryShop : public FoodConer
{
private:
    int PastryCode;
    char PastryName[20];
    float PastryPrice;
public:
    void getdata()
    {
        system("cls");
        BuyPastry();
    }
    void addPastry();
    void BuyPastry();
    void WritePastry();
    void DeleteDetailPastry();
    void UpdateDetailPastry();
};

void PastryShop :: BuyPastry()
{

    PastryShop Pobj;
    gotoxy(2,1);
    timeANDdate();
    int temPid,HmT,i;
    float calc=0,countCalc=0,Pcont;
    int k=13;
    char d[25]="P A S T R Y   S H O P";
    int j;

        gotoxy(48,6);
        for(j=0;j<15;j++)
        {
            Sleep(50);
            cout<<bd2;
        }
        cout<<" ";
        for(j=0;j<23;j++)
        {
           Sleep(50);
           cout<<d[j];
        }
       for(j=0;j<15;j++)
        {
           Sleep(50);
           cout<<bd2;
        }

    ifstream inPastry;
	inPastry.open("Pastry.dat",ios::binary | ios::in);

	if(!inPastry)
    {
        system("cls");
        gotoxy(75,27);
        cout<<"Record Not Found....!!!";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        if(getch()==13)
        {
            MainMenuH();
        }
        else
        {
            MainMenuH();
        }
    }
    else
    {

        gotoxy(40,10);
        cout<<"========================================================================================\n";
        gotoxy(40,11);
        cout<<"Pastry No                    Pastry Name                         Pastry Cost"<<endl;
        gotoxy(40,12);
        cout<<"========================================================================================\n";


            while(inPastry.read(reinterpret_cast<char *>(&Pobj),sizeof(PastryShop)))
            {
                gotoxy(40,k);
                cout<<Pobj.PastryCode<<setw(23)<<" "<<Pobj.PastryName<<setw(33)<<Pobj.PastryPrice<<endl<<endl;
                k+=2;
            }
            inPastry.close();
        gotoxy(40,k);
        cout<<"========================================================================================\n";

        inPastry.open("Pastry.dat",ios::binary | ios::in);

        //cout<<"How Many Type You Want?: ";
        //cin>>HmT;
        //for(i=0; i<HmT; i++)
        //{
            cout<<"\n\n\t\t\t\t\t\tEnter the pastry code you want to buy: ";
            cin>>temPid;
            cout<<"\t\t\t\t\t\tHow many Pastries: ";
            cin>>Pcont;
            while(inPastry.read(reinterpret_cast<char *>(&Pobj),sizeof(PastryShop)))
            {
                if(temPid==Pobj.PastryCode)
                {
                    calc=+Pcont*Pobj.PastryPrice;
                }
            }
        //}
        inPastry.close();
        cout<<"\n\t\t\t\t\t\tYOUR BILL AMOUNT IS: "<<calc;
        cout<<"\n\n\t\t\t\t\t\tIf you want to buy another pastry,Press <y>..";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        switch(getch())
        {
        case 'Y':
        case 'y':
            Pobj.BuyPastry();
            break;
        case 13:
            system("cls");
            MainMenuH();
            break;
        default:
            system("cls");
            MainMenuH();
            break;
        }
    }
}

void PastryShop :: addPastry()
{
    cout<<"\t\t\t\t\t\t Enter The Pastry Name: ";
    cin>>PastryName;
    cout<<"\t\t\t\t\t\t Enter Pastry Price: ";
    cin>>PastryPrice;
}

void PastryShop :: WritePastry()
{
    system("cls");
    gotoxy(2,1);
    timeANDdate();
    int j,PNo,k=13;
    PastryShop Pobj;

        ofstream outFile;
        ifstream inFile;
        outFile.open("Pastry.dat",ios::binary | ios::out | ios::app);
        inFile.open("Pastry.dat",ios::binary | ios::in);

        gotoxy(40,10);
        cout<<"========================================================================================\n";
        gotoxy(40,11);
        cout<<"Pastry No                    Pastry Name                         Pastry Cost"<<endl;
        gotoxy(40,12);
        cout<<"========================================================================================\n";


            while(inFile.read(reinterpret_cast<char *>(&Pobj),sizeof(PastryShop)))
            {
                gotoxy(40,k);
                cout<<Pobj.PastryCode<<setw(23)<<" "<<Pobj.PastryName<<setw(33)<<Pobj.PastryPrice<<endl<<endl;
                k+=2;
            }
            inFile.close();
        gotoxy(40,k);
        cout<<"========================================================================================\n";

        cout<<"\t\t\t\t\t\t Enter The Pastry Code: ";
        cin>>PNo;

        while(inFile.read(reinterpret_cast<char *>(&Pobj),sizeof(PastryShop)))
        {
            if(PNo==Pobj.PastryCode)
            {
                cout<<"Sory!!! You cant Enter This Code";
                getch();
                Pobj.WritePastry();
            }
        }

        Pobj.PastryCode=PNo;
        Pobj.addPastry();
        cout<<endl<<endl;
        outFile.write(reinterpret_cast<char *> (&Pobj), sizeof(PastryShop));
        outFile.close();

    cout<<"\n\n\t\t\t\t\t\t If You Want To add another Pastry the you press <y>..";
    gotoxy(168,48);
    cout<<"Press ENTER to return main menu..";
    switch (getch())
    {
    case 'y':
    case 'Y':
        Pobj.WritePastry();
        break;
    case 13:
        system("cls");
        MainMenuH();
        break;
    default:
        system("cls");
        MainMenuH();
        break;
    }
}

void PastryShop :: UpdateDetailPastry()
{
    system("cls");
    gotoxy(2,1);
    timeANDdate();
    PastryShop Pobj;
    int k=13;

    ifstream inPastry;
	inPastry.open("Pastry.dat",ios::binary | ios::in);

	if(!inPastry)
    {
        system("cls");
        gotoxy(75,27);
        cout<<"Record Not Found....!!!";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        if(getch()==13)
        {
            MainMenuH();
        }
        else
        {
            MainMenuH();
        }
    }
    else
    {

        gotoxy(40,10);
        cout<<"========================================================================================\n";
        gotoxy(40,11);
        cout<<"Pastry No                    Pastry Name                         Pastry Cost"<<endl;
        gotoxy(40,12);
        cout<<"========================================================================================\n";


            while(inPastry.read(reinterpret_cast<char *>(&Pobj),sizeof(PastryShop)))
            {
                gotoxy(40,k);
                cout<<Pobj.PastryCode<<setw(23)<<" "<<Pobj.PastryName<<setw(33)<<Pobj.PastryPrice<<endl<<endl;
                k+=2;
            }
            inPastry.close();
        gotoxy(40,k);
        cout<<"========================================================================================\n";

        int d;

            cout<<"\n\n\t\t\t\t\t\t Enter The Pastry Number You Want to update: ";
            cin>>d;

            fstream File;
            File.open("Pastry.dat",ios::binary | ios::in | ios::out | ios::app);
            if(!File)
            {
                cout<<"File Doesn't Found !";
            }
            while(File.read(reinterpret_cast<char *>(&Pobj),sizeof(PastryShop)))
            {
                if(d==Pobj.PastryCode)
                {
                    system("cls");
                    gotoxy(20,7);
                    cout<<l<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<z;
                    gotoxy(20,8);
                    cout<<r<<endl;                                              gotoxy(60,8);cout<<r;
                    gotoxy(20,9);
                    cout<<r<<"The Pastry Code is: "<<Pobj.PastryCode<<endl;            gotoxy(60,9);cout<<r;
                    gotoxy(20,10);
                    cout<<r<<"The Pastry Name is: "<<Pobj.PastryName<<endl;            gotoxy(60,10);cout<<r;
                    gotoxy(20,11);
                    cout<<r<<"The Pastry Price is: "<<Pobj.PastryPrice<<endl;            gotoxy(60,11);cout<<r;
                    gotoxy(20,12);
                    cout<<r<<endl;                                              gotoxy(60,12);cout<<r;
                    gotoxy(20,13);
                    cout<<s<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<t;

                    gotoxy(20,14);
                    cout<<"Enter The Pastry Code: ";
                    cin>>Pobj.PastryCode;
                    Pobj.addPastry();

                    int pos=(-1)*static_cast<int>(sizeof(Pobj));
                    File.seekp(pos,ios::cur);
                    File.write(reinterpret_cast<char *> (&Pobj),sizeof(PastryShop));
                    cout<<"RECORD UPDATED!!!!"<<endl;
                }

            }
            File.close();

        cout<<"\n\n\t\t\t\t\t\t You Want To Update Again, press <y>..";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        switch(getch())
        {
        case 'Y':
        case 'y':
            Pobj.UpdateDetailPastry();
            break;
        case 13:
            system("cls");
            MainMenuH();
            break;
        default:
            system("cls");
            MainMenuH();
            break;
        }
    }
}

void PastryShop :: DeleteDetailPastry()
{
    PastryShop Pobj;
    system("cls");
    gotoxy(2,1);
    timeANDdate();
    int k=13;

    ifstream inPastry;
	inPastry.open("Pastry.dat",ios::binary | ios::in);

	if(!inPastry)
    {
        system("cls");
        gotoxy(75,27);
        cout<<"Record Not Found....!!!";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        if(getch()==13)
        {
            MainMenuH();
        }
        else
        {
            MainMenuH();
        }
    }
    else
    {

        gotoxy(40,10);
        cout<<"========================================================================================\n";
        gotoxy(40,11);
        cout<<"Pastry No                    Pastry Name                         Pastry Cost"<<endl;
        gotoxy(40,12);
        cout<<"========================================================================================\n";


            while(inPastry.read(reinterpret_cast<char *>(&Pobj),sizeof(PastryShop)))
            {
                gotoxy(40,k);
                cout<<Pobj.PastryCode<<setw(23)<<" "<<Pobj.PastryName<<setw(33)<<Pobj.PastryPrice<<endl<<endl;
                k+=2;
            }
            inPastry.close();
        gotoxy(40,k);
        cout<<"========================================================================================\n";


        int PId;

            cout<<"\n\t\t\t\t\t\t Enter the Pastry Code You want to Delete: ";
            cin>>PId;
            ifstream inFile;
            inFile.open("Pastry.dat",ios::binary | ios::in);

            if(!inFile)
            {
                cout<<"File Does Not Found";
                Pobj.DeleteDetailPastry();
            }

            ofstream outFile;
            outFile.open("tempPastry.dat",ios::binary | ios::out | ios::app);
            inFile.seekg(0,ios::beg);

            while(inFile.read(reinterpret_cast<char *>(&Pobj),sizeof(PastryShop)))
            {
                if(PId!=Pobj.PastryCode)
                {
                    outFile.write(reinterpret_cast<char *>(&Pobj),sizeof(PastryShop));
                }
            }

            outFile.close();
            inFile.close();
            remove("Pastry.dat");
            rename("tempPastry.dat","Pastry.dat");
            cout<<"Record Deleted Successfully!!!!"<<endl<<endl;

        cout<<"\n\n\t\t\t\t\t\t If You Want To Delete Again,Press <y>..";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        switch(getch())
        {
        case 'Y':
        case 'y':
            system("cls");
            Pobj.DeleteDetailPastry();
            break;
        case 13:
            system("cls");
            MainMenuH();
            break;
        default:
            system("cls");
            MainMenuH();
            break;
        }
    }
}


void WhatIsTheFunction(FoodConer*p)
{
    p->getdata();
}

void FoodConerMain()
{
    system("cls");

    FoodConer *f;

    CofeeShop cofee;
    FruitJuice fruit;
    BrekFast bfast;
    Lunch lunch;
    Dinner dinner;
    PastryShop pastry;

    DecorateTopic();
    gotoxy(2,1);
    timeANDdate();

    gotoxy(75,27);
    cout<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<" FOOD SECTION "<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri;
    gotoxy(75,29);
    cout<<"...................................";

    gotoxy(75,31);
    cout<<g<<g<<q<<" 1.COFFEE SHOP "<<endl;
    gotoxy(75,33);
    cout<<g<<g<<q<<" 2.FRUIT JUICE "<<endl;
    gotoxy(75,35);
    cout<<g<<g<<q<<" 3.BREAKFAST "<<endl;
    gotoxy(75,37);
    cout<<g<<g<<q<<" 4.LUNCH "<<endl;
    gotoxy(75,39);
    cout<<g<<g<<q<<" 5.DINNER "<<endl;
    gotoxy(75,41);
    cout<<g<<g<<q<<" 6.PASTRY SHOP "<<endl;
    gotoxy(75,43);
    cout<<g<<g<<q<<" 7.BACK TO MAIN MENU"<<endl;

    gotoxy(75,45);
    cout<<"...................................";
    gotoxy(75,47);
    cout<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri;

    gotoxy(75,48);
    cout<<"What is you choice?: ";
    switch (getch())
    {
        case '1':
            WhatIsTheFunction(&cofee);
            break;
        case '2':
            WhatIsTheFunction(&fruit);
            break;
        case '3':
            WhatIsTheFunction(&bfast);
            break;
        case '4':
            WhatIsTheFunction(&lunch);
            break;
        case '5':
            WhatIsTheFunction(&dinner);
            break;
        case '6':
            WhatIsTheFunction(&pastry);
            break;
        case '7':
            system("cls");
            MainMenuH();
            break;
        default:
            system("cls");
            FoodConerMain();
            break;
    }
}
//**************************************************************************
//**************************************************************************

class Bar
{
private:
    int TypeCode;
    char TypeName[20];
    float TypeCost;
public:
    void BarBuyItem();
    void BarAddData();
    void BarWriteData();
    void BarUpdateData();
    void BarDeleteData();
};

void Bar :: BarAddData()
{
    //Bar barObj;
    cout<<"\t\t\t\t\t\tEnter The Type Name: ";
    cin>>TypeName;
    cout<<"\t\t\t\t\t\tEnter The Type Cost: ";
    cin>>TypeCost;

}

void Bar :: BarBuyItem()
{

    Bar barObj;
    int temIid,Icont,HmT,i;
    float calc=0,countCalc;
    int k=13;
    gotoxy(2,1);
    timeANDdate();
    char d[25]="B A R";
    int j;

        gotoxy(48,6);
        for(j=0;j<15;j++)
        {
            Sleep(50);
            cout<<bd2;
        }
        cout<<" ";
        for(j=0;j<7;j++)
        {
           Sleep(50);
           cout<<d[j];
        }
       for(j=0;j<15;j++)
        {
           Sleep(50);
           cout<<bd2;
        }

    ifstream inItem;
	inItem.open("BarRecord.dat",ios::binary);

	if(!inItem)
    {
        system("cls");
        gotoxy(75,27);
        cout<<"Record Not Found....!!!";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        if(getch()==13)
        {
            MainMenuH();
        }
        else
        {
            MainMenuH();
        }
    }
    else
    {

        gotoxy(40,10);
        cout<<"=============================================================================\n";
        gotoxy(40,11);
        cout<<"Item No                  Item Name                       Item Cost"<<endl;
        gotoxy(40,12);
        cout<<"=============================================================================\n";


            while(inItem.read(reinterpret_cast<char *>(&barObj),sizeof(Bar)))
            {
                gotoxy(40,k);
                cout<<barObj.TypeCode<<setw(21)<<" "<<barObj.TypeName<<setw(29)<<barObj.TypeCost<<endl<<endl;
                k+=2;
            }
            inItem.close();
        gotoxy(40,k);
        cout<<"=============================================================================\n";

        inItem.open("BarRecord.dat",ios::binary);

        cout<<"\t\t\t\t\t\tHow many item types you want to buy?: ";
        cin>>HmT;
        for(i=0; i<HmT; i++)
        {
            cout<<"\n\n\t\t\t\t\t\tEnter the item code you want to buy: ";
            cin>>temIid;
            cout<<"\t\t\t\t\t\tHow many Items: ";
            cin>>Icont;
            while(inItem.read(reinterpret_cast<char *>(&barObj),sizeof(Bar)))
            {
                if(temIid==barObj.TypeCode)
                {
                    calc=(float)Icont*barObj.TypeCost;
                }
            }
            countCalc+=calc;
        }
        inItem.close();
        cout<<"\n\t\t\t\t\t\tYOUR BILL AMOUNT IS: "<<countCalc;
        cout<<"\n\n\t\t\t\t\t\tIf you want to add another item, Press <y>...";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        switch(getch())
        {
        case 'Y':
        case 'y':
            barObj.BarBuyItem();
            break;
        case 13:
            system("cls");
            MainMenuH();
            break;
        default:
            system("cls");
            MainMenuH();
            break;
        }
    }
}

void Bar :: BarWriteData()
{
    int i,j,INo;
    system("cls");
    Bar barObj;
    gotoxy(2,1);
    timeANDdate();

    char ch[10];
    int k=13;

    ifstream inFile;
	inFile.open("BarRecord.dat",ios::binary);

	gotoxy(40,10);
	cout<<"==========================================================\n";
	gotoxy(40,11);
    cout<<"Item No              Item Name                   Item Cost"<<endl;
    gotoxy(40,12);
    cout<<"==========================================================\n";


        while(inFile.read(reinterpret_cast<char *>(&barObj),sizeof(Bar)))
        {
            //cout<<endl;
            gotoxy(40,k);
            cout<<barObj.TypeCode<<setw(15)<<" "<<barObj.TypeName<<setw(28)<<barObj.TypeCost<<endl;
            k+=2;
        }
        inFile.close();
    gotoxy(40,k++);
    cout<<"==========================================================\n";

        ofstream outFile;

        outFile.open("BarRecord.dat",ios::binary | ios::app);
        inFile.open("BarRecord.dat",ios::in);

        cout<<"\t\t\t\t\t\t Enter The Item Number: ";
        cin>>INo;

        while(inFile.read(reinterpret_cast<char *>(&barObj),sizeof(Bar)))
        {
            if(INo==barObj.TypeCode)
            {
                cout<<"\t\t\t\t\t\t Sorry!!! You cant Enter This No";
                getch();
                barObj.BarWriteData();
            }
        }

        barObj.TypeCode=INo;
        barObj.BarAddData();
        cout<<endl<<endl;
        outFile.write(reinterpret_cast<char *> (&barObj), sizeof(Bar));
        outFile.close();

    cout<<"\n\n\t\t\t\t\t\t If You Want To add another Item , press <y>..";
    gotoxy(168,48);
    cout<<"Press ENTER to return main menu..";
    switch(getch())
    {
    case 'Y':
    case 'y':
        barObj.BarWriteData();
        break;
    case 13:
        system("cls");
        MainMenuH();
        break;
    default:
        system("cls");
        MainMenuH();
        break;
    }
}


void Bar :: BarUpdateData()
{
    Bar barObj;
    system("cls");
    gotoxy(2,1);
    timeANDdate();

    char ch[10];
    int k=13,INo;

    ifstream inFile;
	inFile.open("BarRecord.dat",ios::binary);

	if(!inFile)
    {
        system("cls");
        gotoxy(75,27);
        cout<<"Record Not Found....!!!";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        if(getch()==13)
        {
            MainMenuH();
        }
        else
        {
            MainMenuH();
        }
    }
    else
    {

        gotoxy(40,10);
        cout<<"==========================================================\n";
        gotoxy(40,11);
        cout<<"Item No              Item Name                   Item Cost"<<endl;
        gotoxy(40,12);
        cout<<"==========================================================\n";


            while(inFile.read(reinterpret_cast<char *>(&barObj),sizeof(Bar)))
            {
                //cout<<endl;
                gotoxy(40,k);
                cout<<barObj.TypeCode<<setw(17)<<" "<<barObj.TypeName<<setw(23)<<barObj.TypeCost<<endl;
                k+=2;
            }
            inFile.close();
        gotoxy(40,k);
        cout<<"==========================================================\n";

        int d,i;

            cout<<"\n\n\t\t\t\t\t Enter The Item Number You Want to update: ";
            cin>>d;

            fstream File;
            File.open("BarRecord.dat",ios::binary | ios::in | ios::out);
            if(!File)
            {
                cout<<"File Doesn't Found !";
            }
            while(File.read(reinterpret_cast<char *>(&barObj),sizeof(Bar)))
            {
                if(d==barObj.TypeCode)
                {
                    system("cls");
                    gotoxy(20,7);
                    cout<<l<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<z;
                    gotoxy(20,8);
                    cout<<r<<endl;                                              gotoxy(60,8);cout<<r;
                    gotoxy(20,9);
                    cout<<r<<"The Item Number is: "<<barObj.TypeCode<<endl;            gotoxy(60,9);cout<<r;
                    gotoxy(20,10);
                    cout<<r<<"The Item Name is: "<<barObj.TypeName<<endl;            gotoxy(60,10);cout<<r;
                    gotoxy(20,11);
                    cout<<r<<"The Item Cost is: "<<barObj.TypeCost<<endl;            gotoxy(60,11);cout<<r;
                    gotoxy(20,12);
                    cout<<r<<endl;                                              gotoxy(60,12);cout<<r;
                    gotoxy(20,13);
                    cout<<s<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<t;

                    gotoxy(20,14);
                    cout<<"Enter The Item Number: ";
                    cin>>barObj.TypeCode;
                    barObj.BarAddData();

                    int pos=(-1)*static_cast<int>(sizeof(barObj));
                    File.seekp(pos,ios::cur);
                    File.write(reinterpret_cast<char *> (&barObj),sizeof(Bar));
                    gotoxy(20,20);
                    cout<<"RECORD UPDATED!!!!"<<endl;
                }

            }
            File.close();


        cout<<"\n\n\t\t\t\t\t\t You Want To Update Again, Press <y>..";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        switch(getch())
        {
        case 'Y':
        case 'y':
            barObj.BarUpdateData();
            break;
        case 13:
            system("cls");
            MainMenuH();
            break;
        default:
            system("cls");
            MainMenuH();
            break;
        }
    }
}

void Bar :: BarDeleteData()
{
    Bar barObj;
    system("cls");
    gotoxy(2,1);
    timeANDdate();

    char ch[10];
    int k=13,INo;

    ifstream inFile;
	inFile.open("BarRecord.dat",ios::binary);

	if(!inFile)
    {
        system("cls");
        gotoxy(75,27);
        cout<<"Record Not Found....!!!";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        if(getch()==13)
        {
            MainMenuH();
        }
        else
        {
            MainMenuH();
        }
    }
    else
    {

        gotoxy(40,10);
        cout<<"==========================================================\n";
        gotoxy(40,11);
        cout<<"Item No              Item Name                   Item Cost"<<endl;
        gotoxy(40,12);
        cout<<"==========================================================\n";


            while(inFile.read(reinterpret_cast<char *>(&barObj),sizeof(Bar)))
            {
                //cout<<endl;
                gotoxy(40,k);
                cout<<barObj.TypeCode<<setw(15)<<" "<<barObj.TypeName<<setw(28)<<barObj.TypeCost<<endl;
                k+=2;
            }
            inFile.close();
        gotoxy(40,k++);
        cout<<"==========================================================\n";
        int barId;

            cout<<"\n\t\t\t\t\t\t Enter the Id You want to Delete: ";
            cin>>barId;
            //ifstream inFile;
            inFile.open("BarRecord.dat",ios::binary);

            if(!inFile)
            {
                cout<<"File Does Not Found";
                barObj.BarDeleteData();
            }

            ofstream outFile;
            outFile.open("tempBarRecord.dat",ios::binary | ios::app);
            inFile.seekg(0,ios::beg);

            while(inFile.read(reinterpret_cast<char *>(&barObj),sizeof(Bar)))
            {
                if(barId!=barObj.TypeCode)
                {
                    outFile.write(reinterpret_cast<char *>(&barObj),sizeof(Bar));
                }
            }

            outFile.close();
            inFile.close();
                remove("BarRecord.dat");
                rename("tempBarRecord.dat","BarRecord.dat");
                cout<<"Record Delete Success!!!!"<<endl<<endl;


        cout<<"\n\n\t\t\t\t\t\t You Want To Delete Again then press <y>..";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        switch(getch())
        {
        case 'Y':
        case 'y':
            barObj.BarDeleteData();
            break;
        case 13:
            system("cls");
            MainMenuH();
            break;
        default:
            system("cls");
            MainMenuH();
            break;
        }
    }
}

//**************************************************************************
//**************************************************************************

class Meeting
{
private:
    int MhallCode,McustomerPhone,MhallId;
    char MhallName[50],MCustomerName[50],MCustomerAddress[50];
    double MhallCost,MCustomerAdvanseP,MRoomCost,MCPayment;
public:
    int MhallBuy();
    void MhallAddData();
    void MhallWriteData();
    void MhallUpdateData();
    void MhallDeleteData();
    int Mhallcheck(int rNo);
    void releseMhall();
};


int Meeting :: MhallBuy()
{
    Meeting MHObj;
    system("cls");
    gotoxy(2,1);
    timeANDdate();

    char ch[10];
    int k=13,Flag,rNo;
    char d[25]="M E E T I N G   H A L L";
    int j;

        gotoxy(48,6);
        for(j=0;j<15;j++)
        {
            Sleep(50);
            cout<<bd2;
        }
        cout<<" ";
        for(j=0;j<25;j++)
        {
           Sleep(50);
           cout<<d[j];
        }
       for(j=0;j<15;j++)
        {
           Sleep(50);
           cout<<bd2;
        }

    ifstream inFile;
	inFile.open("Mrecord.dat",ios::binary | ios::in);

	if(!inFile)
    {
        system("cls");
        gotoxy(75,27);
        cout<<"Record Not Found....!!!";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        if(getch()==13)
        {
            MainMenuH();
        }
        else
        {
            MainMenuH();
        }
    }
    else
    {

        gotoxy(40,10);
        cout<<"===================================================================================\n";
        gotoxy(40,11);
        cout<<"Meeting Hall No              Meeting Hall Name                   Meeting Hall Cost"<<endl;
        gotoxy(40,12);
        cout<<"===================================================================================\n";

            if(!inFile)
            {
                cout<<"File Does Not Found!!!";
            }

            while(inFile.read(reinterpret_cast<char *>(&MHObj),sizeof(Meeting)))
            {
                    gotoxy(40,k);
                    cout<<MHObj.MhallCode<<setw(27)<<" "<<MHObj.MhallName<<setw(30)<<MHObj.MhallCost<<endl;
                    k+=2;
            }
            inFile.close();
        gotoxy(40,k);
        cout<<"===================================================================================\n";

        ofstream fout;
        fout.open("Mbooking.dat",ios::binary | ios::out | ios::app);

                cout<<"\n\t\t\t\t\t\t Enter the meeting hall number you want to book : ";
                cin>>rNo;

                Flag = Mhallcheck(rNo);

                if(Flag==1)
                {
                    cout<<"\n\t\t\t\t\t\t\t Sorry! This hall is already booked";
                }
                else
                {
                    cout<<"\n\n\t\t\t\t\t\t    "<<bd1<<bd1<<bd1<<bd1<<bd1<<bd1<<bd1<<bd1<<bd1<<bd1<<bd1<<" FILL UP THE FORM "<<bd1<<bd1<<bd1<<bd1<<bd1<<bd1<<bd1<<bd1<<bd1<<bd1<<bd1<<endl;
                    cout<<"\n\t\t\t\t\t\t\tName: ";
                    cin>>MHObj.MCustomerName;
                    cout<<"\t\t\t\t\t\t\tAddress: ";
                    cin>>MHObj.MCustomerAddress;
                    cout<<"\t\t\t\t\t\t\tPhone No: ";
                    cin>>MHObj.McustomerPhone;
                    MHObj.MhallId=rNo;

                    fout.write(reinterpret_cast<char *>(&MHObj),sizeof(Meeting));
                    cout<<"\n\t\t\t\t\t\t\t\t HALL IS BOOKED!";
                }

                cout<<"\n\n\t\t\t\t\t\t\t Press any key to continue.....!!";
                getch();
                fout.close();

        cout<<"\n\n\t\t\t\t\t\t If you want to book another meeting hall, Press <y>...";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        switch (getch())
        {
        case 'y':
        case 'Y':
            system("cls");
            MHObj.MhallBuy();
            break;
        case 13:
            system("cls");
            MainMenuH();
            break;
        default:
            system("cls");
            MainMenuH();
            break;
        }
    }
}

int Meeting :: Mhallcheck(int rNo)
{
    Meeting MHObj;

    int flag=0;

    ifstream fin("Mbooking.dat",ios::in);

    while(fin.read(reinterpret_cast<char *>(&MHObj),sizeof(Meeting)))
    {
        if(MHObj.MhallId==rNo)
        {

        flag=1;
        break;

        }

    }

    fin.close();
    return(flag);

}

void Meeting :: releseMhall()
{
    Meeting MHObj;
    system("cls");
    DecorateTopic();
    gotoxy(2,1);
    timeANDdate();
    int rNo,Flag;
    float tot=0;

    //cout<<"\n";
    ifstream fin;
    fin.open("Mbooking.dat",ios::binary | ios::in);
    gotoxy(67,31);
    cout<<"   Enter the meeting hall number you want to release: ";
    cin>>rNo;


    ofstream fout;
    fout.open("tempMbooking.dat",ios::binary | ios::out | ios::app);
    fin.seekg(0,ios::beg);

       while(fin.read(reinterpret_cast<char *>(&MHObj),sizeof(Meeting)))
       {
           if(rNo!=MHObj.MhallId)
           {
               fout.write(reinterpret_cast<char *>(&MHObj),sizeof(Meeting));
           }
       }
    fin.close();
    fout.close();

    remove("Mbooking.dat");
    rename("tempMbooking.dat","Mbooking.dat");
    gotoxy(70,32);
    cout<<"RELEASED HALL..!!!";

    gotoxy(70,38);
    cout<<"If you want to release another meeting hall, Press <y>...";
    gotoxy(168,48);
    cout<<"Press ENTER to return main menu..";
    switch (getch())
    {
    case 'y':
    case 'Y':
        system("cls");
        MHObj.releseMhall();
        break;
    case 13:
        system("cls");
        MainMenuH();
        break;
    default:
        system("cls");
        MainMenuH();
        break;
    }

}

void Meeting::MhallAddData()
{
    cout<<"\n\t\t\t\t><. Enter The Meeting Hall Name: ";
    cin>>MhallName;
    cout<<"\n\t\t\t\t><. Enter The Meeting Hall Cost: ";
    cin>>MhallCost;

}

void Meeting :: MhallWriteData()
{
    int i,j,RNo;
    system("cls");
    gotoxy(2,1);
    timeANDdate();
    Meeting MHObj;

    char ch[10];
    int k=13;

    ifstream inFile;
	inFile.open("Mrecord.dat",ios::binary | ios::in);

	gotoxy(40,10);
	cout<<"===================================================================================\n";
	gotoxy(40,11);
    cout<<"Meeting Hall No              Meeting Hall Name                   Meeting Hall Cost"<<endl;
    gotoxy(40,12);
    cout<<"===================================================================================\n";


        while(inFile.read(reinterpret_cast<char *>(&MHObj),sizeof(Meeting)))
        {
            //cout<<endl;
            gotoxy(40,k);
            cout<<MHObj.MhallCode<<setw(27)<<MHObj.MhallName<<setw(30)<<MHObj.MhallCost<<endl;
            k+=2;
        }
        inFile.close();
    gotoxy(40,k);
    cout<<"===================================================================================\n";

        ofstream outFile;

        outFile.open("Mrecord.dat",ios::binary | ios::out | ios::app);
        inFile.open("Mrecord.dat",ios::binary | ios::in);

        cout<<"\n\t\t\t\t><. Enter The Meeting Hall Number: ";
        cin>>RNo;

        while(inFile.read(reinterpret_cast<char *>(&MHObj),sizeof(Meeting)))
        {
            if(RNo==MHObj.MhallCode)
            {
                cout<<"\n\t\t\t\t\t\tSorry! You can't enter this no";
                getch();
                MHObj.MhallWriteData();
            }
        }

        MHObj.MhallCode=RNo;
        MHObj.MhallAddData();
        cout<<endl<<endl;
        outFile.write(reinterpret_cast<char *> (&MHObj), sizeof(Meeting));
        outFile.close();

    cout<<"\n\n\n\t\t\t\t\t\t If you want to add another meeting hall, press <y>..";
    gotoxy(168,48);
    cout<<"Press ENTER to return main menu..";
    switch (getch())
    {
    case 'y':
    case 'Y':
        MHObj.MhallWriteData();
        break;
    case 13:
        system("cls");
        MainMenuH();
        break;
    default:
        system("cls");
        MainMenuH();
        break;
    }
}


void Meeting :: MhallUpdateData()
{
    Meeting MHObj;
    system("cls");
    gotoxy(2,1);
    timeANDdate();

    char ch[10];
    int k=13,Flag,rNo;

    ifstream inFile;
	inFile.open("Mrecord.dat",ios::binary | ios::in);

	if(!inFile)
    {
        system("cls");
        gotoxy(75,27);
        cout<<"Record Not Found....!!!";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        if(getch()==13)
        {
            MainMenuH();
        }
        else
        {
            MainMenuH();
        }
    }
    else
    {

        gotoxy(40,10);
        cout<<"====================================================================================\n";
        gotoxy(40,11);
        cout<<"meeting Hall No              Meeting Hall Name                   Meeting Hall Cost"<<endl;
        gotoxy(40,12);
        cout<<"====================================================================================\n";


            while(inFile.read(reinterpret_cast<char *>(&MHObj),sizeof(Meeting)))
            {
                //cout<<endl;
                gotoxy(40,k);
                cout<<MHObj.MhallCode<<setw(27)<<" "<<MHObj.MhallName<<setw(30)<<MHObj.MhallCost<<endl;
                k+=2;
            }
            inFile.close();
        gotoxy(40,k);
        cout<<"====================================================================================\n";

        int d,i;

            cout<<"\n\t\t\t\t><.Enter The Meeting Hall Number You Want to update: ";
            cin>>d;

            fstream File;
            File.open("Mrecord.dat",ios::binary | ios::in | ios::out);
            if(!File)
            {
                cout<<"Doesn't Found File!!!";
            }
            while(File.read(reinterpret_cast<char *>(&MHObj),sizeof(Meeting)))
            {
                if(d==MHObj.MhallCode)
                {
                    system("cls");
                    gotoxy(20,7);
                    cout<<l<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<z;
                    gotoxy(20,8);
                    cout<<r<<endl;                                              gotoxy(60,8);cout<<r;
                    gotoxy(20,9);
                    cout<<r<<">. The Meeting Hall Number is  : "<<MHObj.MhallCode<<endl;            gotoxy(60,9);cout<<r;
                    gotoxy(20,10);
                    cout<<r<<">. The Meeting Hall Name is    : "<<MHObj.MhallName<<endl;            gotoxy(60,10);cout<<r;
                    gotoxy(20,11);
                    cout<<r<<">. The Meeting Hall Cost is    : "<<MHObj.MhallCost<<endl;            gotoxy(60,11);cout<<r;
                    gotoxy(20,12);
                    cout<<r<<endl;                                              gotoxy(60,12);cout<<r;
                    gotoxy(20,13);
                    cout<<s<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<t;

                    gotoxy(20,14);
                    cout<<"\n\t\t\t\t><. Enter The Meeting Hall Number: ";
                    cin>>MHObj.MhallCode;
                    MHObj.MhallAddData();

                    int pos=(-1)*static_cast<int>(sizeof(MHObj));
                    File.seekp(pos,ios::cur);
                    File.write(reinterpret_cast<char *> (&MHObj),sizeof(Meeting));
                    cout<<"\n\n\t\t\t\t\t\tRECORD UPDATE!!!!"<<endl;
                }

            }
            File.close();


        cout<<"\n\n\n\t\t\t\t\t\t You Want To Update Again then press <y>..";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        switch(getch())
        {
        case 'Y':
        case 'y':
            MHObj.MhallUpdateData();
            break;
        case 13:
            system("cls");
            MainMenuH();
            break;
        default:
            system("cls");
            MainMenuH();
            break;
        }
    }
}

void Meeting :: MhallDeleteData()
{
    Meeting MHObj;
    system("cls");
    gotoxy(2,1);
    timeANDdate();

    char ch[10];
    int k=13,Flag,rNo;

    ifstream inFile;
	inFile.open("Mrecord.dat",ios::binary | ios::in);

	if(!inFile)
    {
        system("cls");
        gotoxy(75,27);
        cout<<"Record Not Found....!!!";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        if(getch()==13)
        {
            MainMenuH();
        }
        else
        {
            MainMenuH();
        }
    }
    else
    {

        gotoxy(40,10);
        cout<<"===================================================================================\n";
        gotoxy(40,11);
        cout<<"Meeting Hall No              Meeting Hall Name                   Meeting Hall Cost"<<endl;
        gotoxy(40,12);
        cout<<"===================================================================================\n";


            while(inFile.read(reinterpret_cast<char *>(&MHObj),sizeof(Meeting)))
            {
                //cout<<endl;
                gotoxy(40,k);
                cout<<MHObj.MhallCode<<setw(27)<<" "<<MHObj.MhallName<<setw(30)<<MHObj.MhallCost<<endl;
                k+=2;
            }
            inFile.close();
        gotoxy(40,k);
        cout<<"===================================================================================\n";
        int rmId;

            cout<<"\n\t\t\t\t><. Enter the Meeting Hall Number You want to Delete: ";
            cin>>rmId;
            //ifstream inFile;
            inFile.open("Mrecord.dat",ios::binary | ios::in);

            if(!inFile)
            {
                cout<<"File Does Not Found";
                MHObj.MhallDeleteData();
            }

            ofstream outFile;
            outFile.open("tempMrecord.dat",ios::binary | ios::out | ios::app);
            inFile.seekg(0,ios::beg);

            while(inFile.read(reinterpret_cast<char *>(&MHObj),sizeof(Meeting)))
            {
                if(rmId!=MHObj.MhallCode)
                {
                    outFile.write(reinterpret_cast<char *>(&MHObj),sizeof(Meeting));
                }
            }

            outFile.close();
            inFile.close();
                remove("Mrecord.dat");
                rename("tempMrecord.dat","Mrecord.dat");
                cout<<"\n\n\t\t\t\t\t\t\tRecord Delete Success!!!!"<<endl<<endl;


        cout<<"\n\n\n\t\t\t\t\t\t You Want To Delete Again then press <y>..";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        switch(getch())
        {
        case 'Y':
        case 'y':
            MHObj.MhallDeleteData();
            break;
        case 13:
            system("cls");
            MainMenuH();
            break;
        default:
            system("cls");
            MainMenuH();
            break;
        }
    }
}

//**************************************************************************
//**************************************************************************

class Wedding
{
private:
    int WhallCode,WcustomerPhone,WhallId;
    char WhallName[20],WCustomerName[20],WCustomerAddress[20];
    float WhallCost,WCustomerAdvanseP,WRoomCost,WCPayment;
public:
    int WhallBuy();
    void WhallAddData();
    void WhallWriteData();
    void WhallUpdateData();
    void WhallDeleteData();
    int Whallcheck(int rNo);
    void releseWhall();
};


int Wedding :: WhallBuy()
{
    Wedding WHObj;
    system("cls");
    gotoxy(2,1);
    timeANDdate();

    char ch[10];
    int k=13,Flag,rNo;
    char d[25]="W E D D I N G   H A L L";
    int j;

        gotoxy(48,6);
        for(j=0;j<15;j++)
        {
            Sleep(50);
            cout<<bd2;
        }
        cout<<" ";
        for(j=0;j<25;j++)
        {
           Sleep(50);
           cout<<d[j];
        }
       for(j=0;j<15;j++)
        {
           Sleep(50);
           cout<<bd2;
        }

    ifstream inFile;
	inFile.open("Wrecord.dat",ios::binary | ios::in);

	if(!inFile)
    {
        system("cls");
        gotoxy(75,27);
        cout<<"Record Not Found....!!!";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        if(getch()==13)
        {
            MainMenuH();
        }
        else
        {
            MainMenuH();
        }
    }
    else
    {

        gotoxy(40,10);
        cout<<"===================================================================================\n";
        gotoxy(40,11);
        cout<<"Wedding Hall No              Wedding Hall Name                   Wedding Hall Cost"<<endl;
        gotoxy(40,12);
        cout<<"===================================================================================\n";

            if(!inFile)
            {
                cout<<"\t\t\t\t\t\t File Does Not Found!!!";
            }

            while(inFile.read(reinterpret_cast<char *>(&WHObj),sizeof(Wedding)))
            {
                    gotoxy(40,k);
                    cout<<WHObj.WhallCode<<setw(27)<<" "<<WHObj.WhallName<<setw(30)<<WHObj.WhallCost<<endl;
                    k+=2;
            }
            inFile.close();
        gotoxy(40,k);
        cout<<"===================================================================================\n";

        ofstream fout;
        fout.open("Wbooking.dat",ios::binary | ios::out | ios::app);

                cout<<"\n\t\t\t\t\t\t Enter the wedding hall number you want to book : ";
                cin>>rNo;

                Flag = Whallcheck(rNo);

                if(Flag==1)
                {
                    cout<<"\n\t\t\t\t\t\t\tSorry! This Hall is already booked";
                }
                else
                {
                    cout<<"\n\n\t\t\t\t\t\t    "<<bd1<<bd1<<bd1<<bd1<<bd1<<bd1<<bd1<<bd1<<bd1<<bd1<<bd1<<" FILL UP THE FORM "<<bd1<<bd1<<bd1<<bd1<<bd1<<bd1<<bd1<<bd1<<bd1<<bd1<<bd1<<endl;
                    cout<<"\n\t\t\t\t\t\t\tName: ";
                    cin>>WHObj.WCustomerName;
                    cout<<"\t\t\t\t\t\t\tAddress: ";
                    cin>>WHObj.WCustomerAddress;
                    cout<<"\t\t\t\t\t\t\tPhone No: ";
                    cin>>WHObj.WcustomerPhone;
                    WHObj.WhallId=rNo;

                    fout.write(reinterpret_cast<char *>(&WHObj),sizeof(Wedding));
                    cout<<"\n\t\t\t\t\t\t\t\t HALL IS BOOKED!";
                }

                cout<<"\n\n\t\t\t\t\t\t Press any key to continue !";
                getch();
                fout.close();

        cout<<"\n\n\t\t\t\t\t\t If you want to book another Wedding Hall, Press <y>...";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        switch (getch())
        {
        case 'y':
        case 'Y':
            system("cls");
            WHObj.WhallBuy();
            break;
        case 13:
            system("cls");
            MainMenuH();
            break;
        default:
            system("cls");
            MainMenuH();
            break;
        }
    }
}

int Wedding :: Whallcheck(int rNo)
{
    Wedding WHObj;

    int flag=0;

    ifstream fin("Wbooking.dat",ios::in);

    while(fin.read(reinterpret_cast<char *>(&WHObj),sizeof(Wedding)))
    {
        if(WHObj.WhallId==rNo)
        {

        flag=1;
        break;

        }

    }

    fin.close();
    return(flag);

}

void Wedding :: releseWhall()
{
    Wedding WHObj;
    system("cls");
    DecorateTopic();
    gotoxy(2,1);
    timeANDdate();
    int rNo,Flag;
    float tot=0;

    //cout<<"\n";
    ifstream fin;
    fin.open("Wbooking.dat",ios::binary | ios::in);
    gotoxy(67,31);
    cout<<"   Enter the wedding hall number you want to release: ";
    cin>>rNo;


    ofstream fout;
    fout.open("tempWbooking.dat",ios::binary | ios::out | ios::app);
    fin.seekg(0,ios::beg);

       while(fin.read(reinterpret_cast<char *>(&WHObj),sizeof(Wedding)))
       {
           if(rNo!=WHObj.WhallId)
           {
               fout.write(reinterpret_cast<char *>(&WHObj),sizeof(Wedding));
           }
       }
    fin.close();
    fout.close();

    remove("Wbooking.dat");
    rename("tempWbooking.dat","Wbooking.dat");
    gotoxy(70,32);
    cout<<"RELEASED HALL..!!!";

    gotoxy(70,38);
    cout<<"If you want to release another wedding hall, Press  <y>...";
    gotoxy(168,48);
    cout<<"Press ENTER to return main menu..";
    switch (getch())
    {
    case 'y':
    case 'Y':
        system("cls");
        WHObj.releseWhall();
        break;
    case 13:
        system("cls");
        MainMenuH();
        break;
    default:
        system("cls");
        MainMenuH();
        break;
    }

}

void Wedding::WhallAddData()
{
    cout<<"\n\t\t\t\t><. Enter The Wedding Hall Name: ";
    cin>>WhallName;
    cout<<"\n\t\t\t\t><. Enter The Wedding Hall Cost: ";
    cin>>WhallCost;

}

void Wedding :: WhallWriteData()
{
    int i,j,RNo;
    system("cls");
    gotoxy(2,1);
    timeANDdate();
    Wedding WHObj;

    char ch[10];
    int k=13;

    ifstream inFile;
	inFile.open("Wrecord.dat",ios::binary | ios::in);

	gotoxy(40,10);
	cout<<"===================================================================================\n";
	gotoxy(40,11);
    cout<<"Wedding Hall No              Wedding Hall Name                   Wedding Hall Cost"<<endl;
    gotoxy(40,12);
    cout<<"===================================================================================\n";


        while(inFile.read(reinterpret_cast<char *>(&WHObj),sizeof(Wedding)))
        {
            //cout<<endl;
            gotoxy(40,k);
            cout<<WHObj.WhallCode<<setw(27)<<" "<<WHObj.WhallName<<setw(30)<<WHObj.WhallCost<<endl;
            k+=2;
        }
        inFile.close();
    gotoxy(40,k);
    cout<<"===================================================================================\n";

        ofstream outFile;

        outFile.open("Wrecord.dat",ios::binary | ios::app);
        inFile.open("Wrecord.dat",ios::binary | ios::in);

        cout<<"\n\t\t\t\t><. Enter The Wedding Hall Number: ";
        cin>>RNo;

        while(inFile.read(reinterpret_cast<char *>(&WHObj),sizeof(Wedding)))
        {
            if(RNo==WHObj.WhallCode)
            {
                cout<<"\n\t\t\t\t\t\tSorry!!! You cant Enter This No";
                getch();
                WHObj.WhallWriteData();
            }
        }

        WHObj.WhallCode=RNo;
        WHObj.WhallAddData();
        cout<<endl<<endl;
        outFile.write(reinterpret_cast<char *> (&WHObj), sizeof(Wedding));
        outFile.close();

    cout<<"\n\n\t\t\t\t\t\t If You Want To add another Wedding Hall the you press <y>..";
    gotoxy(168,48);
    cout<<"Press ENTER to return main menu..";
    switch (getch())
    {
    case 'y':
    case 'Y':
        WHObj.WhallWriteData();
        break;
    case 13:
        system("cls");
        MainMenuH();
        break;
    default:
        system("cls");
        MainMenuH();
        break;
    }
}


void Wedding :: WhallUpdateData()
{
    Wedding WHObj;
    system("cls");
    gotoxy(2,1);
    timeANDdate();

    char ch[10];
    int k=13,Flag,rNo;

    ifstream inFile;
	inFile.open("Wrecord.dat",ios::binary | ios::in);

	if(!inFile)
    {
        system("cls");
        gotoxy(75,27);
        cout<<"Record Not Found....!!!";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        if(getch()==13)
        {
            MainMenuH();
        }
        else
        {
            MainMenuH();
        }
    }
    else
    {

        gotoxy(40,10);
        cout<<"====================================================================================\n";
        gotoxy(40,11);
        cout<<"Wedding Hall No              Wedding Hall Name                   Wedding Hall Cost"<<endl;
        gotoxy(40,12);
        cout<<"====================================================================================\n";


            while(inFile.read(reinterpret_cast<char *>(&WHObj),sizeof(Wedding)))
            {
                //cout<<endl;
                gotoxy(40,k);
                cout<<WHObj.WhallCode<<setw(27)<<" "<<WHObj.WhallName<<setw(30)<<WHObj.WhallCost<<endl;
                k+=2;
            }
            inFile.close();
        gotoxy(40,k);
        cout<<"====================================================================================\n";

        int d,i;

            cout<<"\n\t\t\t\t><.Enter The Wedding Hall Number You Want to update: ";
            cin>>d;

            fstream File;
            File.open("Wrecord.dat",ios::binary | ios::in | ios::out);
            if(!File)
            {
                cout<<"Doesn't Found File!!!";
            }
            while(File.read(reinterpret_cast<char *>(&WHObj),sizeof(Wedding)))
            {
                if(d==WHObj.WhallCode)
                {
                    system("cls");
                    gotoxy(20,7);
                    cout<<l<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<z;
                    gotoxy(20,8);
                    cout<<r<<endl;                                              gotoxy(60,8);cout<<r;
                    gotoxy(20,9);
                    cout<<r<<">. The Wedding Hall Number is  : "<<WHObj.WhallCode<<endl;            gotoxy(60,9);cout<<r;
                    gotoxy(20,10);
                    cout<<r<<">. The Wedding Hall Name is    : "<<WHObj.WhallName<<endl;            gotoxy(60,10);cout<<r;
                    gotoxy(20,11);
                    cout<<r<<">. The Wedding Hall Cost is    : "<<WHObj.WhallCost<<endl;            gotoxy(60,11);cout<<r;
                    gotoxy(20,12);
                    cout<<r<<endl;                                              gotoxy(60,12);cout<<r;
                    gotoxy(20,13);
                    cout<<s<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<t;

                    gotoxy(20,14);
                    cout<<"\n\t\t\t\t><. Enter The Wedding Hall Number: ";
                    cin>>WHObj.WhallCode;
                    WHObj.WhallAddData();

                    int pos=(-1)*static_cast<int>(sizeof(WHObj));
                    File.seekp(pos,ios::cur);
                    File.write(reinterpret_cast<char *> (&WHObj),sizeof(Wedding));
                    cout<<"\n\n\t\t\t\t\t\tRECORD UPDATE!!!!"<<endl;
                }

            }
            File.close();


        cout<<"\n\n\n\t\t\t\t\t\t You Want To Update Again then press <y>..";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        switch(getch())
        {
        case 'Y':
        case 'y':
            WHObj.WhallUpdateData();
            break;
        case 13:
            system("cls");
            MainMenuH();
            break;
        default:
            system("cls");
            MainMenuH();
            break;
        }
    }
}

void Wedding :: WhallDeleteData()
{
    Wedding WHObj;
    system("cls");
    gotoxy(2,1);
    timeANDdate();

    char ch[10];
    int k=13,Flag,rNo;

    ifstream inFile;
	inFile.open("Wrecord.dat",ios::binary | ios::in);

	if(!inFile)
    {
        system("cls");
        gotoxy(75,27);
        cout<<"Record Not Found....!!!";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        if(getch()==13)
        {
            MainMenuH();
        }
        else
        {
            MainMenuH();
        }
    }
    else
    {

        gotoxy(40,10);
        cout<<"===================================================================================\n";
        gotoxy(40,11);
        cout<<"Wedding Hall No              Wedding Hall Name                   Wedding Hall Cost"<<endl;
        gotoxy(40,12);
        cout<<"===================================================================================\n";


            while(inFile.read(reinterpret_cast<char *>(&WHObj),sizeof(Wedding)))
            {
                //cout<<endl;
                gotoxy(40,k);
                cout<<WHObj.WhallCode<<setw(27)<<" "<<WHObj.WhallName<<setw(30)<<WHObj.WhallCost<<endl;
                k+=2;
            }
            inFile.close();
        gotoxy(40,k);
        cout<<"===================================================================================\n";
        int rmId;

            cout<<"\n\t\t\t\t><. Enter the Wedding Hall Number You want to Delete: ";
            cin>>rmId;
            //ifstream inFile;
            inFile.open("Wrecord.dat",ios::binary | ios::in);

            if(!inFile)
            {
                cout<<"File Does Not Found";
                WHObj.WhallDeleteData();
            }

            ofstream outFile;
            outFile.open("tempWrecord.dat",ios::binary | ios::out | ios::app);
            inFile.seekg(0,ios::beg);

            while(inFile.read(reinterpret_cast<char *>(&WHObj),sizeof(Wedding)))
            {
                if(rmId!=WHObj.WhallCode)
                {
                    outFile.write(reinterpret_cast<char *>(&WHObj),sizeof(Wedding));
                }
            }

            outFile.close();
            inFile.close();
                remove("Wrecord.dat");
                rename("tempWrecord.dat","Wrecord.dat");
                cout<<"\n\n\t\t\t\t\t\t\tRecord Delete Success!!!!"<<endl<<endl;


        cout<<"\n\n\n\t\t\t\t\t\t You Want To Delete Again then press <y>..";
        gotoxy(168,48);
        cout<<"Press ENTER to return main menu..";
        switch(getch())
        {
        case 'Y':
        case 'y':
            WHObj.WhallDeleteData();
            break;
        case 13:
            system("cls");
            MainMenuH();
            break;
        default:
            system("cls");
            MainMenuH();
            break;
        }
    }
}


//**************************************************************************
//**************************************************************************

void ServiceCenter()
{
    system("cls");
    DecorateTopic();
    gotoxy(2,1);
    timeANDdate();
    char arr[]="Password Protect",pass[20],ch;
    int b=0;

    gotoxy(73,27);
    for(int a=0;a<10;a++)
    {
        cout<<"*";
        Sleep(50);
    }
    cout<<" ";
    for(int a=0;a<16;a++)
    {
        cout<<arr[a];
        Sleep(50);
    }
    cout<<" ";
    for(int a=0;a<10;a++)
    {
        cout<<"*";
        Sleep(50);
    }

    gotoxy(73,30);
    cout<<"Enter The Password: ";
       while(ch!=13)
       {
        ch=getch();

        if(ch!=13 && ch!=8)
        {
            putch('*');
            //cout<<"*";
            pass[b] = ch;
            b++;
        }
       }
        pass[b]='\0';
    if(strcmp(pass,pw)==0)
    {
        gotoxy(75,32);
        cout<<"      PASSWORD MATCHED";
        gotoxy(77,33);
        cout<<"Press any key to continue";
        getch();

        system("cls");
        Hotel h;
        Bar barObj;
        Meeting MHObj;
        Wedding WHObj;
        int i,j;

        DecorateTopic();
        gotoxy(2,1);
        timeANDdate();
        gotoxy(75,27);
        cout<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<" SERVICE CENTER "<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1;
        gotoxy(75,29);
        cout<<n1<<n2<<n2<<" 1.ROOM"<<endl;
        gotoxy(75,31);
        cout<<n1<<n2<<n2<<" 2.FOOD"<<endl;
        gotoxy(75,33);
        cout<<n1<<n2<<n2<<" 3.BAR"<<endl;
        gotoxy(75,35);
        cout<<n1<<n2<<n2<<" 4.MEETING HALL"<<endl;
        gotoxy(75,37);
        cout<<n1<<n2<<n2<<" 5.WEDDING HALL"<<endl;
        gotoxy(75,39);
        cout<<n1<<n2<<n2<<" 6.HELP"<<endl;
        gotoxy(75,41);
        cout<<n1<<n2<<n2<<" 7.BACK TO MAIN MENU"<<endl;
        gotoxy(75,43);
        cout<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1;
        gotoxy(75,45);
        cout<<"Enter your choice: ";
        switch(getch())
        {
            case '1':
                system("cls");
                DecorateTopic();
                gotoxy(2,1);
                timeANDdate();
                gotoxy(75,28);
                cout<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<" ROOM SERVICE "<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<endl;
                gotoxy(75,30);
                cout<<n1<<n2<<n2<<" 1.ADD ROOM"<<endl;
                gotoxy(75,32);
                cout<<n1<<n2<<n2<<" 2.UPDATE ROOM"<<endl;
                gotoxy(75,34);
                cout<<n1<<n2<<n2<<" 3.DELETE ROOM"<<endl;
                gotoxy(75,36);
                cout<<n1<<n2<<n2<<" 4.BACK TO SERVICE CENTER"<<endl;
                gotoxy(75,38);
                cout<<n1<<n2<<n2<<" 5.BACK TO MAIN MENU"<<endl;
                gotoxy(75,40);
                cout<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<endl;
                gotoxy(75,42);
                cout<<"Enter your choice: ";
                switch (getch())
                {
                case '1':
                    h.writedata();
                    break;
                case '2':
                    h.UpdateDetail();
                    break;
                case '3':
                    h.DeleteDetail();
                    break;
                case '4':
                    system("cls");
                    ServiceCenter();
                    break;
                case '5':
                    MainMenuH();
                    break;
                default:
                    system("cls");
                    ServiceCenter();
                    break;
                }
                break;
            case '2':
                FoodService();
                break;
            case '3':
                system("cls");
                DecorateTopic();
                gotoxy(75,28);
                cout<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<" BAR SERVICE "<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<endl;
                gotoxy(75,30);
                cout<<n1<<n2<<n2<<" 1.ADD ITEM"<<endl;
                gotoxy(75,32);
                cout<<n1<<n2<<n2<<" 2.UPDATE ITEM"<<endl;
                gotoxy(75,34);
                cout<<n1<<n2<<n2<<" 3.DELETE ITEM"<<endl;
                gotoxy(75,36);
                cout<<n1<<n2<<n2<<" 4.BACK TO SERVICE CENTER"<<endl;
                gotoxy(75,38);
                cout<<n1<<n2<<n2<<" 5.BACK TO MAIN MENU"<<endl;
                gotoxy(75,40);
                cout<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<endl;
                gotoxy(75,42);
                cout<<"Enter your choice: ";
                switch (getch())
                {
                case '1':
                    barObj.BarWriteData();
                    break;
                case '2':
                    barObj.BarUpdateData();
                    break;
                case '3':
                    barObj.BarDeleteData();
                    break;
                case '4':
                    system("cls");
                    ServiceCenter();
                    break;
                case '5':
                    MainMenuH();
                    break;
                default:
                    system("cls");
                    ServiceCenter();
                    break;
                }
                break;
            case '4':
                system("cls");
                DecorateTopic();
                gotoxy(2,1);
                timeANDdate();
                gotoxy(75,28);
                cout<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<" MEETING HALL SERVICE "<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<endl;
                gotoxy(75,30);
                cout<<n1<<n2<<n2<<" 1.ADD MEETING HALL"<<endl;
                gotoxy(75,32);
                cout<<n1<<n2<<n2<<" 2.UPDATE MEETING HALL"<<endl;
                gotoxy(75,34);
                cout<<n1<<n2<<n2<<" 3.DELETE MEETING HALL"<<endl;
                gotoxy(75,36);
                cout<<n1<<n2<<n2<<" 4.BACK TO SERVICE CENTER"<<endl;
                gotoxy(75,38);
                cout<<n1<<n2<<n2<<" 5.BACK TO MAIN MENU"<<endl;
                gotoxy(75,40);
                cout<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<endl;
                gotoxy(75,42);
                cout<<"Enter your choice: ";
                switch (getch())
                {
                case '1':
                    MHObj.MhallWriteData();
                    break;
                case '2':
                    MHObj.MhallUpdateData();
                    break;
                case '3':
                    MHObj.MhallDeleteData();
                    break;
                case '4':
                    system("cls");
                    ServiceCenter();
                    break;
                case '5':
                    MainMenuH();
                    break;
                default:
                    system("cls");
                    ServiceCenter();
                    break;
                }
                break;
            case '5':
                system("cls");
                DecorateTopic();
                gotoxy(2,1);
                timeANDdate();
                gotoxy(75,28);
                cout<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<" WEDDING HALL SERVICE "<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<endl;
                gotoxy(75,30);
                cout<<n1<<n2<<n2<<" 1.ADD WEDDING HALL"<<endl;
                gotoxy(75,32);
                cout<<n1<<n2<<n2<<" 2.UPDATE WEDDING HALL"<<endl;
                gotoxy(75,34);
                cout<<n1<<n2<<n2<<" 3.DELETE WEDDING HALL"<<endl;
                gotoxy(75,36);
                cout<<n1<<n2<<n2<<" 4.BACK TO SERVICE CENTER"<<endl;
                gotoxy(75,38);
                cout<<n1<<n2<<n2<<" 5.BACK TO MAIN MENU"<<endl;
                gotoxy(75,40);
                cout<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<endl;
                gotoxy(75,42);
                cout<<"Enter your choice: ";
                switch (getch())
                {
                case '1':
                    WHObj.WhallWriteData();
                    break;
                case '2':
                    WHObj.WhallUpdateData();
                    break;
                case '3':
                    WHObj.WhallDeleteData();
                    break;
                case '4':
                    system("cls");
                    ServiceCenter();
                    break;
                case '5':
                    MainMenuH();
                    break;
                default:
                    system("cls");
                    ServiceCenter();
                    break;
                }
                break;
            case '6':
                cout<<"Help";
                break;
            case '7':
                system("cls");
                MainMenuH();
                break;
            default:
                ServiceCenter();
                break;
        }
    }
    else
    {
        gotoxy(75,33);
        printf("\aWarning!! Incorrect Password");
        getch();
        ServiceCenter();
    }
}

void FoodService()
{
    system("cls");

    CofeeShop Cobj;
    FruitJuice Fobj;
    BrekFast Bobj;
    Lunch Lobj;
    Dinner Dobj;
    PastryShop Pobj;

    DecorateTopic();
    gotoxy(2,1);
    timeANDdate();

    gotoxy(75,28);
    cout<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<" FOOD SERVICE "<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<endl;
    gotoxy(75,30);
    cout<<n1<<n2<<n2<<" 1.COFEE DETAIL"<<endl;
    gotoxy(75,32);
    cout<<n1<<n2<<n2<<" 2.FRUIT DETAIL"<<endl;
    gotoxy(75,34);
    cout<<n1<<n2<<n2<<" 3.BREAK FAST DETAILS"<<endl;
    gotoxy(75,36);
    cout<<n1<<n2<<n2<<" 4.LUNCH DETAILS"<<endl;
    gotoxy(75,38);
    cout<<n1<<n2<<n2<<" 5.DINNER DETAILS"<<endl;
    gotoxy(75,40);
    cout<<n1<<n2<<n2<<" 6.PASTRY SHOP DETAILS"<<endl;
    gotoxy(75,42);
    cout<<n1<<n2<<n2<<" 7.BACK TO SERVICE CENTER"<<endl;
    gotoxy(75,44);
    cout<<n1<<n2<<n2<<" 8.BACK TO MAIN MENU"<<endl;
    gotoxy(75,46);
    cout<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<endl;

    gotoxy(75,48);
	cout<<"Enter your choice: ";

    switch(getch())
    {
    case '1':
        system("cls");
        DecorateTopic();
        gotoxy(2,1);
        timeANDdate();
        gotoxy(75,28);
        cout<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<" COFEE SERVICE "<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<endl;
        gotoxy(75,30);
        cout<<n1<<n2<<n2<<" 1.ADD DETAIL"<<endl;
        gotoxy(75,32);
        cout<<n1<<n2<<n2<<" 2.UPDATE DETAIL"<<endl;
        gotoxy(75,34);
        cout<<n1<<n2<<n2<<" 3.DELETE DETAILS"<<endl;
        gotoxy(75,36);
        cout<<n1<<n2<<n2<<" 4.BACK TO FOOD DETAIL MENU"<<endl;
        gotoxy(75,38);
        cout<<n1<<n2<<n2<<" 5.BACK TO MAIN MENU"<<endl;
        gotoxy(75,40);
        cout<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<endl;

        gotoxy(75,42);
        cout<<"Enter your choice: ";

        switch(getch())
        {
        case '1':
            Cobj.WriteCoffe();
            break;
        case '2':
            Cobj.UpdateDetailCofee();
            break;
        case '3':
            Cobj.DeleteDetailCofee();
            break;
        case '4':
            FoodService();
            break;
        case '5':
            MainMenuH();
            break;
        default:
            ServiceCenter();
            break;
        }

    case '2':
        system("cls");
        DecorateTopic();
        gotoxy(2,1);
        timeANDdate();
        gotoxy(75,28);
        cout<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<" JUICE SERVICE "<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<endl;
        gotoxy(75,30);
        cout<<n1<<n2<<n2<<" 1.ADD DETAIL"<<endl;
        gotoxy(75,32);
        cout<<n1<<n2<<n2<<" 2.UPDATE DETAIL"<<endl;
        gotoxy(75,34);
        cout<<n1<<n2<<n2<<" 3.DELETE DETAILS"<<endl;
        gotoxy(75,36);
        cout<<n1<<n2<<n2<<" 4.BACK TO FOOD DETAIL MENU"<<endl;
        gotoxy(75,38);
        cout<<n1<<n2<<n2<<" 5.BACK TO MAIN MENU"<<endl;
        gotoxy(75,40);
        cout<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<endl;

        gotoxy(70,42);
        cout<<"Enter your choice: ";

        switch(getch())
        {
        case '1':
            Fobj.WriteJuices();
            break;
        case '2':
            Fobj.UpdateDetailFruit();
            break;
        case '3':
            Fobj.DeleteDetailFruit();
            break;
        case '4':
            FoodService();
            break;
        case '5':
            MainMenuH();
            break;
        default:
            ServiceCenter();
            break;
        }

    case '3':
        system("cls");
        DecorateTopic();
        gotoxy(2,1);
        timeANDdate();
        gotoxy(75,28);
        cout<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<" BREAKFAST SERVICE "<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<endl;
        gotoxy(75,30);
        cout<<n1<<n2<<n2<<" 1.ADD DETAIL"<<endl;
        gotoxy(75,32);
        cout<<n1<<n2<<n2<<" 2.UPDATE DETAIL"<<endl;
        gotoxy(75,34);
        cout<<n1<<n2<<n2<<" 3.DELETE DETAILS"<<endl;
        gotoxy(75,36);
        cout<<n1<<n2<<n2<<" 4.BACK TO FOOD DETAIL MENU"<<endl;
        gotoxy(75,38);
        cout<<n1<<n2<<n2<<" 5.BACK TO MAIN MENU"<<endl;
        gotoxy(75,40);
        cout<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<endl;
        gotoxy(75,42);
        cout<<"Enter your choice: ";

        switch(getch())
        {
        case '1':
            Bobj.WriteBrekfast();
            break;
        case '2':
            Bobj.UpdateDetailBrekfast();
            break;
        case '3':
            Bobj.DeleteDetailBrekfast();
            break;
        case '4':
            FoodService();
            break;
        case '5':
            MainMenuH();
            break;
        default:
            ServiceCenter();
            break;
        }

    case '4':
        system("cls");
        DecorateTopic();
        gotoxy(2,1);
        timeANDdate();
        gotoxy(75,28);
        cout<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<" LUNCH SERVICE "<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<endl;
        gotoxy(75,30);
        cout<<n1<<n2<<n2<<" 1.ADD DETAIL"<<endl;
        gotoxy(75,32);
        cout<<n1<<n2<<n2<<" 2.UPDATE DETAIL"<<endl;
        gotoxy(75,34);
        cout<<n1<<n2<<n2<<" 3.DELETE DETAILS"<<endl;
        gotoxy(75,36);
        cout<<n1<<n2<<n2<<" 4.BACK TO FOOD DETAIL MENU"<<endl;
        gotoxy(75,38);
        cout<<n1<<n2<<n2<<" 5.BACK TO MAIN MENU"<<endl;
        gotoxy(75,40);
        cout<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<endl;
        gotoxy(75,42);
        cout<<"Enter your choice: ";

        switch(getch())
        {
        case '1':
            Lobj.Writelunch();
            break;
        case '2':
            Lobj.UpdateDetaillunch();
            break;
        case '3':
            Lobj.DeleteDetaillunch();
            break;
        case '4':
            FoodService();
            break;
        case '5':
            MainMenuH();
            break;
        default:
            ServiceCenter();
            break;
        }

    case '5':
        system("cls");
        DecorateTopic();
        gotoxy(2,1);
        timeANDdate();
        gotoxy(75,28);
        cout<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<" DINNER SERVICE "<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<endl;
        gotoxy(75,30);
        cout<<n1<<n2<<n2<<" 1.ADD DETAIL"<<endl;
        gotoxy(75,32);
        cout<<n1<<n2<<n2<<" 2.UPDATE DETAIL"<<endl;
        gotoxy(75,34);
        cout<<n1<<n2<<n2<<" 3.DELETE DETAILS"<<endl;
        gotoxy(75,36);
        cout<<n1<<n2<<n2<<" 4.BACK TO FOOD DETAIL MENU"<<endl;
        gotoxy(75,38);
        cout<<n1<<n2<<n2<<" 5.BACK TO MAIN MENU"<<endl;
        gotoxy(75,40);
        cout<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<endl;
        gotoxy(75,42);
        cout<<"Enter your choice: ";

        switch(getch())
        {
        case '1':
            Dobj.Writedinner();
            break;
        case '2':
            Dobj.UpdateDetaildinner();
            break;
        case '3':
            Dobj.DeleteDetaildinner();
            break;
        case '4':
            FoodService();
            break;
        case '5':
            MainMenuH();
            break;
        default:
            ServiceCenter();
            break;
        }

    case '6':
        system("cls");
        DecorateTopic();
        gotoxy(2,1);
        timeANDdate();
        gotoxy(75,28);
        cout<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<" PASTRY SERVICE "<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<endl;
        gotoxy(75,30);
        cout<<n1<<n2<<n2<<" 1.ADD DETAIL"<<endl;
        gotoxy(75,32);
        cout<<n1<<n2<<n2<<" 2.UPDATE DETAIL"<<endl;
        gotoxy(75,34);
        cout<<n1<<n2<<n2<<" 3.DELETE DETAILS"<<endl;
        gotoxy(75,36);
        cout<<n1<<n2<<n2<<" 4.BACK TO FOOD DETAIL MENU"<<endl;
        gotoxy(75,38);
        cout<<n1<<n2<<n2<<" 5.BACK TO MAIN MENU"<<endl;
        gotoxy(75,40);
        cout<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<endl;
        gotoxy(75,42);
        cout<<"Enter your choice: ";

        switch(getch())
        {
        case '1':
            Pobj.WritePastry();
            break;
        case '2':
            Pobj.UpdateDetailPastry();
            break;
        case '3':
            Pobj.DeleteDetailPastry();
            break;
        case '4':
            FoodService();
            break;
        case '5':
            MainMenuH();
            break;
        default:
            ServiceCenter();
            break;
        }

        case '7':
            ServiceCenter();
            break;
        case '8':
            MainMenuH();
            break;
        default:
            MainMenuH();
            break;
    }
}


int MainMenuH()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),31);
    DecorateTopic();
    gotoxy(2,1);
    timeANDdate();
    Sleep(500);
    Hotel h;
    Bar barObj;
    Meeting MHObj;
    Wedding WHObj;
    //int ch;
    gotoxy(75,27);
    cout<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<" MAIN MENU " <<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q;
    gotoxy(75,29);
    cout<<g<<g<<g<<g<<q<<" 1. ROOM BOOKING   ";
    gotoxy(75,31);
    cout<<g<<g<<g<<g<<q<<" 2. FOOD SECTION";
    gotoxy(75,33);
    cout<<g<<g<<g<<g<<q<<" 3. BAR SECTION";
    gotoxy(75,35);
    cout<<g<<g<<g<<g<<q<<" 4. MEETING BOOKING";
    gotoxy(75,37);
    cout<<g<<g<<g<<g<<q<<" 5. WEDDING BOOKING";
    gotoxy(75,39);
    cout<<g<<g<<g<<g<<q<<" 6. CHECK OUT";
    gotoxy(75,41);
    cout<<g<<g<<g<<g<<q<<" 7. SERVICE CENTER";
    gotoxy(75,43);
    cout<<g<<g<<g<<g<<q<<" 0. EXIT";
    gotoxy(75,45);
    cout<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q;
    gotoxy(75,47);
	cout<<"Enter your choice: ";

	switch(getch())
        {
			case '1':
			    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),31);
			    h.BookRoom();
				break;
			case '2':
			    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),31);
			    FoodConerMain();
				break;
			case '3':
			    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),31);
			    system("cls");
			    barObj.BarBuyItem();
				break;
            case '4':
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),31);
                system("cls");
                MHObj.MhallBuy();
				break;
            case '5':
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),31);
                system("cls");
                WHObj.WhallBuy();
                break;
            case '6':
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),31);
                system("cls");
                DecorateTopic();
                gotoxy(2,1);
                timeANDdate();
                gotoxy(75,30);
                cout<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<" RELEASE SECTION "<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<endl;
                gotoxy(75,32);
                cout<<n1<<n2<<n2<<" 1.ROOM"<<endl;
                gotoxy(75,34);
                cout<<n1<<n2<<n2<<" 2.MEETING HALL"<<endl;
                gotoxy(75,36);
                cout<<n1<<n2<<n2<<" 3.WEDDING HALL"<<endl;
                gotoxy(75,38);
                cout<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<endl;
                gotoxy(75,40);
                cout<<"Enter your choice: ";
                gotoxy(1,47);
                cout<<"Press ENTER to return main menu..";

                switch(getch())
                {
                case '1':
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),31);
                    h.releseRoom();
                    break;
                case '2':
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),31);
                    MHObj.releseMhall();
                    break;
                case '3':
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),31);
                    WHObj.releseWhall();
                    break;
                case 13:
                    MainMenuH();
                    break;
                default:
                    MainMenuH();
                    break;
                }
                break;
            case '7':
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),31);
                ServiceCenter();
                break;
            case '0':
                system("cls");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),31);
                gotoxy(23,7);
                cout<<"Are You sure!!!!\n\t\t\t\tThen Press (y) or (n)...";
                if(getch()=='y' | getch()=='Y')
                {
                    system("cls");
                    gotoxy(20,6);
                    cout<<"PROGRAMMER....";
                    gotoxy(20,9);
                    cout<<"1. Sachintha Madhawa     MA-DSE-192-F-011";
                    Sleep(1000);
                    gotoxy(20,10);
                    cout<<"   Mobile: +940701871192     E-mail: dsema192f011@student.nibm.lk";

                    gotoxy(50,13);
                    Sleep(1000);
                    cout<<"...................THANK YOU...................";
                    gotoxy(50,16);
                    cout<<"Exiting in 5 second...........";
                    Sleep(5000);
                    system("cls");
                    exit(0);
                }
                else
                {
                    MainMenuH();
                    system("cls");
                }

			default :
			    system("cls");
			    gotoxy(20,5);
                cout<<"\aWrong Entry!!\n\n\t\t\tPlease re-entered correct option";
                getch();
                system("cls");
                MainMenuH();
                break;
		}
}

void DecorateTopic()
{
    system("cls");
    cout<<endl;
    cout<<"\t\t\t\t\t                         @@        @@  @@@@@@@@@@  @@@@@@@@@@@      @@                 @@"<<endl;
    cout<<"\t\t\t\t\t                         @@@       @@      @@      @@@@@@@@@@@      @@@               @@@"<<endl;
    cout<<"\t\t\t\t\t                         @@@@      @@      @@      @@         @@    @@@@             @@@@"<<endl;
    cout<<"\t\t\t\t\t                         @@ @@     @@      @@      @@         @@    @@ @@           @@ @@"<<endl;
    cout<<"\t\t\t\t\t                         @@  @@    @@      @@      @@@@@@@@@@@      @@  @@         @@  @@"<<endl;
    cout<<"\t\t\t\t\t                         @@   @@   @@      @@      @@@@@@@@@@@      @@   @@       @@   @@"<<endl;
    cout<<"\t\t\t\t\t                         @@    @@  @@      @@      @@         @@    @@    @@     @@    @@"<<endl;
    cout<<"\t\t\t\t\t                         @@     @@ @@      @@      @@         @@    @@     @@   @@     @@"<<endl;
    cout<<"\t\t\t\t\t                         @@      @@@@      @@      @@         @@    @@      @@ @@      @@"<<endl;
    cout<<"\t\t\t\t\t                         @@       @@@      @@      @@@@@@@@@@@      @@       @@@       @@"<<endl;
    cout<<"\t\t\t\t\t                         @@        @@  @@@@@@@@@@  @@@@@@@@@@@      @@                 @@"<<endl;
    cout<<"\t\t\t\t\t ============================================================================================================================="<<endl;
    cout<<endl;
    cout<<"\t\t\t        @@     @@   @@@@@@@   @@@@@@@@@@  @@@@@@@@@@  @@                  @@@@@@@@@  @@      @@   @@@@@@@@@  @@@@@@@@@@  @@@@@@@@@@  @@               @@"<<endl;
    cout<<"\t\t\t        @@     @@  @@@@@@@@@  @@@@@@@@@@  @@@@@@@@@@  @@                 @@@@@@@@@@  @@      @@  @@@@@@@@@@  @@@@@@@@@@  @@@@@@@@@@  @@@             @@@"<<endl;
    cout<<"\t\t\t        @@     @@  @@     @@      @@      @@          @@                 @@           @@    @@   @@              @@      @@          @@@@           @@@@"<<endl;
    cout<<"\t\t\t        @@     @@  @@     @@      @@      @@          @@                 @@            @@  @@    @@              @@      @@          @@ @@         @@ @@"<<endl;
    cout<<"\t\t\t        @@@@@@@@@  @@     @@      @@      @@@@@@@     @@                 @@@@@@@@@      @@@@     @@@@@@@@@       @@      @@@@@@@     @@  @@       @@  @@"<<endl;
    cout<<"\t\t\t        @@@@@@@@@  @@     @@      @@      @@@@@@@     @@                  @@@@@@@@@      @@       @@@@@@@@@      @@      @@@@@@@     @@   @@     @@   @@"<<endl;
    cout<<"\t\t\t        @@     @@  @@     @@      @@      @@          @@                         @@      @@              @@      @@      @@          @@    @@   @@    @@"<<endl;
    cout<<"\t\t\t        @@     @@  @@     @@      @@      @@          @@                         @@      @@              @@      @@      @@          @@     @@ @@     @@"<<endl;
    cout<<"\t\t\t        @@     @@  @@@@@@@@@      @@      @@@@@@@@@@  @@@@@@@@@@         @@@@@@@@@@      @@      @@@@@@@@@@      @@      @@@@@@@@@@  @@      @@@      @@"<<endl;
    cout<<"\t\t\t        @@     @@   @@@@@@@       @@      @@@@@@@@@@  @@@@@@@@@@         @@@@@@@@@       @@      @@@@@@@@@       @@      @@@@@@@@@@  @@               @@"<<endl;
    cout<<"\t\t\t ==========================================================================================================================================================="<<endl;
    cout<<endl;
}

void LoadingBar()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
    gotoxy(2,1);
    timeANDdate();
    char des=219;
    gotoxy(80,21);
    cout<<"loading...";
    for(int j=0;j<=100;j++)
    {
        //system("cls");
        gotoxy(115,22);
        cout<<j<<"%"<<endl;
        gotoxy(0,21);

        cout<<"\n\t\t\t\t\t\t\t\t\t\t";
        for(int i=1;i<=j;i++)
        {

            if(i%3==0)
            {
                cout<<des;
            }
        }
        cout<<endl;
        Sleep(30);
    }
    Sleep(1000);
}

int timeANDdate()
{
    time_t t;
    t=time(NULL);
    cout<<asctime(localtime(&t));
}

int main()
{
    LoadingBar();
    MainMenuH();
}
