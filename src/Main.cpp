#include "Heap.hpp"
#include <iostream>

int main() {

    int tam, novo;

    std::cin >> tam;

    Heap heap(tam);

    for (int i = 0; i < tam; i++) {
        std::cin >> novo;
        heap.Inserir(novo);
    }

    std::cout << std::endl;

    for(int i = 0; i < tam; i++)
        std::cout << heap.Remover() << " ";

    heap.~Heap();
}