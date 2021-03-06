#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>



//legge muprop.dat e lo mette in un tree
//poi legge l'output di MADX per i muoni,
//verifica quali muoni sono andati persi e
//ci mette x=999 metri, e prepara l'input
//per MSmuon.cxx

void mutrack(int ntgt=0){

  ifstream in;
  ofstream out;

  
  TTree mu("mu","viene da MADX");
  int partID,partID_tree,turn,turn0;
  double x, px, y, py, ct, dE_E, s, E, w, z;
  mu.Branch("partID_tree",&partID_tree); //ID particella
  mu.Branch("turn",&turn); // 
  mu.Branch("x",&x); // m
  mu.Branch("px",&px); // px/p0
  mu.Branch("y",&y);
  mu.Branch("py",&py);
  mu.Branch("ct",&ct); // -ct? m
  mu.Branch("dE_E",&dE_E); //
  mu.Branch("s",&s);
  mu.Branch("E",&E); // GeV
  
  in.open("trackEND");
  while (1) {
    in >>partID_tree>>turn>>x>>px>>y>>py>>ct>>dE_E>>s>>E;
    if(!in.good()) break;
    //cout<<partID_tree<<endl;
    mu.Fill();     
  }
  in.close();


  
  in.open("muPROP.tmp");
  out.open("muTEMP.tmp");

  int i=0;
  string dump;
  while (1) { 
    in>>partID>>turn>>w>>z>>turn0;
    if(!in.good()) break;
    mu.GetEntry(i);
    //cout<<partID<<" "<<partID_tree<<endl;
    if(partID==partID_tree){
      out<<partID<<" "<<ntgt<<" "<<x<<" "<<px<<" "<<y<<" "<<py<<" "<<ct<<" "<<dE_E<<" "<<s<<" "<<E<<endl;
      i++;
    }
    else{
      out<<partID<<" "<<ntgt<<" "<<"999"<<" "<<px<<" "<<y<<" "<<py<<" "<<ct<<" "<<dE_E<<" "<<s<<" "<<E<<endl;
    }

  }

  
  in.close();
  out.close();


   
}//FINE
