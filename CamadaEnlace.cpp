#include "CamadaEnlace.h"
#include <math.h>

void CamadaEnlaceDadosTransmissora(vector<int> quadro){
  vector<int> quadroEnquadrado = CamadaEnlaceDadosTransmissoraEnquadramento(quadro);

  vector<int> quadroCorrigido = CamadaEnlaceDadosTransmissoraControleDeErro(quadroEnquadrado);

  CamadaFisicaTransmissora(quadroCorrigido);
}

void CamadaEnlaceDadosReceptora(vector<int> quadro){
  vector<int> quadroCorrigido = CamadaEnlaceDadosTransmissoraControleDeErro(quadro);

  vector<int> quadroEnquadrado = CamadaEnlaceDadosTransmissoraEnquadramento(quadroCorrigido);

  CamadaDeAplicacaoReceptora(quadroEnquadrado);
}