#include"objetos.h"
#include<iostream>

//metodos del soldado//
void soldado::movimiento(std::vector<std::vector<float>> matriz){
	srand(time(NULL));
	while(true){
		  srand(time(NULL));
		  float arr[] = {matriz[posx-1][posy+1], matriz[posx][posy+1], matriz[posx+1][posy+1], matriz[posx-1][posy], matriz[posx+1][posy], matriz[posx-1][posy-1], matriz[posx][posy-1], matriz[posx+1][posy-1]};
        	sort(arr, arr + 8);
        	int R = log2(rand() % 256);
		if (arr[R] == matriz[lposx][lposy]){
			R--;
		}
        	if(arr[R] == matriz[posx-1][posy+1]){
                	posy += 1;
                	posx -= 1;
        	}
        	else if(arr[R] == matriz[posx][posy+1]){
                	posy += 0;
                	posx -= 1;

        	}	
        	else if(arr[R] == matriz[posx+1][posy+1]){
        	        posy += 1;
        	        posx += 1;
	
	        }
	        else if(arr[R] == matriz[posx-1][posy]){
        	        posy += 0;
        	        posx -= 1;

       		}
        	else if(arr[R] == matriz[posx+1][posy]){
                	posy += 0;
                	posx += 1;

        	}
        	else if(arr[R] == matriz[posx-1][posy-1]){
                	posy -= 1;
                	posx -= 1;

        	}
        	else if(arr[R] == matriz[posx][posy-1]){
                	posy -= 1;
                	posx += 0;


		}
		else if(arr[R] == matriz[posx+1][posy-1]){
                	posy -= 1;
                	posx += 1;

		
                }
		lposy = posy;
		lposx = posx;
	}
}
//fin//
//metodos obrera//
void obrera::movimiento(std::vector<std::vector<float>> matriz){
	  while(true){
                  srand(time(NULL));

        float arr[] = {matriz[posx-1][posy+1], matriz[posx][posy+1], matriz[posx+1][posy+1], matriz[posx-1][posy], matriz[posx+1][posy], matriz[posx-1][posy-1], matriz[posx][posy-1], ma
triz[posx+1][posy-1]};
        sort(arr, arr + 8);
        int R = log2(rand() % 256);
	if (arr[R] == matriz[lposx][lposy]){
                        R--;
                }
        if(arr[R] == matriz[posx-1][posy+1]){
                posy += 1;
                posx -= 1;
        }
        else if(arr[R] == matriz[posx][posy+1]){
                posy += 0;
                posx -= 1;

        }
        else if(arr[R] == matriz[posx+1][posy+1]){
                posy += 1;
                posx += 1;

        }
        else if(arr[R] == matriz[posx-1][posy]){
                posy += 0;
                posx -= 1;

        }
        else if(arr[R] == matriz[posx+1][posy]){
                posy += 0;
                posx += 1;

        }
        else if(arr[R] == matriz[posx-1][posy-1]){
                posy -= 1;
                posx -= 1;

        }
        else if(arr[R] == matriz[posx][posy-1]){
                posy -= 1;
                posx += 0;


                }
        else if(arr[R] == matriz[posx+1][posy-1]){
                posy -= 1;
                posx += 1;
	}
	lposx = posx;
	lposy = posy
	}
}
//fin//
//metodos reina//
void reina::movimiento(std::vector<std::vector<float>> matriz){
	while(true){
                  srand(time(NULL));

        float arr[] = {matriz[posx-1][posy+1], matriz[posx][posy+1], matriz[posx+1][posy+1], matriz[posx-1][posy], matriz[posx+1][posy], matriz[posx-1][posy-1], matriz[posx][posy-1], ma
triz[posx+1][posy-1]};
        sort(arr, arr + 8);
        int R = log2(rand() % 256);
        if(arr[R] == matriz[posx-1][posy+1]){
                posy += 1;
                posx -= 1;
        }
        else if(arr[R] == matriz[posx][posy+1]){
                posy += 0;
                posx -= 1;

        }
        else if(arr[R] == matriz[posx+1][posy+1]){
                posy += 1;
                posx += 1;

        }
        else if(arr[R] == matriz[posx-1][posy]){
                posy += 0;
                posx -= 1;

        }
        else if(arr[R] == matriz[posx+1][posy]){
                posy += 0;
                posx += 1;

        }
        else if(arr[R] == matriz[posx-1][posy-1]){
                posy -= 1;
                posx -= 1;

        }
        else if(arr[R] == matriz[posx][posy-1]){
                posy -= 1;
                posx += 0;


                }
        else if(arr[R] == matriz[posx+1][posy-1]){
		posy -= 1;
                posx += 1;
        }
	  if(matriz[posiciony][posicionx] > matriz[posiciony +1][posicionx-1] && matriz[posiciony][posicionx] > matriz[posiciony +1][posicionx] &&
                matriz[posiciony][posicionx] > matriz[posiciony + 1][posicionx + 1] && matriz[posiciony][posicionx] > matriz[posiciony][posicionx - 1]
                && matriz[posiciony][posicionx] > matriz[posiciony][posicionx+1] && matriz[posiciony][posicionx] > matriz[posiciony-1][posicionx-1]
        	&& matriz[posiciony][posicionx] > matriz[posiciony -1][posicionx] && matriz[posiciony][posicionx] > matriz[posiciony - 1][posicionx + 1])
                                         break;

	}

}
void reina::crear_obrera(){
	
}
void reina::crear_soldado(){

}
void reina::crear_reina(){

}
//fin metodos reina//
