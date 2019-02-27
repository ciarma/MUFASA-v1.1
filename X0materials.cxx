
//Questo programma calcola la lunghezza di radiazione [m]
//di un materiale. I dati sono presi dal PDG

void X0materials(){

  double n_av = 6.022e23;
  Double_t X0; //pdg[g cm^-2]
  Double_t rho; //pdg[g cm^-3]???
  double A; //pdg
  double Z;
  Double_t X0_tgt; //n lungh rad del bers

  double berillio[] = {0,65.19,1.848,9.01218,4};
  double idrogeno[] = {0,63.04,0.071,1.008,1};
  double litio[] = {0,82.78,0.534,6.94,3};
  double carbonio[] = {0,42.70,2.267,12.0107,6};

  X0 = berillio[1]; //pdg[g cm^-2]
  rho = berillio[2]; //pdg[g cm^-3]???
  A = berillio[3]; //pdg
  Z = berillio[4];
  X0_tgt = X0/rho; //n lungh rad del bers.
  cout<<endl;
  cout<<"Bersaglio di Be"<<endl;
  cout<<"X0_tgt: "<<X0_tgt/100<<" [m]"<<endl;
  cout<<endl;

  X0 = idrogeno[1]; //pdg[g cm^-2]
  rho = idrogeno[2]; //pdg[g cm^-3]???
  A = idrogeno[3]; //pdg
  Z = idrogeno[4];
  X0_tgt = X0/rho; //n lungh rad del bers.
  cout<<endl;
  cout<<"Bersaglio di H2"<<endl;
  cout<<"X0_tgt: "<<X0_tgt/100<<" [m]"<<endl;
  cout<<endl;

  X0 = litio[1]; //pdg[g cm^-2]
  rho = litio[2]; //pdg[g cm^-3]???
  A = litio[3]; //pdg
  Z = litio[4];
  X0_tgt = X0/rho; //n lungh rad del bers.
  cout<<endl;
  cout<<"Bersaglio di Li"<<endl;
  cout<<"X0_tgt: "<<X0_tgt/100<<" [m]"<<endl;
  cout<<endl;

  X0 = carbonio[1]; //pdg[g cm^-2]
  rho = carbonio[2]; //pdg[g cm^-3]???
  A = carbonio[3]; //pdg
  Z = carbonio[4];
  X0_tgt = X0/rho; //n lungh rad del bers.
  cout<<endl;
  cout<<"Bersaglio di C"<<endl;
  cout<<"X0_tgt: "<<X0_tgt/100<<" [m]"<<endl;
  cout<<endl;


  
}//FINE
