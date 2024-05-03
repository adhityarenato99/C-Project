#include <conio.h>
#include <iostream.h>
#include <stdio.h>
#include <dos.h>
 
main()
{
 
struct {
   int nomor;
    int nominal;
   }belipulsa[20];
 
struct {
    int tujuan;
   int nominal;
   }trfdana[20];
 
struct {
    char jenis[10];
   int nmr;
   int jmltag;
   }tagihan[20];
 
int sal=25000000;
int pin;
int a=0, b=0, c=0, i=0;
int gtpin=1234;
char jwb1, jwb2, jwb3, jwb4;
int tarik;
char Str[100]="BANK AMIR";
 
login:
//cout << "------------------------------------------\n"; // animasi bank amir
       for(int I=0 ; I<=8 ; I++)
   {
    for(int J=50 ; J>=10+I ; J--)
      {
        gotoxy(J,1);
         cout<<Str[I];
         //sleep(1);
         for(long int K=1 ; K<=9000000 ;  K++)
         {
         }
        gotoxy(J,1);
         cout<<' ';
      }
      gotoxy(1+I,1); cout<<Str[I];
 
   }
cout << "\n------------------------------------------\n"; // login bank
cout << " masukan pin anda \n";
cout << "------------------------------------------\n\n";
   do {
      cout << "pin : "; cin >>pin;
 
       if (pin == gtpin) {
            goto menu;
      } else {
        cout << "\n------------------------\n";
        textcolor(12); cprintf(" Maaf PASSWORD Salah! ");
         cout<<endl;
         cout << "--------------------------\n\n";
         i = i +1;
      }
   }
   while (i < 3);
 
   cout << "Anda Telah 3x Memasukan Pin Yang Salah\n";
   cout << "Mohon Maaf Akun Anda Kami Blockir, Hubungi CS Kami ..";
    getch();
   goto exit;
 
menu :
clrscr();
textcolor(14); cprintf(" | Menu Utama Bank ********************|");cout<<endl;//menu utama
textcolor(14); cprintf(" | 1. Bayar Tagihan     4. Tarik Tunai |");cout<<endl;
textcolor(14); cprintf(" | 2. Beli Pulsa        5. Cek Saldo   |");cout<<endl;
textcolor(14); cprintf(" | 3. Transfer Dana     6. Ganti Pin   |");cout<<endl;
textcolor(14); cprintf(" |                      7. Exit__      |");cout<<endl;
textcolor(14); cprintf(" | ************************************|");cout<<endl;
 
cout<<endl<<endl<<"  Masukan Pilihan Trx Anda : ";cin>>jwb1;
clrscr();
 
switch(jwb1)
{
 
case '1':
{
textcolor(10); cprintf(" << Multi Tagihan >> ");cout<<endl;  // tagihan
tagihan[0].jmltag=1000000;
tagihan[1].jmltag=2000000;
tagihan[2].jmltag=3000000;
tagihan[3].jmltag=4000000;
tagihan[4].jmltag=5000000;
do
    {
      cout<<endl;
      cout<<"masukan Jenis Tagihan : ";cin>>tagihan[a].jenis;
      cout<<"masukan ID Pelanggan : ";cin>>tagihan[a].nmr;
      cout<<"jumlah tagihan : "<<tagihan[a].jmltag<<endl;
        if (sal >= tagihan[a].jmltag){
                cout<<"saldo = "<<sal<<" - "<<tagihan[a].jmltag<<endl;
                sal = sal - tagihan[a].jmltag;
            textcolor(14); cprintf("(pembayaran success) Saldo Akhir = ");
            cout<<sal<<endl;
            }
        else{
            textcolor(12); cprintf("saldo anda tidak mencukupi, saldo anda saat ini : ");cout<<sal<<endl;
            }
            cout<<"Trx Payment lagi (y/t): ";cin>>jwb2;
            a++;
   }
   while (jwb2 == 'y');
   getch();
   goto menu;
}
break;
 
case '2':
{
textcolor(10); cprintf(" << Beli Pulsa >> ");cout<<endl;  // beli pulsa
 
do
    {
      cout<<endl;
    cout<<"masukkan nomor : ";cin>>belipulsa[b].nomor;
      belipulsa:
      cout<<"masukan nominal (10000 / 20000 / 50000 / 100000) : ";cin>>belipulsa[b].nominal;
 
        switch(belipulsa[b].nominal)
        {
            case 10000:
            goto trxpulsa;
            break;
 
            case 20000:
            goto trxpulsa;
            break;
 
            case 50000:
            goto trxpulsa;
            break;
 
            case 100000:
            goto trxpulsa;
            break;
 
            default:
            textcolor(12); cprintf("nominal yang masukkan salah anda");cout<<endl;
            goto belipulsa;
        }
 
 
        trxpulsa: // perintah trx pulsa
        if (sal < belipulsa[b].nominal){
            textcolor(12); cprintf("saldo anda tidak mencukupi, saldo anda saat ini : ");cout<<sal<<endl;}
        else if (sal >= belipulsa[b].nominal){
                cout<<"saldo = "<<sal<<" - "<<belipulsa[b].nominal<<endl;
                sal = sal - belipulsa[b].nominal;
                textcolor(14); cprintf("(pembelian success) saldo Akhir = ");cout<<sal<<endl;
            }
       cout<<"Beli Pulsa Lagi (y/t): ";cin>>jwb3;
       b++;
   }
   while (jwb3 == 'y');
   getch();
   goto menu;
}
break;
 
case '3':
{
textcolor(10); cprintf(" << Transfer Dana >> ");cout<<endl;  // transfer dana
do
    {
      cout<<endl;
    cout<<"masukkan nomor tujuan: ";cin>>trfdana[c].tujuan;
      cout<<"masukan nominal : ";cin>>trfdana[c].nominal;
        if (trfdana[c].nominal < 10000){
                textcolor(12); cprintf("nominal yang anda masukan salah ( min 10000 )!");cout<<endl;}
        else if (sal >= trfdana[c].nominal){
                cout<<"saldo = "<<sal<<" - "<<trfdana[c].nominal<<endl;
                sal = sal - trfdana[c].nominal;
            textcolor(14); cprintf("(transfer dana success) saldo akhir = ");cout<<sal<<endl;
            }
        else
                {
            textcolor(12); cprintf("saldo anda tidak mencukupi, saldo anda saat ini : ");cout<<sal<<endl;
            }
       cout<<"Transfer Dana lagi (y/t): ";cin>>jwb4;
       b++;
   }
   while (jwb4 == 'y');
   getch();
   goto menu;
}
break;
 
case '4':
{
textcolor(10); cprintf(" << Tarik Tunai >> ");cout<<endl;  // tarik tunai
jmltarik:
cout<<endl;
cout<<"(100000 / 300000 / 500000 / 1000000 / [kelipatan 100000])"<<endl;
cout<<"masukan nominal anda : ";cin>>tarik;
     if (tarik <100000 || tarik > 5000000 ){
            textcolor(12); cprintf(" !! nominal harus 100000 - 5000000 !!");cout<<endl;
         goto jmltarik;}
     else if (tarik%100000 != 0){
            textcolor(12); cprintf(" !! nominal harus kelipatan 100000 !!");cout<<endl;
         goto jmltarik;}
     else if (sal < tarik){
            textcolor(12); cprintf("saldo anda tidak cukup. saldo anda saat ini : ");cout<<sal<<endl;}
     else{
            cout<<"saldo = "<<sal<<" - "<<tarik<<endl;
            sal = sal - tarik;
         textcolor(14); cprintf(" Tarik Tunai Success. Saldo Anda : ");cout<<sal<<endl;         
         }
getch();
goto menu;
}
break;
 
case '5':
{
    textcolor(10); cprintf(" << Cek Saldo >> ");cout<<endl; // cek saldo
    cout<<" Saldo Anda Saat ini Adalah = "<<sal<<endl;
    getch();
    goto menu;
}
break;
 
case '6':
    {
    textcolor(10); cprintf(" << Ganti Pin >> ");cout<<endl;  // ganti pin
    cout<<" Masukan Pin baru : ";cin>>gtpin;
    pin = gtpin;
    cout<<" Ganti Pin Success<img src="/img/emoticon/smile.gif"> "<<endl;
    getch();
   clrscr();
 
    goto login;
    }
    break;
 
case '7':
    {
        exit: // exit
    }
        break;
 
    default:
    cout<<"Null"<<endl;
    getch();
    goto menu;
}<br>//This code Created By : Amir Thoham<br>
 
}