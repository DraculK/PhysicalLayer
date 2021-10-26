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
  
  vector<int> quadroEnquadrado;

  quadroEnquadrado = CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(quadro);
  cout << "Contagem de caracteres: ";
  for(int i = 0; i< quadroEnquadrado.size(); i++){
    cout << quadroEnquadrado[i];
  }
  cout << endl;
  
  quadroEnquadrado = CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes(quadro);
  cout << "Inserção de bytes: ";
  for(int i = 0; i< quadroEnquadrado.size(); i++){
    cout << quadroEnquadrado[i];
  }
  cout << endl;
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

vector<int> CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes(vector<int> quadro){
    unsigned char FLAG = 0x0F;
    unsigned char ESC = 0xF0;
    unsigned char byte;
    std::vector<int> quadro_end;

    // Flag para indicar inicio do quadro
    InsereByte(&quadro_end, FLAG);
    int lenght = quadro.size();
    for(int i = 0; i < lenght; i += 8) {
        byte = 0x00;
        // Extrai um byte do vetor
        for(int j = 0; j < 8; j++) {
            byte |= (char)(quadro.at(i + 7 - j) << j);
        }
        // Insere caracter de escape ESC caso
        // um byte coincida com o byte de FLAG ou de ESC
        if((byte == FLAG) || (byte == ESC)) {
            InsereByte(&quadro_end, ESC);
        }
        InsereByte(&quadro_end, byte);
    }
    // Flag para indicar fim do quadro
    InsereByte(&quadro_end, FLAG);

    return quadro_end;
}
  
vector<int> CamadaEnlaceDadosTransmissoraControleDeErro(vector<int> quadro){
  vector<int> quadroFinal = quadro;
  int tipoDeErro = 0;

  switch(tipoDeErro){
    case 0:
      quadroFinal = CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar(quadro);
      break;
    case 1:
      quadroFinal = CamadaEnlaceDadosTransmissoraControleDeErroBitParidadeImpar(quadro);
      break;
    case 2:
      quadroFinal = CamadaEnlaceDadosTransmissoraControleDeErroCRC(quadro);
      break;
    case 3:
      quadroFinal = CamadaEnlaceDadosTransmissoraControleDeErroCodigoDeHamming(quadro);
      break;
  }

  return quadroFinal;
}

