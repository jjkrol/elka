/** 
@file asd.cc

Plik do modyfikacji w ramach cwiczenia z AISDI.
Zawiera niekompletne implementacje metod klasy ListMap,
oraz mape podobna koncepcyjnie do tej z cwicznia 1 (SmallMap)
zaimplementowana w jescze bardziej szczatkowy sposob.
Jest tez prosta funkcja testujaca (void test()), ktora
jest wolana w funkcji main. Mozna w niej zaimplementowac
wlasne testy.
NALEZY ZMODYFIKOWAC I UZUPELNIC CIALA METOD KLASY LISTMAP.
    
@author
Pawel Cichocki, Michal Nowacki

@date  
last revision
- 2006.01.06 Michal Nowacki: wersja polska
- 2005.11.17 Michal Nowacki: constructor
- 2005.11.04 Pawel Cichocki: copied comments from the header
- 2005.11.03 Pawel Cichocki: const_iterator done properly now
- 2005.10.27 Pawel Cichocki: cosmetic changes
- 2005.10.26 Michal Nowacki: removed some method bodies
- 2005.10.25 Pawel Cichocki: wrote it

COPYRIGHT:
Copyright (c) 2005 Instytut Informatyki, Politechnika Warszawska
ALL RIGHTS RESERVED
*******************************************************************************/

#include <assert.h>
#include <algorithm>

#include <iostream>

#ifdef _SUNOS
#include "/home/common/dyd/aisdi/liniowe/ListMap.h" 
#else
#include "ListMap.h"
#endif

//////////////////////////////////////////////////////////////////////////////
// ListMap and ListMap::iterator methods
//////////////////////////////////////////////////////////////////////////////

ListMap::ListMap()
{
   first = new Node(std::make_pair(0,""));//straznik
   first->next=first->prev=first;//wskazuje na siebie
};

ListMap::ListMap( const ListMap& m )
{
   ///@todo Zaimplementowa� metode
	first = new Node(std::make_pair(0,""));//straznik 
	first->next=first->prev=first; //wskazuje na siebie
	Node* i = m.first->next;
	while(i!=m.first){//wstaw dane
		insert(i->data);
		i=i->next; 
	}
};

ListMap::~ListMap()
{
   clear();
   delete first;
};

// Wstawienie elementu do mapy.
// @returns Para, kt�rej komponent bool jest r�wny true gdy wstawienie zosta�o
//          dokonane, r�wny false gdy element identyfikowany przez klucz
//          ju� istnia� w mapie. Iterator ustawiony jest na ten wstawiony 
//          lub istniej�cy ju� w mapie element.
std::pair<ListMap::iterator, bool> ListMap::insert(const std::pair<Key, Val>& entry)
{
   ///@todo Uzupe�ni� kod
	//std::cout<<"wstawiam "<<entry.first<<" "<<entry.second<<std::endl;
	ListMap::iterator i;
	for(i=begin(); i!=end();i++){//przejdz po liscie
		if(i->first==entry.first)//znajdz taki sam klucz
			return std::make_pair(i, (bool) false);//zwroc
	}
	return std::make_pair(unsafe_insert(entry), (bool)true);//udalo sie
}

// Wstawienie elementu do mapy.
// Matoda zak�ada, �e w mapie nie wyst�puje element identyfikowany przez key
ListMap::iterator ListMap::unsafe_insert(const std::pair<Key, Val>& entry)
{
	Node* wstawiany = new Node(entry);
	if (empty()){ //jesli lista pusta
		first->prev=first->next = wstawiany; //wstaw i polacz oba konce ze straznikiem
		wstawiany->prev = first;//doczep poczatek do straznika
	}
	else{
		first->prev->next = wstawiany; //doczep do przedostatniego (w przod)
		wstawiany->prev = first->prev;//doczep do przedostatniego (w tyl)
		first->prev = wstawiany;//doczep do straznika (w tyl)
	}
	wstawiany->next = first; //doczep do straznika (w przod)

/*	ListMap::const_iterator k;
std::cout<<"Wypisywanie listy:"<<std::endl;
for(k=begin();k!=end();k++){
std::cout<<"Sytuacja: "<<k.node->prev->data.first<<"->"<<k->first<<"->"<<k.node->next->data.first<<std::endl;
}*/
   ///@todo Uzupe�ni� kod
   //assert(0);
   return iterator(wstawiany);
}

