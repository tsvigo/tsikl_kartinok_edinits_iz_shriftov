#include "dialog.h"
#include "ui_dialog.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Dialog::Dialog
/// \param parent
#include <iostream>
#include <fstream>
using namespace std;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///  
Dialog::Dialog(QWidget *parent)
     : QDialog(parent)
     , ui(new Ui::Dialog)
     {
          ui->setupUi(this);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //   QString myString;
    const int len = 2832, strings =2480;
    const char ch = '\n';
    char mass[len][strings];
    
 // magick -background white -fill  black -pointsize 72   -font "shrift" -size 10  label:1  +antialias  "/home/viktor/my_projects_qt_2/kartinki_iz_shriftov/papka-fonts-sort/shrift.bmp"
   
    
    
    ifstream fs("/home/viktor/my_projects_qt_2/kartinki_iz_shriftov/fonts-sort", ios::in | ios::binary);
    
    QString comanda1="magick -background white -fill  black -pointsize 72   -font \"";    
      QString font;
    QString comanda3="\"  -size 10  label:1  +antialias  \"/home/viktor/my_projects_qt_2/kartinki_iz_shriftov/papka-fonts-sort/";
   QString comanda4=".bmp\"";
    QString comanda_vsia;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    for(int r = 0; r<strings; r++)
    {
        fs.getline(mass[r], len-1,ch); //Считываем строки в массив
        
        font=mass[r];
       
        comanda_vsia=comanda1+font+comanda3+font+comanda4;
        system (comanda_vsia.toStdString().c_str() );
     
    }

    fs.close(); //Закрываем файл          
     }

Dialog::~Dialog()
     {
          delete ui;
     }

