# Exemplos-ROOT
Repositório com alguns exemplos básicos de ROOT, o programa de análise de dados desenvolvido pelo CERN, que conta com ferramentas para análise e processamento de grande quantidade de dados. Para informações sobre instalação e sobre as diversas bibliotecas consulte https://root.cern.ch/

Repository with basic ROOT examples for educational purposes.

```bash
Exemplo 1: Gráfico de duas variáveis X-Y com suas respectivas incertezas e um ajuste linear. (plotxytxt.C)
```

```bash
Exemplo 2: Histograma de uma variável com incerteza nos canais e fit gaussiano. (Hist_1d.C)
```


```bash
Exemplo 3: Multiplas curvas de duas variáveis desenhadas no mesmo Canvas. (multiplotXYtxt.C)
```

Após instalação, vá até o diretório dos exemplos e abra o root com o comando no terminal:

```bash
root
```

Execute os exemplos com o seguinte comando:

```bash
.x nomedoexemplo.C
```


# Conversão de arquivos .txt em .root

No diretório txt_to_root é possível encontrar um programa para transformar um arquivo .txt de multiplas colunas em um arquivo .root contendo uma TTree para análise de dados.

Caso queira alterar o número de branchs e seu nome faça isso no arquivo txt_to_root.cxx

Para compilar o executável faça:

```bash
make
```

Para rodar o programa:

```bash
./txt2root arquivo.txt
```