// Zwraca iterator addresuj�cy element w mapie dla kt�rego klucz jest r�wny 
// szukanemu kluczowi lub element za ostatnim gdy szukanego klucza brak w mapie.
ListMap::iterator ListMap::find(const Key& k)
{
   ///@todo Zaimplementowa� metode
   //assert(0);
	ListMap::iterator i;
	for(i=begin(); i!=end();i++){//przejdz po liscie
		if(i->first==k)//znajdz szukany klucz
			return i;//zwroc na niego iterator
	}
	return iterator(first);//guard
}

ListMap::const_iterator ListMap::find(const Key& k) const
{
   ///@todo Zaimplementowa� metode
	for(Node* i=first->next; i!=first;i=i->next){//przejdz po liscie 
		if(i->data.first==k)//znajdz szukany klucz
			return iterator(i);//zwroc na niego iterator
	}
	return iterator(first);
}

// Udost�pnia warto�� powi�zan� z kluczem key. Wstawia element do mapy je�li 
// nie istnia�.
// @returns Referencje do warto�ci powi�zanej z kluczem.
ListMap::Val& ListMap::operator[](const Key& k)
{
   ///@todo Zaimplementowa� metode
   //assert(0);
	ListMap::iterator j = find(k);
	if(j==iterator(first))//jesli nie ma takiego klucza
		return (insert(std::pair<Key, Val>(k,"")).first)->second;   //wstaw i zwroc referencje na wartosc
return j->second;//jesli jest, zwroc referencje na wartosc
}

// Sprawdzenie czy mapa jest pusta.
bool ListMap::empty( ) const
{
   return ((first->next==first)&&(first->prev==first)); //jesli jest tylko straznik
}

// Zwraca ilo�� element�w w mapie.
ListMap::size_type ListMap::size( ) const
{
   ///@todo Zaimplementowa� metode
   //assert(0);
int j=0; //licznik elementow
for(Node* i=first->next; i!=first;i=i->next){//przejdz po liscie 
	j++; //zwieksz j
}
   return j;
}

// Zwraza ilo�� element�w skojarzonych z kluczem key.
ListMap::size_type ListMap::count(const Key& _Key) const
{
   ///@todo Zaimplementowa� metode
	ListMap::const_iterator i = find(_Key); //znajdz klucz
		if(i == end()) //jesli go nie ma
			return 0; //to nic nie jest z nim powiazane
   return 1;  // this is not a multimap
}

// Usuwa element z mapy.
// @returns iterator adresuj�cy pierwszy element za usuwanym.
ListMap::iterator ListMap::erase(ListMap::iterator i)
{
	
/*ListMap::const_iterator k;
std::cout<<"Wypisywanie listy:"<<std::endl;
for(k=begin();k!=end();k++){
std::cout<<"Sytuacja: "<<k.node->prev->data.first<<"->"<<k->first<<"->"<<k.node->next->data.first<<std::endl;
}*/
   ///@todo Uzupe�ni� kod
   ///@todo Zaimplementowa� metode
   //assert(0);
if(i.node==first)return ListMap::iterator(first); //puste/straznik
Node* nastepny = i.node->next;
Node* poprzedni = i.node->prev;
delete i.node;
//if(nastepny != first) //jesli to nie byl ostatni element
	nastepny->prev = poprzedni; //polacz liste
//if (poprzedni !=first)//jesli to nie byl pierwszy
	poprzedni->next=nastepny; //polacz liste
//else {//jesli byl pierwszy
//	first->next = nastepny;
//	nastepny->prev = first;
//}
return ListMap::iterator(nastepny);//zwroc iterator na nastepny element
}

