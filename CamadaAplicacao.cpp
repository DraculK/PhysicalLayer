#include "CamadaAplicacao.h"
#include <vector>

void AplicacaoTransmissora() {
  string mensagem;
  cout << "Digite uma mensagem:" << endl;
  getline(cin, mensagem); 

  CamadaDeAplicacaoTransmissora(mensagem);
}

void CamadaDeAplicacaoTransmissora(string mensagem) {
  vector<int> quadro = StringToBit(mensagem);
  CamadaFisicaTransmissora(quadro);
}

vector<int> StringToBit(string mensagem){
  vector<int> quadro;
  string mensagemBit;

  //cout << mensagem << endl;
  
  //para fazer a conversão, utilizamos bitset para conseguir transformar nossa mensagem em um binário no formato de string.
  for(int i = 0; i<mensagem.size(); i++) {
    mensagemBit += std::bitset<8>(mensagem[i]).to_string();
  }

  //Aqui mostramos o resultado da conversão.
  int tamanho = mensagemBit.length();
  cout << "A mensagem em binário é: ";
  cout << mensagemBit << endl;

  //Nesse for, estamos comparando cada item da String com seu valor ASCII. Sendo 0 = 48 e 1 = 49. De acordo com o valor, colocamos 0 ou 1 no vetor quadro.
  for(int i = 0; i < tamanho; i++){
    if (mensagemBit[i] == 48){
      quadro.push_back(0);
    }

    if (mensagemBit[i] == 49){
      quadro.push_back(1);
    }
  }

  //for(int i = 0; i < tamanho; i++){
  //  cout << quadro[i];
  //}

  //cout << endl;

  return quadro;
}

string BitToString(vector<int> quadro){
  string mensagemBinario, final;
  vector<bitset<8>> conversor;

  //Nesse for, estamos passando por todos os itens do quadro e transformando em string para facilitar o trabalho depois.
  for(int i = 0; i < quadro.size(); i++){
    mensagemBinario += to_string(quadro[i]);
    
  }

  //Nessa parte, começamos a utilizar a biblioteca sstream, pois essa biblioteca facilita na hora da conversão.

  //Aqui, usamos as bibliotecas sstream e bitset para converter a variável 'mensagemBinario' em bits e armazenamos os bits na variável 'paraBits'. Após isso, fazemos a variável final receber 'char(paraBits.to_ulong())', pois o 'to_ulong' retorna o valor com a mesma representação do bitset, no nosso caso, usamos o char, pois queremos letras e não interos. Com isso, temos a conversão pronta.
  stringstream sstream(mensagemBinario);
  while (sstream.good())
  {
    bitset<8> paraBits;
    sstream >> paraBits;
    final += char(paraBits.to_ulong());
  }
  //cout << "O texto decodificado é: ";
  //cout << final << endl;
  return final;
}

void CamadaDeAplicacaoReceptora(vector<int> quadro){
  string mensagem = BitToString(quadro);
  AplicacaoReceptora(mensagem);
}

void AplicacaoReceptora(string mensagem) {
  cout << "A mensagem recebida foi: " << mensagem << endl;
}