vector<int> CamadaEnlaceDadosReceptoraEnquadramento(vector<int> quadro){
  int tipoDeEnquadramento = 1;
  vector<int> quadroDesenquadrado;

  quadroDesenquadrado = CamadaEnlaceDadosReceptoraEnquadramentoContagemDeCaracteres(quadro);
  cout << "Contagem de caracteres: ";
  for(int i = 0; i< quadroDesenquadrado.size(); i++){
    cout << quadroDesenquadrado[i];
  }
  cout << endl;
  
  quadroDesenquadrado = CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBytes(quadro);
  cout << "Inserção de bytes: ";
  for(int i = 0; i< quadroDesenquadrado.size(); i++){
    cout << quadroDesenquadrado[i];
  }
  cout << endl;

  return quadroDesenquadrado;
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

vector<int> CamadaEnlaceDadosReceptoraControleDeErro(vector<int> quadro){
  vector<int> quadroFinal = quadro;
  int tipoDeErro = 0;

  switch(tipoDeErro){
    case 0:
      quadroFinal = CamadaEnlaceDadosReceptoraControleDeErroBitParidadePar(quadro);
      break;
    case 1:
      quadroFinal = CamadaEnlaceDadosReceptoraControleDeErroBitParidadeImpar(quadro);
      break;
    case 2:
      quadroFinal = CamadaEnlaceDadosReceptoraControleDeErroCRC(quadro);
      break;
    case 3:
      quadroFinal = CamadaEnlaceDadosReceptoraControleDeErroCodigoDeHamming(quadro);
      break;
  }

  return quadroFinal;
}

vector<int> CamadaEnlaceDadosReceptoraControleDeErroBitParidadeImpar(vector<int> quadro){
  //auxiliar para manter o valor original
  vector<int> auxQuadro = quadro;
  //bit de paridade
  int ultimoBit = auxQuadro.back();
  //retira o último bit
  auxQuadro.pop_back();
  vector<int> semUltimoBit = auxQuadro;

  if(!paridadeQuadro(semUltimoBit) && ultimoBit == 0){
    //Par e último bit zero
    return semUltimoBit;
  }else if(paridadeQuadro(semUltimoBit) && ultimoBit == 1){
    //Ímpar e último bit 1
    return semUltimoBit;
  }else{
    return semUltimoBit;
  }
}

// Montando um XOR com quadroAtual e gerador
int intXor(int quadro, int aux){
  if (quadro == 1 && aux == 0 || quadro == 0 && aux == 1){
    return 1;
  } else {
    return 0;
  }
}

vector<int> CamadaEnlaceDadosTransmissoraControleDeErroCRC(vector<int> quadro){
  vector<int> gerador = {1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1};
  vector<int> quadro = quadro;
  vector<int> quadroAtual;
  vector<int> quadroTemporario;
  size_t len; // calcula o tamanho de len (len é uma variavel dinâmica)
  int i;

  // Inserindo os zeros necessários para montar o CRC
  for(i = 0; i < 32; i++){
    quadro.push_back(0);
  }
  quadroAtual = quadro;

  for(len = 33; len <= quadro.size(); len++){
    for(i = 0; i < 33; i++){
      // Xor com polinomio gerador se if(true)
      if(quadroAtual[0] == 1){
        quadroTemporario.push_back(intXor(quadroAtual[i],gerador[i]));
      }
      // Xor com 0, se if(false)
      else{
        quadroTemporario.push_back(intXor(quadroAtual[i],0));
      }
    }
    quadroAtual = quadroTemporario;
    quadroTemporario.clear();
    // Primeiro bit do quadro, não pe mais util
    quadroTemporario.erase(quadroTemporario.begin());

    // verifica se chegamos no final da divisão
    if(len != quadro.size()){
      quadroTemporario.push_back(quadro.at(len));
    }
  }

  //Insere o CRC no quadro
  for(len = 0; len < quadroAtual.size(); len++){
    quadro.push_back(quadroAtual.at(len));
  }
  return quadro;
}

vector<int> CamadaEnlaceDadosTransmissoraControleDeErroCodigoDeHamming(vector<int> quadro){
  int tamanhoQuadro = quadro.size();
  int tamanhoHamming = 0;
  int i, j;
  unsigned int mask = 0x80000000;
  vector<int> quadroFinal;

  // Verifica o número de bits necessários de dados contidos no quadro
  // Lembrando que utilizamos potências de 2
  for(i = 0; i < 32; i++) {
    if(tamanhoQuadro & mask) {
      tamanhoHamming = 32 - i;
      break;
    }
    mask >>= 1;
  }

  tamanhoHamming += tamanhoQuadro;
  mask = 0x80000000;

  // O mesmo processo mas verificando para representar o tamanho de hamming
  for(i = 0; i < 32; i++) {
    if(tamanhoHamming & mask) {
      tamanhoHamming = 32 - i;
      break;
    }
    mask >>= 1;
  }

  // Criamos um vetor para hamming, utilizando os valores encontrados acima
  vector<int> hamming(tamanhoHamming, 0x00000000);
  int indiceQuadro = 0; // Variável auxiliar para salvar os indices

  for(i = 1; i <= (tamanhoQuadro + tamanhoHamming); i++) {
    mask = 0x00000001;
    if((log2(i) - int(log2(i))) != 0) { // Veridica se o indice é potência de 2
      // Verifica para quais bits de verificação o i-ésimo elemento contribui
      for(j = 0; j < tamanhoHamming; j++) {
        if(i & mask) {
          // XOR do bit de dado
          hamming[j] ^= quadro[indiceQuadro];
        }
        mask <<= 1;
      }
      indiceQuadro++;
    }
  }

  indiceQuadro = 0;
  j = 0;

  // Criando quadro final (lembrando que inserimos nas potências de 2)
  for(i = 1; i <= (tamanhoHamming); i++) {
    if((log2(i) - int(log2(i))) != 0) {
      quadroFinal.push_back(quadro[indiceQuadro]);
      indiceQuadro++;
    }
    else{
      quadroFinal.push_back(hamming[j]);
      j++;
    }
  }
  return quadroFinal;
}