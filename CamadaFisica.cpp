#include "CamadaFisica.h"
#include "CamadaAplicacao.h" 
#include <typeinfo>

void CamadaFisicaTransmissora(vector<int> quadro) {
  int tipoDeCodificacao = 2;
  vector<int> fluxoBrutoDeBits;

  switch(tipoDeCodificacao) {
    case 0: //codificacao binaria
      CamadaFisicaTransmissoraCodificacaoBinaria(quadro);
      
			break;
    case 1: //codificacao manchester
      //fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoManchester(quadro);
      cout << "case1" <<endl;
			break;
    case 2: //codificacao bipolar
			CamadaFisicaTransmissoraCodificacaoBipolar(quadro);
      for(int i = 0; i< quadro.size(); i++){
        cout << quadro[i];
      }
      cout << "\n";
      break;
  }
  MeioDeComunicacao(fluxoBrutoDeBits);
}

void CamadaFisicaTransmissoraCodificacaoBinaria(vector<int>& quadro){
  
}

vector<int> CamadaFisicaTransmissoraCodificacaoManchester(vector<int> quadro){
  cout << "case1" <<endl;
}

void CamadaFisicaTransmissoraCodificacaoBipolar(vector<int>& quadro){
 	int i, aux = 0;
  int v = 1;
  for(i = 0; i < quadro.size(); i++){
		if(quadro[i] == 1 && aux == 0){
			quadro[i] = v;
			aux = 1;
		}else if(quadro[i] == 1 && aux == 1){
			quadro[i] = -v;
			aux = 0;
		}
	}
}

void MeioDeComunicacao (vector<int> fluxoBrutoDeBits) {
	vector<int> fluxoBrutoDeBitsPontoA;
	vector<int> fluxoBrutoDeBitsPontoB;

	for(int i = 0; i< fluxoBrutoDeBitsPontoA.size(); i++){
		fluxoBrutoDeBitsPontoB.push_back(fluxoBrutoDeBitsPontoA.at(i));
	}

	//CamadaFisicaReceptora(fluxoBrutoDeBitsPontoB);
}

// void CamadaFisicaReceptora (vector<int> quadro) {
// 	int tipoDeCodificacao = 0;
// 	vector<int> fluxoBrutoDeBits;

// 	switch (tipoDeCodificacao) {
// 		case 0:
// 			fluxoBrutoDeBits = CamadaFisicaReceptoraCodificacaoBinaria(quadro);
// 			break;
// 		case 1:
// 			fluxoBrutoDeBits = CamadaFisicaReceptoraCodificacaoManchester(quadro);
// 			break;
// 		case 2:
// 			fluxoBrutoDeBits = CamadaFisicaReceptoraCodificacaoBipolar(quadro);
// 			break;
// 	}

// 	CamadaDeAplicacaoReceptora(fluxoBrutoDeBits);
// }

// vector<int> CamadaFisicaReceptoraCodificacaoBinaria(vector<int> quadro){

// }

// vector<int> CamadaFisicaReceptoraCodificacaoManchester(vector<int> quadro){

// }

// vector<int> CamadaFisicaReceptoraCodificacaoBipolar(vector<int> quadro){

// }
