#include "InterfazTienda.h"

InterfazTienda::InterfazTienda(){
    sistemas = new Catalogo();
    ventas = new ListarGenerica<Venta>();
    manejo = new Archivos();
}

InterfazTienda::~InterfazTienda(){
    if (sistemas){delete sistemas;}
    if (ventas){delete ventas;}
}

void InterfazTienda::ingresarSistema(Sistema* sis){sistemas->ingresaSistema(sis);}//Llama al metodo ingresaSistema de la clase catalago y le pasa por paramentro un puntero a un objeto de tipo Sistema para ingresarlo al principio del catalogo.

void InterfazTienda::ingresarVentas(Venta* ven){ventas->insertarInicio(*ven);}//Llama al metodo insertarInicio de la ListaGenerica de ventas y le pasa por paramentro un puntero a un objeto de tipo venta para insertarlo al principio de la lista.

void InterfazTienda::ingresarSuscriptor(ClienteEnLinea* cli){sistemas->agregarSub(cli);}//Llama al metodo agregarSub de la clase catalago y le pasa por paramentro un puntero a un objeto de tipo ClienteEnLinea para luego ser ingresado en la lista generica del observer

void InterfazTienda::eliminarSistemaPos(int pos){sistemas->eliminarSistema(pos);}//Llama al metodo eliminarSistema de la clase catalago y le pasa por paramentro un entero(posicion del sistema que se desea eliminar) para luego buscar el sistema en la posicion del entero dado y eliminarlo

void InterfazTienda::eliminarSuscriptorPos(int pos){sistemas->eliminarSub(pos);}//Llama al metodo eliminarSub de la clase catalago y le pasa por paramentro un entero(posicion del suscriptor que se desea eliminar) para luego buscar el suscriptor en la posicion del entero dado y eliminarlo

void InterfazTienda::quitarSistemaPos(int pos){sistemas->quitarSistemaePos(pos);}//Llama al metodo quitarSistemaPos de la clase catalago y le pasa por paramentro un entero(posicion del sistema que se desea eliminar) para luego buscar el sistema en la posicion del entero dado y eliminarlo

Sistema* InterfazTienda::retornarSistemaPorPos(int pos){return sistemas->getsistemaPos(pos);}//Llama al metodo getsistemaPos de la clase catalago y le pasa por paramentro un entero(posicion del sistema que se desea devolver) para luego buscar el sistema en la posicion del entero dado y devolverlo

ClienteEnLinea* InterfazTienda::retornarClientePorCorreo(string corr){//Este método busca un ClienteEnLínea por su correo dentro de la lista generica y devuelve un puntero al objeto ClienteEnLinea correspondiente si se encuentra una coincidencia en caso contrario devuelve nullptr. 
    ClienteEnLinea* c = nullptr;
    for (int i = 1; i <= sistemas->getCanTotalSubs(); i++){
        c = dynamic_cast <ClienteEnLinea*>(sistemas->retornarSubPos(i));
        if (corr == c->getCorreo()){
            return c;
        }
    }
    return nullptr;
}

ClienteEnLinea* InterfazTienda::retornarClientePorCedula(string ced){//Este método busca un ClienteEnLínea por su cedula dentro de la lista generica y devuelve un puntero al objeto ClienteEnLinea correspondiente si se encuentra una coincidencia. 
    ClienteEnLinea* c = nullptr;
    for (int i = 1; i <= sistemas->getCanTotalSubs(); i++) {
        c = dynamic_cast <ClienteEnLinea*>(sistemas->retornarSubPos(i));
        if (ced == sistemas->retornarSubPos(i)->getCedula()) {
            c = sistemas->retornarSubPos(i);
            return c;
        }
    }
}

bool InterfazTienda::estaCedula(string ced, bool per){return sistemas->ExisteCedula(ced, per);}//Llama al metodo ExisteCedula de catalogo y le pasa por parametro un string y un bool y busca si la cedula(string) ya se encuentra registrada.Mientras que el bool lo utiliza para saber el tipo de cedula(Personal o juridica).

bool InterfazTienda::estaCorreo(string cor){return sistemas->ExisteCorreo(cor);}//Llama al metodo ExisteCorreo de catalogo y le pasa por parametro un string y busca si el correo(string) ya se encuentra registrada.

bool InterfazTienda::estaCodigo(string cod){return sistemas->ExisteCodigo(cod);}//Llama al metodo ExisteCodigo de catalogo y le pasa por parametro un string y busca si el codigo(string) ya se encuentra registrada.

int InterfazTienda::getCanTotalDeVentas(){return ventas->getK();}//Devuelve la cantidad de ventas totales de la tienda

int InterfazTienda::getCanTotalDeSistema(){return sistemas->getCanTotalSistemas();}//Devuelve la cantidad de sistemas registrados en la tienda

int InterfazTienda::getCanTotalDeClientes(){return sistemas->getCanTotalSubs();}//Devuelve la cantidad de suscriptores registrados en la tienda

