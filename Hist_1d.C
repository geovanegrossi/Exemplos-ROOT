void Hist_1d()
    {    
    gStyle->SetOptFit(1111);    //Printa os parametros do fit no gráfico

    TCanvas* c1 = new TCanvas("c1","c1",1200,1200); //Cria um quadro para desenharmos o gráfico

    FILE* f =fopen("dados_exemplo2.txt", "r");  //cria o objeto que contem o txt que será lido
    double value;   
    double integral=0;
    TH1I* h=new TH1I("h", "h", 30, -5, 5);  //Cria um histograma com eixo indo de -5 a 5 e 30 canais
    while(fscanf(f,"%lf\n",&value)!=EOF) //Lê o txt, com doubles até chegar no fim do arquivo
        {
        h->Fill(value); //preenche o histograma h
        }
    
    TF1 *f1 = new TF1("gaus","gaus", -5, 5); //Função para fitar o histograma
    h->Fit("gaus");
    double Const = f1->GetParameter(0);
    double Mean = f1->GetParameter(1);
    double Sigma = f1->GetParameter(2);

    TLine *l1 = new TLine(Mean,0,Mean,Const); //Desenha linhas auxiliares na imagem 
    TLine *l2 = new TLine(Mean,(0.6)*Const, Mean+Sigma, (0.6)*Const);

    h->GetXaxis()->SetTitle("X");   //Título dos eixos
    h->GetYaxis()->SetTitle("Counts");

    h->Draw();  //desenha o histograma
    h->Draw("e0 same"); //desenha os erros correspondentes nos bins srqt(nbin)
    
    l1->Draw(); //desenha as linhas
    l2->Draw();
    
    TLatex latex;   
    latex.SetTextSize(0.05);
    latex.SetTextAlign(13);  //align at top
    latex.DrawLatex(Mean+Sigma/2,(0.65)*Const,"#sigma"); //Escreve sigma na imagem
    latex.DrawLatex(Mean,1.1*Const,"#LT x #GT"); //Escreve <x>

    }
