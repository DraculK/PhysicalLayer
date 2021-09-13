/* Este arquivo é apenas um modelo, vai ser apagado posteriormente */
#include <iostream>
#include <vector>  
using namespace std;  

/* variaveis globais */
int i, aux = 0;
int v = 1;

void cod_bipolar(vector<int>& bit, int bit_size){
	for(i = 0; i < bit_size; i++){
		if(bit[i] == 1 && aux == 0){
			bit[i] = v;
			aux = 1;
		}else if(bit[i] == 1 && aux == 1){
			bit[i] = -v;
			aux = 0;
		}
	}
	/* poderiam ser utilizados também:
		bit.erase(bit.begin()+i);
		bit.insert(bit.begin()+i, v);
	*/
}

void dec_bipolar(vector<int>& bit, int bit_size){
	for(i = 0; i < bit_size; i++){
		if(bit[i] == v || bit[i] == -v){
			bit[i] = 1;
		}
	}
}

void printar(vector<int> bit){
	for(i = 0; i < 8; i++){
		std::cout << bit[i];
	}
	std::cout << "\n" << std::endl;
}

int main() {
	
	vector<int> bit;
	bit.insert(bit.end(), {0, 1, 0, 1, 0, 0, 1, 1});
	int bit_size = bit.size();
	printar(bit);

	cod_bipolar(bit, bit_size);
	printar(bit);
	
	dec_bipolar(bit, bit_size);
	printar(bit);

    return 0;
}