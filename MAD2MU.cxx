#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>





void MAD2MU(string nome_mu="ciao"){

  int partID,turn,turn0;
  double x, px, y, py, ct, dE_E, s, E, w, z;

 
  ifstream temp;
  ifstream altro;
  ofstream append;

  string dump;

  temp.open("muTEMP.tmp");
  altro.open("muPROP.tmp");
  append.open(nome_mu,ios::app);
  while(1){
    temp>>partID>>turn>>x>>px>>y>>py>>ct>>dE_E>>s>>E;
    altro>>partID>>turn>>w>>z>>turn0;
    if(!temp.good()) break;
    if(!altro.good()) break;
    if(x!=999){
      append<<partID<<" "<<turn<<" "<<x<<" "<<px<<" "<<y<<" "<<py<<" "<<ct<<" "<<dE_E<<" "<<s<<" "<<E<<" "<<w<<" "<<z<<" "<<turn0<<endl;
    }
  }
  append.close();
  temp.close();
  altro.close();



   
}//FINE
