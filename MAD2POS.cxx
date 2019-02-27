#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>



//Questo programma legge l'output dei positroni
//di madx e lo appende sul MIO file di output

void MAD2POS(string nomefile="ciao",int ntgt=0){

  int partID,turn;
  double x, px, y, py, ct, dE_E, s, E;

 

  //lettura file e fill istogrammi

  ifstream in;
  ofstream out;
  in.open("trackEND");
  out.open(nomefile,ios::app);


  while (1) {
    in >>partID>>turn>>x>>px>>y>>py>>ct>>dE_E>>s>>E;//turn si butta
    if(!in.good()) break;
    out<<partID<<" "<<ntgt<<" "<<x<<" "<<px<<" "<<y<<" "<<py<<" "<<ct<<" "<<dE_E<<" "<<s<<" "<<E<<endl;    
   
  }
  in.close();
  out.close();


   
}//FINE