int InterfazTienda::getCanTotalDeClientesEmpresa(){return sistemas->getCanTotalDeClientesEmpresa();}//Devuelve la cantidad de clientes de tipo empresa que existen en la tienda

int InterfazTienda::getCanTotalDeClientesFisicos(){return sistemas->getCanTotalDeClientesFisicos();}//Devuelve la cantidad de clientes de tipo persona que existen en la tienda

string InterfazTienda::codigoSistemaMasVendido(){//Devuelve el codigo del sistema que mas ventas tiene
    int cont = 0;
    int auxCont = 0;
    Sistema* aux = nullptr;
    Sistema* masVendido = nullptr;

    for (int i = 1; i <= ventas->getK(); i++){
        aux = ventas->retonarObjetoLugar(i)->getSistema();
        for (int x = 1; x <= ventas->getK(); x++){
            if (aux->getCodigo() == ventas->retonarObjetoLugar(x)->getSistema()->getCodigo()){
                cont++;
            }
        }
        if (cont > auxCont){
            auxCont = cont;
            masVendido = aux;
        }
    }
    return masVendido->getCodigo();
}

string InterfazTienda::ventasConGanancia(){//Devuelve la cantidad de ventas realizadas por la tienda y las ganancias que esta teniendo la tienda 
    stringstream s;
    VentasEmpresa& v = VentasEmpresa::instanciar();

    for (int i = 1; i <= ventas->getK(); i++){
        s << ventas->retonarObjetoLugar(i)->venta();
        s << "-------------------------------------" << endl << endl;
    }
    s << "********************************************" << endl;
    s << v.cantVentasGanancia();
    s << "********************************************" << endl;
    return s.str();
}

string InterfazTienda::listaClientes(){//Muestra la lista de suscriptores(Clientes en Linea)
    stringstream s;
    s << sistemas->mostrarSubs();
    return s.str();
}

string InterfazTienda::listaClientesFisicos(){//Muestra la lista de suscriptores(Clientes en Linea) de tipo persona
    stringstream s;
    ClienteEnLinea* c = nullptr;
    int cont = 0;

    s << "----> Lista de Clientes Persona <----" << endl << endl;

    for (int i = 1; i <= sistemas->getCanTotalSubs(); i++){
        c = dynamic_cast<Persona*>(sistemas->retornarSubPos(i));
        if (c){
            s << ++cont << "-" << c->toString(true);
            s << "-------------------------------------" << endl << endl;
        }
    }
    return s.str();
}

string InterfazTienda::listaClientesEmpresa()//Muestra la lista de suscriptores(Clientes en Linea) de tipo empresa
{
    stringstream s;
    ClienteEnLinea* c = nullptr;
    int cont = 0;
    s << "----> Lista de Clientes Empresa <----" << endl << endl;
    for (int i = 1; i <= sistemas->getCanTotalSubs(); i++){
        c = dynamic_cast<Empresa*>(sistemas->retornarSubPos(i));
        if (c){
            s << ++cont << "-" << c->toString(true);
            s << "-------------------------------------" << endl << endl;
        }
    }
    return s.str();
}

string InterfazTienda::mostrarStock(){return sistemas->mostrarCatalogo();}

string InterfazTienda::mostrarSuscriptores(){return sistemas->mostrarSubs();}

string InterfazTienda::mostrarHistorialDeVentas(){//Devuelve todas las facturas emitas por la tienda
    stringstream s;
    for (int i = 1; i <= ventas->getK(); i++){
        s << "Factura# " << i << "\n" << ventas->retonarObjetoLugar(i)->venta();
        s << "-------------------------------------" << endl << endl;
    }
    return s.str();
}

string InterfazTienda::toString(){
    stringstream s;
    s << "\tCatalogo:" << endl << endl
        << sistemas->mostrarCatalogo() << endl;
    s << "\tClientes:" << endl << endl
        << sistemas->mostrarSubs() << endl;
    s << "\tVentas:" << endl << endl
        << mostrarHistorialDeVentas() << endl;
    return s.str();
}

void InterfazTienda::recuperarDatosAplicacion(){//Se encargar de todo el proceso de recuperacion de datos almacenados en el archivo
    manejo->abrirFlujoModoLectura();
    manejo->recuperarDatosSingleton();
    sistemas->setSuscriptores(manejo->recuperarClientesLinea()); 
    sistemas->setCatalogo(manejo->recuperarSistemas());
    ventas = manejo->recuperarVentas();
    manejo->cerrarFlujo();
}

void InterfazTienda::guardarDatosAplicacion(){//Se encarga de almacenar todo los datos en el archivo
    manejo->abrirFlujoModoEscritura();
    manejo->guardarDatosSingleton();
    manejo->guardarClientesEnLinea(sistemas->getSuscriptores());
    manejo->guardarSistemas(sistemas->getCatalogo());
    manejo->guardarVentas(ventas);
    manejo->cerrarFlujo();
}