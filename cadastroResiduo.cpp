#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include "cadastroResiduo.h"
#include "Residuo.h"


using namespace std;


void cadastroResiduo::create(Residuo &r){
    if (find(listaDeResiduos.begin(), listaDeResiduos.end(), &r) == listaDeResiduos.end()){
        listaDeResiduos.push_back(&r);
    } else {
        cout << "Residuo: " << r.getMaterial() << " ja Cadastrado" << endl;
    }
}//void

void cadastroResiduo::daleted(Residuo &r){

    if(find(listaDeResiduos.begin(), listaDeResiduos.end(), &r) != listaDeResiduos.end()){
        vector<Residuo*>::iterator it;
        for(it = listaDeResiduos.begin(); it != listaDeResiduos.end(); it++){
            if((*it)->getMaterial() == r.getMaterial()){
                delete *it;///libera a memoria alocada
                listaDeResiduos.erase(it);
                break;
            }//if
        }//for
    }//if
    else{
        cout <<"Residuo: " << r.getMaterial() << " nao cadastrado" << endl;
    }
}//void
void cadastroResiduo::listaDeResiduo(){
    vector<Residuo*>::iterator it;
    for(it = listaDeResiduos.begin(); it != listaDeResiduos.end(); ++it) {

        cout<< (*it)->getMaterial() <<endl;
    }//for
}//void

void cadastroResiduo::update(Residuo &r, string _descricao){
    if (find(listaDeResiduos.begin(), listaDeResiduos.end(), &r) != listaDeResiduos.end()){
        vector<Residuo*>::iterator it;
        for(it = listaDeResiduos.begin(); it != listaDeResiduos.end(); ++it) {
            if((*it)->getMaterial() == r.getMaterial()){
                (*it)->setDescricao(_descricao);
            }//if
        }//for
    }//if
    else{
        cout<<"Residuo: " << r.getMaterial() << " nao cadastrado" << endl;
    }
}//void


cadastroResiduo::~cadastroResiduo(){
    vector<Residuo*>::iterator it;
        for(it= listaDeResiduos.begin(); it != listaDeResiduos.end(); ++it) {
            delete *it;///libera a memoria alocada
        }//for
    listaDeResiduos.clear();
}//destrutor
string cadastroResiduo::getDescricao(string _material){
        vector<Residuo*>::iterator it;
        for(it = listaDeResiduos.begin(); it != listaDeResiduos.end(); it++){
            if((*it)->getMaterial() == _material){
                return (*it)->getDescricao();
            }//if
        }//for
}///string

