void multiplotXYtxt()
{
    	TCanvas *c3 = new TCanvas("c3","c3",400, 400);  //Canvas onde vamos desenhar o gráfico
    	c3->SetLogy(); //Queremos o eixo Y em escala LOG
    	TMultiGraph *mg = new TMultiGraph("mg","mg");   //iniciamos o objeto de Multigráficos
	   
   	gStyle->SetOptStat(0);  //Não queremos nenhuma estatistica desenhada junto ao gráfico
	   
    	TGraph *gr1 = new TGraph("dados_exemplo3a.txt");   //abrimos o primeiro txt
    	gr1->SetName("gr1"); //precisamos dar um nome para visualizar a legenda corretamente
    	gr1->SetMarkerStyle(21);   //estilo de marca
    	gr1->SetLineColor(2);   //cor da linha
    	gr1->SetMarkerColor(2); //cor da marca
    	gr1->SetLineWidth(2);   //largura da linha
	  
    	TGraph *gr2 = new TGraph("dados_exemplo3b.txt");   //abrimos o segundo txt
    	gr2->SetName("gr2");
    	gr2->SetMarkerStyle(22);
    	gr2->SetLineColor(3);
    	gr2->SetMarkerColor(3);
    	gr2->SetLineWidth(2);
     
   	mg->Add( gr1 );   //adicionamos os objetos ao multigraficos
	mg->Add( gr2 );
   
	mg->SetTitle("MultiGraph; X(U.A) ; Y(U.A)"); //titulos e legenda dos eixos
	mg->Draw("APL");  //queremos desenhar pontos(P), linhas(L) e eixos(A)

	TLegend *legend = new TLegend(0.14,0.68,0.41,0.88);   //criamos uma legenda
	legend->AddEntry((TObject*)0, "Legenda", "");   //titulo da legenda
	legend->AddEntry("gr1","y = x^{2}","lp"); //adicionamos as informações
	legend->AddEntry("gr2","y = x^{2.5}","lp");
	
	legend->Draw();   //desenhamos a legenda
   
   	//~ c1->SaveAs("Multgraph.pdf");    //salva o canvas em um pdf	
}

