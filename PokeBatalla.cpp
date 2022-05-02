#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

int selectPokemonMenu(string[]);
int actionMenu();
void Play();
int main() {
//cout << sizeof(nombre)/sizeof(nombre[0]);
//min + rand() % (( max + 1 ) - min)
  
cout << "Muy buenas\nBienvenido al simulador de pokemon en consola mas generico y chafa que te puedas imaginar" << endl <<endl << endl;
  int temp = 1;
  do{
    Play();
    cout << "Quieres volver a jugar?" << endl << "  1. Volver a jugar\n  2. Salir" << endl;
    cin >> temp;
  }while(temp == 1);
  
}

void Play(){
  srand(time(NULL)); //set seed for random based on actual time
  string nombre[] = {"Machamp", "Victreebel", "Geodude", "Ponyta"};
  int slcPkIndex;
  int opPkIndex;

  //Stats
  int myAtck;
  int myHp;
  int opAtck;
  int opHp;
  
  cout << "Elige tu pokemon:" << endl;
  slcPkIndex = selectPokemonMenu(nombre)-1;
  
  cout << "Excelente has seleccionado a: " << nombre[slcPkIndex] << endl << endl;
  myAtck = 2 + rand() % ((4 + 1 ) - 2);
  myHp = 7 + rand() % ((12 + 1 ) - 7);
  cout << "Tus stats son:\nAtaque: " << myAtck <<"\nHP: " << myHp << endl << endl;

  opPkIndex =  rand() % 3;
  cout << "Un " << nombre[opPkIndex] << " salvaje ha aparecido"<< endl;
  opAtck = 2 + rand() % ((4 + 1 ) - 2);
  opHp = 7 + rand() % ((12 + 1 ) - 7);
  cout << "Sus stats son:\nAtaque: " << opAtck <<"\nHP: " << opHp << endl << endl;
  cout << "Comienza la batalla!" << endl<< endl;
  
    
  while(myHp > 0 && opHp > 0){
    int temp;
    srand(time(NULL));
    cout << "Elige una accion:" << endl;
    temp = actionMenu();
    cout << endl << endl;
    switch(temp){
      case 1: 
        //El enemigo se defendió
        if((rand() % 2) > 0){
          //No se defendio
          //El ataque fue exitoso?
          if((rand() % 2) > 0){
            cout << "El ataque fue exitoso :D" << endl;
            opHp-=myAtck;
          }
          else{
            cout << "El " << nombre[opPkIndex] << " salvaje ni siquiera se defendio y aun asi fallaste el ataque XD" << endl;
            }
          //El tambien atacó
            cout << "El " << nombre[opPkIndex] << " salvaje tambien te atacó y te hizo daño" << endl;
            myHp-=opAtck;

        }else{
          
          //Si se defendio
          //El ataque fue exitoso?
          if((rand() % 2) > 0){
            cout << "El enemigo se defendio pero aun asi el ataque fue exitoso :D" << endl;
            opHp-=myAtck;
          }
          else{
            cout << "El " << nombre[opPkIndex] << " salvaje se defendio y fallaste el ataque" << endl;
            }
        }
        break;
      
      case 2:
        if((rand() % 2) > 0){
          cout << "Te has defendido exitosamente de un ataque enemigo" << endl;
        }
        else{
          if((rand() % 2) > 0){
          cout << "Te has defendido pero aun asi te hizo daño" << endl;
            myHp-=opAtck;
        }else{
          cout << "Ambos se defendieron y nadie atacó XD" << endl;
            }
        }
        break;
    }
    cout << "----------------------------" << endl;
    cout << "Tus stats son:\nAtaque: " << myAtck <<"\nHP: " << myHp << endl << endl;
    cout << "Sus stats son:\nAtaque: " << opAtck <<"\nHP: " << opHp << endl;
    cout << "----------------------------" << endl;
  }
  cout << endl << endl;
  if(myHp <= 0){
    cout << "Mataron a tu pokemon :(" << endl;
  }else{
    cout << "Ganaste :D" << endl;
  }
  cout << endl << endl;
}

int selectPokemonMenu(string nombre[]){
  for(int i = 0; i < 4; i++){
    cout << "  " << i+1 << ". " <<nombre[i] << endl;
  }
  uint temp;
  cin >> temp;
  while(temp>4 || temp < 1){
    cout << "Elige una de las opciones disponibles(Escribe 5 si quieres volver a imprimir el menu)" << endl;
    cin >> temp;
    if(temp == 5)temp = selectPokemonMenu(nombre);
    }

  return temp;
}

int actionMenu(){
  cout << "  1. Atacar\n  2. Defenderse" << endl;
  uint temp;
  cin >> temp;
  while(temp>2 || temp < 1){
    cout << "Elige una de las opciones disponibles(Escribe 5 si quieres volver a imprimir el menu)" << endl;
    cin >> temp;
    if(temp == 5)temp = actionMenu();
    }

  return temp;
}
