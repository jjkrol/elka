/** 
@file aisdihashmap.h

AISDIHashMap and related functions interface.
      
@author
Pawel Cichocki

@date  
last revision
- 2006.03.24 Pawel Cichocki: wrote it

COPYRIGHT:
Copyright (c) 2006 Instytut Informatyki, Politechnika Warszawska
ALL RIGHTS RESERVED
*******************************************************************************/

#include <utility>
#include <iostream>

#define SIZE 64000

//element trzymany w liscie, pod jednym hashem
template<class K, class V>
class Node { 
public:
	std::pair<K, V> data; //dane trzymane w elemencie
	Node<K, V> *next; //wskazniki na sasidnie elementy
	Node<K, V> *prev; // listy dwukierunkowej

	//konstruktory
	Node(const std::pair<K, V>& d) : next(NULL), prev(NULL), data(d){} 
	Node(const std::pair<K, V>& d, Node<K, V>* p, Node<K,V>* n): next(n), prev(p), data(d){}
};


template <class Key>   
inline int _compFunc(const Key& key1,const Key& key2)
{
   return (key1==key2);
};

template <class K> unsigned hashF(const K& key){
	unsigned hash = 1500100900, i=0;
	while (key[i]!='\0') hash = hash ^ ((hash<<3) ^ (hash >> 8)) ^ key[i++];
	return (hash%SIZE);
}

/// A map with a similar interface to std::map.
template<class K, class V,
         unsigned hashFunc(const K&),
         int compFunc(const K&,const K&)=&_compFunc<K> >
class AISDIHashMap
{
protected:

// klasa listy, ktora bedzie w kazdym elemencie tablicy
// w niej trzymane beda dane w klasie Node	
class List{
	public:
	Node<K, V> *first; //pierwszy element listy, "straznik"

	List() : first(NULL){
		//tworzenie pierwszego elementu o indeksie -1 (przed reszta)
		first = new Node<K,V>(std::make_pair(K(),V()),NULL,NULL);
	}

	List(const List& l){ 
	Node<K,V> *mn = l.first; //skopiuj pierwszy element
	first = new Node<K,V>(mn->data, NULL, NULL); //stworz go
	Node<K,V> *prev = first; //zapamietaj poprzedni element;
	mn = mn->next;
	while(mn!=NULL){ //iteruj
		//stworz nowe elementy takie jak w drugiej liscie
		Node<K,V> *new_node = new Node<K,V>(mn->data, prev, NULL);
		prev->next = new_node; //podlacz do poprzedniego
		prev = prev->next; // podlacz poprzedni
		mn = mn->next; // nastepny
	}
	}

	~List(){
		clear();
	}

	std::pair<Node<K,V>*, bool> insert(const std::pair<K, V>& entry){
	if (first->next==NULL){ //jesli lista pusta
		first->next = new Node<K,V>(entry, NULL, NULL); //stworz nowy
		first->next->prev = first; // doczep do straznika
		return std::make_pair(first->next, true); // zwroc
	}

	Node<K,V> *new_node; // nowy element
	Node<K,V> *mn = first; // zapamietaj pierwszy

	while(mn->next !=NULL && (mn->data).first < entry.first){
		//dojdz do ostatniego elementu o mniejszym kluczu niz wstawiany
		mn=mn->next;
	}
	if((mn->data).first == entry.first) return std::make_pair(mn, false); //jesli juz istnieje
	if((mn->data).first < entry.first){ //jesli wstawiamy jako ostatni
		new_node = new Node<K,V>(entry, mn, NULL); //stworz
		mn->next = new_node; // doczep
	}
	else{ //jesli gdzies w srodku
		new_node = new Node<K,V>(entry, mn->prev, mn); // stworz
		mn->prev->next = new_node; // doczep z przodu
		mn->prev = new_node; // doczep z tylu
	}
	return std::make_pair(new_node, true); // zwroc wstawiony element
	}

	Node<K,V>* find(const K& key){
		if(first->next==NULL) return NULL; // pusta lista
		Node<K,V> *mn = first->next; // "iterator" 
		while(mn->next!=NULL && (mn->data).first!=key) {
			//szukaj klucza
			mn=mn->next;
		} 
		if((mn->data).first == key && mn!=first) return mn; // jesli sie udalo, zwroc
		return NULL; // jesli nie, to zwroc NULL
	}
	
