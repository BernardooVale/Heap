#include "Heap.hpp"
#include <algorithm> // para std::swap
#include <iostream>

// Construtor que inicializa o heap com um tamanho máximo e configura o tamanho atual como zero
Heap::Heap(int tam) : tamanho(0) {
    data = new int[tam];
}

// Destrutor que libera a memória alocada para o heap
Heap::~Heap() {}

// Função para verificar se o heap está vazio
bool Heap::Vazio() {
    return this->tamanho == 0 ? true : false;
}

// Função para inserir um novo elemento no heap
void Heap::Inserir(int x) {
    
    if (this->Vazio()){

        this->data[this->tamanho] = x;
    }
    else{

        this->data[this->tamanho] = x;
        HeapifyPorBaixo(this->tamanho);
    }

    this->tamanho++;
}

// Função para remover e retornar o menor elemento do heap 
int Heap::Remover() {
    
    int retorno = this->data[0];
    this->data[0] = this->data[--tamanho];

    this->HeapifyPorCima(0);

    return retorno;
}

// Função para obter o índice do ancestral de um nó
int Heap::GetAncestral(int posicao) {
    return (posicao - 1) / 2;
}

// Função para obter o índice do sucessor esquerdo de um nó
int Heap::GetSucessorEsq(int posicao) {
    return (2 * posicao) + 1;
}

// Função para obter o índice do sucessor direito de um nó
int Heap::GetSucessorDir(int posicao) {
    return (2 * posicao) + 2;
}

// Função para manter a propriedade de min-heap "por baixo"
void Heap::HeapifyPorBaixo(int posicao) {

    int id_ancestral = this->GetAncestral(posicao);

    if (this->data[posicao] < this->data[id_ancestral]) {
        std::swap(this->data[posicao], this->data[id_ancestral]);
        if(id_ancestral != 0){
            this->HeapifyPorBaixo(id_ancestral);
        }
    }
}

// Função para manter a propriedade de min-heap "por cima"
void Heap::HeapifyPorCima(int posicao) {
    
    int id_e = this->GetSucessorEsq(posicao), id_d = this->GetSucessorDir(posicao);

    // se ambos existem
    if(id_e <= tamanho && id_d <= tamanho){

        //se o do meio e menor
        if (this->data[posicao] <= this->data[id_e] && this->data[posicao] <= this->data[id_d]) return;
        //se o da dir e menor
        if (this->data[id_d] < this->data[id_e]) {
            std::swap(this->data[posicao], this->data[id_d]);
            this->HeapifyPorCima(id_d);
            return;
        }
        //se o da esq e menor
        std::swap(this->data[posicao], this->data[id_e]);
        this->HeapifyPorCima(id_e);
        return;
    }

    // se so da esquerda existir
    if (id_e <= tamanho) {

        //se o do meio e menor
        if (this->data[posicao] <= this->data[id_e]) return;
        //se o da esq e menor
        std::swap(this->data[posicao], this->data[id_e]);
        this->HeapifyPorCima(id_e);
    }

    //se so da direita existir
    if (id_d <= tamanho) {

        //se o do meio e menor
        if (this->data[posicao] <= this->data[id_d]) return;
        //se o da esq e menor
        std::swap(this->data[posicao], this->data[id_d]);
        this->HeapifyPorCima(id_d);
    }

    //se nenhum existir
    return;
}