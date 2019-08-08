void plotxytxt()
{

	TCanvas *c1 = new TCanvas("c1","c1",1200, 1200); //Cria o quadro para desenharmos o gráfico
	TGraphErrors *gr1 = new TGraphErrors("dados_exemplo1.txt"); //Abre um arquivo txt com valores de x, y, sx e sy separados por espaço
	gr1->SetTitle("Uma simples reta");	//Título do gráfico
	gr1->GetXaxis()->SetTitle("Uma coisa #frac{#Lambda_{a}}{#mub}"); //Legenda em X
	gr1->GetYaxis()->SetTitle("Outra #Chi^{c}");	//Legenda em Y
	gr1->SetMarkerStyle(21);
	gr1->SetMarkerColor(2);
	gr1->Draw("AP"); //Desenha axis e pontos
		
	TF1 *f1 = new TF1("f1","[0]*x+[1]",0,10); //fita uma reta de 0 a 10
	gr1->Fit("f1");	
	//~ c1->SaveAs("graph1.pdf");	//descomente para salvar um pdf
		
	std::vector<double> x; //variáveis para calcular um gráfico de resíduos
	std::vector<double> residuo; 
	std::vector<double>	ex;
	std::vector<double>	ey;

	for(Int_t i = 0; i < gr1->GetN(); i++) 
		{
		x.push_back((gr1->GetX())[i]);
		residuo.push_back(f1->Eval((gr1->GetX())[i])-(gr1->GetY())[i]); //resíduo absoluto função ajustada avaliada em xi menos yi
		ex.push_back(gr1->GetEX()[i]); //pega o sx e joga na posição i de ex
		ey.push_back(gr1->GetEY()[i]);  //pega o sy e joga na posição i de ey
		}
				
	TCanvas *c2 = new TCanvas("c2","c2",1200, 1200); //cria um quadro para desenhar o gráfico de resíduos
	TGraphErrors *gr2 = new TGraphErrors(gr1->GetN(), &x[0], &residuo[0], &ex[0], &ey[0]); //gráfico a partir de valores em vetores
	gr2->SetTitle("Res#acute{i}duos de uma simples reta");
	gr2->SetMarkerStyle(21);
	gr2->GetXaxis()->SetTitle("Uma coisa #frac{#Lambda_{a}}{#mub}");
	gr2->GetYaxis()->SetTitle("Outra #Chi^{c}-Func Ajustada");
	gr2->Draw("AP");

}

