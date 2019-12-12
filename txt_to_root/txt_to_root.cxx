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
 
  Double_t x0;		
  Double_t y0;
  Double_t z0;
  
  int i = 0;

  TFile* out = new TFile(rootfname(file),"RECREATE");
    
  cout << "Gerando arquivo: " << rootfname(file)<< endl;

  TTree *MyTree = new TTree("evt","evt");
  MyTree->Branch("x0",&x0,"x0/D");
  MyTree->Branch("y0",&y0,"y0/D");
  MyTree->Branch("z0",&z0,"z0/D");	//caso seu arquivo txt seja diferente adicione ou retire novos branchs aqui!
  
  while(!EndPointsFile.eof())
	{
	  EndPointsFile>>x0; 		//Lembre-se de preencher o arquivo com as entradas aqui.
	  EndPointsFile>>y0;
	  EndPointsFile>>z0;
	  MyTree->Fill();
	  i++;
	}
  
  cout << "Arquivo " << rootfname(file)<<" gerado com " << i <<" entradas"<< endl;
  MyTree->Write();
  EndPointsFile.close();
  delete out;
 }
	


