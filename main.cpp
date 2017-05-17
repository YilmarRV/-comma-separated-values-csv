#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

struct Est{
    char nombre[200];
    char apellido[200];
    char Fnacimiento[11];
    char CI[12];
    float notas[30];
    char direccion[500];
};


int main () {
  
  streampos size;
  int cursor=0,repetir=0;
  Est estudiante;
    ofstream Csv("estudiantes.csv",ios::trunc);  
    ifstream Binario("datos.bin", ios::in|ios::binary|ios::ate);
    if(Binario.is_open()){
        size = Binario.tellg();
        Binario.seekg (0, ios::beg);        
        do{
            if(cursor<size){
                repetir=1  ; 
                Binario.seekg(cursor);
                Binario.read (estudiante.nombre, 200);
                cursor=cursor+200;
                Binario.read (estudiante.apellido, 200);
                cursor=cursor+200;
                Binario.read (estudiante.Fnacimiento, 11);
                cursor=cursor+11;
                Binario.read (estudiante.CI,12);
                cursor=cursor+12;
                for (int x=0;x<30;x++){
                    cursor=cursor+4;
                    Binario.read((char *)(&estudiante.notas[x]),sizeof(estudiante.notas[x]));  //esta linea de codigo,permite leer un vector float de un archivo binario
                }
                Binario.read (estudiante.direccion,500);
                cursor=cursor+500;
                cursor++;
                 
                Csv<<estudiante.nombre<<","<<estudiante.apellido<<",";
                Csv<<estudiante.Fnacimiento<<","<<estudiante.CI<<",\"";
                for(int x=0;x<30;x++){
                    Csv<<estudiante.notas[x];
                    if(x<=28){
                        Csv<<",";
                    }else{
                        Csv<<"\",\"";
                    }
                }
                Csv<<estudiante.direccion<<"\"\n";
            } else repetir=0;
        }while (repetir==1);
        
        Binario.close();
    }else {
        cout<<"unable to open the file\n";
    }
  cout << "gracias por usar nuestro programa!!!\n\n";
  system("pause");
  return 0;
}
