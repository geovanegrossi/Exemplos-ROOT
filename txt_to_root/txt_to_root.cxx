#include "txt_to_root.h"
#include <iostream>
#include <fstream>
#include <TFile.h>
#include <TTree.h>


using namespace std;

char* rootfname(const char* txtfname)
{
  char* str = new char[100];
  char* dot;
  sprintf(str,"%s",txtfname);
  dot = strstr(str,".txt");
  strcpy (dot,".root");
  return str;
}

void ReadEvtFile(const char *file)
{
	
  ifstream EndPointsFile;
  EndPointsFile.open(file);
 
  Int_t i;
  Int_t l;
  Double_t x0;		
  Double_t y0;
  Double_t z0;
  Double_t t0;
  Double_t e0;
  Double_t x1;
  Double_t y1;
  Double_t z1;  
  Double_t t1;
  Double_t e1;
  Int_t status;
  
  int k = 0;

  TFile* out = new TFile(rootfname(file),"RECREATE");
    
  cout << "Gerando arquivo: " << rootfname(file)<< endl;

  TTree *MyTree = new TTree("evt","evt");
  MyTree->Branch("i",&i,"i/I");
  MyTree->Branch("l",&l,"l/I");
  MyTree->Branch("x0",&x0,"x0/D");
  MyTree->Branch("y0",&y0,"y0/D");
  MyTree->Branch("z0",&z0,"z0/D");	//caso seu arquivo txt seja diferente adicione ou retire novos branchs aqui!
  MyTree->Branch("t0",&t0,"t0/D");
  MyTree->Branch("e0",&e0,"e0/D");
  MyTree->Branch("x1",&x1,"x1/D");
  MyTree->Branch("y1",&y1,"y1/D");
  MyTree->Branch("z1",&z1,"z1/D");
  MyTree->Branch("t1",&t1,"t1/D");
  MyTree->Branch("e1",&e1,"e1/D");
  MyTree->Branch("status",&status,"status/I");
  
  
  while(!EndPointsFile.eof())
	{
    EndPointsFile>>i;
    EndPointsFile>>l;
	  EndPointsFile>>x0; 		//Lembre-se de preencher o arquivo com as entradas aqui.
	  EndPointsFile>>y0;
	  EndPointsFile>>z0;
    EndPointsFile>>t0;
    EndPointsFile>>e0;
    EndPointsFile>>x1;
    EndPointsFile>>y1;
    EndPointsFile>>z1;
    EndPointsFile>>t1;
    EndPointsFile>>e1;
    EndPointsFile>>status;

	  MyTree->Fill();
	  k++;
	}
  
  cout << "Arquivo " << rootfname(file)<<" gerado com " << k <<" entradas"<< endl;
  MyTree->Write();
  EndPointsFile.close();
  delete out;
 }
	


