//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "snake.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

#include<ctime.h>
#include<math.h>
#include<stdio.h>
#include<string.h>

#define VK_ESCAPE 0x1B
#define VK_SPASE 0x20
#define VK_RETURN 0x0D
#define VK_UP 0x26
#define VK_RIGHT 0x27
#define VK_DOWN 0x28
#define VK_LEFT 0x25
#define VK_SHIFT 0x10

   int ochki=0,k1[50],k2[50],N=0,naprav[50],izmennaprav[50],a[22][29],level=1,map=1;
   double razmer_kletki=20;
   bool konec=false,apple=false,knopkalevel=false,start=false,pause=false;
//---------------------------------------------------------------------------

void map2()
{for (int i=0;i<29;i++)
 {a[0][i]=1;
 a[21][i]=1;}
 for (int i=0;i<22;i++)
 {a[i][0]=1;
  a[i][28]=1;}
 for (int i=1;i<=8;i++)
 {a[i][5]=1;
  a[i][23]=1;}
 for (int i=16;i<=20;i++)
 a[i][14]=1;
 for (int i=7;i<=21;i++)
 a[16][i]=1;}

void map1()
{for (int i=0;i<29;i++)
 {a[0][i]=1;
  a[21][i]=1;}
 for (int i=0;i<22;i++)
 {a[i][0]=1;
  a[i][28]=1;}}

void map3()
{for (int i=0;i<29;i++)
 {a[0][i]=1;
  a[21][i]=1;}
 for (int i=0;i<22;i++)
 {a[i][0]=1;
  a[i][28]=1;}
 for (int i=3;i<=6;i++)
 {a[i][3]=1;
  a[i][6]=1;
  a[i][9]=1;
  a[i][15]=1;
  a[i][22]=1;
  a[i][25]=1;}
 for (int i=1;i<=3;i++)
 {a[6][i+3]=1;
  a[6][i+8]=1;
  a[3][i+8]=1;
  a[3][i+13]=1;
  a[4][i+17]=1;
  a[5][i+17]=1;
  a[14][i+13]=1;
  a[15][i+13]=1;
  a[16][i+13]=1;
  a[14][i+18]=1;}
 for (int i=1;i<=5;i++)
 {a[i+13][3]=1;
  a[i+13][4]=1;
  a[i+13][5]=1;
  a[i+13][8]=1;
  a[i+13][9]=1;
  a[i+13][10]=1;
  a[i+13][11]=1;
  a[i+13][14]=1;
  a[i+13][19]=1;
  a[i+13][24]=1;
  a[i+13][25]=1;
  a[i+13][26]=1;}
 a[15][4]=4;
 a[15][5]=4;
 a[15][9]=4;
 a[15][10]=4;
 a[15][15]=4;
 a[15][25]=4;
 a[16][9]=4;
 a[16][10]=4;
 a[17][4]=4;
 a[17][24]=4;
 a[17][25]=4;
 a[14][25]=4;
 a[18][9]=4;
 a[18][10]=4;}