	Node<K,V>* erase(Node<K,V> *node){
		if(node==NULL) return NULL; // przy pustej liscie nie ma czego usuwac
		Node<K,V> *mn = first->next; // zacznij szukac od pierwszego
		while(mn!=NULL && mn != node){ // szukaj
			mn=mn->next;
		}
		if(mn==NULL) return NULL; // jesli nie znalazl
		Node<K,V> *retnode = mn->next; // zapamietaj nastepny do zwrocenia
		Node<K,V> *prev = mn->prev; // poprzedni, zeby dowiazac
		prev->next = retnode; // dowiaz z tylu
		if(retnode!=NULL) retnode->prev = prev; // dowiaz z przodu, jesli nie koniec
		delete mn; // usun
		if(retnode!=NULL) return retnode; //jesli to nie koniec, zwroc element z porzdu
		return prev; // jesli jednak koniec, to zwroc element przed usunietym (ostatni)
	}

	int erase(const K& key){
		Node<K,V> *mn = find(key); //znajdz element o takim kluczu
		if(mn!=NULL) erase(mn); // jesli sie udalo, usun
		else return 0;
		return 1;
	}

	void clear(){ 
		Node<K,V> *next;
	       	Node<K,V> *curr = first->next; // zacznij od pierwszego
		while(curr!=NULL){ //jesli nie jest pusty
			next = curr->next; // wez nastepny
			delete curr; // ten skasuj
			}
		delete first; // usun straznika
	}

	unsigned size(){
		Node<K,V> *mn = first->next; // zacznij od pierwszego
		unsigned ret_val = 0; // licznik
		while(mn!=NULL) {++ret_val; mn=mn->next;} // idz po liscie i zwiekszaj licznik
		return ret_val; // zwroc licznik
	}

	bool empty(){ return first->next==NULL; } // jesli za straznikiem nikogo nie ma, lista jest pusta

	Node<K,V> *begin(){ return first; } // straznik

} arr[SIZE+1];

public:
   typedef K key_type;
   typedef V value_type;
   typedef unsigned size_type;
   AISDIHashMap(){
   }

   ~AISDIHashMap(){
   	clear();
   }

   explicit AISDIHashMap(const AISDIHashMap<K, V, hashFunc, compFunc>& a){
	for(int i=0; i<SIZE; i++) arr[i]=a.arr[i];
   }

   class const_iterator : public std::iterator<std::forward_iterator_tag, std::pair<K, V> >{
protected:
friend class AISDIHashMap;

Node<K, V>* node; // wskazywany element
int index; // indeks elementu
List *arr; // tablica list

const_iterator(Node<K,V>* n, int i, List *l) : node(n), index(i), arr(l) {}

public:

const_iterator(): node(NULL), index(-1), arr(NULL) {}
const_iterator(const const_iterator& it) : node(it.node), index(it.index), arr(it.arr) {}

// operatory inkementacji i dekrementacji
inline const_iterator& operator++(){
	if(node->next!=NULL){ // je?li sa elementy dalej na liscie, wez nastepny
		node = node->next;
		return *this;
	}
	++index; // jesli nie, to sprawdz nastepna liste
	while(index<=SIZE && arr[index].begin()->next==NULL) index++; // szukaj niepustej listy
	if(index>SIZE){ // jesli doszedles do konce
		index = SIZE;
		node = arr[SIZE].begin();
		return *this; //zwroc siebie pokazujac na koniec
	}
	node = arr[index].begin()->next; // jesli nie, to pokazuj na znaleziony element
	return *this;
}

inline const_iterator operator++(int) {return ++(*this);}

// operator por?wnania
inline bool operator<(const const_iterator& a) const{
	if(index<a.index || node->data.first < a.node->data.first) return true;
	return false;
	}	
inline bool operator==(const const_iterator& a) const { return node==a.node;}
inline bool operator!=(const const_iterator& a) const { return node!=a.node;}
// operatory dostepu do danych
inline const std::pair<K,V>* operator->() const{
	return &(node->data);
}	

const std::pair<K, V>& operator*() const{
	return node->data;
	}
   };

   class iterator : public const_iterator{
protected:
	friend class AISDIHashMap;
	iterator(Node<K,V> *n, int i, List* l):const_iterator(n, i, l){}
public:
	//konstruktory
	iterator() {}
	iterator(const const_iterator& a) : const_iterator(a) {}
	iterator(const iterator& a) { const_iterator::node = a.node; this->index = a.index; this->arr = a.arr;}


