
// Ejemplo de decodificar máquina de Mealy 
// Modelos de Computación - Juan Pablo Donoso 

#include <iostream>
#include <vector>
using namespace std; 

int main(){
	enum Estados {q0,q1}; // codificador con dos estados 
	Estados estado = q0; 	// estado inicial 


	int vIn[] = {-1,1,1,0,0,1,1,1}; // lista codificada 
	vIn[0] = sizeof(vIn) / sizeof(vIn[0]) - 1; 	// tamaño del vector de entrada

	std::vector<int> vOut;
	
	for(int i = 0; i < vIn[0]; i++){
		// si el anterior léido es 0, 0->0 y 1->1
		// si el anterior leído es 1, 0->1 y 1->0
		switch(estado){
			case q0:	// estaremos en el estado q0 si se ha ledio un 0
			    // el anterio leído es 0
				cout << "Estado: q0 (anterior 0)" << endl; 
				if(vIn[i] == 0) { // 0->0
					estado = q0; 
					cout << "Reentrante de q0 a q0" << endl; 
					vOut.push_back(0);
				}else if(vIn[i] == 1){ // 1->1
					estado = q1;  
					cout << "Transición de q0 a q1" << endl; 
					vOut.push_back(1);
				}
				break;
			case q1:	// estaremos en el estado q1 si se ha leido un 1 
				cout << "Estado q1 (anterior 1)" << endl;
				 if (vIn[i] == 0) { // 0 -> 1
				 	vOut.push_back(1);
				 	estado = q0;
				 	cout << "Transición de q1 a q0" << endl; 	
				 }else if (vIn[i] == 1){ //1 -> 1 
				 	vOut.push_back(0);
				 	cout << "Reentrante de q1 a q1" << endl; 
				 	estado = q1; 
				 }
				 break;
		}
	}

	// imprimir el vector
	cout << "Resultado decodificado:" << " "; 
	for(int i = 0; i <= vOut.size(); i++){
		cout << vOut[i] << " ";  
	}


}

