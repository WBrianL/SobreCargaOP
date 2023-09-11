#include <conio.h>
#include <iostream>
#include <string>

using namespace std;

class empleado{
private:
	int ClaveEmpleado;
	string nombre;
	string domicilio;
	float sueldo;
	string reporta;
	public:
//metos costructores
	empleado(){
		ClaveEmpleado=0;
		nombre=" ";
		domicilio=" ";
		sueldo=0;
		reporta=" ";
	}
	empleado(int clave, string nom, string dom, float suel, string report){
	 ClaveEmpleado=clave;
	 nombre=nom;
	 domicilio=dom;
	 sueldo=suel;
	 reporta=report;
	}
	int comparar(){
        return(ClaveEmpleado);
	}
	//Sobre Carga
	bool operator==(empleado& e){
	    return ((ClaveEmpleado==e.ClaveEmpleado));
	}
	friend istream& operator>>(istream& in, empleado& e){
	    cout<<"Dame el codigo: ";
	    in>>e.ClaveEmpleado;
	    return in;
	}
	friend ostream& operator<<(ostream& ot, empleado& e){
	    ot<<"Clave: "<<e.ClaveEmpleado<<endl;
	    ot<<"Nombre: "<<e.nombre<<endl;
	    ot<<"Domocilio: "<<e.domicilio<<endl;
	    ot<<"Sueldo: "<<e.sueldo<<endl;
	    ot<<"Reporta: "<<e.reporta<<endl;
	}

//metodos
	void imprime(){
        cout<<"Clave: "<<ClaveEmpleado<<endl;
        cout<<"Nombre: "<<nombre<<endl;
        cout<<"Domicilio: "<<domicilio<<endl;
        cout<<"Sueldo: "<<sueldo<<endl;
        cout<<"Reporta a: "<<reporta<<endl;

	}
	void CambiaDomic(string D){
		domicilio=D;
		cout<<"Se cambio Correctamente";
	}
	void ActualSuedo(float S){
        sueldo=S;
        cout<<"Se cambio correctamente";
	}
	void CambiaReporta(string N){
        reporta=N;
        cout<<"Se cambio correctamente";
	}
};

int main(){
	empleado JefePlanta(1234,"Juan","Calada Independencia",50000, "Luis"), JefePersonal(4321,"Carlos","Periferico Norte",100000, "Carmen"), Otro;

	string domi,Nnombre;
	int opc,code;
	float sueldo;

	do
	{
		cout<<"---Menu---"<<endl;
		cout<<"1.- Cambiar Domicilio."<<endl;
		cout<<"2.- Actualizar Sueldo."<<endl;
		cout<<"3.- Imprimir Empleado."<<endl;
		cout<<"4.- Cambiar Nombre."<<endl;
		cout<<"5.- Salir."<<endl;
		cout<<"Elige una opcion: ";
		cin>>opc;
		system("cls");


		switch(opc){
		case 1:
            cin>>Otro;
            cin.ignore();
            if(Otro==JefePersonal){
                cout<<"Dame el nuevo domocilio: ";
                getline(cin, domi);
                JefePersonal.CambiaDomic(domi);
            }
            if(Otro==JefePlanta){
                cout<<"Dame el nuevo domocilio: ";
                getline(cin, domi);
                JefePlanta.CambiaDomic(domi);
            }
			getch();
		    system("cls");
            break;

		case 2:
            cin>>Otro;
            if(Otro==JefePersonal){
                cout<<"Dame el nuevo sueldo: ";
                cin>>sueldo;
                JefePersonal.ActualSuedo(sueldo);
            }
            if(Otro==JefePlanta){
                cout<<"Dame el nuevo sueldo: ";
                cin>>sueldo;
                JefePlanta.ActualSuedo(sueldo);
            }
			getch();
		    system("cls");
            break;

		case 3:
		    cin>>Otro;
		    if (Otro==JefePlanta){
                cout<<JefePlanta;
		    }
		    if(Otro==JefePersonal){
                cout<<JefePersonal;
		    }
		    getch();
		    system("cls");
            break;

		case 4:
            cin>>Otro;
            cin.ignore();
            if(Otro==JefePersonal){
                cout<<"Dame el nuevo nombre del reportado: ";
                getline(cin, Nnombre);
                JefePersonal.CambiaReporta(Nnombre);
            }
            if(Otro==JefePlanta){
                cout<<"Dame el nuevo nombre del reportado: ";
                getline(cin, Nnombre);
                JefePlanta.CambiaReporta(Nnombre);
            }
			getch();
		    system("cls");
            break;

		case 5:
		    cout<<"Adios :)";
            break;
		}
	}while(opc!=5);

	}

