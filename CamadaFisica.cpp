#include "CamadaFisica.h"
#include "CamadaAplicacao.h" 
#include <typeinfo>

const int valorBipolar = 1;

void CamadaFisicaTransmissora(vector<int> quadro) {
  int tipoDeCodificacao;
  vector<int> fluxoBrutoDeBits, fluxoBinario, fluxoManchester;
  vector<int> msgFinal;

  cout << "---------------------------------" << endl;
  cout << "Escolha o tipo de transmissão: " << endl;
  cout << "1 - Codificação Binária" << endl;
  cout << "2 - Codificação Manchester" << endl;
  cout << "3 - Codificação Bipolar" << endl;
  cout << "4 - Todos" << endl;
  cout << "---------------------------------" << endl;
  cin >> tipoDeCodificacao;

  switch(tipoDeCodificacao-1) {

    // Codificacao Binaria
    case 0: 
      fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoBinaria(quadro);
      cout << "Codificação Binaria é: ";
      Imprimir(fluxoBrutoDeBits);
		break;

    // Codificacao Manchester
    case 1:
      fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoManchester(quadro);
      cout << "Codificação Manchester é: ";
      Imprimir(fluxoBrutoDeBits);
		break;

    // Codificacao Bipolar
    case 2:
			fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoBipolar(quadro);
      cout << "Codificação Bipolar: ";
      Imprimir(fluxoBrutoDeBits);
    break;

    // Utilizando todas as codificações implementadas
    case 3:
      fluxoBinario = CamadaFisicaTransmissoraCodificacaoBinaria(quadro);
      cout << "Codificação Binaria é: ";
      Imprimir(fluxoBinario);

      fluxoManchester = CamadaFisicaTransmissoraCodificacaoManchester(quadro);
      cout << "Codificação Manchester é: ";
      Imprimir(fluxoManchester);

      fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoBipolar(fluxoManchester);
      cout << "Codificação Bipolar: ";
      Imprimir(fluxoBrutoDeBits);
    break;
  }
  MeioDeComunicacao(fluxoBrutoDeBits, tipoDeCodificacao);
}

// Função utilizada para imprimir nossos dados no momento em que é chamado
void Imprimir(vector<int> quadro){
  for(int i = 0; i< quadro.size(); i++){
    cout << quadro[i];
  }
  cout << endl;
}


vector<int> CamadaFisicaTransmissoraCodificacaoBinaria(vector<int> quadro){
  return quadro;
}

// Implementação da porta XOR para codificação manchester
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

// Codificação Manchester com simulação de um clock, 
// recebe e retorna um vetor de inteiros
vector<int> CamadaFisicaTransmissoraCodificacaoManchester(vector<int> quadro){
	vector<int> manchester;
  int i, clock = 0;
  for(i = 0; i < quadro.size(); i++){
		clock = 0;	// Simulando um clock
		CodManchester(quadro, manchester, clock, i);
		clock = 1;	// Simulando um clock
		CodManchester(quadro, manchester, clock, i);
	}
  return manchester;
}

// Codificação Bipolar,
// recebe e retorna um vetor de inteiros
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

void MeioDeComunicacao (vector<int> fluxoBrutoDeBits, int tipoDeCodificacao) {
	vector<int> fluxoBrutoDeBitsPontoA;
	vector<int> fluxoBrutoDeBitsPontoB;

  fluxoBrutoDeBitsPontoA = fluxoBrutoDeBits;

	for(int i = 0; i< fluxoBrutoDeBitsPontoA.size(); i++){
		fluxoBrutoDeBitsPontoB.push_back(fluxoBrutoDeBitsPontoA.at(i));
	}
  

	CamadaFisicaReceptora(fluxoBrutoDeBitsPontoB, tipoDeCodificacao);
}

void CamadaFisicaReceptora (vector<int> quadro, int tipoDeCodificacao) {
	vector<int> fluxoBrutoDeBits, fluxoBipolar, fluxoManchester;
	switch (tipoDeCodificacao-1) {

    // Decodificacao Binaria
		case 0:
			fluxoBrutoDeBits = CamadaFisicaReceptoraCodificacaoBinaria(quadro);
      cout << "Decodificação Binaria é: ";
      Imprimir(fluxoBrutoDeBits);
		break;

    // Decodificacao Manchester
		case 1:
			fluxoBrutoDeBits = CamadaFisicaReceptoraCodificacaoManchester(quadro);
      cout << "Decodificação Manchester é: ";
      Imprimir(fluxoBrutoDeBits);
		break;

    // Decodificacao Bipolar
		case 2:
			fluxoBrutoDeBits = CamadaFisicaReceptoraCodificacaoBipolar(quadro);
      cout << "Decodificação Bipolar é: ";
      Imprimir(fluxoBrutoDeBits);
		break;

    // Decodificacao de todos
    case 3:
      fluxoBipolar = CamadaFisicaReceptoraCodificacaoBipolar(quadro);
      cout << "Decodificação Bipolar é: ";
      Imprimir(fluxoBipolar);

      fluxoManchester = CamadaFisicaReceptoraCodificacaoManchester(fluxoBipolar);
      cout << "Decodificação Manchester é: ";
      Imprimir(fluxoManchester);

      fluxoBrutoDeBits = CamadaFisicaReceptoraCodificacaoBinaria(fluxoManchester);
      cout << "Decodificação Binaria é: ";
      Imprimir(fluxoBrutoDeBits);
    break;
	}
	CamadaDeAplicacaoReceptora(fluxoBrutoDeBits);
}

vector<int> CamadaFisicaReceptoraCodificacaoBinaria(vector<int> quadro){
  return quadro;
}

// Implementação da camada receptora da codificação Manchester,
// recebe e retorna um vetor de inteiros
vector<int> CamadaFisicaReceptoraCodificacaoManchester(vector<int> manchester){
  int i, clock = 0;
  vector<int> quadro;
	for(i = 0; i < manchester.size(); i++){
		if((clock % 2) == 1){ /* Simulando um clock */
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

// Implementação da camada receptora da codificação Bipolar,
// recebe e retorna um vetor de inteiros
vector<int> CamadaFisicaReceptoraCodificacaoBipolar(vector<int> quadro){
  int i = 0;
  for(i = 0; i < quadro.size(); i++){
		if(quadro[i] == valorBipolar || quadro[i] == -valorBipolar){
			quadro[i] = 1;
		}
	}
  return quadro;
}