// Usuwa zakres element�w z mapy.
// Zakres jest zdefiniowany poprzez iteratory first i last
// first jest okre�la pierwszy element do usuni�cia, a last okre�la element 
// po ostatnim usuni�tym elemencie.
// @returns iterator adresuj�cy pierwszy element za usuwanym.
ListMap::iterator ListMap::erase(ListMap::iterator f, ListMap::iterator l)
{
   ///@todo Zaimplementowa� metode
   //assert(0);
	while(f!=l && f.node!=first){//poki sie nie zrownaja i poki sa elementy
//std::cout<<"Usuwam "<<f.node->data.first<<" "<<f.node->data.second<<std::endl;
	f = erase(f); // usuwaj i idz do przodu
	}
return l;//zwroc ostatni
}

// Usuwa element z mapy.
// @returns Ilo�� usuni�tych element�w.
//          (nie jest to multimapa, wi�� mo�e by� to warto�� 1 lub 0 )
ListMap::size_type ListMap::erase(const Key& key)
{
   ///@todo Zaimplementowa� metode
	ListMap::iterator i= find(key);//znajdz element o takim kluczu
	if(i != erase(i))//jesli nie staralismy sie usunac straznika i jesli sie udalo
		return 1;
	else
		return 0;
}

// Usuni�cie wszystkich element�w z mapy.
void ListMap::clear( )
{
   ///@todo Zaimplementowa� metode
   //assert(0);
	erase(begin(),end());
}

// Por�wnanie strukturalne map.
// Czy reprezentacja danych jest identyczna.
// Zwraca true je�li wewn�trzne struktury map s� identyczne.
bool ListMap::struct_eq(const ListMap& another) const
{
   ///@todo Zaimplementowa� metode
   //assert(0);
if(size()==another.size()){ //musza miec taka sama wielkosc
Node* tu = first->next;//element naszej listy
Node* tam = another.first->next;//element drugiej listy
while(tu!=first && tam!=another.first){//przejdz przez liste
if(tu->data.first == tam->data.first){//jesli takie same klucze to ok
	tu=tu->next;//idz dalej
	tam=tam->next;
	}
else{
	return false;//jesli sie roznia, to zle
}
}
if(tu==first || tam == another.first)//jesli doszlo do konca
		return true;//to takie same
}
   return false;
}

// Por�wnanie informacyjne map.
// Czy informacje trzymane w mapach s� identyczne.
// Zwraca true je�li mapy zwieraj� takie same pary klucz-warto��.
bool ListMap::info_eq(const ListMap& another) const
{
   ///@todo Zaimplementowa� metode
   //assert(0);
if(size()!=another.size()) return false; //rozny rozmiar, rozne dane
ListMap::const_iterator i,j;
for(i=begin();i!=end();i++){//przejdz po liscie
	j=another.find(i->first);//znajdz wartosc klucza w innej liscie
	if(j->second!=i->second)//porownaj z ta
		return false;
}
return true;
}


// preincrementacja
ListMap::const_iterator& ListMap::const_iterator::operator++()
{
   ///@todo Zaimplementowa� metode
	if(node)//je�li jest na co
		node=node->next; //incrementuj
   return *this;
}

// postincrementacja
ListMap::const_iterator ListMap::const_iterator::operator++(int)
{
   ///@todo Zaimplementowa� metode
	ListMap::const_iterator temp = *this;//zapamietaj
	if(node)//jesli jest na co
		node=node->next; //inkrementuj
   return temp;
}

ListMap::const_iterator& ListMap::const_iterator::operator--()
{
   ///@todo Zaimplementowa� metode
	if(node) //jesli jest na co
		node=node->prev; //dekrementuj
   return *this;
}

// postincrementacja
ListMap::const_iterator ListMap::const_iterator::operator--(int)
{
   ///@todo Zaimplementowa� metode
	ListMap::const_iterator temp = *this; //zapamietaj
	if(node)//jesli jest na co
		node=node->prev;//dekrementuj
   return temp; 
}

/// Zwraca iterator addresuj�cy pierwszy element w mapie.
ListMap::iterator ListMap::begin()
{ 
   ///@todo Zaimplementowa� metode
   return iterator(first->next); //zwraca iterator na pierwszy element (nastepny po strazniku
}

