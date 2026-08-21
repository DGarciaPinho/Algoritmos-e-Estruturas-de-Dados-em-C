/* 1 Chave Hash -> 2 Função de Espalhamento ou função Hash -> 3 Tabela Hash 
 * 
 * Como tratar com colisões em Tabelas Hash : 
 * Tamanho da tabela deve (indicado) ser um número primo, usualmente T = 2 * n de dados = Primo mais proximo 
 * 
 * Fator de Carga 
 * FC = T/Primo 
 * Deve-se analisar quão proximo de 0.5 esse fator se encontra
 * FC proximo de 0 significa que pouco espaço está sendo usado
 * FC proximo de 1 significa uma busca pior dentro da tabela 
 *
 * Dentro de uma tabela Hash espaços vazios são necessarios para fazer uma busca eficiente
 *
 * Função de Espalhamento 
 *  Chave % Tamanho 
 * 
 * 
 */

#include <stdlib.h>
#include <stdbool.>

typedef struct {
    long long *table;
    int capacity;
    int size;
} HashSet;

HashSet* createSet(int capacity) {
    HashSet *set = (HashSet*)malloc(sizeof(HashSet));
    set->capacity = capacity;
    set->size = 0;
    set->table = (long long*)malloc(sizeof(long long) * capacity);
    for (int i = 0; i < capacity; i++) set->table[i] = LLONG_MIN; 
    return set;
}

int hashFunc(HashSet *set, long long key) {
    long long h = key % set->capacity;
    if (h < 0) h += set->capacity;
    return (int)h;
}

bool contains(HashSet *set, long long key) {
    int idx = hashFunc(set, key);
    while (set->table[idx] != LLONG_MIN) {
        if (set->table[idx] == key) return true;
        idx = (idx + 1) % set->capacity;
    }
    return false;
}

void insert(HashSet *set, long long key) {
    int idx = hashFunc(set, key);
    while (set->table[idx] != LLONG_MIN) {
        idx = (idx + 1) % set->capacity;
    }
    set->table[idx] = key;
    set->size++;
}

void removeKey(HashSet *set, long long key) {
    int idx = hashFunc(set, key);
    while (set->table[idx] != LLONG_MIN) {
        if (set->table[idx] == key) {
            set->table[idx] = LLONG_MIN;
            return;
        }
        idx = (idx + 1) % set->capacity;
    }
}