void map4() 
{for (int i=0;i<29;i++)
 {a[0][i]=1;
  a[21][i]=1;}
 for (int i=0;i<22;i++)
 {a[i][0]=1;
  a[i][28]=1;}
 for (int i=1;i<=4;i++)
 {a[i+2][3]=1;
  a[3][i+2]=1;
  a[i+2][7]=1;
  a[i+8][3]=1;
  a[i+14][3]=1;
  a[18][i+2]=1;
  a[i+14][7]=1;
  a[i+8][7]=1;
  a[i+3][10]=1;
  a[3][i+9]=1;
  a[i+7][10]=1;
  a[i+3][13]=1;
  a[i+7][13]=1;
  a[14][i+9]=1;
  a[i+14][10]=1;
  a[i+14][13]=1;
  a[i+2][16]=1;
  a[i+2][19]=1;
  a[i+6][16]=1;
  a[i+6][19]=1;
  a[i+13][16]=1;
  a[i+13][19]=1;
  a[18][i+15]=1;
  a[i+2][22]=1;
  a[i+2][25]=1;
  a[i+8][22]=1;
  a[i+8][25]=1;
  a[i+14][22]=1;
  a[i+14][25]=1;
  a[3][i+21]=1;}}

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
for (int i1=0;i1<22;i1++)
for (int i2=0;i2<29;i2++)
a[i1][i2]=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)
{
if (Key==VK_ESCAPE) Close();
if (Key==VK_SPASE)
Button2->Click();
if (Key==VK_RETURN)
{if (start==true)
 {Timer->Enabled=false;
  Button1->Visible=true;
  Button2->Visible=true;
  Button3->Visible=true;
  Button4->Visible=true;
  Button5->Visible=true;
  Button6->Visible=true;
  records->Visible=true;
  levelvision->Visible=true;
  mapvision->Visible=true;
  pause=true;}}
if (Key==VK_UP) if ((naprav[0]!=3)&&(k2[0]-1!=k2[N])) naprav[0]=1;
if (Key==VK_RIGHT) if ((naprav[0]!=4)&&(k1[0]+1!=k1[N])) naprav[0]=2;
if (Key==VK_DOWN) if ((naprav[0]!=1)&&(k2[0]+1!=k2[N])) naprav[0]=3;
if (Key==VK_LEFT) if ((naprav[0]!=2)&&(k1[0]-1!=k1[N])) naprav[0]=4;
if ((Shift.Contains(ssShift))&&(Key == VK_RETURN)) Button1->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerTimer(TObject *Sender)
{
switch(naprav[0])
 {case 1: if ((a[k2[0]-1][k1[0]]==1)||(a[k2[0]-1][k1[0]]==4)) konec=true; break;
  case 2: if ((a[k2[0]][k1[0]+1]==1)||(a[k2[0]][k1[0]+1]==4)) konec=true; break;
  case 3: if ((a[k2[0]+1][k1[0]]==1)||(a[k2[0]+1][k1[0]]==4)) konec=true; break;
  case 4: if ((a[k2[0]][k1[0]-1]==1)||(a[k2[0]][k1[0]-1]==4)) konec=true; break;}
if (konec==true)
 {Timer->Enabled=false;
  ShowMessage("Конец игры. Твои очки: "+IntToStr(ochki));
  GameArena->Visible=false;
  Button1->Visible=true;
  Button2->Visible=true;
  Button3->Visible=true;
  Button4->Visible=true;
  Button5->Visible=true;
  Button6->Visible=true;
  records->Visible=true;
  Label1->Visible=false;
  levelvision->Visible=true;
  mapvision->Visible=true;
  FILE *F;
  char fa[5][5]={"","","","",""},a1[5],a2[10],fio[5][10]={"","","","",""};
  F=fopen("файлы//рекорды.txt","r");
  fscanf(F,"%s %s %s %s %s %s %s %s %s %s",fio[0],fa[0],fio[1],fa[1],fio[2],fa[2],fio[3],fa[3],fio[4],fa[4]);
  fclose(F);
  int a=4;
  for (int i=0;i<=4;i++)
  if (atoi(fa[i])<=ochki)
  {strcpy(a1,fa[i]);
   strcpy(a2,fio[i]);
   a=i;
   strcpy(fio[a],(InputBox("Ну ты даёшь!","Введи своё имя или ник)","").c_str()));
   itoa(ochki,fa[i],10);
   break;}
  for (int i=4;i>a+1;i--)
  {strcpy(fa[i],fa[i-1]);
   strcpy(fio[i],fio[i-1]);}
  if (a+1<4)
  {strcpy(fa[a+1],a1);
   strcpy(fio[a+1],a2);} 
  F=fopen("файлы//рекорды.txt","w");
  fseek(F,0,0);
  fprintf(F,"%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s",fio[0],fa[0],fio[1],fa[1],fio[2],fa[2],fio[3],fa[3],fio[4],fa[4]);
  fcloseall();
  start=false;}
 GameArena->Canvas->Brush->Color=clWhite;
 GameArena->Canvas->Ellipse(k1[0]*razmer_kletki,k2[0]*razmer_kletki,(k1[0]+1)*razmer_kletki,(k2[0]+1)*razmer_kletki);
 switch(naprav[0])
 {case 1: if (a[k2[0]-1][k1[0]]==3) {N++; apple=true; a[k2[0]][k1[0]]=4; k1[N]=k1[0]; k2[N]=k2[0]; naprav[N]=naprav[0];} else a[k2[0]][k1[0]]=0; k2[0]--; a[k2[0]][k1[0]]=4; break;
  case 2: if (a[k2[0]][k1[0]+1]==3) {N++; apple=true; a[k2[0]][k1[0]]=4; k1[N]=k1[0]; k2[N]=k2[0]; naprav[N]=naprav[0];} else a[k2[0]][k1[0]]=0; k1[0]++; a[k2[0]][k1[0]]=4; break;
  case 3: if (a[k2[0]+1][k1[0]]==3) {N++; apple=true; a[k2[0]][k1[0]]=4; k1[N]=k1[0]; k2[N]=k2[0]; naprav[N]=naprav[0];} else a[k2[0]][k1[0]]=0; k2[0]++; a[k2[0]][k1[0]]=4; break;
  case 4: if (a[k2[0]][k1[0]-1]==3) {N++; apple=true; a[k2[0]][k1[0]]=4; k1[N]=k1[0]; k2[N]=k2[0]; naprav[N]=naprav[0];} else a[k2[0]][k1[0]]=0; k1[0]--; a[k2[0]][k1[0]]=4; break;}
GameArena->Canvas->Brush->Color=clRed;
GameArena->Canvas->Ellipse(k1[0]*razmer_kletki,k2[0]*razmer_kletki,(k1[0]+1)*razmer_kletki,(k2[0]+1)*razmer_kletki);
if (apple==true)
{apple=false;
 switch (level)
 {case 1: ochki++; break;
  case 2: ochki+=2; break;
  case 3: ochki+=3; break;}
 Label1->Caption=IntToStr(ochki);
 GameArena->Canvas->Brush->Color=clMaroon;
 GameArena->Canvas->Ellipse(k1[N]*razmer_kletki,k2[N]*razmer_kletki,(k1[N]+1)*razmer_kletki,(k2[N]+1)*razmer_kletki);
 apple=false;
 int e,r;
 e=(GetTickCount())%21;
 r=(GetTickCount())%28;
 while ((a[e][r]==4)||(a[e][r]==1))
 {e=(GetTickCount())%21;
  r=(GetTickCount())%28;}
 a[e][r]=3;
 GameArena->Canvas->Brush->Color=clGreen;
 GameArena->Canvas->Ellipse(r*razmer_kletki,e*razmer_kletki,(r+1)*razmer_kletki,(e+1)*razmer_kletki);}
else for (int i=1;i<=N;i++)
	 {if (i==1)
	  {GameArena->Canvas->Brush->Color=clWhite;
	   GameArena->Canvas->Ellipse(k1[i]*razmer_kletki,k2[i]*razmer_kletki,(k1[i]+1)*razmer_kletki,(k2[i]+1)*razmer_kletki);
	   a[k2[i]][k1[i]]=0;}
	  switch(naprav[i])
	  {case 1: {k2[i]--; a[k2[i]][k1[i]]=4; break;}
	   case 2: {k1[i]++; a[k2[i]][k1[i]]=4; break;}
	   case 3: {k2[i]++; a[k2[i]][k1[i]]=4; break;}
	   case 4: {k1[i]--; a[k2[i]][k1[i]]=4; break;}}
	  GameArena->Canvas->Brush->Color=clMaroon;
	  GameArena->Canvas->Ellipse(k1[i]*razmer_kletki,k2[i]*razmer_kletki,(k1[i]+1)*razmer_kletki,(k2[i]+1)*razmer_kletki);
	  if (i==N) naprav[N]=naprav[0]; else naprav[i]=naprav[i+1];}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
start=true;
levelvision->Visible=false;
mapvision->Visible=false;
GameArena->Visible=true;
konec=false,apple=false;
ochki=0;
N=0;
Label1->Visible=true;
Label1->Caption=IntToStr(ochki);
GameArena->Canvas->Brush->Color=clWhite;
GameArena->Canvas->Pen->Color=clWhite;
GameArena->Canvas->Rectangle(0,0,GameArena->Width,GameArena->Height);
for (int i1=0;i1<22;i1++)
for (int i2=0;i2<29;i2++)
a[i1][i2]=0;

switch (map)
{case 1: map1(); break;
 case 2: map2(); break;
 case 3: map3(); break;
 case 4: map4(); break;}

GameArena->Canvas->Brush->Color=clBlue;
for (int i1=0;i1<22;i1++)
for (int i2=0;i2<29;i2++)
if (a[i1][i2]==1)
GameArena->Canvas->Rectangle((i2*razmer_kletki),(i1*razmer_kletki),((i2+1)*razmer_kletki),((i1+1)*razmer_kletki));
a[13][13]=4;
int e,r;
e=(GetTickCount())%21;
r=(GetTickCount())%28;
while ((a[e][r]==4)||(a[e][r]==1))
{e=(GetTickCount())%21;
 r=(GetTickCount())%28;}
a[e][r]=3;
GameArena->Canvas->Brush->Color=clRed;
GameArena->Canvas->Ellipse(13*razmer_kletki,13*razmer_kletki,14*razmer_kletki,14*razmer_kletki);
GameArena->Canvas->Brush->Color=clGreen;
GameArena->Canvas->Ellipse(r*razmer_kletki,e*razmer_kletki,(r+1)*razmer_kletki,(e+1)*razmer_kletki);
naprav[0]=2;
izmennaprav[0]=0;
k1[0]=k2[0]=13;
Button1->Visible=false;
Button2->Visible=false;
Button3->Visible=false;
Button4->Visible=false;
Button5->Visible=false;
Button6->Visible=false;
records->Visible=false;
Timer->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
MessageBox(0,"Управление змейкой осуществляется стрелками на клавиатуре.\nПробел - запуски игры, Enter - пауза, Esc - выход.\n\nВНИМАНИЕ!!! КАРТЫ С БУКВАМИ: узкие коридоры у букв являются препятствиями, если вы решите заползти от безделия в букву, то сможете проползти только по широким коридорам.","Управление",MB_OK);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
if (pause==true)
{Timer->Enabled=true;
 Button1->Visible=false;
 Button2->Visible=false;
 Button3->Visible=false;
 Button4->Visible=false;
 Button5->Visible=false;
 Button6->Visible=false;
 records->Visible=false;
 levelvision->Visible=false;
 mapvision->Visible=false;
 pause=false;}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button3Click(TObject *Sender)
{
if (knopkalevel==false)
{Button4->Top=(Button4->Top+level1->Height);
Button5->Top=(Button5->Top+level1->Height);
Button6->Top=(Button6->Top+level1->Height);
records->Top=(records->Top+level1->Height);
level1->Visible=true;
level2->Visible=true;
level3->Visible=true;
knopkalevel=true;}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::level1Click(TObject *Sender)
{
level1->Visible=false;
level2->Visible=false;
level3->Visible=false;
Button4->Top=(Button4->Top-level1->Height);
Button5->Top=(Button5->Top-level1->Height);
Button6->Top=(Button6->Top-level1->Height);
records->Top=(records->Top-level1->Height);
levelvision->Caption="Выбранный уровень сложности: 1";
Timer->Interval=200;
level=1;
knopkalevel=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::level2Click(TObject *Sender)
{
level1->Visible=false;
level2->Visible=false;
level3->Visible=false;
Button4->Top=(Button4->Top-level1->Height);
Button5->Top=(Button5->Top-level1->Height);
Button6->Top=(Button6->Top-level1->Height);
records->Top=(records->Top-level1->Height);
levelvision->Caption="Выбранный уровень сложности: 2";
level=2;
Timer->Interval=130;
knopkalevel=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::level3Click(TObject *Sender)
{
level1->Visible=false;
level2->Visible=false;
level3->Visible=false;
Button4->Top=(Button4->Top-level1->Height);
Button5->Top=(Button5->Top-level1->Height);
Button6->Top=(Button6->Top-level1->Height);
records->Top=(records->Top-level1->Height);
levelvision->Caption="Выбранный уровень сложности: 3";
level=3;
Timer->Interval=80;
knopkalevel=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::recordsClick(TObject *Sender)
{
FILE *F;
char fa[5][5],as[100]="",fio[5][10];
F=fopen("файлы//рекорды.txt","r");
fscanf(F,"%s %s %s %s %s %s %s %s %s %s",fio[0],fa[0],fio[1],fa[1],fio[2],fa[2],fio[3],fa[3],fio[4],fa[4]);
fcloseall();
strcat(as,"1) ");
strcat(as,fio[0]);
strcat(as,"\n");
strcat(as,fa[0]);
strcat(as,"\n2) ");
strcat(as,fio[1]);
strcat(as,"\n");
strcat(as,fa[1]);
strcat(as,"\n3) ");
strcat(as,fio[2]);
strcat(as,"\n");
strcat(as,fa[2]);
strcat(as,"\n4) ");
strcat(as,fio[3]);
strcat(as,"\n");
strcat(as,fa[3]);
strcat(as,"\n5) ");
strcat(as,fio[4]);
strcat(as,"\n");
strcat(as,fa[4]);
MessageBox(NULL,as,"Рекорды",MB_OK);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
map=1;	
BitBtn1->Visible=false;
BitBtn2->Visible=false;
BitBtn3->Visible=false;
BitBtn4->Visible=false;
mapvision->Caption="Выбранная карта: \"стандарт\"";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn3Click(TObject *Sender)
{
map=2;
BitBtn1->Visible=false;
BitBtn2->Visible=false;
BitBtn3->Visible=false;
BitBtn4->Visible=false;
mapvision->Caption="Выбранная карта: \"оригинал\"";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
map=3;
BitBtn1->Visible=false;
BitBtn2->Visible=false;
BitBtn3->Visible=false;
BitBtn4->Visible=false;
mapvision->Caption="Выбранная карта: \"Ист-11 Баргу\"";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn4Click(TObject *Sender)
{
map=4;
BitBtn1->Visible=false;
BitBtn2->Visible=false;
BitBtn3->Visible=false;
BitBtn4->Visible=false;
mapvision->Caption="Выбранная карта: \"ОАИП\"";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
BitBtn1->Visible=true;
BitBtn2->Visible=true;
BitBtn3->Visible=true;
BitBtn4->Visible=true;
}
//---------------------------------------------------------------------------

