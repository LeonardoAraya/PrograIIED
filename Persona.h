#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

struct Pecado {
    string tipo;
    int cantidad;
};

struct Persona{
    int id;
    string nombre;
    string apellido;
    string pais;
    string creencia;
    string profesion;
    string correo;
    string fecha;
    Persona* amigos[100];
    int redes[7];
    Pecado pecados[7];

    Persona(){

    }

};

Persona persona[100000];
int IDNoRepetido = 1;
int cantidadPersonasTotales = 0;
int indiceSiguientePersona = cantidadPersonasTotales;



string randomNombre() {
    string nombres[1000]; // almacenar nombres
    string linea; //linea del .txt
    ifstream archivo("Nombres.txt"); //abrir el archivo

    if (archivo.is_open()) {
        int numNombres = 0; // contador de nombres leídos

        while (getline(archivo, linea) && numNombres < 1000) {
            nombres[numNombres] = linea; // Almacena cada nombre en el array
            numNombres++; //Suma al contador
        }
        archivo.close();

        if (numNombres > 0) {
            // Generar un nombre aleatorio
            int indiceAleatorio = rand() % numNombres;

            return nombres[indiceAleatorio];
        } else {
            cout << "La lista de nombres está vacía." << endl;
        }
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
    return string();
}

string randomApellido(){
    string apellidos[30];
    string linea; //para cada linea del .txt
    ifstream archivo("Apellidos.txt"); //el .txt que se lee

    if (archivo.is_open()) { //si se abre el archivo
        int numApellidos = 0; // Contador de nombres leídos
        while (getline(archivo, linea) && numApellidos < 30) {
            apellidos[numApellidos] = linea; // Almacena cada nombre en el Array
            numApellidos++; //suma al contador
        }
        archivo.close();
        if (numApellidos > 0) {
            // Generar un apellido aleatorio
            int indiceAleatorio = rand() % numApellidos;

            return apellidos[indiceAleatorio];
        } else{
            cout << "La lista de apellidos está vacía." << endl;
        }
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
    return string();
}

string randomPais(){
    string paises[20];
    string linea;
    ifstream archivo("Paises.txt");
    if(archivo.is_open()){
        int numPaises = 0;
        while (getline(archivo, linea) && numPaises < 20) {
            paises[numPaises] = linea;
            numPaises++; //suma al contador
        }
        archivo.close();
        if (numPaises > 0) {
            int indiceAleatorio = rand() % numPaises;
            return paises[indiceAleatorio];
        } else{
            cout << "La lista de paises está vacía." << endl;
        }
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
    return string();
}

string randomCreencia(){
    string creencias[10];
    string linea;
    ifstream archivo("Creencias.txt");
    if(archivo.is_open()){
        int numCreencias = 0;
        while (getline(archivo, linea) && numCreencias < 10) {
            creencias[numCreencias] = linea;
            numCreencias++; //suma al contador
        }
        archivo.close();
        if (numCreencias > 0) {
            int indiceAleatorio = rand() % numCreencias;
            return creencias[indiceAleatorio];
        } else{
            cout << "La lista de creencias está vacía." << endl;
        }
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
    return string();
}

string randomProfesion(){
    string profesiones[20];
    string linea;
    ifstream archivo("Profesiones.txt");
    if(archivo.is_open()){
        int numProfesiones = 0;
        while (getline(archivo, linea) && numProfesiones < 20) {
            profesiones[numProfesiones] = linea;
            numProfesiones++; //suma al contador
        }
        archivo.close();
        if (numProfesiones > 0) {
            int indiceAleatorio = rand() % numProfesiones;
            return profesiones[indiceAleatorio];
        } else{
            cout << "La lista de profesiones está vacía." << endl;
        }
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
    return string();
}

bool cumpleCriteriosAmistad(const Persona& persona1, const Persona& persona2) {
    return (persona1.pais == persona2.pais) && (persona1.apellido == persona2.apellido || persona1.profesion == persona2.profesion || persona1.creencia == persona2.creencia);
}

void crearAmigos() {
    for (int i = 0; i < cantidadPersonasTotales; i++) {
        int numAmigos = rand() % 101; // Genera un número aleatorio entre 0 y 100 para la cantidad de amigos.

        int amigosAgregados = 0;
        for (int j = 0; j < cantidadPersonasTotales && amigosAgregados < numAmigos; j++) {
            if (j != i && cumpleCriteriosAmistad(persona[i], persona[j])) {
                persona[i].amigos[amigosAgregados] = &persona[j];
                amigosAgregados++;
            }
        }
    }
}

void randomRedes(Persona& persona) {
    for (int i = 0; i < 7; i++) {
        int masGusta = rand() % 101;
        persona.redes[i] = masGusta; //aleatorio entre 0 y 100 a cada red.
    }
}

void iniciarPecados(Persona& persona){
    persona.pecados[0].tipo = "Lujuria";
    persona.pecados[1].tipo = "Gula";
    persona.pecados[2].tipo = "Avaricia";
    persona.pecados[3].tipo = "Pereza";
    persona.pecados[4].tipo = "Ira";
    persona.pecados[5].tipo = "Envidia";
    persona.pecados[6].tipo = "Soberbia";
    for (int i = 0; i < 7; i++) {
        persona.pecados[i].cantidad = 0;
    }
}


void crearPersonas(int cantidadDePersonas) {
    for (int i = 0; i < cantidadDePersonas; i++) {
        int indice = indiceSiguientePersona;
        if (indice < 100000) {  // Asegúrate de no exceder el tamaño del arreglo.
            persona[indice].nombre = randomNombre();
            persona[indice].apellido = randomApellido();
            persona[indice].id = IDNoRepetido;
            persona[indice].pais = randomPais();
            persona[indice].creencia = randomCreencia();
            persona[indice].profesion = randomProfesion();
            randomRedes(persona[indice]);
            iniciarPecados(persona[indice]);
            IDNoRepetido++;
            indiceSiguientePersona++;
            cantidadPersonasTotales++;
        } else {
            cout << "No se pueden agregar más personas, se alcanzó el límite." << endl;
            break;
        }
    }
    crearAmigos();
}


void imprimirPersonas() {
    for (int i = 0; i < cantidadPersonasTotales; i++) {
        cout << "Persona " << i + 1 << ":\n";
        cout << "ID: " << persona[i].id << "\n";
        cout << "Nombre: " << persona[i].nombre << "\n";
        cout << "Apellido: " << persona[i].apellido << "\n";
        cout << "Pais: " << persona[i].pais << "\n";
        cout << "Creencia: " << persona[i].creencia << "\n";
        cout << "Profesion: " << persona[i].profesion << "\n";

        //imprimir amigos:
        cout << "Amigos:\n";
        for (Persona* amigo : persona[i].amigos) {
            if (amigo != NULL) {
                std::cout << " - " << amigo->nombre << " " << amigo->apellido << "\n";
            }
        }
        cout << "Redes: " << endl;
        cout << "Twitter: " << persona[i].redes[0] << endl;
        cout << "Instagram: " << persona[i].redes[1] << endl;
        cout << "Netflix: " << persona[i].redes[2] << endl;
        cout << "Tinder: " << persona[i].redes[3] << endl;
        cout << "Facebook: " << persona[i].redes[4] << endl;
        cout << "Linkedin: " << persona[i].redes[5] << endl;
        cout << "Pinterest: " << persona[i].redes[6] << endl;
        cout << "Pecados: " << endl;
        cout << "Lujuria: " << persona[i].pecados[0].cantidad << endl;
        cout << "Gula: " << persona[i].pecados[1].cantidad << endl;\
        cout << "Avaricia: " << persona[i].pecados[2].cantidad << endl;
        cout << "Pereza: " << persona[i].pecados[3].cantidad << endl;
        cout << "Ira: " << persona[i].pecados[4].cantidad << endl;
        cout << "Envidia: " << persona[i].pecados[5].cantidad << endl;
        cout << "Soberbia: " << persona[i].pecados[6].cantidad << endl;
        std::cout << "\n";
    }
}