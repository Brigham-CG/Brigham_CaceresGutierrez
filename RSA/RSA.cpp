// compile: g++ -g -O2 -std=c++11 -pthread -march=native RSA.cpp RSAFun.cpp -o RSA -lntl -lgmp -lm
#include <iostream>
#include <NTL/ZZ.h>
#include "RSA.h"

using namespace std;
using namespace NTL;
int main(){

    cout <<"\n         ____  ____    _    \n";
    cout <<"        |  _ \\/ ___|  / \\   \n";
    cout <<"        | |_) \\___ \\ / _ \\  \n";
    cout <<"        |  _ < ___) / ___ \\ \n";
    cout <<"        |_| \\_\\____/_/   \\_\\ \n\n\n";
    int select = 0;
    cout << "1) Muestra\n";
    cout << "2) Enviar mensaje\n";
    cout << "3) Recibir mensaje\n";
    cout << "Seleccione: ";
    cin >> select;
    cin.ignore();
    if (select == 1){

        int bits = 0;
        cout << "Ingrese la cantidad de bits: "; cin >> bits;
        cin.ignore();
        RSA receptor(bits);

        RSA emisor(receptor.getE(),receptor.getN());

        // examples:
        // "vis an alii graeci ne magna elitr ubique per mei te quis reque epicuri libris deleniti appareat vel et at tale labores urbanitas sit duo eu noster epicurei consetetur sea sumo principes adversarium an prima audire apeirian ut usu nonumy complectitur vix ad id duo vero etiam adversarium et aliquam scaevola adipiscing vis nam at case salutatus contentiones decore facilis appareat eu qui ne omnesque consequuntur vim eos an amet vocent mei ei feugait salutandi mel novum causae in pro id duis dolore incorrupte option equidem sed no vis nullam menandri ullamcorper at nullam vocent splendide ut vel"
        // "el unico sistema completamente seguro es aquel que esta apagado encerrado en un bloque de cemento y sellado en una habitacion rodeada de alambradas y guardias armados"
        string mensaje = "el unico sistema completamente seguro es aquel que esta apagado encerrado en un bloque de cemento y sellado en una habitacion rodeada de alambradas y guardias armados";

        string mensajeCifrado = emisor.cifrar(mensaje);

        cout << "\nMensaje cifrado\n";

        cout << "Emisor: " << mensajeCifrado << endl;
        cout << "\nmensaje descifrado\n";
        string mensajeDescifrado = receptor.descifrar(mensajeCifrado);
        cout << "Receptor: " << "'" << mensajeDescifrado <<"'"<< endl;
    }   

    else if(select == 2)
    {

        ZZ e, N;
        cout << "e: ";cin >> e;
        cout << "N: ";cin >> N;

        cin.ignore();
        RSA emisor(e,N);
        string mensaje;
        getline(cin, mensaje);
        mensaje = emisor.cifrar(mensaje);
        cout << "Mensaje cifrado: " << mensaje << endl;

    }
    else if(select == 3)
    {
        
        int bits = 0;
        cout << "Ingrese la cantidad de bits\n"; cin >> bits;
        
        RSA receptor(bits);
        cout << "e: " << receptor.getE() << endl;
        cout << "n: " << receptor.getN() << endl;
        cin.ignore();
        string mensaje;
        cout << "Mensaje cifrado: ";
        getline(cin, mensaje);

        cout << "Mensaje descifrado: " <<receptor.descifrar(mensaje) << endl;
    }
}