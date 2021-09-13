#include "CamadaAplicacao.h"
#include <vector>

void AplicacaoTransmissora() {
  string mensagem;
  cout << "Digite uma mensagem:" << endl;
  cin >> mensagem; 

  CamadaDeAplicacaoTransmissora(mensagem);
}

void CamadaDeAplicacaoTransmissora(string mensagem) {
  vector<int> quadro = StringToBit(mensagem);
  CamadaFisicaTransmissora(quadro);
}

vector<int> StringToBit(string mensagem){
  vector<int> quadro;
  string mensagemBit;
  
  for(int i = 0; i<mensagem.size(); i++) {
    mensagemBit += std::bitset<8>(mensagem[i]).to_string();
  }

  int tamanho = mensagemBit.length();
  //cout << mensagemBit << endl;

  for(int i = 0; i < tamanho; i++){
    if (mensagemBit[i] == 48){
      quadro.push_back(0);
    }

    if (mensagemBit[i] == 49){
      quadro.push_back(1);
    }
  }

  for(int i = 0; i < tamanho; i++){
    cout << quadro[i];
  }

  cout << endl;

  return quadro;
}

// string BitToString(vector<int> quadro){

// }

// void CamadaDeAplicacaoReceptora(vector<int> quadro){
//   string mensagem = BitToString(quadro);
//   AplicacaoReceptora(mensagem);
// }

// void AplicacaoReceptora(string mensagem) {
//   cout << "A mensagem recebida foi: " << mensagem << endl;
// }