/// Zwraca iterator addresuj�cy pierwszy element w mapie.
ListMap::const_iterator ListMap::begin() const
{ 
   ///@todo Zaimplementowa� metode
   return iterator(first->next);//zwraca iter na pierwszy element (nastepny po strazniku)
}

/// Zwraca iterator addresuj�cy element za ostatnim w mapie.   
ListMap::iterator ListMap::end()
{ 
   ///@todo Zaimplementowa� metode
   return iterator(first);//straznik jest na koncu
}

/// Zwraca iterator addresuj�cy element za ostatnim w mapie.   
ListMap::const_iterator ListMap::end() const
{ 
   ///@todo Zaimplementowa� metode
   return iterator(first);//straznik jest na koncu
}

//////////////////////////////////////////////////////////////////////////////
// SmallMap
//////////////////////////////////////////////////////////////////////////////

/// Przyk�ad map'y z implementacj� podobn� do std::map.
/// To jest jedynie przyk�ad!!!
/// Normalnie implementacja powinna opiera� si� o drzewo lub tablic� haszuj�c�.
template <class Key, class Val>
class SmallMap
{
   std::pair<Key, Val> tab[2];
   int isOcupied[2];
public:

   SmallMap()
   {
      for(unsigned i=0; i<2; ++i)
      {
         isOcupied[i]=0;
      }
   }

   typedef std::pair<Key, Val>* iterator;   ///< Ka�dy wska�nik jest te� iteratorem.

   iterator begin() { return tab; }
   iterator end() { return tab+2; }

   Val& operator[](const Key& k)
   {
      static Val val;
      for(unsigned i=0; i<2; ++i)
      {
         if(isOcupied[i]&&tab[i].first==k)
            return tab[i].second;
      }
      // create
      for(unsigned i=0; i<2; ++i)
      {
         if(!isOcupied[i])
         {
            tab[i].first=k;
            isOcupied[i]=1;
            return tab[i].second;
         }
      }
      //std::cout<<"Out of space! You should not put more than two Key-Value pairs into the SmallMap.\n";
      std::cerr<<"Out of space! You should not put more than two Key-Value pairs into the SmallMap.\n";
      //assert(0);
      return val;   // Ma�o sensowne, ale to jest tylko przyk��d
   }
};
      

//////////////////////////////////////////////////////////////////////////////
// Testy
//////////////////////////////////////////////////////////////////////////////

/// Funckcja pomocnicza do wypisania element�w.
void print(const std::pair<int, std::string>& p)
{
   std::cout<<p.first<<", "<<p.second<<std::endl;
}

#include <map>

/// Testy u�ytkownika
void test()
{
   // A typedef used by the test.
   //typedef std::map<int, std::string> TEST_MAP;
   //typedef SmallMap<int, std::string> TEST_MAP;
   typedef ListMap TEST_MAP;

   std::cout << "Testy uzytkownika" << std::endl;

        TEST_MAP m;  
     ListMap::const_iterator k; 

   
/* wypisywanie */
/*std::cout<<"Wypisywanie listy:"<<std::endl;
for(k=m.begin();k!=m.end();k++){
   std::cout<<"Wypisuje: "<<k->first<<" "<<k->second<<std::endl;
}*/
/*   m[2] = "Merry";
   m[4] = "Jane";
   m[8] = "Korwin";
   m[4] = "Magdalena";

   for_each(m.begin(), m.end(), print );*/
   //system("PAUSE");
}

//////////////////////////////////////////////////////////////////////////////
// main - jest w pliku /home/common/dyd/aisdi/z2/main.cc
//////////////////////////////////////////////////////////////////////////////

//int main()
//{
//   std::cout << "AISDI cwiczenie 2: wchodze do funkcji main." << std::endl;
//   test();
//   // Biblioteka z bardziej rygorystyczna wersja tych testow bedzie udostepniona na nastepnych zajeciach.
//   Test2();
//   //system("PAUSE");
//   return EXIT_SUCCESS;
//}
