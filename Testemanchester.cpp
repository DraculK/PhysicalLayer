/* Este arquivo é apenas um modelo, vai ser apagado posteriormente*/
#include <iostream>
#include <vector>  
using namespace std;  
int i, j = 0;
/* i é utilizado para bit e j para manchester */

void cod_manchester(vector<int> bit, vector<int>& manchester, int clock){
	if(clock == 0 && bit[i] == 0){
		manchester.push_back(0);
	}else if(clock == 0 && bit[i] == 1){
		manchester.push_back(1);
	}else if(clock == 1 && bit[i] == 0){
		manchester.push_back(1);
	}else if(clock == 1 && bit[i] == 1){
		manchester.push_back(0);
	}
}

void dec_manchester(vector<int>& novo_bit, vector<int> manchester){
	int clock = 0;
	for(j = 0; j < manchester.size(); j++){
		if((clock % 2) == 1){ /* simulando um clock */
			if(manchester[j] == 0){
				novo_bit.push_back(1);
			}else if(manchester[j] == 1){
				novo_bit.push_back(0);
			}
		}
		clock++;
	}
}

void printar(vector<int> bit){
	for(i = 0; i <bit.size(); i++){
		cout << bit[i];
	}
	cout << "\n" << endl;
}

int main() {
	vector<int> bit;
	vector<int> novo_bit;
	vector<int> manchester;
	bit.insert(bit.end(), {0, 1, 0, 1, 0, 0, 1, 1});
	int clock = 1;
	printar(bit);

	/* Codificação Manchester */
	for(i = 0; i < bit.size(); i++){
		clock = 0;	/* simulando um clock */
		cod_manchester(bit, manchester, clock);
		clock = 1;	/* simulando um clock */
		cod_manchester(bit, manchester, clock);
	}
	printar(manchester);

	/* Decodificação manchester */
	dec_manchester(novo_bit, manchester);
	printar(novo_bit);
	
    return 0;
}