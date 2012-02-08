/** 
  @file asd.cc

  Plik do modyfikacji w w ramach cwiczenia 4 z AISDI.
  Zawiera niekompletne implementacje metod klasy TreeMap.
  Jest tez prosta funkcja testujaca (void test()), ktora
  jest wolana w funkcji main. Mozna w niej zaimplementowac
  wlasne testy.
  NALEZY ZMODYFIKOWAC I UZUPELNIC CIALA METOD KLASY TreeMap.

  @author
  Pawel Cichocki, Michal Nowacki

  @date  
  last revision
  - 2005.12.01 Pawel Cichocki: TreeNodeDetail class
  - 2005.12.01 Michal Nowacki: lab #4
  - 2005.11.17 Michal Nowacki: lab #3, copy operator and constructor
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
#include "/home/common/dyd/aisdi/tree/TreeMap.h" 
#else
#include "TreeMap.h"
#endif

/// A helper class.
class TreeMapDetail //Helper
{
	public:
		TreeNode * afterLast;
		static void print(TreeMap* tm){
			std::cout<<"Root:"<<tm->root<<std::endl;
			if(tm->root == NULL) return;
			TreeMapDetail::printNode(tm->root,"|","");
		}

		static void print(const TreeMap* tm){
			std::cout<<"Root:"<<tm->root<<std::endl;
			if(tm->root == NULL) return;
			TreeMapDetail::printNode(tm->root,"|","");
		}

		static void printNode(TreeNode * node, std::string path, std::string leftright){
			std::cout<<path<<leftright<<" "<<node->data.first\
				<<":"<<node->data.second<<" "<<node<<std::endl;
			if (node->right) {
				printNode(node->right,"\t"+path,"(r)");
			}
			if (node->left) {
				printNode(node->left, "\t"+path,"(l)");
			}
		}

		void copyTreeMap(TreeMap& target, const TreeMap& source){
			TreeNode * nodePointer = source.root;
			if(nodePointer)
				copyBranch(target, nodePointer);
			return;
		}

		void copyBranch(TreeMap& target, TreeNode * nodePointer){
			target.unsafe_insert(nodePointer->data);
			if(nodePointer->left)
				copyBranch(target, nodePointer->left);
			if(nodePointer->right)
				copyBranch(target, nodePointer->right);
		}

		int structureEquality(const TreeMap& target, const TreeMap& source){
			TreeNode * targetNode = target.root;
			TreeNode * sourceNode = source.root;
			if(targetNode && sourceNode)
				return	branchEquality(targetNode, sourceNode);
			return 1;
		}

		int	branchEquality(TreeNode * targetNode, TreeNode * sourceNode){
			int i;
			if((targetNode->data != sourceNode->data )
			||	(targetNode->left && targetNode->left->data != sourceNode->left->data)
			||	(targetNode->right && targetNode->right->data != sourceNode->right->data)
			||	(targetNode->left && !branchEquality(targetNode->left, sourceNode->left))
			|| 	(targetNode->right && !branchEquality(targetNode->right, sourceNode->right)))
					return 0;
			
			return 1;	
		}

		int size(TreeNode * node){
			int i=0;
			if(node->right)
				i+=size(node->right);
			if(node->left)
				i+=size(node->left);
			return ++i;
		}


	protected:
		friend class TreeMap;

		/// Stupid example of a method that modifies a protected field in 
		/// the TreeMap class. Feel free to remove this method or add new
		/// ones here.
		static void erase(TreeMap* tm, const TreeMap::Key& k)
		{
			tm->root=NULL; // we just modified a protected field in tree map
		}
};

//////////////////////////////////////////////////////////////////////////////
// TreeMap and TreeMap::iterator methods
//////////////////////////////////////////////////////////////////////////////

TreeMap::TreeMap()
{
//	std::cout<<"Konstruktor"<<std::endl;
	root = NULL;
	detail = new TreeMapDetail();
	detail->afterLast = new TreeNode(std::make_pair<int, std::string>(-1,"wartownik"));
};

TreeMap::TreeMap( const TreeMap& m )
{
	root = NULL;
	detail = new TreeMapDetail();
	detail->afterLast = new TreeNode(std::make_pair<int, std::string>(-1,"wartownik"));
//	std::cout<<"Konstruktor kopiujacy"<<std::endl;
	*this = m;
	


};

TreeMap::~TreeMap()
{
//	std::cout<<"destruktor"<<std::endl;
	delete detail->afterLast;
	delete detail;
	clear();
};

std::pair<TreeMap::iterator, bool> TreeMap::insert(const std::pair<Key, Val>& entry)
{
	iterator foundEntry = find(entry.first);
	if(foundEntry==end()){
		return std::make_pair<TreeMap::iterator, bool>(unsafe_insert(entry), true);
	}
	else{
		return std::make_pair<TreeMap::iterator, bool>(foundEntry, false);
	}
}

TreeMap::iterator TreeMap::unsafe_insert(const std::pair<Key, Val>& entry)
{
	TreeNode* nodePointer = root;
	TreeNode * newNode;
	if(!root){
		root = new Node(entry);
		detail->afterLast->left = root;
		root->parent = detail->afterLast;
//		std::cout<<"wstawione jako root"<<std::endl;
		return root;
	}
	else{
	while(nodePointer!=NULL){// na iterator  - straznik!
		if(entry.first > nodePointer->data.first){
			if(nodePointer->right){
				nodePointer = nodePointer->right;	
			}
			else{
//				std::cout<<"Wstawiam z prawej "<<&entry<<" "<<entry.second<<std::endl;
				newNode = new Node(entry,nodePointer);
				nodePointer->right = newNode;
				break;
			}
		}
		else{
			if(nodePointer->left){
				nodePointer = nodePointer->left;
			}
			else{
//				std::cout<<"Wstawiam z lewej "<<&entry<<" "<<entry.second<<std::endl;
				newNode = new Node(entry,nodePointer);
				nodePointer->left = newNode;
				break;
			}
		}
	}
	}
//	std::cout<<"wstawiam"<<std::endl;
	return iterator(newNode);
}

TreeMap::iterator TreeMap::find(const Key& k)
{
	if(root == NULL) return end();
	TreeNode* nodePointer = root;
	while (nodePointer) {
		if(nodePointer->data.first == k){
			return iterator(nodePointer);
		}
		if(k > nodePointer->data.first && nodePointer->right)
		       	nodePointer = nodePointer->right;
		else if(k < nodePointer->data.first && nodePointer->left)
		       	nodePointer = nodePointer->left;
		else return end();
	}

	return end();
}

TreeMap::const_iterator TreeMap::find(const Key& k) const
{
	if(root == NULL) return end();
	TreeNode* nodePointer = root;
	while (nodePointer) {
		if(nodePointer->data.first == k){
			return const_iterator(nodePointer);
		}
		if(k > nodePointer->data.first && nodePointer->right)
		       	nodePointer = nodePointer->right;
		else if(k < nodePointer->data.first && nodePointer->left)
		       	nodePointer = nodePointer->left;
		else return end();
	}

	return end();
}

TreeMap::Val& TreeMap::operator[](const Key& k)
{
	return insert(P(k,"tmp")).first->second;
}

bool TreeMap::empty( ) const
{
	return root==NULL;
}

TreeMap::size_type TreeMap::size( ) const
{
	if(root == NULL) return 0;
	return detail->size(root);
}

TreeMap::size_type TreeMap::count(const Key& _Key) const
{
//	std::cout<<"szukam "<<_Key<<std::endl;
	if(find(_Key)==NULL)
	       	return 0;
	else
		return 1; 
}

TreeMap::iterator TreeMap::erase(TreeMap::iterator i)
{
	iterator it(i);
	it++;
	erase(i->first);
	return it;
}

TreeMap::iterator TreeMap::erase(TreeMap::iterator f, TreeMap::iterator l)
{
	while(f!=l && f!=end()){
		f=erase(f);
	}
	return l;
}

TreeMap::size_type TreeMap::erase(const Key& key)
{
	if(root == NULL) return 0;
	TreeNode * erased = root; //find it
	while (erased && erased->data.first != key){

		if(key > erased->data.first && erased->right)
		       	erased = erased->right;
		else
		       	erased = erased->left;
	}
	if (erased == NULL) return 0;
//	std::cout<<"usuwany: "<<erased<<std::endl;
	TreeNode * substitute;
	if(erased->left && erased->right){
		//find most left of the right
		TreeNode * nodePointer = erased->right;
		while(nodePointer->left){
			nodePointer = nodePointer->left;
		}
		//hook the left to the most left of the right
		nodePointer->left = erased->left;
		erased->left->parent=nodePointer;
		
		substitute = erased->right;
	}
	else if(erased->left){
		substitute = erased->left;
	}
	else if(erased->right){
		substitute = erased->right;
	}
	else{
		substitute = NULL;
	}
	//substitution
	if(erased->parent->left == erased){
		erased->parent->left = substitute;
	}
	else{
		erased->parent->right = substitute;
	}
	if(erased->parent == detail->afterLast){
		root = substitute;
	}
	if(substitute){
		substitute->parent = erased->parent;
	}
//	std::cout<<"usuwam"<<std::endl;
	delete erased;
	return 1;
}

void TreeMap::clear( )
{
	erase(begin(), end());
}

bool TreeMap::struct_eq(const TreeMap& another) const
{
	if (size() != another.size())
		return false;
return	detail->structureEquality(*this, another);
}

bool TreeMap::info_eq(const TreeMap& another) const
{
	for (iterator it = begin(); it != end(); it++){
		if(another.find(it->first) == another.end())
			return false;
	}
	return true;
}

TreeMap::const_iterator& TreeMap::const_iterator::operator ++()
{
	if(node->right) {
		node = node->right;
		while(node->left)
			node=node->left;
		return *this;
	}

	TreeNode *oldNode = node;
	while(node->parent){
		node = node->parent;
		if(node->data.first > oldNode->data.first) 
			return *this; 
	}

	//dotarlismy do roota, czyli to byl ostatni
	return *this;
}

TreeMap::const_iterator TreeMap::const_iterator::operator++(int)
{
	iterator temporary = *this;
	++*this;
	return temporary;
}

TreeMap::const_iterator& TreeMap::const_iterator::operator--()
{
	if(node->left) {
		node = node->left;
		while(node->right)
			node=node->right;
		return *this;
	}

	TreeNode *oldNode = node;
	while(node->parent){
		node = node->parent;
		if(node->data.first < oldNode->data.first) {
			if(node->data.first == -1) node=oldNode;
			return *this; 
		}
	}
}

TreeMap::const_iterator TreeMap::const_iterator::operator--(int)
{
	iterator temporary = *this;
	--*this;
	return temporary;
}


TreeMap& TreeMap::operator=(const TreeMap& other)
{
	if(&other == this)
		return *this;
	clear();
	detail->copyTreeMap(*this, other);
	return *this;

}

TreeMap::iterator TreeMap::begin()
{ 
	if (root==NULL) {
		return end();
	}

	TreeNode * nodePointer = root;
	while (nodePointer->left) {
		nodePointer = nodePointer->left;
	}
	return iterator(nodePointer);
}

TreeMap::const_iterator TreeMap::begin() const
{ 
	if (root==NULL) {
		return end();
	}

	TreeNode * nodePointer = root;
	while (nodePointer->left) {
		nodePointer = nodePointer->left;
	}
	return const_iterator(nodePointer);
}

TreeMap::iterator TreeMap::end()
{ 
	return iterator(detail->afterLast);
}

TreeMap::const_iterator TreeMap::end() const
{ 
	return const_iterator(detail->afterLast);
}

//////////////////////////////////////////////////////////////////////////////
// Tests
//////////////////////////////////////////////////////////////////////////////

/// A helper function that outputs a key-value pair.
void print(const std::pair<int, std::string>& p)
{
	std::cout<<p.first<<", "<<p.second<<std::endl;
}

#include <map>

/// The big mean test function ;)

void fillWithData(TreeMap &m){
	m[16]="kotek";
	m[3]="piesek";
	m[36]="szynka";
	m[1]="nana";
	m[8]="ee";
	m[24]="ooo";
	m[51]="uu";
}
void testIterators(TreeMap &m){
	std::cout<<"--Iteratory"<<std::endl;

	TreeMap::iterator it= m.begin();
	int i;
	for (i = 1; i < 12; i++) {
		std::cout<<i<<" "<<it->first<<" "<<it->second<<std::endl;
		it++;
	}
	std::cout<<std::endl;
	for ( ; i>0 ; i--) {
		std::cout<<i<<" "<<it->first<<" "<<it->second<<std::endl;
		it--;
	}
	std::cout<<std::endl;
	for (i = 1; i < 9; i++) {
		std::cout<<i<<" "<<it->first<<" "<<it->second<<std::endl;
		it++;
	}
}
void test()
{
	// A typedef used by the test.
	//typedef std::map<int, std::string> TEST_MAP;
	//typedef SmallMap<int, std::string> TEST_MAP;
	//typedef TreeMap TEST_MAP;

	std::cout << "Testy uzytkownika" << std::endl;

	TreeMap m;
	fillWithData(m);
	std::cout<<"--Wypisuje"<<std::endl;
	TreeMapDetail::print(&m);
	std::cout<<"--Szukam"<<std::endl;
	m.find(8);
	testIterators(m);
	
	std::cout<<"Liczenie"<<std::endl;
	std::cout<<"count 2: "<<m.count(2)<<std::endl;
	std::cout<<"count 16: "<<m.count(16)<<std::endl;
	std::cout<<"size: "<<m.size()<<std::endl;

	m[51]="uu";
	TreeMapDetail::print(&m);
	std::cout<<"--Usuwanie"<<std::endl;

	m.erase(15);
	TreeMapDetail::print(&m);
	m.erase(16);
	TreeMapDetail::print(&m);

	TreeMap::iterator it = m.begin();
	it++;
	it++;
	m.erase(it,m.end());
	TreeMapDetail::print(&m);

	fillWithData(m);
	TreeMapDetail::print(&m);

	/* TEST_MAP m;  

	   m[2] = "Merry";
	   m[4] = "Jane";
	   m[8] = "Korwin";
	   m[4] = "Magdalena";

	   for_each(m.begin(), m.end(), print );
	 */
	//system("PAUSE");
}

//////////////////////////////////////////////////////////////////////////////
// main - jest w pliku /home/common/dyd/aisdi/z2/main.cc
//////////////////////////////////////////////////////////////////////////////

//int main()
//{
//   std::cout << "AISDI cwiczenie 4: wchodze do funkcji main." << std::endl;
//   test();
//   // Biblioteka z bardziej rygorystyczna wersja tych testow bedzie udostepniona na nastepnych zajeciach.
//   Test2();
//   //system("PAUSE");
//   return EXIT_SUCCESS;
//}
