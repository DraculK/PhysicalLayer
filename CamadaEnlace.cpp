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

vector<int> CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBits(vector<int> quadro){
  bitset<8> flag = 0x7E;
  int contador = 0;
  int tamanho = (int) quadro.size();

  for(int i = 0; i < tamanho; i++) {
    if(quadro[i]==0){
      contador = 0;
    }
    else contador ++;

    //insere 0 em sequenciais de uns
    if(contador == 5) {
      quadro.insert(quadro.begin() + i+1,0);
      contador = 0;
    }
  }

  for(int i = 7; i >= 0;i--){
    quadro.push_back(flag[i]);
    quadro.insert(quadro.begin(), flag[i]);
  }
  return quadro;
}
  
vector<int> CamadaEnlaceDadosTransmissoraControleDeErro(vector<int> quadro){
  vector<int> quadroFinal = quadro;
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

vector<int> CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBits(vector<int> quadro){
  vector<int> quadro_final;
  bitset<8> first_byte, last_byte;
  int tamanho = quadro.size();
  int contador = 0;
  int loop_inicio = 0;
  int loop_final = tamanho;

  //Pega os primeiro e último byte do quadro
  for(int i = 0; i < 8; i++) {
    first_byte[i] = quadro[i];
    last_byte[i] = quadro[tamanho + i - 8];
  }

  //Verifica se os primeiro e útlimo bytes tÊm uma flag e caso tenham, não insere ele no quadro desenquadrado
  if(first_byte == 0x7E) {
    loop_inicio = 8;
  }
  if(last_byte == 0x7E) {
    loop_final = tamanho - 8;
  }

  for(int i = loop_inicio; i < loop_final; i++) {
    if(quadro[i] == 1) {
      contador++;
      quadro_final.push_back(quadro[i]);
    }else{
      if(contador < 5) {
        quadro_final.push_back(quadro[i]);
      }
        contador = 0;
    }
  }
  return quadro_final;
}


vector<int> CamadaEnlaceDadosReceptoraControleDeErro(vector<int> quadro){
  vector<int> quadroFinal = quadro;
  return quadroFinal;
}

vector<int> CamadaEnlaceDadosReceptoraControleDeErroBitParidadePar(vector<int> quadro){
  //auxiliar para manter o valor original
  vector<int> auxQuadro = quadro;
  //bit de paridade
  int ultimoBit = auxQuadro.back();
  //retira o último bit
  auxQuadro.pop_back();
  vector<int> semUltimoBit = auxQuadro;

  if(CheckParidadeQuadro(semUltimoBit) && ultimoBit == 0){
    //Par e último bit zero
    return semUltimoBit;
  }else if(!CheckParidadeQuadro(semUltimoBit) && ultimoBit == 1){
    //Ímpar e último bit 1
    return semUltimoBit;
  }else{
    return semUltimoBit;
  }
}
