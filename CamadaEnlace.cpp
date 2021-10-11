#include "CamadaEnlace.h"
#include <math.h>

void CamadaEnlaceDadosTransmissora(vector<int> quadro){
  vector<int> quadroEnquadrado = CamadaEnlaceDadosTransmissoraEnquadramento(quadro);

  vector<int> quadroCorrigido = CamadaEnlaceDadosTransmissoraControleDeErro(quadroEnquadrado);

  CamadaFisicaTransmissora(quadroCorrigido);
}

void CamadaEnlaceDadosReceptora(vector<int> quadro){
  vector<int> quadroCorrigido = CamadaEnlaceDadosReceptoraControleDeErro(quadro);

  vector<int> quadroEnquadrado = CamadaEnlaceDadosReceptoraEnquadramento(quadroCorrigido);

  CamadaDeAplicacaoReceptora(quadroEnquadrado);
}

vector<int> CamadaEnlaceDadosTransmissoraEnquadramento(vector<int> quadro){
  int tipoDeEnquadramento = 0;
  vector<int> quadroEnquadrado;

  switch(tipoDeEnquadramento) {
    case 0:
      quadroEnquadrado = CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(quadro);
      break;
    case 1:
      quadroEnquadrado = CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes(quadro);
      break;
  }
  return quadroEnquadrado;
}

vector<int> CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(vector<int> quadro){
  vector<int> quadroBytes;

  //Conta os bytes
  bitset<8> howmany = ((quadro.size())/8);

  //Número de bytes no quadro
  for(int i = 7; i>=0; i--){
    quadroBytes.push_back(howmany[i]);
  }
  quadroBytes.insert(quadroBytes.end(), quadro.begin(), quadro.end());
  return quadroBytes;
}

vector<int> CamadaEnlaceDadosReceptoraEnquadramento(vector<int> quadro){
  int tipoDeEnquadramento = 0;
  vector<int> quadroDesenquadrado;

  switch(tipoDeEnquadramento) {
    case 0:
      quadroDesenquadrado = CamadaEnlaceDadosReceptoraEnquadramentoContagemDeCaracteres(quadro);
      break;
    case 1:
      quadroDesenquadrado = CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBytes(quadro);
      break;
  }

  return quadroDesenquadrado;
}

vector<int> CamadaEnlaceDadosReceptoraEnquadramentoContagemDeCaracteres(vector<int> quadro){
  vector<int> quadroFinal(quadro.begin() + 8, quadro.begin() + quadro.size());
  return quadroFinal;
}