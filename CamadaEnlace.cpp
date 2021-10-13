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

// utilizado para inserir Byte em algum Vetor
void InsereByte(vector<int> *vetor, unsigned char byte){
  unsigned char aux = 0x80;
  int i = 0;
  for(int i = 0; i < 8; i++) {
    if((byte << i) & aux) {
      vetor->push_back(1);
    } else {
      vetor->push_back(0);
    }
  }
}

vector<int> CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBytes(vector<int> quadro){
  unsigned char FLAG = 0x0F;
  unsigned char ESC = 0xF0;
  unsigned char byte;
  int aux = 0; // Verifica se o último caracter foi de escape
  vector<int> quadroFinal;

  for(int i = 0; i < quadro.size(); i += 8) {
    byte = 0x00;
    for(int j = 0; j < 8; j++) {
      byte |= (char)(quadro.at(i + 7 - j) << j);
    }
    if(aux == 1) {
      InsereByte(&quadroFinal, byte);
      aux = 0;
    } else if(byte == FLAG) {
      continue;
    } else if (byte == ESC) {
      aux = 1;
      continue;
    } else {
      InsereByte(&quadroFinal, byte);
    }
  }
  return quadroFinal;
}

vector<int> CamadaEnlaceDadosReceptoraEnquadramentoContagemDeCaracteres(vector<int> quadro){
  vector<int> quadroFinal(quadro.begin() + 8, quadro.begin() + quadro.size());
  return quadroFinal;
}