//---------------------------------------------------------------------------

#ifndef snakeH
#define snakeH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TImage *GameArena;
	TTimer *Timer;
	TLabel *Label1;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TButton *level1;
	TButton *level2;
	TButton *level3;
	TLabel *levelvision;
	TLabel *mapvision;
	TButton *records;
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn2;
	TBitBtn *BitBtn3;
	TBitBtn *BitBtn4;
	TLabel *Label2;
	void __fastcall FormKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall TimerTimer(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall level1Click(TObject *Sender);
	void __fastcall level2Click(TObject *Sender);
	void __fastcall level3Click(TObject *Sender);
	void __fastcall recordsClick(TObject *Sender);
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall BitBtn3Click(TObject *Sender);
	void __fastcall BitBtn2Click(TObject *Sender);
	void __fastcall BitBtn4Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