	//inkrementacja i dekrementacja
	iterator operator++(int){
		iterator temp = *this;
		++*this;
		return temp;
	}
	iterator& operator++(){
		++(*(const_iterator*)this);
		return (*this);
	}

	//operatory dostepu do danych
	std::pair<K,V>& operator*() { return this->node->data; }
	inline std::pair<K,V>* operator->() const {return &(this->node->data); }

   };

   inline iterator begin(){
	for(int i = 0; i<SIZE;i++){
	if(arr[i].begin()->next!=NULL) return iterator(arr[i].begin()->next, i, arr);
	}
	return end();
   }
   inline const_iterator begin() const {
	for(int i = 0; i<SIZE;i++){
	if(arr[i].begin()->next!=NULL) return const_iterator(arr[i].begin()->next, i, arr);
	}
	return end();
   }

inline iterator end() { return iterator(arr[SIZE].begin(), SIZE, arr); }
inline const_iterator end() const { return const_iterator(arr[SIZE].begin(), SIZE, arr); }

   std::pair<iterator, bool> insert(const std::pair<K, V>& entry){
	   int index = hashFunc(entry.first); // oblicz indeks
	   std::pair<Node<K,V>*, bool> pair = arr[index].insert(entry); // wstaw do listy pod danym indeksem
	   return std::make_pair(iterator(pair.first, index, arr), pair.second); // zwroc iterator i czy sie powiodlo
   }

   iterator find(const K& k){
	Node<K,V> *mn = arr[hashFunc(k)].find(k); // oblicz indeks
	if(mn == NULL){ // jesli nic tam nie ma
		return this->end(); // zwroc koniec
	}
	return iterator(mn, hashFunc(k), arr); // jesli jest, to zwroc iterator
   }

   const_iterator find(const K& k) const { 
	Node<K,V> *mn = arr[hashFunc(k)].find(k); // oblicz indeks
	if(mn==NULL){ // jesli nie ma
		return this->end(); // zwroc koniec
	}
	return const_iterator(mn, hashFunc(k), arr); // jesli jest, zwroc iterator
   }

   V& operator[](const K& k)   {
	int index = hashFunc(k); // oblicz indeks
	Node<K,V>* mn = arr[index].insert(std::make_pair(k, V())).first; //wstaw stworzona pare
	return mn->data.second; // zwroc nowy jesli nie bylo, albo istniejacy, jesli byl
   }

   bool empty() const {
	   for (int i = 0; i < SIZE; i++){ // przejdz cala mape
		if(!arr[i].empty()) return false; // jesli jeden jest niepusty, cala mapa tez
	   }
	   return true;
   }

   size_type size() {
	int ret_value = 0;
	for(int i = 0; i < SIZE; i++){ // przejdz cala mape
		ret_value += arr[i].size(); // i zsumuj wielkosci list
	}
	return ret_value;
   }

   size_type count(const K& _Key) const { // to nie jest multimapa, wiec jesli znajdzie, to jest jeden, jesli nie, to zero
	   return (arr[hashFunc(_Key)].find(_Key) != NULL); 
   }

   iterator erase(iterator i){
	   if(i.node==arr[i.index].begin()) return end(); // nie usuwamy straznika
	   int index = i.index; 
	   K key = i->first;
	   //usun element
	   Node<K,V>* mn = arr[index].erase(i.node);
	   // jesli nei znalazl 
	   if(mn==NULL) return this->end();
	   //jesli bylo cos jeszcze w tej liscie, zwroc iterator na to 
	   if(mn->data.first > key) return iterator(mn, index, arr);
	   // jesli nie, poszukaj nastepnego elementu
	   while(arr[++index].begin()->next==NULL && index!=SIZE);
	   mn = arr[index].begin()->next;
	   // i zwroc na niego iterator
	   return iterator(mn, index, arr);
   }

   iterator erase(iterator first, iterator last){
	   if(first==end() || !(first < last)) return end(); // jesli zakres = 0, lub bledne dane, zwroc koniec
	   iterator i = first;
	   while(i!=last){ // usun wszystko z zakresu
		   erase(i);
		   //arr[i.index].erase(i.node);
		   i++;
	   }
	   return last;
   }
   
   size_type erase(const K& key){
	   return arr[hashFunc(key)].erase(key);
   }

   void clear(){
	   erase(begin(), end());
   }


};
