#include "CamadaFisica.h"
#include "CamadaAplicacao.h" 
#include <typeinfo>

const int valorBipolar = 1;

void CamadaFisicaTransmissora(vector<int> quadro) {
  int tipoDeCodificacao =  2;
  vector<int> fluxoBrutoDeBits;
  vector<int> msgFinal;

  switch(tipoDeCodificacao) {
    case 0: //codificacao binaria
      fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoBinaria(quadro);
      
			break;
    case 1: //codificacao manchester
      fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoManchester(quadro);
      cout << "Codificação Manchester é: ";
      for(int i = 0; i< fluxoBrutoDeBits.size(); i++){
        cout << fluxoBrutoDeBits[i];
      }
      cout << "\n";

      /* Isso vai ser aplicado em outro lugar, está aqui apenas para mostrar que funfa */
      msgFinal = CamadaFisicaReceptoraCodificacaoManchester(fluxoBrutoDeBits);
      cout << "Após a decodificação fica: ";
      for(int i = 0; i< msgFinal.size(); i++){
        cout << msgFinal[i];
      }
      cout << "\n";

			break;
    case 2: //codificacao bipolar
			fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoBipolar(quadro);
      cout << "Codificação Bipolar: ";
      for(int i = 0; i< fluxoBrutoDeBits.size(); i++){
        cout << fluxoBrutoDeBits[i];
      }
      cout << "\n";

      msgFinal = CamadaFisicaReceptoraCodificacaoBipolar(fluxoBrutoDeBits);
      cout << "Após a decodificação fica: ";
      for(int i = 0; i< msgFinal.size(); i++){
        cout << msgFinal[i];
      }
      cout << "\n";

      break;
  }
  MeioDeComunicacao(fluxoBrutoDeBits);
}

vector<int> CamadaFisicaTransmissoraCodificacaoBinaria(vector<int> quadro){
  return quadro;
}

void CodManchester(vector<int> bit, vector<int>& manchester, int clock, int indice){
  if(clock == 0 && bit[indice] == 0){
		manchester.push_back(0);
	}else if(clock == 0 && bit[indice] == 1){
		manchester.push_back(1);
	}else if(clock == 1 && bit[indice] == 0){
		manchester.push_back(1);
	}else if(clock == 1 && bit[indice] == 1){
		manchester.push_back(0);
	}
}

vector<int> CamadaFisicaTransmissoraCodificacaoManchester(vector<int> quadro){
	vector<int> manchester;
  int i, clock = 0;
  for(i = 0; i < quadro.size(); i++){
		clock = 0;	/* simulando um clock */
		CodManchester(quadro, manchester, clock, i);
		clock = 1;	/* simulando um clock */
		CodManchester(quadro, manchester, clock, i);
	}
  return manchester;
}

vector<int> CamadaFisicaTransmissoraCodificacaoBipolar(vector<int> quadro){
 	int i, aux = 0;
  for(i = 0; i < quadro.size(); i++){
		if(quadro[i] == 1 && aux == 0){
			quadro[i] = valorBipolar;
			aux = 1;
		}else if(quadro[i] == 1 && aux == 1){
			quadro[i] = -valorBipolar;
			aux = 0;
		}
	}
  return quadro;
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

vector<int> CamadaFisicaReceptoraCodificacaoManchester(vector<int> manchester){
  int i, clock = 0;
  vector<int> quadro;
	for(i = 0; i < manchester.size(); i++){
		if((clock % 2) == 1){ /* simulando um clock */
			if(manchester[i] == 0){
				quadro.push_back(1);
			}else if(manchester[i] == 1){
				quadro.push_back(0);
			}
		}
		clock++;
	}
  return quadro;

}

vector<int> CamadaFisicaReceptoraCodificacaoBipolar(vector<int> quadro){
  int i = 0;
  for(i = 0; i < quadro.size(); i++){
		if(quadro[i] == valorBipolar || quadro[i] == -valorBipolar){
			quadro[i] = 1;
		}
	}
  return quadro;
}
