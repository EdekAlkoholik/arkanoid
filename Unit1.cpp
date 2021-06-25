//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "mmsystem.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

        int x=8,y=8;
        bool kolizja(TImage*pilka, TImage* cegla){
             if( pilka->Left >= cegla->Left - pilka->Width &&
                 pilka->Left <= cegla->Left+cegla->Width &&
                 pilka->Top >= cegla->Top-pilka->Height &&
                 pilka->Top <= cegla->Top+cegla->Height){
                  return true;
                 }
             else return false;
        }
        int win=0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerbTimer(TObject *Sender)
{
        b->Left+=x;
        b->Top+=y;
        //odbij od lewej
        if(b->Left-5<=tlo->Left) x=-x;
        //odbij od prawej
        if(b->Left>=1250) x=-x;
        //odbij od gory
        if(b->Top-15<=tlo->Top) y=-y;
        //spadla w dol
        if(b->Top>=p->Top-p->Height+b->Height){
                Timerb->Enabled=false;
                b->Visible=false;
                Button1->Visible=true;
                sndPlaySound("snd/wilhelm.wav",SND_ASYNC);
        }
        else if((b->Left>p->Left-b->Width/2)&&(b->Left<(p->Left+p->Width))&&(b->Top+b->Height>p->Top)){
        if(y>0)y=-y;
        if((lewo->Enabled)||(prawo->Enabled)){
        x=-x;
        b->Picture->LoadFromFile("jpg/ball2.bmp");
        }
        else b->Picture->LoadFromFile("jpg/ball.bmp");
        sndPlaySound("snd/ping.wav",SND_ASYNC);

        }
        //obsluga kolizji
        if(kolizja(b,Image1)&&(Image1->Visible==true)){
           x=-x;
           y=-y;
           Image1->Visible=false;
           win++;
           sndPlaySound("snd/pkt.wav",SND_ASYNC);
        }
        if(kolizja(b,Image2)&&Image2->Visible==true){
           x=-x;y=-y;
           Image2->Visible=false;
           win++;
           sndPlaySound("snd/pkt.wav",SND_ASYNC);
        }
        if(kolizja(b,Image3)&&Image3->Visible==true){
           x=-x;y=-y;
           Image3->Visible=false;
           win++;
           sndPlaySound("snd/pkt.wav",SND_ASYNC);
        }
        if(kolizja(b,Image4)&&Image4->Visible==true){
           x=-x;y=-y;
           Image4->Visible=false;
           win++;
           sndPlaySound("snd/pkt.wav",SND_ASYNC);
        }
        if(kolizja(b,Image5)&&Image5->Visible==true){
           x=-x;y=-y;
           Image5->Visible=false;
           win++;
           sndPlaySound("snd/pkt.wav",SND_ASYNC);
        }
        if(kolizja(b,Image6)&&Image6->Visible==true){
           x=-x;y=-y;
           Image6->Visible=false;
           win++;
           sndPlaySound("snd/pkt.wav",SND_ASYNC);
        }
        if(kolizja(b,Image7)&&Image7->Visible==true){
           x=-x;y=-y;
           Image7->Visible=false;
           win++;
           sndPlaySound("snd/pkt.wav",SND_ASYNC);
        }
        if(kolizja(b,Image8)&&Image8->Visible==true){
           x=-x;y=-y;
           Image8->Visible=false;
           win++;
           sndPlaySound("snd/pkt.wav",SND_ASYNC);
        }
        if(kolizja(b,Image9)&&Image9->Visible==true){
           x=-x;y=-y;
           Image9->Visible=false;
           win++;
           sndPlaySound("snd/pkt.wav",SND_ASYNC);
        }
        if(kolizja(b,Image10)&&Image10->Visible==true){
           x=-x;y=-y;
           Image10->Visible=false;
           win++;
           sndPlaySound("snd/pkt.wav",SND_ASYNC);
        }
        if(kolizja(b,Image11)&&Image11->Visible==true){
           x=-x;y=-y;
           Image11->Visible=false;
           win++;
           sndPlaySound("snd/pkt.wav",SND_ASYNC);
        }
        if(kolizja(b,image12)&&image12->Visible==true){
           x=-x;y=-y;
           image12->Visible=false;
           win++;
           sndPlaySound("snd/pkt.wav",SND_ASYNC);
        }



        if(win>=12){
          Timerb->Enabled=false;
          b->Visible=false;
          Button1->Visible=true;
        }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::lewoTimer(TObject *Sender)
{
        if(p->Left>=10)  p->Left-=30;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::prawoTimer(TObject *Sender)
{
        if(p->Left<(tlo->Width-p->Width-21)) p->Left+=30;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key==VK_LEFT) lewo->Enabled=true;
        if(Key==VK_RIGHT) prawo->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key==VK_LEFT) lewo->Enabled=false;
        if(Key==VK_RIGHT) prawo->Enabled=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        b->Left=50;
        b->Top=50;

        b->Visible=true;
        x=-8; y=-8;
        Timerb->Enabled=true;
        Button1->Visible=false;
        win=0;
        Image1->Visible=true;
        Image2->Visible=true;
        Image3->Visible=true;
        Image4->Visible=true;
        Image5->Visible=true;
        Image6->Visible=true;
        Image7->Visible=true;
        Image8->Visible=true;
        Image9->Visible=true;
        Image10->Visible=true;
        Image11->Visible=true;
        image12->Visible=true;
        p->Left=504;
}
//---------------------------------------------------------------------------

