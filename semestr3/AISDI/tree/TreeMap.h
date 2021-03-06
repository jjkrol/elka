tree/asd.cc                                                                                         0100644 0003673 0000144 00000020304 11704031110 0013777 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        /** 
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
   root = NULL;
};

/// Content of existing TreeMap object is copied into the new object. 
TreeMap::TreeMap( const TreeMap& m )
{
   ///@todo Implement this
};

TreeMap::~TreeMap()
{
   clear();
};

// Inserts an element into the map.
// @returns A pair whose bool component is true if an insertion was
//          made and false if the map already contained an element
//          associated with that key, and whose iterator component coresponds to
//          the address where a new element was inserted or where the element
//          was already located.
std::pair<TreeMap::iterator, bool> TreeMap::insert(const std::pair<Key, Val>& entry)
{
   ///@todo Finnish this
   iterator i;
   for(i=begin(); i!=end(); ++i)
   {
      if(i->first==entry.first)
        return std::make_pair(i, (bool)false);
   }
        return std::make_pair(i, (bool)false);
}

// Inserts an element into the map.
// This method assumes there is no value asociated with
// such a key in the map.
TreeMap::iterator TreeMap::unsafe_insert(const std::pair<Key, Val>& entry)
{
   ///@todo Finnish this
   assert(0);
   return iterator(root);
}

// Returns an iterator addressing the location of the entry in the map
// that has a key equivalent to the specified one or the location succeeding the
// last element in the map if there is no match for the key.
TreeMap::iterator TreeMap::find(const Key& k)
{
   ///@todo Implement this
   assert(0);
   return end();
}

TreeMap::const_iterator TreeMap::find(const Key& k) const
{
   ///@todo Implement this
   assert(0);
   return end();
}

// Inserts an element into a map with a specified key value
// if one with such a key value does not exist.
// @returns Reference to the value component of the element defined by the key.
TreeMap::Val& TreeMap::operator[](const Key& k)
{
   ///@todo Implement this
   assert(0);
   iterator i;
   return i->second;
}

// Tests if a map is empty.
bool TreeMap::empty( ) const
{
   return root==NULL;
}

// Returns the number of elements in the map.
TreeMap::size_type TreeMap::size( ) const
{
   ///@todo Implement this
   assert(0);
   return 0;
}

// Returns the number of elements in a map whose key matches a parameter-specified key.
TreeMap::size_type TreeMap::count(const Key& _Key) const
{
   ///@todo Implement this
   return 1;  // this is not a multimap
}

// Removes an element from the map.
// @returns The iterator that designates the first element remaining beyond any elements removed.
TreeMap::iterator TreeMap::erase(TreeMap::iterator i)
{
   ///@todo Implement this
   assert(0);
   return end();
}

// Removes a range of elements from the map.
// The range is defined by the key values of the first and last iterators
// first is the first element removed and last is the element just beyond the last elemnt removed.
// @returns The iterator that designates the first element remaining beyond any elements removed.
TreeMap::iterator TreeMap::erase(TreeMap::iterator f, TreeMap::iterator l)
{
   ///@todo Implement this
   assert(0);
   return end();
}

// Removes an element from the map.
// @returns The number of elements that have been removed from the map.
//          Since this is not a multimap itshould be 1 or 0.
TreeMap::size_type TreeMap::erase(const Key& key)
{
   ///@todo Implement this
   assert(0);
   return 0;
}

// Erases all the elements of a map.
void TreeMap::clear( )
{
   TreeMapDetail::erase(this, 0);  /// Stupid helper usage example
   ///@todo Implement this
   assert(0);
}

bool TreeMap::struct_eq(const TreeMap& another) const
{
   ///@todo Implement this
   assert(0);
   return false;
}

bool TreeMap::info_eq(const TreeMap& another) const
{
   ///@todo Implement this
   assert(0);
   return false;
}

// preincrement
TreeMap::const_iterator& TreeMap::const_iterator::operator ++()
{
   ///@todo Implement this
   return *this;
}

// postincrement
TreeMap::const_iterator TreeMap::const_iterator::operator++(int)
{
   ///@todo Implement this
   return *this;
}

// predecrement
TreeMap::const_iterator& TreeMap::const_iterator::operator--()
{
   ///@todo Implement this
   return *this;
}

// postdecrement
TreeMap::const_iterator TreeMap::const_iterator::operator--(int)
{
   ///@todo Implement this
   return *this;
}


/// Assignment operator copy the source elements into this object.
TreeMap& TreeMap::operator=(const TreeMap& other)
{
   ///@todo Implement this
   return *this;
}
      
/// Returns an iterator addressing the first element in the map
TreeMap::iterator TreeMap::begin()
{ 
   ///@todo Implement this
   return iterator(NULL);
}

TreeMap::const_iterator TreeMap::begin() const
{ 
   ///@todo Implement this
   return iterator(NULL);
}

/// Returns an iterator that addresses the location succeeding the last element in a map
TreeMap::iterator TreeMap::end()
{ 
   ///@todo Implement this
   return iterator(NULL);
}

/// Returns an iterator that addresses the location succeeding the last element in a map
TreeMap::const_iterator TreeMap::end() const
{ 
   ///@todo Implement this
   return iterator(NULL);
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
void test()
{
   // A typedef used by the test.
   typedef std::map<int, std::string> TEST_MAP;
   //typedef SmallMap<int, std::string> TEST_MAP;
   //typedef TreeMap TEST_MAP;

   std::cout << "Testy uzytkownika" << std::endl;

        TEST_MAP m;  
   
   m[2] = "Merry";
   m[4] = "Jane";
   m[8] = "Korwin";
   m[4] = "Magdalena";

   for_each(m.begin(), m.end(), print );
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
                                                                                                                                                                                                                                                                                                                            tree/chm/                                                                                           0040755 0003673 0000144 00000000000 11704031104 0013477 5                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        tree/chm/AISDIc4.chm                                                                                0100644 0003673 0000144 00000322602 11704031104 0015252 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        ITSF   `      *�<�	  �|�{�� ��"���|�{�� ��"��`              x       T      �      �      ��             ITSP   T   
            ����        ����   	  j�].!��� ��"��T   ������������PMGL)      ��������/   /#IDXHDR��+� /#ITBITS   	/#STRINGS��!�0/#SYSTEM �&�$/#TOPICS��+�p/#URLSTR��o�2/#URLTBL���T	/#WINDOWS��>�L/$FIftiMain��&��	/$OBJINST��g�?/$WWAssociativeLinks/   /$WWAssociativeLinks/Property��c/$WWKeywordLinks/   /$WWKeywordLinks/BTree��
�L/$WWKeywordLinks/Data��V�C/$WWKeywordLinks/Map��*/$WWKeywordLinks/Property��C /_tree_map_8h-source.html����y/_tree_map_8h.html��J�/_tree_map_8h__dep__incl.png��4�k/_tree_map_8h__incl.png��B�r/annotated.html��f�4/asd_8cc-source.html��|��/asd_8cc.html��	�(/asd_8cc__incl.png���u/class_c_count-members.html��y�p/class_c_count.html��k�/class_c_count__coll__graph.png��f�P"/class_c_count__inherit__graph.png��h�~/class_tree_map-members.html��*�z/class_tree_map.html��k��?//class_tree_map_1_1const__iterator-members.html��<�l'/class_tree_map_1_1const__iterator.html��$��3/class_tree_map_1_1const__iterator__coll__graph.png��s�+6/class_tree_map_1_1const__iterator__inherit__graph.png���o(/class_tree_map_1_1iterator-members.html���Q /class_tree_map_1_1iterator.html��(��\,/class_tree_map_1_1iterator__coll__graph.png��t�Z//class_tree_map_1_1iterator__inherit__graph.png���V /class_tree_map__coll__graph.png��D�@#/class_tree_map_detail-members.html��p�R/class_tree_map_detail.html��U�/classbasic__wfstream.html��G�$)/classbasic__wfstream__inherit__graph.png���I/classes.html���A/classstd_1_1iterator.html��i�)/classstd_1_1iterator__inherit__graph.png��6�/doxcfg3_8dox.html���_/doxcfg_8dox.html��1�]/doxygen.css��:�&/doxygen.png���/files.html��M�//functions.html��v�/functions_func.html��
�S/functions_rela.html��(�/functions_type.html��+�}/functions_vars.html��]�N/globals.html��7�9/globals_func.html��p�u/graph_legend.html��(�/graph_legend.png��F�/hierarchy.html��[�
/index.hhc���
/index.hhk��)��^/index.html��u�X/inherit__graph__0.png��\�*/inherit__graph__1.png���k/inherit__graph__2.png��q�k/inherit__graph__3.png��\�E/inherit__graph__4.png��!�/inherits.html��)�i/main_8cc-source.html���	/main_8cc.html��m�]/main_8cc__incl.png��}�E/pages.html��e�C/struct_tree_node-members.html��U�^/struct_tree_node.html��B��"/struct_tree_node__coll__graph.png��K�{%/struct_tree_node__inherit__graph.png��N�}	/tabs.css��`�^
/todo.html��3�::DataSpace/NameList  <(::DataSpace/Storage/MSCompressed/Content �J��l,::DataSpace/Storage/MSCompressed/ControlData j)::DataSpace/Storage/MSCompressed/SpanInfo b/::DataSpace/Storage/MSCompressed/Transform/List <&_::DataSpace/Storage/MSCompressed/Transform/{7FC28940-9D31-11D0-9B27-00A0C91E9C7C}/InstanceData/   i::DataSpace/Storage/MSCompressed/Transform/{7FC28940-9D31-11D0-9B27-00A0C91E9C7C}/InstanceData/ResetTable ��                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      �	�O�L�d�e���"�� > Y    U n c o m p r e s s e d    M S C o m p r e s s e d   { 7 F C 2 8 9 4 0 - 9 D 3 1 - 1 1 D 0 Q_        LZXC                         (   Q_     �      �              �      F      3      �>      O      �W      tg      zo      <}      ބ      Й      �      2)     �m        
  k��C	  HHA Version 4.74.8702  $ 	                �92����          index.html   AISDI Cwiczenie 4   aisdic4   main   ��        T#SMR�c   g       ����        ������������������������*  ����                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        2c04  u�ʴ�Q�%���``���H�(�������ڷ%���I���2� 02E3 pV"����餷'q�XQI�6/����n�6�[u9����i�ؽ/Y�`�ۣ�Z���u�Q�������rM�P��s���,G� 9�G � �8�+ ���]�mww��k6����&[qM�Y%��-�J%�)j�kڸL T�)@�����b$s���(�K�ŀ^n�/Se�߳9/�Ϛ�fgB�95c˙E	�G��sf�˸�����+7ǕE��Ykeǌ�/r��?�_����>�bF�ͬ=G�D)����"�֚Jv����m^R�Qm�jT�j槺ꛄ(M諦��T�������O{��5W�+��S�(��3]�*Si&�� ��|�d�%��-dOy�M�	��Y��*��d���d"$�	���kJ2Ğ��뻐&��P^���U�;{ѩzsKv�k*��G�	���Y��"�j�-'M�+�#�6ۡlӃ�\�q9ٚ���[��U���X�k��y��l�������C�M,����]9�� ���0ݶ�"�*J8͡K6%B���"?�����fI���mY+=ezѪk�`����v���E*�޳��l�:<��+���oU��6
�����q����-Cy�w�l�m�5�u��b�ԊYVuW��Zm-�&�7$�x^[�,g;ڼs�WM{PW�a]h�%v<��PK��L��x>Թ�i���LPjå�̗s��&w:����cŎ����9U[�ĘY�u�Q���?͐��V��22B�Ҹ�`�͓�&D�sQ��,(ˑ�3r��������]O�J<�[����;j��C�88K�d9p$'z8G��]�������MˆY����<9�1��j\�krƤ)���5oP#���U����>"�E��#YJ�s�@0�0נ��x9��D9�9Ő$KŬ������� Gq�E�]�r�#�	T<�(>�\�h9��"&r1��.��Ga�"/*xa��)R"�J%a8�w�؅W8��4p
��-2ǡ�"1JI^�t�F�L鎷:b�y�N:3R>��F/Ѵ%F�x^M/�_���Gaȴ�ؔo�$㵇e���2����!�r�a'�#'yh�O_��������eP<�P,�����!�6��/��t�zI��&ΕFM*�%�b��1e�DjJ '�X��դ�S�(w�2�5���0I���L�⊿[G(�c�Z1��P1��Q���@�"=���p�Y���ٵp����8,+�	���J���HvqR#���;A�A��T *O�KVש��}D>O��JW���!
±O�gibڳd�#��+��+	%����
d��kb��CJf��Hz�Y!�R׬2�(���`v������qp�*ac�"�N�T�Ō�٭�0��`���v��V3Ss��� �ͻo����W{Q�u*�PD�s~�ڂ;�c�*�WE��&�xؙ��8��a����0�k����E�7X��#V���
�`i��ôD9nT'��9츄s<���j+�E��V�^��t�p%�:�_��A�� ��I9���*0`��`owu�	E��+����b��W�{�����A���H��́�E���U��H�Ry��ٿ�{�U�\Q��%]|"ΐ�J�Y��'I���{e��W*�ف[f��&�J*��)�\kY�h�(sXC�'���WHv;�te�n(�� �
ɵ�y�M@��H��޿�-ZE呾J�SŝʊT�4�#j'�]�-9�D�^�\�E-O��d+>�����V9�*5�ҕ�)�IiI�G�<�p+r"G����V��t�P��pi�@Cu��1��f��U9@���A������V���9K0V;"׎~�)p�79ڀ���mDb:J�7���m+���8$.g$NKRQ-F,�!���(4v2Q��(-�)�V?������sU�����Y )NY�X)ǌ#��r1>ìf�0����bd��~�P�wp��)
�=�kڎp���i*e��̉Y�(�Ʌ�4���0{�,��h�K?D�i8�ۦr��)7/0S�ѳV��L9R!�d��3�%��f0�7�k�H���ƕ�������q�e��*��7�R$�p��2��<16����Eh�Kԝ��`KYvW�Es�
�UtC�\�;݂�g-�Y<��-nH-ń�uD�U��D�!Z%�<⤎�a\��$;v�o��������a,�U\5�)R�e[�eh*������V� �s���o}��Q0��G���&�`�0Lm���ެ+_)A-'��R~�0c;��>�d��y=>��HMB��\��_U2�4䇈�xȑ8���id�Ak0�����xv�� �m��>���y1�����	�:����;���n��9�%_�Di��a��/�rX=�)G}�\�缏Q��.�_[��}�\����5������2\}-RA3������5"�������('ת/�d��0��2��<\S�'�8pk��ߧk�Z�N��]��9r�t-����|m�/�udO��U������mK�s);b�QX�T��S k�*�t�GTV�v�l	�
��
}��wު��9��Ax;�f�\�TAe�)[:o��	S���aq�S�w*�n��𩦍�U��4��5"y����Ẇ�#����k���!��Mzչ2?��>4�b�N�0��`�F,�W]y�$��}.4�Ubb�(fJnc�����Ed.VvF��-���U5<7+�H�7�ǳ����qV���|-����o6ID ���-��TT�z����p�@"l�s��98�3�_���ܛ�ɓ����q�4N.��������*�'<���������~�g�mHa���K�� 2�(��O�J�./��8=�Ø�;	LF�7���������q��t�����eo����qa�3���ݞ��}�xҞ�g���0;�%S{�F���u�߲l�ڏV�=���aW3y����
��2�_��k۵=25^93_˝D�h�١��U&$fn{a�}�ئ5u�m-
m�Wǲ>����Z�I��MVk;Y_�%��v�'��s���d��{vg�y���O�k�j��X_&$��A�K$� 2���2ۀ�WC�M�-%�z���T(��Ƶ �y|�R��x���:��>����MhV��B{nP]	��E���A&��#yg	�����0��>��+�r������Q̷��}��%������S��%��&f�R�D1�O�IgZ���3�'GJ��Z��֬3'�c��� �d$#�H���Ô��C���d�E˒���t�#��g�!�{�z�UU=�U����R������w�uu�-l�5֩�h�$-�vU^�b�_�͊���ܵ���s�3�/m���e��{�b6.��t�)�����.�a3�3����5�f_k�m�mB�X^�	&����:g}Sw%�%;���ƙV�VW�CvK�w�z�$#�l�t-��>y��y�^oP�����a��ݛj�-��Gl9�l&@*���M��?lu�G�+���7�����H�:�jO}bYa����գ�X�sV�g�X`v�v�!�F2}��~'4�nu�T���Q�o�k!�,ts�.X���U��V���m��;��Y�+��Y;/���i�;]���?�I����r�}����>L�?{w|*w[��r�z���ַn���a�	0�*���w�ݯ�lq��H� �@��^0"��՝�]�6U��V�c|��e��B���5�_�{~(U�\���� <����*�R�h<h}�4�dZ�����8C�5�E'N����g��y�o��\*��;�0{$-WT./E��z��T�e����##q���Hg��%��S@G�&b9^�
��{y�d;�Df�
��Ї{��qX���ޘԆ�v��?l��߀#E��������CO�E�J7!�ǫ9 ���)���`&�N^�"���}H��� %L
+�&-;����B`�(���$��Qkr� ��b"���K�=���.�L������.YBg�Գ}�66�_	K,˾�!���MM���X]��V~og��ulb�����}Q�1
@ן���Gn�Sx�ۍ)��ͬ�M�×_~{S����e�wX�j�D���k���t%��}\"�Q���Q@��~ldOD�(\q�O�0ؘ@��XZ0�����x_�]0�s���M}�>�	b	�/���`�,؞����"eU����aˣi6��vMqsEغ�LW2�9^��!�PfϜ�%��^�_vH����ugʺ��o#N	��
(Dp���Կ�k��3�
�/�M�֘"����b
�U�{��ޗ_���V�@Dqk��!��3`M��ɟ��UD�#𛝧��Dr�U��#u8�~���t�j-��wd���j��˥Bg���؄OM7ev̐9%]�-�^�Nּ΂+!yW`�ߛ�W�ϔ�ՠN���YO�Xg}ʠ�m�.!�.�P!*�u������V���n���Dx�)��W�n!�q\JpIG*i�I��^�>ڷ����{w��5��_�݄B���`�LK��l��n�������\K�M�2m���&�4d�7
�!/Κi��ݻ>�)��w���|�w��oح�fU`91�@�"0.��OoV��.��d���� �xJM�}^k<���*^���F�Õ�������#w��u~����(���ci "�9�{r�&����O�G �77��Qjq�푏9����1d�����
KR��C��\I\�劝2��0�&�RFԁ���a��Y�&%����8.&�����s�;|N��Ќ�ű%����{��~_D��D&~7������u"�?�}+��+_<���m��z�~X,��Ad�,�h�ٛ��L�
�`xC[��r��4��DF~�b�4��L
�pb'V����Ft�t��(�����Ư���#�b���$�Z_8��.�����G�t�^C%���FZ7�q��Z��]���-w�"�K�t�mV�ߣ-7�qj+�P1U�F�-T�Ļ�v��ٿ��g5.�M�s{�'�EO�V�|d=J�"x2�c�����B��b�V���8��%�`����n��V�\���1g�i$��(?�ɫ0R�K�}=w}��bAG}�h2G&����"z��H�i�| dFt����sr�8}�/�% @ �� �[��.��(1FP��F��:z,p�8����5�&�.|��bsi���s�8�x�V�H2�2�]5>�w����N9��_LĮ_|�c��D���.�Ue�9�\<l'dٜRcaT�5\䮬C��1n
JN�*��=�W�*'�����(ǊA<1C�0N/C���e�B�6�o������G[�B�� �0" N������eZ�atPr�E��h�Ц_�i-�������i��e���n��V�U�-�5�Qp-02���/��y@�1�����6�Qxԝ'	�����o/^�Y��?��a��9Pz¤��B�u)<���d='H��k��V����V #��})sz�;h�iD)(���3�q{�G�	��#��~���˹�&1����t��FsAGI%��k�T m��^��2@K��:tu����z�g���ͼR1�aE'�&~1��2ym�=��h�x w�;0��@
����[�L����d��U%Ld��F����{�j�3=�a����}~Q/wU�W��{:�8����Ȫ���]�2r�Մ�2-�F�^�$i;�:�B�1���d��t�L#������rb[P`f*�l-�B�H���E�j�9��G�7�	�h-��y���#�9���:�x��]���*� ���亐�N��2ȧa=y�:��AY���L}+,<�|}�uU�`��'�R��0sہ�n�,.EbO?K�[��{Af��g[P�*������� T������L�fꞲm,�r�\�p���7vH���%F���Q�sR�I�G�Y�_9tߔ�No[�Ɠ ��YO<���b[���b�E��/��F�Lp;��m1��͙�ߒ\�`N�����fj֘$����L+ܝ$y���n�Gz!|N,,�54U��v�0�ˍE��3�V��BT\�+:���#��d�?�zr�v�iZ:�-�6����eh��i���*��npl���M���&
X����;�ɠ5c���"4�=��*�9
�tGQ��A�tK��
�>�N���{�W��~�#���]�z۲Y�:2����sQo�Of�5����ez�H{ ��q�1�;z�*Pc��ӵ�:�#�H'��݃Y0h��ɰ&��|��v�ށ
y�gŊ�ѕ�ȶ�q�vrG�m:öm���1l��SK�{Ǽmc�F��6�A���,Q�@ ����Tp�W%�+�+C�os涑C��.��ė����Q�
ۙ�eZ*�}5��FG'�n��mA@�����N�>;B����(Y���7ŊT�ϴ���b}bٖ
�ڂ�SJlAum�����Џ�e��P[2�~-��	IORd!���Ġ��T��ā�[PiCVӦ�xٿ)vw�x0-V�'�u[R�6u�+>%�$A��c�\&2u��e���~��b��N�LC��]K�����Bq�$>��41��$ڸ�MV��k���y���`jΦO	X4��-����/�YS���~��j���,�6��gI�Xc�9;R�gO��֜z-��ztf�N~����؝4L9� ,p���UI�M�	?Q�4v8���z�~g��X��\��Ծ���,�Y��� �oi×�_m[��ϟ�!�Z��B�]�i��L�JW�^���Z�Pt.�a��hT��q:-}Ɨ\^�O�Np�ߘ����e�����P��YO����R��?7�/O��7����I{�!� ��_�yg[��Z��^3��o&Η0_8
x+�>x�wl�ܱ�`�IRq"�A�)0�՝8A�PFE�?���XC����1*�G��A�{E�!(k$ʉ_w�	�gO��B�2@�h[��q۶���?(/��f����A����pSC�X�`�+=��H?ڷ&��`A=�K! I�r�Jf$���z�ta�k��H^���%�6�!��~��t{�_m	�
 02���yN�X����,�/sgX��"��� vM�[0��N?hv7��I���(a���N�Suh��Z�'��?�)�bd��ia�g^~���=�h�)���@E�s������Q�J�� ��{4�5;���{>߭
�i&..U ��ό���� ���|�����e���������|��K+Z���lm�ř�&*���?��eR��nmG�eNMޥ�����&���Sy	��f����?ld'���� �<"Rc&���9�P��2�v&�������<��g�t��F����}�������#����C�D0�.4��P�*p�v�n*�>C%7�B���7>~�����z�����&�/\��A��=N��_�r{��{�4p����������{��@�Å~�[]���%���>h{]�CD��N��gBE|��R?�tgy�B��J2����R|�y �:ؾ�
,5^N9�ˠpWP�4YfbH�㜴[����B��k���I�����Aɝ2�=t!���@�<��ЁX&=���5� r�Jf����u�A��Ga=f#��ж�c���Rt< R(	??���-�g'w�&i���v���'��B_��f��Ɩ�ޘ��<{�H+���?���U��dLPo�@��h��P�������h��w�ab�%w��d��@������:���H�e����!0]7�O�خ̢�s9������w٘֊B�=�����)�zTE�����\R>m��_	~��tt�*���Mq�GC�( P   #D@4  _T8*F	�I�����e6�*Y�.R�פ���`�LFf������Ȍ��  �o��P�:6�5j�&Պ��qĴ|�<B}`B/��P���qt��h:��Ou5>y
j���,r��s�cH]�}!��˓���,[ȉ�7�I 9 ��+��w���~o��vkw�۷���v�����ݤ�7�[M-\� ����F+H�_�(D5��_�AAPA��r�+N�K� ���qY2��-������pq�n�_~
�Hnоl��q* ��Ņ���<?�Y=*קJm5�n�;�\ݨtq�ٵ;�����ڠ��hʰ��Q�+��k�j��Wz!���F.��xjS��Z;c�`��G�a�������A(���=�ލ6��l�EEQ�5�Yi})����vܦ'u����6i*SD�j�C�n�k�֛d)�cP(�ː�n0Ć0�<-�80����������"�s�����Q;��C޼��,\g�].h� .䄾�����S5]=�S��ѻB�z?�ʪ,(h���0f1�M���k2 f�yI��h	��c
0u ��@&��|�����Ϳ��a��F��9W�.:챸�y��
t�1��f-��<��QC�B�Eф,Bh���K����ޫA� �6���t�~ ґ����hH�+��{ �*c(W�mwX���%ƘGuk ��uB�Q�jU�W�B� ���9\fQ!d�A����Tb�y*��j��q��5! i#�N& �(0� P�R�_�8��DR-}��ǹ�p/�A-IQF���i�Ղ��	�F��*&�c���RT�V�;R�Iʕ>k�p���
r���VP�c)��9�s��7���G�0+ho�D��70+č	�o�E���-�c�{E�
'�sƄ}���Z��(q��j7P�ו/�nd=�FP��[O�J��25�Q��a<3� c��m1�;	>�$�N�?Zc�:��#}��q�GPY���5PQ�8,�!X>Gf 柆�R��q����cʿz�ۏ|�2�������}V���ռ[�~�j�Sᢏ��srL�:Q����
<\�����XL��pUtås�I�iK𷗩��xvXuދ�\Ϲ�5�rY�YO�Q2$gS{��Q�
�U�����0B�0�U���0̲�̻��?5��R���xfXk1�D��w�	:~Ah$�H�;|�w���?%%�S����芈h°���^v�O��6�r1���^��d�M�L��O�c����ɨ�g�F�RZ�y.n�B�F%�z��-����m��I.k�Dxh��x��4�R0���,Xn��։�S�M6�Ԟ$��( �`�����W�($M���(p�n�>�	 �3�(���%V�G�<��P(8�3�Hd�m��@��b��nU'Ӫ{D��!����r3��qcpA�����9 T��Um_�]f٣�]f�o�b������fqAh����ۦ*�*K��P�d�$P&��+�A<��3(ϲ��z�������&�qJ����bÚ�T�I���{�TD���e�a�7�9+dTcS��c�j����ܞ*��?�^��7�v������ہm�x�����94y��f*H�%��%�I��H�du��?ek�M�z�h-V�U�w�Am|�{����iŚ=�z2��o#�b��0�� �G�8��Q4��2H0���qA�����o���c���he��i!E��C���šp&���!L! �缉�f�40t)�"%��,Ƨ�BDu-!�r0գ1ő���&~9�q8�F%�8a����~.��rX��o���ꖂM���2���6ŶN�����=��4VX	�2�@��X0���� �T�F|ˢ� ��ݥfcb�ﲺÏKD�$]�2�`����*E�X���1���<XRy)y�d����Vm��gv�v�6��se�D������-�П�!��d$@S�|_~�M>�h�2KK�W�����,'�HzS�hJ�V6�bp�H0�-l�r_�P$�t�"���%��U{�Yzޒ�m��X޺�a@�#u��J��X�a�2`)α��uQ���MQ�؊ր��V�m�8f�!��2Sx�
���W&�i�˽���E9��):U��4��6�)B��K�<$��! $�dF:+.^^|�>;*�Ջ��3���Q]M��:D�p�l����r((�>�H�JX%Aӵ]��p�BP��j-oS#��d)��V��qO�b��0vN���@"Þ�W_=���^�#�_����n�k6%�����O�7ػ��*��)���& ��"p�ko��c+�����MG�ә9&�"L��,$�"eb�����bpj��E��7������5E�cge��ܥ$�l(��hdvL�6"j@�7��-��� �(K��c���e�Ȳ�l)�k���H PR*�Ai2E8��7d���%g)p���j5Z��J�
���H)����G�fä%l�P�) ���I`vVӼd�@��!�䳮^iN/z�c�A�s�:�P�����۱v �/�>�[r��ݚ?�Y�FƸ"0R¥�����^1�ez3�`ʊf�����@�Ƣ/VJ3"��2�>�l�c�!1����At�������$~4�BV62)\�d�3�T�yy�^=�g九яK�C�}��+����t��З�Qc�j����c��Ӯ�!"Cޛѭ$3�f����e�����bv��4�=q¯9)���C����R�#et���+��!x.�<��K���|�D���Ux���� ��+X���o���	�nZm��]�lw���DN�M�X��lTأ�7��2h�).��@����X�.毸u��13�����(�����V������:�(�b�|�m:�7a��t<G!�V�q7����AQ1��k�+�O����I�G�zS����'�&��9�ʒc9F�#�Hݛ�����g��Y��O��e�;D�����E~}3E`k�� �
Up4b�dc��N��@��õ`�Bb�T9l��޸���~�t^j�O�ܼu�]:�H�M�q3&����i0^#63UK2�7�(�s���ɥs[�j<��æ�L��5X$1j�X :�0o�ǫ���/����OAS*"߽لZ��*/�+r������}��~*���%a�"�YËt��0J�PU���&����IvbƦ��1j0��B״�.ao"& ��>��#��c9�\�$����.^��B
�CN��$]�[/y�����Mo��ŝ�o�<��F�$�x^�Be6��_0 ��R�)���6��n�̘)�alˊ��j���|L&���O��fƯ���p�]�qF@4)f?��Xv���!�dK+f���n�we1����K�s�
-
��[f��In�30	!J�0�~%�?�]��F����M�؏2EU�z`�/�qF3y�vXa�E�0�E�h��q��և�Ic?F�n�!R(lxy
��-��C��߻t_���9�#������!�M�>t�s�,B�(~�R?3,/��o�Ę�w��C���ʣR��e 0F��C�sKy�dU�E�;�ͬp7���6X�$j�����8{s6b����Dv�J�X�6�rh�Q�#F�-���TdL!]T`CSZ�������j�
����氎8*f�yp\m��2��[b=�"�� ��Amx�o�ѫs6{T(y��2��jEq�^ŏ�k�
�tb�)��*0�Ĺ�c�	�lQ�)�x���QE��9���JԈ#c#:Jd����;����ML|���O�x��#G����N�k���=��l�3����L��:Z��K+ �44��0� u'�v�g"$�?��}$i���M��h�O���.o��A�?n�ǽ]�ex^�� s9�ףյ�R�������Xc*.��ߴ�V��~��'�s+��h��T��0JW��\<u���ys���)-]�C+���م��a?�,{15����|҆��K}��ʺ����C~����UU����Am-Je���)�έ[�BH���<�����o -H� [�mq���S}����Iy�|�;�͜�yg�|��s�́S��7��۞Ι{���0d���ZL?�kvژv_s�n�Z�l�
��F\A��(ż�]���pB�������Y�j�nu���d�1�aT,l��/��L�pa��MC!�W��g��{�l���]nH�g:�G�¦J�5����٭A���z?dO�z�[ѡk����~͎>�d�xe������5�Ox�͵��/�l���B]���1�y���n��.����jpVW��x�ϡE��?�B��C������9��ܑ�\YW�x�w�S��C\�PQ�*o�_Y���M;m�Y���j��ؾ�n��\"�R�u�SA�.]�3�|6���y�{�~�qwuT�*����zњ@R�<��@g��r��ZwJݹ��M\µf�֨�7vj����r�7F���Z��5GzU��g�6���j\A��Vl�/��N�MUՆ��%;�߱����OA��+Q#���ki�����T�y�[هKA����>�����h��,��d{�����V�Ʀ���}�{��������u%�D�t�T�����F_u���H��¢��� �~$��F�޼�WY:��˭�s���J�ѿ�UC8ZzI}��3�0ܻ�jͷ֑ ��ꏯ(�߱�m��@tן���Mn�Ù ժ�A"��|*�v�9Tf�%�Mmc��p~5��f����l��.��˵)��^er�����5�F���X�ߙ;C��x&7���D�����U)4�B�C�Z���Go�1�4@�m��}�Mk�?$�!�hw�{(b^�(�~�}�V���N����{�����}�Vn�67�o8˙c��j�5
��
�=�p�Ft�7�����1^�T��"��p͸ӵ�P���-+=����v�C��	Ӑ��cFH+  ]Y;����Nҭ�������v.�zp9�u�V|���� -��<�]�=��~�*(���zi�������K����a�b�l��~�F���胬��_>���s��+n�����?���E=h����h�=[���m��1!�.��.�E@D�<���G~N.��mH�h�y'�͛�s�/����y�Vs�#?���s瞙3߬01��x��|�ٯ�p�|s������Ps���3�k3R �kBՕ>���6��6u+r��܆s�(����胵�^k�'Y\v��f�e���L��)�^�pĕ��و^@�4�<
����+\����Q�d��k�!����^[�	p��L��O"X6���������d�{]�q�#�j$�Ovѽ.ھ�$�� $dg���kj=\�:,̵��f�4�d~�kF�[d>@�bk���A볍oraS9�wΨ���u������9`�r������\s����e�{�|�f����d@f"��WE?�`�]��\sk��������d���G���[^(8ܰ����hS��0�kiʄ$&>x���-92��V���g�.�Ie���,q��@p'n����v�1da�{���"J;;��;#j��e��y�]
|��9���O)7���`�x	�` <��7�|p���S��M�
��\�Q�E	�:�JMW�#�Ԫ�����Ӵ�펈�}EC
7e�.#UF%�`qN���#�B{��,f��I���jŚ9�->�������I��S�B���ո$"���d#�fے��OlP�ğ�=O���:�TN��2�R&H����oua=;Ǥl8 �1�8[�d���/�Y�J�K	T�O�JYI�s)���f�2�R�KJ	\/%I�p)���t�%�/Vzh�ю�k�f�k#!�59�!����,�Y[
F�(�V���)��O�oZ[�`:�ܡJF!������_�@��PnC爦�AHDp�тR�}NP����
Z�=�6���:�#)��D8Y��AgiF;H��"�b�Ns�y�:c�R���+;�K�~���6��Й*	_�̡�,������U� ܓG��u�����E��U� J!�9�@:��St��w�K'�I�;��������ߥ�e̾2J����f��F�ʋ�b�0�����i�)k��/%I�KђKj���Oۛ��f���%�1|iֿK�e_}%,/+�)�),.%�u�"��[[u��|]����J�t�!�fR?�q���q��c�EɼS�%��S�(TNx8G�*.h�-n��no���T��6{��Ѻ����H��.�`�9�9&�C� ��e�4)qD
� �ս�{J�+%������˂g���1J�3d��>.q�%��b��S����k�r�e�D��LyB�����'ŨUb4����ٯ���ȥ�|l�z������)�`o����%���i�}��T�_��1<%l����kL�a|ڐ7"=��|��<]����B�Y�hp����4��e/5���f��V{���ǲx#W1ص��$�Pj0j|�#�~R#sά�+��T3�ѳ�tn#��[u������24�0�hTvlƴu��؏��nYoW_�u���+��oe'j�U�~9�G��Ӂ�ū<��r��x�������nk� n_dЀc`����m��� �,�p��Kc��,8����ߘ���c����~�SCZ�}U?R��yD9����������RfMOK��`�Wq�	�M����ן=�g�H9���A��2[X�W�:��6���JJ��ơ�|�;�ŧcoɰfa=��'˵���� :�>��L��<�$����7&i�`��J�QY���3�3&�{�-�0B��O��u����ھc��Lr9XSV��r��
X�^��u$u�[��7�M��dC�ij^Rtȇ��cI�)���NSJG(C�I�T8��8d*/���̆�&=I�5<�N���w�����4y���{����4˦�}���s.Ou�fPG�����Vm�b��_�S�9gv�J������l��ɓ���!�[����2΋����99��O�/Qrr!
�����ҿ X�5��y��R[bf1ȷ}|�m��}���F�,�	�Kzb/�5f�k������l2�i�iN�ϖ��2iƚ��?���_j�4L���7�M�XĤ)I�a����?�E�yP�w4��rЀ��x2��SC��;�z�zH�j����>���j�_kD6�u�8�}����*��åF�/��0�7��c�N}"JrГ������lP�m^ �-6��͵�Gm a_ꠏߴ��0HR�X��ZƟ��V���P����f�{]�c���FA����i�7�.�Ζ���n �ZC��N�g�'������b��6��:���>���B������J��a?J��j�
ˡ�`m(�lkR+��t�q��`\(9�J
��X�h�|����(��3�"��	ُm����� �d��=o%<�����̭��.֒)���J0����s��ڔ��i�Ah�����Y��$h)�[���4,ǃ�@����ZnFԐ��-�SZa�$�	� ���yP����1 ����@4���J�X">a!w�{YͼTu�s^�V!nk|o@� *�?\���-\��m��J�H;Lr���5��i��|�2? 2����А~������p�uX����,A��T��*3RAa$2� &�*P�x Z<�~��sЌ!4NȒz)�w	����x^g��p}� �r	��<�� O�h)i�I-L_�ė�<�őm��h��D��נJs�^N]��j&sO�$���]�dih���^�u"��a
W��ȁf"]d��e,=�� ��}&~#6��&r�4bt�5I5^��G>�����HҬ$V��L�d$i=�Sa�J3��Bi$��3����;����H�btA�t?bc�i�w!�7c�]퐎�@��v�����wg�u8�u��[�B�;3�P� `   34@4  oe~��i�ɼ�d�ߎ�R�Y<�G(!Vd�?�[����#����� 0254   �⫗GD"��K���WM���4mĹZ�l���Q;�8�^���fSp�z�I[���P��eW���喁/��-Ӈ]F���r���e�'�r��'�	 @ hf �
����vwvݫ��n��ڻ��Z%�����۶���ڭ����mF��*)Y#A�>#��X��'�P��xd4�jA�d��@G;H;�'������'-t����h� �ׅ�X����k�B��������)Z�5H���-���n#��Q	O#0��8��
�9z����u�G]�SHY�lE��$��2a ����Ɓ�(2�]G�1t)�ʳ 
fI�O)����8 �e��)f�e(:�բ�B^�)�a�� ��w2���K��wxlX�UvQ��*1��L�0ƕ�e�L=\�4Y�(�|K�mT���>�����0��b �X����bi��찚���*� �`�l0��x�Jaa�ž4xOŏ��,��������mԤ��W<eFN*Q���`��)���[��ٝ�2:()�1�労JR�	,+����:>���?2���3�褍0v�-�JSU�ne<�)�!��	�W&	<!��~�e���0�v�	o�V�l��� GbB�!(2�k�<Ơ�ZJ�W0)��U��y�ư']=\G����/飜0��Мǲ���h7T,l�ҳE�huŤ΢Y��,ͣ"<cM%pb��Kf��J�D���7Ζ�K��z�_O�d�H���T��d���x�����y�����	�N �R����Ć�LY�<���8P��&�%�{�>��;�v�l�H1i
�RP�Jgyd�W�M��4��c^)�H��єC�B���eU��|����2���O#���BLWØ��r$WVF��e�L[��m���&�\�"�]�QX�mF�
�[0ěD��Iތj-��ۨ-��c���-�A$��" j����8d^n�Ej��D�_�j1Iު�jB��,Gƣ����Ɍ��i3᧴�>mv��a�S���{Q)��	�u
�u�$�pv��RXac��Y�#�rK_�X�W�3$��
�,�o�=xX���~��}��h�@Vd� ��O��Ck�z�4@�Z���xx��e�NP��3�"I�hS��g�7�ә��6W����\����'���$�-VV�	��}��j���G�$K<���w��I�!�AB�����z����Y��%�����z�N[�����?���~Z�����u`�_~�I���¿iMp>ӎ�G�Z{m��`��Zݾ�_��L��@�I���K�b�ΨyY��#c#si{s|�b>�Y m����'�$V1m!�,]�6{�W{e��� �O{1��R>�7Kޣ�7�d���&���,�u{׼k	���W�C��G\�N���{�v����Ԭ��r�'�Zz0���|�m& �����9CfB�(��\Z�]�Yk��6��'�{w R��{�<��_k��������^Y�(1��Ba�G8��aw9j㺚-f�b�$�F�GoŌۖ���Fc]U�$�+���~e/z-g�l� �	N׶2�W�z�e��|g0utxcedo�d����},�ƚa����b�������)��~���<��<s�$z����X_l=�|��NR~�9x
��BI���KW�!Y�d:✔�w�a�'��2EA5�4�"{��E�Ao9��Q>��ý��o``%��iG�j��ã�����uݷ�R���܁`$Z�c�0�pi�1A�)^�{雴�G����R��P���!`kއi�J���xAtן;�gƂb���AD�K#>,�)7~>Hhov)z%�\d�u�g'�����.���KA��FF7qx��A���B#	I.�
v�`�Rŭj��L�6ȥ\\�~�f�tI�)�<(ˋL�� +h��P2��2�a���]	E�qV�1�1��ݫ�C�A�Wb�E��cZ�"eU�3�����]%#�|����!�� �������Q׆�c+��B�Bqq��=�.��4���)�b�4؛��&F��h�i/�U�qp3[ZA�l�X02�W�cW��C�?: ��Y�v��E"@� �
a��X�ė'�8%#�4Q��t�ȶy�M��7o�^h��$h41[��j~VB�"����'P��(:
���m~2zM̙�f�i���ӱ�d�ة��<I"٣��Ǣq[뽂c$���l:���=�9=5��)�RH��Jԯ���4#�.U4��
Kg�u��AգR��7�RL��.=��!�����Y���[ ��c��1���YH�(Y)���BN) OJ����"��~3>�U�+%�O��F�!M��C2��p8��[(�該�X c@&�-w.���E��t�`/��㛤�;�?�ar�i����y	/=�c�'
)w^d4O&�"���'��Q�3���ǽ�ٳB�00���rU�
)��äS�?)�R����\��C�8I��<��̊s��F�|j��N��+O^�IlL!�\H!�ѐ������.�B.�BE�}J
��l��4h�#��4�RH��m
�b�0V��ӣ&=)��	aؾ>������w:���9`0���^�J��E���|�Sm�����N?�!��/3��5"7{1J-��l. >%w̽^6��J/ �w���m���$&4}�8R]wD{�)�&��>=�{��ݟ>����r��,� 7�`��M\��^���C���3'�|�~n#��1p�oqB�����ۨ�<��]�M�}1�����U!Կ������%���YHR8�*���w��fh-�M�s�C�+�r	Ն�}��w�u{��@�s�إ��6�_X�M�u����-果F�kߙ>�@����;�sM�&e���1��i/�ؕ6F�%J����En^��q|bj�ag�z���s�=�N���_�<��ŀ��� ��������b�K��!�q� n'
o�'����3�^��1�'������.��Rm3ʛn1�m�<���,���j�l���~\�]��ѯ����V�� �4�
��ډ���e�Ʀ�K��tu�Ë����������������8�g[j-�>i�Ҹ�cF���*��z����XƎ�J�ɐ&^B<�7΂�D6��6wzl���_7�t�5��7��n�Iܵ|P����c2��h��o���6����P�O%U�y9v����eV�Lx���/}�T', K����M��2O̸�c4N�p�4@5f�=ˀҎ�p�;�\=	�=`�4���>H?>��?)R�_h΋l%u���q���z������nއ~�#�ֱw�wm�����^��|���Y%�(���%aS��~o[���YY�q�M�q��`�u�n<s�ק��i�e�A�� �>��qg��>聧&�n�v^���:R��]��OPo����l�?��Q_��-GX�8;�����Աo��&J^^�� p����1~��[YR�;�5��BZ��2�C`ä�7sS`�=B����NՈ_��@_1ߧ�ō�O�7�M5���O6��!п0���{u7XMhӅȝ=�L2�f �@����������vTVqh����a�ž��@��}0Q���E���V����T~Z��grYJ�"[+~�tV���3eb̊aA�wΣ��.yL�1$�6�:q��8Ss�u9{-�g�w���Lɤq��^�T�N�g<�� +T��'Kr�����������(h-S^��1Q�������Ó��3B�!U�������;���K����*��BZ��a�>˴k�|���ֽ�����y=�nM1Y_��}*[������DA����|셔����s��e�+�o�؞�;sv-u���$K�@�I�s�S�3iw0ζ���A�J�+���'u�mj����gp�$__����$�
)ZTJ���O�gԔ�]U��;�L��;�a������n�����L9S�oN����r�ڑg4��h�C�S"��zjn\���\���u��RH7��H!�RQʉr��^���R`� \��g2�be���l�ݿ�Iߋ�K9���b*>����<,F]�Tq\�s����8mc��V�<j����Q ��n��p}\1<ݕY��̑�s׵'-?�s�-����\�_�jg�T?��������rL	U~��i�]���K�U��\�Z�I˗ ���`x��5���3*u�[��eԅ�t�*��9-3�MN�M2*Aˏ�@%L� ��ã4�e}}!�S��`�����*��?�[t�J�|>�9��ȓ�\�pE~���_��gb�ß����>���~>T�s�|Y�U�����~Xm%� ���Sh,l��s (���Q(	�A8q/>�j?�T���c���m9)�kK��T�A[X��j����,���Rwy�Ⱦ�k\�[ �L,z��;�ŕ��\�,%b��}>��)��<��c��`d�؎��p�͌�m�_���#�S���^�7B�4����;��F�ڒ<[���Op�\���x�/��Q�r�ց�*h���y=$���p-/���c2<�g���n�'��I�?,K���s�\��%��Ϝ���,ф��Jz3�'XƧ0h��W� >��OCP���� �[f��^�]�qc	g����y)Nz�Șn���>ss6��M�簴�ǃ�ﾊ�$:����C�����JM������񡬇�+ɧ\}b�wo.ݽ�r���\�C'Q��.z�&s��^P�X���5=�b���b�	���9�ϣ�����SŹ��?ƣ]�� J6���K7�&��޲'�n��;Z�Q+�������W�����~nT�'��ey�h���?�n����O���K�l���ٰ�d��3K��q�V���v�x�EKv�ya�	�dHhdh���7+f���Ǔ)��<�__���ӃC?��X3%ٻm��p�s�%1�%!��BQ�4o�U�gM�B+H��j�ۥC����c��L��R�ޝ���k��9��{b�oK	�\O�3���u��w��Տ��s�?�T��B?��!��2�r�)]W�o* ��Q%_�Zns��iȃ��)(O�B�����A�����Z��z�u���������'�W�:���?�|���+Q�%ۋe�X�7�c�/�Ҽ4������[���rw�\��V�%H ��5f�wj ~�f;1���U޵^�|���-�W�����������k ��I�&HY�j��P�3HuR�B�2|O���E�gF��g�h���_���']~vσ�~4͇�6_����S*G*!��u�l�J=����*����;1f�����F>AU��L��g��`*f���������y�$C]�z����յ)S3[��/��V�\;J�E��i!�?[z��|����c��	D�\
}m��.m�=x���*��B��/�2�AF[|�~O���q[�ɸ㲫���B2&���։X� ��&e�b0�gJ[�C��c��eOєV�H�PK;��|KoY�����SB�?�Χ���ŏ����;+4�+�RXܭ���"�O|�C]0]>J���e?�M=�dui����&��k�"-��Rv��m��4���b᩵V*�u�����?F8�
��ʦkŨy3���N���1�A^ �3Z����δ��g�HH�S�5��R�9Fy{M�_� ��W��,���M=���ۨۃ�bZI͹�;&����;�\ۖ2-'P�?U���~,�Y �\3h;�e{��m�\����3��ݣ'Ct���R�6Մg�`џ��yo�)��{u�+I�!$B[p��h��{mn'~pnQ����kV���uF����e����
�k�~Ž�vu�W�2�D�1X�I[��	�W]�)���~��A��l�C��|�Ƶ7xZomb5]
�p�af��d���}�D����|��jF��L��� K��7�])�j}�빸����]5���]�e��T��\g��]	�Է�QQ�N�����[��XY��oU��Inӈ�����+�R����S�+̊v�:ڳ���9K�'��7�?�Ϳĝ�&��3�.�I�E
��M����M�(`���{���(��><Nr�o�=�UJ@3���Dt�N]*� H�S�oq�cSv娶�w��������Z����b��p�8Pw��B+�MO�6   33E4  od.�� ����ǵ� �D���HB�!�(���ny�Uɕ P��`� `d�f �D�[���4WO��?�v1W�&j�>5A����o�YJ�}nV)�F��	������ Z���ږ�KZ -u9�-��b9��Yr�i�$�[�D�  F �f ��{�۽�]���u���]v֗�m�i�n����.�i)��B��#�u	��$�%(�*BV%�"T@B*�� E~�O�J����oS�5�Y1��?�s�wXZ��ZE8��J��dj`���0r&&��5y«�@��Z�����mh_tC3,==
����D�'@m����,���N� j؈��\{,s]G�v�ϸ��w��7!��{���5�ז�Z2_>���˖H��X�/ɫ�߲���%v�q��ȣ�"ך��lP���v�Z4 6D�kAto0�_W�zgDk��ڨ��%�+M�j�+���[�~=oϽȏ
����(_�s��g�����wq�����{#;��U�}�.'gY1�U�wIn��g���g��� C��HT�kF뺂̾�&R�x�+R��@����)���ʉA���=x�Ќ�Y�@����ņ@}�t��������۱�U��D� #�4}�x�����|����g -��[�7�ȑVldؚ���^��{��f_��|����b�z�]�w]�[�QT҂){R|+��UO2��m{�Ϭ% ���/p(}��?ﷃt%J�f�d)��z�P�=A��b�&�� 9!+B� �+Ay⇶'	����a��K���' M^˰����Ǩ�$���Ҽ���U.��RN�TQyD"��4�H}���\g�=�}qX�y���h����8P&S��,b����Ϙ&�#Gg�+��9��zV�.(m�t���w�L�}���~���S 8:�_k���O���nK[ �����o��}Ȉ�7�/�<�ň��Gᐃ��{��H"��y}�ǈx�	t E�}w�����8M�hY(�Ȓ�L	��59S"�����ظ7����r�Q���zG��4��`V��j�aU��q9�"��	"76��[)1�<{��� mJ'(>���5#�w�$�I�a���XQ.����|��y_>��y>x�m��J��82�i3(ٶ���n�W��@��!������ ��	�GX�<[�`�'���	��G�N�Ձn9�A5ӂ$R��HB)ʕ/�r�Z9����0�_�	��4�$P�E�m���C��,j�%a��l�`CM� �TQ��Hgj���)��/"��T�G;�?���`a�5����7K�g�R�Qu�,��k�9	�km���w��; ��h�P�0�$��QD�R�*i�v�)�g�2�n9���X�~�n�LM%���ź�p淯W�b����yB��})g;O����ǙWE��c�W)��"xH��ou�
�D��+�o�2�M��6����h�g�$�Q�I�,JM�3�C^	%�0I'�*y�����H��}�q�F}.����PχnH�����������{��Ow㫖����@�T���
aũ=��$���֧%��S�pP�p�6�P�n�I��u�g�ĕ�Fnp��}��k��ROo7ʼ5I Ci�EB�1�Ddȓ�(�or�ƀ0�]�K�cY�=�ԃ�q��x?H��b�����Y����>Y�����Z��;i�'��K�ɩ�"xMEAID%�r(e�џYmnJ�#o�N�h�b�'8�n����|���I�̓E����i}��q�b� @�2�,���:g}���~"�+�o�w&8��A'`5'#e�?d�����#��gJel�����{&�5��YDx���Ƌ��lL[����"���G}Y:'!}Y�P��ݬ�xd��(�L7dVR��̐�B4�'(��bǋ��,�N�,�M�L����L�H@���};��N��x���N�8��%���/{x_E?�L���x>�OH	)4��v-��է�FT��r�j�*>�(�i}�fWNf)y<R�,���K�p�#��t_O���J8>�B�h��#єw�L&���nO>?��{���I ����\5���'�̘����(��q0�#�"���f�b�� NɆ��}��!\�#�\)��[�|u�Tʦ �Y��O�gsx�ٜ���K��-$��4x�Ɉ彍�U����Nq�r�"h��(!n�\�T�Q�e��P�>E%�4,Uu�TS=��8>�f�Z*��Z�|��C�u�ݧ���!�2@�P��Z%Fwq��P5-�b��4r��C7/H������	�k�u���K��ݭOY��co�m3�p�-�8�W�l���>��|Z��Z�E�]\��f����2Rq��d"�B6",��%��r��T`V$���5�_�$Z��¥��iBB߉��k�Ʌo@h�@�g����,%�Bܜ�ïQ(qp���#�򑈲!u��O�-)u���k�o���d߶��0�\�aT*ɉj",�t'I'.hײ���)���6{=*�7`�������ì��E��Y��}��Ʒ���?�DO���&R�5+Ζ��F��k�iK��Y@��� IO E|��h�.��lͰ�*EM�}>?�X,)˰��i�_%��.�FP���n_Ƣ`�T��I�N�y�	��t!2L���sv����p;�A�����|���,L��|�*�!}y5g���jXm���T;�;+6X7�>�;5��g���ؓ�+i���AyN>�:
�����'a���#����>��@�T�K��j_1ؼ��l��������v٠	���/O͇1��C�p�J_��q�U�~u�g�F�o�hy�1˕B) ��2����<:�7=�Ј�3ҟ�2Rg�q��>ٛ����~�A�����pך�FnG��k���YUȣ��dm��=���3I��7#�����J�6�츞9�H*��ͺ�~����&}���4�~�iO;u�ud��=��^FH�r�Df���K����,�D�>zw/���)�f�NvϮ�"��Z���f��$�!�n�ޑ ����B����^�qJ�Z%'VZ�ڍo��܎R��Vϓ�;���ڨvf��mF�ȸ=n�����	����}j�ĵ�Z�'�/'7�#q�L_<�PD��$�Vx��pq��~W\x�~h�W��D�$ܴ�8���߶��w%�/���~.7ϋu�'l&]���`��m��S$���Q\]�oOh�1��:&\�-��n4���5��7Ω퍕������uA��7[Y��ί�D��r<w�En";Z��t�������I�Y��#�����ă�tfqQֱ`�Z�*~^O�(�wl������'�L؆ ����a�j: e��M�J�R�F�y� 3F3oI�`J�9�r������5�������h��(x��WeqL	��#Z 3���k���V����/��FH%�7Z1�L0*�2�X�.�VW�a�#3M�	,0�n䓲vĴ���2��\:��.�&˹�H"�f�เ�L�]�/%�e	�i&":%��E��v������.B�zۼ-J%W���9��#������y���۝�-%Q��?]Zm�;m+T��8���J�2�^�\��邏U6۾���N[ �W���sنZW��Ѷ���#;�fV�?B2�����G�k������q����,�=�����{�e<�"Πi�D�W�Xzr��Q�£]����������j��ν/EԴ�-�hE��H��Ԩ�V۝v?�AH�L�rOiTK��w  �B�����f�_%�f0�<C�!�T�}�����P�#;�����\,����(���p	7�2MK��2��V^�Ђ��\5(CD�Y1L"<2)O;#!x�n�Q��/$w���A��o���8�qg�r�G�{f�Nr����/!q,׊eB1F�TD�����G��� :L��{k�����~�����a �6Y��h
���o����ڲ9f����O=o b�����L7 n�s@'�2���I��!�~����D=��ډST�^:bx��9���^�G�$�'K����1��\����0���Ŗ<웗��k%m���5�K��������#�8-R��gXlF���	���e#��6��5+�;���ŏ7H� [-d�"r��2����i�a}�gD��+�@�2��.�ea�`���nˆu!C_v��L��i�����Y��e��6��W�G=d��B�6��F���cb0�
��.�5��-$%�����1 �Ņi�x�83���_R���T�F\��%v����-�&m`�Vno����h���/H̢�+�z(�3A����j��m��(�VF��bQ�=@�f��V'p��]�҆C�wT0���"�pA�溒��o����ȩ�%�T��AҦ���N�*��@U��;fv��� g�s�j%��ٴݚ�`t�0AU�3�ŉ\�i ���Q;�\ZEj*I�y�$���
R$��a}�ۙ��қ���J�����M�� DJT�p��	��� �f���Ѥ.���k<>v�����|�$�r2Z4�l<̒I0��zAJ�o���ޝ&l9��(J�$!g����M{Nq,B��ȑ�����;����{��i���K"@#��0��)�Q!Cޖ�[���y���QD*�R� 
�@BH��5!Y���l�ٲ�be��PPL+	�)i��gn���m�O�+�Z������"}I���D���6&I[����"��v�9B���%ʂ&����?(A@R"��jًtPp�T�%��-=}������a�0JO��,M/ U������̛��9f�)��LK4r����0�!�� ���*8y+R�����G����K�7*&��?>�b���"q�&չ��@��7�@���]�����(�m����0� ����m�Z��$%>	���LU�&:�uj2����������g�ZUES=���Y8>�"��nѦpB:�-Mmg�$���snLW�\q#��Z�'�OՆOZ ����e����Ѩ���J����������I1��sU�c~�8D�W�m�������$��ܤw\�r�z��'��X�;�f�;r;����o���[�v�J>�ݶ���2Q�ӡ"������UKrW#]�������k73��~��޻���m2k_]�~�6��.W�c��C-7�+BwZ�<��P+R��;��_ŗ١�V�F��B�s�?3�(�㘯5�.��S!���Rk:�y=�d���1
�?o1�u4�9��q���,Z�n�����oGH^g�p*؎�ʟJ%��)��h��醞:��?Z�w��gq��}�1ֽ��P!n�iz{C�~�z�?=�O�o��E�syBh-Ucp;��Ü7.�6f#�^�B���6�K}j�=�ЗX�"��������н��Z��OC��r��U�1y���^�֤�.T��.d�n9)6�QTTI Q]�'��P#�i?~6���e}�uuo��9_��`!.�]m�usg�5Z�����1{U�y���^b֤�.�ٮ��z����t�{��!n-��\"���������|���Ԭ��+�%��zPE�V��Rj�{EΎ��nJVy�*��#��������.Z�o����Ɔ��j�[�XŻ��c6��4��St��7��\o6�|�i	!M��_��3�w�*Ϫ�}�5"���~�_F7�>?	��UK�e����檫��d9�\8��๬�q���ܙ	�a�0�T}0�g�pn��jĆ�竓�G���y��7����Ty��%��a��Z��7��`nJt���Kl�jO�x��6�B���kݻ�`�9��M�A�F�M��䪭҂���uSĠ?�m^���̫&?3V�uR����u5��{��4�K�||wV���S��/��j@�_���4��Asq�%�F� �K�r����k4/���Տ�����GG��
e�ú�S;�����u������Sk7 �   B4E4  od��l%��?��aU������MR���}�2��<��w�� @fjh  
��V//�1�X�;���Z��X]5�:�j�u+K���vE���f,K��$���xl���1��m-[L�9�X�x1Ki%K��b#�Ă/����{ "  3#pFP �~�m�^��뿷�ov������u��[����d��H�������h# *���B��,A �P�Qb��X��A#B?�j%��8C����a��g\"Ϳ�ZBഴ������@�\CckuӘ�@p� �!$�����d�/��n`���x#s}4nI8�h?I8�zO�\�ɶR��yo����W�����ؓ?�Cp���v]em�Ðd�6�oi���x|3�(mh-��rlӑ` ���3EI��}$9|�L�B���I�GId��9����S9�3��c��~��(������UO��m+��ޡ��PwV�(�H>�W/�&?���i�;A�1��}���sK/����	PW��G��ɿ����qi:I`��CI�&Y��P%w|A �bb�DY�na�(!�e,lZS
L*B�̀	J�.���-s6\������_�>���)�4�o��b��5&,d�--е�K;x��Jm��!�CC���;ā�{��B\�k�؍�C�k[oH{G+�L�ĘMo�.�5���X���}3�o(�����P���E�M#CȆ�Fô��c]���=����x�s%�gFq���AJ%(���$�"�4E�a����6- ��y8�,�������0���ҏ�����C��u,� ��"�� �P̔�e�=�E��#5e)f�@��S2��%r��hf�,i{S|Y`F��T���'���ݒK��#o�7c����.�������NH�Ƙ0"��D�m@�g�#g�$S�\?C����E]#�hc�(
�K:D��a��J֎%��+x�(���d`Dbrn� I��� 4�2u�Й��A���l���NLH3d�9���	#����, V2�k�����*�o�}���y��,7T$�98���L�ɢqR�e|V3��;*iGy��y�&�S��I̝��Y��9%��������t�5I�[svt�{$G��Xh�@rax2�pA�"fЇ3"�9� ��(8�n�BP�=e����GgW�%#J@�C@RvaqB�cR�	L�%MQ�*=�yA�:���K����RI�0�@�Hd9����\q6�5�h$Nfj���j�!Ի���4��frG1��H����%��L՞UP�e�+р�đ/���V9�k*c_�ۍ6�J�o�� �H�)0�s�sL�O�`W�oࣝ�&CB�K�a[�Sc�d��1}	���3�/�=�9���Ú�x����Ta����Uҷ`ϸ��AG$%t��90��I��rQW;��?1`�=w��wnC�)8"�4H�|� ,��W^�J�XbJ��]�J�v����/���c�G�/�W�ҥ7�q��җ�����e�ј�j��)"G}��������5aw�8qg��$���E�d8�t�L&��0[��8����ܤ�n{M����J���	Y^�[�܅x���{�3��̌�:d�۪t��k��#[�7l��X�
����ڭ��;=шv��'kIr.R�J䅠oN��>��ޟ�zV�F����I��p��bV�����ԅ|(����בm��R�u��?���;���b�cv�����/�v��2�7��%��Q�z2�,�چV��?����i�I//3��3���d�{E�a�W�7Fg	��9r�M�r�Y���?h�X���'Slv���Z��i�R�"ksūk��؇��vv�V�"��ٗuyb����g��E׫Sip=J^��(����Qj���vy錷�o�w녌V����Ȳ��C:��iV�'��Z挀�yS��N.�� ʭ���F+X�T���Ҳ�h�ا�V+��Q��E~=��r6�cCZ�W�7�t�=̏f`c�����D��`K�Z���T�AϘ۞�훌��EJ�_�)�\��nO�̧\�['�
G�V�D�͇tj���څ3�iۻt�&���v�� ��1Ϯ��s��Eg��U��Y����52���֯i��Ym�m?WCBB�S��V�Q*p5�Jz^خr���oq��kЉ˫�����Y����C�T\Ӧ�u�{>B/��9��-�lp4%c]�>H�`�Q��@�H���=G ��Ms8����~���S)κG��c��i��Ʌ�N{���U������ڞ��X:���{I���ť��'����G���8�V/��ʧ�zi���G}xx��^ؕ��{eXʩ�E��SQr�i�z/����9��8��'��*[.UkQʏOS5<  �׮Q'?s��,�
1
jRW�� .��Ew�ڕ8(�
*��Q��Zo���R�Äm�Nsb���|�	�\��߫rKs�>�LS��K��ϭ�-U�9YA�]�ϸ-���Ҥ�Mz8r�+WS�8�?V�߰��Шd�S6�`���g��2ι4w\n�E�$��P�X�X��o9�p���Y��n�l[8��$=F,D���(���b�'%q��&�͞j鷿ms���2�f�Ɍ��*eFu�GhbƁj�~��y�^ܦ;҃���h�74�o~2������·�Xx#�YB�k��V��.}o]��v�a���[���f�Aញ!���h�a+�̣3v�]z�0�I򥫤��/��N� [�ň�U�ϱ�����s�r�@�}�a���T���� ���:9��������D�3��)ǋ��pvȐ�К?H��|��4�ߖؿA�-��������i؃��fM���/i[�/mr־��|��!�<cO|���~�1'l�5��O[
1���G�c�};��Z����q5 <��
ף�Ӟوy�Y���AB60#Z�!uէj��q��|j>l4;��&���.������y�?�����{�������f'�Q�]�4?	"�z@E�<��[��7��v���P�8]�#_*bU~��.�ڶ���_y���P��y�VLJ�L�WSe������K��zp���u�S	e�d�*r�oY̼a���;�p�f��|����ø��H>��i��q%����jt�"�;ˍ�*���"�o+#I���y߾8���~���?����������[,�����}�AS$T��u/���ޛm���^��$��D�B@��(8�$fJ?�����GY��C��٫�0�Do5����8�^��-��2KH�Yr��^��Ȱ=�ѝI����ʘ�Yg".��#by-Dn��q 1�0ׂ0��*'�3����r)��<'��=U\l�c�;\�X"h���i\_�:zilE��B��*!��Q?5E7�ӧ��E��T}yh�M1T��Qg<դ(ڧv4��;7��~VN������?Z����M��O;���ưX�e!�:t�1 �QK�W���BA�iM#�L ��S��|�3&�]-�G\�*���B������-@S�E�݄����գ���t�����3��:U c���}�ͼyv�	�1< ��!��� ���xu�� �����P�,L`����<�Iv\{��$���γ���\��
�U�F�����'��?��(�X-g=ĳz攃�_��M�����(�l����En�S�v��X�������nTv��I����m����� &�n)�EǢ�|�}�F�*7"eۉ_��ZZeu��N��w�h�J��E��r�+��HeFvIO7�i�Z̃�D����m��j�d�Z������g�O�re��<�,n�"Ȑ���c̞��#���B�cJP���'^/7)�*�?kg�������f� -X�G)�!:�c��W~�F�5��
4��9{ȇ�=��Aw����%B�Kj����-�d*�[-�{�l�[���STP����O"�3t�R���;���M�|�l�b�l������ڭ7�i����p�Ƶ����}z٭���ԭ7PA�T%I�:���u�d���Gi�[?���w�U��S����	��+�=}�˒�)�����pN��̩��� u^�Fn ��\sX'�XV���eu��xV`)L=;�_Ǜ��ǐ�9zY5ov�������U�֑�GSdW�^�Jtv�:D緻�7R��XCgrEH�8h��O��{���%�e�\ܸb��
faxh�`Re�	q$ �)"ha�hBQ�@n�no6H�n��^p\ԝ�)g8���&,
�����
ň)�ǝK6�dmj���T��;HPN��4FC!Br$`9O��0{-��g'��1Ђ"aF�³@��#*WBz�.�{�q��!]��^��d������@�$D�@�q��͢2&�d���'2��1����18�����sb
ԍx���=��� ao[m"���Mk0*Ey���GYƗH� ��GQ�|4Wd�@�����ؠУY-;�C_0�yy�)� Ƒ��t8�(��0	��N<���Z�\)l>A�͈%�����ic�z�$EQԀ8��1q1��!��>��Ы��A�w 2b�E�J�e�`JyF���g:��I�BW�
����/���6
4i�V�z+W|�ZrR�4����o�n{��S�-�RБU=R!�V@%�7�9�,}�u��\��GO�X)}?p�H,D�{t��mR(ǳ�-�����j��n*�;��ִ^H;�Jm��48��`٪�=W�pxY
MOQ�����=���W$g�c�Xa]���x��p�^N����`9��S]z��t����T���{�-�p�w,�U6�*(D��E5Pv�T�&���i����/,���X�{Krd�pQD����[Ո�w��@l�ctk�92���q*<��_�����|r�V��;k)�stS��3�n�l�2B�� �*�էA5�;��\o�q�g��%f�\7.�1��DY�l��+oY��J[���ªsi7�Nc(^�(�p����m{��6p ��������B�فLP/�%�-SW/��[ ��zI���=(;PK/�ƅ�O����:��������/Z!�����
*�Cvf�T��ׯ��EB��k�G�G�Gk��Z���p(�=r8M��Z
�"%� �݉���Kݙ]�`��	.�,f�η'��#�U�b�j���sn�x�s{81���9���s2�T[=:h��)/�(ӎ��z�a��ne ��}w�	�,�Z(�x�bR�5;%�9�"q1D=Q�i��7 ӹ:7p���"\�'KI����I����[��2{�3�(R���@'#�GI ��pLE�[�������v�c�H H�������4(����8�� ����AR*��O�c(�O�1Au5�"s<D�]y�D��)��&�$��Q���}Ԍ�fg�O��"Ҩ���Qy�E��( @        ; W¢����Ʒ�ބB�/HWؒ�P)��"������
�J"OꥢFFf�h  � ���}NH��O׾��Ӗ�Ӵ�ZXҦ��:7�G=p
!G���K�I��XQ�{��ص{� �ĭ����j�w{�r`�W;��DT#2enm�Z�	I�$�  �� ��nw��.k]�wݵiI�*Jm�n�K��tɝ�*�dKȭ!�@bT�<I` � ?�Ѿ���[�A$G��@��#8"�1~@ �(�IkR�-IpI-�-iB����'�c3�n�L�,�jZk�`����46����/����l�#�����
7oj8qn6g0���-��Q��
%�I��|u-$��cݷ�u6�a��c����Ֆ5ۆ�F�a�A#HNF���H��
k���mm�@ �@H_�GǳoH�C�ZCi{@���z,QP	���#Xh>ݟ��1�بEXi'?�X�FD���.)� �PZA%�0�0tE8� ���Y��A�	��j���@I�� BF7`������څ��P��irkRG��lv-g��H܌ �!Dm �P���*18!��^n���1�� ��r��P1c����8
5j��שm�5V������j)@H�8jT_0D�X��V�l	v��ho�Q��o���]���R��o��F��,�ש��Op{ I��
*0�@�t��� sp���|r�m���?/"\�5��96~�TGf#!���������4�O]v�Z�Z^�����AFp�	��1�vH�G�2!0ʖ�^��Zkg����Ppkā��AqĄA�`����&��s�� �3��z��t$n��Q�z�ał?������9�Z5��\F�<��<p]���#����<�0A�� $���`�"l��)��T��y�${���� 1/���@!�[��'$��9��zݻW��Zj� ����_�ʙ,P8�> @�YM4;��_ol�X��_����C��1�W�<|�p�����O ��W }����qq'U����S�Z���Q�Z(B�Z���PH \�\�?��#\;�b�ώ�v�[���!օa�?�x��n�.&�#@n[m_�RL�_�̟�k�fG�^�A���3_ƶ����g�$+}�o�uNSY��`�f���)9�q�����ɭ�$�}�Ԁo�D�+(C_��(�5uìU�aa3�.�\���k���S;Q��]Kt{vW;��DJ�/2��2��Z�mqծ���6��s'h}L���4jק-2��'��z�kP�@�h�<4�&_�����&�E"���|�p,��#�Ve�e���≲±���?J
?���6Z��[0��p�_�[�L������ >��Ɲ��*���#�[*�x6��C	w`�pg��>ԅI�s��5�qr��
�������`�����ԯ|,�~��[k�j����l��l��U�}�N�x6���ia�6����~��i�����ڛ_�7OCC�6� ��l$�H�0����V���U|v��w��F���7)��~����-�&���]M�,��>E�����a^�,�ֳ|��G�@�W&<b�;�G�7A�ܸ�_k'�5��)�=�������ko��l�:�Q���:cκ�q�����]j�4�7����?��˺����c��gO�[��@�F�C��:�s�:kQUe�0�m���S����Q����m6��;�5�q~�Ϸ����>O�ʿ�Ѭ����Ҋ@����m*��ϒ��{�E��~��( >!\�]�D��aF�3�x�����=ު�?�?�����g/2����7PH �:����`|�'����G\�Z�s�S�y�u�$��Ѡ	�(�_��!���8>�P�O���.��Ku��#�f�[(��o	ٿ~�M_�u `�Hh;"��.����z�2����p���x=l^��2z���6+�V�5^���{������)��߷I����0�8r��o�����r��m��A��ҙ�]�~�E�4��ۂ&�:�M����Z��q�g\�v_?R�G����M`[q��� �[lp����{S�/��)#tc��?�~��;�B�}"����;e��+K3Ӽ�7�6��uc��O� ��&�����q�m2��/��X�n��Md����o�;�Z	���7�L��{>͝��f�������Ig�O�oG_O����5\�å<|=���A����$�:/WS֌��C18?���>툩�`u���y�v:��Z+�������g���ﾆ�I�a��x`�;�6w�e������+�U��ȏ�Üy���v�K�x��+N����6�X�6P��������{ݡfn?��c���[��W[m�����i��wЗ�c�\{ݚ�|���gwV-}����~+����Sr�?�}��t���!���J_nx�tn�7����/��˪b���=��@�[�<���ק�}�z����Gu ���zP�����O�)_�<�M�&��O��D�9��:���(ƶ��ˣae����)O_(-�1\h`_T]PhURUTV`U��[�8��}���*[k�K�>D1����ҏ������ �Xtr�l~�
��$J���h�Sܐ~���_���_C�g�k_�0��C�m�}���<�m��D�t�f#Bͤ<�r8\��/��J��2���������`D�d>��r�5�����~�����Aq«W�� �mϞ�S�7�?/���o������o�;~x�R��ߎ�}�[ft��nO��q��~,O8Ż�l��>�ג:��o·y��'�/ܐ뉿X�C��_��u����3�o�����e`�����~��d�g�O�#g׆�u`�^n׎1�?8�@����G���4𞎾��ߓ�L�.�7W�a/�����3����D�~�n���B��>��w��7�����߄\^���>�ҏK����?���?���M�ӸV�~�'�}=��G�Z����FQ��B��U1��O�o�V�����b�˖� �3t!ڇ��qݦ)~/G��Q�,
��`�o���*`o�-M�"�,\��%����}�o�+xC0�}�� �G�U�Я�:;֊�!S5��]�}���v�ԙ����y��'P�jp�>�?tb�5�m~��*�s�]��+-ya������*���iV��oT�����y[/��O�Y��KEQ�g���͟W�!�t�����U��}M8���� ��_e\��N?h���&�pS���K����"mf��������>Z�(����+'��9��ş��V�|�3N���4�J�!���~!-���~��zPmn�l���.z
4�a���u-��������	�u�UOb��wsj��u�����c���,sѰ�����J'���e�ǟ=���+z{�:��\�����V�zh����G_����=�G�m��ApK}`����O�NAm�/Ƕ�gu��D��~�O�-�є��!�>�����U�T����y.���XW|�R�3*(_ߐ�?��?wc�b��OT�[�c�a�l��t���|/������7UN���!��縘�۟Ϋp��������V��U|�H�����~�?/Hc�B��:���u� �� �()o��~��+�`{��;�.B��Z�X��n��'����*�]t��;��ܦj�Oc�����h&�vMğ$oL��A[���{^?���L;���n�=?��?�m�6�����f�m�����܅�s�}W�E��)ހ�Gf���F����ѵ�sۮ�O�w�.�>�=�����[Q:o����_����.��wM���������&G��:���ˬ���(�dPR���Eϋ��?�=�.����,���~����ݽ�\�>%�ت����o�yx���3�8y�x+���w���c��U��?��bp�p���/� ���k^q�r�(�1����WǪ#��]֭�5�#4��@�	�a�6�{���G���pt��H���I݄uB���P��2R @C����8��/�F�>��F)'����M��J��X���h�h}��	# @�u<@�ۀ|�A�i��� �X �Ď����g-�����#-}�ԏmy�uK�o�$� œ�� a������(x����n���	�^�����(�Lo�ʧ�����qd�F�l��ؽJ��F!�y�ĥ"��(�{��z#AG F (���ԟ��;Sϓ��r��(�G%t�ހ��4=+���[�|!8�� �,?���M#%4�Ĵ�ǳA(�`�((>P�Pj 0@��##�(�C,��1��� ��	��J@)Z[�$��
5�v���O`�P����ò�q��g����ƍ'��F�zH7�������W������7#��x���7|��G�OA���_S��_������{l�3=�`h`�����#����{<��:���Z�I����'�_ǿ��u���ې�������jw?w{c����/>o-s������8=HB"�-�8��� $F~�<ۂ���0���+�yhS����F7��O$܄�:��/��;܃�e1
�GH���1Z0���y�=��,�0��j�����Ս�{���T~y�;{���x�#��k����T�i�X�!�5�6� =�������']6>f��O�\��!t~�[sM0yC�O�v�J �m��9�����O��j�w0�[*��D}���R>��D�(&o��(=ш�#>�-*�G�� �vۥ ���hw��7
�����  4�@|�X>Z�70t��ȝ�6Ȣ� ۮ���9�C O���t ���hw�����y�٦� m���� @�(B�� ������~��/7:��I�7�� ټ��m����3���h^}�ȈGR������ba���ڽ�x�3���ڻ5�S�����-����NTˉU�����^�;�l���v��Y�RDF�?��=G&v�AY9�7�������݀�{C`<�W�A��8���:&��3>��E��OuPi�с�O�~�O��
V�����X����������t�*�?�P�>��0'�@�#�N�>����g��))�)^���}"�Ѯ!�.����?��:��U?�ph�f��]��}�����x6p��	2*!@?^U�8b�4��G�0�����/���Y{�%�}���P�`48BU���T/��]�?�=<�Hn�><�Cᵢ��h�w�70���5Z�:� ��h~���{�������I��u9?��G?O����F>o���֞%V�诓i�G
2��x}΋��o�'���Y�d"��ћē����3��xhF�t����`bt���k� �+�D  �?`�M|���+����p�\v�{�V��M�������w{d���]���w�n��7����"������"��J`�{�cr!�a����܁���E����9��&�s�-���}=�W���F��=�&�9��0q���l�>�����#q?������%o��>L���'n�&Gno�!$�(���� D� �� `����]���~��K�ڶ �g��B`P�#�`)o��(�H��ޏF�Ɂ����ү�/4m{x������4FCG �ǿ���z���و5�G հ�A ŌH���|�C`�D A0J}�����x�GW��;b�~��N��������ct��ă�����<ɽ����A�G!���S��\�(:���_ܾ�>):�=�"�9� $+��@4BЄ��HÀ``dO��c.އ��DF�u�̛~�h��k�j��$�OםTY�:��2�)���i����-�x(j�5J4�-o91�߹�[���z�k��#�����Ệ'�%fgY]R`������F�ew��viM�2�7u��j�8���ށ�?=ݲV���x����+��ͱf��f���_./��x�<���p�}�����ԡ�-�$=�凩���@������z�#6]&V�AxVР��	�Q��Rf�n¦LΟ����u�Of�<��e���&
�J��!d6�1ҕ��'�M·4~�PK��p���l��g���ױKPv��w#,�ʒcUe`uIS#���I�W�]NȖ
,0��dOTՍՈڍH��
/�ϧW|M�a{ Q�����󱆥�ܰ���]t��@PJG�}M�F}u�~�"KC���w'Ȣ�>HgUV����ܨ�Z�VP�6	�v�x�j甭G}�2j]�jM����v�inz�*<g���5�uWCҒi�8t��{��{��2R��"�_҇���S��m���r�������X�\���,"ܴ�X�za֎��d�����7�����UM�R�b�m��Z|������n�~l�>J��X�У���8�-��)r'-A��r��|i����jv��D��<=�x��&��|H&�@����V��a~����6_�w��e_W��y�!�݁�EXϟ)��&��kZ���9�Ou'W�����:�jj�b��g���A���p���������LaZ���a�-��9��R	�%((i)ɺv�����l�J�����"�b�2��O �c!����	��#���&����o��j�S�y
����Oݸ
.��_^���g
˰�19���Y��4�������xV�FY%�=+��q��2;J@�ln~t}�$> E�ǁ >?";�_��"�����|�<�Lx��K����e4{4򤋾�*���pr��O��V7�Ў�82��)�eS������i�Cuy6�M]��p�$$G9�,	�^��]S��5Uh3꛿�#d�U�z��2�Ŝ�����]����,���n]z�ܜ�UP��{���{�ەqP}�K�_�=�&��ucYw�g�g~K�dj]��~�����5�V�*����=Vy�1�
���H�������(��}*#�<�z�H�c�����z��5=�}�\IY<l��������}���~�@���?wJ�00�p�s|_ƣ��w2�՗o4S�<�������'Ң��gt�p˶��-�h��-j�G�����f8��ߖ*=e�LN	\��e[�&T=M����w���qb��k����b�^�и��A��[���DX%��v�uB��1��Nd��Y�_v_
�|�D��yb��~C��l����fw��h1�Q$�R�T���K>���Ʊ���̸P�����\>�5G��� {n;K�Q��$�D��g֪���5|���F}hq
�Al�.YQ�$yA�y��4�<�>:)I3���,k�\)���BF��^=u%���:T�4�e�e�y���!0��;�� љ�@ю��[^������l�bn2����)S��G��&�-Z���Mm����)���`�25�("�],<
w�Y��O�@b��eO��M�.>��C*w�kģ�XdB];�I����m#�G��sw�]Y	��t��k�)u	,�nUh� /@x����t\�+�9Wj���D�˕;�JH]�,�ntyy5G�]�{�v�:�]��*��g,�bdK����+OJa4@���a=�}j��Mc�5�תcgf_V���Ŧ�c�8E�˃��p����jBn�ǹ�b��CЮ��"���+hoi�dQ7�� e_.�����x��h��\6d�ΊM�'�S�S�#�ՠ�1��9�yY��m�s�����EV�2j�Cq�V�r_w��؟�f=9$��y�N��7�h@�q�@��yƷ��,Q>r9CB�Q��#]�e$Z��"_!��kИ�(T j�E���)r��;a7/��_.�M����Yń`�Ǐ� �JǮe#���Jn��b��1���pK.mt������m"Gu]8���qW�F=���~�q)��J���!�Oc�����VGV4�[�v���r��ء,��(�|��Y4&䦐�޿�CkI�c��\Y7���w�Ls�&��7�S�VǤ�,� �4�X����{��$���f�c}��^J�P��Ē'Kq�BbI^H�LW��"@"��"{�M��c���>�rl���	^e��e� ���Xnf5���r:W�[G��[�=���@ԍBVW�#r ��f���[�t�&�1�G֯i��)��_3љe]�o��nF�la��y��ƾ<봒�O�s��z�g)T���j�kδ��y��\&~s��h��y�mɸ\��ֱ`gQo�(��ZV�o�3ه��#TB�����l;R~�qsk�S�F9-�
+	ݔݭR3w�����.������<�r�[^�$k���0m��#��A�I�����m3SGb"�	7:��۱͎�
�וֹ��bӕ��r	�ӛy�}�ΔP�=��������Z�&\��0�UYYmc��A�K���+hROb�cH;�
�����jS������#����ܤ���*
�X�
@&O�������Ӫ�.<5/�z/e��Y#ʌ&4���#�27`�f��;�Ri�e(r��np��҃i��+�̈�>�Z�SGO��a�)&o�-L
TG�iS�s���R��0�|8�&�~�p�g5���!
򾔶C�����+�ϳݕo���TR���ޢ��0�ъ:g^�I��:^�A4���st�J!ش�,x�b@��DM�&��;#��_�m��X�sϭ��:]dZ,�À�)�=����i�U��y_�/��:��
.���\d�(�q���ii	̋k؃�~C&ˬz�����7��S����]u!��M==�t>K^Ӳ�5�VS��"</|w#5B�L6NMWa�6����.K��H/��{���Z�EF=-9� �4�a��G����Ы��Y�X��$�\�ۥ,������诧 (t|Ϩ����9��	H��T�w�v	]�^u�"-'71os��l�_�w�J(4��dș��l�+W���Vn��]����7s�����l}p}Z�,k5�U� 7T�o��Q��su�3�AZ)���}�h����.�����)4 �yi�M�����ly���OE{��
_�}���5|#�	p���:Y.�cw��8���͍ʔ[8���j,�c��B�7�4s
��͕-O����3�FL皾�V�RZO0ۨ������n�I�8�Z��{�1[B���4a�o4����]﮳��	��Yo��k����J��&�$���rn�=>�G��n�d���dg���� ��C�?�X�niXZS�~��w�ϯ�Q(A�k��?Jk���o��c���+ZbB!��щ�9S>y��d�3��Mx�AJ���)c�Miӕ`��������e��oA�c��e��t��(�Kj��p�2E�~3`�Iǃ�����޻��r%�X��LVr{�8,wqq�Y����J��¬K֪ՄSp�
�̇����a�:��k7�y�i��
��ِ�㠨FE�ސ܌`Gn��en���W���sD��׽\�Dy��'6�/*<��G�a&?�k�p}ZWΡH�f��l�1��:���4�N VU��4$�/+����WѾ;^>�&g#i��[��z˚D���2�}o� ����#��^t��&jҼ>����d�MMP(���Wk�2�
��F�M���3w��"攇,Jx�J��ad;\j��P~�OiR:�G.%����ND�u2�z��MoT���Ӏ��I�赎w��(�����G�.�YE��������zM��ݻ�w�Mf��ܢ�O��<�� �^��?�{�n�\������A-�}.�񜴣�|�M��l�bƝ*d�mn�����)><��:��4k��Y���2\����^��z��yյ"�P��Tٷ�V��H�p�A�)%q~�Ԝ'��6��'+�aaƗ��SW���U�ܺ�&�3z�]|�P��9�f�<�yD������51r?�aE��/ݦUE>��%�.&�Z�jE�w����eQ�q���Q=��1���F{LFC����lҸT�i>{�݆�2��\S�+�
ٳ�^Mns�?�q��1��Hom\�:�C�Ԕɟ_�/O��jL�1�d�]E��9:��m������咈�Th�L����2���2�!C�j��?�X��$���ʌX��R\�[C�#<�鿒 t�.v��X�vC���j��y�b��<YS7��!�Vu�S!����cWʻ�$��4�^�\�,h%b5q�ެ�׳��knϔ5��-�꿥NcRwg���$[��}2,��d>ʿ3�(<���[���Z'��M� *���zAe@��;v�<�i�<!�%��U�0WR�O��	>�< ��r(�B)�3���Y'b擂��^=�-#]��f���8�m�rs��$��%�]X�R�u�Pf�s�I�l�$���:R��웆�a<�A��H���_�XO���(�\���o�si�Ɣ�E��pWM�2O��d��^��j�nǛ
��Ty\%�K��+�O%�"��&K���}�A�va�3������)�Z��d
�}v^Đ^��U��}w�t���y�6F�E�&Z>n{���]��C��'�^& �e�X����^X��(��E
��
^���:n<؝�C��G�.?9��V۹��c�qqR�J����x���<=��~k��!	��0F��^p�M~�y����!��ȗ.�m�3�S��;n�â��
F�$B[�ܬ�E��Wo��e5�:��kw�dN7g�'��q'��R��R�K�� Brm
��D\Z�"�rbe���Ut/��fR���z	x
�g<��F���THKcU*���t�4�$&�)j��]|��6~,�=�>Q�$���	)z\J_@zp�(��g�j.v&�(K	��4{��DT�d%�G8Vl�7O8I��9�	�d��l-/ss����ڮ�f[�æB#�qؒ[��}���ݑ���A���TW�i'��)��>�3k�Α0@�)T�-��Fu��:E�z�J��| ޴�����-����U 4��:Ucb���liB�T�Ӥ�޴ۭϑ�����w����5U�=�Ǚ�r�)���^��"�	�|����|bi��<�3[���'\�;���
���ny�#�cMG�O�����N�]���x!P?�me)��|�zq�P��Iqj���O��,�z�	���xY���fZ+%%g�8���'�]��V�˓�撝�7Uh(�-ǧ����m�W`ZX�,{|��|�*�5�a�,t� ,M��6�H(�EDk�! ���;#�sh���zc� ��=¼/o�;���I�؎ὖ4&�N<������`=�5�s�3H�����H��z���%*����$ೣ,)hu��}C���O �:�Nd��Ů����Ǹ�W�$�6�b�h.U��>Q?��/�/�wa`]��R�.ک��'���:LN,5��8�#�y�r̃c�r)8��=��Ԃ�;�l�"�f	�<�ȕM��D�f�~�F�Ӕ�_�G�.;/�-�]�*$X�	���yx$�yz.o��;�z*�_D��y��^��x�m�1�D�Ճ�~W;�p���|�����J�!I��u䞊�T�-r�� ?χ�%!���x��*��3xj�S�ļuf�Ozs��"D\�G�\ĺ��*���S�Z� �����<!���I��أ�l}2���h�϶2P�O�綥��Ǖ�%���Tg�|�s�v��A����ͣ����t�CC������C������=��y�3!v�������8w?��^�U#o�-�&g���9+h�a�Jrʸ��ItC���v\���/|뗽��̓�t�S2�g��뼻)w�Y09��n��\���Kކ��s��L�O�W�6V�!s��o�z�]����#���9�����W�� �����\q֞皋��Q�r�����~C��:��Ó������]2�	 �~g�tr�㐖�����K^3�Z��:��V�ʻ��H�I�]����1�<O�}S�-�w�֙!s):����YΙ`����%f�A�9+�#
G�O�[�6���a<n��i���	��7N�3)A�r�f@K���:��C��܎��%��7{�M�Qv;��XQ���3P�lm5�*Y�w�]}��1���z�[�9�m�w�����__�%���һ&$����]eih��b�+qJˣB%Yh�]�V��jʈ��ۜl,����b��]���Lp[ک0��{̽�[+�S����u�V�~c��u��w>�̚ܝnY\�L����Ǚ�"��&�am-d�J[Ѧ����Rw���=���1Q�����)��)&��ak�4�{'��L���Ƕm��S�kk�q�*4���n���|Vky��@�cwsč����@h�L/VO��3r��G		/PĽ���R9?��:��\"�sr�Oq�׷\������I�25	@
��s�	�xAr���s�rNdS�����l�et ���N���JN��������Pn�bu�j�+<�Q�L�or�{X
�c�VQ٪5wj�ֲw�ΘZ������e�J����<����i�1�vk�zː����G��/7��|��#������3-�N��aN�n�r��鍗��t}<�O�	$�C�Ki�廹��\���SQ2o��L��_��xJ�r��G�J��X�M�����m�u���>v�=qi�D��-YnRt�wr��aU6�a:�',�qx����K������J�L����|�{�N˓�r@�Uތ���iۯÔ�fb����-c��i-&�]���d��D�6Ae<�rG�ZF7љ��+��:���/��)�����4h��rgn�wq���<������x?�nssC ���ߡ�E�e8$�-0X*sa��6�˛Vi��Mn8�I�k��fZ��ެ������iC��"����Ț�+!���1rĨ�$wհy�5�3������]�Y\���:�Z�m����]���)r{:)������x[�[��ɲo�#��N�Ѭ�Ag؊������-��0V�L�Hٲ.����<|E��_�I�n�'6]Ov�)�D&�َ���r��A�_ɘ1^��'�X4��ﵙ�<���Q���93��~Ip�a#0O����W&ww��HUcsI���v��=e������-����<�pJ����B�EE�j�uzgv}꼰����5%�[B6"_�P����a�����4 ���N�c]p����wR��lCl���ٴA@Dn3��y^�6%��b��ߌ�ϋl�vn����YD�f[aXN~�^�S���4��N)8Nr�VR��f���L�Եk@���i��u��L�5G�)�,�j)+�[�Lj�%�1����V�#��(�Y/��L�z�'���͘�8���dߴV��ט������ .�ڕm��pp�,8.'ưl�p���H�P.c�h��2v�h�#�ʒL���$���c�h�b��o��^�܉�*
.Zs]��y0�=I�nʳ3�QY�����7+���?ؒD�Sc5�A���(�*�	P�s�Ý�g
���u�X�J�3d�k{5��XX|Xf_��Џ�X�k�粯�����3�~��oG��n�[2�,��!}@ T���l��c�D˕��e��"Z���2}���O)��t9�H�����vm�[7�U*�8�,��u�/6cr�ݖ�p�Mc�J���Rm�,""�޴gl߾��rT
�mD����zx�]����ƀ�f�G%�޶*�ߴ��{\��f#�Gda�!��c��OsSH�FY�&4,Zf^dR��]ٟ-Jd�^�+�s�������[Vs�ʮ��Qx�+f���pqR���_���kWsK'o8V��}e#��K�V��Xv�L�&�~�X��
���wٍ��b��D+�L��2g�(٘*������N��Ҽ(��g�֕��2����RO?� ̷7㜭��A��
�2�7�g�5X�A�c�� Tv����{���v����6��ŭ��x��	�<�~����|F� �q��u�*���i�Ks\�u�f�ꚡ�s+jCӯ^�OV�Gj�,�l]�V���e�9ԉ~:F�v���ԯg�R��J�	sV�(�e��X���������S������^D�QΉ~P��@���ݚSLb6���RWM��q�M����US��Z��o��	�GJǛ����bY�w�=���fZ@|@y0co3����u�f[gQW�FZC7��AXE������X���v<?�ώ͝3�R*a�.�)��t�����W�hf'�uF���G�Ȗ�Noq��j���Ϊ�r�J�	��测G-�U�M���Б��5��f.�x��m"��^J_�{d��;b���W�3݊��-�a�+(_���{Og�VZ?W6��)� ۚq�G��T[aY��0&Z}����km�KXރ����O!${���[9*酞��d�q�\9�!�J���%�:�.+�|����q������L�9�R�`�tK�f��[��4�M��S���U�������>.��u)�{N��.�yj%ԝ�p���R�h����)~0�f~?"�=�6^Þ4����8�/�Qꘖ��������l�[��גSrUt)a��gNu�&�1`Ͳ�/~΃��W�r���93��,"����c��o�:���G����1I��Z���h�*�u���>�΁�6�F#����~�#�C�������1�?�um�δm���ǇS��'X7�*�{�TK�5fq��⛯��m/n�B[���:/�j��V���W���#^��Ώ���8�AF���wф=��F0�`w��l�\H��:3�lf���S��@�I�ec�K��cU��ޜz�n���:6~��� Ш�dr��1� :����Tx[�«�����c*����nY�\������}���v����˘�,�Yz\#�{lMvB�=-��C���K�G�=�dӢ���%���p{9;i��Z�w��T�V�D�
����Zt��V�{�E� 2���h���h�Au�3�(�,� U$؜1�4܉�a+$~T�|�Pĕ'f���C��w t�geo��H@;	8��P6��r�y� �S��%ĈoE����"�$�̙:g����*̣I>*J ���f����5�Ls�9���vk��β60����l�,!�d�n��@ʺ���Z�u�ZM���?l�����l�T�;/��m��]�b��W����E乍�9�,���kE�&|?c�=��+��ϓ�Lp���kb�|aI��)$_uӖ6�{�Mc�Q�AJ��!K�ƶ3�2Ș�����5u�����k��0�;%�S��Z�c.���Ϊ��+B&.f_�u�LsK��k�������9ǐr�9��m;�.����3��Ѐ9i �"s�Y��(�uc�G�#�V~���Q^j���@��K�.����q;���6��_ӻa�$wK�u���=��$'I�Ye��E'R�ߚ����]:�S���W��Y��K塆�A����a5����.�柴�F��g{I)�-v�j;���အ�o�U,)��5A�*��_�4����/ȹ�?� #̝���ikH��No�g^�MuDQ]�9m
�D�̩�fj��Ĭ�j���,��A�%�G�WI[�Ao2MT-�{u5/���]��W�i
B%ү2����#(��1dgs�x9R2D@�L0F/+�䭍�rK(����X�Ȥ�Y�����KmC�Ͳ�R~�q�&0����E�~�V������I=gxP�D��}`L�/%��Ժ��U��Z��٭J'�Ó���d.�n~�oG����a�[�ָ	8{PCP�{A����N9SU��Y)�F�op�Ue��.�yI �����a[$��*C�VLfA�޶�Y
��D@����d/�WC�4�7�g��*v�rtzW⁆��#>�s���N	�\�w�/�G����\Ǧ� ����#��(�l������'��Ĉ@bx�h��J��g�|n��e|�U|�}o'�Z}ψwqs��4��mng]Ē�TY5�+p���_*�zʅhq�P���t�V�$�zd��3�ol��W�i�vYɶ�<�����Sf��w8�� ��ʂ�H[,!u��Q��Z�9�Z�ޚX�Q��M�����PW�|t��&��� �$+}�	�aj��c7u5x�g�}�� ��-�w@��>m�FUK�
���ܷ'<�ϛ�V_�r�w��>���[���e�����^���!%ÄJ�b�eT����(5�k�˭;�T۴7Ie��������J�:���F]�f�{2���A�r�������|����H׹�A@�-��s�W��<��m%Ԝ��dN��Vm��*yAZ��Cw����Sa,�V	~��-|��	�U )*$5���Z�����?Q�觙l8�h��_���"u%��RXZ�U�Ґq��,�Y�2�	if?B�K�*�5]�5Y󰯅���5�F��Lg�m)G��t�W�ˁ{c�|Ҽ�����i�Jf��
P��"�����*���U���)b����3�Ke9	Mϒ`�;$�ۼ�>���h���/+���Y1m>R\.:�#t�
s�<��:��^�����o���9A�FZ�7�ч���C���f�j�Q�o���<�n����G�-�/w��\��ˏ;D1�,�Z���=�z����n����M���E'�V�)��V/������?#��f@������������<��M7���{��r�]7S�͒�VH�8��w�Z��g��
�z��d��\��㱂��"�L����9r��R���Kc�UN��"Y�_S�5Uw%�	To�����,\��ijS5�Z7|�^�S���9|o���ֈ�T��NB_��оoMJ�:sWb��o-���
6L�>�8$�	���қ2���D�NHQ.��٘D.t'�a�z9������IRi�l��a}�U	z�	�՗~�6�P�����[k3�&xd�z[�D�V��DL�@%�tQK�]�C����
g�V��
��[ou�{l�Q1؟˕�ϕI�Ch�h� �8 $��9J���?�/�oO �l�j4hV�F��v /Q�"�y�1j�G��Aa5$����'%�ğ�u'v,��=��x��/�u'��"	�6��U��ڂvb�-���Y	��<8q�mϓ���h���sMb��0�R��.|a	F�����s�R(�$X��є�`N^�4`>�7S:ސ
=s��?��Cu�C�K�fqf:HI;��"�#�F���yq]y/���nQ�����/�J��V[��q�t�R����:�g�x�e�~�ܽ��R N"K|p�T3Y�`h��h99��� �4W��W���4���T�e���%���Sz��g��,ᎉ�����6��h��Q��yN�n�x�Y����(�l��e%�c���L<��z�~C�?���z��T._(zL�NM�J��w�?�r٫�|�v|B|��@Y
#�[�o'@�AL*�(o��Q����g_͘|t��'wu��w�w~ޡj��z���F�c�[�ln���Ń�۝CP��lr>�Ԟ
�5����ngLVHA��
��3��<����Б�&2F�~vɐ���R��瘷+dx�6���R8�TS"������-=+V��%�P�p�	��$��r�cOn�i!!�SY�D��*qٲ�{�.+8t�Ù��:��rbS������N����a/#�/7�J�M.�G��hD����r|��Y���p�[ �a��1�)m�֊�t���������Ӓ������r�]�]{�f*�W�Mc����6������|P��(^8~zz���Ø8仼A�o��0�8w8��]��m�A�0T��gI:!��q�+Ǵ}��c �W@�e���o��v	���)XV�b�Ć��I2�eiz� ���L�L6���ŋ��B�v��U��e�4��H���)&�˄{j:��ש]��-��������P�5���eq������}��>/�J��C:�ǻVc�g��~�Hu�!�!��Ή�Ӵ]���"���E��%�"�s���d�9����umV�,8)[�3C]��g�J�!*�!�����c�"Y�_�vg�\ڿ2�.�� Zf�y����ݖ
R�6��E!-���-���c}�Å���2�e��m��ż\v�.�!k��j�v�UHn���@�k+I�`�0x(f�� ��Q����bb
gU��h�/�X�~�HC� +	$	Ɣ�6�_@�)��Q�+�ؖu�7�ܘ���͹���%֏l0$�"2��f|�%ʷ��Ώ�p<l	΄<�.,�q`�t8�84��v��K�`'�VR�P��[g�W���u�D�6N�UU��1��B���NM�q�ZB�3��ύDQ�MT�<~`Q�R�f�ʛr�o���Q+'���Ǥ�f�j1U�2a�{1�'�D1������$|��_:�KU�Ġf��.l9 �JY�V����	��JW���\[hƻ���6#}w�:߼��º���ޓ���9fm*�Nʜ�>x�A{��mM�o4y��5S��;u��r�3���=���Z���1�d�*�
��ۯ�NdB��KQs�wz|f$�[�b^G9��7�a���U�ܫ4�.��A�������*\�8�BO�۟<��q"��[�;G��Q�5#�-�K�N�@d(Zp"��דְ[Gؤ%�A�N�Pb�HbxP&2��At���;MӴ.mBL�"x3�@˟�t����%wƦ����UJ�M�\j6pލH��۬��ע��k�u	;�D3+�=���o�vw`��bd�j�Y��wr.��d$I+�|$�9�U�ᩔ��s�j�u���dc�t��iuKK��am�^80'��=5���V�U����8�����^��������9˸�s��)L�&����D(�v}��;"/@��.S�آ�p�kZL�*�U�{�����PT^����������"ͧ4��R�nGՁߧ]keS^�.;m3G�>h6��+�aM��%��2A�6Ȝ��C�V��;�4<`����A����-o-�J3�++9 �&�Z�������
-!z�~L�l\*xV��� �y���}��8������G�����x͢>�Ta��+�ȝ�=�γ�}&)H*IF���y�N;�V��[�˯eS��4҄�퍜���l���Y�uрj %��T��e(������x����o�ӏPsY��ZV�s���\5ѤF����V�*Ӯ�J}�I/a)[%� �ӹ�rc8���oKa/�8`����J�G;�t�Gn�RM��q�l�&���w93��JV���s��F�hg�S�I�i씅��VZ|) �?����؛����g;�2�O5j�((�V�h�t�o�F'ZM0�S��?��g�5���4���d���l�P�6j�s�̰$�8���l��/(\�T�4&t(%mQ��-��x��Z�N����5_�{N�j�<u=�g-�Qh��>.w�DW����L?|IxSZ[�L�b���h�,{7n�,?;_�����Q��YP��WBe��R��a���@ϒT��/�2�BK�RR��(F^�!ٮ,̃��4`wD52�;8����N*���1��8����-�7=}W�YW�B�d�Z�\q��\}N�#�E�f:/�x�-J��7 �|3ӹ�oN)'�5I-lЂ!r�sOV���z��E��r�a��8i�Ԅ
�Y鹥�zq��ɾ�%�$4eW�k�߼�r>9���s�͝�>Do�������m��T���������U���<E�z�q6�G�T}�a�ߖu�M�`��Y!���P�6�1��8Y?��Q�D���_���׳���*��@j���r!���v����"�l.X����@p�u��=�P�S�� ԕW�����|��uwHj�����M��2�\(�K�+>�%թ�=���ctDN����B�|�԰D�WM�g^p$�,��4:u3�>;�$�F�/����Ý�혱	���n����}Ÿ҇���;�J�P�/�^�ܞma��|hD�Wo����	%9#T�Ұ�lf��HԂ̖6_-�-�ǉI$׋����-�k��ъf�Fڷ������ K��N�U�+���l}���ʫSV��v����!O����&��S&� �����E��>ۉ\�>&���ʆyj�9	5��z>H�#R�ǵL���b�W��"|��!U��]���d�U�o}�o���]ߗ��*����D�oy/R�&V��pO	.��~���+���l�~s��G����y�Gܤ���̦%6;�ٴ��<�)+q�ū�ׇ��n�Z/�c��HN��}�2��z�ޝ�J%s&\.	�g+�qs���[���u���(�l����"W$�9�1�����Q�-m�� �N�]Q��S9ߕ�9ӒQ���_p`FF��>_?�=KǍݗ6T�7�MJ6f��0�X�zF-��}yB�ŭ�+���	y?��'١��G��1�oD��-�������]�"�\�F��9MT���5��T����1� !�������9��7�k>P�?l5��|�w��a<���]#'��)驲ޕk� �˰�i����
��Ec�L��|C51�*�/��x���h�tvf&y̷�}��+.+g�A�CnRA�+�~�7�ÿ��NE�dO���������@�T�}	~����}?��R�\�8_=�#��f�=1�o�3��:��������)�S�D^+̉�5�SuHc�[͈�I�F2��8�^���É�!%�N,�>my!��u���rnP�1Oo̐���[�ɶ�T�	6��XʃGZ�/8a�W�e/<$�u��>L�0�?I@H�"�N 9xZ
��Oh�v�ݭv�����
�,e�����`�P��)�	��o������j�BՌ���&m<�#3T����:X������;�\�e�cyQC�b�X,x�'ɘz��}��q6��"��d�3nx�[�9_)�'��F��Sp���ڂ����h�m��A�MY�M�-[,k��������8�r�����!�kXF��p�46樍�Y�_�H���
��T��@�����|���d�!�B�:~�$Yu�&�'�Zr��v"� $A��VH�=�!;_*���ڡ3X9q��\��I¥�3��Z&"{���(]ɺO�Ǖ�����Ԩ� 4]��� �����O��B}�A��N훍T�U6W���Ȓ�@%�����e������e���h���e;��T'��;��H$�cH/nW`Qq1�yg���#��7�k�ɘ�#��%4��+ws�+/4�MShq���Mp�)~�)a�����:έ�>�4���[��͚�I�?/�n������y�'����x���~y4l'�qU�ݎ���b�J���G�c�s���$2#&pcp���%1|$)�=��ڪKn[�������?��
kiQ�U����q�����>�'��	(�ɋ�]K��K��f�q�Y�3Ld�MВ�&#(�`wy
��6	� )�(��<u���I�䗗��BЛ�À���T����ԉ�ߨ�n6�������{>���7���N��sN���\��W�Tb�@o_Ú����y��c�u,r<�6���m�)���|^o"a7
�%�>��<]�8ν����!�3ҽy��Fw:�">��I9ĘnI�M�+�ݘ����xn/;��8:h��<��­��IqO�"xn�<�ĩ��H���7FWXj��3``^��L����S8a�,��Ђ5&IA6�U��o [�S~
4����npe��C�}�� ���^ј�1��NT^��L�ɜcZq��h'��>zk.�[�qb�q�V�i�`��h����lށ���N�3��iG ����q_;/'�kN\P�z��[�'މ5�����mc[=	}�ֺJN8x-�,Y"��pH�b�%id�A����@kZfd�O�8�h��3����J��1v�>']8u�No2ݖ��by4�$�n���ϝ���L���O�b��H���oaЇ���j ��͎��{m^����AI��h?��	��`�=M�7�����(B���;39��ƈ���a���!��u���gVI&#�0E��Nǂ��@W0����^�&�:��Ƹ_�x_����r)+fO�XT��St\�+n�SļJ'�)��X�!%Ĝ�<,���R%��)�9�?~�1_�3F0=r���a�XZ�]}S�$�e�#���,�R��O�
��n��k��#f0e�x[l�{���ǀ�V��c������p��e=D� ��B���o��3�so�S'}C�xo4ԫ���
��~��tnl��텺�`ή���Uu�E����^b��aw��6�f�:�gp;9M�;Sbq�c��:(�)���͙��+Q]��-L��~;��Kt�J8[1��o�-�qiG�3��l��/�&�M����q^Yn���mv��PT��-�l]�4�W�Yu�U�J+dn;��>�˰,�QN�;}3�% G�Ɏ"x7i����4i��
���us>���ĥD�g��Y��鄲�����Μe��F�6Ӽ��w�=��ϝ�\N���&�a���(�Jy ����צ=�ix����t�wl�hE�h&fT���NP�ۦa�b0�S<�ZN�7*q,97��k� _��ὮX��E��7L�.��\��+�3�l�m�q4/�Ҳ8,L���S;�G���;3\���Ԣ(���Z�>Tn	<u�;�t8�����e�|PًJ7�Fv���7�c�,�f�z����� �$����RUֵ�l&̼<n����g�O̍
�V�3#����SC��N�v�s5 &��"�3��rT��e_\��1�����力$4�h�ە�
�F����v-��s�V�M�\W�l08����x�ח�Yn\�k�h^�n��2TQL�BPή3`4��c_�X�����"�I6G�KR�NV��f�ٯ�ٞ�Nv����OZ�GwZN����'_ߎ̝!�
��]�vi2�3��O�Y�����L�v,�/m�n�K��M8^KӼaS4��G���v�1��s��X&�O�	�h��W*���=I�"�#��i���+��!HE��d��ia��J�dr���-/p�:k2z�[�X<�b!�^:&�j�V�\*�PctK��}(�hx�Hxa�۪|���.+/�s�z�3x�}1(�!�;�e�L]�WϿi#�M��U��e�:�������^�<?zN+C��!��H�GS1sga�.Kg|��0��.M_ <�Qœ�n����j�/\lg'�n��P�֣
�c�ز�
��a�� �j��k������t��@�)Ԋy&�#�غ�f��L��p��&k�Wb�_Q���\j$c��w�Ҹ�(麄�6����5)�WbI�C�D�q�@�@�G���*�L/<�ڪGK(���mދ1�7��(�0$f^!B��2=�,Ep��p��� ��/�o�:7qb	�~qM������u��T���3�<vlB��Z��2�K�>��� ?�^d�7gl�eKE��������f�Dܶg痀/3��l��[7&��V]q�Ёӄ�GHHr�1�SB�k�l��Vw���H�ER`�*�+�6%L�8BK`�z/�Qʢ�*�[��k��*X(���6�XWx��C�6 !�Y�K�Čf�o�7�����uD"�q;k�<61��"�KWS�?.术2���ͣ7T!Ue+�@̠�Ö�奕�vthX��UU#�r�"z}K
�pg9����-�Jpo3�P��v��u���O����J�5�%��F��G)��bL��}r4�
�R����|����ګ=�&Be�ž�Yn�QiX7����?�źE	{����:�\g\���PK�ҕd�9
:�(,*�Ԡb��2լ:�t"��0�f�����_����:�ef[I�G�wnD�5���+9pc���*;8
]�$��-��vǆ�&��׍u���]l�l�h��������lE��(�}�(��th4�T��mk�����j�SZ�z$7q�#�=�=���;�}28>ˢ^U���D�J���;��/�U�g���a`�$�2��c�gn�h�)��v���{i�Hu�����]Xk`�/�U�ЊZ��J����q�O�(d<e2'�M��֙���b��+s�Uҗ�΁B�}�v��	u��|�-�� k�&��P7���vçm��9�)�7҉��x�)7kP+q�Gw�p�e芸F�W�b鬇4��䱼��� N<�Yy������p��g'�ӧ��:���x{��o�תNj�|��SIyE�d�u{%Ͷ`�]T�ĉ�ԣ7a����M�2��5�4>���뷉��.����I������n�f���r�������M�Z�ͦQ(>�q51���񈸪������=\	�.;���
9�S]C+z9�a�x��G�щ�����)�*����J��V��+sy�������s�hF��W�\��JI_+J,F�=J�ZeA�>�a����Hk(��ǵ�5�$�n�^��=�L�l}K;���0���d���g'�/^�2{�GU�M�6y�0 tZ��+�b]���vTG��,�Ky�eg`�K�ZI8�DaL�oh<���E��w.V_�q5_�c�;��P$���P�1��%�y�|ՙ6l�R��ޱ��۳�˚���
�&-�	}���qkV�4��]^��U��NЊ      * f�T�jj}PUA�5�CU��U�SCU=U5P"�� � w�5n��sF.|^L<ϋp��xgΪ]��Ey^}x�E��K��/���jr�j	�N���9q��    ��I̭@J.z���������?c�搀e/�m�AMx�*\�{f�n�H���WG�2f��Z�wj��Y�|^=1!�k{Đ�7N��K��D9�5FD�ЏI�AJ�:��)�C����]9}1�$���N��&N%W���P�ol��ti��48t�����o5t�B ���'R��*�4X�H��K���J�z�=����Щ�b]�w�����2|��Gց(uK��Fa�)��T̝����=��O�K�y��+wt����Lx>t�+ۋR�5�Of�)�r���:{ �Y`F�p��~߻��.S�����u�쥀�z?|x�U7Ի-���*�y4�ٝҡ��kƝ�
�*�ynt`�x�t��nv�M�r-���T��ݬ{q� �
��T�b������*iu�C~��;�W�c�^E֐+/��#嫲���-7]֕qS�L;�q.�������n��2OH�F�!c���%3������m�8��#n���U2�Psa�u��$l��9z��/=���`Z���\ E|c���2En=?y9�/p�9��l�������6��"˺�e���*|A2li� {�����-�eOO.�����<���oP����c�yX*7�@jcU��?�$8?�s���,x�?b�M̎}�ߖc7����<�rC�,������䊾I��qS\�D�EN�೶��w�Ӌ��-2}-�_9$+M����VDg_�g'^^��^���rVL4M9!��������i�C�n��n��Ux�j�{u� Ai�W��z���Ef�6�I��%kqDӼ6��zz����Y�Y�*:n$z8��a˹P�!�c6@C�7C�R�<p��X�3�03(�%�R��OXp�&��d!�}���>��~�);͑¸s)�QӠNImv!4��Q�ج���-��'LQ���Q��H;��n��JᎭg��iy��lX��e���|��5���ͩO�s7�9l�`�w�X��F$i�2�vuCkxi�����1+2v�fSq�u��4�/G�=4	1��G��k����f��[�'�D�.M1N�y<Ю�ST4�ʶN7��@҉O��b�p�>x��d�X�}NG�?�׷�_w�o��}�#�Zgz��������i��>�x}؎ ��L,N���`��fT��D��֛�ؠ�3�M�T�-��%*lN!�ױ�z|'+��.~�l��%4�6��$�e���i��ųq�$��	VkQ����Ϧփ���g���P���T�3~}�rO�!�(!V���|�BSÈ��q��������-����[&�ҥ\�*R:y�`�j�[��;�Pf&ٶ�m�����gq6V$���ydC��*7ۃ��zI-Υ.��x����0u����0��)-��!5�Ί�D�����lRM{E�o���i�	gQ�כ�j��!Ƌ�J�AHZ��"����d�c��$d�z9�Rzp2��Ϊ�Pa���nv6|~�a��A����I_V�P��g�N�W�'��g��� �HLM�=/����s���|!�#��`n�g/�F����uO��o5k�a7�$R_��k���
EC���N���4E��%��%���#*+�*�\���Xw�#��ݠ�< o��a��ҳ#���҂���B~�8��zM�2�|�^}�D�Q��/�q��G�::�a[܃����h��X�����`؃U � �V'4�o�d�>��N���By��֊��ZjD���
��+P���a,i��f�/7���%Daن���L��?ȸ����5!f�G0#�����a�Ѧ���U�	Ar�r�� aac��驲�����.�MLPX�?R��M������#��q@�g.iǸ]_����чJ Xǃ�H��麛�j�R0B?���2_d��d��,��UD�qF���������	:�U������1u�*�o��ʧ�v������?T�
��y7�w����-�=u�i�C]o^�<r��B x<�� i��;�ب�I_������v�t�a���Hy��Ǖ����0X���P>ed���� �����,�l��P��s��?�0��,
�v^~����q;L 1t��� � 1�f��ej�Yep�wԵ��O}g�d�Z�/��
W|~�S|y�Hm��*b���/`����c����܎iϭPQ��T�z�^ �f�^���߁�]�w�Nn��R������_}�=�2Ѧ03�P.&vm��U�1�� ��;�&�p������i���,��R����j����A�sDb��?$|�ª%�͒��d����K�s�"['+�G��W~` �rYa���=Eߘ�'�&����D	�`�~��Ә��3@֗��4�B-���HJŚ-O^VDa�����l���텄�hԣ�rnل�@ŢE�����ƞ�g� ݒ;ڴ�x�qwkB�S)����ƩȲ;��;*�c�,�ao�b�Qb&��D��ʊa���/��u�\�-��Bh\la�ǵ1���R0\�t�?�oOCi�x�R�_w�"�sR�eV��8��ɣs�>y���7'�1���]�t)D��䀫��y��c��P�"X C��b|�H�Q4�lSg�i�Ӓ�~�=�2擕aF���	}>.�q��.�`��O�F7�O��ܗ�o�d�I�xI����K&~	����@��`��/N���Aى���ʵfP�K�o�R�Q����+��S��s� �M��z����a��|���9@6տym��}�N���:]>�����-����dlZ���z�m���ݟ��{_��j�7=f1e�|U���� �h��㖠U��FW��T�S�6�i����V4,Ri�]5�� � ��W�|�}T�0��{J�-�ԣ.	���!�[B�i�IٝR�� �F�6<�ʱ����'~BZwq!BI�}�Y�N��qQ��d�ĦM��Z���TW�P�R���p��~��@o���+����[E�Y�t�[��vc�����|qo�5*��}��g�,�8��g���!��^u!�hrl�V��:ۜ��tb�/;m�69���2�A���U�G� ���x�'~Q+��<��hV�É��a��"OU��K�P�7iq	�����D�$2p��8fm�����˘1m��9�;�,kN���F�{t0c5T5\u��6N�dq}��m�\4�����9����Vn���g*��FQ�1>���4��ķIBG�QdJ(���۪��=^B���i��J#�`�j��c��s�I�cK��m!�]��t,+G�#/��I�AWސW��l<�j��=���P鬛�M.nG��:V�^$�ޢ}�9�#�.Df����@75���M�[���x@��L�n���N��W���wk^�˽	��.bB��\��@�:��ﾥV㡦6?�H�x�׌<��� al㽰`x���>����X�iȧ���[�&R�I��c�V��M�RG^*B�1{u(�ٔ���6a^h쬊 `����d��e��d��cZ�A䵏lh�N�a�� 	�xY��jVI�Q*�|�x���x�4����%�t����P�Ɛ��c�J�g�Y�C�z��.�'� ǈg�f��8��L8�P\5\��Z|'t����`E8T��1��r�y�P4�zA >׾b&|��k��~��1��?��P)��>0�]5�� (��p&Cmn&��bQ�lC�z���F2�����2R+?�mƞ��/������3p h��X��G������EX�����	����L��i�
�_���5����1(~�pkï:�w����h'�qr�-ٞ
�6Z�A\֢P����X���S
J
68�gS���}-+�[��D�R�6r���\�J�H(��n�uI���fO��o0)��X��)«沗�Ρ�7yP�6
���D�z���u�%��e�3������ZZ�L$EA���������?���H�~�Z������ʭ��Gn{��'�ӅC�s�M(=^�q����y��16�I�^&`a�'T��IH�3݈l	!Kܢ�7��酹*^n��E� � B)+�{�/d$!I��$�:֐gܒ� �PI#�G�W�+wy��p&.��c��7����=G�ˉv��+�S��@�zs�Z����z�U�鿶Z)�0ǆu^F�Ȟ�'��X4��I��H?��\Ǭ>6��X9:ݐ�N�[���'-����_ˈDD�Q�A��\yMB�(@�+���x(OI���Q��,ŋ�]@AY����� w�zTEͯ|�7��XJ/|A)�)wy�I9|/��%�����=��,%��/?Q'r����Zf|��.g ���-�ԣ�R������t9�5��}bwh�!�r�q���aǯB}��3k���]�t��3A�Ȳ�(��C��FZf\N~�����yr,)i��:�U@����?�He�O��g4,ˬ�8����pK������sLǒ&�^�$� �ҫJiY�3?qpFZ��iŰE���t `��7үL9JG���e]���f0�}�C�fz�3��-��뇴BD���� �w�b4Z�D�r�l�t�&��)�V���~����l�S�]�B����dw+Y7NA�D n����Ѿ��~Uy��P��r�J��u7����8)�Tբ���G�P4D7�4�;�,b���O��s/����:��+6��p�X�.3������)zw�N�����@�V��%����b���������V���<�e��ү3���e[���u�SH����c#�3�2p��z'����v-�喦I)��ٖLƙJ��69��u��I�|���ˤ��'3?����-��R���!4n�A�l�G�κ����Y��z�:e�R"���Ħr)}ӑ1�x���ƶ�ݥ���e�I�C���ہ�N�7hë�/�c8���X|�5���@��>����kə��eY{�=�mR�p�����z"E��Ae,� ��F��q8����f��i�� ���|���3����e�]R���(���&�����	ӡ�ݣ8x&��%:ۙ�%G�NdIgw�"
�(�Q��v!�Mz|C�D��ӎd�֬�R����f���]S}�A;���|��i�v�u��Bs�Ź{�O�հ��E��v�gf�-{�ӌ�Sy�1���_��v�;q�:52�Be����=��iy�[�3��і�6� &�M~�������5@�%QRx��3�x��g�ݻ�q���lɀ�o
?~�:~�.�@��W��-o����}�9�^ȳ�p��k��u4K�W	�ԀIi$�	�_���O��NJ�T8���c,��ӓ����W��h�ɍ���u��t�˗���߯\�*~v����vF��p��'�雚���UC��}��<:8{�Cb�bܼ�|�g���C���!���DUƱai�f�.l������|������q�Dꋘ�#zߤ�틁��uB�Mغ��mi���˟��x��7���KJ��
 @�{��1�Oj�avg"�\�J�UE��o��+��S�/MY�B��h}��y_��{+�9�
�^P�B�*t�LJ�4ψ�S�����Q�����k�^�?Ց�s+iA����	�U%U���r([c����ٍ�Qpw����V�%��pt�ӭ�#��1�����9#�qU�e켽Se�i7pt����O8�??Z�W�kR����緜"�����n^s�k�\F��l&m���K��C��(T��R�y|�����u�9Q~�c*NU~m����G�'�f-�r�3����t�mudX���i���ML`?��g�C�Ś�8|fC���o�(���]�7�'���>k�zw�S4��q�0����;�Z�	��$:�"�<���f�2/�^��M@p�����'�_�ّ�������k����N�?��3de�r��;R�E�~��q� s-w$��x}S��P@/2U�Z_	
��L�f� ��s�WA��F��u1�-<
��AFX���X�"C�IheLL�]1��*1q�J�х�➫Ŧ���r
A����G$C�B��T���O���z��i���nH&`�̫��4�sH����O��y�1���Hً���:
qƭ�2�5\?	��%������Э=�8|�sBp }�q�{��/h��^��7x��yu�y�H|tn��sm���ϭx��V7Ӷ��(�lT���3+���؉��IXu��m�̄���8��<3�f�=�x �ƥe^&~|���S�� ��j|��
$N�8����fxB�pUGB��q<��9��NF!~�Q, ��l������Hh�Z~����(���jD	T���I��j��f���/D��?t-��Ⓡ/�q�S/7����*��F�&�ŏZU~u�!ճ�l����)��y\ѡ0��9sg��֐F��6���G6�u�9*Y.I��J�y���F1�����F�l�[KeYjO��u�0�BN]jֿ{eU��⽄���;-^���zl����l혰YL!�d��z�55\};)�֭�l
%Y89��e	�Y���澫�?_���O����,�(F���\�L�40LI���|%�Q���E��5d�Hp�Z~��*�@�� ]e��D������4��KM��m�mQ't̘�o��L��jk���0sw@rnb��ۿ)�0���?12�Y9��Ț�q=����hc���?p�P�۸�h2� ���L��8�0��ꮲ4�i��dz�y0׎�Z>n.Kh���Z}W���o�϶�z]���;����my�40��P��zP|Zp��G�o�	�
'j~���W=Y�=
y3)0-û� ^�j���&as�y�f��u���BRZT$x�=�� �+!�=Ϟ���(T̷��(9�Rߋ��b]��0@ �Ѱ�%A�SCg��.�hNY���>�g�@��X�"Y����������ִ6�9��#��o���ބ�=�0\�*a4?�.�9C�ui��r���S�� d��R�0[�x���m�jv�Q�J�snyH�
<�xc������z����r�F�믪�'u������[�VP��NM�%���ߛH�忣YGK.��E��3|�饼���q�|�8�uq�6av���	�W���w�q�Ӓ�� A�4ċ���$w�����1CuI鋚dͫd��缅U��,�b��������KL���H��;�U����?y��߀���/���.<'�� �Iwq3w$�i��|������dm���E�)����F�g�K�D$Hz8��fX�/0��u=��'�Z���}�CA���ш�,I��(��n+5���J2Zw�|Mh�@I��1b�Aŕ�a���q�>�P�Cچ���Ҳ`Zv��[F^��<�ܖ8�Iơ3�@���:���};ea�R����T��+xf�xH���1��2��ft��uI�b��5���ġɚ�a�i���ZG�:lʓں���?@��?�fd�e�o��]O��#�n]���KD�a�c��9���(#�πr�q/�L}(���'�
u�uX�Pw�4W�@�[v�(/A}HoZ�����f�o�׊.���R�Pyz�Tf��������,L����ѷ����$V��0<E�<kRaB.�g�����qcV��g��!��Vf�Pz��z��3�NX�/SK��ҧ�b��e��繙�����c�����V
�ᆡ��hA�+���.F��v�~vFQ�s�a���X|���C��G����&�<�{�����J��r#܎%���˃?m:����闯fs��G̒��s����^�>�[�R�Ӵ=p�.�e+���h��_Q$�'�j�XC���U��Cꠓ-Ij8���(��tͅ�rd/�j�#.�����e�d�1��9]�;���s|s98�Φ�()b����0ķt�z�_Xr��s��Vi!w��h��o؟�G��<�G�e��ݜ�~j7-��j�X(�%�׳�	�(��.�o'?���}htl�9�/-��h��B�^q21.��Yv��j:�ob�2+c�ζ��?\���	��*(#��Klo٪�y�.ԍ}�m��+��X���u����O0�x���|���H��������4����B D~>��\�9��P�Î���oлݩ��B	їF}�i��e�dk1{[�����
|*J�`����Ji�S;z8�hc����-"�M��?w�H^��	��܂���],��Ðq9
�H�!z���J��G���$?���{]���-o��_�վ�u����?�k����e��SYR�x䋚�u�.T�����5٢	��YE�E,�C��N��k��w��Z�3�"뀥��II�!�ub���S�Ⱥe���B���U�"�WRv+��`FǇƽ�҇k~v9O�ޖ���i����w��s;R"a���^�H��u���ę��|C�l�7,Q�}��s��Ώ����ŃŪ
C��Hy+2��i��̘k�+P�1dra��Z�ʐ�.PlQ�$�`�uӹLb�3��_�I*0��_�|�u�������/w�(5M�fɎ�:����'�d�u*�����J��<�D�ť���_yn[!]X�0G���� os�����?v���M�#��(^3����-��_P��`��{ޛ#���L���+�uІJ4�؞�65!�s�NLZ�::%�/��Y�-�uñ������f��u��
���E�L��[��s0afIb>1
�[�]M������?�>�<�؂�)��5B�&:\���L��յ�iw)�4���6Nx°��LEz�9�QK�� �n�uD�˒H#�U�C�����C�5���٦�7�������ŹE�]:e�v7?�oa���f#D����J��=�j0�q��3������Y�i�% �=��K�� ��h�{���V �cC!ǿ��&6�MW{��e�Q�:5I�WZC��w��9�+%1׶�jOQ��z�~�Қ�|)�0ڒ�bn>yK�'t}<a��q��b�О�@-����oa���\�~��l�	</!�K��|�c��27=y�ZW����͋���S����.��z���7�c�4�BkT���8u��^|5�����4UY������H���k�)���Op�{��?�/�9���bs���a�������	8}o��B��Z�Պ��/�ƥf�N�������~s��C	�I�(�D�R��0�O�)r�.�'Z�L,띂84/eܝ�����Vaқ]x�!�O~o����_�"�>vNq�[�x%�QsԬ��d�Z����e�s#�\jj!�* P��"����m3�u��>k���v�9��y�g��l\�����[�}k*�l�{�9�
d������-�۩�����#��Y��o�:L05��5s���_��YÆ��B��7�^���5R������y�����穱���:c���CW�'Z��e�uOR��-=/E9��\sIݖ'��.J�j�՗�����N뭔t�O/"�o����¬ד�RQ��G�F{��ݸ�ԉ�F�h
�F�Ѥ!����T]m���c��k�H����\T�H��}���Ǘ�8�O�O�~��=�ٙF�� ��r�|���P
����*�+�*��z�)��`/;s�@�Z�8��<3(*rr�j�q��M�)�"�
�Q![܎����gF��O�_��?�C�����6���>է`e�t��c�tx���D4C ><�)pH�
Y�G��/���<��m+�j�W�w��["�R�7F�Y��pyPt1�SS]s�)fQ� �H�.8њ�`��~�R�ܸ��f�����=�W_��n���o�\yP��X^u�@�q�t��P	$E&61W��G��o��)�TS�����Wuc_�}-�Öƣ���Ř�k`#賑Zl˛��c������-o��)��[��U�R�呷�de �s_b�o��F�UyU?���艥ݓ��Q�r��pY���B�+-�ϵ��֔�MyѨ�Ţ��Fq�O	�u�?��zU|W�A�u��"
r��,B����[�����JL=�F�\�['���`�l�aU���A,��hhr+Plk�
�C툻���}7�A�8��;��f�D�贘I&� ��~������C/.%��<�o@��i�E�_Y9���a�E&�8�*zti�%0Z�~��-�a�c�U��S�1�� �{JdB_	��
���+�o�"���ć�~#0�X�]�F6������L��OC�/J�'�D��{��f%n6���<��1����;���3Z�2�%9�Z#��^���H���v	]�M1?�j/*����[�G�EN9]6 ���f��˞8�k�sO\TaGE�r�]���/���2�$;H��rdl�q�4a���-i��M�?�l����Ê�����c�w�[������TƋa��w�M�飯��U0�����m�oͣ�̠�oeE>Z��Û]�hNǚ+w�^(U�h"����e��"�[���"^*e�i��~��j#}�ꐯRTyUwB�9�)�y@��(��u��������Χ��ӓfG��%<np�7/��H�>�>�8���:/c��OZ��p���q0������'���S�j�e�/c@��,��l�U�哕���\[���F�5i*�Gͥf�KOˋ^��X7I^��*>��
���=)O>=��G'�R-��Ъ�2�b����hf���{��2 |�U����;�u/'	0��⟤��%��xD6�U���k4VM�Hj�QU�G�ͽ�iU�s{��O	��zK�s>�?��i!uY�l�5�U���@n2�2M2�y��W�O�,*�I�re���ߥv�F��"}��?��ƫ�Q����;��~�QYܽ���}l!��Ma:�/�w^WN�B�_!�z���8C��Wm�6a��S�1��J�yY��nw�J�%g��x0��-�|�=�����j )�vH	ݕ��5����Lx5ˢ}�$��8����V��9�f�	%�9��`x��{��zѡZA0٨�?7���O���_�{������y=����F�}�7i���X��ޣ���@�0(�E��%od��T��q4�Ɉ "�)&��&1�fTNlh��J>�����Q��TD��$[���-��I՞Z?��(�Nj��Bd��Q����4F�E�k%yU���(��������^��K8�b!N����ܯ�}��`��m�;��	�OC�Ά�FW%�;�Ϝt\�p }��*0Z�,(��9!��*�]��t�]�W�x�w������5xt��5����d�`$V�H�Ë��r9ܣtU�N��
���w���Y믨��/jH�1��h�
N�}�%�c��Ĭ���S���:��?�e~�~��;�I�|}�7z\gF��&�K��a�c�4A-��x�Z�L~��6�)BҔ(�{ѿw���l���d#J�,�r�x���f˥.:\.L^�Wɒ��`��`$G��Ș�R���m���j�0[/��:������tճ��B�E��P8(G؝��ʴm� -�(-y����i��Re9�Bŧ��6�jU���$�xX [��F�8]Iռ��oz��ä|� ~�A�2hP�Bc��k��{��Oi@�\2Ҵ����m�x'"��+�c7��V"5P�:g]}�i�=IM�>[�WƷf�e�����|���t�|L�o1�L�N�^�lz�ڟ."J�`� ���EO,y	��8O�Q��iv�5�@������~,���z��������\W�j�>x�w�g���g���6W���h�#���x��-'�=����h|u�=�4L*w[� �L��t�;G&R'bՍ���̆���Nw���v��pV��L2���T���e�aB���b<Ms�33�6�P��s#E�ȓ)���3���!�*H��G#cMM�u+�k��	�c�r#2�����������}�D�Ga�:e�]y���4*�d�z�z�A�+��'��bpGƨu׫Ȫ��$�z�Uz�V���V6��V_/w��j��I���k_
�MͲS�����D"Ln��/�Q��3�Z��l1�	�Iñ4x&�U<y^�H2G�v�f)�_�L�����4�2���%GХ��Tߋ�T3K�"9��Y�+������j.��fK�W�C�q4G�N<�7��Y�\͗�_��
���{�A'��C�zG{�=-I��%���N��D��4m2�R�_x=I���b6Ұl�]��
 �,��K*�R��B�O#�F�����9p��ڇ��ݑ�H��C�@!O�����}@�I@��Cp�&�m)7���d�8�+K�D�����7R�n������{4Bi��Jq1���B_k
[�D Υ\���q�os����!Q������v��`�f}WQ�ۈ󀆶����C�\��6�B��t��BҐ>\��U���M4�=P\�~�l�9��v[�)X�*SS��~�O&Tؽ�9�h����j�����҆P��`h�p�󌴂o�!L�#0�vL�Dg1]|����6c/5�s@�v�?�]�;��y���3m}G�.����������WE������f��I���c\~�[��`ќ�Q��㧘��Za�N�bXF���e�7�{%)�"��|����g�lq9Ɏ���0u%fJ�%��Eƴ����2k�f��1b����S�8 ��!�9޻5��q|�V�)�f%�8��ՌG��)���n�����S�	���Y���O!������#��.��'��t��:ah-����*��¾�Q5��1g�3�]5	@��cⓀ@!w�}�_r���_�`��G)�-:�a��q�;�ѯ��<+c����m٬�[��-����z�
� ҥ[{>n�iL���%a�������M�;���gސ�N��<��i1o>7������ِ�w�4Ľj!yWO�<̑�?I�����L&'/� �����U_&���#��}Nm&FJSm�4�/�O�I���Ŭ�W!�z]�c���2_�u�!�ĥ�
�1��4��yl\T=t�c��w�ǭKtΓG��M�oM�&#A�A:�&7�
W�����@.���z��[ty���]P�����J��Pt� �9 l    Dȿ j���s��=�U�
�12���JI�Л� �Lyj��Z��ϔ��+�S+f���g-KyL�^^�z/{��+�?��� ;FD��_6>�f�����(����Ii-^d'����n������F{���e����;��q�.���<`��e����3���D�&ܢ_,�e�jՄ!�O	�� @ WDEe{D{�r��)��������K�m ��@Q���0������]�����MlMl���g�Ck=�)*TM�Bͱ��U�Ԏ��������W����fO�,�Z�UL���WYK�gh��'�|U0����2͸�O���??��� ��AYl��U�xd�@^-C_ҟu7Fi`ىZY3�qR`v�NҞ�ڪR������h�=%���4Ɵ��?�+�<Ou����	�3��}W�����
�G��,��2�2c��t0k����ϔdZ�w$QO�����d>2��c�^ze�I/c��{e\�g�]\+�Yjj�>VY��\�,�x�)Y����W|9�YI*F���5���ai�[��8���O 俳%[�U'������Ԗ=�W�#��
/���T�{I�Ѽ��Z=^P�1+/�Ŷ%=�X|)c�ݝ�������	/��Y��'R�4�e���K�
B2x��ܝ�&����'g�;�*�s�V	�,x��P�������N�U�d�d]T�9j�
f|v>��31��ɟh~�+�6��=��}6��SQ��sec~w5���B��4#	ȃ���^�CWm�G4�&{N����mT&�N��^k�ۓ��i.�3��1��D�����6�fT�rʴ���僚o���T�ӛJ~Ƚ*��ݹO�:f�+2�FԂ����̤'?�*<��E��*��.lӎ���1�)�y4�v2���p�C�O�右e��e�@T��J#�d?@~�iI9qj6�ˢ�b%lY�&Z'���eK[�Z��jR�w�]���*��WA���q���Ӕ���H0�^����G��%&�`N|��¶~����]I��U{�&1��J �aJ	`�b��i���a��vs�R����͌2�b�,��6WZRC����Z����Y1���9d�����yF���u��F��^��V�JG�{NZ������M+�/?�I>���m��i�Q����8{�ԯ4gN"YY�r0͜��&呮�2�f��6�-�X#�,��i#	�u<�!�T:'EE�	�)�d4�}�F�r�{��wO�[(���s����o3�϶z��~>�!���<ۛ��hE�������fc�Ӧ�?KoQp�%'�"lg>u�Ώ��z��	�\ɲ0+l����?K�T�'8K��2��@��RB1S֏�� )P.ϡ�&�B�$�y]�T~|%2*�r���q�ߕ^�V���,�(C�"�2����BiO`q����dg������%[m�e~�11Y���mb�l�����;_���H���@�~�v�U�T�gOf�N K��$�4��zmT���)�&�ө!�ٛV�F9�l�ؖ�_d�+����ޠ�ʔ�i��_i�4%�����Hxi3��ð��F�g��'_[�J�1��\��}�zD� �)�/A��[]�-Ҥ��&��R}��SNA�P�N��@�C�R	��"P9j��h�z���b1d��C�rԥ�es�	G��(�?���j���1��}%#is����ޔ'�M�+~^�q��Ѿ}(�Tk�g�Ǿ�O��}�E�7/-FK��d��,�d����"�xl�����=�*76C�T��~�G�W�܄O^͑��݆YL<Ź�*ە	4>č&�{�����H���fx�'�4e�C' �s�<%���u���@z �jA���g��*���w�	����x���^�eR�V�Oe<5�L�b<G�eQ�
Y"kT�8Rq�Hƽs��ڑa_>��ѷ����kFR�������9|l�+K|P��o[�w��p�R���ƨ�����"i��]~;lC��=�k��crI��~k�̱��RXRi�7-*^��>؜�7��*${�Aͭ3G�����[����˻�tݐ�B��J�6mu0�6OΊL�63�G��69TdB��/�2n��bK����_'>�t�K����`��jX��.�q�)��3^_�Y{gg�������T@ˋ��Ɲ��x/Q���m�� }��F��?(;;���2�����Q��(\�
0�� ��=��d�s���5��z؄𘱃�;^�O���GŠ����~��H�����˕�*A���F�Owbj���}����`͈+ڱE��xJXX`�����5i��V��a�c��Y�k4`Z� ��(� .�T�GT߼�O^�r1�BN����u�cUH5G�з�5�͑��槍���F��8t���hfZ�w0b���j�@DH�����j�M���@)N�Ƽ��K�����:����	,��
1�eqJ.�GYܘ;u���k: x���$��X��96W0?��h��*!B���zV�:j��ˤ��BPFǺ&�	]Зc1�C*9%�zMur������ۇA�:/ARx*G1�j�N�J�&�ͤY,0>`�wX��:Oe	Y�2�z��<]���j�5��T����c*�P��[�(82�Q��d�il�:ېjF� �Vhmh*Q���5F��ȭ7F�	q��m#�lz�̦��G��t!Z���e�:��r��I�J0sbq�P��B�U��#&��Qך3d���;ɖ�g�@M�����W���$ mc׹H������4�L�F��נ�Ȟ�ϧ���Ǹ�wL��f�U����㯋�̧ �łH�[2�]�'�@m尺��9�{G�R_k��ܪR��iE�v�}��sQ��z�N�k8�f�\�Ǿ>F�� �\���`�NR�h!1��gt j	2T��0{�uw��嵚#� .�4cl��Ʃ=m�a!Ef��Hf!�1+�Q9N�L6�ӭ`ft��!��0f��¥�z*WF:�Wq�),#>dX��Z >HI���{� d�N�u�9�Υ)�FSqSv�T�*D�A䃩&�m6�D�f�����H�A�Fa!���I�d$|��Wa�xf9���)Z�� F�(�
��b��C��z����(z���@j$l�d����q3huu�c�`�_��j���S	���E����s��t�)D�.9G8��J%č�9��8/#Ft�ߣ+m���Q/�F,٪ʐojV!�2y�9J)�L8׵G":����8@g�v��B1�ڻ6���`P� �_sH5�a�ǃz�6\��Sz�
D�ׄ�Gr@��&�;X��<���&�:�"`X�xu-�y�)�EnH�Tt'�c:ŕs�QTYw� �A��X9)����D7��.�cd"��3�D]`��/'//�<�j��l9PpG��ňˉ��7�����a�f�8�:��� ����f��,��@
.�1�H��]j �O4�&Ŕ ������/03d?�9��S�	{�L{��_4L`�	&0��/�g�`	L0�&E���I�>��Ϳ�A;�4I�"ӫկw��)w����ZNQ�a�5�};#`[�����������}�-PJښ���ɓ��ch���v�7����`�?B��6x�H�|dx��O����H6H��GO�:j��R�2<�O��
�z|�	�6	�eBU �b������6��H�Ь��|�z��Q{�O�����c�����P�@Ɛƿc�lq�������z��蚒�B���A���.�4�����}�A�l�}1ց=�ׯg���o	�y�l���2�<���0+�Գ�3/=�z�0����߇�ׇ^���=�z�7;G�>L��#9��4![�P�Q���P-o��*^.��H���T�G���?�x_je}�|Q@��jޏ"_Q�z�}����Q��B*b��_q��G�/@���K��{�~_��>�}(����QT���򏢰��m�H��j �����c>
����(�����W�+d��`B�o��`EV�_�o�{�(�wG�`�N	la��9*<�����[��l)�Rz���|�d��>�9�s| ����1@���c�� >�2��d|��9>��|�s ��p�X��wo ~�-�ana#��F��LF8��W6��#��暿���Wn��^�-�s��(�;V��j���B���
�e��ųf&K�t9�s�(�|�Eg�!q%�Z9~D(�>8:���\��}
����n�|��9��M+�:����J�jN�'ϭļv6-�D������ղ��v�w��7&�Hm%��ԀV2w���x�[R6W1�̃���D����R[o~��u����1F0)`�B1�[|�E�	Ըo��^rl�U�r%r���q[p%�]��ߒ����� )%w�s.�o��dp��Օ}���$>�뢒���>�J�u�cc�����]{ .!����(9ehmK��݇p�/���.y�[�%�(k�.�?�JWx� ^b��b|Q+1����"�$#��/+Q����b��Տ��;G��⒯�a�^	}�$��K����0`��������!8�_�a���ƥ�q�+֖A:�g�]n���s0���?z`�N�z��� ��`�>zKW����A��a0~z���0J/?�M���ر��r>�BMV>%�i�\eU�w�-'u�� ���%��e̜�̽(�(�]�8B��&�fV1([�9t�7�g��w�sP���GυK{�8�s0�栃h4 $-:v�G�j�ڴ�A���`}��ߊ��=�ۢm�S o����wu��:�}�-�.� ��u_��� 7�|�z�a`����ͱ{f�!r٠�i|�R�0��bZ ��o
s��?�0$��˼B���Q>*��>8������wg�4��t�K]_�)���pVO�u[���2ذ�!ڼECOP��Cy(�qZ�ɜ��O`�2ش�4\?<C7�*�"Ġ�f��[	�a���Rev���qpB7Hw�k�E�u�u)��8�Ǥ�,0.Q�A� 7.���)Gg�;#9Ĭ�Q��!Z�\iеڽ�&̐�p-l0��pGtwWhXp4���/M�#�FqH�{�=�hҦ�MÜf��J�۳�dV>Tj�њ�����������MA���?4kj�$k8������<��n(j���5b6����Cٳs�k�)m�!z�����nnn�o�7h��ƪq����� >q盹�6vm��ܲ���m���os�fp�������2�d5���	c��r�'���R��bp{x���Y�sv4֡Y�lc�A���,�-�B�҇蔻�7����Tdn;Z7�n����#��0�� ��]�;I����,{a��"�A���3燅]3�#��;�"b!���fJ��͙��(�Ckd���C]��C+R��n�dX�^�,�!g��Ȇ��%n�ͻ"��<�<S��]�;Ր��z�9��/@1��9/|�(�ߢ�	(Љ~�ɖ��8�!�,�cNh򡾱��a%�kxn1n<�O��J).�X/�?:���x`�r��Y(�I,��Cǣ�7�r�z�����t�ٳ����8��DB�!���#@�{�VΠ��q�q(�H���� x8�A��s�d�KS��E�H�0�#�&�I>��$S8���Ġh�л��aR(�ɝ
E���ቅ\<�8x�6�2�������3�8�v��&h��~��\3+u�q/
\�Td���S�E.C�%�a)e"�!��))
'�D�_2���p���[d�.CPz���,8?D�PL����))���p(���⎊DrdŠ�e2j0�
�勊	��p�C*VL�@�32�P
`8C�V��0)|�B��9�b��9�Q�x2g��n��k��c�28�pt��2&�
�ސN.��pn-���W̊��Ў6��t��L��br���d��0�jQ��ɒGx��T��`��Q�%�%��7��DG�<����+�n�<����j �ǒUݕ+JY�z�b+���do�։c�rZ6ϩi~e�޺�����4XO'�M��<ʗ��;G���r}�Gt����v�KtFrr�J���<�Ả7�{c�7[��%��v��]WX8�C��!T��5�'&�Ev��)�C:���o�ܢF��@d���au�%{����>�������PX��ސb���"J`u��s�9�]�3DBa�Յ+��r���ɽW��*���b:�\�$I����d�2���&�톔���Fi,��l���Ұ��Z��вڼ>�x)Q��ќ�Gzߨڂ!��<��ۜ�������e�΢����ҡ��W�r��#7��F��&!O�(��k'K_v����X� �U6!    w @���m֙�>��br���Ю���R�v��yWWC�#��H���#=c�Q鉱�^C��-1m��,�H������ p��b/�̖N�_Oȩ��V{_uέ��U�� q�=-��a�S�D6��'�X�k��˃�I;�����v ��)i!�?�r �*���c��J��ǰ�W6A*��4����E�@U0UEP3T�
�Ͽ���!�Ax{��!��5;:�(.]8�$BD`:��P!t�uO���l�8��p�D�-�T�<��`��R,<�X*������d�I�.�w����zgzy��uY�sz����u����+#�2���rl����cuٶ�z����nxq���p|2�*�u���VD݅o�8�d�d�]�.�vZ/|;ᗄ����>�����a�b��b�������Q�ay�z2+$���oy�3�3�B���4q�B�� =���/+����H�h��8n�F�F��e�{�!q~r�%K�﫢��;�	$8��JŦ���{�<��p�wD~�p�A%a�e��a�b8��KI���<^�8����%U��w���V���;��w;\��X��x�nb�x�6�q�n��_�0���y��������=������K�7ր������0"�F�FrG@"�F�^ۿ����ቇ�P&�����p�*���������xxh+�?����7�a�gko�Z/��?�Y�Ǚ]��y8.����!SH���p/�>����͈̈�h��=^.t��V��5�5�؈ۈ�,|#j 	G~_��C%H��R	�	�U�4�.I  U�J%��^Kz������>����Å	�_
L�'
n�a!L!�޹�}��Հc�c�r��,��q:}��pQ9��MSH��������� �VH�3?"#+$�)&n�[����|8�l�GT��^*1���z!q�Z�0�x������)����F�F�L�� <$��_¸���)�*	1=~�#Q�����HUH�P�ۯ���N|��jW�\x�E0��\�/;�j1}�{��w�vI@��)�̏)�Η� �!�C!�]!�gk���o���yL�p;�������לH/�Z�^�x`oO�
����b1�1D �d��!�%�y���3b3b�
"�F4�d]+����4�4>5b0��NrG;"ꃂ�<���6B6�q�!٢|7S!S���`������̀U�juj��r#�����.�v����{W<�w�ݗ�Sĳ辪8'�oz~�c��u�z����ڼ᳞�Y�
-9v�㣏!�-�-S�����᤿�R���z��҂�����f5��%�j�[��e\g�>�~���8�?�H�^�u�]��X^�˻�ZS�D�0�"}S�<�7�0.hl�HW%U�W�rе���z�?o;10�st�V=J�9��JV��: ya�Z�_���@����
m	�����O�R���kG�r��eL� �%�,@���v���^�(�� .{#�F�r� �ym����x�\U�)[�����@P��KbE}��5.`o0l��z/��[֫�b���M�&�R2t���j�9���M�|R�T�:^P��O�%�}���y�	��<�li8r���4�ns &�r^�ϱ*xP W9Dk0��lA�7�f��]
y�ݥ���\��&�Q&��sv:5��{\��;i��r�� 	T�pk*{f�T�>,:r���~�ɪ�Uo#9?���Y��hf�������֚���N�VP���3����`ﭿVn��m'�Hm� ��b��R:O�խ+���a�$Υ��,��-�#fit�2(��F�C�٧�h�2��O� j��A:�S���J�3a�v!
��Ew�(��Q]	Q��:�j�n�,Y��Z�5����2kV�r+?�Z�kh�>-(Hp�h"� �B��tR�6�%5Z�ͥB�u��F���!/��#� {�LX�e/Xe������M��^�`�_�ڀY�1)3�6�6����>�N���n *�mއ�	�ʉ�5d�Fn�m+���k�W� �m�s�4�� �"�dj�ֺ�M� F�t�d��n@U�bN:�����=X�h���r ���ZC���� �Ȃ�(<߾L̵~t��_��$η�~1���������< � @L�c�&g����m)��w%I=:�`�vy7fd+oO_��5�������k��5��|m�*����JH����jӘ���o�aY�챝�W�-�+ge�2��#<m�l"�n�o� �fd�
d<-�y���m�`|��y\|<\��P�#Ou�Zc�e xnV�����`I}� i3�j.[Z�?�tZ�8,c��>ڜ��+�K��`���O�)�};��Euch�8�|'����P��N\I���L�:�rc���/��
����3,e����ʰ�Rz���u��a�'�VNg۶�j&]g̠���<mF@���6�HY���l�[3�g��|�Lμ���ӈ�'�������j�&������O/0l���"F{�g�� d��a�2 ��x�^���J��K6���OL� ���!7�
���QI�G$o��v@ϏN��ČA�2P�^��sݐ�qo;
���r6�r����Ьk锅���fpX���A
X$����jd�\d����rȌH~�u"�LmQ�j�9�"Z�=���"|��З��w�Y��&T;�>�s2��Tr��^�9#� {V�#�0��Gs �=��� �������RSH�)DҶ�����a|R����4���	�8�NNݎ]sf��
��M��fճÆ�d���Yb|Yz���M�|漫��!rX��ҿ����N������Ą�R�KX�O�{�_��B����s_ +S��!\�so�e�Y809�p�Me�X��}�&����_�^{��RYꭚ�XW�θ:��g75*.B�m�JH�A�����M��c�$�r�#xyf��q��O�^���1������(�K8Krt��,�=���X4� ��0@M��wF����ʺ�W�ˑ#S"�w���Fw�5��{俗F����(�6�Vi��x�`�խ��C_I�� |��~�w�Жq���ԑO8�(�LĘ끪RW/�������Rj��Kr�%�.�9�������5)
j>�@����>@v��4���@���e�8g��;|Z0������q���~��4�����l8��Qӗ!m���0+g�P*dT�LD90򀽀�jh�Np��-Қ�H�JւU�����@'���୵2X3�zکi#c��%����Oul����U-?lR_༲�r���Mʪ,�5Zl�R]�]�@��XB�L�{]RR������C��]���0B�����C�X��a��ߕ�f��,K��
�Y�K�r�.d9�Bf���\�S۱�A]ə�{)ʉΣ��ha���}�8���ƶ�^pU&7b'}-�&j�˥È�6$�4�9د���������������M4zW'Q�g�Q�	�Θ��M�A��ȣ�MW�9�u��"U��I��4s+&�ݟﻍ^����v�9�����N_z+/X a�j�@��yO�W�gi
��YE��
AI��d�ˣ��S,L�Ew-�
���6�Iu.��UTqYoLe:%����3;�
c@��Н�{9�!1�m�a˳jFi�0<N�+8\Tfz�y�,��U�E�tjǾ��YBQ2ތ�ђl�6cBe��f^�ԛ��E��F����n��C���{+\
qJ�]\��6Ğ���B�5`Ԋ������}2���B��y�
o�/34�0M��Hk3
ک��6�P�1M �p��5�'&I�0����W��6�<
�9F.�QX�'�Pyŝ�|K ��M|K��_�Ny=�?�{���"ڔ�K��B�7�%%@�u�l�Ox��m�ȃ�O�d��3�ŷ��D��,�YX�m�b0����������Ң�ak�N�	���:S�EG�D��qv��p"��y7at�1%mPW��S���p��d��:�Qy�2;��S�N���a�S����s�R���jڢcF6{�^8���[S:�A�T>�DM��	%��h�N��/�!���0/j5	�A�r�=���I4��s�>ݞ��$͓���D2*�I�>�W`]G~�7X��5�k/Rl���z/B���fr0�;=�B�Nvo�P��57\@��N*!m$usIXD�
��wȹ pS0���7غS]c�ݎ�b�وf��th[6��Z�I��[j�9�&;�_T�'0�EF��}͖�5��a��|�[FL�㙟Lx�'�>ː�$w���vCQP���:!훚i��G`��:e��ӘR���H7������p�=�
+�1F�������/���u�*� ���Q�JȤn�n]ڏ��k�A%�`)`��z�?�]�@t
�����+�b���1���V�?�}E�r��t��t�*�,����ud�8����E�o�"� ސ6�:���&P~i��p��.Y�[���L�΋��A���hG�F��p?|��������7R��D�5��U�
�Z��QܬBg��Gݙz}�OXԃ�a��H����ͪ�=3,��*��tf��T$<|�.�i���%�1{�!�4hJ'��{��f��9r�B*7cbU�Aï�ғș�K��#«dF������4� ;kj_CUU��'&�%b����wJ"xZJ7V]}�k�a_��X���Ӈ�� �� FH�XhB���i<��^-�N[&̬�X�k|a�G�	�_ͨ��F��	�9�s��]�#Y�P9,���G�,�x�G�Rf�GMfJ�Rd-3MF3����l5@u
�#������
O��.R�KLc/��q�j�5��^��eC[�d�gX�I}�w� �m���gN�	�f�|oR&���8�k�m��O2>���}7��=��Y��y&�,i�z���F��>j�BX+Y5�~]� �ǛD��]:&pݐ}k�~���י -۾�`�)L�p��ep��f'�'`��D,���"�O*�%�CR-�D��L������/��yf'�p�ȍ�t���a2�)��M�t�Y�OuX'�f�6s�21M!�{-�����u�	5?���G�~S|�z��*�`A�	DN�=rr�����K�=�0�H����"�UˢEL�<#��?n�����[�z%Yh��B��OU������R���~�"�h1,Xϝ��5�5R��{1��	�d;��&�a4`���f��30������p) �І���L��0ԢA�:.�]�X��R�ldd���%`��gv�lƅ���e6� ���9�����O�6��s�����#���.g���{�.V���O"�eP[yv�*!<>���5s�WSʎ�C�K�+��s
^���-)Lhϲ!3����W�i/K
�f�] <DӢ�s�?�IWNk��;t��іĪ��u�KTS���|]v��RT�R��(u���[��dW��p[��H�]T��c#�D.� �.���ҸG��sM1�_W�W�$AWP.�Oʲ^�����}1�Cy�](؇�^�F�n��w����z`����_��� 6u�K�9C�Lo�1���C�������T÷Fݒt�A�Fg��
�b='���@ z���n�
GsNO��E{�~ܴ�S����n�>�`?T۽{�A/N.��O��I�R���K��SI�=%x*�[��{�}N���}��'<�?�)J$"/ts+��_*9)GsE�-��m'�#���Q�.�ϣ�vG��ڄG��-[�eW��t����I�O���\p +���*���7�x�/���o�;�D.�&x��?��!�k�^G�i��<��=���.��~�aB�%�{�G&��+�\ǝ}��\��	�¯��+�(�z9���`��#��N-��&�:ߧ���P?NU���
P(.������$Z�v���p�5�ǫN�N��c'����
��'�T\��ǽ�{s��ߑ<A����~3��!�ڀ�u�>�a$���ӳ����Ѿ�����Q�%��S*�����U�|�V����P�]'��Ƽ���o�}8���,�h��`�M�7��F��\E�����"�)����=
�P�?i-���%������2F|��p���B���0��Hѐft������Р]5�)�c<���ީ)������w�G��j��~"P���,g�ŀF�&�*�PV�%�y,�[b�S���(*,�]+g�6H"�ޞu��.�%�?i�tB=�O�e;��S���o�}(��>��ύ��#�es~�S)�`ޱ�m?bޫz`�A�H5�S��[��!�����Y��[H܁�N8�B�f��k����<n�;^L�\�g��S#{��|���4�n��8�x�;�zh����Egu�;4��~���"7��2��\�Z���'�U��R����ޤֿ̂T���
QH��2?O@3R?��3P��:�/5���+Cu�3�]4^&l�'T�qϳ�'R~\8��,���pO2�\�ĮӺs�\���\�V8Ė�Ś���҄v1M��)jC��u�(�Z��<���aB�S"ݲst�k���!��ԯW�4S�\���u������»�BvΤ�^ ��*����!�����3���s�H_.gp>����?�m���*��ߘ���a�H�S�=�#?�5��GD�uЫ[�����+�뉮P7N}9 �p
�ٌ����c[�萢�aqǅ�S d9�dY��:��jh��y~�EMK���~���(�hT�#���W� ��lh�4�!$�y0SX�&��s��
\�h&e9D�$h�Χ��I�Ԑ��]����ֲ����xǣ���3��aD�.������>��������h���~����dݯ���q@���o�@�N���'�
:3�ɜ��X7S_%�	=���� 9�c�f5��0*��L����'�w�?7��'��0���,nAg�6H��W�����)��"��VN�D��B�4u������C��\�}�� �����āo��)�I�vM����Q�����dBG�<*ʔt5��O �u^�p�Oezng'�T7��gş*.t��3�� Hx�:���`9FK����e�;jk��h������Y-T�,ds�U-O���ÆWT���AE~΍��-^@Jk(�<�F��=����o-���k/5�p���J��ʹ Q�tE�]h���j�V�)�I���(��R�$.��s	�r��
�B�۬FNѧy[V��^b�z��{��7�<��nQ?�W�0�'��X�!�,��7�1M��b�gy����z�L�Ϣ��_�ch�"�w��5#�7���<�ΰ�6%���i����`�\�cZ���5�}2��|��Z�^x"�����0����x�~����9�R�38`�U�(�ѳ�OU<�'�y�4:̓�95�S(�k�EW��j&Ѿ����NB��M"����km�cǿ*v[����SM ����迡���u;���dcrx�P�>�:o�#>���U'���0�F��(��/B=d����M h��6!�G,_��!P�ީ�I��cqz��}�ա��wL��?��At<������:*6�(aruK�o����v�m�ܤꦹ���y+��)�%���iJ�]8ں�onVLB��OAk�����cK
�{:�~���vt(�y}X�����!���H�N��zxЫ9�Q �c`K�̪es~"�~�:`�9<k�O�YU�N57��K���$�fat�\�Z=�C����!hqyކ�z�D(���W+���p�V�3�'�ݏ�x��xN-�����(��1�����O"��x���f���anY�6��b��'������Ts���c���gͳ�ܼ{t��!�[y�y�ܹ����Zc_��߁ Q
���k��Өx�Ȉ����Lc����g��]��?�	��i{JO�]��Pn�|�/S�>ٗ�c��}�H��?��&N�$9��
'���Η^E�%T�0I�x/�?���ln����6g_"���l�?��3b
���ӚXo#H݀8�I�,Bd�i�dg���_&_�����N�,���Ǥ���ocn���Li����@�/t�J��u�N"�lX�����}v���X�P�Ы�0�*�vn�)4��B�*\F�������:���4S(�	<��Skߴ?Dj����i1}r�1�H�C�<�q�SH�j0�ؒV�q�i:�d�.��y�O��Tvh�kT] c۵����p��"o�j��p�����.�o��I6���w�d���XB�K�cw���MK����)��`f�2��^n�7��b7�E�j�3�Rh�7GK��S��T<kd(�Pp�d]�o�_w�OkL_�����M�ԓ�B-�J&�����/3��0�T���0J���`Y!�3�����/d�i�em^�h��C����F��YJ�;�w�]��6n�G	���e�}��ڥ 1�/�WK^ r�pE)�:��vn1�F,<Cm�&t.#L�6��d�)�ut?�^��Fpp�A�ޒ�.�e���Y�N����2�XE�
��u�q�DHK}]�5O��X]⵴dj��v��dK�u�٥�)�ƌ'����Y�-u^��i5���._Ɍ���cn$d�Sb�ɴ�k���teu��C�C�y^�{��~�\���@w����,�1.�+��JQ��]e���ET��]�CRr��.�ؒ�V']c�:O���P<Z�Q�^3/c0=��ezŔ�E(R.�f�'�m֙3��ۯ�`�՟�{Y8|���(�f	QG�B�|B�M�[��d騞�tYg�YU��+���T2a�'(S�f�o�v���ET�����,~t�M� ��ň��kz�N���b/j٭�Y)P
;o�?	�.��9-�hG�+BT�d?B�h����@*)H%�c�_����ZB�:�7�F����A�p<Q2N���5Y;>G�
��D;���.���rV�t=	�����0P�Y��&�#{jڢ{��<��~\�p�E^�L��O��Y�7��r&x(;,f���k3d.����/��m����Z?T����<� ��l@���Ol�|�	���'iL��O��)� xz����h��@^��l�P�,�aV0��V|4�g-S(�'�I��u�\�|;X��|�$\-��@����������6�)DCeܧ��v`�i�\�Y�i�2'!Rr�i�;�a�q���Y���bvV�]1�[�[�g�j'�� �������l���>x^9��q�������ݨ{Ғ������O��b��jb�B����/�$u��ao e���^ܴӧ��7j��T|>���~�d�����Y��)iMt���Yu���Kp9nN��c�j�_�Ad�%7��J`h[�}3��
m��7l�ϒ����e�=�W�  ���$wv&�����E��}	�|l����?��|��6d/o���j���r.A�ү�(�B�+B�Ǔ���������C�O1�e��K��췀O��Fl�BM2��ox9�ƿ"o�����J���sJ����J뻙��t!lA�*e �85y��'�[t��M�Fo�����앪�mR��S}�U߸0Vd��-H��X��sʩ9�H�h��/tz^�9��BE�����ԁ	��٠�,�8v�`� �=��Fi�}GO�5p��/`�	����,��`�T�Xt�|�M��Z��J����O�ȭ��9����^;�.����aU��9u�HE�3�-i��k�q�F!�ؠ�udBY+2�h0܇.0�X��[�Q>���u���ʱ0)���c,����Q6<�݅��+�ڶ���uJ�qZ��r+T�cY�}�Ng��,E�5��;ߺ'%���+z��>��ׇ�پ���ʤp�y}�lE�{ou�L�*�P Sob��ר�X�^h���':dJ�qj���L�͇$E�f���m.bU��� ��Ł��n�����8B�Q���(�&jB(P�� ��S `8Sm������!�S="�I�0�����]pv�@]��b�9.9�K�؉\�x��)�&K<P��pM?��?��R�x����{k�ݘ)�]�Y����&�K���K����7LR茪*O$�K��l �DG�eno����j�[�%�>�r�0�+�5�6��R�,�lEI#�Xӗ���K�|���w!��Ɂ=��C�29#�a-'IB��x���R�o�v��3۞�ܻ����z`(x+��3�1W�,F�ID��a�@1$aSF+z�[�Q<WL�F=Ev�i�Kج-�ʀ���~�Wv�&`��s��OMlci���{/�����g�@M9{7Z+x������~L6�O>��⍗'���G�bn{a�X��T9=޵z�I��I�o�����3�+��)����/�?ʮ�^�x�왔�Ѷ=�s�PŽ >������yt1>�v�X��gi	c�@���	N8z�0�$�.�O-*r%�nwm�k�O��(00�P3�6��Z��3LP��KL �:#O"�9�|����i��2�ɿ���(�;d:�m�83V�Q/ӏ��zI��F�b��q���Y^l��K�M�M.N};���5P�qʹy��|�l$��K��F�%4�Ј�/doO���F�"z�zO��T�a2s����A��wPO���	l�5q�4�^���I~�
4�/�J��գ?��:3J��(��RQ�P3�3���%�����R�]l�Չ�IN����K�p6�^�{�4�svmF��^fv��2[������=��YT�N~���6���Su]��l��6�ϱ�'%�ۖsH��s��	�Y���{��h��۵t�N�G�sY� 2�Q����9�𚞿����k�?��,��<8�4�����[�a�1�����|Q���bI��Y�y���-W-���=Q������n��N_�q�V�����\:R�0�����������'NP�/��y6-���k��i#�k�m.��%afw��s���ؔ)S����5}�ŝ�R����5aډ����o1����*]l�(\Kp�D��vl�/ w�2�����lM'���P��"��(%�I5z����l��Y��ܼ����l�L� HB�ԕ�j��2,z���P��=g�K�s�����2?N\Fk�v�ݔ?��&\>=�r@�X���� L��r��>�tw^�>9}���+�����P����j�T�9A���]��		?=!���.0YJ4���г���字$P�U�`%� 9�iH�b�2�M;k"����Oj����mN���_ �u ��ܦu��H���:���Ҭ����|����=���^�E��a��to�W���A�D�Y�5�%�^k�Ϻu?&�]��Gx��b��魅��K��Tl��k�*���tZ���T(�X��K�ϊ����w���TzC:��5��y QY�J$!���J8$�m�4�q��"B߭3'���(¨�+{,t��XÝ�Sc}���8��Yr�n��|
{E�����i�T+�ȯe&��d7����0�E6�_I�L,� a�t{:�u�i�bF��.%���^V�tF�${�{=���@7�#�n��Cn��j<���@�AX��Q���pg�6��Ek}��\��&;`����)�a�5�QJ�7[t[�ȝ��a�.&[.j
����f��i��kJM*֑>=3]to&C^1;[�i
�}=�-�6���oi���Yu+�I�VE�}���je��&]Iۛ��\X.oJ���sD����Q@NV����Q�]�=�XU�қ��/c#�/��q��qR�M͔���ƨ{���ZB�dê0>�,��z���ʔ�hj��*��o챃��.��3Iɸ�<Л8Ɂ�[Km�S35�<ҭ�&���U�ĭ��KԨ;^��K^`"<�5ߞ_��¸�]�\N^m���"qN_SQ���7B_�*�Eh��K��&�p�'���pԲ����-���u���fp�f�Ϊ�f4u{�3������)0�5�+��6]J�ט���kn��
�2�%D\�ti��z�_1hu��p�a��d��+^��]oܺ�b[d��E�{~�����.���_6o����{�}���������q�h�����_�s�G&"�^��;|��Q��vc��;r� e��:��L^��;)ӫ�uT�GųX�i�Ğ�[�d/��]������]���\���������mU��!J8=��T�G���'FLe54�u�j�֞�%�ϕ���7?�]��������d�Y���	yjFnv���X��y8s
�D4&�5#���;�7Ak���E7㮫t�/� ��g"�$��tI�G�b��n*��T�Tͣ�^�&%nu����b	�I�w k%��������C����6Ң$�X���О�)�rg_ /�|7R¸��GY�W��
U�4*2���dUOC2|5Z��$���� �>��/�bR1~������6BB!��F�h��KR�"
T��T
Q�Xe�'��L����@�<��[���H'ԡ�݁�t�o��/�Ī����f�oa�(Z*Y��C����̟��sI�W��O?�۟p����ݢ�[���u�5�C:�T���l@F�zu�TF��
��U/Rl�X��&��[Ќ=��p7�g�q2Yb��Ip�p��A�U�ߦ��_E��D#��	���0�I�QQI� 4�Q��g%����� 5��,��2����Lc��x���`b�2�(����S�W��z�dy%q݌��X`"�;�z����qd�c&��߼O]��So¡�����}�1I����b�-Q��� ���y\�,)DO[�r1Zr�E�H��_��`*Cf6����a,R�*[��Ȃ��j�$���=N�T�=f0W���g)[�H6ϼ�h��2�AJ�-�,j��n�>ϬU]�W]��D�c��������UX2���T֨n �7��I[��U))�Mq��I�ѽJ��"�C�����{`�ow�#c� >@��Sv�(@x]?��菡�s�b��>ZQߡX���v���?�E�5�V����mBSn,k�����[�%��7�84�%���~X
���[����E����G��\�-��hoR��2#���O�����?Qt�H�A<��g؀��4�v�I��M�����8f���EG�l�;��e �yK2b���Kb�y��t��EĲ�{"��m4}�js5�'�q�w�VHi웈Gl
���+�M�����c�고�;��hu�o�1;�=V�">D"�<�p��o�lg�q쿊_�Cs*�����eMʓ�;�}�ꉀ�ӧs���d�#���?#{4A.F=Y�~)fw���Eϟ9n%��K�RO���f9�)O���"���-�l"��=4K�"u�����Mw�Ot\�G�[c7��aF��t1�(WC������K����i��R�{����n��){��1*R�k��lב)��]��Q�����t�E!6Ɲd?���w�_b�E�� �ҁ�̋6*��C�Ř Mt�h�c�KcC!����P �~��#�1W��czA�Y�C�o��qtEn�8�f������Q=~��I��@��ߤ�8f����72�!lJ���?ˉ#�l��I�}^L���Yˣ�ͅ�	c΋�΅�蛛�)�8Ǵ����X�G�ډ��d��RT�2�y���$�}�冟���s?�}��m�G79~�p&���2�h������������п�N%}���v��Ew�N'❨{�%6��'���b���y�ڪ�>I�N��:-�o�aXE���R�4et���d�{�cv	�^�����A&�Q�������o6c�h~yN�cx�ɪ�Pc�z����
*>W*�mi%O�!D���������Xo�؟\+����v��L��;[(�N�}L�����~�'����s���Uw�ˎ��G�U�QI.C9R��s��f�QQ��|^Ooy,��,���;j	�ўo�t�;��Ʒ�b��y!-�h��A/��+K?��� {�6K�(�	��f���f�sNצ������~?&y��G'���C=���$r��?���d�4�M/;AlLN��t���;��q�y_�U�#��{��>U
V~�W��Z��u7�:����>	���r:�lj��bH�,St�9ֳ���P�6W�ǁBx�r��ɞ�h�N�Q�>�qX�w��y�ףI�_YH��,nxHEc)�6��+��F�ǀt����qF=��Fn�z��	'�=����6y��+��k����_�����c�Q�T��1~���䪇h���E@t��L�p=Կ�8�|�-8%�7�=���?[��D�h<&���.�7�Q�;�s�;X������Q�����E��+�w����#�����bH�g�%Ac1�;Nf�-�I6͞j����G��|��^��^�Y�#i6|��`�S�gc����  m� �D E `  {o�����O��+na�?���QU��%����}���yw�{��o��]�dM�F�k�[������ːh5�̡�h4��� ���+3 ��uJ��=�u�V~AO%Z�M��luNN��aWwRQ�������k��}�6�jvUJ�9��e�b�D��m�#5%M$>F	��@4  h �F

o��q�嗭��܄r�! ��]f���>�oLg�j��ޢ����������+(�5X�p)�#
���qc��@!�
�����."5:݆@���rX���^�X��5�i4O\�WKT���z�b%���;���7ci���x�ܱ�|m�«@չ�cJ��CJ5�X!�ʅ��P6p��kJ�8Pn2��U��T��Y�f=��:	��B��t�cUڔZ|p��cҌ��y2j�"�vC��J�l$S'�,qʓ�}��%���Fz2Ȼ��$e��,Ô�	��V]~��_�=jE_2o/[c<��� A����m�D�GNMo�$k-�����\�I��.)���O\���jݱ_���c�v����	��e����B�Ic����F׬\��w't�.v���?��4���T��)^b���3嚆gt/�U�I�1���DL+�R�K�Y~�dkw��FX\�n8G5���\�ۃpN
��IXh~�j�5�]e&�T�O%���B�m�S�|u�[�W��_���I楍OS>6���'$o���!��+�r��Jp���D���\0�'��YW��#Į���>Y��E��3.H��'ke=-S{���#{�̑��7������9	QJr�Y/G3� �,fT���T5���2:%s,���"]"ǷJ/�H��n
n�C�Xi��ƪ�ph���֪�!;�PH�>�F�%cp���	58]ߨ�8�(V��7��c����2w�X|f�
�R��Wxr�$��U B>>ø}�U֏�׾�!@}��N���; ����~��l��ˠ�r�5w���[X��TsC'w��L�[�-ʖB���;WsPc��p��a����c\Ǉ-�Η�r�!�q����8����I�3��S���>�zF��g��o����ݎ�iC��L��;�tt����+�-�mk�m¬��HOO����R٫I�|��[_�x��Z��Iz�������S�ν���d=<���v|��m۵s?Z�2�v���P�Cύ�xV�,���W�X��xn߇C�1�7ת�`�]�!���#�ha��w�op{�����T�U�-�}�8���J��]��`,x���Zk;�x�X�8lG;7:Z�W�s�n's[�����yϰ�W�F��ӵ3ɾ&�R6�}���]��<p�}��z��?4�4�f�'����#M�s��~`'�~�#�F�Z]�B�

H(�6���C�Q��U����o���i�bFrb�w�@���vݯt�42�B!��58.�J���"�T��#�ڠ$���qLԩ�O�=��Vb��2n\��ٷw�ȑ��טr�R�敷��VR	_��_ ����c*��TQ�P���Kn���
��a����@:�@�\R�F�w��m݄��V�k�g'Ͽ��y���ʘ�s������۞L��o���8�}���O{2z�-�Q��q8d��������w���z�}���gS��D�q1������������Ǝ����%[ǆ����o<��l�*o�����GGGGGGGGGGGGGG�Gp\Ɖ���b߁�/j��k�k�e������,9s���~p��=�>�Xl���5-���?e�6��Z�r`���5t$���`q�e2ޘ����|��igy��r��P��=�00ؙAb�Χ�eo0�)b#��49��o�Η�A7]Y�c@�@۹)�%��%6���,�bz�����L4��V�Bʽ�hwЫ�9ϻ
�;����S-Lc9�ܙ6�A5� ]�=xk��@���|G�?��;J]�?y��pVd�2su=b0�"�l��zt �c���[+ߠ��:�Py�l�ށ�p�@a�>'B�����������$�/>_mھh^�f��q ��^L|��/���r� `��AB̘�Hc �N��i��I9ms4⭨��<0�E��⏼YLZf4n�|�"|��t4�����n�9 0���v�Y�#��x-��f��I��]� h^H|vŇ��lΑp$� t�t`:�+ ;1m��� f2R�)x���r�V�g?;�e�2�Il���P�`nT�����;7�v�f���֜z�{�M��`���_t/O�?�v`��b9�it �lj�j��{�6δg�O�ξ���j���ȭ�C�[V���_ )�T�
�Gœ�rO�c�-=p~]X�jl
7ӽ-��n���4'��F�/�j��4ճS�o�_g�[WfWN_�r�vq�����:��g0�gRሉL4�]ܞj�>Y��g�4=Ͽ��t��������u�3��D����<κ�y���F7,���f	ޓ�-�m�ʣ�.?fR��rTj�:��)[���vն�G7��EvɸB�R�����S�b6��m���Z��,q��\��b7�U�ضJ��4�AB�fj�<������I���YZ:��t��z��]-�E��[��B�U�N��7X?N̺W61���Oa�>�qׁg����ν�)��Z�n�[Q�#���{ Eim1�.�hk��re��Vě��;�/�U�q�>�|�?�{���x� �mN7�N��r����Qhn��Ɉ�FX�[0+���V: �̝��-����颻�[���^k�&�M;�#�x�u9��K:�ڍ;p5<��/������~Һi���G?dn�tO��H�K����ؤw� Wi�-<qzX��|:�_�Ɯh{�έu�7�����j�QZ�w�ւ����kn�{��ɨ�����=6-��q&��[j5D�Ka!Wm-Z�$���c�=��OVlE[��Un`5l��r��|�uƮ��X�.6_�6����7�0.W8��vV�RCo-��Xms_�:iҝ�����rn�.=GƲ�9��Y)����֍��I�,`A�c;h���(�i��׵N������
��L ���-�� ��e�H�7[SU� ��0�e��K�dͯ�Aw93�ܐ.�ĺ��N�A�n��
p:=�����ϡ�A���0�`A{�\@�A7���c�{�)@�&�������x���e$ͬ��&w=n�3c
)n�R�_����~A�w�?5�'���]-�C��W���3�>�	��So������$S	e}Ä}��1}&BT敯p0&���/i���2�mu+U�ƫ�fn�{�"��́�Z��Ji��o�fL?&�����/n�n�1��]�9|ƍ%Wf%*�L<��Ų��L��߷'���"5�|�<w�i�|�A���<m������)r�RqH&�b�:�d�B#�B��l�(y�CD����"S���&b�D4䦓���XIr@=�B㱎�|2L0�OB^\m���� ���Q�:����x�O���$e(wyi��6�i'G���e,����2~��4�:��SpV�C���rLhY8ĥQ*sS�t
��3FJ���ŞiE�9,�02�V��|�࡟�FF�j�oRB�!v�,�vy�I��k�2��9�*kh%��Fď����}P*���u�tA�@�<��C�ACX,��4S�>��B��|"h
��L���W�8��#z�jbHB�!!B���;�2�Ł�D��&ޖ�N��c븍2��`��q=�O+��*K��PB\YF�HR䘧��G�K/I�&IAvP��2�n�u���i�~Z"N�dR�[z���!��I��4H!(�׷6ߴ/�� ,:�p� %.�0���
6��ī��.t�GH!���L�����g��JD�� �>�g
V�����!8:�hkޢ%㐊�`{�Cl$�$��Uō&e@Bd�c�8�k���,%����]��$6$iԾJ�<۬ �`E��R+i��2�h͡ŭ�Ӭa�0N���S�}����S�e髷�d�%�A|�Ǩ�ߦ�dլ9��Sմ��\m`�RV�3G��q�Ki�Fa�WV�#��h���6㟚dH�iUܧ��j�ȇԜQdV.�	��Pd�FH���#��Ͳ�ϒ��Vc�dx't�� \u��j���uH�����ڐB�f�<m�!��8-HbIDY�"4RB&��6.�����1�¼���?��C18��K	�(S�8�:ق#&��H�U���u�"p���6b��B	�K��]�F�u���_���J�tC��ʄ�	'D"$��F�?��r:|�Do�E�����i'y��q���ɒ`�QHo�]�i�юI+�RL��v�)��_q	�הu|�&�6G��,{b�?9Jd���OB(OF]��D��*�� A��'O��I⩱hì�)~�D$3�q�5j0x(��JayD�ϝP4�(�"6?����_��	C�(�J�-����h�\h�i>��HA�DY∲�m�=�ljt1I�o��%D�=��8=>9��R�~��Y1B��9�Z�҆i�')�_�O�44q�ܛZK8�G&y�=�3]D���S:�".�	fI�
W1���Iz��:��t����/���_�����IH(%̓깅R�9C�!=^?E�ŚƩW@FiP�(�3�zX�L��2)��	_�W�&)���٩�ɵ�$�}{���=����}�v�w�3�Q����qh�c��(�?9&/��m�D��͎��ROE�y=��{ql��=g�
�C�:\"�u
B�\�A��/����z�]W<!��*��� 5���m<}���z��F��V�wǾ4W^$6��f��5�	uCa���������3��1� �_���}I�Ɋ<w֟�9Rp1L�Wz�k���mp�����IM^3焕W��?/=��g�kl{�ֺ����a��]�,�+m�^ϟ,������]E�o�׷�o<0~�uۢ��|�I�����[rV��;���������//&�T��=+<���F�~��=�?��E²������(�B�3��E}	G*����R4�m:��ɢ9K�2BF����UM+�*�r1���/7����f�]��@����1Q6j�Oߤl,���@y��������X�a�l�2X�M��e�'y�)���|`�Ō�_�V�u��N��<�Ƽ\�
o�|�b����;-�1¿0%5~
�e�z0�k����@{�j���;�?��g�>a��Ђ�������4�r���G;�n����������������������������������R��S}�U߸0Vd��-H��X��sʩ9�H�h��/tz^�9��BE�����ԁ	��٠�,�8v�`� �=��Fi�}GO�5p��/`�	����,��`�T�Xt�|�M��Ztree/info/                                                                                          0040755 0003673 0000144 00000000000 11704031110 0013660 5                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        tree/info/doxygen.css                                                                               0100644 0003673 0000144 00000016046 11704031104 0016056 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        BODY,H1,H2,H3,H4,H5,H6,P,CENTER,TD,TH,UL,DL,DIV {
	font-family: Geneva, Arial, Helvetica, sans-serif;
}
BODY,TD {
       font-size: 90%;
}
H1 {
	text-align: center;
       font-size: 160%;
}
H2 {
       font-size: 120%;
}
H3 {
       font-size: 100%;
}
CAPTION { font-weight: bold }
DIV.qindex {
	width: 100%;
	background-color: #e8eef2;
	border: 1px solid #84b0c7;
	text-align: center;
	margin: 2px;
	padding: 2px;
	line-height: 140%;
}
DIV.nav {
	width: 100%;
	background-color: #e8eef2;
	border: 1px solid #84b0c7;
	text-align: center;
	margin: 2px;
	padding: 2px;
	line-height: 140%;
}
DIV.navtab {
       background-color: #e8eef2;
       border: 1px solid #84b0c7;
       text-align: center;
       margin: 2px;
       margin-right: 15px;
       padding: 2px;
}
TD.navtab {
       font-size: 70%;
}
A.qindex {
       text-decoration: none;
       font-weight: bold;
       color: #1A419D;
}
A.qindex:visited {
       text-decoration: none;
       font-weight: bold;
       color: #1A419D
}
A.qindex:hover {
	text-decoration: none;
	background-color: #ddddff;
}
A.qindexHL {
	text-decoration: none;
	font-weight: bold;
	background-color: #6666cc;
	color: #ffffff;
	border: 1px double #9295C2;
}
A.qindexHL:hover {
	text-decoration: none;
	background-color: #6666cc;
	color: #ffffff;
}
A.qindexHL:visited { text-decoration: none; background-color: #6666cc; color: #ffffff }
A.el { text-decoration: none; font-weight: bold }
A.elRef { font-weight: bold }
A.code:link { text-decoration: none; font-weight: normal; color: #0000FF}
A.code:visited { text-decoration: none; font-weight: normal; color: #0000FF}
A.codeRef:link { font-weight: normal; color: #0000FF}
A.codeRef:visited { font-weight: normal; color: #0000FF}
A:hover { text-decoration: none; background-color: #f2f2ff }
DL.el { margin-left: -1cm }
.fragment {
       font-family: Fixed, monospace;
       font-size: 95%;
}
PRE.fragment {
	border: 1px solid #CCCCCC;
	background-color: #f5f5f5;
	margin-top: 4px;
	margin-bottom: 4px;
	margin-left: 2px;
	margin-right: 8px;
	padding-left: 6px;
	padding-right: 6px;
	padding-top: 4px;
	padding-bottom: 4px;
}
DIV.ah { background-color: black; font-weight: bold; color: #ffffff; margin-bottom: 3px; margin-top: 3px }
TD.md { background-color: #F4F4FB; font-weight: bold; }
TD.mdPrefix {
       background-color: #F4F4FB;
       color: #606060;
	font-size: 80%;
}
TD.mdname1 { background-color: #F4F4FB; font-weight: bold; color: #602020; }
TD.mdname { background-color: #F4F4FB; font-weight: bold; color: #602020; width: 600px; }
DIV.groupHeader {
       margin-left: 16px;
       margin-top: 12px;
       margin-bottom: 6px;
       font-weight: bold;
}
DIV.groupText { margin-left: 16px; font-style: italic; font-size: 90% }
BODY {
	background: white;
	color: black;
	margin-right: 20px;
	margin-left: 20px;
}
TD.indexkey {
	background-color: #e8eef2;
	font-weight: bold;
	padding-right  : 10px;
	padding-top    : 2px;
	padding-left   : 10px;
	padding-bottom : 2px;
	margin-left    : 0px;
	margin-right   : 0px;
	margin-top     : 2px;
	margin-bottom  : 2px;
	border: 1px solid #CCCCCC;
}
TD.indexvalue {
	background-color: #e8eef2;
	font-style: italic;
	padding-right  : 10px;
	padding-top    : 2px;
	padding-left   : 10px;
	padding-bottom : 2px;
	margin-left    : 0px;
	margin-right   : 0px;
	margin-top     : 2px;
	margin-bottom  : 2px;
	border: 1px solid #CCCCCC;
}
TR.memlist {
   background-color: #f0f0f0; 
}
P.formulaDsp { text-align: center; }
IMG.formulaDsp { }
IMG.formulaInl { vertical-align: middle; }
SPAN.keyword       { color: #008000 }
SPAN.keywordtype   { color: #604020 }
SPAN.keywordflow   { color: #e08000 }
SPAN.comment       { color: #800000 }
SPAN.preprocessor  { color: #806020 }
SPAN.stringliteral { color: #002080 }
SPAN.charliteral   { color: #008080 }
.mdTable {
	border: 1px solid #868686;
	background-color: #F4F4FB;
}
.mdRow {
	padding: 8px 10px;
}
.mdescLeft {
       padding: 0px 8px 4px 8px;
	font-size: 80%;
	font-style: italic;
	background-color: #FAFAFA;
	border-top: 1px none #E0E0E0;
	border-right: 1px none #E0E0E0;
	border-bottom: 1px none #E0E0E0;
	border-left: 1px none #E0E0E0;
	margin: 0px;
}
.mdescRight {
       padding: 0px 8px 4px 8px;
	font-size: 80%;
	font-style: italic;
	background-color: #FAFAFA;
	border-top: 1px none #E0E0E0;
	border-right: 1px none #E0E0E0;
	border-bottom: 1px none #E0E0E0;
	border-left: 1px none #E0E0E0;
	margin: 0px;
}
.memItemLeft {
	padding: 1px 0px 0px 8px;
	margin: 4px;
	border-top-width: 1px;
	border-right-width: 1px;
	border-bottom-width: 1px;
	border-left-width: 1px;
	border-top-color: #E0E0E0;
	border-right-color: #E0E0E0;
	border-bottom-color: #E0E0E0;
	border-left-color: #E0E0E0;
	border-top-style: solid;
	border-right-style: none;
	border-bottom-style: none;
	border-left-style: none;
	background-color: #FAFAFA;
	font-size: 80%;
}
.memItemRight {
	padding: 1px 8px 0px 8px;
	margin: 4px;
	border-top-width: 1px;
	border-right-width: 1px;
	border-bottom-width: 1px;
	border-left-width: 1px;
	border-top-color: #E0E0E0;
	border-right-color: #E0E0E0;
	border-bottom-color: #E0E0E0;
	border-left-color: #E0E0E0;
	border-top-style: solid;
	border-right-style: none;
	border-bottom-style: none;
	border-left-style: none;
	background-color: #FAFAFA;
	font-size: 80%;
}
.memTemplItemLeft {
	padding: 1px 0px 0px 8px;
	margin: 4px;
	border-top-width: 1px;
	border-right-width: 1px;
	border-bottom-width: 1px;
	border-left-width: 1px;
	border-top-color: #E0E0E0;
	border-right-color: #E0E0E0;
	border-bottom-color: #E0E0E0;
	border-left-color: #E0E0E0;
	border-top-style: none;
	border-right-style: none;
	border-bottom-style: none;
	border-left-style: none;
	background-color: #FAFAFA;
	font-size: 80%;
}
.memTemplItemRight {
	padding: 1px 8px 0px 8px;
	margin: 4px;
	border-top-width: 1px;
	border-right-width: 1px;
	border-bottom-width: 1px;
	border-left-width: 1px;
	border-top-color: #E0E0E0;
	border-right-color: #E0E0E0;
	border-bottom-color: #E0E0E0;
	border-left-color: #E0E0E0;
	border-top-style: none;
	border-right-style: none;
	border-bottom-style: none;
	border-left-style: none;
	background-color: #FAFAFA;
	font-size: 80%;
}
.memTemplParams {
	padding: 1px 0px 0px 8px;
	margin: 4px;
	border-top-width: 1px;
	border-right-width: 1px;
	border-bottom-width: 1px;
	border-left-width: 1px;
	border-top-color: #E0E0E0;
	border-right-color: #E0E0E0;
	border-bottom-color: #E0E0E0;
	border-left-color: #E0E0E0;
	border-top-style: solid;
	border-right-style: none;
	border-bottom-style: none;
	border-left-style: none;
       color: #606060;
	background-color: #FAFAFA;
	font-size: 80%;
}
.search     { color: #003399;
              font-weight: bold;
}
FORM.search {
              margin-bottom: 0px;
              margin-top: 0px;
}
INPUT.search { font-size: 75%;
               color: #000080;
               font-weight: normal;
               background-color: #e8eef2;
}
TD.tiny      { font-size: 75%;
}
a {
	color: #1A41A8;
}
a:visited {
	color: #2A3798;
}
.dirtab { padding: 4px;
          border-collapse: collapse;
          border: 1px solid #84b0c7;
}
TH.dirtab { background: #e8eef2;
            font-weight: bold;
}
HR { height: 1px;
     border: none;
     border-top: 1px solid black;
}

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          tree/info/tabs.css                                                                                  0100644 0003673 0000144 00000003336 11704031104 0015330 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        /* tabs styles, based on http://www.alistapart.com/articles/slidingdoors */

DIV.tabs
{
   float            : left;
   width            : 100%;
   background       : url("tab_b.gif") repeat-x bottom;
   margin-bottom    : 4px;
}

DIV.tabs UL
{
   margin           : 0px;
   padding-left     : 10px;
   list-style       : none;
}

DIV.tabs LI, DIV.tabs FORM
{
   display          : inline;
   margin           : 0px;
   padding          : 0px;
}

DIV.tabs FORM
{
   float            : right;
}

DIV.tabs A
{
   float            : left;
   background       : url("tab_r.gif") no-repeat right top;
   border-bottom    : 1px solid #84B0C7;
   font-size        : x-small;
   font-weight      : bold;
   text-decoration  : none;
}

DIV.tabs A:hover
{
   background-position: 100% -150px;
}

DIV.tabs A:link, DIV.tabs A:visited,
DIV.tabs A:active, DIV.tabs A:hover
{
       color: #1A419D;
}

DIV.tabs SPAN
{
   float            : left;
   display          : block;
   background       : url("tab_l.gif") no-repeat left top;
   padding          : 5px 9px;
   white-space      : nowrap;
}

DIV.tabs INPUT
{
   float            : right;
   display          : inline;
   font-size        : 1em;
}

DIV.tabs TD
{
   font-size        : x-small;
   font-weight      : bold;
   text-decoration  : none;
}



/* Commented Backslash Hack hides rule from IE5-Mac \*/
DIV.tabs SPAN {float : none;}
/* End IE5-Mac hack */

DIV.tabs A:hover SPAN
{
   background-position: 0% -150px;
}

DIV.tabs LI#current A
{
   background-position: 100% -150px;
   border-width     : 0px;
}

DIV.tabs LI#current SPAN
{
   background-position: 0% -150px;
   padding-bottom   : 6px;
}

DIV.nav
{
   background       : none;
   border           : none;
   border-bottom    : 1px solid #84B0C7;
}
                                                                                                                                                                                                                                                                                                  tree/info/tab_b.gif                                                                                 0100644 0003673 0000144 00000000043 11704031104 0015413 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        GIF89a  �  ���   ,       D ;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             tree/info/tab_l.gif                                                                                 0100644 0003673 0000144 00000001302 11704031104 0015424 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        GIF89a	 ,�  ��������������������������������������������������������������������薴ŝ�ɯ�ͻ���������������������������������������������������������                                                      ,    	 , �@�P��`H$!%Cq Ve2X���J(�Ġ+��32$�� �kv��-���u*�"}�|}|~q("$f�'�l(�&&$r����&!�)���{���r�����������������������������Ʋ��εҽͼ�����и������������������������������������P�?�����Bm�A�����%V܈�!�k��/�Đ;^���$Ɩ#Mf)f͇(W�L���K�҄� �I)L:eD�C��x*4U�h�
%A���^�NKb��e�X�� ��k�x!���2t��	 !��5t�����]$��%�X��.i[�]Y���f��E��kg`���:z��Ҟ;�}��j�aa��M���׸c瞽�v�ۺ���8��ȋ'?��9�積G_>�yu�_ߞ]zw�߭�Ǿ��m�浏G~����თ/�>���٫��������|�W�} v ;                                                                                                                                                                                                                                                                                                                              tree/info/tab_r.gif                                                                                 0100644 0003673 0000144 00000005031 11704031104 0015435 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        GIF89a�,�  ��������������������������������������������������������������������薴ŝ�ɯ�ͻ���������������������������������������������������������                                                      ,    �, �@�pH,�Ȥr�l:�ШtJ�Z�جv�h<�pkL.���z�n���|N�����~�wVa+���������������������������*)^,*�������������������������ö)'��������������������������ڥ("���������������� 
H�����K�"�RH�H��ŋ3j�ȱ�Ǐ C�I��ɓ(S�\�Łu&@� ���͛8s��ɳ�O��(���DУH�*]ʴ�ӧP�J�J��իX�j�ʵ�ׯS84� �hӪ]˶�۷p�ʝK��ݻx���˷�߿��} �D�f(^̸��ǐ#K�L���˘3k�̹��ϠC�m��C�H�Xͺ��װc˞M���۸s��ͻ�����N��J� �����УK�N����سk�ν����ËO�<v1�+_.������˟O��������Ͽ��� (���_Yɕ@�r�5���F(�Vh�f��v��� �(�$��a��H��,���0�(�4�h�	*�"�<���@)�Di�H&��L6��PF)�T&�\�;V��\v��`�)�Z^�%	d���l���p�hf�q�i�x��sR�枀*蠄��矅&�袌6:䡎F*餔�	i��f��O^�駠�ʩ���jꩄ��ꪬ�ʦ���*�S�J뭸�*�����물�*찥K��Vjl��6���F+-��Nk��kV����v�m���۩�t�k�Q~�����n���n��r;o��N{o��2�o� �o��:p�K��	7��Gl*�W�)�g�)�w)���(�"�,(�&��'�*�l��,3�,�l3�5߬3�0���=�,t�9m��E���A/�t�I?-5�QOm5�U_=u�Z?�u�K��b�=t�f��v�;����n�=s�r�Lw�*ߍ��z�-r�~{x�N�ņ.q�;�x�	?y��Op���y��n�y��o袷Kz�랎����.n뮃{��6M��ֳ�~m��k{�R��������+]|��.ϼ��?/����J}�G����ok��+�%�᫭}�v��~���w������O��ߏx��/���� #'�R�����2�s| �"(��Q���� S�����|C(���v��		��F|.dc82�PZ3�a�l��f將D�!���!ꩈF���(,$2�NN|���(�쵰�L!���.z�`��H�.zaH����6��p���H�:���x̣���>��d�@� ��L�"��F:򑐌�$9�  (8�&��Nz��(G�FB^�!˨ )W��V��l�)1�w��̥.w�Y����0�I�b�|�Hp�f:���epJ���}Ȧ6���nz���8�0 ��%"��8���v�����<�P�Q`�%�$�>���~�� �@JЂ��M�B�І:����D'ZPKF ּ&16�юz�� �HGJRb �L�5��Җ����0��LgJӚ�#(e>��Ӟ���@�P�JԢ��HM�R��Ԧ:��P��T�Jժ&5;%�U��ծz��`�X�JV��C���jY��ֶ���p��\�U����xͫ^��׾�����i)$�����M�b���:v�,ಘͬf7���z����hGK�Қ���M�jW��ֺ����*$�SP���ͭnw��������m + ���M�r����:���E�?�9��Z���ͮv�9��"����x�K��b���L��z��^A������|�������ͯ0���������/�L����N���(�;��	n0�'La�J���0{/��{ؘ���G|����(��S��Cr�.���	����v�1�w�c6��@��Ld��HN��d/��P��LeO��X�p��|�+s����2��L_1����53��M5����t3��_:���w�s���g�ʹπp���?��/F����F��Ў�t!-�J�Җ��1��N��Ӟu�A-�P��ԝ>5�3��UW�ծ�4�c��Y�ZѶ���s��A�׀�5��,�a��ƶ3��=�e3���~���-�3S��c�6����mo����2��M�q���>7�ӭn$���D~7��,�y����1��m�}����v����\�/��N�3�����#��S\�gu�-m�O��0�C����\�'_��S^���|�.�c.�0ל�4�9~s��=���<�y|�.�4]�D?�z���67]�O�3ӣ�̩S�W�v��l>��3��d�:�u)��?���F;�ˮ�W����|;�W)�����vt�˽w���|��=x���A  ;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       tree/info/_tree_map_8h__dep__incl.png                                                               0100644 0003673 0000144 00000001353 11704031104 0021055 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        �PNG

   IHDR   �   [   ��   !PLTE���p???������___���   ���Hэ�   tRNS @��f  xIDATx����n�@ ����=V�Z>�Rͱ��+�R���H�5Ƕ���=�1��|efmC�C	f#����~f�&{�:�����9��؜��p�{t��nnVk���&�m{��ɥuGI�yN�y���$��%>w�bA��f���ѹŕ�]p��I,�����"&����y���k����]�~��_�����]ޝ�}�T�ز�i�be��.�����o���VT�dl�e�����YgY��;sr{\i�-����8+�ܹi߇˵�?�����/���6�FK�l=��Q���q�UB�ϕ�I�D}��L���M��f��`�o��OK������`O1��0mw �8�4�pp�pa�?�k��K!��/x8z�Q)�4���-����)T:�60�@����oQ��	�xQ/j��E��T��ޓ�C��e���QY3�C�J<���ݽ�f�h4+����5�qѴ�e(��܁���K	d�Z����߰H��[���q*6�K����nS��ܦ8yN�^c�o����n�"Wsq{�F�h��lXsq}����l�����?a�׷�"�򈘕{u��td7���]��?�Pg�ꈘ���3��N�c��3ܮ�-ֳ/a�I�    IEND�B`�                                                                                                                                                                                                                                                                                     tree/info/_tree_map_8h__incl.png                                                                    0100644 0003673 0000144 00000002562 11704031104 0020071 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        �PNG

   IHDR   �   �   �+   !PLTE���p???������___���   ���Hэ�   tRNS @��f  �IDATx���Ao�6 ��]},Z�q@�ɷa���t]��9H鸭�[�(y�*K*�+KR��8�H��kS�Pb#���%Q�OO(d���ȍ�ͭ����&'�d�F��j����#n����Y��zzDo#Ĭ4���ʙO�"bK��Lӄ����8�|O���5#�V�W_��l!�v�}�/������I�y��'fK��Ĺ�)W�uE�hƖz��1�.��2r#7r������<�Q4+��M$����y���q�ʉ����2'��޾S����ɷ���\�r��|B��K
mi��lAp*��ǩk68���ll��*=���sZMi��5�1��r:ǀ9��q��	��)��Z#�A�$X�p���C�%w��8����q�]θ�gJW\�yy��0�����N�t(�q^�pe�QK\׹k��\�Up:E�~�Ɯѝ��0��'82;&�Z.w�'݉�/�����a�ĂK�n�Ɔ�p=c���k�%۞y/X;������^��ޑ��ʙO�{�n8�?��:L+L7=��\��+�|Z���m�2�y4齲�}����z���ۘ�M�jV�Φ̽I���nʼ� �{�������:G�r�^-wB`�>h�唂���>�ڳ�}Խa5�����{���7;����}'{?GY�]���s�K�st��)ZE�S�U됭z[��0�F�7>��a�Z����g���\p��kg1����o%��K��p��X%8+K���'�W9�V���=�����Y�K�7l߽�hyŌ�v߹����lWE����}Y�>w��9n�����v�=�|R{�P�Q��{����#hp6�t8�wZ��ݫ�so�ݛ�qj�B���	�W��V�F�Z�h�N�8��!��J��ԋp��;�S��� ����z	�f<�w('�gr.��&�M��+��;��Fk9���D$��q[N���/<�׼v�H;]�}����^��}g���#���YBDRo%z�'�%��w���$3\����w��a��ùAs�ܐ�en�����`���<�q��p�
t6t�t&t�pt�t#p~&t�)tn-t�0t^��9\�7pN;�TGx��#l'�9�gI��:�s@�O9Q�g�XY�<�8�z֍��})�M��䢇�\r&��q~�
�����^�\ZD��	&K�V��k�i�$����Oc��9
�n�y�r�7f��^��I�W�'�:��������$W��\Arwe�F�r�X�eN^Fn�T��/2����    IEND�B`�                                                                                                                                              tree/info/asd_8cc__incl.png                                                                         0100644 0003673 0000144 00000005365 11704031104 0017047 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        �PNG

   IHDR  H   �   @�   !PLTE���p���___��߿��???   ����?�   tRNS @��f  
�IDATx���o�6��/�X_�)t;�L1��8-���,�
3m�m1�έN�D�ɍ�咢$S?�'[�Ջ��P$||E���~�ű �CbI�%=$���X�CbI�%=$���X�CbI�%=$���X�CbI�%=$�r���`�cB2�k�u;��@'���A�X�����!#�,�Z�+_�Q���r��XBڣaA�"���D����8�>���!'ȐI���B:�bM�w�u|�^t��ߦ1�-� �XB��I:�}���_g�|u��F��n�����l'���(��0�p5���?��⁽h��b@&�j,!�xϰF�5ɚ$c�pI��'��l���p �s��k�;_���q[���X�m>`�1����$"ck����Ab2������ċE+�@V*{���'!	Y��,��JY~ƙf�Uv8d%q���A�Z6.����	��jP!�['�z*��	d�f!�4�d��ϝ��I���h�2�� �����O���B8���QC��	�¬E��)��?O�Ȟ�N�}::�e)_f��R�i��� �l�S�v=�ˈ�I��>����=�R�D�{J��b��	�w��pH��|��o_�gd0�,���C�\RYL���wWL���IH�C R���=}?e6�J�$���!͏�@H�����?|�o�rC�!�c�����/���Is0RSP)����؇�ԥ!�>���n���@A��4���l�;�6�.Aj+�6� �ԗ	�:�@�ˉi���C��HM�+@��̍R�� ��j{ސ�ŏ,�)0+���	�" �I )2)k��'q8E� �I$H���m�.	Ɨ�T6���C��W�r��d>�;�"-��$����)��Lu�	R�������(�Ř�BL�
��0�Y ��D���H\sT�d	�U9�DY/&vU;,��!k��g��P���Z�J�ͺ��Q���"ћu#�@ �5�����Dɭ��d��TF�{�n#1�r8��3�LL�]��{H8db
�
����#+��PY��o��I30b�D,�JIB*�x=�!���������=^��Jd�$ ����x�]�]�ww�y|�]�!9e^���h��$�������ҳ�<��-��Ӭ��I[j���,��_}�d��w��+$��!߮g|�M�����ɻA~������7��n&m}hT7�?,�;�n��]٪�S�:y�$֎'�I��b�n��D��ݛm������5ȻD�]��&�l��=��e�&����E������3���׹g�p���v���������&)	M
d�OT���]Ѥ��9�/�Sa��w�7v���M2C���^x?5@VvE�隬�6����ϫ�#�>�֝�]��3[�.��{w������AY}�����)}.Z�9�[�{�T!]�Y��w�:��ٙ���p8{��1��"dc����&���@6�k��*�o�EV$�=�)�m�JN��=4�4�W����&�q&Q+E�xmW�D��Ⱚ^��M�;�p��C)�����J��+��������e"��j��y�>.
����NǛR���pu�4LX'�g� /�,#�����e��W�j�9���x��uαHû���O��Iܿ<=Q]za!=���1��ͻ����ۅ������� �<(������d��!x�Ὃ8Fb������F{a罳�7��/㿾俉.i�{Rm��0��!-����v]�T��s�*UvR���A*T�=H�*3ȴ2��;�����N�?dS�i3�ǈ^H�M��=>פ�t0�l�Ry;�_A!E����ռ����R�l�ꆾ!���o�]��M���ĄG���8;����=d�/��^P�i7!�!��,�v]��!YϟC��G_F,*��mvv�d]�{��_��^P�r�Jx|D��V�9��Y��Jϋ�w���R���fN��"�AK������Yt�8]���ʊ&E%�?���g���@B4IE�@M�T)C�[�l�o(���/�_�6i�,Ne�yTf$�&�!���!�w�u�a7en���$������Ci	�!Yt�N���YU��[���n�Z񀬨2R�0�dE����U����\$UvR�vR��C�+�ːe�w���NCn��(�p�,Uq;�aA��u?r��������^��[������� J?H�]�!��	�q\o�+b���[���^�"�*���|f?ezCz�W�[�?�) =O����T鞥;e�X�w��L�-�{Ds�I��'�XGL@�x�1���=���(^�иG����x�� �p�$�P0�g�BZ"�G�0��e�`�m�nH�����?�>�/������� ~|H�U=�={�U=�={�U��A�9�T���=H��1>���c~(��1�f�����f.�S��������c�����f.o7�A���V�׌d~�B��2ٶ��ogQ,68@��*��*$?a�O�p���U�oZ�$?��&�s���d�E�}��;?WA@�غK!���bs)�ːg���e�Q�t�[THi�vUi�v�����%6�F��CbI�%��� �L�f�R    IEND�B`�                                                                                                                                                                                                                                                                           tree/info/class_c_count__coll__graph.png                                                            0100644 0003673 0000144 00000001120 11704031104 0021667 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        �PNG

   IHDR   U   �   �J[   -PLTE����+�9L��ߘ2�???���___��߿��   ������z   tRNS @��f  �IDATx���MO�0p��M�p�v���p%#q�i�ʮF	;�ĶA�l�����ý�vl!�=�%]~y�_����5�U6����c4]���%�$Z�h�����~���]\Dj;p��-�&Ԁ6g�1[���s0}�$��s�}�+�=�Ea���3��}dc:�v�,����}��E��7��n��[Kf�h���W?�f}�>�We�n��n����Z�n*�v�'����YI�ݭV�J�l��4�ζܷS��v��mP%,ɵ�`4�df��.�����Mf��~𐡰ɬWXB�#�������.�(/��ɬW����vR���֏���g{g\٨��m�������=Ƞ��Bޡ0ik�����M�iK�vƟw-¬�a�[ S��q������%���5��m���epy�	�Dmٻuٻ�è��g�11؞Ձ�t!C�Y4�&�!�����6�*�k�PUvm�������    IEND�B`�                                                                                                                                                                                                                                                                                                                                                                                                                                                tree/info/class_c_count__inherit__graph.png                                                         0100644 0003673 0000144 00000000776 11704031104 0022420 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        �PNG

   IHDR   ]   s   ��   !PLTE���p???���___��߿��   ���15   tRNS @��f  �IDATx���AO�0 �����Mw\��v5�tW/n���y�����@�I2D�~��� �$�D]_8�ݗ��,���g|'�օ��lNc����>��5ݒ){G��9�Klʞ�����J��g���%�����D���W���u��i��z"QLx^�q����h�߯����>�����y��d��-�e3��"����k$��ּuֱ���{��@[�j�h�'����|����o����s���Qufb^s�oqʞgL��Q����p���a��E^r|>1��+�9�Rwl��k/�������
X�1���]�\���Nˆ�5^4N�0�ߕ�k�X�0uG8�K���~c�8>�����V������k?������7�އ�t{    IEND�B`�  tree/info/class_tree_map__coll__graph.png                                                           0100644 0003673 0000144 00000005300 11704031104 0022035 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        �PNG

   IHDR  !  M   ��	   $PLTE���p�2�???������___���   �������   tRNS @��f  
JIDATx���s�6�=96�^�KG�յ���13N#��m�S_�#]�Nm5���v����ֲ,��D���$����x�� ���H�a2?�M�)�H.�H.�@��^A�%2G$�H.�H.{E�OAvّM��f�V�"�	3�����<�G ����D�|d�(�Gh��b���wL���6u��%�ZD�X����$
o#���@E�*B�j��:�K����h����qB4�G�L�����u��4!��GT=�H�\�\�\�\L��~k��6/~�$81A��TOc-{JԮ��Z���o5�#���v�hA�["�f�G"�m�l�H��g�#��#��#�K��Փ�SsD���yS3O4,����y"XK95D�'��v���5V��,�o��h���I�I�R����*$�2�M3���!z���$�5V�F��u����*Q�$8qDr�O�ƷF����9"yj�H��^�!�\�\�\�GԼ;�#RH�z|j�H��#���ؐ?6O��~ESp�I;�"�(\>��	Nq��8qD�S�lO�Fh4��CB!Q�ݥvEt���~�����9Z��;>$�Jt�WĻ>��F@�D0�:�H�Fvu����md�j=l�b�ꀰKt��d?g:
@t�{�k��O�Q�6�<�D��>B�M{���n��j]+�\sD
�����<��K5��$o����-�H>���N6F�*o�o���lC���ʂ��)ɷC���L0E�w��G��"j���o�$*��(̷E�Z*G�%�q?�����c�I�$D�b���l�#�rv�$����%8�<"-'�Q"�ٞ�$��b�HT��fk�H�Dj���mw^�M���hԏ�n#����m~@�t[!�SD���xjKC� �l���\;QaA":bK�}�C#�|��[���]�DEf��C?^���uC���4Q�ٚG���EDZO~�D�qD���������8�,F��h�l�#��j�h�lړ Q�l�#�^=�QeR����삈7�#Hk�U��h�8�9"������},D���PR"?�E*�!JR���iI�o�0����&"��X�<��(���Ql��VĽ���Y��&DI_W=Dc�_�0����Ů�!�\����ăA��]�(.H1��[�5ɕ�1F�bW�%�)���Q��Dl~@�D~�<%Zy�Z�XAb�(\>� !
�/��%��ƥʅ����~~B>�j��h�k'&�u�[�m�(�^&��ϕ�L�D���!J*�b�aD�∸�M�5?w�/���� &��0�
�2w���f�E�Ѱ��z, �#>�]��u�z��!�#^�ё�h��pcDD�=��#Z�M=u���D���%�~G��L���3H��Q�̻�?8��Vb5����\�#G��N����""%�R�Dߠ_����/�C꟏._0"��VB4���$��'���zq��=� �M�#���+|_��k꟏�#��k%D��i���H���XDDs+#���:�c�����Ɏk�D�ry�4|��""�[��X��?3�|�]��=$���$:B,���ZGI�"��l�-~x��x��o����~�v\���Id�\9:�ܸ�@sD�)�kg�
����k}8bwH�v\���qd��K���kӒ��s��>EJ�v�qD[���5�}�8���B�D���e�|Ow�������;-Mvy����ɍG�[�E5�X�
�������k~aXEw�K��b-���t����l��DKь5X�j�vI���P^�s����HD�f�o��C�Z��C�ފ�HDzJ�vd�d,��刵�X	7Չ��T<7l�d}2�v�X{�5�`�\��6Xo��nM��?����a*�~Z�b�o5?x�N�&"���*i���`�*�Fw�3o5ԩ�H'��'JD�����Ūu���b1"j^����*�E���*2NT}�aE"�j#RIP�\�U��bN�e5LT]E�D�|�L����U����,��冕�Tr3�"u"�[_�D
3k֛$�����N$Հ�e���Ȍ�tF�Hr4��9"C*�!��#�їu��e�x9^�.��CG>DNW&CTE�#9]���mW'�����:��G�m<5�΃�?OF�DOQ�qʲ�<�"�ٞ���ќ��8��n�5��?��%���|�#�Ⱥ]���g��9�����$B�Q�m<�Fhv��?Og�sD>%��Z�m<5�4�o#F��n��G$�ڤ�����Y�odFUd�Ȭ�L�U�.QQ��Ȼ5�Ee"��/���+İ���V�6Q�so�$MP�(W�M�2�q��`�0[��Qe"�O"�D~ɑ�&��F�bn_�w���#ځѶ �
�.T�D�ٌ?ӈlA�j�������̤<7�h'FS#*v����#�D���� ��M �=|�^��ރ��&}OO^��� ���ܜ��r`�(Lo��]�>�`vq	w]�D��30���}�%��V`l��#\��t��`���\X�:D)�{���C��Z��d���!�� ��g�MO��i8�`���s>.���bI���D��#rD�h�jG$G$��{�LGx�    IEND�B`�                                                                                                                                                                                                                                                                                                                                tree/info/class_tree_map_1_1const__iterator__coll__graph.png                                        0100644 0003673 0000144 00000007653 11704031105 0025632 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        �PNG

   IHDR  D  M   )m<   0PLTE����+�9L��ߘ2�p???������___���   ���7S   tRNS @��f  )IDATx���s���}ɩ��ؿ�E��^rᡗ�c}L�&��3�#=U\�X�#�W%�PG��񚦭�K"Z���ТHj�����?(�}m�v�����v	�}�X��݀�#"ňH1"R��#"UD_B�5�W Q+�<qbD�)FD��bD�����/S%͖4[�<+�J�:�2���yVP�	|��4γ�*�h�r�U//�����e��۰e�YM�A�u�: ��GDt�[v��TD��t�iD�S�j��QK���-�~�V#�:%��<��ڗ�l/bD�Z����z�VȞTߘ���<��2���fW���S3��	�h�VFy�ĈH1"R��#"ňH1"R��#"UD��������dj�����L�1"R��T59Y��"�#��hdi��T%D�dh��bD�*���ȶ3bD�*��������5FD��bD�)FD���$��L�1"R��T�ִVD�5�� �X�Z%��uz���]������J":u�G'��.{Q�>��c�ޗ�(J�
3�E�cϋ��(N0}Q�ִVID�7#��F�]�Z%9�ZcD�)FD����b)FD��bD�)FD��bD��L�1"R��#"ňH1"R��#"UID�Ց#"ňH1"R��#"ňH1������;��w�ך��4�"�[���bD�1�%ĈH1"R���!0}�Z���s;ejg0�I��R+�|u�i�6�ӿ�)c;��̋�۱[�櫃�{u�=9W/S�G���qz����$"孷È��4����؋<���7��y�Zm����#���G�]?3^4eD��A���y����v�!p��@�rzD�&MxD3�R��#"ňH1"R��#"ňH1"R?X�~�~��S�~��҇���CgiS�E�ir:#"�x�zu%FZ�g��(э�F��Fi0�0�72"ЧInĈP��R�ReD���n1�J#�s#F��hF�J����R���!��%!J�*#��4F�)���L��G���
#"UiD��椱ROD��=VQ\�ݤ2H1"R�F�ݘ�����3��rF��(&Ҷ"�v	�Z"���x��+�Ȕ*�(:�~s�U#!ո�Kۨ#��wom�`�%"����o��?m�F�EvFڋ�|�n�}F��#"g}���8c��K�TQT�9
F���b"F�zG��'�T�:��Hs�Y�!�T��U-�;ϯ��Έ���(���*�h1�QX��T8��vE��V��#�-*�(��Uk�(iN��T�"�I[�v�Ҟ�2�%TD�ΈE)��I]����.͈H��i�O?�bD�j���VX"��bD��h���1"Z�@4�����tٺ"6br��=�+�&��Hs���(r"���ʮ)"|hH�`�|P��n�	"?�o���њO��?Iuz T��t��=�Q#�H��_����'B]�D��ȋ4G�Èf��v��T���+"o@ӄ�=����[��,o੎����3Dt4�'"�_� �'!��'Q�KADQ }��VX8�������K��Qe�h�gb�hK���|وR����L;��h�����O9���F;�@F4��;-#�}bDt':G Q�/"�����Se]T1s'�jz��?�ٶoزl7����=�7n���)�A��]����Y]ƙm�X� �̋X�^h:�XY����x)-��,�;��o��������rA!ښm��f�y�H���V��XyGlv��d	�3��n[�N���zm�y��m7��4"a�#ڽ�w�^WL�ǋ���Lg�崮;����=���w�����A�d����!�ӹ��&΁���
��t1�\�ku�YP�r�cf�V�N&ƽ7��	P��g>�(D^�p�K\�?C%����+� �#�:B��(ӽ|7:�/�tv�([�"�;�ynf�^ݝ�!������C���9�"��`��dȯpǱWe�2d�5{�������9�>�XӦT�Q$"Ӵ�s%���c��U��PF��	�5ڋ���r=D�iG'���@�<�~if��R�1xV�ǺF���/�!�T/�u���ЗgԢeS��U~u�+m?��qkOy�p�����B�M{߂�T+��D:k4�S�%�4l��A���n����������5#1����7�?C������LJ��T�lj6���o��@����c��2^d��b�-fm�u�t�hD
��"����/2Mى�"3"yno8~�E:	��wxU-���M���}�M�m['v����"�i?Z^���^�]Ct�}� "F3��,V�ct0���aW�=i�`��K۾��� �����/2���^�A��a�^���%V��5̦6�Ԉ�5��>����Y"�u�h�mvխ7���:����Lg7K���}8�و�E���k�ðq��z��h" ��1��#�66��\�	Z���5�_J��	��7�L':u��E~ӎ��H�hJ�hG�e��Z�8؀��Ю���}l8kL��N@J^�9�C�?��5���A<K�4�$�<��A$��k{���#"�׋H1"R�\ޟ�t��h�ik!�\4bD���� MZ����JgYK6"��FD����l)����J��0ɝ�wѨ�����3V��U��N$O��T�
�<ߵ��8%�����{���(b��V�|s�I�d9��c�X���N\�c�d�q���WY�
�a��LaF����7�*��VV��%��Q�������T�Z��.��C��wيZ�ʺ�ڻcV��6W�̵2�]4*QA�n�Hk���.~��1�1ߥJ@TH���Z���Gs��(qy�,��f�\��AT���}5���ZL��dd�pD����+�-��}x��jYVr�5W4"��>`6ʪ�U���9#ʚP�򍴨���T��<�(��)Q�n���TQ.GS�d��"m��*QNnt��3O*g�^.n��
!ʋPI�r����576s7�F�,DY�Q�'��5�:[7�/�TE�J�4DYFZ����Gd�Fy�C��e�Fyz��r'T�3C����	��(7r2����<��e~�:BQ��D�~�Y7��M��@e>�i]7��jF)��\QDkF6��n�,I�y1i+��,���H��z�����Z|@.*�:nd�������;��{e������P��Y�܇�i~���E�)��r���Z�=���E��4*��R�"�y��y,�-�h�U�V����\2�Uܨ�&�����n�Ͻ	zp����#Je#Ji�*QJ7*��C��/f�*Q�H+�Z~�JG��!���ej-i�\ˏP���u��m��ܨ4B��h)7J��tfz �J̴6i7N����& "ݨL�D��K�! *����F J���	m�7*���#*�І ����	m
�87ڄ�mBT,��h�F4B�DZ�'f�6Q������#�B�("Ҝ��b��4��ňH1"R��#"ňH�H(�׮{����K�7�� r]��wm�(��g�7Ԡv����	��B	QD���]������7�}2튓=��<�>���^�J�
��١�S���*��[w�j��>v�ˋ3龽�b�X'>�:�w��{���θ��7��0��ɓv�A�ry6p�\�c�r��=�����Kw���D��G^�)%��\�鴥������@@��av��'���N�������EG�a��Z�v�;j�W/ڹ�﷿q��=l����g�/D��	ěF4��P�MrNaD{�����R��k�94#|��MܦA���P���I�6�H����R�4ۈ��TD�(UH��JG��#bD�bD�)FD�U[��#"ňH1"R����?V�@zj�    IEND�B`�                                                                                     tree/info/class_tree_map_1_1const__iterator__inherit__graph.png                                     0100644 0003673 0000144 00000003557 11704031105 0026342 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        �PNG

   IHDR  �   �   �*�   !PLTE���p???������___���   ���Hэ�   tRNS @��f  �IDATx���s�F��/��c�4��g�=��X�8p��D=�LеmZ�Vc#�b@��_���JH�3Ȳ�}=	־_��?�3�.���z�;خ���b�b��<J�D2�y�gu[b�b�y����x4F#^�5MM��|�LL�"qa�T*Cv�D�d�y��G��_�D����;�c� $y�U�bS��a!q"�`�8�K-Q?�"����q�qUGS��I�B��Z�X�8�^�3�����1<%J5�����N�ܟ}ِ
���oo=��>�w��V�ꇶ���D.ߜ@��w�y����}�6!���-g\iD�MH�BH���$$`I�He�;:�UN��+t�$��`B���U<�Q[�O�p�H�q�UG�1��s���)��7.E�]s!��'N��F2pN"�V� Ɍ�ɀ��d*3�S�ꨪ���!Z`�Q*� ��A�/�s���M����
�|����Q����\�=���}sX�y��f2����:Tr1��l���U����L*�g;�o�ϥ�K�dx���|00|2��;�':�6�6��<L��b|�(1Yb4`J.f6�MUՅ=�)|:MF�N�n~4�������w��1q���1�S8�0����2A����@X2���*���K�R���dn�M���V���+�+��T.yWaS������]��k�Ќ�T��9�V<@>�SL���x8�Lg����ê�~���c�J��|;������]}y�����:�̓8n����|�P:�4�O+M������g"�
c�L�t�Q���<��B�[��R��iS����	Y�~�y���.-�i(8�]�a�iκ�fa,��_���5�(��@?�j�ޒ5�GU�W+��lQ�Sl1O�UV�~u�_5�ߏ��|��Ƴ�C.e��R���˥L^<����e�1����Ǔ�b;���q/��<�*��k��X�y��<�b+1����J�c)��X�y��<�b+1����J�c)��X�y��<�b+1ςv�7y��<��<̳#���E��y���(�<��G��_��[�b�_��R(��<3W|Zã�"dy�?�9n���Dp.��؟��{%�
�O<w�/�Y�� �~Z�y�+�Q��[�No{J|(y�!���w;b#�G31���O�y�*l���/.����7�dˏ��_�Pw�"�wZi���h�Gk7#T��R��ܧ���$XWØ�E�'��3G��;��_���\$���H����W������?�z����1�?f� ��va�O���~-c.Os
���*�)��%o�iR��|�oo��p���~}e��Y)�ƶ&�y��G>UX;1�0���{�R~���*O�>O[6��}�6�:�c��}>�l<�yg;1����yڲ���(�X�y,�<VbK1����R�c%��X�y,�<VbK1����R�c%��X�y,�<VbK1���'KO4y��ǖ�b�<��y��<ۋ��<Y*%O�}ޏZc#�X2�1rayҝ�n=}�������/�����+�#/y�'�\y���������:�j�VW���荵��;�rܖ�׸{h�J�x��^�Rw��r2zc�'�|����5AV��8Ժ��V����V�荵����<uT&��4��W�4��S�kG��F~0M���n�}�W����h9{0M����Ѹ�^�>�t����F���O�4AV�U����2�k�������X���y�n�g��'K�|�Lѱ�'K̳��X̓���l���-�En���I�Sl1O���L��b�/@Z    IEND�B`�                                                                                                                                                 tree/info/doxygen.png                                                                               0100644 0003673 0000144 00000002401 11704031105 0016041 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        �PNG

   IHDR   d   -   ok>�   gAMA  ���OX2   tEXtSoftware Adobe ImageReadyq�e<   ]PLTE   Ǿ�"&���ﶻ������ޠ���������������{�ԍ�눙נ��������������������ED9���hg]_X<@:#mhU�����1   tRNS������������������������������ �v  �IDATx�b�C ��:  d#�����h`	@ �X",***LK �.� ], �X@t� ��b	@ ��� B�D�6� �%""�� ���%��B:H����f@�  �RPy"K`\PbC(!II!h���(���!���C�ą�l!0[X\J\$TM�(�>a$S���@Ш@R.$��LJBR��A�G1
��(F���Phh�T���%!`�&q�%u�P ��� � �CT$B��|���W���l��!B`R$(�������@ A�%���%@,(�����%$���RPmB U`1I�YB 99� \�1  yCCC�f"[N�' �=TGȒ�l8�^K�5�<�S��Rɤ�%�@@ ���b1�q�A�XH���&��B�R y	n�P��� 4A ��j���>� �t!�+(.��WQ�A2��MU܂�����`1�%`19� F<3cZ�`�e!\� D�+.83����!lYYA -6�EJ��V �@��XXX 4��
�@86�`RdB��4I	"�	"��@xr ʌ�H��A�`�f	�ȰC�"X V0���Cb@2���H
�ȓ p)!( � �0�4�)(%R��	�$�T ʀ���b�b�,s� �@7 � �Ѱ���?f�֗\PIx!I��"��Ȉ�3�
QY��t�^^��gv- }>W �JOAV`$&#��8���8�\FF �SFJ$�ƀ�Ɗ��� ������4�����	 -��� �H�������f	?��5� ��k1� d�,��	����.� "�F��ˀ���I�� "�� 4�H�gx�|�f �m)))9�.aM D�&  �X@t� ��b	@ ��� ��% DK �.� ], �X@t� ��b	@� d`�ɽS�O    IEND�B`�                                                                                                                                                                                                                                                               tree/info/index.hhc                                                                                 0100644 0003673 0000144 00000011427 11704031105 0015461 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        <!DOCTYPE HTML PUBLIC "-//IETF//DTD HTML//EN">
<HTML><HEAD></HEAD><BODY>
<OBJECT type="text/site properties">
<param name="FrameName" value="right">
</OBJECT>
<UL>
<LI><OBJECT type="text/sitemap"><param name="Name" value="File List"><param name="Local" value="files.html"><param name="ImageNumber" value="1"></OBJECT>
  <UL>
  <LI><OBJECT type="text/sitemap"><param name="Name" value="asd.cc"><param name="Local" value="asd_8cc.html"><param name="ImageNumber" value="11"></OBJECT>
  <LI><OBJECT type="text/sitemap"><param name="Name" value="main.cc"><param name="Local" value="main_8cc.html"><param name="ImageNumber" value="11"></OBJECT>
  <LI><OBJECT type="text/sitemap"><param name="Name" value="TreeMap.h"><param name="Local" value="_tree_map_8h.html"><param name="ImageNumber" value="11"></OBJECT>
  </UL>
<LI><OBJECT type="text/sitemap"><param name="Name" value="Class List"><param name="Local" value="annotated.html"><param name="ImageNumber" value="1"></OBJECT>
  <UL>
  <LI><OBJECT type="text/sitemap"><param name="Name" value="basic_wfstream"><param name="Local" value="classbasic__wfstream.html"><param name="ImageNumber" value="11"></OBJECT>
  <LI><OBJECT type="text/sitemap"><param name="Name" value="CCount"><param name="Local" value="class_c_count.html"><param name="ImageNumber" value="11"></OBJECT>
  <LI><OBJECT type="text/sitemap"><param name="Name" value="iterator"><param name="Local" value="classstd_1_1iterator.html"><param name="ImageNumber" value="11"></OBJECT>
  <LI><OBJECT type="text/sitemap"><param name="Name" value="TreeMap"><param name="Local" value="class_tree_map.html"><param name="ImageNumber" value="11"></OBJECT>
  <LI><OBJECT type="text/sitemap"><param name="Name" value="TreeMap::const_iterator"><param name="Local" value="class_tree_map_1_1const__iterator.html"><param name="ImageNumber" value="11"></OBJECT>
  <LI><OBJECT type="text/sitemap"><param name="Name" value="TreeMap::iterator"><param name="Local" value="class_tree_map_1_1iterator.html"><param name="ImageNumber" value="11"></OBJECT>
  <LI><OBJECT type="text/sitemap"><param name="Name" value="TreeMapDetail"><param name="Local" value="class_tree_map_detail.html"><param name="ImageNumber" value="11"></OBJECT>
  <LI><OBJECT type="text/sitemap"><param name="Name" value="TreeNode"><param name="Local" value="struct_tree_node.html"><param name="ImageNumber" value="11"></OBJECT>
  </UL>
<LI><OBJECT type="text/sitemap"><param name="Name" value="Class Hierarchy"><param name="Local" value="hierarchy.html"><param name="ImageNumber" value="1"></OBJECT>
  <UL>
  <LI><OBJECT type="text/sitemap"><param name="Name" value="basic_wfstream"><param name="Local" value="classbasic__wfstream.html"><param name="ImageNumber" value="11"></OBJECT>
  <LI><OBJECT type="text/sitemap"><param name="Name" value="CCount"><param name="Local" value="class_c_count.html"><param name="ImageNumber" value="1"></OBJECT>
    <UL>
    <LI><OBJECT type="text/sitemap"><param name="Name" value="TreeNode"><param name="Local" value="struct_tree_node.html"><param name="ImageNumber" value="11"></OBJECT>
    </UL>
  <LI><OBJECT type="text/sitemap"><param name="Name" value="iterator"><param name="Local" value="classstd_1_1iterator.html"><param name="ImageNumber" value="1"></OBJECT>
    <UL>
    <LI><OBJECT type="text/sitemap"><param name="Name" value="TreeMap::const_iterator"><param name="Local" value="class_tree_map_1_1const__iterator.html"><param name="ImageNumber" value="1"></OBJECT>
      <UL>
      <LI><OBJECT type="text/sitemap"><param name="Name" value="TreeMap::iterator"><param name="Local" value="class_tree_map_1_1iterator.html"><param name="ImageNumber" value="11"></OBJECT>
      </UL>
    </UL>
  <LI><OBJECT type="text/sitemap"><param name="Name" value="TreeMap"><param name="Local" value="class_tree_map.html"><param name="ImageNumber" value="11"></OBJECT>
  <LI><OBJECT type="text/sitemap"><param name="Name" value="TreeMapDetail"><param name="Local" value="class_tree_map_detail.html"><param name="ImageNumber" value="11"></OBJECT>
  </UL>
<LI><OBJECT type="text/sitemap"><param name="Name" value="Class Members"><param name="Local" value="functions.html"><param name="ImageNumber" value="11"></OBJECT>
<LI><OBJECT type="text/sitemap"><param name="Name" value="File Members"><param name="Local" value="globals.html"><param name="ImageNumber" value="11"></OBJECT>
<LI><OBJECT type="text/sitemap"><param name="Name" value="Related Pages"><param name="Local" value="pages.html"><param name="ImageNumber" value="1"></OBJECT>
  <UL>
  <LI><OBJECT type="text/sitemap"><param name="Name" value="Todo List"><param name="Local" value="todo.html"><param name="ImageNumber" value="11"></OBJECT>
    <UL>
    </UL>
  </UL>
<LI><OBJECT type="text/sitemap"><param name="Name" value="Graphical Class Hierarchy"><param name="Local" value="inherits.html"><param name="ImageNumber" value="11"></OBJECT>
</UL>
                                                                                                                                                                                                                                         tree/info/class_tree_map_1_1iterator__coll__graph.png                                               0100644 0003673 0000144 00000010532 11704031105 0024253 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        �PNG

   IHDR  D  �   �N�   0PLTE����+�9L��ߘ2�p???������___���   ����j5�   tRNS @��f  �IDATx�흽s����I�dre����ߐƍ
7F��W�w�O����dy�"��2:��ol�Ԍ.'�q���&%QX5<Q$��}� ��| �/�g�"����� �x����?����"R�B�P��)�ݡ�(��T&R�B�PH
)B!E(MR4����z��@�h����|�f�2+�$E^�o�Y��(�o���y�f\�=Q_N�eV�1�F��S)���� ]Yf5���jhJ�ꔸR���C��Ļ7J��)1R�����}�ʌ"R��S��������V�E�hh�Y��(ڴ��b�5���9�G4�hNG4��S�8H
)B!E(����"R�B�PHJ����~�ưr����&k�VG�P���ʳ�&*Z#E�em-�Έ�4Pфa�"+��HJ�����HJ�il
�\k#E(����"R�B�P��a���"R�B�PZ�hx��Z�hp��Z��ݱ�F*��y��t�nM�q���5R�����Rtҡ(���� N��`�/��dHQ$n-HQ�}�h���X[#�^�:�J��kk�"+��H
)Bi�":�G!E(����"R�B�PH��km����"R�B�PH
)Bi�"��B�PH
)B!E(����"R��>	�0
�dN��EY
�D,�%�M�)������"m`�����'撅Y@�(��W�^b��Qt�=�.�_�Kff�Eƽƽ�ꛣ�{q�>?/�KH�c`W�7��g��_:#d��o�i�}7�>wG�P9��?�R��5��lhS��D2�������]?�Q� E&�AS�o�U_䌐q��"m��鶀r�挐��MC' (����"R�B�PH
)B!E(�_c%�`��~ܪ_c���(y��J]Uc}�����2<W���[Z��3�U�F�H)J
�,	�(!�&�H�iR�" QQ�L!MV�Ҳ%Si���0"E����F���#)>}�!a))�<R��a�i�"�{Q�j��(���"R����RM��wFV�ZHJ�Ŷ4+K-�Tt���F+�ki�h	)B�iiW�'�E�Jڬh���f+�ii�"�v	M+��In?����ኢ[�oN����q1�v�:Z����c�ʠ��hlmT4��߽��?��:�(�3��d}�J*���1^E+�e_t�F��J�G�銢Z�%�m�5���?��U�SQ&��(��Y�jh��L�)JA��;�l�BZ�(���(��HQR�ji�(HPQ�ޚ�4_Q�3"Ea�2?]��-�ʺ>)Bi�"K�z�F�R�E��F���)�2��E��fe^���B��ҲwE�S��������h������C�����"�v(�Z)��U���hŔ���ݕ�EnK������̸+���&kk0���$r@:3nm�"��Y�$<�`G����G.��������v*
>�����_p�7g�r�ZE� KGp��`��X�O��Y�uR�~pR���R����P���a�v�T�[�V��H�(�~��%�(���#�@�3}/?�����O��X�"8����-帬�c*ʼ���b�+A��w��w���W�y�,�����W�y��~!E�;R��cE��)��pa4��p��0.�豓�f��;�٬!�b�fsu�wz��ݔ�ͺ��鄻C�-���G^���Mw���),W1�{���3a(
nP���<\C|�F��̯�S�Rφ��%�(2��b�z�#s7}��r�Ș�Yn�e|�ʿ���C�pޛun�����Ǝ���ѯ�u��3:I������:�[6|�TyŸ|{:�?���N�r n>�M�9���*9��P6"��e����\O���0�ih6�Ke�2n�bY^b3��_f%��G�8v��!�d��},-��L.e����9�).!�%����Er���@��F�S�'Bw/�M�=�]%e®�<�#J/n��e�ywC}s��/���;�8,�5���bY^-�{�&}5��j��V��Bm��9,}&ۚ�JE*һ6|.�7rrj�0ZG��1U4:��v�:�u� F����D�c�l6���b�'�X��-2(=�}��H.u��Z̽�����YoYo���60]Kg�M�4�[��ml����kG������ 6�1�T�hE�v���`���\����(�?k��l���	uqw��c�=Ep�Ƞ23�$�3�&�5�-����@cՋN��5�D��5z�u���w�)RE�	hhf�j8��"�+qQ��HN��?0~Ej���E0�٤�ftj�z����RU�u�xg��J����E"��E�ݵl��e_4�-XI�pv���-��������yoZ����վ�h(�B��V�����g���e_[v�*�����]-���JuDsvm�L��}ѳ8E��8JѦ����M��sy����u�c�?���;����9��acG��Vc�Es&��y�2���h��9�����S�e�K)|u<�*��7ӹZ��{��k���Tф:���q�hP�x�AN@d�:�
}x���ƬV�	H%�噓��8E���1��E��$��%��� F_O�ڽTT.�����"���N�y��2}шy��,#E�+�;_��T�
�9�J����ȝ0�kk�~�]�:?x��R�+L��cDQi`	�%6��U��+8�Vg��
�*��������#"O
܃�=�Q_��HQy�&I��&f�����H_���ʪRTZS������uXA_��R�keܹhT�������H~r�{�4<�~]_���ʸsѨ|E%5�+4�����++�B���q4y8I"U�#�3ݛ���2��l:Y��jj�(1�b��������,C+�ȏ�tE��W�!�^JV$OA�R(惕oue+�)s!�>ȥ���V���*��~�{�U�)2�
�<U(*0���8�RTȧ�d�UQ-m�Q�8�(*(��¿a�A5C�
	��5HQQ�*RT@K+�PUccs�Ia���(�{)ʻ�C�B�7�
�U)�5���MP���?�=�!����3Q3Q���¨ȃ���g��F��PQ>aT��{��ʥ�D*|8O-�����BE9���P�����Ow##�HQ$f+k��;�4��Q��$ad�aĠ�\��Yjw
#��S5��£ 
�REw	#}�1�#�a�� �|�ܸ����������yR�CWni��̈���)D��V#�Z�����W�"�:,ӏ��#�y�h���rw�bE+�Q��\�3fW��w��)*����V�����tU+�F��o�*0T��L-����\Q�0*�Z~�IQ5�j�(uK����:(JF��=RT��:(J�Ҫ3TEi¨BC�P��Q�S>��~(��߉x�mie�rO-!a��(�L�EU�b���$���/�����0��򇟺+��PMŶ�����0����(���.����*O��(����P9��<~��МO�����(�5�C�PH
)B!E(�����ȟX�!��p�Ռ<��A��(�~s(�n%�� ���mPt�_'(b�5�R��h�~s�.v�ʗ�Q�����*tj���	�yG�K�dE����oL�K8й7��'U(W�CEL�Q_��P��e�͟�'���	NBE�*���X*
���X
�+r�o��OT/n�Чg	yG}5�B�Q�߼~�S�r�Q؍"���hh�P�Q��R(]��~��R� u��ou_����;!&�Qc)���M�����6B�P� l�s'��m�����^k5HJ]Ŧ
�k̛�ե�xH
)B!E(�����kE�|�e�C]n{��ifꥨ�t��!E(5STjbٔ�J�R�A�P>��z7=��V���*���)�agD�Pꤨ��ę E(uRD��) E(����"R�B�PH
)B!E(����"R�B�PH
)B!E(����"R�B�PH
)B!E(����"R�B�PH
)B!E(����"R$�	Ow��l�����"R�B�P�PĄ��۾�2E�sc��NE҂�o�����c��1)���}�{�"f�T{���;7��ަ=۲���x��6����0������	(&�Q�{�3������1��^p����������,���#�Q��fΏ�������L�*R�U��7:v[^�	��g��`�����s����C��Z��X���9��'2�v�Qe��5hym\l������VN_o}Q_ͷٓ�=S}Q[�,��H~S�����qv���Ո����?O�:��PQ$,a)"E��@�H
)B!E(��5R�B�PH
)B!E(�����7�KǠ    IEND�B`�                                                                                                                                                                      tree/info/class_tree_map_1_1iterator__inherit__graph.png                                            0100644 0003673 0000144 00000003526 11704031105 0024771 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        �PNG

   IHDR  �   �   �*�   !PLTE���p???������___���   ���Hэ�   tRNS @��f  �IDATx��MsG��t�ё㈣���]�8����*�l8�J��c�8��9�|���t�첻�"��A�V�*�tO�<�����B��'�=�l%<����[��1� ��c?�YIx�-�ɷ���S����,9h���/ƍ	C���$"��E�w��΢��M�p��x�S#�$M�<���"�d��R�X�%A竨5�r,�e9�|���$擘B2�Y�X8j���L|y���
5����Ŏ�Tz�ʞ�hmc��k��i_�<�g��mÎ�VG��g���/>�%l�#�Ϛ5G�ݺ7>8	���`��(4�?Hi����HD�;:Y.����H8R�	��V��tGm?N���Q˼�'# �z����8㕡�i҈����}�q6�};����B���O�8R&"�;e��J�t�����K@	���t��i�d���������6��4b`�.�>����X��5��d6���y(�rd��e5��(�����I�ȅ�vNc�C�9WU���ç�nO���Ƅ�D��m�����K=������C��:\���.��jZpF0Ān�Q�,�i},������7��q��i���`�a�G;�>d�`���� e22,'evY�>�?��\k�P���At~�_�^�7�����\�C���ۻ4��q�9om�4<>X�����Ώ��#H���3Y��5&�W�#�(����HyM;�7۴�=��l���ҍ��q�����͢���o=��*�j�B�M��(�Tc�oz)��5e_�����!������w��<�`o���Vf��e�����-�Y�K��ۮ�&���<���Z�uL*_�+�Sڜ-듡�'��|��<[���-�?݆�n'��x���J�a�p<{[I�-�����ʆ���ǳ�$<<���ޖ��0U����Ò�0%<,	S�Ò�0%<,	S�Ò�0%<,	S�Ò�0%<,	S�Ò�0%<,	S��ҷ����s������|���#
O�ٳ�(<Yf�>��d�=����$�b���+��a�e�9�I��\��"��.�S˞s�s��Wx6�S����x����vP�����+Th/{ՠz�� �����Gd*;W��Z�?nh�VnQu�=5�hC�6��:���x�����L;T�l|w2�ҖJ���6�Y��NDd*K�x��N�۾뤝ц%�7���t}����{W�l\u�>T��o����LeɃ���緮�9<?�����m��Φ�S�"2�%U<�®��fsU�E9w�֏׻�醥�S�����G���gO���@��n���,�gQx�̞}D��2{���^�v���{�p��E�)\=�V�OE�.��;�$<,���h<�{?*<,	S�Ò�0%<,	S�Ò�0%<,	S�Ò�0%<,	S�Ò�0%<,	S�Ò�0%<,	S��s�/�ӆ��IxR%<�s��'UᴢI��T�8>kӋ5�;�S�Mr\W��/hb��w�g�T�<:�X;£�R�q�W=R�cua����[G`�k�޾�^j�n��{���ܯt�gʼ�nu�7�r�Za��>h���_�������T���+C�A�C�����v���c��	*�hԍz�0t�C����wp7x��&37/���3X��h}�����.�O�ܭ�S�v��I��ԩ_�g�����	���x��@��'�;�n{u���o����w���l³I�;�,<��Jx��N	O�%<����[���{�߼�`9�    IEND�B`�                                                                                                                                                                          tree/info/classbasic__wfstream__inherit__graph.png                                                  0100644 0003673 0000144 00000001511 11704031105 0023744 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        �PNG

   IHDR   �   s   �2Ճ   !PLTE���p___���������???   ����'	   tRNS @��f  �IDATx��Mo�@�����s��UZ�)p�(�>�*��b+U��������ήM��XZ$��H�`杇�e���#ƙ�kxa�p`����p������4�|P�}$�������XZC�'.B;q)�0&n�3�������R���8P����V���.=�_��/������� ��r]	cz.����͠�0�[�3)@�o���l�΁'[r��ۈ!̬T�9���4��ܤݳד���f 8�lr !8N��=�Jz�˕2�0:"x��A����BGnL�	y�th��Bp��(&��[>�E�\�5�e��x��.���z�J���K��dzq��ǆ��^x���Kq���������������ǆǽ�����^W�~ψ5����l��Hv��#g�܀��T��.8n��yw�5����zޜ���Ȩ��(eN��������=�����/�pf��/KS1���HV����D�!��^��aE�q�	�K��{�u�Y�\P�Ҕ%�Y�����Ȼ��I�SE�Q2ⷲsA7d�M�&K�h�
_���µ,�l��QJ� ��1+��.<�J�'�|r��\H�-(7���uK����R��9Y�X{��^MIJ)� �+>��r[���xn��D,�n�Wh�x�mK<���@� �'n�7��SF�-$�J"jO��t�-�ϵ������(\�k��7������ʍn�=�m     IEND�B`�                                                                                                                                                                                       tree/info/classstd_1_1iterator__inherit__graph.png                                                  0100644 0003673 0000144 00000001616 11704031105 0023626 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        �PNG

   IHDR   �   �   ��   !PLTE���p???___���������   ���H��   tRNS @��f  IDATx��ٽSQ p�ʤ�#����~`�f,f�+Ղ{����xۉp��W��]�Cy��3��Ƚ�߬��0�-)�xE`��!�������*;�R�_%)+���{�[?������t'���������)�WG��������Q�"&/���X�n}����0ٻF=�3���]�bx��g�cg,𻆟���+?���%�\�-.1�U��	�k�2C^��m
,��,��,�
�y�wL�C�D�.�u�@�΄q���Dq�]��j5�2t�D�:�U�rF8�`bTn{�7���|�w:�U����t����� ]t���N���
�А8��8O�9n����⃾j�B���iw��5��W���U�N�"�G渣0�m��E���a��h<��D�u�n�6���́��?|_��s�ǉ��?�~
�t�a&�`����O��q+ݱ7�F�j����^\�?�m~~1��N2c�G�)OĖE&��L�J���Y����y�tr	�]�m�%w�::�H�&��8���<xn,�r_Ax��ex������U8d%4�_��FVBI�Jh��X`�X`�X`�+�s�����".������m�9;H/iT�$���NzI.�����u��3v80^�6�'���{�c�4�,i�zh��n����]y���MH���y�s��d��p+HfS;۱��}��ص�1Ks��A��q9صñK�N�m���U�ṑ�r7p~,p9��Χ�G�
C���O�S4	�U�    IEND�B`�8�`bTn{�7���|�w:�U����t����� ]t���N���
�А8��8O�9n����⃾j�B���iw��5��W���U�N�"�G渣0�m��E���atree/info/graph_legend.png                                                                          0100644 0003673 0000144 00000007426 11704031105 0017017 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        �PNG

   IHDR  �   �   `z   0PLTE����2��� � d �  p???���������___   ���L��   tRNS @��f  �IDATx���o��ǳA�����{yɹ=�B�^6�E� >.�n���A�:�N\�X�nx���d�mQ$�␎�ڲ-s:o���c~R�!m�o��?�͛���q(��k�Yךn��"�.D�]�ܻ�w!r�����;C5������g�ܰ�i���QY����*!r'eUB�Nʪ�ȝ�U	�;)�Ry,��hV�2�a,u�w���Q�l�EyT��ϵ�r"/u<���U�y�{�B�Wҽǽ|ٹU@�@���ΐ<�N��!�z7 [��9�r��ۍn�|���M��|�˕�[E��0�����]�koƻ���eG��8~2���t�O���]!'� �I<�k�I��O.;r����)}���{e��9cM&O7���K���^&}���F���/���;�@���Y�o{����W�~�h���ތ��D._J��\�s�B��*C�5�?#;ta@�/�����#��s\��eE�ܢ�c'D�ݢ�c'D�ݢ�c'DJ��IY����*!r'eUB�Nʪ�ȝ�UI�k��_�_k��ï�D:���ԁ����o�q��Z�����@�ܻ]֮@~ۥ�V�!�GW����̢B~U3"����߾���&s���wr�������W6�,��,������'�΄�B�ޅȽ�{"�.D�]�ܻ�w�;���Ƚ�{G�7P�$D.P6���RU����� 2��qwk���Ϯ��I����ϕZ�#r���k�a�vh���@l��|'��>��vD.�A�$�(���4�'�1�;��p�{G,�?���wj����$z"�.D�]�ܻ��[�B�ޅȽ�{"�.D�]�ܻ�wᩐw!r�B�ޅȽ�{"�.D�]�ܻ�TȻ�w!r�B�ޅȽ�{"�.��œx��N�-��*{?SKӌ�ɷeЁ�Wu� ��KK�-I�휟Ts����a�5�"������%"G��b!����ڄ<��fe�Hz�c�+��P���e&u�����^�e	y��d��Ʋiy45��x��d��ȝ*L����������	4C��nb7���OK��e��]fR�~�?&���\��� [ �}ٴ�ik2v�MD��Sٞz�s�,�rGD�K����E�E��R�i5�yf�O�2+�fׅn�������^D�6Oq�6�O��>�i�8$[4=}�&\�?��Q����e6[�v�?�h}�'��Gd*Fw�dk5b>w��-�;k��<���!,@k2v��Ĭ(72��F�1XC��>�|yԃ
�V푟��'����O�\��K�u;�r�g���y����.����H�C�:�hl������%�3�J�o.���S�sZ��ؽC�A�?��*,@k�ȡ7�H='�c�fER���q*�6�!��Av[�=��}������.Mi�2�����F4N�!]8�� Ck`�$���'��r�{��E��4.�'���)�ĶĬ�{�
�9r(��X��M��Z�"g�
9}A�h��7�5�=������{��	}�����B���~�hd:.E9<�SJ�%�eS	r�Α3��f��.��\����u�I��(�
{��
�'�(�􏿇��L�2�I��D9!I�o�?=� b��)���C���E�e�w�He�|� OB��h��$����+��	rE.�G�B�TP-ʇ��\�
R�O��ȯ烯e^9r��{4�.�![`��L~$�G��a�3�,���>�gꏙ�L��W[= ���^���A�Y��].�:A�r9�p������.q��\�Wa�m�z��Ǐ��������9�w�� ��Xh�&�'��mR#��揙�L������q2b��}���̀|�5^3bYO�x7��G����ΨK�]���z�b&�W[���_� ��#���%"��ȍ�#rc!r+�V �t�KSL.Dn�?A�KM1���F|��jB>o.������\��n���t-�Ye��򦌥�r����Ǭ#`�'��~ g�rs���������	����xw̭n,@Z�s��5rR�a�o�9Y�֮;�_@�/�:��y�;�r�v6�+����x����/ ��Q�����=�+!�f^�a���a}�uQ�����m�Z���oZ���
7�=2%��m�UAN�gG����r@XT�xGwm�L�UB�Rv�*�Ē�MK�2Gw�����;�J��눬:xH��1����q�g��/XU�V5䩬��r+�+D�M����2�:C�̋�~ l��z�b��$�I�Y�k^��Ca�+�XlJ�9�I�mO�-����X]͈���zUr��9�|�j�n^ؤ�~-x
��N��n����6��q!NjCn��-�M�9��v�YP����b��"�XL:`B�ڂy}V�3YYd�|n*�W� 8�dq�zk6�.�̍��<�y�I���4�.�̍���x�c�j�gS�a9S�������NR�iv1d�3�+��}�`XSU99Jf3憙�0�u�6S��`�]̾'
�<9Զ���O���zͲˡ	���&#��������ܽ����07�,&yEG�G���͠�0�EL�\C\���j�'UX�ۣ�t�ޑrqe��d��ս�M��d}^�W����5����i���� W��n����6�/�\Xg�`��Q��i������6̵A�&�9��'��bg>_\��Mp��p����z�����H�|n�J��٤�'O y2_\�Α��I/0�&?�u� :恦v�w���f2�I��~�N�@=|¤[a��i<��	�.�h�k�\�*��3ȧ�E@��&0� �D�f��X���E�<P�����~ih8Cޝ��|���F9L�:��ڥR���f(�U{�;�ŧ�ǣ��|t�c��M��0��?�K�|"W�t%sefQ�9q
�ۭ"Е��.e�K���"B.ﯴ"����U�dΔ�c�Um�7�<�(�+2�"�Ȉ��rS�F�4���E�K�7�S��9�H����4��A.&����M�:jK����=r����{��B.�.R�x�4�_�k��wֆ�\K����$�eA."~��w�:5����˘�*$U�7:Lɨ�7���y �@\��x�Ô��m"�b���"�+e�m	q��B臢r#����X��Z�\�H�<X�j+���e��4���Ay� y���>2��-�)z����R�+J*�������,D��R���J����ڃ��%�Aɤ�^$��'XB�y9Ћ�K��P�H|���[���E�A�xa5O��]r;�.�@/0/�y�l�x[��y��(�\�<O�F[��yz�y�+�[���]n\-D^�~���e�30d��J�y����\f�P�omO�R�9�Y�A�DfqF�������F��0�a�w5�G�j1�̈q�\�|F�M��J�j�&�~�<����ɜ�-��P������l�m?l�j9rH.f�?��'���У/M��{��v��ȍ�E"�.D�]9��L4%���vD^����=D�Nb�"w�m��<����F�0&��0\{��(E�l7�G��r�3]�/�?���7�/F/"X��|=�!rJ���!1G�]1�r* ��,�C�r7* �|��!�n��\�F�k�@>�#���=�X\(4Rӭ4"�.D�]�ܻ�w!r�B�ޅȽ�{"�.D�] �e"�.D�]�ܻ�w�Jr���l    IEND�B`�                                                                                                                                                                                                                                          tree/info/inherit__graph__0.png                                                                     0100644 0003673 0000144 00000000652 11704031105 0017732 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        �PNG

   IHDR   �   (   �_�{   PLTE������___���???���   �����<   tRNS @��f  :IDATx��AO�@��L�&�����`����\k��4p�",ו�y��٭�`�I��a�/߾7��z�h � ��U��N�܀���Ur��w�)rT{ ~�l�W����p�ż����^R�H�5tߴ���&9�Vӽc#�!�F*��a^���A⍥��2�c�T%<���������P ,��<���}Ey��+8�g��)-�<� !���`�����v ?��i J�
���ɇ����4L�
�2`,%h�K�g�\}���T�������� �`��Ϳr0 N��3��p�T��&�k�l    IEND�B`�                                                                                      tree/info/inherit__graph__1.png                                                                     0100644 0003673 0000144 00000000753 11704031105 0017735 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        �PNG

   IHDR   �   (   �|�0   !PLTE���p���___���???���   �����u�   tRNS @��f  xIDATx��ֱn�0 �����R#un���C�Uf*��U��AaNI��}e�Ř0�"6:��p�L`���8�QW���-D�p��z�3e]Q'5tK�r���S��k#%@Q�חv:�\G�*��6<��\�I�v���� *�a
�E�L�?l���T��iE�x�Txq�ƫ��<�>�z�Q������Q�^߽��%E�+���'��y�<���.ΐ�P��
!$� 5�l�*�6 �;A3���q%�@NQ��XW~S�A����P���S,�w�5�A��ժ����K�.�,�b���YqOA�K��J�d�'lƳZ�R0M9d�@U�L���t&a�T�b��-U���U;��W���s�(G]����8�(G�Q?�=�ĳĈ�    IEND�B`�                     tree/info/inherit__graph__2.png                                                                     0100644 0003673 0000144 00000001553 11704031105 0017735 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        �PNG

   IHDR  �   (   �Ŷ�   !PLTE���p������???___���   ����	   tRNS @��f  �IDATx��Mo�@��|ͽJı�R��J>�K���8����ZQ����7�������_�kl%��#E��3�;�]����ɿnॢ=��@-�
���P����p2������P���*J�R�T]��q�@GZJ�HAYrs���b_
�R����܏~�}��Z-@䉮"CN��){^��!|P4��P:��T!�˘�0�.Z�h�a�̃����T^�_����r��mxǲ�Ҳ��볰ӆ��jfsS����Y�t�P)�`5���L����7q�9�֬&'��	��N�8�t����T�u�5�j� ��&@9,�+��w�}��z�G�:ЉK��X���qX�-��ipi7�T���I8Q^�	��IzM6T��?:�Y޿2Ȧ@W0���f*p��e��	�����=O.Z7$���S-���N�,(��(�X6D��]dS���a��&��&Orf���Jq����|�x
km!�a��N������(�P�h�fy %��DI��y�'*v:��l�z^{����҉�
<Q��7�Y��IP\h����ÉGS|�g��۠ˡ�@���v����,ZNn̉�bNxonEQ�4���֨J6��M����Ħu1�R�`�%#�~�a<��v䮋�����Ŝ(/�$�P��'������J�����Cv;�a>>�Y��-�v/�y]�S��A�E�3��j�ץ-h)�-h�ݙQ��yV<����
�Т=�8пE�]�3��    IEND�B`�                                                                                                                                                     tree/info/inherit__graph__3.png                                                                     0100644 0003673 0000144 00000000505 11704031105 0017732 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        �PNG

   IHDR   X   (   �� �   PLTE������___???��ߟ��   ���w�Ӫ   tRNS @��f   �IDATx����
�@`ߡA���Qn��Z��/�m��e�]fj��m#%Xh�� ;+/�y�b4T���/��dX��k����G�@l�k�ܑ'`�*��}���剨o�hbIh�<7��z���]�*&n;ep#7�ڄ���")�A@r/��H�-�촰H��Ғs�)��r��f(Ơ�/����������<]��B\�|?�U\�ER���� ��ئ    IEND�B`�                                                                                                                                                                                           tree/info/inherit__graph__4.png                                                                     0100644 0003673 0000144 00000000631 11704031105 0017733 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        �PNG

   IHDR   {   (   ,�   PLTE������___???��ߟ��   ���w�Ӫ   tRNS @��f  )IDATx��AK�@��,�w��*�Հf���[��x�n��M��8��:�1VEWH=d �o�~�ٙ@zh���C�V�B�x���Kx5��(R`\l�«:ݧ���M��~!?ᷰ�Ǥ��R�h�x.(F��)�"g�<6h��E(>kq�];�bg�P�<�p�34�Vp�'�F��p������3\�a���3�d��of��=��ӽ���8iq�@�[Wz���b�w?"dw|�?��΃s���q7��7;��^fXΫ���_}�:��w<��o����4�o�� P�V�}�    IEND�B`�                                                                                                       tree/info/main_8cc__incl.png                                                                        0100644 0003673 0000144 00000003705 11704031105 0017221 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        �PNG

   IHDR  P   �   ��&   !PLTE���p������???���___   ���S���   tRNS @��f  RIDATx���S�8��/�����,�>��2����i�f���n;p����-�$�%�ĺ%`�\�rp�d��")��NJ$�I��{~z����o U5��Հ�V��Wr� @#i�l@uI{4�z��=P=E��&��qР񶀂PAv�t�`�6���)�h��@�Ȼ�W� �HF����
M��1D/��N}�&?(Я�����`�
C����:�E�=X��sp�=B/�FO�8T��0������灂V��S$�р�)��h@�I{��@$��T~"z*��_��|��.(ִ�R�#�i���-,�o �p�4ЩʀZ-\�9�O8����}dkT:��As~���*�ũ��&Y��<ȷ�pv҆yg�u)� �|	�"�e6���!��N9� �t���:d񜸼8�Pr�����@����`�n���|N��$�:���#
��o*�ʜv�(Z�$^�C;}PeN�V?�-pܨ7L�_�+�*\�
y����
�b�K�����H�+Tݐ��*}NsA�8m�F
]9�z�@�^ǐ�j�2N3P]NSP�6͍I����@��GjH��O����L��
�T��Ios��냮���&�+�z��Y3���*Z7$�j�vmN۠*����UP[��ON���0��𦠹h��o�/A���{@kԊ�3��)(��_AKP����9��F�h�I?M��^ڞ��|�SУ��)���_���25�@���I>�����Q�*=�\X�*S�Q�cA@'�A)Sc�">����t��wasꅷ��s���tL��L�5P��O�&.] 6��@{i�͝Y}9�z�G\�Z�
�����u���U����r�(h;��5Z:�v���a�KwmY}��IA_��>|(��fqy����ȍ��P��D4�,0 ���jO.49ٳ��s���|��ZaH4$d�*=���ܐ1+@9�P1�lAm��'������u�_=7F���y�z�<�_�r��-t�)�5�E�
�Rp��zH�@�tAUr�2;RR-�:�⚠�:?az*���:'�.�jhLf������+ׯ�ѽ���[�92��U����އzӅJ4�'_�����#?���F�]Xt�#k�$Ac�Bp<C�$��18DM7Y(Iи�g�[� R�s��08P���?��H ��A�HhLӳ��w����3$�Uv�H>@p�=�s�F����A0�˲���O�0R0�Jm�����j@U����j|&�-�B����6@e���#%3�r�M�9�jg7��y�@��G�VER�"ή@�W��Z��p��<�m&I��;Ъ�7piL�m&q��;PI����?<��vG�-+oH((H�_��8v�Ғ�vW�B�Hhq�b��3�g]�����6�V�.AI�R�5�q^nw��V�X�8~�c��B��݁�R5ȈB��:�b�/@���8&k���r�uu�X ����'V_nw	Z��$�s��L2�܃�r�� *�v�(�4HP��	j���� k��~�/P��@��q�1��v;"?�_H=���'�UKG{/���?w1֔�}���9��=�M���T�6Yו�5�k�/R�5�4H=O�.����y��2��A1�RΤwP�R*N �⦉0@��{�+���A�j)ȡ��(GW[[Z<��T��U빤|D �����QP=E��H���5R����k�ia�r���	����U����^��ʪ��d��"\PV4'�K�y���*hQ�"\PV���<��*(��eUA)h�V��9��t�~@B�ܲ���A�j@���P#E��H���`@�j@m�����N�K���    IEND�B`�                                                           tree/info/struct_tree_node__coll__graph.png                                                         0100644 0003673 0000144 00000003173 11704031105 0022433 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        �PNG

   IHDR   �   �   �l�   $PLTE���p�2�???������___���   �������   tRNS @��f  IDATx���=o�6 � k��^:elQ��� )jo=4��)r���=HPk.h�Q|��:�V�?W����H�Tb�< �lI��%MI��HZhG;;�_9��cC�m��!Ǥ\��5�)p�g�� X��@�%6��9����f] ~��(aȚl�r��Q:u^�l���sXA!<�
�	�A�����
�p0�ۇ�x~�8�h���"�[�|�c�v.@w��?���īo��H�o�I;���+;���_�\���]��N�D;��v#�ݜ#9p�봛s$��±���U���k�hg��vd8fC�ѐ�9����d�ʜ�c�1s;��c�P�C)t -�u�t�����[�|�s�ʜ�W�:}挔9���Ξ����ξ���N�ξ��юB������;�*��|���wz�K�viG;��Lf��=�����u�*!���?������u�Qr6���ë���|gMctC�&O&�=]U2p茑7�IE~"����ݢ�!qshܺQ7��ԃ3R��^~�����z}�e��1e.ߡ������3�0g��)H;پiG;��l_��O�u�w�׽Yi�*��y�_��@�||\����B�U��-�)̐L�U���ȎgY	Y*q�#'�i�}+8"�j�lyNaŖ��ёDEN/���"G�V�W'���bG�����n:���Q'7p���ʜ������ю�R''p�R�wDT]�wDT�����	S�9���괏،;)Nv���6pݥ]}�'OU��b�Rb�~`6�N��Y@4?���]M.:6&�.G�͸��d�������/�fܩt�����A�<NF��
o�I�!G�q$��
ܮ;ہS�lg�)G���:[����Ɯ��5�Tu��$�N"pM9�nq;��5�7�N<pJ�X��We�t���.jv��*N��v��/�	�D� p���G&�IY�o��/Tp�`�ٽA�o�D_��`"��б�ӈ���?vp|ƕ��L:�}��˄���g\�pҳ��c�{�5����+!�\�۩��G�C���gBUw�g:ksZ�Y��Vp9�:���ϸ���<n<�V�b3������Y)ꩈ~\��#�rֽ/J��Qr�q���:9�$'����"*p��qԻ͓bG�*q�c�z���;~�zh9�����^�� ����z�㞾G 6ߗ���������h~&�0��r�6n̟���9����3H���~��z��&�N%��B�� �������E�� 0��/�(?� �O�z��5�%�qE��X�\��Y4�Rę����K*���L�[P�n�A��Ny���h�	g��s鰹J��=�Z���Z@NAʾ&�ZO&[�b�SP����ܑd�3�V-�����Vw�z_h&�����(�SP��Nz�Ђ��U�T�IC,�s��������9;�n��}�
�w
�_`Z�!�F�Z����V!�NA�Lk:��m�+�ݡ���Զ��r�B'��r��v���p�*�iT�r�c    IEND�B`�                                                                                                                                                                                                                                                                                                                                                                                                     tree/info/_tree_map_8h__dep__incl.map                                                               0100644 0003673 0000144 00000000135 11704031105 0021044 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        base referer
rect $asd_8cc-source.html 148,7 207,34
rect $main_8cc-source.html 143,58 212,84
                                                                                                                                                                                                                                                                                                                                                                                                                                   tree/info/struct_tree_node__inherit__graph.png                                                      0100644 0003673 0000144 00000000775 11704031105 0023151 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        �PNG

   IHDR   ]   s   ��   !PLTE���p???������___���   ���Hэ�   tRNS @��f  �IDATx����j�@ `_!�^=�c��(H��6�j�zr�Т�6�t�Ԑ4a�);���l~h����av�g	k������M<���E_[Y{�u��yW��Ϭ��]�&y�}��#����i#��]|�L6��a��ۄ�ڳ��x%�kL��y�;��c?��&<��x�K<o<������J,�����R�P��( <1-9�8J�����������Ó�ʷ�޸8�7Z����� ]y��/=@G>2u���޴�^{����Ǿ���!����ϥ �+&U���A��>�6��	��܎��K�7+k�����з������|K@���f�|��^h; �J�Wo��`�p�Qܣ�����'��\}�y�����0��B�����|/�r>n����o����e�h=��"    IEND�B`�   tree/info/_tree_map_8h__incl.map                                                                    0100644 0003673 0000144 00000000015 11704031105 0020052 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        base referer
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   tree/info/asd_8cc__incl.map                                                                         0100644 0003673 0000144 00000000074 11704031105 0017031 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        base referer
rect $_tree_map_8h-source.html 117,159 203,186
                                                                                                                                                                                                                                                                                                                                                                                                                                                                    tree/info/class_c_count__coll__graph.map                                                            0100644 0003673 0000144 00000000015 11704031105 0021663 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        base referer
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   tree/info/class_c_count__inherit__graph.map                                                         0100644 0003673 0000144 00000000065 11704031105 0022401 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        base referer
rect $struct_tree_node.html 7,82 87,108
                                                                                                                                                                                                                                                                                                                                                                                                                                                                           tree/info/class_tree_map__coll__graph.map                                                           0100644 0003673 0000144 00000000220 11704031105 0022023 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        base referer
rect $class_tree_map_detail.html 7,199 116,225
rect $struct_tree_node.html 140,199 220,225
rect $class_c_count.html 100,97 167,124
                                                                                                                                                                                                                                                                                                                                                                                tree/info/class_tree_map_1_1const__iterator__coll__graph.map                                        0100644 0003673 0000144 00000000217 11704031105 0025610 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        base referer
rect $classstd_1_1iterator.html 7,199 407,225
rect $struct_tree_node.html 431,199 511,225
rect $class_c_count.html 391,97 457,124
                                                                                                                                                                                                                                                                                                                                                                                 tree/info/class_tree_map_1_1const__iterator__inherit__graph.map                                     0100644 0003673 0000144 00000000156 11704031105 0026323 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        base referer
rect $class_tree_map_1_1iterator.html 145,156 268,183
rect $classstd_1_1iterator.html 7,7 407,33
                                                                                                                                                                                                                                                                                                                                                                                                                  tree/info/class_tree_map_1_1iterator__coll__graph.map                                               0100644 0003673 0000144 00000000314 11704031105 0024241 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        base referer
rect $class_tree_map_1_1const__iterator.html 201,300 364,327
rect $classstd_1_1iterator.html 7,199 407,226
rect $struct_tree_node.html 431,199 511,226
rect $class_c_count.html 391,98 457,124
                                                                                                                                                                                                                                                                                                                    tree/info/class_tree_map_1_1iterator__inherit__graph.map                                            0100644 0003673 0000144 00000000164 11704031105 0024755 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        base referer
rect $class_tree_map_1_1const__iterator.html 125,81 288,108
rect $classstd_1_1iterator.html 7,7 407,33
                                                                                                                                                                                                                                                                                                                                                                                                            tree/info/inherit__graph__0.map                                                                     0100644 0003673 0000144 00000000070 11704031105 0017715 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        base referer
rect $classbasic__wfstream.html 7,7 121,33
                                                                                                                                                                                                                                                                                                                                                                                                                                                                        tree/info/classbasic__wfstream__inherit__graph.map                                                  0100644 0003673 0000144 00000000015 11704031106 0023734 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        base referer
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   tree/info/classstd_1_1iterator__inherit__graph.map                                                  0100644 0003673 0000144 00000000174 11704031106 0023616 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        base referer
rect $class_tree_map_1_1const__iterator.html 7,81 169,108
rect $class_tree_map_1_1iterator.html 27,156 149,183
                                                                                                                                                                                                                                                                                                                                                                                                    tree/info/inherit__graph__1.map                                                                     0100644 0003673 0000144 00000000131 11704031106 0017715 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        base referer
rect $class_c_count.html 7,7 74,33
rect $struct_tree_node.html 123,7 203,33
                                                                                                                                                                                                                                                                                                                                                                                                                                       tree/info/inherit__graph__2.map                                                                     0100644 0003673 0000144 00000000244 11704031106 0017723 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        base referer
rect $classstd_1_1iterator.html 7,7 71,33
rect $class_tree_map_1_1const__iterator.html 120,7 283,33
rect $class_tree_map_1_1iterator.html 333,7 456,33
                                                                                                                                                                                                                                                                                                                                                            tree/info/inherit__graph__3.map                                                                     0100644 0003673 0000144 00000000061 11704031106 0017721 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        base referer
rect $class_tree_map.html 7,7 81,33
                                                                                                                                                                                                                                                                                                                                                                                                                                                                               tree/info/inherit__graph__4.map                                                                     0100644 0003673 0000144 00000000071 11704031106 0017723 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        base referer
rect $class_tree_map_detail.html 7,7 116,33
                                                                                                                                                                                                                                                                                                                                                                                                                                                                       tree/info/main_8cc__incl.map                                                                        0100644 0003673 0000144 00000000073 11704031106 0017206 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        base referer
rect $_tree_map_8h-source.html 125,83 211,109
                                                                                                                                                                                                                                                                                                                                                                                                                                                                     tree/info/struct_tree_node__coll__graph.map                                                         0100644 0003673 0000144 00000000062 11704031106 0022417 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        base referer
rect $class_c_count.html 9,97 76,124
                                                                                                                                                                                                                                                                                                                                                                                                                                                                              tree/info/struct_tree_node__inherit__graph.map                                                      0100644 0003673 0000144 00000000061 11704031106 0023127 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        base referer
rect $class_c_count.html 13,7 80,34
                                                                                                                                                                                                                                                                                                                                                                                                                                                                               tree/info/index.hhk                                                                                 0100644 0003673 0000144 00000057336 11704031106 0015503 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        <!DOCTYPE HTML PUBLIC "-//IETF//DTD HTML//EN">
<HTML><HEAD></HEAD><BODY>
<OBJECT type="text/site properties">
<param name="FrameName" value="right">
</OBJECT>
<UL>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="asd_8cc.html"><param name="Name" value="asd.cc"></OBJECT>
  <UL>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="asd_8cc.html#e29929e8b88737e614f6df9a0f9b6def"><param name="Name" value="print"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="asd_8cc.html#5af26b3a0b1f8425bfcd62bcfe8991cc"><param name="Name" value="test"></OBJECT>
  </UL>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#6c34e3a8894af3a2160a3c0baa7e6fad"><param name="Name" value="begin"></OBJECT>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="class_c_count.html"><param name="Name" value="CCount"></OBJECT>
  <UL>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_c_count.html#56b8d3879a6fedc1932c5c2733eb7655"><param name="Name" value="CCount"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_c_count.html#e2942a04780e223b215eb8b663cf5353"><param name="Name" value="count"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_c_count.html#68b1e82502beaa137b00477d034627d5"><param name="Name" value="getCount"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_c_count.html#c0ade7f379584bcec5c868e24abd743c"><param name="Name" value="TreeNode"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_c_count.html#46a9e57e83393ebb6451f597d02d2338"><param name="Name" value="~CCount"></OBJECT>
  </UL>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#3616b8000a015689fed4b46c19c06ea2"><param name="Name" value="clear"></OBJECT>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1const__iterator.html#27f123de1dda4c35c67d132f620c5b7a"><param name="Name" value="const_iterator"></OBJECT>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="class_c_count.html#e2942a04780e223b215eb8b663cf5353"><param name="Name" value="count"></OBJECT>
  <UL>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_c_count.html#e2942a04780e223b215eb8b663cf5353"><param name="Name" value="CCount"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#1d79deabb6ad2a93ef5358356055ee3b"><param name="Name" value="TreeMap"></OBJECT>
  </UL>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="struct_tree_node.html#8d777f385d3dfec8815d20f7496026dc"><param name="Name" value="data"></OBJECT>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#951da6b7179a4f697cc89d36acf74e52"><param name="Name" value="detail"></OBJECT>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#ea1ddff44da5abff286d8b01793eb7ee"><param name="Name" value="empty"></OBJECT>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#37d6974af8ee6af64f7b4f71330853cb"><param name="Name" value="end"></OBJECT>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#f768666a08bb3f9bf6d59af014dc8a79"><param name="Name" value="erase"></OBJECT>
  <UL>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#f768666a08bb3f9bf6d59af014dc8a79"><param name="Name" value="TreeMap"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_detail.html#5637e02d8d73d541ed8c19d448ecac17"><param name="Name" value="TreeMapDetail"></OBJECT>
  </UL>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#732153e7bc56dacafa2411864b548219"><param name="Name" value="find"></OBJECT>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="class_c_count.html#68b1e82502beaa137b00477d034627d5"><param name="Name" value="getCount"></OBJECT>
  <UL>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_c_count.html#68b1e82502beaa137b00477d034627d5"><param name="Name" value="CCount"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_c_count.html#68b1e82502beaa137b00477d034627d5"><param name="Name" value="TreeNode"></OBJECT>
  </UL>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#68dd925067e3812184dcedea9211ac4b"><param name="Name" value="info_eq"></OBJECT>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#94500a970d082e87b838a94fed333521"><param name="Name" value="insert"></OBJECT>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1iterator.html#4869ea6e94137dd3c8ead09023ab2a3f"><param name="Name" value="iterator"></OBJECT>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#897356954c2cd3d41b221e3f24f99bba"><param name="Name" value="Key"></OBJECT>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="struct_tree_node.html#811882fecd5c7618d7099ebbd39ea254"><param name="Name" value="left"></OBJECT>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="main_8cc.html"><param name="Name" value="main.cc"></OBJECT>
  <UL>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="main_8cc.html#ea83b916b3f52eec32ae6d54d59b4453"><param name="Name" value="main"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="main_8cc.html#5af26b3a0b1f8425bfcd62bcfe8991cc"><param name="Name" value="test"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="main_8cc.html#da006f4ed56183a923cadf4bc85ce457"><param name="Name" value="Test2"></OBJECT>
  </UL>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="main_8cc.html#ea83b916b3f52eec32ae6d54d59b4453"><param name="Name" value="main"></OBJECT>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#6c3a6944a808a7c0bbb6788dbec54a9f"><param name="Name" value="Node"></OBJECT>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1const__iterator.html#36c4536996ca5615dcf9911f068786dc"><param name="Name" value="node"></OBJECT>
  <UL>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1const__iterator.html#36c4536996ca5615dcf9911f068786dc"><param name="Name" value="TreeMap::const_iterator"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1const__iterator.html#36c4536996ca5615dcf9911f068786dc"><param name="Name" value="TreeMap::iterator"></OBJECT>
  </UL>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1const__iterator.html#f7a39cedb9cf2cea096b6e77b4794aa2"><param name="Name" value="operator *"></OBJECT>
  <UL>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1const__iterator.html#f7a39cedb9cf2cea096b6e77b4794aa2"><param name="Name" value="TreeMap::const_iterator"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1iterator.html#f7a39cedb9cf2cea096b6e77b4794aa2"><param name="Name" value="TreeMap::iterator"></OBJECT>
  </UL>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1const__iterator.html#1afff81678307f558fa6ed1eadd24c40"><param name="Name" value="operator!="></OBJECT>
  <UL>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1const__iterator.html#1afff81678307f558fa6ed1eadd24c40"><param name="Name" value="TreeMap::const_iterator"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1const__iterator.html#1afff81678307f558fa6ed1eadd24c40"><param name="Name" value="TreeMap::iterator"></OBJECT>
  </UL>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1const__iterator.html#5d4681e027a07e3fb51ab21bef0dcc3d"><param name="Name" value="operator++"></OBJECT>
  <UL>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1const__iterator.html#5d4681e027a07e3fb51ab21bef0dcc3d"><param name="Name" value="TreeMap::const_iterator"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1iterator.html#5d4681e027a07e3fb51ab21bef0dcc3d"><param name="Name" value="TreeMap::iterator"></OBJECT>
  </UL>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1const__iterator.html#12332c0f3ca9f1be40bf725d24d260ef"><param name="Name" value="operator--"></OBJECT>
  <UL>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1const__iterator.html#12332c0f3ca9f1be40bf725d24d260ef"><param name="Name" value="TreeMap::const_iterator"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1iterator.html#12332c0f3ca9f1be40bf725d24d260ef"><param name="Name" value="TreeMap::iterator"></OBJECT>
  </UL>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1const__iterator.html#0435166b505820018f60233eb3f00662"><param name="Name" value="operator->"></OBJECT>
  <UL>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1const__iterator.html#0435166b505820018f60233eb3f00662"><param name="Name" value="TreeMap::const_iterator"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1iterator.html#0435166b505820018f60233eb3f00662"><param name="Name" value="TreeMap::iterator"></OBJECT>
  </UL>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#18b0ae91b08ac71b923d1c9dd85f7876"><param name="Name" value="operator=="></OBJECT>
  <UL>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#18b0ae91b08ac71b923d1c9dd85f7876"><param name="Name" value="TreeMap"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1const__iterator.html#af10f269139a928a53584bc453003226"><param name="Name" value="TreeMap::const_iterator"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1const__iterator.html#af10f269139a928a53584bc453003226"><param name="Name" value="TreeMap::iterator"></OBJECT>
  </UL>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#48753429045577c544d7b1765997223e"><param name="Name" value="operator="></OBJECT>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#ce20a84b60c9bcce43c37cb75d29fe50"><param name="Name" value="operator[]"></OBJECT>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#44c29edb103a2872f519ad0c9a0fdaaa"><param name="Name" value="P"></OBJECT>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="struct_tree_node.html#d0e45878043844ffc41aac437e86b602"><param name="Name" value="parent"></OBJECT>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="asd_8cc.html#e29929e8b88737e614f6df9a0f9b6def"><param name="Name" value="print"></OBJECT>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="struct_tree_node.html#7c4f29407893c334a6cb7a87bf045c0d"><param name="Name" value="right"></OBJECT>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#63a9f0ea7bb98050796b649e85481845"><param name="Name" value="root"></OBJECT>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#5a9421972c178b3c37b99f953470c6f6"><param name="Name" value="size"></OBJECT>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#3eb1f9410d79d28273ccc045cf8e6478"><param name="Name" value="size_type"></OBJECT>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#e62bc2a78904e459d5f302a5ff48769a"><param name="Name" value="struct_eq"></OBJECT>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1const__iterator.html#b9ece18c950afbfa6b0fdbfa4ff731d3"><param name="Name" value="T"></OBJECT>
  <UL>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1const__iterator.html#b9ece18c950afbfa6b0fdbfa4ff731d3"><param name="Name" value="TreeMap::const_iterator"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1const__iterator.html#b9ece18c950afbfa6b0fdbfa4ff731d3"><param name="Name" value="TreeMap::iterator"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="struct_tree_node.html#b9ece18c950afbfa6b0fdbfa4ff731d3"><param name="Name" value="TreeNode"></OBJECT>
  </UL>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="main_8cc.html#da006f4ed56183a923cadf4bc85ce457"><param name="Name" value="Test2"></OBJECT>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="asd_8cc.html#5af26b3a0b1f8425bfcd62bcfe8991cc"><param name="Name" value="test"></OBJECT>
  <UL>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="asd_8cc.html#5af26b3a0b1f8425bfcd62bcfe8991cc"><param name="Name" value="asd.cc"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="main_8cc.html#5af26b3a0b1f8425bfcd62bcfe8991cc"><param name="Name" value="main.cc"></OBJECT>
  </UL>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1const__iterator.html"><param name="Name" value="TreeMap::const_iterator"></OBJECT>
  <UL>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1const__iterator.html#27f123de1dda4c35c67d132f620c5b7a"><param name="Name" value="const_iterator"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1const__iterator.html#36c4536996ca5615dcf9911f068786dc"><param name="Name" value="node"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1const__iterator.html#f7a39cedb9cf2cea096b6e77b4794aa2"><param name="Name" value="operator *"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1const__iterator.html#1afff81678307f558fa6ed1eadd24c40"><param name="Name" value="operator!="></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1const__iterator.html#5d4681e027a07e3fb51ab21bef0dcc3d"><param name="Name" value="operator++"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1const__iterator.html#12332c0f3ca9f1be40bf725d24d260ef"><param name="Name" value="operator--"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1const__iterator.html#0435166b505820018f60233eb3f00662"><param name="Name" value="operator->"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1const__iterator.html#af10f269139a928a53584bc453003226"><param name="Name" value="operator=="></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1const__iterator.html#b9ece18c950afbfa6b0fdbfa4ff731d3"><param name="Name" value="T"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1const__iterator.html#ec21601f0dade4123a4f02c3ab309706"><param name="Name" value="TreeMap"></OBJECT>
  </UL>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1iterator.html"><param name="Name" value="TreeMap::iterator"></OBJECT>
  <UL>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1iterator.html#4869ea6e94137dd3c8ead09023ab2a3f"><param name="Name" value="iterator"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1iterator.html#36c4536996ca5615dcf9911f068786dc"><param name="Name" value="node"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1iterator.html#f7a39cedb9cf2cea096b6e77b4794aa2"><param name="Name" value="operator *"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1iterator.html#1afff81678307f558fa6ed1eadd24c40"><param name="Name" value="operator!="></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1iterator.html#5d4681e027a07e3fb51ab21bef0dcc3d"><param name="Name" value="operator++"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1iterator.html#12332c0f3ca9f1be40bf725d24d260ef"><param name="Name" value="operator--"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1iterator.html#0435166b505820018f60233eb3f00662"><param name="Name" value="operator->"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1iterator.html#af10f269139a928a53584bc453003226"><param name="Name" value="operator=="></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1iterator.html#b9ece18c950afbfa6b0fdbfa4ff731d3"><param name="Name" value="T"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1iterator.html#ec21601f0dade4123a4f02c3ab309706"><param name="Name" value="TreeMap"></OBJECT>
  </UL>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html"><param name="Name" value="TreeMap"></OBJECT>
  <UL>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#6c34e3a8894af3a2160a3c0baa7e6fad"><param name="Name" value="begin"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#3616b8000a015689fed4b46c19c06ea2"><param name="Name" value="clear"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#1d79deabb6ad2a93ef5358356055ee3b"><param name="Name" value="count"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#951da6b7179a4f697cc89d36acf74e52"><param name="Name" value="detail"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#ea1ddff44da5abff286d8b01793eb7ee"><param name="Name" value="empty"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#37d6974af8ee6af64f7b4f71330853cb"><param name="Name" value="end"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#f768666a08bb3f9bf6d59af014dc8a79"><param name="Name" value="erase"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#732153e7bc56dacafa2411864b548219"><param name="Name" value="find"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#68dd925067e3812184dcedea9211ac4b"><param name="Name" value="info_eq"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#94500a970d082e87b838a94fed333521"><param name="Name" value="insert"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#897356954c2cd3d41b221e3f24f99bba"><param name="Name" value="Key"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#6c3a6944a808a7c0bbb6788dbec54a9f"><param name="Name" value="Node"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#48753429045577c544d7b1765997223e"><param name="Name" value="operator="></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#18b0ae91b08ac71b923d1c9dd85f7876"><param name="Name" value="operator=="></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#ce20a84b60c9bcce43c37cb75d29fe50"><param name="Name" value="operator[]"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#44c29edb103a2872f519ad0c9a0fdaaa"><param name="Name" value="P"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#63a9f0ea7bb98050796b649e85481845"><param name="Name" value="root"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#5a9421972c178b3c37b99f953470c6f6"><param name="Name" value="size"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#3eb1f9410d79d28273ccc045cf8e6478"><param name="Name" value="size_type"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#e62bc2a78904e459d5f302a5ff48769a"><param name="Name" value="struct_eq"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#8c50809795fa8b8f2a3cd019e2acae62"><param name="Name" value="TreeMap"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1const__iterator.html#ec21601f0dade4123a4f02c3ab309706"><param name="Name" value="TreeMap::const_iterator"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1iterator.html#ec21601f0dade4123a4f02c3ab309706"><param name="Name" value="TreeMap::iterator"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#359f4c98a692d55e998de2a0ccbfe3c9"><param name="Name" value="TreeMapDetail"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#9b42b72518de2845832b80e44424fab3"><param name="Name" value="unsafe_insert"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#5988c20a047cfe063999787584b0aca7"><param name="Name" value="Val"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#3d396c0d29bbefef0723fb19a95dd386"><param name="Name" value="~TreeMap"></OBJECT>
  </UL>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_detail.html"><param name="Name" value="TreeMapDetail"></OBJECT>
  <UL>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_detail.html#5637e02d8d73d541ed8c19d448ecac17"><param name="Name" value="erase"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#359f4c98a692d55e998de2a0ccbfe3c9"><param name="Name" value="TreeMap"></OBJECT>
  </UL>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="class_c_count.html#c0ade7f379584bcec5c868e24abd743c"><param name="Name" value="TreeNode"></OBJECT>
  <UL>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_c_count.html#c0ade7f379584bcec5c868e24abd743c"><param name="Name" value="CCount"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="struct_tree_node.html#8d777f385d3dfec8815d20f7496026dc"><param name="Name" value="data"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="struct_tree_node.html#68b1e82502beaa137b00477d034627d5"><param name="Name" value="getCount"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="struct_tree_node.html#811882fecd5c7618d7099ebbd39ea254"><param name="Name" value="left"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="struct_tree_node.html#d0e45878043844ffc41aac437e86b602"><param name="Name" value="parent"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="struct_tree_node.html#7c4f29407893c334a6cb7a87bf045c0d"><param name="Name" value="right"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="struct_tree_node.html#b9ece18c950afbfa6b0fdbfa4ff731d3"><param name="Name" value="T"></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="struct_tree_node.html#1771ccd0efaf3c15a4bf549833e92049"><param name="Name" value="TreeNode"></OBJECT>
  </UL>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#9b42b72518de2845832b80e44424fab3"><param name="Name" value="unsafe_insert"></OBJECT>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#5988c20a047cfe063999787584b0aca7"><param name="Name" value="Val"></OBJECT>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="class_c_count.html#46a9e57e83393ebb6451f597d02d2338"><param name="Name" value="~CCount"></OBJECT>
  <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map.html#3d396c0d29bbefef0723fb19a95dd386"><param name="Name" value="~TreeMap"></OBJECT>
</UL>
558fa6ed1eadd24c40"><param name="Name" value="operator!="></OBJECT>
    <LI><OBJECT type="text/sitemap"><param name="Local" value="class_tree_map_1_1const__iterator.html#5d4681e027a07e3fb51ab21bef0dcc3d"><param name="Name" value="operator++"></OBJECT>
    <LI><OBJECT type="text/sitemap"><ptree/info/index.hhp                                                                                 0100644 0003673 0000144 00000002213 11704031106 0015470 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        [OPTIONS]
Compiled file=../AISDIc4.chm
Compatibility=1.1
Full-text search=Yes
Contents file=index.hhc
Default Window=main
Default topic=index.html
Index file=index.hhk
Language=0x409 English (United States)
Title=AISDI Cwiczenie 4

[WINDOWS]
main="AISDI Cwiczenie 4","index.hhc","index.hhk","index.html","index.html",,,,,0x23520,,0x387e,,,,,,,,0

[FILES]
index.html
files.html
asd_8cc-source.html
main_8cc-source.html
_tree_map_8h-source.html
asd_8cc.html
doxcfg_8dox.html
doxcfg3_8dox.html
main_8cc.html
_tree_map_8h.html
annotated.html
classes.html
hierarchy.html
functions.html
functions_func.html
functions_vars.html
functions_type.html
functions_rela.html
classbasic__wfstream.html
class_c_count.html
class_c_count-members.html
classstd_1_1iterator.html
class_tree_map.html
class_tree_map-members.html
class_tree_map_1_1const__iterator.html
class_tree_map_1_1const__iterator-members.html
class_tree_map_1_1iterator.html
class_tree_map_1_1iterator-members.html
class_tree_map_detail.html
class_tree_map_detail-members.html
struct_tree_node.html
struct_tree_node-members.html
todo.html
globals.html
globals_func.html
pages.html
graph_legend.html
inherits.html
                                                                                                                                                                                                                                                                                                                                                                                     tree/info/_tree_map_8h.html                                                                         0100644 0003673 0000144 00000012434 11704031106 0017106 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html><head><meta http-equiv="Content-Type" content="text/html;charset=iso-8859-1">
<title>AISDI Cwiczenie 4: TreeMap.h File Reference</title>
<link href="doxygen.css" rel="stylesheet" type="text/css">
<link href="tabs.css" rel="stylesheet" type="text/css">
</head><body>
<!-- Generated by Doxygen 1.4.5 -->
<div class="tabs">
  <ul>
    <li><a href="index.html"><span>Main&nbsp;Page</span></a></li>
    <li><a href="annotated.html"><span>Classes</span></a></li>
    <li id="current"><a href="files.html"><span>Files</span></a></li>
    <li><a href="pages.html"><span>Related&nbsp;Pages</span></a></li>
  </ul></div>
<div class="tabs">
  <ul>
    <li><a href="files.html"><span>File&nbsp;List</span></a></li>
    <li><a href="globals.html"><span>File&nbsp;Members</span></a></li>
  </ul></div>
<h1>TreeMap.h File Reference</h1>Zawiera deklaracje klasy <a class="el" href="class_tree_map.html">TreeMap</a>. <a href="#_details">More...</a>
<p>
<code>#include &lt;assert.h&gt;</code><br>
<code>#include &lt;stdlib.h&gt;</code><br>
<code>#include &lt;iterator&gt;</code><br>
<code>#include &lt;string&gt;</code><br>

<p>
Include dependency graph for TreeMap.h:<p><center><img src="_tree_map_8h__incl.png" border="0" usemap="#TreeMap.h_map" alt=""></center>

<p>
This graph shows which files directly or indirectly include this file:<p><center><img src="_tree_map_8h__dep__incl.png" border="0" usemap="#TreeMap.hdep_map" alt=""></center>
<map name="TreeMap.hdep_map">
<area href="asd_8cc-source.html" shape="rect" coords="148,7,207,34" alt="">
<area href="main_8cc-source.html" shape="rect" coords="143,58,212,84" alt="">
</map>

<p>
<a href="_tree_map_8h-source.html">Go to the source code of this file.</a><table border="0" cellpadding="0" cellspacing="0">
<tr><td></td></tr>
<tr><td colspan="2"><br><h2>Classes</h2></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top">class &nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_c_count.html">CCount</a></td></tr>

<tr><td class="mdescLeft">&nbsp;</td><td class="mdescRight">A simple instance counter for detecting memory leaks.  <a href="class_c_count.html#_details">More...</a><br></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top">struct &nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="struct_tree_node.html">TreeNode</a></td></tr>

<tr><td class="mdescLeft">&nbsp;</td><td class="mdescRight">A class to package the data into so it has the left and right hook for the tree.  <a href="struct_tree_node.html#_details">More...</a><br></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top">class &nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map.html">TreeMap</a></td></tr>

<tr><td class="mdescLeft">&nbsp;</td><td class="mdescRight">A map with a similar interface to std::map.  <a href="class_tree_map.html#_details">More...</a><br></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top">class &nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map_1_1const__iterator.html">TreeMap::const_iterator</a></td></tr>

<tr><td class="mdescLeft">&nbsp;</td><td class="mdescRight">A <a class="el" href="class_tree_map_1_1const__iterator.html">const_iterator</a>.  <a href="class_tree_map_1_1const__iterator.html#_details">More...</a><br></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top">class &nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map_1_1iterator.html">TreeMap::iterator</a></td></tr>

<tr><td class="mdescLeft">&nbsp;</td><td class="mdescRight">An iterator.  <a href="class_tree_map_1_1iterator.html#_details">More...</a><br></td></tr>
</table>
<hr><a name="_details"></a><h2>Detailed Description</h2>
Zawiera deklaracje klasy <a class="el" href="class_tree_map.html">TreeMap</a>. 
<p>
Jest to mapa (Slownik) zrobiona na drzewie binarnym. Implementacja tej klasy jest przedmiotem cwiczenia 4 na laboratoriach z AISDI.<p>
<dl compact><dt><b>Author:</b></dt><dd>Pawel Cichocki, Michal Nowacki</dd></dl>
<dl compact><dt><b>Date:</b></dt><dd>last revision<ul>
<li>2005.12.01 Pawel Cichocki: More <a class="el" href="struct_tree_node.html">TreeNode</a> constructors</li><li>2005.12.01 Pawel Cichocki: TreeNodeDetail class</li><li>2005.12.01 Michal Nowacki: Lab #4</li><li>2005.11.17 Michal Nowacki: prev pointer</li><li>2005.11.04 Pawel Cichocki: cosmetic code improvements</li><li>2005.11.04 Pawel Cichocki: a public method for obtaining the count from <a class="el" href="class_c_count.html">CCount</a></li><li>2005.11.03 Pawel Cichocki: const_iterator done properly now</li><li>2005.10.27 Pawel Cichocki: cosmetic changes</li><li>2005.10.27 Michal Nowacki: removed templates, and moved the implementation to another file</li><li>2005.10.25 Pawel Cichocki: wrote it</li></ul>
</dd></dl>
COPYRIGHT: Copyright (c) 2005 Instytut Informatyki, Politechnika Warszawska ALL RIGHTS RESERVED 
<p>
Definition in file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.<hr size="1"><address style="align: right;"><small>Generated on Fri Dec 2 01:03:51 2005 for AISDI Cwiczenie 4 by&nbsp;
<a href="http://www.doxygen.org/index.html">
<img src="doxygen.png" alt="doxygen" align="middle" border="0"></a> 1.4.5 </small></address>
</body>
</html>
                                                                                                                                                                                                                                    tree/info/_tree_map_8h-source.html                                                                  0100644 0003673 0000144 00000100571 11704031106 0020404 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html><head><meta http-equiv="Content-Type" content="text/html;charset=iso-8859-1">
<title>AISDI Cwiczenie 4: TreeMap.h Source File</title>
<link href="doxygen.css" rel="stylesheet" type="text/css">
<link href="tabs.css" rel="stylesheet" type="text/css">
</head><body>
<!-- Generated by Doxygen 1.4.5 -->
<div class="tabs">
  <ul>
    <li><a href="index.html"><span>Main&nbsp;Page</span></a></li>
    <li><a href="annotated.html"><span>Classes</span></a></li>
    <li id="current"><a href="files.html"><span>Files</span></a></li>
    <li><a href="pages.html"><span>Related&nbsp;Pages</span></a></li>
  </ul></div>
<div class="tabs">
  <ul>
    <li><a href="files.html"><span>File&nbsp;List</span></a></li>
    <li><a href="globals.html"><span>File&nbsp;Members</span></a></li>
  </ul></div>
<h1>TreeMap.h</h1><a href="_tree_map_8h.html">Go to the documentation of this file.</a><div class="fragment"><pre class="fragment"><a name="l00001"></a>00001 
<a name="l00030"></a>00030 <span class="preprocessor">#include &lt;assert.h&gt;</span>
<a name="l00031"></a>00031 <span class="preprocessor">#include &lt;stdlib.h&gt;</span>
<a name="l00032"></a>00032 <span class="preprocessor">#include &lt;iterator&gt;</span>
<a name="l00033"></a>00033 
<a name="l00034"></a>00034 <span class="preprocessor">#include &lt;string&gt;</span>
<a name="l00035"></a>00035 
<a name="l00037"></a><a class="code" href="class_c_count.html">00037</a> <span class="keyword">class </span><a class="code" href="class_c_count.html">CCount</a>
<a name="l00038"></a>00038 {
<a name="l00039"></a>00039 <span class="keyword">private</span>:
<a name="l00040"></a><a class="code" href="class_c_count.html#e2942a04780e223b215eb8b663cf5353">00040</a>   <span class="keyword">static</span> <span class="keywordtype">int</span> <a class="code" href="class_c_count.html#e2942a04780e223b215eb8b663cf5353">count</a>;
<a name="l00041"></a><a class="code" href="class_c_count.html#56b8d3879a6fedc1932c5c2733eb7655">00041</a>   <a class="code" href="class_c_count.html#56b8d3879a6fedc1932c5c2733eb7655">CCount</a>() {<a class="code" href="class_c_count.html#e2942a04780e223b215eb8b663cf5353">count</a>++;}
<a name="l00042"></a><a class="code" href="class_c_count.html#46a9e57e83393ebb6451f597d02d2338">00042</a>   <a class="code" href="class_c_count.html#46a9e57e83393ebb6451f597d02d2338">~CCount</a>()
<a name="l00043"></a>00043   {
<a name="l00044"></a>00044      assert(<a class="code" href="class_c_count.html#e2942a04780e223b215eb8b663cf5353">count</a>&gt;0);
<a name="l00045"></a>00045      <span class="comment">//if(count&gt;0) </span>
<a name="l00046"></a>00046         <a class="code" href="class_c_count.html#e2942a04780e223b215eb8b663cf5353">count</a>--;
<a name="l00047"></a>00047      <span class="comment">//else</span>
<a name="l00048"></a>00048      <span class="comment">//   cerr&lt;&lt;"ERROR (CCount): More destructors than constructors called!"&lt;&lt;std::endl;</span>
<a name="l00049"></a>00049   }
<a name="l00050"></a><a class="code" href="class_c_count.html#c0ade7f379584bcec5c868e24abd743c">00050</a>   <span class="keyword">friend</span> <span class="keyword">struct </span><a class="code" href="struct_tree_node.html">TreeNode</a>;
<a name="l00051"></a>00051 
<a name="l00052"></a>00052 <span class="keyword">public</span>:
<a name="l00054"></a><a class="code" href="class_c_count.html#68b1e82502beaa137b00477d034627d5">00054</a>    <span class="keyword">static</span> <span class="keywordtype">int</span> <a class="code" href="class_c_count.html#68b1e82502beaa137b00477d034627d5">getCount</a>() { <span class="keywordflow">return</span> <a class="code" href="class_c_count.html#e2942a04780e223b215eb8b663cf5353">count</a>; }
<a name="l00055"></a>00055 };
<a name="l00056"></a>00056 
<a name="l00058"></a>00058 <span class="comment">// TreeMap and related classes</span>
<a name="l00060"></a>00060 <span class="comment"></span>
<a name="l00062"></a><a class="code" href="struct_tree_node.html">00062</a> <span class="keyword">struct </span><a class="code" href="struct_tree_node.html">TreeNode</a> : <a class="code" href="class_c_count.html">CCount</a>
<a name="l00063"></a>00063 {
<a name="l00064"></a><a class="code" href="struct_tree_node.html#b9ece18c950afbfa6b0fdbfa4ff731d3">00064</a>    <span class="keyword">typedef</span> std::pair&lt;int,std::string&gt; <a class="code" href="struct_tree_node.html#b9ece18c950afbfa6b0fdbfa4ff731d3">T</a>;
<a name="l00065"></a><a class="code" href="struct_tree_node.html#d0e45878043844ffc41aac437e86b602">00065</a>    <a class="code" href="struct_tree_node.html">TreeNode</a>* <a class="code" href="struct_tree_node.html#d0e45878043844ffc41aac437e86b602">parent</a>;  
<a name="l00066"></a><a class="code" href="struct_tree_node.html#811882fecd5c7618d7099ebbd39ea254">00066</a>    <a class="code" href="struct_tree_node.html">TreeNode</a>* <a class="code" href="struct_tree_node.html#811882fecd5c7618d7099ebbd39ea254">left</a>;    
<a name="l00067"></a><a class="code" href="struct_tree_node.html#7c4f29407893c334a6cb7a87bf045c0d">00067</a>    <a class="code" href="struct_tree_node.html">TreeNode</a>* <a class="code" href="struct_tree_node.html#7c4f29407893c334a6cb7a87bf045c0d">right</a>;   
<a name="l00068"></a><a class="code" href="struct_tree_node.html#8d777f385d3dfec8815d20f7496026dc">00068</a>    <a class="code" href="struct_tree_node.html#b9ece18c950afbfa6b0fdbfa4ff731d3">T</a> <a class="code" href="struct_tree_node.html#8d777f385d3dfec8815d20f7496026dc">data</a>;            
<a name="l00069"></a><a class="code" href="struct_tree_node.html#1771ccd0efaf3c15a4bf549833e92049">00069</a>    <a class="code" href="struct_tree_node.html#1771ccd0efaf3c15a4bf549833e92049">TreeNode</a>(<span class="keyword">const</span> <a class="code" href="struct_tree_node.html#b9ece18c950afbfa6b0fdbfa4ff731d3">T</a>&amp; d) : <a class="code" href="struct_tree_node.html#811882fecd5c7618d7099ebbd39ea254">left</a>(NULL), <a class="code" href="struct_tree_node.html#7c4f29407893c334a6cb7a87bf045c0d">right</a>(NULL), <a class="code" href="struct_tree_node.html#8d777f385d3dfec8815d20f7496026dc">data</a>(d) {}
<a name="l00070"></a><a class="code" href="struct_tree_node.html#f80e9a2626343d444a53e15fd94e5bf3">00070</a>    <a class="code" href="struct_tree_node.html#1771ccd0efaf3c15a4bf549833e92049">TreeNode</a>(<span class="keyword">const</span> <a class="code" href="struct_tree_node.html#b9ece18c950afbfa6b0fdbfa4ff731d3">T</a>&amp; d, <a class="code" href="struct_tree_node.html">TreeNode</a>* l, <a class="code" href="struct_tree_node.html">TreeNode</a>* r) : <a class="code" href="struct_tree_node.html#d0e45878043844ffc41aac437e86b602">parent</a>(NULL), <a class="code" href="struct_tree_node.html#811882fecd5c7618d7099ebbd39ea254">left</a>(l), <a class="code" href="struct_tree_node.html#7c4f29407893c334a6cb7a87bf045c0d">right</a>(r), <a class="code" href="struct_tree_node.html#8d777f385d3dfec8815d20f7496026dc">data</a>(d) {}
<a name="l00071"></a><a class="code" href="struct_tree_node.html#9c2276854bef51bd201e5d87b7557c23">00071</a>    <a class="code" href="struct_tree_node.html#1771ccd0efaf3c15a4bf549833e92049">TreeNode</a>(<span class="keyword">const</span> <a class="code" href="struct_tree_node.html#b9ece18c950afbfa6b0fdbfa4ff731d3">T</a>&amp; d, <a class="code" href="struct_tree_node.html">TreeNode</a>* p) : <a class="code" href="struct_tree_node.html#d0e45878043844ffc41aac437e86b602">parent</a>(p), <a class="code" href="struct_tree_node.html#811882fecd5c7618d7099ebbd39ea254">left</a>(NULL), <a class="code" href="struct_tree_node.html#7c4f29407893c334a6cb7a87bf045c0d">right</a>(NULL), <a class="code" href="struct_tree_node.html#8d777f385d3dfec8815d20f7496026dc">data</a>(d) {}
<a name="l00072"></a><a class="code" href="struct_tree_node.html#d8a9895b7d52ea3650148d93a1d132ce">00072</a>    <a class="code" href="struct_tree_node.html#1771ccd0efaf3c15a4bf549833e92049">TreeNode</a>(<span class="keyword">const</span> <a class="code" href="struct_tree_node.html#b9ece18c950afbfa6b0fdbfa4ff731d3">T</a>&amp; d, <a class="code" href="struct_tree_node.html">TreeNode</a>* p, <a class="code" href="struct_tree_node.html">TreeNode</a>* l, <a class="code" href="struct_tree_node.html">TreeNode</a>* r) : <a class="code" href="struct_tree_node.html#d0e45878043844ffc41aac437e86b602">parent</a>(p), <a class="code" href="struct_tree_node.html#811882fecd5c7618d7099ebbd39ea254">left</a>(l), <a class="code" href="struct_tree_node.html#7c4f29407893c334a6cb7a87bf045c0d">right</a>(NULL), <a class="code" href="struct_tree_node.html#8d777f385d3dfec8815d20f7496026dc">data</a>(d) {}
<a name="l00073"></a>00073 };
<a name="l00074"></a>00074 
<a name="l00077"></a><a class="code" href="class_tree_map.html">00077</a> <span class="keyword">class </span><a class="code" href="class_tree_map.html">TreeMap</a>
<a name="l00078"></a>00078 {
<a name="l00079"></a><a class="code" href="class_tree_map.html#359f4c98a692d55e998de2a0ccbfe3c9">00079</a>    <span class="keyword">friend</span> <span class="keyword">class </span><a class="code" href="class_tree_map_detail.html">TreeMapDetail</a>;
<a name="l00080"></a>00080 <span class="keyword">public</span>:
<a name="l00081"></a><a class="code" href="class_tree_map.html#897356954c2cd3d41b221e3f24f99bba">00081</a>    <span class="keyword">typedef</span> <span class="keywordtype">int</span> <a class="code" href="class_tree_map.html#897356954c2cd3d41b221e3f24f99bba">Key</a>;
<a name="l00082"></a><a class="code" href="class_tree_map.html#5988c20a047cfe063999787584b0aca7">00082</a>    <span class="keyword">typedef</span> std::string <a class="code" href="class_tree_map.html#5988c20a047cfe063999787584b0aca7">Val</a>;
<a name="l00083"></a>00083 
<a name="l00084"></a>00084 <span class="keyword">protected</span>:
<a name="l00085"></a><a class="code" href="class_tree_map.html#6c3a6944a808a7c0bbb6788dbec54a9f">00085</a>    <span class="keyword">typedef</span> <a class="code" href="struct_tree_node.html">TreeNode</a><span class="comment">/*&lt;Key, Value&gt;*/</span> <a class="code" href="struct_tree_node.html">Node</a>;
<a name="l00086"></a><a class="code" href="class_tree_map.html#63a9f0ea7bb98050796b649e85481845">00086</a>    <a class="code" href="struct_tree_node.html">Node</a>* <a class="code" href="class_tree_map.html#63a9f0ea7bb98050796b649e85481845">root</a>;   
<a name="l00087"></a><a class="code" href="class_tree_map.html#951da6b7179a4f697cc89d36acf74e52">00087</a>    <a class="code" href="class_tree_map_detail.html">TreeMapDetail</a>* <a class="code" href="class_tree_map.html#951da6b7179a4f697cc89d36acf74e52">detail</a>;
<a name="l00088"></a>00088 <span class="keyword">public</span>:
<a name="l00089"></a><a class="code" href="class_tree_map.html#3eb1f9410d79d28273ccc045cf8e6478">00089</a>    <span class="keyword">typedef</span> size_t <a class="code" href="class_tree_map.html#3eb1f9410d79d28273ccc045cf8e6478">size_type</a>;
<a name="l00090"></a><a class="code" href="class_tree_map.html#44c29edb103a2872f519ad0c9a0fdaaa">00090</a>    <span class="keyword">typedef</span> std::pair&lt;Key, Val&gt; <a class="code" href="class_tree_map.html#44c29edb103a2872f519ad0c9a0fdaaa">P</a>;
<a name="l00091"></a>00091 
<a name="l00092"></a>00092    <a class="code" href="class_tree_map.html#8c50809795fa8b8f2a3cd019e2acae62">TreeMap</a>();
<a name="l00093"></a>00093    <a class="code" href="class_tree_map.html#8c50809795fa8b8f2a3cd019e2acae62">TreeMap</a>( <span class="keyword">const</span> <a class="code" href="class_tree_map.html">TreeMap</a>&amp; );
<a name="l00094"></a>00094    <a class="code" href="class_tree_map.html#3d396c0d29bbefef0723fb19a95dd386">~TreeMap</a>();
<a name="l00095"></a>00095 
<a name="l00098"></a><a class="code" href="class_tree_map_1_1const__iterator.html">00098</a>    <span class="keyword">class </span><a class="code" href="class_tree_map_1_1const__iterator.html">const_iterator</a> : <span class="keyword">public</span> std::<a class="code" href="class_tree_map_1_1iterator.html">iterator</a>&lt;std::bidirectional_iterator_tag,
<a name="l00099"></a>00099                                                std::pair&lt;Key, Val&gt; &gt;
<a name="l00100"></a>00100    {
<a name="l00101"></a>00101    <span class="keyword">public</span>:
<a name="l00102"></a><a class="code" href="class_tree_map_1_1const__iterator.html#b9ece18c950afbfa6b0fdbfa4ff731d3">00102</a>       <span class="keyword">typedef</span> std::pair&lt;Key, Val&gt; <a class="code" href="class_tree_map_1_1const__iterator.html#b9ece18c950afbfa6b0fdbfa4ff731d3">T</a>;
<a name="l00103"></a>00103 
<a name="l00104"></a>00104    <span class="keyword">protected</span>:
<a name="l00106"></a><a class="code" href="class_tree_map_1_1const__iterator.html#36c4536996ca5615dcf9911f068786dc">00106</a>       <a class="code" href="struct_tree_node.html">Node</a>* <a class="code" href="class_tree_map_1_1const__iterator.html#36c4536996ca5615dcf9911f068786dc">node</a>;
<a name="l00107"></a><a class="code" href="class_tree_map_1_1const__iterator.html#ec21601f0dade4123a4f02c3ab309706">00107</a>       <span class="keyword">friend</span> <span class="keyword">class </span><a class="code" href="class_tree_map.html">TreeMap</a>;
<a name="l00108"></a>00108 
<a name="l00109"></a><a class="code" href="class_tree_map_1_1const__iterator.html#27f123de1dda4c35c67d132f620c5b7a">00109</a>       <a class="code" href="class_tree_map_1_1const__iterator.html#645ef348f77c435481d85152ee348aa2">const_iterator</a>(<a class="code" href="struct_tree_node.html">Node</a>* x) : <a class="code" href="class_tree_map_1_1const__iterator.html#36c4536996ca5615dcf9911f068786dc">node</a>(x) {}
<a name="l00110"></a>00110    <span class="keyword">public</span>:
<a name="l00111"></a><a class="code" href="class_tree_map_1_1const__iterator.html#645ef348f77c435481d85152ee348aa2">00111</a>       <a class="code" href="class_tree_map_1_1const__iterator.html#645ef348f77c435481d85152ee348aa2">const_iterator</a>() {}
<a name="l00112"></a><a class="code" href="class_tree_map_1_1const__iterator.html#6e845f4990b76b6659a5e525ee7c917e">00112</a>       <a class="code" href="class_tree_map_1_1const__iterator.html#645ef348f77c435481d85152ee348aa2">const_iterator</a>(<span class="keyword">const</span> <a class="code" href="class_tree_map_1_1const__iterator.html">const_iterator</a>&amp; a) : <a class="code" href="class_tree_map_1_1const__iterator.html#36c4536996ca5615dcf9911f068786dc">node</a>(a.<a class="code" href="class_tree_map_1_1const__iterator.html#36c4536996ca5615dcf9911f068786dc">node</a>) {}
<a name="l00113"></a>00113 
<a name="l00114"></a><a class="code" href="class_tree_map_1_1const__iterator.html#f7a39cedb9cf2cea096b6e77b4794aa2">00114</a>       <span class="keyword">inline</span> <span class="keyword">const</span> <a class="code" href="class_tree_map_1_1const__iterator.html#b9ece18c950afbfa6b0fdbfa4ff731d3">T</a>&amp; <a class="code" href="class_tree_map_1_1const__iterator.html#f7a39cedb9cf2cea096b6e77b4794aa2">operator*</a>()<span class="keyword"> const</span>
<a name="l00115"></a>00115 <span class="keyword">      </span>{
<a name="l00116"></a>00116          <span class="keywordflow">return</span> <a class="code" href="class_tree_map_1_1const__iterator.html#36c4536996ca5615dcf9911f068786dc">node</a>-&gt;<a class="code" href="struct_tree_node.html#8d777f385d3dfec8815d20f7496026dc">data</a>;
<a name="l00117"></a>00117       }
<a name="l00118"></a>00118 
<a name="l00119"></a><a class="code" href="class_tree_map_1_1const__iterator.html#0435166b505820018f60233eb3f00662">00119</a>       <span class="keyword">inline</span> <span class="keyword">const</span> <a class="code" href="class_tree_map_1_1const__iterator.html#b9ece18c950afbfa6b0fdbfa4ff731d3">T</a>* <a class="code" href="class_tree_map_1_1const__iterator.html#0435166b505820018f60233eb3f00662">operator-&gt;</a>()<span class="keyword"> const</span>
<a name="l00120"></a>00120 <span class="keyword">      </span>{
<a name="l00121"></a>00121          <span class="keywordflow">return</span> &amp;(<a class="code" href="class_tree_map_1_1const__iterator.html#36c4536996ca5615dcf9911f068786dc">node</a>-&gt;<a class="code" href="struct_tree_node.html#8d777f385d3dfec8815d20f7496026dc">data</a>);
<a name="l00122"></a>00122       }
<a name="l00123"></a>00123 
<a name="l00124"></a>00124       <span class="comment">// preincrement</span>
<a name="l00125"></a>00125       <span class="comment">/*inline*/</span> <a class="code" href="class_tree_map_1_1const__iterator.html">const_iterator</a>&amp; <span class="keyword">operator</span>++();
<a name="l00126"></a>00126       <span class="comment">// postincrement</span>
<a name="l00127"></a>00127       <span class="comment">/*inline*/</span> <a class="code" href="class_tree_map_1_1const__iterator.html">const_iterator</a> <a class="code" href="class_tree_map_1_1const__iterator.html#879fb570af328b721ed45fe254b0a582">operator++</a>(<span class="keywordtype">int</span>);
<a name="l00128"></a>00128       <span class="comment">// predecrement</span>
<a name="l00129"></a>00129       <span class="comment">/*inline*/</span> <a class="code" href="class_tree_map_1_1const__iterator.html">const_iterator</a>&amp; <a class="code" href="class_tree_map_1_1const__iterator.html#08e169f7d9d8a763281a98d478c20a02">operator--</a>();
<a name="l00130"></a>00130       <span class="comment">// postdecrement</span>
<a name="l00131"></a>00131       <span class="comment">/*inline*/</span> <a class="code" href="class_tree_map_1_1const__iterator.html">const_iterator</a> <a class="code" href="class_tree_map_1_1const__iterator.html#08e169f7d9d8a763281a98d478c20a02">operator--</a>(<span class="keywordtype">int</span>);
<a name="l00132"></a>00132 
<a name="l00133"></a><a class="code" href="class_tree_map_1_1const__iterator.html#af10f269139a928a53584bc453003226">00133</a>       <span class="keyword">inline</span> <span class="keywordtype">bool</span> <a class="code" href="class_tree_map_1_1const__iterator.html#af10f269139a928a53584bc453003226">operator==</a>(<span class="keyword">const</span> <a class="code" href="class_tree_map_1_1const__iterator.html">const_iterator</a>&amp; a)<span class="keyword"> const</span>
<a name="l00134"></a>00134 <span class="keyword">      </span>{
<a name="l00135"></a>00135          <span class="keywordflow">return</span> <a class="code" href="class_tree_map_1_1const__iterator.html#36c4536996ca5615dcf9911f068786dc">node</a> == a.<a class="code" href="class_tree_map_1_1const__iterator.html#36c4536996ca5615dcf9911f068786dc">node</a>;
<a name="l00136"></a>00136       }
<a name="l00137"></a>00137 
<a name="l00138"></a><a class="code" href="class_tree_map_1_1const__iterator.html#1afff81678307f558fa6ed1eadd24c40">00138</a>       <span class="keyword">inline</span> <span class="keywordtype">bool</span> <a class="code" href="class_tree_map_1_1const__iterator.html#1afff81678307f558fa6ed1eadd24c40">operator!=</a>(<span class="keyword">const</span> <a class="code" href="class_tree_map_1_1const__iterator.html">const_iterator</a>&amp; a)<span class="keyword"> const</span>
<a name="l00139"></a>00139 <span class="keyword">      </span>{
<a name="l00140"></a>00140          <span class="keywordflow">return</span> <a class="code" href="class_tree_map_1_1const__iterator.html#36c4536996ca5615dcf9911f068786dc">node</a> != a.<a class="code" href="class_tree_map_1_1const__iterator.html#36c4536996ca5615dcf9911f068786dc">node</a>;
<a name="l00141"></a>00141       }
<a name="l00142"></a>00142    };
<a name="l00143"></a>00143 
<a name="l00145"></a><a class="code" href="class_tree_map_1_1iterator.html">00145</a>    <span class="keyword">class </span><a class="code" href="class_tree_map_1_1iterator.html">iterator</a> : <span class="keyword">public</span> <a class="code" href="class_tree_map_1_1const__iterator.html">const_iterator</a>
<a name="l00146"></a>00146    {
<a name="l00147"></a><a class="code" href="class_tree_map_1_1iterator.html#4869ea6e94137dd3c8ead09023ab2a3f">00147</a>       <a class="code" href="class_tree_map_1_1iterator.html">iterator</a>(<a class="code" href="struct_tree_node.html">Node</a>* x) : <a class="code" href="class_tree_map_1_1const__iterator.html">const_iterator</a>(x) {}
<a name="l00148"></a><a class="code" href="class_tree_map_1_1iterator.html#ec21601f0dade4123a4f02c3ab309706">00148</a>       <span class="keyword">friend</span> <span class="keyword">class </span><a class="code" href="class_tree_map.html">TreeMap</a>;
<a name="l00149"></a>00149 
<a name="l00150"></a>00150    <span class="keyword">public</span>:
<a name="l00151"></a><a class="code" href="class_tree_map_1_1iterator.html#c49f9eff2ae38470827eedc5b90f1eb1">00151</a>       <a class="code" href="class_tree_map_1_1iterator.html">iterator</a>() {}
<a name="l00152"></a><a class="code" href="class_tree_map_1_1iterator.html#f0f6d6b5b544eb701ae3d015e6133e1e">00152</a>       <a class="code" href="class_tree_map_1_1iterator.html">iterator</a>(<span class="keyword">const</span> <a class="code" href="class_tree_map_1_1const__iterator.html">const_iterator</a>&amp; a) : <a class="code" href="class_tree_map_1_1const__iterator.html">const_iterator</a>(a) {}
<a name="l00153"></a><a class="code" href="class_tree_map_1_1iterator.html#5c297ca07cf2a75a9b0227b654c196d9">00153</a>       <a class="code" href="class_tree_map_1_1iterator.html">iterator</a>(<span class="keyword">const</span> <a class="code" href="class_tree_map_1_1iterator.html">iterator</a>&amp; a) { <a class="code" href="class_tree_map_1_1const__iterator.html#36c4536996ca5615dcf9911f068786dc">node</a> = a.<a class="code" href="class_tree_map_1_1const__iterator.html#36c4536996ca5615dcf9911f068786dc">node</a>; }
<a name="l00154"></a>00154 
<a name="l00155"></a><a class="code" href="class_tree_map_1_1iterator.html#f7a39cedb9cf2cea096b6e77b4794aa2">00155</a>       <span class="keyword">inline</span> <a class="code" href="class_tree_map_1_1const__iterator.html#b9ece18c950afbfa6b0fdbfa4ff731d3">T</a>&amp; <a class="code" href="class_tree_map_1_1const__iterator.html#f7a39cedb9cf2cea096b6e77b4794aa2">operator*</a>()<span class="keyword"> const</span>
<a name="l00156"></a>00156 <span class="keyword">      </span>{
<a name="l00157"></a>00157          <span class="keywordflow">return</span> <a class="code" href="class_tree_map_1_1const__iterator.html#36c4536996ca5615dcf9911f068786dc">node</a>-&gt;<a class="code" href="struct_tree_node.html#8d777f385d3dfec8815d20f7496026dc">data</a>;
<a name="l00158"></a>00158       }
<a name="l00159"></a><a class="code" href="class_tree_map_1_1iterator.html#0435166b505820018f60233eb3f00662">00159</a>       <span class="keyword">inline</span> <a class="code" href="class_tree_map_1_1const__iterator.html#b9ece18c950afbfa6b0fdbfa4ff731d3">T</a>* <a class="code" href="class_tree_map_1_1const__iterator.html#0435166b505820018f60233eb3f00662">operator-&gt;</a>()<span class="keyword"> const</span>
<a name="l00160"></a>00160 <span class="keyword">      </span>{
<a name="l00161"></a>00161          <span class="keywordflow">return</span> &amp;(<a class="code" href="class_tree_map_1_1const__iterator.html#36c4536996ca5615dcf9911f068786dc">node</a>-&gt;<a class="code" href="struct_tree_node.html#8d777f385d3dfec8815d20f7496026dc">data</a>);
<a name="l00162"></a>00162       }
<a name="l00163"></a>00163 
<a name="l00164"></a><a class="code" href="class_tree_map_1_1iterator.html#879fb570af328b721ed45fe254b0a582">00164</a>       <a class="code" href="class_tree_map_1_1iterator.html">iterator</a>&amp; <span class="keyword">operator</span>++()
<a name="l00165"></a>00165       {  <span class="comment">// preincrement</span>
<a name="l00166"></a>00166          ++(*(<a class="code" href="class_tree_map_1_1const__iterator.html">const_iterator</a>*)<span class="keyword">this</span>);
<a name="l00167"></a>00167          <span class="keywordflow">return</span> (*<span class="keyword">this</span>);
<a name="l00168"></a>00168       }
<a name="l00169"></a>00169 
<a name="l00170"></a><a class="code" href="class_tree_map_1_1iterator.html#5d4681e027a07e3fb51ab21bef0dcc3d">00170</a>       <a class="code" href="class_tree_map_1_1iterator.html">iterator</a> <a class="code" href="class_tree_map_1_1const__iterator.html#879fb570af328b721ed45fe254b0a582">operator++</a>(<span class="keywordtype">int</span>)
<a name="l00171"></a>00171       {  <span class="comment">// postincrement</span>
<a name="l00172"></a>00172          <a class="code" href="class_tree_map_1_1iterator.html">iterator</a> temp = *<span class="keyword">this</span>;
<a name="l00173"></a>00173          ++*<span class="keyword">this</span>;
<a name="l00174"></a>00174          <span class="keywordflow">return</span> temp;
<a name="l00175"></a>00175       }
<a name="l00176"></a>00176 
<a name="l00177"></a><a class="code" href="class_tree_map_1_1iterator.html#08e169f7d9d8a763281a98d478c20a02">00177</a>       <a class="code" href="class_tree_map_1_1iterator.html">iterator</a>&amp; <a class="code" href="class_tree_map_1_1const__iterator.html#08e169f7d9d8a763281a98d478c20a02">operator--</a>()
<a name="l00178"></a>00178       {  <span class="comment">// predecrement</span>
<a name="l00179"></a>00179          --(*(<a class="code" href="class_tree_map_1_1const__iterator.html">const_iterator</a>*)<span class="keyword">this</span>);
<a name="l00180"></a>00180          <span class="keywordflow">return</span> (*<span class="keyword">this</span>);
<a name="l00181"></a>00181       }
<a name="l00182"></a>00182 
<a name="l00183"></a><a class="code" href="class_tree_map_1_1iterator.html#12332c0f3ca9f1be40bf725d24d260ef">00183</a>       <a class="code" href="class_tree_map_1_1iterator.html">iterator</a> <a class="code" href="class_tree_map_1_1const__iterator.html#08e169f7d9d8a763281a98d478c20a02">operator--</a>(<span class="keywordtype">int</span>)
<a name="l00184"></a>00184       {  <span class="comment">// postdecrement</span>
<a name="l00185"></a>00185          <a class="code" href="class_tree_map_1_1iterator.html">iterator</a> temp = *<span class="keyword">this</span>;
<a name="l00186"></a>00186          --*<span class="keyword">this</span>;
<a name="l00187"></a>00187          <span class="keywordflow">return</span> temp;
<a name="l00188"></a>00188       }
<a name="l00189"></a>00189    };
<a name="l00190"></a>00190    
<a name="l00192"></a>00192    <span class="keyword">inline</span> <a class="code" href="classstd_1_1iterator.html">iterator</a> <a class="code" href="class_tree_map.html#4b1a01a7db76e79c6194363c78d33615">begin</a>();
<a name="l00194"></a>00194    <span class="keyword">inline</span> <a class="code" href="class_tree_map_1_1const__iterator.html#645ef348f77c435481d85152ee348aa2">const_iterator</a> <a class="code" href="class_tree_map.html#4b1a01a7db76e79c6194363c78d33615">begin</a>() <span class="keyword">const</span>;
<a name="l00195"></a>00195 
<a name="l00197"></a>00197    <span class="keyword">inline</span> <a class="code" href="classstd_1_1iterator.html">iterator</a> <a class="code" href="class_tree_map.html#f34c4b013e5d012ab5f1bfef486d630f">end</a>();
<a name="l00199"></a>00199    <span class="keyword">inline</span> <a class="code" href="class_tree_map_1_1const__iterator.html#645ef348f77c435481d85152ee348aa2">const_iterator</a> <a class="code" href="class_tree_map.html#f34c4b013e5d012ab5f1bfef486d630f">end</a>() <span class="keyword">const</span>;
<a name="l00200"></a>00200    
<a name="l00207"></a>00207    std::pair&lt;iterator, bool&gt; <a class="code" href="class_tree_map.html#94500a970d082e87b838a94fed333521">insert</a>(<span class="keyword">const</span> std::pair&lt;Key, Val&gt;&amp; entry);
<a name="l00208"></a>00208 
<a name="l00212"></a>00212    <a class="code" href="classstd_1_1iterator.html">iterator</a> <a class="code" href="class_tree_map.html#9b42b72518de2845832b80e44424fab3">unsafe_insert</a>(<span class="keyword">const</span> std::pair&lt;Key, Val&gt;&amp; entry);
<a name="l00213"></a>00213 
<a name="l00217"></a>00217    <a class="code" href="classstd_1_1iterator.html">iterator</a> <a class="code" href="class_tree_map.html#da5bc54e6c1da79235e9160ee021b9f5">find</a>(<span class="keyword">const</span> <a class="code" href="class_tree_map.html#897356954c2cd3d41b221e3f24f99bba">Key</a>&amp; k);
<a name="l00218"></a>00218    <a class="code" href="class_tree_map_1_1const__iterator.html#645ef348f77c435481d85152ee348aa2">const_iterator</a> <a class="code" href="class_tree_map.html#da5bc54e6c1da79235e9160ee021b9f5">find</a>(<span class="keyword">const</span> <a class="code" href="class_tree_map.html#897356954c2cd3d41b221e3f24f99bba">Key</a>&amp; k) <span class="keyword">const</span>;
<a name="l00219"></a>00219  
<a name="l00220"></a>00220    <span class="comment">//bool belongs( const Key&amp; k) const;</span>
<a name="l00221"></a>00221 
<a name="l00225"></a>00225    <a class="code" href="class_tree_map.html#5988c20a047cfe063999787584b0aca7">Val</a>&amp; <a class="code" href="class_tree_map.html#ce20a84b60c9bcce43c37cb75d29fe50">operator[]</a>(<span class="keyword">const</span> <a class="code" href="class_tree_map.html#897356954c2cd3d41b221e3f24f99bba">Key</a>&amp; k);   
<a name="l00226"></a>00226 
<a name="l00228"></a>00228    <span class="keywordtype">bool</span> <a class="code" href="class_tree_map.html#ea1ddff44da5abff286d8b01793eb7ee">empty</a>( ) <span class="keyword">const</span>;
<a name="l00229"></a>00229 
<a name="l00231"></a>00231    <a class="code" href="class_tree_map.html#3eb1f9410d79d28273ccc045cf8e6478">size_type</a> <a class="code" href="class_tree_map.html#5a9421972c178b3c37b99f953470c6f6">size</a>() <span class="keyword">const</span>;
<a name="l00232"></a>00232 
<a name="l00234"></a>00234    <a class="code" href="class_tree_map.html#3eb1f9410d79d28273ccc045cf8e6478">size_type</a> <a class="code" href="class_tree_map.html#1d79deabb6ad2a93ef5358356055ee3b">count</a>(<span class="keyword">const</span> <a class="code" href="class_tree_map.html#897356954c2cd3d41b221e3f24f99bba">Key</a>&amp; _Key) <span class="keyword">const</span>;
<a name="l00235"></a>00235 
<a name="l00238"></a>00238    <a class="code" href="classstd_1_1iterator.html">iterator</a> <a class="code" href="class_tree_map.html#99d178e178a2d0a71c1f5698c5879dcf">erase</a>(<a class="code" href="classstd_1_1iterator.html">iterator</a> i);
<a name="l00239"></a>00239    
<a name="l00244"></a>00244    <a class="code" href="classstd_1_1iterator.html">iterator</a> <a class="code" href="class_tree_map.html#99d178e178a2d0a71c1f5698c5879dcf">erase</a>(<a class="code" href="classstd_1_1iterator.html">iterator</a> first, <a class="code" href="classstd_1_1iterator.html">iterator</a> last);
<a name="l00245"></a>00245    
<a name="l00249"></a>00249    <a class="code" href="class_tree_map.html#3eb1f9410d79d28273ccc045cf8e6478">size_type</a> <a class="code" href="class_tree_map.html#99d178e178a2d0a71c1f5698c5879dcf">erase</a>(<span class="keyword">const</span> <a class="code" href="class_tree_map.html#897356954c2cd3d41b221e3f24f99bba">Key</a>&amp; key);
<a name="l00250"></a>00250 
<a name="l00252"></a>00252    <span class="keywordtype">void</span> <a class="code" href="class_tree_map.html#3616b8000a015689fed4b46c19c06ea2">clear</a>( );
<a name="l00253"></a>00253    
<a name="l00255"></a>00255    <span class="keywordtype">bool</span> <a class="code" href="class_tree_map.html#e62bc2a78904e459d5f302a5ff48769a">struct_eq</a>(<span class="keyword">const</span> <a class="code" href="class_tree_map.html">TreeMap</a>&amp; another) <span class="keyword">const</span>;
<a name="l00257"></a>00257    <span class="keywordtype">bool</span> <a class="code" href="class_tree_map.html#68dd925067e3812184dcedea9211ac4b">info_eq</a>(<span class="keyword">const</span> <a class="code" href="class_tree_map.html">TreeMap</a>&amp; another) <span class="keyword">const</span>;
<a name="l00258"></a>00258 
<a name="l00260"></a><a class="code" href="class_tree_map.html#18b0ae91b08ac71b923d1c9dd85f7876">00260</a>    <span class="keyword">inline</span> <span class="keywordtype">bool</span> <a class="code" href="class_tree_map.html#18b0ae91b08ac71b923d1c9dd85f7876">TreeMap::operator==</a>(<span class="keyword">const</span> <a class="code" href="class_tree_map.html">TreeMap</a>&amp; a)<span class="keyword"> const </span>{ <span class="keywordflow">return</span> <a class="code" href="class_tree_map.html#68dd925067e3812184dcedea9211ac4b">info_eq</a>(a); }
<a name="l00261"></a>00261    
<a name="l00263"></a>00263    <a class="code" href="class_tree_map.html">TreeMap</a>&amp; <a class="code" href="class_tree_map.html#48753429045577c544d7b1765997223e">operator=</a>(<span class="keyword">const</span> <a class="code" href="class_tree_map.html">TreeMap</a>&amp; );
<a name="l00264"></a>00264 };
<a name="l00265"></a>00265 
</pre></div><hr size="1"><address style="align: right;"><small>Generated on Fri Dec 2 01:03:51 2005 for AISDI Cwiczenie 4 by&nbsp;
<a href="http://www.doxygen.org/index.html">
<img src="doxygen.png" alt="doxygen" align="middle" border="0"></a> 1.4.5 </small></address>
</body>
</html>
6b505820018f60233eb3f00662">operator-&gt;</a>()<span class="keyword"> const</span>
<a name="l00160"></a>00160 <span class="keyword">   tree/info/annotated.html                                                                            0100644 0003673 0000144 00000005264 11704031106 0016534 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html><head><meta http-equiv="Content-Type" content="text/html;charset=iso-8859-1">
<title>AISDI Cwiczenie 4: Class List</title>
<link href="doxygen.css" rel="stylesheet" type="text/css">
<link href="tabs.css" rel="stylesheet" type="text/css">
</head><body>
<!-- Generated by Doxygen 1.4.5 -->
<div class="tabs">
  <ul>
    <li><a href="index.html"><span>Main&nbsp;Page</span></a></li>
    <li id="current"><a href="annotated.html"><span>Classes</span></a></li>
    <li><a href="files.html"><span>Files</span></a></li>
    <li><a href="pages.html"><span>Related&nbsp;Pages</span></a></li>
  </ul></div>
<div class="tabs">
  <ul>
    <li id="current"><a href="annotated.html"><span>Class&nbsp;List</span></a></li>
    <li><a href="classes.html"><span>Alphabetical&nbsp;List</span></a></li>
    <li><a href="hierarchy.html"><span>Class&nbsp;Hierarchy</span></a></li>
    <li><a href="functions.html"><span>Class&nbsp;Members</span></a></li>
  </ul></div>
<h1>AISDI Cwiczenie 4 Class List</h1>Here are the classes, structs, unions and interfaces with brief descriptions:<table>
  <tr><td class="indexkey"><a class="el" href="classbasic__wfstream.html">basic_wfstream</a></td><td class="indexvalue"></td></tr>
  <tr><td class="indexkey"><a class="el" href="class_c_count.html">CCount</a></td><td class="indexvalue">A simple instance counter for detecting memory leaks </td></tr>
  <tr><td class="indexkey"><a class="el" href="classstd_1_1iterator.html">iterator</a></td><td class="indexvalue"></td></tr>
  <tr><td class="indexkey"><a class="el" href="class_tree_map.html">TreeMap</a></td><td class="indexvalue">A map with a similar interface to std::map </td></tr>
  <tr><td class="indexkey"><a class="el" href="class_tree_map_1_1const__iterator.html">TreeMap::const_iterator</a></td><td class="indexvalue">A <a class="el" href="class_tree_map_1_1const__iterator.html">const_iterator</a> </td></tr>
  <tr><td class="indexkey"><a class="el" href="class_tree_map_1_1iterator.html">TreeMap::iterator</a></td><td class="indexvalue">An iterator </td></tr>
  <tr><td class="indexkey"><a class="el" href="class_tree_map_detail.html">TreeMapDetail</a></td><td class="indexvalue">A helper class </td></tr>
  <tr><td class="indexkey"><a class="el" href="struct_tree_node.html">TreeNode</a></td><td class="indexvalue">A class to package the data into so it has the left and right hook for the tree </td></tr>
</table>
<hr size="1"><address style="align: right;"><small>Generated on Fri Dec 2 01:03:51 2005 for AISDI Cwiczenie 4 by&nbsp;
<a href="http://www.doxygen.org/index.html">
<img src="doxygen.png" alt="doxygen" align="middle" border="0"></a> 1.4.5 </small></address>
</body>
</html>
                                                                                                                                                                                                                                                                                                                                            tree/info/asd_8cc.html                                                                              0100644 0003673 0000144 00000015250 11704031106 0016057 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html><head><meta http-equiv="Content-Type" content="text/html;charset=iso-8859-1">
<title>AISDI Cwiczenie 4: asd.cc File Reference</title>
<link href="doxygen.css" rel="stylesheet" type="text/css">
<link href="tabs.css" rel="stylesheet" type="text/css">
</head><body>
<!-- Generated by Doxygen 1.4.5 -->
<div class="tabs">
  <ul>
    <li><a href="index.html"><span>Main&nbsp;Page</span></a></li>
    <li><a href="annotated.html"><span>Classes</span></a></li>
    <li id="current"><a href="files.html"><span>Files</span></a></li>
    <li><a href="pages.html"><span>Related&nbsp;Pages</span></a></li>
  </ul></div>
<div class="tabs">
  <ul>
    <li><a href="files.html"><span>File&nbsp;List</span></a></li>
    <li><a href="globals.html"><span>File&nbsp;Members</span></a></li>
  </ul></div>
<h1>asd.cc File Reference</h1>Plik do modyfikacji w w ramach cwiczenia 4 z AISDI. <a href="#_details">More...</a>
<p>
<code>#include &lt;assert.h&gt;</code><br>
<code>#include &lt;algorithm&gt;</code><br>
<code>#include &lt;iostream&gt;</code><br>
<code>#include &quot;<a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>&quot;</code><br>
<code>#include &lt;map&gt;</code><br>

<p>
Include dependency graph for asd.cc:<p><center><img src="asd_8cc__incl.png" border="0" usemap="#asd.cc_map" alt=""></center>
<map name="asd.cc_map">
<area href="_tree_map_8h-source.html" shape="rect" coords="117,159,203,186" alt="">
</map>

<p>
<a href="asd_8cc-source.html">Go to the source code of this file.</a><table border="0" cellpadding="0" cellspacing="0">
<tr><td></td></tr>
<tr><td colspan="2"><br><h2>Classes</h2></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top">class &nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map_detail.html">TreeMapDetail</a></td></tr>

<tr><td class="mdescLeft">&nbsp;</td><td class="mdescRight">A helper class.  <a href="class_tree_map_detail.html#_details">More...</a><br></td></tr>
<tr><td colspan="2"><br><h2>Functions</h2></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top">void&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="asd_8cc.html#e29929e8b88737e614f6df9a0f9b6def">print</a> (const std::pair&lt; int, std::string &gt; &amp;p)</td></tr>

<tr><td class="mdescLeft">&nbsp;</td><td class="mdescRight">A helper function that outputs a key-value pair.  <a href="#e29929e8b88737e614f6df9a0f9b6def"></a><br></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top">void&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="asd_8cc.html#5af26b3a0b1f8425bfcd62bcfe8991cc">test</a> ()</td></tr>

<tr><td class="mdescLeft">&nbsp;</td><td class="mdescRight">The big mean test function ;).  <a href="#5af26b3a0b1f8425bfcd62bcfe8991cc"></a><br></td></tr>
</table>
<hr><a name="_details"></a><h2>Detailed Description</h2>
Plik do modyfikacji w w ramach cwiczenia 4 z AISDI. 
<p>
Zawiera niekompletne implementacje metod klasy <a class="el" href="class_tree_map.html">TreeMap</a>. Jest tez prosta funkcja testujaca (void <a class="el" href="asd_8cc.html#5af26b3a0b1f8425bfcd62bcfe8991cc">test()</a>), ktora jest wolana w funkcji main. Mozna w niej zaimplementowac wlasne testy. NALEZY ZMODYFIKOWAC I UZUPELNIC CIALA METOD KLASY <a class="el" href="class_tree_map.html">TreeMap</a>.<p>
<dl compact><dt><b>Author:</b></dt><dd>Pawel Cichocki, Michal Nowacki</dd></dl>
<dl compact><dt><b>Date:</b></dt><dd>last revision<ul>
<li>2005.12.01 Pawel Cichocki: TreeNodeDetail class</li><li>2005.12.01 Michal Nowacki: lab #4</li><li>2005.11.17 Michal Nowacki: lab #3, copy operator and constructor</li><li>2005.11.04 Pawel Cichocki: copied comments from the header</li><li>2005.11.03 Pawel Cichocki: const_iterator done properly now</li><li>2005.10.27 Pawel Cichocki: cosmetic changes</li><li>2005.10.26 Michal Nowacki: removed some method bodies</li><li>2005.10.25 Pawel Cichocki: wrote it</li></ul>
</dd></dl>
COPYRIGHT: Copyright (c) 2005 Instytut Informatyki, Politechnika Warszawska ALL RIGHTS RESERVED 
<p>
Definition in file <a class="el" href="asd_8cc-source.html">asd.cc</a>.<hr><h2>Function Documentation</h2>
<a class="anchor" name="e29929e8b88737e614f6df9a0f9b6def"></a><!-- doxytag: member="asd.cc::print" ref="e29929e8b88737e614f6df9a0f9b6def" args="(const std::pair&lt; int, std::string &gt; &amp;p)" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">void print           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="md" nowrap valign="top">const std::pair&lt; int, std::string &gt; &amp;&nbsp;</td>
          <td class="mdname1" valign="top" nowrap> <em>p</em>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>
A helper function that outputs a key-value pair. 
<p>

<p>
Definition at line <a class="el" href="asd_8cc-source.html#l00273">273</a> of file <a class="el" href="asd_8cc-source.html">asd.cc</a>.
<p>
Referenced by <a class="el" href="asd_8cc-source.html#l00281">test()</a>.    </td>
  </tr>
</table>
<a class="anchor" name="5af26b3a0b1f8425bfcd62bcfe8991cc"></a><!-- doxytag: member="asd.cc::test" ref="5af26b3a0b1f8425bfcd62bcfe8991cc" args="()" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">void test           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="mdname1" valign="top" nowrap>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>
The big mean test function ;). 
<p>

<p>
Definition at line <a class="el" href="asd_8cc-source.html#l00281">281</a> of file <a class="el" href="asd_8cc-source.html">asd.cc</a>.
<p>
References <a class="el" href="asd_8cc-source.html#l00273">print()</a>.
<p>
Referenced by <a class="el" href="main_8cc-source.html#l00033">main()</a>.    </td>
  </tr>
</table>
<hr size="1"><address style="align: right;"><small>Generated on Fri Dec 2 01:03:51 2005 for AISDI Cwiczenie 4 by&nbsp;
<a href="http://www.doxygen.org/index.html">
<img src="doxygen.png" alt="doxygen" align="middle" border="0"></a> 1.4.5 </small></address>
</body>
</html>
s="mdescLeft">&nbsp;</td><td class="mdescRight">The big mean test function ;).  <a href="#5af26b3a0b1f8425bfcd62bcfe8991cc"></a><br></td></tr>
</table>
<hr><a name="_details"></a><h2>Detailed Description</h2>
Plik do modyfikacji w w ramach cwiczenia 4 z AISDI. 
<p>
Zawiera niekompletne implementacje metod klasy <a class="el" href="class_tree_tree/info/asd_8cc-source.html                                                                       0100644 0003673 0000144 00000064213 11704031106 0017360 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html><head><meta http-equiv="Content-Type" content="text/html;charset=iso-8859-1">
<title>AISDI Cwiczenie 4: asd.cc Source File</title>
<link href="doxygen.css" rel="stylesheet" type="text/css">
<link href="tabs.css" rel="stylesheet" type="text/css">
</head><body>
<!-- Generated by Doxygen 1.4.5 -->
<div class="tabs">
  <ul>
    <li><a href="index.html"><span>Main&nbsp;Page</span></a></li>
    <li><a href="annotated.html"><span>Classes</span></a></li>
    <li id="current"><a href="files.html"><span>Files</span></a></li>
    <li><a href="pages.html"><span>Related&nbsp;Pages</span></a></li>
  </ul></div>
<div class="tabs">
  <ul>
    <li><a href="files.html"><span>File&nbsp;List</span></a></li>
    <li><a href="globals.html"><span>File&nbsp;Members</span></a></li>
  </ul></div>
<h1>asd.cc</h1><a href="asd_8cc.html">Go to the documentation of this file.</a><div class="fragment"><pre class="fragment"><a name="l00001"></a>00001 
<a name="l00030"></a>00030 <span class="preprocessor">#include &lt;assert.h&gt;</span>
<a name="l00031"></a>00031 <span class="preprocessor">#include &lt;algorithm&gt;</span>
<a name="l00032"></a>00032 
<a name="l00033"></a>00033 <span class="preprocessor">#include &lt;iostream&gt;</span>
<a name="l00034"></a>00034 
<a name="l00035"></a>00035 <span class="preprocessor">#ifdef _SUNOS</span>
<a name="l00036"></a>00036 <span class="preprocessor"></span><span class="preprocessor">#include "/home/common/dyd/aisdi/z4/TreeMap.h"</span> 
<a name="l00037"></a>00037 <span class="preprocessor">#else</span>
<a name="l00038"></a>00038 <span class="preprocessor"></span><span class="preprocessor">#include "<a class="code" href="_tree_map_8h.html">TreeMap.h</a>"</span>
<a name="l00039"></a>00039 <span class="preprocessor">#endif</span>
<a name="l00040"></a>00040 <span class="preprocessor"></span>
<a name="l00042"></a><a class="code" href="class_tree_map_detail.html">00042</a> <span class="keyword">class </span><a class="code" href="class_tree_map_detail.html">TreeMapDetail</a> <span class="comment">//Helper</span>
<a name="l00043"></a>00043 {
<a name="l00044"></a>00044 <span class="keyword">protected</span>:
<a name="l00045"></a><a class="code" href="class_tree_map_detail.html#ec21601f0dade4123a4f02c3ab309706">00045</a>    <span class="keyword">friend</span> <span class="keyword">class </span><a class="code" href="class_tree_map.html">TreeMap</a>;
<a name="l00046"></a>00046 
<a name="l00050"></a><a class="code" href="class_tree_map_detail.html#5637e02d8d73d541ed8c19d448ecac17">00050</a>    <span class="keyword">static</span> <span class="keywordtype">void</span> <a class="code" href="class_tree_map_detail.html#5637e02d8d73d541ed8c19d448ecac17">erase</a>(<a class="code" href="class_tree_map.html">TreeMap</a>* tm, <span class="keyword">const</span> <a class="code" href="class_tree_map.html#897356954c2cd3d41b221e3f24f99bba">TreeMap::Key</a>&amp; k)
<a name="l00051"></a>00051    {
<a name="l00052"></a>00052       tm-&gt;<a class="code" href="class_tree_map.html#63a9f0ea7bb98050796b649e85481845">root</a>=NULL; <span class="comment">// we just modified a protected field in tree map</span>
<a name="l00053"></a>00053    }
<a name="l00054"></a>00054 };
<a name="l00055"></a>00055 
<a name="l00057"></a>00057 <span class="comment">// TreeMap and TreeMap::iterator methods</span>
<a name="l00059"></a>00059 <span class="comment"></span>
<a name="l00060"></a><a class="code" href="class_tree_map.html#8c50809795fa8b8f2a3cd019e2acae62">00060</a> <a class="code" href="class_tree_map.html#8c50809795fa8b8f2a3cd019e2acae62">TreeMap::TreeMap</a>()
<a name="l00061"></a>00061 {
<a name="l00062"></a>00062    <a class="code" href="class_tree_map.html#63a9f0ea7bb98050796b649e85481845">root</a> = NULL;
<a name="l00063"></a>00063 };
<a name="l00064"></a>00064 
<a name="l00066"></a><a class="code" href="class_tree_map.html#36057872ebdcdb89755ff678ad8a5179">00066</a> <a class="code" href="class_tree_map.html#8c50809795fa8b8f2a3cd019e2acae62">TreeMap::TreeMap</a>( <span class="keyword">const</span> <a class="code" href="class_tree_map.html">TreeMap</a>&amp; m )
<a name="l00067"></a>00067 {
<a name="l00069"></a>00069 };
<a name="l00070"></a>00070 
<a name="l00071"></a><a class="code" href="class_tree_map.html#3d396c0d29bbefef0723fb19a95dd386">00071</a> <a class="code" href="class_tree_map.html#3d396c0d29bbefef0723fb19a95dd386">TreeMap::~TreeMap</a>()
<a name="l00072"></a>00072 {
<a name="l00073"></a>00073    <a class="code" href="class_tree_map.html#3616b8000a015689fed4b46c19c06ea2">clear</a>();
<a name="l00074"></a>00074 };
<a name="l00075"></a>00075 
<a name="l00076"></a>00076 <span class="comment">// Inserts an element into the map.</span>
<a name="l00077"></a>00077 
<a name="l00078"></a>00078 <span class="comment">// @returns A pair whose bool component is true if an insertion was</span>
<a name="l00079"></a>00079 <span class="comment">//          made and false if the map already contained an element</span>
<a name="l00080"></a>00080 <span class="comment">//          associated with that key, and whose iterator component coresponds to</span>
<a name="l00081"></a>00081 <span class="comment">//          the address where a new element was inserted or where the element</span>
<a name="l00082"></a><a class="code" href="class_tree_map.html#94500a970d082e87b838a94fed333521">00082</a> <span class="comment">//          was already located.</span>
<a name="l00083"></a>00083 std::pair&lt;TreeMap::iterator, bool&gt; <a class="code" href="class_tree_map.html#94500a970d082e87b838a94fed333521">TreeMap::insert</a>(<span class="keyword">const</span> std::pair&lt;Key, Val&gt;&amp; entry)
<a name="l00084"></a>00084 {
<a name="l00086"></a>00086    <a class="code" href="class_tree_map_1_1iterator.html">iterator</a> i;
<a name="l00087"></a>00087    <span class="keywordflow">for</span>(i=<a class="code" href="class_tree_map.html#4b1a01a7db76e79c6194363c78d33615">begin</a>(); i!=<a class="code" href="class_tree_map.html#f34c4b013e5d012ab5f1bfef486d630f">end</a>(); ++i)
<a name="l00088"></a>00088    {
<a name="l00089"></a>00089       <span class="keywordflow">if</span>(i-&gt;first==entry.first)
<a name="l00090"></a>00090         <span class="keywordflow">return</span> std::make_pair(i, (<span class="keywordtype">bool</span>)<span class="keyword">false</span>);
<a name="l00091"></a>00091    }
<a name="l00092"></a>00092         <span class="keywordflow">return</span> std::make_pair(i, (<span class="keywordtype">bool</span>)<span class="keyword">false</span>);
<a name="l00093"></a>00093 }
<a name="l00094"></a>00094 
<a name="l00095"></a>00095 <span class="comment">// Inserts an element into the map.</span>
<a name="l00096"></a>00096 <span class="comment">// This method assumes there is no value asociated with</span>
<a name="l00097"></a><a class="code" href="class_tree_map.html#9b42b72518de2845832b80e44424fab3">00097</a> <span class="comment">// such a key in the map.</span>
<a name="l00098"></a>00098 
<a name="l00099"></a>00099 <a class="code" href="class_tree_map_1_1iterator.html">TreeMap::iterator</a> <a class="code" href="class_tree_map.html#9b42b72518de2845832b80e44424fab3">TreeMap::unsafe_insert</a>(<span class="keyword">const</span> std::pair&lt;Key, Val&gt;&amp; entry)
<a name="l00100"></a>00100 {
<a name="l00102"></a>00102    assert(0);
<a name="l00103"></a>00103    <span class="keywordflow">return</span> <a class="code" href="class_tree_map_1_1iterator.html">iterator</a>(<a class="code" href="class_tree_map.html#63a9f0ea7bb98050796b649e85481845">root</a>);
<a name="l00104"></a>00104 }
<a name="l00105"></a>00105 
<a name="l00106"></a>00106 <span class="comment">// Returns an iterator addressing the location of the entry in the map</span>
<a name="l00107"></a><a class="code" href="class_tree_map.html#da5bc54e6c1da79235e9160ee021b9f5">00107</a> <span class="comment">// that has a key equivalent to the specified one or the location succeeding the</span>
<a name="l00108"></a>00108 <span class="comment">// last element in the map if there is no match for the key.</span>
<a name="l00109"></a>00109 <a class="code" href="class_tree_map_1_1iterator.html">TreeMap::iterator</a> <a class="code" href="class_tree_map.html#da5bc54e6c1da79235e9160ee021b9f5">TreeMap::find</a>(<span class="keyword">const</span> <a class="code" href="class_tree_map.html#897356954c2cd3d41b221e3f24f99bba">Key</a>&amp; k)
<a name="l00110"></a>00110 {
<a name="l00112"></a>00112    assert(0);
<a name="l00113"></a>00113    <span class="keywordflow">return</span> <a class="code" href="class_tree_map.html#f34c4b013e5d012ab5f1bfef486d630f">end</a>();
<a name="l00114"></a><a class="code" href="class_tree_map.html#732153e7bc56dacafa2411864b548219">00114</a> }
<a name="l00115"></a>00115 
<a name="l00116"></a>00116 <a class="code" href="class_tree_map_1_1const__iterator.html">TreeMap::const_iterator</a> <a class="code" href="class_tree_map.html#da5bc54e6c1da79235e9160ee021b9f5">TreeMap::find</a>(<span class="keyword">const</span> <a class="code" href="class_tree_map.html#897356954c2cd3d41b221e3f24f99bba">Key</a>&amp; k)<span class="keyword"> const</span>
<a name="l00117"></a>00117 <span class="keyword"></span>{
<a name="l00119"></a>00119    assert(0);
<a name="l00120"></a>00120    <span class="keywordflow">return</span> <a class="code" href="class_tree_map.html#f34c4b013e5d012ab5f1bfef486d630f">end</a>();
<a name="l00121"></a>00121 }
<a name="l00122"></a>00122 
<a name="l00123"></a>00123 <span class="comment">// Inserts an element into a map with a specified key value</span>
<a name="l00124"></a><a class="code" href="class_tree_map.html#ce20a84b60c9bcce43c37cb75d29fe50">00124</a> <span class="comment">// if one with such a key value does not exist.</span>
<a name="l00125"></a>00125 <span class="comment">// @returns Reference to the value component of the element defined by the key.</span>
<a name="l00126"></a>00126 <a class="code" href="class_tree_map.html#5988c20a047cfe063999787584b0aca7">TreeMap::Val</a>&amp; <a class="code" href="class_tree_map.html#ce20a84b60c9bcce43c37cb75d29fe50">TreeMap::operator[]</a>(<span class="keyword">const</span> <a class="code" href="class_tree_map.html#897356954c2cd3d41b221e3f24f99bba">Key</a>&amp; k)
<a name="l00127"></a>00127 {
<a name="l00129"></a>00129    assert(0);
<a name="l00130"></a>00130    <a class="code" href="class_tree_map_1_1iterator.html">iterator</a> i;
<a name="l00131"></a>00131    <span class="keywordflow">return</span> i-&gt;second;
<a name="l00132"></a>00132 }
<a name="l00133"></a><a class="code" href="class_tree_map.html#ea1ddff44da5abff286d8b01793eb7ee">00133</a> 
<a name="l00134"></a>00134 <span class="comment">// Tests if a map is empty.</span>
<a name="l00135"></a>00135 <span class="keywordtype">bool</span> <a class="code" href="class_tree_map.html#ea1ddff44da5abff286d8b01793eb7ee">TreeMap::empty</a>( )<span class="keyword"> const</span>
<a name="l00136"></a>00136 <span class="keyword"></span>{
<a name="l00137"></a>00137    <span class="keywordflow">return</span> <a class="code" href="class_tree_map.html#63a9f0ea7bb98050796b649e85481845">root</a>==NULL;
<a name="l00138"></a>00138 }
<a name="l00139"></a><a class="code" href="class_tree_map.html#5a9421972c178b3c37b99f953470c6f6">00139</a> 
<a name="l00140"></a>00140 <span class="comment">// Returns the number of elements in the map.</span>
<a name="l00141"></a>00141 <a class="code" href="class_tree_map.html#3eb1f9410d79d28273ccc045cf8e6478">TreeMap::size_type</a> <a class="code" href="class_tree_map.html#5a9421972c178b3c37b99f953470c6f6">TreeMap::size</a>( )<span class="keyword"> const</span>
<a name="l00142"></a>00142 <span class="keyword"></span>{
<a name="l00144"></a>00144    assert(0);
<a name="l00145"></a>00145    <span class="keywordflow">return</span> 0;
<a name="l00146"></a>00146 }
<a name="l00147"></a><a class="code" href="class_tree_map.html#1d79deabb6ad2a93ef5358356055ee3b">00147</a> 
<a name="l00148"></a>00148 <span class="comment">// Returns the number of elements in a map whose key matches a parameter-specified key.</span>
<a name="l00149"></a>00149 <a class="code" href="class_tree_map.html#3eb1f9410d79d28273ccc045cf8e6478">TreeMap::size_type</a> <a class="code" href="class_tree_map.html#1d79deabb6ad2a93ef5358356055ee3b">TreeMap::count</a>(<span class="keyword">const</span> <a class="code" href="class_tree_map.html#897356954c2cd3d41b221e3f24f99bba">Key</a>&amp; _Key)<span class="keyword"> const</span>
<a name="l00150"></a>00150 <span class="keyword"></span>{
<a name="l00152"></a>00152    <span class="keywordflow">return</span> 1;  <span class="comment">// this is not a multimap</span>
<a name="l00153"></a>00153 }
<a name="l00154"></a>00154 
<a name="l00155"></a><a class="code" href="class_tree_map.html#99d178e178a2d0a71c1f5698c5879dcf">00155</a> <span class="comment">// Removes an element from the map.</span>
<a name="l00156"></a>00156 <span class="comment">// @returns The iterator that designates the first element remaining beyond any elements removed.</span>
<a name="l00157"></a>00157 <a class="code" href="class_tree_map_1_1iterator.html">TreeMap::iterator</a> <a class="code" href="class_tree_map.html#99d178e178a2d0a71c1f5698c5879dcf">TreeMap::erase</a>(<a class="code" href="class_tree_map_1_1iterator.html">TreeMap::iterator</a> i)
<a name="l00158"></a>00158 {
<a name="l00160"></a>00160    assert(0);
<a name="l00161"></a>00161    <span class="keywordflow">return</span> <a class="code" href="class_tree_map.html#f34c4b013e5d012ab5f1bfef486d630f">end</a>();
<a name="l00162"></a>00162 }
<a name="l00163"></a>00163 
<a name="l00164"></a>00164 <span class="comment">// Removes a range of elements from the map.</span>
<a name="l00165"></a>00165 <span class="comment">// The range is defined by the key values of the first and last iterators</span>
<a name="l00166"></a><a class="code" href="class_tree_map.html#4c750f4eb7c25898376b2945bceb60a3">00166</a> <span class="comment">// first is the first element removed and last is the element just beyond the last elemnt removed.</span>
<a name="l00167"></a>00167 <span class="comment">// @returns The iterator that designates the first element remaining beyond any elements removed.</span>
<a name="l00168"></a>00168 <a class="code" href="class_tree_map_1_1iterator.html">TreeMap::iterator</a> <a class="code" href="class_tree_map.html#99d178e178a2d0a71c1f5698c5879dcf">TreeMap::erase</a>(<a class="code" href="class_tree_map_1_1iterator.html">TreeMap::iterator</a> f, <a class="code" href="class_tree_map_1_1iterator.html">TreeMap::iterator</a> l)
<a name="l00169"></a>00169 {
<a name="l00171"></a>00171    assert(0);
<a name="l00172"></a>00172    <span class="keywordflow">return</span> <a class="code" href="class_tree_map.html#f34c4b013e5d012ab5f1bfef486d630f">end</a>();
<a name="l00173"></a>00173 }
<a name="l00174"></a>00174 
<a name="l00175"></a>00175 <span class="comment">// Removes an element from the map.</span>
<a name="l00176"></a><a class="code" href="class_tree_map.html#f768666a08bb3f9bf6d59af014dc8a79">00176</a> <span class="comment">// @returns The number of elements that have been removed from the map.</span>
<a name="l00177"></a>00177 <span class="comment">//          Since this is not a multimap itshould be 1 or 0.</span>
<a name="l00178"></a>00178 <a class="code" href="class_tree_map.html#3eb1f9410d79d28273ccc045cf8e6478">TreeMap::size_type</a> <a class="code" href="class_tree_map.html#99d178e178a2d0a71c1f5698c5879dcf">TreeMap::erase</a>(<span class="keyword">const</span> <a class="code" href="class_tree_map.html#897356954c2cd3d41b221e3f24f99bba">Key</a>&amp; key)
<a name="l00179"></a>00179 {
<a name="l00181"></a>00181    assert(0);
<a name="l00182"></a>00182    <span class="keywordflow">return</span> 0;
<a name="l00183"></a>00183 }
<a name="l00184"></a><a class="code" href="class_tree_map.html#3616b8000a015689fed4b46c19c06ea2">00184</a> 
<a name="l00185"></a>00185 <span class="comment">// Erases all the elements of a map.</span>
<a name="l00186"></a>00186 <span class="keywordtype">void</span> <a class="code" href="class_tree_map.html#3616b8000a015689fed4b46c19c06ea2">TreeMap::clear</a>( )
<a name="l00187"></a>00187 {
<a name="l00188"></a>00188    <a class="code" href="class_tree_map_detail.html#5637e02d8d73d541ed8c19d448ecac17">TreeMapDetail::erase</a>(<span class="keyword">this</span>, 0);  
<a name="l00189"></a>00189 
<a name="l00190"></a>00190    assert(0);
<a name="l00191"></a><a class="code" href="class_tree_map.html#e62bc2a78904e459d5f302a5ff48769a">00191</a> }
<a name="l00192"></a>00192 
<a name="l00193"></a>00193 <span class="keywordtype">bool</span> <a class="code" href="class_tree_map.html#e62bc2a78904e459d5f302a5ff48769a">TreeMap::struct_eq</a>(<span class="keyword">const</span> <a class="code" href="class_tree_map.html">TreeMap</a>&amp; another)<span class="keyword"> const</span>
<a name="l00194"></a>00194 <span class="keyword"></span>{
<a name="l00196"></a>00196    assert(0);
<a name="l00197"></a>00197    <span class="keywordflow">return</span> <span class="keyword">false</span>;
<a name="l00198"></a><a class="code" href="class_tree_map.html#68dd925067e3812184dcedea9211ac4b">00198</a> }
<a name="l00199"></a>00199 
<a name="l00200"></a>00200 <span class="keywordtype">bool</span> <a class="code" href="class_tree_map.html#68dd925067e3812184dcedea9211ac4b">TreeMap::info_eq</a>(<span class="keyword">const</span> <a class="code" href="class_tree_map.html">TreeMap</a>&amp; another)<span class="keyword"> const</span>
<a name="l00201"></a>00201 <span class="keyword"></span>{
<a name="l00203"></a>00203    assert(0);
<a name="l00204"></a>00204    <span class="keywordflow">return</span> <span class="keyword">false</span>;
<a name="l00205"></a>00205 }
<a name="l00206"></a><a class="code" href="class_tree_map_1_1const__iterator.html#879fb570af328b721ed45fe254b0a582">00206</a> 
<a name="l00207"></a>00207 <span class="comment">// preincrement</span>
<a name="l00208"></a>00208 <a class="code" href="class_tree_map_1_1const__iterator.html">TreeMap::const_iterator</a>&amp; <a class="code" href="class_tree_map_1_1const__iterator.html#879fb570af328b721ed45fe254b0a582">TreeMap::const_iterator::operator ++</a>()
<a name="l00209"></a>00209 {
<a name="l00211"></a>00211    <span class="keywordflow">return</span> *<span class="keyword">this</span>;
<a name="l00212"></a>00212 }
<a name="l00213"></a><a class="code" href="class_tree_map_1_1const__iterator.html#5d4681e027a07e3fb51ab21bef0dcc3d">00213</a> 
<a name="l00214"></a>00214 <span class="comment">// postincrement</span>
<a name="l00215"></a>00215 <a class="code" href="class_tree_map_1_1const__iterator.html">TreeMap::const_iterator</a> <a class="code" href="class_tree_map_1_1const__iterator.html#879fb570af328b721ed45fe254b0a582">TreeMap::const_iterator::operator++</a>(<span class="keywordtype">int</span>)
<a name="l00216"></a>00216 {
<a name="l00218"></a>00218    <span class="keywordflow">return</span> *<span class="keyword">this</span>;
<a name="l00219"></a>00219 }
<a name="l00220"></a><a class="code" href="class_tree_map_1_1const__iterator.html#08e169f7d9d8a763281a98d478c20a02">00220</a> 
<a name="l00221"></a>00221 <span class="comment">// predecrement</span>
<a name="l00222"></a>00222 <a class="code" href="class_tree_map_1_1const__iterator.html">TreeMap::const_iterator</a>&amp; <a class="code" href="class_tree_map_1_1const__iterator.html#08e169f7d9d8a763281a98d478c20a02">TreeMap::const_iterator::operator--</a>()
<a name="l00223"></a>00223 {
<a name="l00225"></a>00225    <span class="keywordflow">return</span> *<span class="keyword">this</span>;
<a name="l00226"></a>00226 }
<a name="l00227"></a><a class="code" href="class_tree_map_1_1const__iterator.html#12332c0f3ca9f1be40bf725d24d260ef">00227</a> 
<a name="l00228"></a>00228 <span class="comment">// postdecrement</span>
<a name="l00229"></a>00229 <a class="code" href="class_tree_map_1_1const__iterator.html">TreeMap::const_iterator</a> <a class="code" href="class_tree_map_1_1const__iterator.html#08e169f7d9d8a763281a98d478c20a02">TreeMap::const_iterator::operator--</a>(<span class="keywordtype">int</span>)
<a name="l00230"></a>00230 {
<a name="l00232"></a>00232    <span class="keywordflow">return</span> *<span class="keyword">this</span>;
<a name="l00233"></a>00233 }
<a name="l00234"></a>00234 
<a name="l00235"></a><a class="code" href="class_tree_map.html#48753429045577c544d7b1765997223e">00235</a> 
<a name="l00237"></a>00237 <a class="code" href="class_tree_map.html">TreeMap</a>&amp; <a class="code" href="class_tree_map.html#48753429045577c544d7b1765997223e">TreeMap::operator=</a>(<span class="keyword">const</span> <a class="code" href="class_tree_map.html">TreeMap</a>&amp; )
<a name="l00238"></a>00238 {
<a name="l00240"></a>00240    <span class="keywordflow">return</span> *<span class="keyword">this</span>;
<a name="l00241"></a>00241 }
<a name="l00242"></a><a class="code" href="class_tree_map.html#4b1a01a7db76e79c6194363c78d33615">00242</a>       
<a name="l00244"></a>00244 <a class="code" href="class_tree_map_1_1iterator.html">TreeMap::iterator</a> <a class="code" href="class_tree_map.html#4b1a01a7db76e79c6194363c78d33615">TreeMap::begin</a>()
<a name="l00245"></a>00245 { 
<a name="l00247"></a>00247    <span class="keywordflow">return</span> <a class="code" href="class_tree_map_1_1iterator.html">iterator</a>(NULL);
<a name="l00248"></a><a class="code" href="class_tree_map.html#6c34e3a8894af3a2160a3c0baa7e6fad">00248</a> }
<a name="l00249"></a>00249 
<a name="l00250"></a>00250 <a class="code" href="class_tree_map_1_1const__iterator.html">TreeMap::const_iterator</a> <a class="code" href="class_tree_map.html#4b1a01a7db76e79c6194363c78d33615">TreeMap::begin</a>()<span class="keyword"> const</span>
<a name="l00251"></a>00251 <span class="keyword"></span>{ 
<a name="l00253"></a>00253    <span class="keywordflow">return</span> <a class="code" href="classstd_1_1iterator.html">iterator</a>(NULL);
<a name="l00254"></a>00254 }
<a name="l00255"></a><a class="code" href="class_tree_map.html#f34c4b013e5d012ab5f1bfef486d630f">00255</a> 
<a name="l00257"></a>00257 <a class="code" href="class_tree_map_1_1iterator.html">TreeMap::iterator</a> <a class="code" href="class_tree_map.html#f34c4b013e5d012ab5f1bfef486d630f">TreeMap::end</a>()
<a name="l00258"></a>00258 { 
<a name="l00260"></a>00260    <span class="keywordflow">return</span> <a class="code" href="class_tree_map_1_1iterator.html">iterator</a>(NULL);
<a name="l00261"></a>00261 }
<a name="l00262"></a><a class="code" href="class_tree_map.html#37d6974af8ee6af64f7b4f71330853cb">00262</a> 
<a name="l00264"></a>00264 <a class="code" href="class_tree_map_1_1const__iterator.html">TreeMap::const_iterator</a> <a class="code" href="class_tree_map.html#f34c4b013e5d012ab5f1bfef486d630f">TreeMap::end</a>()<span class="keyword"> const</span>
<a name="l00265"></a>00265 <span class="keyword"></span>{ 
<a name="l00267"></a>00267    <span class="keywordflow">return</span> <a class="code" href="class_tree_map_1_1iterator.html">iterator</a>(NULL);
<a name="l00268"></a>00268 }
<a name="l00269"></a>00269 
<a name="l00271"></a>00271 <span class="comment">// Tests</span>
<a name="l00273"></a><a class="code" href="asd_8cc.html#e29929e8b88737e614f6df9a0f9b6def">00273</a> <span class="comment"></span>
<a name="l00275"></a>00275 <span class="keywordtype">void</span> <a class="code" href="asd_8cc.html#e29929e8b88737e614f6df9a0f9b6def">print</a>(<span class="keyword">const</span> std::pair&lt;int, std::string&gt;&amp; p)
<a name="l00276"></a>00276 {
<a name="l00277"></a>00277    std::cout&lt;&lt;p.first&lt;&lt;<span class="stringliteral">", "</span>&lt;&lt;p.second&lt;&lt;std::endl;
<a name="l00278"></a>00278 }
<a name="l00279"></a>00279 
<a name="l00280"></a>00280 <span class="preprocessor">#include &lt;map&gt;</span>
<a name="l00281"></a><a class="code" href="main_8cc.html#5af26b3a0b1f8425bfcd62bcfe8991cc">00281</a> 
<a name="l00283"></a>00283 <span class="keywordtype">void</span> <a class="code" href="asd_8cc.html#5af26b3a0b1f8425bfcd62bcfe8991cc">test</a>()
<a name="l00284"></a>00284 {
<a name="l00285"></a>00285    <span class="comment">// A typedef used by the test.</span>
<a name="l00286"></a>00286    <span class="keyword">typedef</span> std::map&lt;int, std::string&gt; TEST_MAP;
<a name="l00287"></a>00287    <span class="comment">//typedef SmallMap&lt;int, std::string&gt; TEST_MAP;</span>
<a name="l00288"></a>00288    <span class="comment">//typedef TreeMap TEST_MAP;</span>
<a name="l00289"></a>00289 
<a name="l00290"></a>00290    std::cout &lt;&lt; <span class="stringliteral">"Testy uzytkownika"</span> &lt;&lt; std::endl;
<a name="l00291"></a>00291 
<a name="l00292"></a>00292         TEST_MAP m;  
<a name="l00293"></a>00293    
<a name="l00294"></a>00294    m[2] = <span class="stringliteral">"Merry"</span>;
<a name="l00295"></a>00295    m[4] = <span class="stringliteral">"Jane"</span>;
<a name="l00296"></a>00296    m[8] = <span class="stringliteral">"Korwin"</span>;
<a name="l00297"></a>00297    m[4] = <span class="stringliteral">"Magdalena"</span>;
<a name="l00298"></a>00298 
<a name="l00299"></a>00299    for_each(m.begin(), m.end(), <a class="code" href="asd_8cc.html#e29929e8b88737e614f6df9a0f9b6def">print</a> );
<a name="l00300"></a>00300    <span class="comment">//system("PAUSE");</span>
<a name="l00301"></a>00301 
<a name="l00302"></a>00302 }
<a name="l00303"></a>00303 
<a name="l00305"></a>00305 <span class="comment">// main - jest w pliku /home/common/dyd/aisdi/z2/main.cc</span>
<a name="l00307"></a>00307 <span class="comment"></span>
<a name="l00308"></a>00308 <span class="comment">//int main()</span>
<a name="l00309"></a>00309 <span class="comment">//{</span>
<a name="l00310"></a>00310 <span class="comment">//   std::cout &lt;&lt; "AISDI cwiczenie 4: wchodze do funkcji main." &lt;&lt; std::endl;</span>
<a name="l00311"></a>00311 <span class="comment">//   test();</span>
<a name="l00312"></a>00312 <span class="comment">//   // Biblioteka z bardziej rygorystyczna wersja tych testow bedzie udostepniona na nastepnych zajeciach.</span>
<a name="l00313"></a>00313 <span class="comment">//   Test2();</span>
<a name="l00314"></a>00314 <span class="comment">//   //system("PAUSE");</span>
<a name="l00315"></a>00315 <span class="comment">//   return EXIT_SUCCESS;</span>
<a name="l00316"></a>00316 <span class="comment">//}</span>
</pre></div><hr size="1"><address style="align: right;"><small>Generated on Fri Dec 2 01:03:51 2005 for AISDI Cwiczenie 4 by&nbsp;
<a href="http://www.doxygen.org/index.html">
<img src="doxygen.png" alt="doxygen" align="middle" border="0"></a> 1.4.5 </small></address>
</body>
</html>
91"></a><a class="code" href="class_tree_map.html#e62bc2a78904e459d5f302a5ff48769a">00191</a> }
<a name="l00192"></a>00192 
<a name="l00193"></a>00193 <span class="keywordtype">bool</span> <a class="code" href="class_tree_map.html#e62bc2a78904e459d5f302a5ff48769a">TreeMap::struct_eq</a>(<span class="keyword">const</span> <a class="code" href="class_tree_map.html">TreeMaptree/info/class_c_count.html                                                                        0100644 0003673 0000144 00000022616 11704031106 0017376 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html><head><meta http-equiv="Content-Type" content="text/html;charset=iso-8859-1">
<title>AISDI Cwiczenie 4: CCount Class Reference</title>
<link href="doxygen.css" rel="stylesheet" type="text/css">
<link href="tabs.css" rel="stylesheet" type="text/css">
</head><body>
<!-- Generated by Doxygen 1.4.5 -->
<div class="tabs">
  <ul>
    <li><a href="index.html"><span>Main&nbsp;Page</span></a></li>
    <li id="current"><a href="annotated.html"><span>Classes</span></a></li>
    <li><a href="files.html"><span>Files</span></a></li>
    <li><a href="pages.html"><span>Related&nbsp;Pages</span></a></li>
  </ul></div>
<div class="tabs">
  <ul>
    <li><a href="annotated.html"><span>Class&nbsp;List</span></a></li>
    <li><a href="classes.html"><span>Alphabetical&nbsp;List</span></a></li>
    <li><a href="hierarchy.html"><span>Class&nbsp;Hierarchy</span></a></li>
    <li><a href="functions.html"><span>Class&nbsp;Members</span></a></li>
  </ul></div>
<h1>CCount Class Reference</h1><!-- doxytag: class="CCount" -->A simple instance counter for detecting memory leaks.  
<a href="#_details">More...</a>
<p>
<code>#include &lt;<a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>&gt;</code>
<p>
Inherited by <a class="el" href="struct_tree_node.html">TreeNode</a>.
<p>
Inheritance diagram for CCount:<p><center><img src="class_c_count__inherit__graph.png" border="0" usemap="#_c_count__inherit__map" alt="Inheritance graph"></center>
<map name="_c_count__inherit__map">
<area href="struct_tree_node.html" shape="rect" coords="7,82,87,108" alt="">
</map>
<center><font size="2">[<a href="graph_legend.html">legend</a>]</font></center>Collaboration diagram for CCount:<p><center><img src="class_c_count__coll__graph.png" border="0" usemap="#_c_count__coll__map" alt="Collaboration graph"></center>
<center><font size="2">[<a href="graph_legend.html">legend</a>]</font></center><a href="class_c_count-members.html">List of all members.</a><table border="0" cellpadding="0" cellspacing="0">
<tr><td></td></tr>
<tr><td colspan="2"><br><h2>Static Public Member Functions</h2></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top">static int&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_c_count.html#68b1e82502beaa137b00477d034627d5">getCount</a> ()</td></tr>

<tr><td class="mdescLeft">&nbsp;</td><td class="mdescRight">A public method for getting the count.  <a href="#68b1e82502beaa137b00477d034627d5"></a><br></td></tr>
<tr><td colspan="2"><br><h2>Private Member Functions</h2></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top">&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_c_count.html#56b8d3879a6fedc1932c5c2733eb7655">CCount</a> ()</td></tr>

<tr><td class="memItemLeft" nowrap align="right" valign="top">&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_c_count.html#46a9e57e83393ebb6451f597d02d2338">~CCount</a> ()</td></tr>

<tr><td colspan="2"><br><h2>Static Private Attributes</h2></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top">static int&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_c_count.html#e2942a04780e223b215eb8b663cf5353">count</a> = 0</td></tr>

<tr><td colspan="2"><br><h2>Friends</h2></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top">struct&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_c_count.html#c0ade7f379584bcec5c868e24abd743c">TreeNode</a></td></tr>

</table>
<hr><a name="_details"></a><h2>Detailed Description</h2>
A simple instance counter for detecting memory leaks. 
<p>

<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00037">37</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.<hr><h2>Constructor &amp; Destructor Documentation</h2>
<a class="anchor" name="56b8d3879a6fedc1932c5c2733eb7655"></a><!-- doxytag: member="CCount::CCount" ref="56b8d3879a6fedc1932c5c2733eb7655" args="()" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">CCount::CCount           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="mdname1" valign="top" nowrap>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap><code> [inline, private]</code></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>

<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00041">41</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.
<p>
References <a class="el" href="_tree_map_8h-source.html#l00040">count</a>.    </td>
  </tr>
</table>
<a class="anchor" name="46a9e57e83393ebb6451f597d02d2338"></a><!-- doxytag: member="CCount::~CCount" ref="46a9e57e83393ebb6451f597d02d2338" args="()" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">CCount::~CCount           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="mdname1" valign="top" nowrap>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap><code> [inline, private]</code></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>

<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00042">42</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.
<p>
References <a class="el" href="_tree_map_8h-source.html#l00040">count</a>.    </td>
  </tr>
</table>
<hr><h2>Member Function Documentation</h2>
<a class="anchor" name="68b1e82502beaa137b00477d034627d5"></a><!-- doxytag: member="CCount::getCount" ref="68b1e82502beaa137b00477d034627d5" args="()" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">static int CCount::getCount           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="mdname1" valign="top" nowrap>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap><code> [inline, static]</code></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>
A public method for getting the count. 
<p>

<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00054">54</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.
<p>
References <a class="el" href="_tree_map_8h-source.html#l00040">count</a>.    </td>
  </tr>
</table>
<hr><h2>Friends And Related Function Documentation</h2>
<a class="anchor" name="c0ade7f379584bcec5c868e24abd743c"></a><!-- doxytag: member="CCount::TreeNode" ref="c0ade7f379584bcec5c868e24abd743c" args="" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">friend struct <a class="el" href="struct_tree_node.html">TreeNode</a><code> [friend]</code>          </td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>

<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00050">50</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.    </td>
  </tr>
</table>
<hr><h2>Member Data Documentation</h2>
<a class="anchor" name="e2942a04780e223b215eb8b663cf5353"></a><!-- doxytag: member="CCount::count" ref="e2942a04780e223b215eb8b663cf5353" args="" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">int <a class="el" href="class_c_count.html#e2942a04780e223b215eb8b663cf5353">CCount::count</a> = 0<code> [static, private]</code>          </td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>

<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00040">40</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.
<p>
Referenced by <a class="el" href="_tree_map_8h-source.html#l00041">CCount()</a>, <a class="el" href="_tree_map_8h-source.html#l00054">getCount()</a>, and <a class="el" href="_tree_map_8h-source.html#l00042">~CCount()</a>.    </td>
  </tr>
</table>
<hr>The documentation for this class was generated from the following files:<ul>
<li><a class="el" href="_tree_map_8h-source.html">TreeMap.h</a><li><a class="el" href="main_8cc-source.html">main.cc</a></ul>
<hr size="1"><address style="align: right;"><small>Generated on Fri Dec 2 01:03:51 2005 for AISDI Cwiczenie 4 by&nbsp;
<a href="http://www.doxygen.org/index.html">
<img src="doxygen.png" alt="doxygen" align="middle" border="0"></a> 1.4.5 </small></address>
</body>
</html>
                                                                                                                  tree/info/class_c_count-members.html                                                                0100644 0003673 0000144 00000004760 11704031106 0021026 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html><head><meta http-equiv="Content-Type" content="text/html;charset=iso-8859-1">
<title>AISDI Cwiczenie 4: Member List</title>
<link href="doxygen.css" rel="stylesheet" type="text/css">
<link href="tabs.css" rel="stylesheet" type="text/css">
</head><body>
<!-- Generated by Doxygen 1.4.5 -->
<div class="tabs">
  <ul>
    <li><a href="index.html"><span>Main&nbsp;Page</span></a></li>
    <li id="current"><a href="annotated.html"><span>Classes</span></a></li>
    <li><a href="files.html"><span>Files</span></a></li>
    <li><a href="pages.html"><span>Related&nbsp;Pages</span></a></li>
  </ul></div>
<div class="tabs">
  <ul>
    <li><a href="annotated.html"><span>Class&nbsp;List</span></a></li>
    <li><a href="classes.html"><span>Alphabetical&nbsp;List</span></a></li>
    <li><a href="hierarchy.html"><span>Class&nbsp;Hierarchy</span></a></li>
    <li><a href="functions.html"><span>Class&nbsp;Members</span></a></li>
  </ul></div>
<h1>CCount Member List</h1>This is the complete list of members for <a class="el" href="class_c_count.html">CCount</a>, including all inherited members.<p><table>
  <tr class="memlist"><td><a class="el" href="class_c_count.html#56b8d3879a6fedc1932c5c2733eb7655">CCount</a>()</td><td><a class="el" href="class_c_count.html">CCount</a></td><td><code> [inline, private]</code></td></tr>
  <tr class="memlist"><td><a class="el" href="class_c_count.html#e2942a04780e223b215eb8b663cf5353">count</a></td><td><a class="el" href="class_c_count.html">CCount</a></td><td><code> [private, static]</code></td></tr>
  <tr class="memlist"><td><a class="el" href="class_c_count.html#68b1e82502beaa137b00477d034627d5">getCount</a>()</td><td><a class="el" href="class_c_count.html">CCount</a></td><td><code> [inline, static]</code></td></tr>
  <tr class="memlist"><td><a class="el" href="class_c_count.html#c0ade7f379584bcec5c868e24abd743c">TreeNode</a></td><td><a class="el" href="class_c_count.html">CCount</a></td><td><code> [friend]</code></td></tr>
  <tr class="memlist"><td><a class="el" href="class_c_count.html#46a9e57e83393ebb6451f597d02d2338">~CCount</a>()</td><td><a class="el" href="class_c_count.html">CCount</a></td><td><code> [inline, private]</code></td></tr>
</table><hr size="1"><address style="align: right;"><small>Generated on Fri Dec 2 01:03:51 2005 for AISDI Cwiczenie 4 by&nbsp;
<a href="http://www.doxygen.org/index.html">
<img src="doxygen.png" alt="doxygen" align="middle" border="0"></a> 1.4.5 </small></address>
</body>
</html>
                tree/info/class_tree_map.html                                                                       0100644 0003673 0000144 00000155677 11704031106 0017556 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html><head><meta http-equiv="Content-Type" content="text/html;charset=iso-8859-1">
<title>AISDI Cwiczenie 4: TreeMap Class Reference</title>
<link href="doxygen.css" rel="stylesheet" type="text/css">
<link href="tabs.css" rel="stylesheet" type="text/css">
</head><body>
<!-- Generated by Doxygen 1.4.5 -->
<div class="tabs">
  <ul>
    <li><a href="index.html"><span>Main&nbsp;Page</span></a></li>
    <li id="current"><a href="annotated.html"><span>Classes</span></a></li>
    <li><a href="files.html"><span>Files</span></a></li>
    <li><a href="pages.html"><span>Related&nbsp;Pages</span></a></li>
  </ul></div>
<div class="tabs">
  <ul>
    <li><a href="annotated.html"><span>Class&nbsp;List</span></a></li>
    <li><a href="classes.html"><span>Alphabetical&nbsp;List</span></a></li>
    <li><a href="hierarchy.html"><span>Class&nbsp;Hierarchy</span></a></li>
    <li><a href="functions.html"><span>Class&nbsp;Members</span></a></li>
  </ul></div>
<h1>TreeMap Class Reference</h1><!-- doxytag: class="TreeMap" -->A map with a similar interface to std::map.  
<a href="#_details">More...</a>
<p>
<code>#include &lt;<a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>&gt;</code>
<p>
Collaboration diagram for TreeMap:<p><center><img src="class_tree_map__coll__graph.png" border="0" usemap="#_tree_map__coll__map" alt="Collaboration graph"></center>
<map name="_tree_map__coll__map">
<area href="class_tree_map_detail.html" shape="rect" coords="7,199,116,225" alt="">
<area href="struct_tree_node.html" shape="rect" coords="140,199,220,225" alt="">
<area href="class_c_count.html" shape="rect" coords="100,97,167,124" alt="">
</map>
<center><font size="2">[<a href="graph_legend.html">legend</a>]</font></center><a href="class_tree_map-members.html">List of all members.</a><table border="0" cellpadding="0" cellspacing="0">
<tr><td></td></tr>
<tr><td colspan="2"><br><h2>Public Types</h2></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top">typedef int&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map.html#897356954c2cd3d41b221e3f24f99bba">Key</a></td></tr>

<tr><td class="memItemLeft" nowrap align="right" valign="top">typedef std::string&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map.html#5988c20a047cfe063999787584b0aca7">Val</a></td></tr>

<tr><td class="memItemLeft" nowrap align="right" valign="top">typedef size_t&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map.html#3eb1f9410d79d28273ccc045cf8e6478">size_type</a></td></tr>

<tr><td class="memItemLeft" nowrap align="right" valign="top">typedef std::pair&lt; <a class="el" href="class_tree_map.html#897356954c2cd3d41b221e3f24f99bba">Key</a>, <a class="el" href="class_tree_map.html#5988c20a047cfe063999787584b0aca7">Val</a> &gt;&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map.html#44c29edb103a2872f519ad0c9a0fdaaa">P</a></td></tr>

<tr><td colspan="2"><br><h2>Public Member Functions</h2></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top">&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map.html#8c50809795fa8b8f2a3cd019e2acae62">TreeMap</a> ()</td></tr>

<tr><td class="memItemLeft" nowrap align="right" valign="top">&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map.html#36057872ebdcdb89755ff678ad8a5179">TreeMap</a> (const <a class="el" href="class_tree_map.html">TreeMap</a> &amp;)</td></tr>

<tr><td class="mdescLeft">&nbsp;</td><td class="mdescRight">Content of existing TreeMap object is copied into the new object.  <a href="#36057872ebdcdb89755ff678ad8a5179"></a><br></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top">&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map.html#3d396c0d29bbefef0723fb19a95dd386">~TreeMap</a> ()</td></tr>

<tr><td class="memItemLeft" nowrap align="right" valign="top"><a class="el" href="class_tree_map_1_1iterator.html">iterator</a>&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map.html#4b1a01a7db76e79c6194363c78d33615">begin</a> ()</td></tr>

<tr><td class="mdescLeft">&nbsp;</td><td class="mdescRight">Returns an iterator addressing the first element in the map.  <a href="#4b1a01a7db76e79c6194363c78d33615"></a><br></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top"><a class="el" href="class_tree_map_1_1const__iterator.html">const_iterator</a>&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map.html#6c34e3a8894af3a2160a3c0baa7e6fad">begin</a> () const </td></tr>

<tr><td class="mdescLeft">&nbsp;</td><td class="mdescRight">Returns a <a class="el" href="class_tree_map_1_1const__iterator.html">const_iterator</a> addressing the first element in the map.  <a href="#6c34e3a8894af3a2160a3c0baa7e6fad"></a><br></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top"><a class="el" href="class_tree_map_1_1iterator.html">iterator</a>&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map.html#f34c4b013e5d012ab5f1bfef486d630f">end</a> ()</td></tr>

<tr><td class="mdescLeft">&nbsp;</td><td class="mdescRight">Returns an iterator that addresses the location succeeding the last element in a map.  <a href="#f34c4b013e5d012ab5f1bfef486d630f"></a><br></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top"><a class="el" href="class_tree_map_1_1const__iterator.html">const_iterator</a>&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map.html#37d6974af8ee6af64f7b4f71330853cb">end</a> () const </td></tr>

<tr><td class="mdescLeft">&nbsp;</td><td class="mdescRight">Returns a <a class="el" href="class_tree_map_1_1const__iterator.html">const_iterator</a> that addresses the location succeeding the last element in a map.  <a href="#37d6974af8ee6af64f7b4f71330853cb"></a><br></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top">std::pair&lt; <a class="el" href="class_tree_map_1_1iterator.html">iterator</a>, bool &gt;&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map.html#94500a970d082e87b838a94fed333521">insert</a> (const std::pair&lt; <a class="el" href="class_tree_map.html#897356954c2cd3d41b221e3f24f99bba">Key</a>, <a class="el" href="class_tree_map.html#5988c20a047cfe063999787584b0aca7">Val</a> &gt; &amp;entry)</td></tr>

<tr><td class="mdescLeft">&nbsp;</td><td class="mdescRight">Inserts an element into the map.  <a href="#94500a970d082e87b838a94fed333521"></a><br></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top"><a class="el" href="class_tree_map_1_1iterator.html">iterator</a>&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map.html#9b42b72518de2845832b80e44424fab3">unsafe_insert</a> (const std::pair&lt; <a class="el" href="class_tree_map.html#897356954c2cd3d41b221e3f24f99bba">Key</a>, <a class="el" href="class_tree_map.html#5988c20a047cfe063999787584b0aca7">Val</a> &gt; &amp;entry)</td></tr>

<tr><td class="mdescLeft">&nbsp;</td><td class="mdescRight">Inserts an element into the map.  <a href="#9b42b72518de2845832b80e44424fab3"></a><br></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top"><a class="el" href="class_tree_map_1_1iterator.html">iterator</a>&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map.html#da5bc54e6c1da79235e9160ee021b9f5">find</a> (const <a class="el" href="class_tree_map.html#897356954c2cd3d41b221e3f24f99bba">Key</a> &amp;k)</td></tr>

<tr><td class="mdescLeft">&nbsp;</td><td class="mdescRight">Returns an iterator addressing the location of the entry in the map that has a key equivalent to the specified one or the location succeeding the last element in the map if there is no match for the key.  <a href="#da5bc54e6c1da79235e9160ee021b9f5"></a><br></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top"><a class="el" href="class_tree_map_1_1const__iterator.html">const_iterator</a>&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map.html#732153e7bc56dacafa2411864b548219">find</a> (const <a class="el" href="class_tree_map.html#897356954c2cd3d41b221e3f24f99bba">Key</a> &amp;k) const </td></tr>

<tr><td class="memItemLeft" nowrap align="right" valign="top"><a class="el" href="class_tree_map.html#5988c20a047cfe063999787584b0aca7">Val</a> &amp;&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map.html#ce20a84b60c9bcce43c37cb75d29fe50">operator[]</a> (const <a class="el" href="class_tree_map.html#897356954c2cd3d41b221e3f24f99bba">Key</a> &amp;k)</td></tr>

<tr><td class="mdescLeft">&nbsp;</td><td class="mdescRight">Inserts an element into a map with a specified key value if one with such a key value does not exist.  <a href="#ce20a84b60c9bcce43c37cb75d29fe50"></a><br></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top">bool&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map.html#ea1ddff44da5abff286d8b01793eb7ee">empty</a> () const </td></tr>

<tr><td class="mdescLeft">&nbsp;</td><td class="mdescRight">Tests if a map is empty.  <a href="#ea1ddff44da5abff286d8b01793eb7ee"></a><br></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top"><a class="el" href="class_tree_map.html#3eb1f9410d79d28273ccc045cf8e6478">size_type</a>&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map.html#5a9421972c178b3c37b99f953470c6f6">size</a> () const </td></tr>

<tr><td class="mdescLeft">&nbsp;</td><td class="mdescRight">Returns the number of elements in the map.  <a href="#5a9421972c178b3c37b99f953470c6f6"></a><br></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top"><a class="el" href="class_tree_map.html#3eb1f9410d79d28273ccc045cf8e6478">size_type</a>&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map.html#1d79deabb6ad2a93ef5358356055ee3b">count</a> (const <a class="el" href="class_tree_map.html#897356954c2cd3d41b221e3f24f99bba">Key</a> &amp;_Key) const </td></tr>

<tr><td class="mdescLeft">&nbsp;</td><td class="mdescRight">Returns the number of elements in a map whose key matches a parameter-specified key.  <a href="#1d79deabb6ad2a93ef5358356055ee3b"></a><br></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top"><a class="el" href="class_tree_map_1_1iterator.html">iterator</a>&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map.html#99d178e178a2d0a71c1f5698c5879dcf">erase</a> (<a class="el" href="class_tree_map_1_1iterator.html">iterator</a> i)</td></tr>

<tr><td class="mdescLeft">&nbsp;</td><td class="mdescRight">Removes an element from the map.  <a href="#99d178e178a2d0a71c1f5698c5879dcf"></a><br></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top"><a class="el" href="class_tree_map_1_1iterator.html">iterator</a>&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map.html#4c750f4eb7c25898376b2945bceb60a3">erase</a> (<a class="el" href="class_tree_map_1_1iterator.html">iterator</a> first, <a class="el" href="class_tree_map_1_1iterator.html">iterator</a> last)</td></tr>

<tr><td class="mdescLeft">&nbsp;</td><td class="mdescRight">Removes a range of elements from the map.  <a href="#4c750f4eb7c25898376b2945bceb60a3"></a><br></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top"><a class="el" href="class_tree_map.html#3eb1f9410d79d28273ccc045cf8e6478">size_type</a>&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map.html#f768666a08bb3f9bf6d59af014dc8a79">erase</a> (const <a class="el" href="class_tree_map.html#897356954c2cd3d41b221e3f24f99bba">Key</a> &amp;key)</td></tr>

<tr><td class="mdescLeft">&nbsp;</td><td class="mdescRight">Removes an element from the map.  <a href="#f768666a08bb3f9bf6d59af014dc8a79"></a><br></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top">void&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map.html#3616b8000a015689fed4b46c19c06ea2">clear</a> ()</td></tr>

<tr><td class="mdescLeft">&nbsp;</td><td class="mdescRight">Erases all the elements of a map.  <a href="#3616b8000a015689fed4b46c19c06ea2"></a><br></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top">bool&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map.html#e62bc2a78904e459d5f302a5ff48769a">struct_eq</a> (const <a class="el" href="class_tree_map.html">TreeMap</a> &amp;another) const </td></tr>

<tr><td class="mdescLeft">&nbsp;</td><td class="mdescRight">Returns true if this map's internal structure is identical to another map's structure.  <a href="#e62bc2a78904e459d5f302a5ff48769a"></a><br></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top">bool&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map.html#68dd925067e3812184dcedea9211ac4b">info_eq</a> (const <a class="el" href="class_tree_map.html">TreeMap</a> &amp;another) const </td></tr>

<tr><td class="mdescLeft">&nbsp;</td><td class="mdescRight">Returns true if this map contains exactly the same key-value pairs as the another map.  <a href="#68dd925067e3812184dcedea9211ac4b"></a><br></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top">bool&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map.html#18b0ae91b08ac71b923d1c9dd85f7876">operator==</a> (const <a class="el" href="class_tree_map.html">TreeMap</a> &amp;a) const </td></tr>

<tr><td class="mdescLeft">&nbsp;</td><td class="mdescRight">Returns true if this map contains exactly the same key-value pairs as the another map.  <a href="#18b0ae91b08ac71b923d1c9dd85f7876"></a><br></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top"><a class="el" href="class_tree_map.html">TreeMap</a> &amp;&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map.html#48753429045577c544d7b1765997223e">operator=</a> (const <a class="el" href="class_tree_map.html">TreeMap</a> &amp;)</td></tr>

<tr><td class="mdescLeft">&nbsp;</td><td class="mdescRight">Assignment operator copy the source elements into this object.  <a href="#48753429045577c544d7b1765997223e"></a><br></td></tr>
<tr><td colspan="2"><br><h2>Protected Types</h2></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top">typedef <a class="el" href="struct_tree_node.html">TreeNode</a>&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map.html#6c3a6944a808a7c0bbb6788dbec54a9f">Node</a></td></tr>

<tr><td colspan="2"><br><h2>Protected Attributes</h2></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top"><a class="el" href="struct_tree_node.html">Node</a> *&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map.html#63a9f0ea7bb98050796b649e85481845">root</a></td></tr>

<tr><td class="mdescLeft">&nbsp;</td><td class="mdescRight">The root of the tree.  <a href="#63a9f0ea7bb98050796b649e85481845"></a><br></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top"><a class="el" href="class_tree_map_detail.html">TreeMapDetail</a> *&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map.html#951da6b7179a4f697cc89d36acf74e52">detail</a></td></tr>

<tr><td colspan="2"><br><h2>Friends</h2></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top">class&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map.html#359f4c98a692d55e998de2a0ccbfe3c9">TreeMapDetail</a></td></tr>

<tr><td colspan="2"><br><h2>Classes</h2></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top">class &nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map_1_1const__iterator.html">const_iterator</a></td></tr>

<tr><td class="mdescLeft">&nbsp;</td><td class="mdescRight">A <a class="el" href="class_tree_map_1_1const__iterator.html">const_iterator</a>.  <a href="class_tree_map_1_1const__iterator.html#_details">More...</a><br></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top">class &nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map_1_1iterator.html">iterator</a></td></tr>

<tr><td class="mdescLeft">&nbsp;</td><td class="mdescRight">An iterator.  <a href="class_tree_map_1_1iterator.html#_details">More...</a><br></td></tr>
</table>
<hr><a name="_details"></a><h2>Detailed Description</h2>
A map with a similar interface to std::map. 
<p>
This map should be implemented as a binary tree. 
<p>

<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00077">77</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.<hr><h2>Member Typedef Documentation</h2>
<a class="anchor" name="897356954c2cd3d41b221e3f24f99bba"></a><!-- doxytag: member="TreeMap::Key" ref="897356954c2cd3d41b221e3f24f99bba" args="" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">typedef int <a class="el" href="class_tree_map.html#897356954c2cd3d41b221e3f24f99bba">TreeMap::Key</a>          </td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>

<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00081">81</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.    </td>
  </tr>
</table>
<a class="anchor" name="6c3a6944a808a7c0bbb6788dbec54a9f"></a><!-- doxytag: member="TreeMap::Node" ref="6c3a6944a808a7c0bbb6788dbec54a9f" args="" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">typedef <a class="el" href="struct_tree_node.html">TreeNode</a> <a class="el" href="struct_tree_node.html">TreeMap::Node</a><code> [protected]</code>          </td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>

<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00085">85</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.    </td>
  </tr>
</table>
<a class="anchor" name="44c29edb103a2872f519ad0c9a0fdaaa"></a><!-- doxytag: member="TreeMap::P" ref="44c29edb103a2872f519ad0c9a0fdaaa" args="" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">typedef std::pair&lt;<a class="el" href="class_tree_map.html#897356954c2cd3d41b221e3f24f99bba">Key</a>, <a class="el" href="class_tree_map.html#5988c20a047cfe063999787584b0aca7">Val</a>&gt; <a class="el" href="class_tree_map.html#44c29edb103a2872f519ad0c9a0fdaaa">TreeMap::P</a>          </td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>

<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00090">90</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.    </td>
  </tr>
</table>
<a class="anchor" name="3eb1f9410d79d28273ccc045cf8e6478"></a><!-- doxytag: member="TreeMap::size_type" ref="3eb1f9410d79d28273ccc045cf8e6478" args="" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">typedef size_t <a class="el" href="class_tree_map.html#3eb1f9410d79d28273ccc045cf8e6478">TreeMap::size_type</a>          </td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>

<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00089">89</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.    </td>
  </tr>
</table>
<a class="anchor" name="5988c20a047cfe063999787584b0aca7"></a><!-- doxytag: member="TreeMap::Val" ref="5988c20a047cfe063999787584b0aca7" args="" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">typedef std::string <a class="el" href="class_tree_map.html#5988c20a047cfe063999787584b0aca7">TreeMap::Val</a>          </td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>

<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00082">82</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.    </td>
  </tr>
</table>
<hr><h2>Constructor &amp; Destructor Documentation</h2>
<a class="anchor" name="8c50809795fa8b8f2a3cd019e2acae62"></a><!-- doxytag: member="TreeMap::TreeMap" ref="8c50809795fa8b8f2a3cd019e2acae62" args="()" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">TreeMap::TreeMap           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="mdname1" valign="top" nowrap>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>

<p>
Definition at line <a class="el" href="asd_8cc-source.html#l00060">60</a> of file <a class="el" href="asd_8cc-source.html">asd.cc</a>.
<p>
References <a class="el" href="_tree_map_8h-source.html#l00086">root</a>.    </td>
  </tr>
</table>
<a class="anchor" name="36057872ebdcdb89755ff678ad8a5179"></a><!-- doxytag: member="TreeMap::TreeMap" ref="36057872ebdcdb89755ff678ad8a5179" args="(const TreeMap &amp;)" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">TreeMap::TreeMap           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="md" nowrap valign="top">const <a class="el" href="class_tree_map.html">TreeMap</a> &amp;&nbsp;</td>
          <td class="mdname1" valign="top" nowrap> <em>m</em>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>
Content of existing TreeMap object is copied into the new object. 
<p>
<dl compact><dt><b><a class="el" href="todo.html#_todo000001">Todo:</a></b></dt><dd>Implement this</dd></dl>

<p>
Definition at line <a class="el" href="asd_8cc-source.html#l00066">66</a> of file <a class="el" href="asd_8cc-source.html">asd.cc</a>.    </td>
  </tr>
</table>
<a class="anchor" name="3d396c0d29bbefef0723fb19a95dd386"></a><!-- doxytag: member="TreeMap::~TreeMap" ref="3d396c0d29bbefef0723fb19a95dd386" args="()" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">TreeMap::~TreeMap           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="mdname1" valign="top" nowrap>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>

<p>
Definition at line <a class="el" href="asd_8cc-source.html#l00071">71</a> of file <a class="el" href="asd_8cc-source.html">asd.cc</a>.
<p>
References <a class="el" href="asd_8cc-source.html#l00184">clear()</a>.    </td>
  </tr>
</table>
<hr><h2>Member Function Documentation</h2>
<a class="anchor" name="6c34e3a8894af3a2160a3c0baa7e6fad"></a><!-- doxytag: member="TreeMap::begin" ref="6c34e3a8894af3a2160a3c0baa7e6fad" args="() const " --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top"><a class="el" href="class_tree_map_1_1const__iterator.html">TreeMap::const_iterator</a> TreeMap::begin           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="mdname1" valign="top" nowrap>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap> const<code> [inline]</code></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>
Returns a <a class="el" href="class_tree_map_1_1const__iterator.html">const_iterator</a> addressing the first element in the map. 
<p>
<dl compact><dt><b><a class="el" href="todo.html#_todo000021">Todo:</a></b></dt><dd>Implement this</dd></dl>

<p>
Definition at line <a class="el" href="asd_8cc-source.html#l00248">248</a> of file <a class="el" href="asd_8cc-source.html">asd.cc</a>.    </td>
  </tr>
</table>
<a class="anchor" name="4b1a01a7db76e79c6194363c78d33615"></a><!-- doxytag: member="TreeMap::begin" ref="4b1a01a7db76e79c6194363c78d33615" args="()" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top"><a class="el" href="class_tree_map_1_1iterator.html">TreeMap::iterator</a> TreeMap::begin           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="mdname1" valign="top" nowrap>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap><code> [inline]</code></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>
Returns an iterator addressing the first element in the map. 
<p>
<dl compact><dt><b><a class="el" href="todo.html#_todo000020">Todo:</a></b></dt><dd>Implement this</dd></dl>

<p>
Definition at line <a class="el" href="asd_8cc-source.html#l00242">242</a> of file <a class="el" href="asd_8cc-source.html">asd.cc</a>.
<p>
Referenced by <a class="el" href="asd_8cc-source.html#l00082">insert()</a>.    </td>
  </tr>
</table>
<a class="anchor" name="3616b8000a015689fed4b46c19c06ea2"></a><!-- doxytag: member="TreeMap::clear" ref="3616b8000a015689fed4b46c19c06ea2" args="()" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">void TreeMap::clear           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="mdname1" valign="top" nowrap>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>
Erases all the elements of a map. 
<p>
Stupid helper usage example<p>
<dl compact><dt><b><a class="el" href="todo.html#_todo000012">Todo:</a></b></dt><dd>Implement this</dd></dl>

<p>
Definition at line <a class="el" href="asd_8cc-source.html#l00184">184</a> of file <a class="el" href="asd_8cc-source.html">asd.cc</a>.
<p>
References <a class="el" href="asd_8cc-source.html#l00050">TreeMapDetail::erase()</a>.
<p>
Referenced by <a class="el" href="asd_8cc-source.html#l00071">~TreeMap()</a>.    </td>
  </tr>
</table>
<a class="anchor" name="1d79deabb6ad2a93ef5358356055ee3b"></a><!-- doxytag: member="TreeMap::count" ref="1d79deabb6ad2a93ef5358356055ee3b" args="(const Key &amp;_Key) const " --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top"><a class="el" href="class_tree_map.html#3eb1f9410d79d28273ccc045cf8e6478">TreeMap::size_type</a> TreeMap::count           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="md" nowrap valign="top">const <a class="el" href="class_tree_map.html#897356954c2cd3d41b221e3f24f99bba">Key</a> &amp;&nbsp;</td>
          <td class="mdname1" valign="top" nowrap> <em>_Key</em>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap> const</td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>
Returns the number of elements in a map whose key matches a parameter-specified key. 
<p>
<dl compact><dt><b><a class="el" href="todo.html#_todo000008">Todo:</a></b></dt><dd>Implement this</dd></dl>

<p>
Definition at line <a class="el" href="asd_8cc-source.html#l00147">147</a> of file <a class="el" href="asd_8cc-source.html">asd.cc</a>.    </td>
  </tr>
</table>
<a class="anchor" name="ea1ddff44da5abff286d8b01793eb7ee"></a><!-- doxytag: member="TreeMap::empty" ref="ea1ddff44da5abff286d8b01793eb7ee" args="() const " --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">bool TreeMap::empty           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="mdname1" valign="top" nowrap>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap> const</td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>
Tests if a map is empty. 
<p>

<p>
Definition at line <a class="el" href="asd_8cc-source.html#l00133">133</a> of file <a class="el" href="asd_8cc-source.html">asd.cc</a>.
<p>
References <a class="el" href="_tree_map_8h-source.html#l00086">root</a>.    </td>
  </tr>
</table>
<a class="anchor" name="37d6974af8ee6af64f7b4f71330853cb"></a><!-- doxytag: member="TreeMap::end" ref="37d6974af8ee6af64f7b4f71330853cb" args="() const " --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top"><a class="el" href="class_tree_map_1_1const__iterator.html">TreeMap::const_iterator</a> TreeMap::end           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="mdname1" valign="top" nowrap>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap> const<code> [inline]</code></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>
Returns a <a class="el" href="class_tree_map_1_1const__iterator.html">const_iterator</a> that addresses the location succeeding the last element in a map. 
<p>
<dl compact><dt><b><a class="el" href="todo.html#_todo000023">Todo:</a></b></dt><dd>Implement this</dd></dl>

<p>
Definition at line <a class="el" href="asd_8cc-source.html#l00262">262</a> of file <a class="el" href="asd_8cc-source.html">asd.cc</a>.    </td>
  </tr>
</table>
<a class="anchor" name="f34c4b013e5d012ab5f1bfef486d630f"></a><!-- doxytag: member="TreeMap::end" ref="f34c4b013e5d012ab5f1bfef486d630f" args="()" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top"><a class="el" href="class_tree_map_1_1iterator.html">TreeMap::iterator</a> TreeMap::end           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="mdname1" valign="top" nowrap>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap><code> [inline]</code></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>
Returns an iterator that addresses the location succeeding the last element in a map. 
<p>
<dl compact><dt><b><a class="el" href="todo.html#_todo000022">Todo:</a></b></dt><dd>Implement this</dd></dl>

<p>
Definition at line <a class="el" href="asd_8cc-source.html#l00255">255</a> of file <a class="el" href="asd_8cc-source.html">asd.cc</a>.
<p>
Referenced by <a class="el" href="asd_8cc-source.html#l00155">erase()</a>, <a class="el" href="asd_8cc-source.html#l00107">find()</a>, and <a class="el" href="asd_8cc-source.html#l00082">insert()</a>.    </td>
  </tr>
</table>
<a class="anchor" name="f768666a08bb3f9bf6d59af014dc8a79"></a><!-- doxytag: member="TreeMap::erase" ref="f768666a08bb3f9bf6d59af014dc8a79" args="(const Key &amp;key)" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top"><a class="el" href="class_tree_map.html#3eb1f9410d79d28273ccc045cf8e6478">TreeMap::size_type</a> TreeMap::erase           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="md" nowrap valign="top">const <a class="el" href="class_tree_map.html#897356954c2cd3d41b221e3f24f99bba">Key</a> &amp;&nbsp;</td>
          <td class="mdname1" valign="top" nowrap> <em>key</em>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>
Removes an element from the map. 
<p>
<dl compact><dt><b>Returns:</b></dt><dd>The number of elements that have been removed from the map. Since this is not a multimap itshould be 1 or 0. </dd></dl>

<p>
Definition at line <a class="el" href="asd_8cc-source.html#l00176">176</a> of file <a class="el" href="asd_8cc-source.html">asd.cc</a>.    </td>
  </tr>
</table>
<a class="anchor" name="4c750f4eb7c25898376b2945bceb60a3"></a><!-- doxytag: member="TreeMap::erase" ref="4c750f4eb7c25898376b2945bceb60a3" args="(iterator first, iterator last)" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top"><a class="el" href="class_tree_map_1_1iterator.html">TreeMap::iterator</a> TreeMap::erase           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="md" nowrap valign="top"><a class="el" href="class_tree_map_1_1iterator.html">iterator</a>&nbsp;</td>
          <td class="mdname" nowrap> <em>first</em>, </td>
        </tr>
        <tr>
          <td class="md" nowrap align="right"></td>
          <td class="md"></td>
          <td class="md" nowrap><a class="el" href="class_tree_map_1_1iterator.html">iterator</a>&nbsp;</td>
          <td class="mdname" nowrap> <em>last</em></td>
        </tr>
        <tr>
          <td class="md"></td>
          <td class="md">)&nbsp;</td>
          <td class="md" colspan="2"></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>
Removes a range of elements from the map. 
<p>
The range is defined by the first and last iterators first is the first element removed and last is the element just beyond the last elemnt removed. <dl compact><dt><b>Returns:</b></dt><dd>The iterator that designates the first element remaining beyond any elements removed. </dd></dl>

<p>
Definition at line <a class="el" href="asd_8cc-source.html#l00166">166</a> of file <a class="el" href="asd_8cc-source.html">asd.cc</a>.
<p>
References <a class="el" href="asd_8cc-source.html#l00255">end()</a>.    </td>
  </tr>
</table>
<a class="anchor" name="99d178e178a2d0a71c1f5698c5879dcf"></a><!-- doxytag: member="TreeMap::erase" ref="99d178e178a2d0a71c1f5698c5879dcf" args="(iterator i)" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top"><a class="el" href="class_tree_map_1_1iterator.html">TreeMap::iterator</a> TreeMap::erase           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="md" nowrap valign="top"><a class="el" href="class_tree_map_1_1iterator.html">iterator</a>&nbsp;</td>
          <td class="mdname1" valign="top" nowrap> <em>i</em>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>
Removes an element from the map. 
<p>
<dl compact><dt><b>Returns:</b></dt><dd>The iterator that designates the first element remaining beyond any elements removed. </dd></dl>

<p>
Definition at line <a class="el" href="asd_8cc-source.html#l00155">155</a> of file <a class="el" href="asd_8cc-source.html">asd.cc</a>.
<p>
References <a class="el" href="asd_8cc-source.html#l00255">end()</a>.    </td>
  </tr>
</table>
<a class="anchor" name="732153e7bc56dacafa2411864b548219"></a><!-- doxytag: member="TreeMap::find" ref="732153e7bc56dacafa2411864b548219" args="(const Key &amp;k) const " --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top"><a class="el" href="class_tree_map_1_1const__iterator.html">TreeMap::const_iterator</a> TreeMap::find           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="md" nowrap valign="top">const <a class="el" href="class_tree_map.html#897356954c2cd3d41b221e3f24f99bba">Key</a> &amp;&nbsp;</td>
          <td class="mdname1" valign="top" nowrap> <em>k</em>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap> const</td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>
<dl compact><dt><b><a class="el" href="todo.html#_todo000005">Todo:</a></b></dt><dd>Implement this</dd></dl>

<p>
Definition at line <a class="el" href="asd_8cc-source.html#l00114">114</a> of file <a class="el" href="asd_8cc-source.html">asd.cc</a>.    </td>
  </tr>
</table>
<a class="anchor" name="da5bc54e6c1da79235e9160ee021b9f5"></a><!-- doxytag: member="TreeMap::find" ref="da5bc54e6c1da79235e9160ee021b9f5" args="(const Key &amp;k)" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top"><a class="el" href="class_tree_map_1_1iterator.html">TreeMap::iterator</a> TreeMap::find           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="md" nowrap valign="top">const <a class="el" href="class_tree_map.html#897356954c2cd3d41b221e3f24f99bba">Key</a> &amp;&nbsp;</td>
          <td class="mdname1" valign="top" nowrap> <em>k</em>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>
Returns an iterator addressing the location of the entry in the map that has a key equivalent to the specified one or the location succeeding the last element in the map if there is no match for the key. 
<p>
<dl compact><dt><b><a class="el" href="todo.html#_todo000004">Todo:</a></b></dt><dd>Implement this</dd></dl>

<p>
Definition at line <a class="el" href="asd_8cc-source.html#l00107">107</a> of file <a class="el" href="asd_8cc-source.html">asd.cc</a>.
<p>
References <a class="el" href="asd_8cc-source.html#l00255">end()</a>.    </td>
  </tr>
</table>
<a class="anchor" name="68dd925067e3812184dcedea9211ac4b"></a><!-- doxytag: member="TreeMap::info_eq" ref="68dd925067e3812184dcedea9211ac4b" args="(const TreeMap &amp;another) const " --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">bool TreeMap::info_eq           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="md" nowrap valign="top">const <a class="el" href="class_tree_map.html">TreeMap</a> &amp;&nbsp;</td>
          <td class="mdname1" valign="top" nowrap> <em>another</em>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap> const</td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>
Returns true if this map contains exactly the same key-value pairs as the another map. 
<p>
<dl compact><dt><b><a class="el" href="todo.html#_todo000014">Todo:</a></b></dt><dd>Implement this</dd></dl>

<p>
Definition at line <a class="el" href="asd_8cc-source.html#l00198">198</a> of file <a class="el" href="asd_8cc-source.html">asd.cc</a>.
<p>
Referenced by <a class="el" href="_tree_map_8h-source.html#l00260">operator==()</a>.    </td>
  </tr>
</table>
<a class="anchor" name="94500a970d082e87b838a94fed333521"></a><!-- doxytag: member="TreeMap::insert" ref="94500a970d082e87b838a94fed333521" args="(const std::pair&lt; Key, Val &gt; &amp;entry)" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">std::pair&lt; <a class="el" href="class_tree_map_1_1iterator.html">TreeMap::iterator</a>, bool &gt; TreeMap::insert           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="md" nowrap valign="top">const std::pair&lt; <a class="el" href="class_tree_map.html#897356954c2cd3d41b221e3f24f99bba">Key</a>, <a class="el" href="class_tree_map.html#5988c20a047cfe063999787584b0aca7">Val</a> &gt; &amp;&nbsp;</td>
          <td class="mdname1" valign="top" nowrap> <em>entry</em>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>
Inserts an element into the map. 
<p>
<dl compact><dt><b>Returns:</b></dt><dd>A pair whose bool component is true if an insertion was made and false if the map already contained an element associated with that key, and whose iterator component coresponds to the address where a new element was inserted or where the element was already located. </dd></dl>

<p>
Definition at line <a class="el" href="asd_8cc-source.html#l00082">82</a> of file <a class="el" href="asd_8cc-source.html">asd.cc</a>.
<p>
References <a class="el" href="asd_8cc-source.html#l00242">begin()</a>, and <a class="el" href="asd_8cc-source.html#l00255">end()</a>.    </td>
  </tr>
</table>
<a class="anchor" name="48753429045577c544d7b1765997223e"></a><!-- doxytag: member="TreeMap::operator=" ref="48753429045577c544d7b1765997223e" args="(const TreeMap &amp;)" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top"><a class="el" href="class_tree_map.html">TreeMap</a> &amp; TreeMap::operator=           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="md" nowrap valign="top">const <a class="el" href="class_tree_map.html">TreeMap</a> &amp;&nbsp;</td>
          <td class="mdname1" valign="top" nowrap>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>
Assignment operator copy the source elements into this object. 
<p>
<dl compact><dt><b><a class="el" href="todo.html#_todo000019">Todo:</a></b></dt><dd>Implement this</dd></dl>

<p>
Definition at line <a class="el" href="asd_8cc-source.html#l00235">235</a> of file <a class="el" href="asd_8cc-source.html">asd.cc</a>.    </td>
  </tr>
</table>
<a class="anchor" name="18b0ae91b08ac71b923d1c9dd85f7876"></a><!-- doxytag: member="TreeMap::operator==" ref="18b0ae91b08ac71b923d1c9dd85f7876" args="(const TreeMap &amp;a) const " --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">bool TreeMap::operator==           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="md" nowrap valign="top">const <a class="el" href="class_tree_map.html">TreeMap</a> &amp;&nbsp;</td>
          <td class="mdname1" valign="top" nowrap> <em>a</em>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap> const<code> [inline]</code></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>
Returns true if this map contains exactly the same key-value pairs as the another map. 
<p>

<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00260">260</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.
<p>
References <a class="el" href="asd_8cc-source.html#l00198">info_eq()</a>.    </td>
  </tr>
</table>
<a class="anchor" name="ce20a84b60c9bcce43c37cb75d29fe50"></a><!-- doxytag: member="TreeMap::operator[]" ref="ce20a84b60c9bcce43c37cb75d29fe50" args="(const Key &amp;k)" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top"><a class="el" href="class_tree_map.html#5988c20a047cfe063999787584b0aca7">TreeMap::Val</a> &amp; TreeMap::operator[]           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="md" nowrap valign="top">const <a class="el" href="class_tree_map.html#897356954c2cd3d41b221e3f24f99bba">Key</a> &amp;&nbsp;</td>
          <td class="mdname1" valign="top" nowrap> <em>k</em>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>
Inserts an element into a map with a specified key value if one with such a key value does not exist. 
<p>
<dl compact><dt><b>Returns:</b></dt><dd>Reference to the value component of the element defined by the key. </dd></dl>

<p>
Definition at line <a class="el" href="asd_8cc-source.html#l00124">124</a> of file <a class="el" href="asd_8cc-source.html">asd.cc</a>.    </td>
  </tr>
</table>
<a class="anchor" name="5a9421972c178b3c37b99f953470c6f6"></a><!-- doxytag: member="TreeMap::size" ref="5a9421972c178b3c37b99f953470c6f6" args="() const " --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top"><a class="el" href="class_tree_map.html#3eb1f9410d79d28273ccc045cf8e6478">TreeMap::size_type</a> TreeMap::size           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="mdname1" valign="top" nowrap>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap> const</td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>
Returns the number of elements in the map. 
<p>
<dl compact><dt><b><a class="el" href="todo.html#_todo000007">Todo:</a></b></dt><dd>Implement this</dd></dl>

<p>
Definition at line <a class="el" href="asd_8cc-source.html#l00139">139</a> of file <a class="el" href="asd_8cc-source.html">asd.cc</a>.    </td>
  </tr>
</table>
<a class="anchor" name="e62bc2a78904e459d5f302a5ff48769a"></a><!-- doxytag: member="TreeMap::struct_eq" ref="e62bc2a78904e459d5f302a5ff48769a" args="(const TreeMap &amp;another) const " --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">bool TreeMap::struct_eq           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="md" nowrap valign="top">const <a class="el" href="class_tree_map.html">TreeMap</a> &amp;&nbsp;</td>
          <td class="mdname1" valign="top" nowrap> <em>another</em>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap> const</td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>
Returns true if this map's internal structure is identical to another map's structure. 
<p>
<dl compact><dt><b><a class="el" href="todo.html#_todo000013">Todo:</a></b></dt><dd>Implement this</dd></dl>

<p>
Definition at line <a class="el" href="asd_8cc-source.html#l00191">191</a> of file <a class="el" href="asd_8cc-source.html">asd.cc</a>.    </td>
  </tr>
</table>
<a class="anchor" name="9b42b72518de2845832b80e44424fab3"></a><!-- doxytag: member="TreeMap::unsafe_insert" ref="9b42b72518de2845832b80e44424fab3" args="(const std::pair&lt; Key, Val &gt; &amp;entry)" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top"><a class="el" href="class_tree_map_1_1iterator.html">TreeMap::iterator</a> TreeMap::unsafe_insert           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="md" nowrap valign="top">const std::pair&lt; <a class="el" href="class_tree_map.html#897356954c2cd3d41b221e3f24f99bba">Key</a>, <a class="el" href="class_tree_map.html#5988c20a047cfe063999787584b0aca7">Val</a> &gt; &amp;&nbsp;</td>
          <td class="mdname1" valign="top" nowrap> <em>entry</em>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>
Inserts an element into the map. 
<p>
This method assumes there is no value asociated with such a key in the map. 
<p>
Definition at line <a class="el" href="asd_8cc-source.html#l00097">97</a> of file <a class="el" href="asd_8cc-source.html">asd.cc</a>.
<p>
References <a class="el" href="_tree_map_8h-source.html#l00086">root</a>.    </td>
  </tr>
</table>
<hr><h2>Friends And Related Function Documentation</h2>
<a class="anchor" name="359f4c98a692d55e998de2a0ccbfe3c9"></a><!-- doxytag: member="TreeMap::TreeMapDetail" ref="359f4c98a692d55e998de2a0ccbfe3c9" args="" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">friend class <a class="el" href="class_tree_map_detail.html">TreeMapDetail</a><code> [friend]</code>          </td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>

<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00079">79</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.    </td>
  </tr>
</table>
<hr><h2>Member Data Documentation</h2>
<a class="anchor" name="951da6b7179a4f697cc89d36acf74e52"></a><!-- doxytag: member="TreeMap::detail" ref="951da6b7179a4f697cc89d36acf74e52" args="" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top"><a class="el" href="class_tree_map_detail.html">TreeMapDetail</a>* <a class="el" href="class_tree_map.html#951da6b7179a4f697cc89d36acf74e52">TreeMap::detail</a><code> [protected]</code>          </td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>

<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00087">87</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.    </td>
  </tr>
</table>
<a class="anchor" name="63a9f0ea7bb98050796b649e85481845"></a><!-- doxytag: member="TreeMap::root" ref="63a9f0ea7bb98050796b649e85481845" args="" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top"><a class="el" href="struct_tree_node.html">Node</a>* <a class="el" href="class_tree_map.html#63a9f0ea7bb98050796b649e85481845">TreeMap::root</a><code> [protected]</code>          </td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>
The root of the tree. 
<p>

<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00086">86</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.
<p>
Referenced by <a class="el" href="asd_8cc-source.html#l00133">empty()</a>, <a class="el" href="asd_8cc-source.html#l00050">TreeMapDetail::erase()</a>, <a class="el" href="asd_8cc-source.html#l00060">TreeMap()</a>, and <a class="el" href="asd_8cc-source.html#l00097">unsafe_insert()</a>.    </td>
  </tr>
</table>
<hr>The documentation for this class was generated from the following files:<ul>
<li><a class="el" href="_tree_map_8h-source.html">TreeMap.h</a><li><a class="el" href="asd_8cc-source.html">asd.cc</a></ul>
<hr size="1"><address style="align: right;"><small>Generated on Fri Dec 2 01:03:51 2005 for AISDI Cwiczenie 4 by&nbsp;
<a href="http://www.doxygen.org/index.html">
<img src="doxygen.png" alt="doxygen" align="middle" border="0"></a> 1.4.5 </small></address>
</body>
</html>
="18b0ae91b08ac71b923d1c9dd85f7876"></a><!-- doxytag: member="Tretree/info/class_tree_map_1_1const__iterator.html                                                    0100644 0003673 0000144 00000064430 11704031106 0023317 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html><head><meta http-equiv="Content-Type" content="text/html;charset=iso-8859-1">
<title>AISDI Cwiczenie 4: TreeMap::const_iterator Class Reference</title>
<link href="doxygen.css" rel="stylesheet" type="text/css">
<link href="tabs.css" rel="stylesheet" type="text/css">
</head><body>
<!-- Generated by Doxygen 1.4.5 -->
<div class="tabs">
  <ul>
    <li><a href="index.html"><span>Main&nbsp;Page</span></a></li>
    <li id="current"><a href="annotated.html"><span>Classes</span></a></li>
    <li><a href="files.html"><span>Files</span></a></li>
    <li><a href="pages.html"><span>Related&nbsp;Pages</span></a></li>
  </ul></div>
<div class="tabs">
  <ul>
    <li><a href="annotated.html"><span>Class&nbsp;List</span></a></li>
    <li><a href="classes.html"><span>Alphabetical&nbsp;List</span></a></li>
    <li><a href="hierarchy.html"><span>Class&nbsp;Hierarchy</span></a></li>
    <li><a href="functions.html"><span>Class&nbsp;Members</span></a></li>
  </ul></div>
<div class="nav">
<a class="el" href="class_tree_map.html">TreeMap</a>::<a class="el" href="class_tree_map_1_1const__iterator.html">const_iterator</a></div>
<h1>TreeMap::const_iterator Class Reference</h1><!-- doxytag: class="TreeMap::const_iterator" --><!-- doxytag: inherits="std::iterator" -->A <a class="el" href="class_tree_map_1_1const__iterator.html">const_iterator</a>.  
<a href="#_details">More...</a>
<p>
<code>#include &lt;<a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>&gt;</code>
<p>
Inherits <a class="el" href="classstd_1_1iterator.html">iterator</a>.
<p>
Inherited by <a class="el" href="class_tree_map_1_1iterator.html">TreeMap::iterator</a>.
<p>
Inheritance diagram for TreeMap::const_iterator:<p><center><img src="class_tree_map_1_1const__iterator__inherit__graph.png" border="0" usemap="#_tree_map_1_1const__iterator__inherit__map" alt="Inheritance graph"></center>
<map name="_tree_map_1_1const__iterator__inherit__map">
<area href="class_tree_map_1_1iterator.html" shape="rect" coords="145,156,268,183" alt="">
<area href="classstd_1_1iterator.html" shape="rect" coords="7,7,407,33" alt="">
</map>
<center><font size="2">[<a href="graph_legend.html">legend</a>]</font></center>Collaboration diagram for TreeMap::const_iterator:<p><center><img src="class_tree_map_1_1const__iterator__coll__graph.png" border="0" usemap="#_tree_map_1_1const__iterator__coll__map" alt="Collaboration graph"></center>
<map name="_tree_map_1_1const__iterator__coll__map">
<area href="classstd_1_1iterator.html" shape="rect" coords="7,199,407,225" alt="">
<area href="struct_tree_node.html" shape="rect" coords="431,199,511,225" alt="">
<area href="class_c_count.html" shape="rect" coords="391,97,457,124" alt="">
</map>
<center><font size="2">[<a href="graph_legend.html">legend</a>]</font></center><a href="class_tree_map_1_1const__iterator-members.html">List of all members.</a><table border="0" cellpadding="0" cellspacing="0">
<tr><td></td></tr>
<tr><td colspan="2"><br><h2>Public Types</h2></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top">typedef std::pair&lt; <a class="el" href="class_tree_map.html#897356954c2cd3d41b221e3f24f99bba">Key</a>, <a class="el" href="class_tree_map.html#5988c20a047cfe063999787584b0aca7">Val</a> &gt;&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map_1_1const__iterator.html#b9ece18c950afbfa6b0fdbfa4ff731d3">T</a></td></tr>

<tr><td colspan="2"><br><h2>Public Member Functions</h2></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top">&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map_1_1const__iterator.html#645ef348f77c435481d85152ee348aa2">const_iterator</a> ()</td></tr>

<tr><td class="memItemLeft" nowrap align="right" valign="top">&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map_1_1const__iterator.html#6e845f4990b76b6659a5e525ee7c917e">const_iterator</a> (const <a class="el" href="class_tree_map_1_1const__iterator.html">const_iterator</a> &amp;a)</td></tr>

<tr><td class="memItemLeft" nowrap align="right" valign="top">const <a class="el" href="class_tree_map_1_1const__iterator.html#b9ece18c950afbfa6b0fdbfa4ff731d3">T</a> &amp;&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map_1_1const__iterator.html#f7a39cedb9cf2cea096b6e77b4794aa2">operator *</a> () const </td></tr>

<tr><td class="memItemLeft" nowrap align="right" valign="top">const <a class="el" href="class_tree_map_1_1const__iterator.html#b9ece18c950afbfa6b0fdbfa4ff731d3">T</a> *&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map_1_1const__iterator.html#0435166b505820018f60233eb3f00662">operator-&gt;</a> () const </td></tr>

<tr><td class="memItemLeft" nowrap align="right" valign="top"><a class="el" href="class_tree_map_1_1const__iterator.html">const_iterator</a> &amp;&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map_1_1const__iterator.html#879fb570af328b721ed45fe254b0a582">operator++</a> ()</td></tr>

<tr><td class="memItemLeft" nowrap align="right" valign="top"><a class="el" href="class_tree_map_1_1const__iterator.html">const_iterator</a>&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map_1_1const__iterator.html#5d4681e027a07e3fb51ab21bef0dcc3d">operator++</a> (int)</td></tr>

<tr><td class="memItemLeft" nowrap align="right" valign="top"><a class="el" href="class_tree_map_1_1const__iterator.html">const_iterator</a> &amp;&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map_1_1const__iterator.html#08e169f7d9d8a763281a98d478c20a02">operator--</a> ()</td></tr>

<tr><td class="memItemLeft" nowrap align="right" valign="top"><a class="el" href="class_tree_map_1_1const__iterator.html">const_iterator</a>&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map_1_1const__iterator.html#12332c0f3ca9f1be40bf725d24d260ef">operator--</a> (int)</td></tr>

<tr><td class="memItemLeft" nowrap align="right" valign="top">bool&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map_1_1const__iterator.html#af10f269139a928a53584bc453003226">operator==</a> (const <a class="el" href="class_tree_map_1_1const__iterator.html">const_iterator</a> &amp;a) const </td></tr>

<tr><td class="memItemLeft" nowrap align="right" valign="top">bool&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map_1_1const__iterator.html#1afff81678307f558fa6ed1eadd24c40">operator!=</a> (const <a class="el" href="class_tree_map_1_1const__iterator.html">const_iterator</a> &amp;a) const </td></tr>

<tr><td colspan="2"><br><h2>Protected Member Functions</h2></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top">&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map_1_1const__iterator.html#27f123de1dda4c35c67d132f620c5b7a">const_iterator</a> (<a class="el" href="struct_tree_node.html">Node</a> *x)</td></tr>

<tr><td colspan="2"><br><h2>Protected Attributes</h2></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top"><a class="el" href="struct_tree_node.html">Node</a> *&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map_1_1const__iterator.html#36c4536996ca5615dcf9911f068786dc">node</a></td></tr>

<tr><td class="mdescLeft">&nbsp;</td><td class="mdescRight">Points to the tree element.  <a href="#36c4536996ca5615dcf9911f068786dc"></a><br></td></tr>
<tr><td colspan="2"><br><h2>Friends</h2></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top">class&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map_1_1const__iterator.html#ec21601f0dade4123a4f02c3ab309706">TreeMap</a></td></tr>

</table>
<hr><a name="_details"></a><h2>Detailed Description</h2>
A <a class="el" href="class_tree_map_1_1const__iterator.html">const_iterator</a>. 
<p>
It also serves as a base for the (not const) iterator. 
<p>

<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00098">98</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.<hr><h2>Member Typedef Documentation</h2>
<a class="anchor" name="b9ece18c950afbfa6b0fdbfa4ff731d3"></a><!-- doxytag: member="TreeMap::const_iterator::T" ref="b9ece18c950afbfa6b0fdbfa4ff731d3" args="" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">typedef std::pair&lt;<a class="el" href="class_tree_map.html#897356954c2cd3d41b221e3f24f99bba">Key</a>, <a class="el" href="class_tree_map.html#5988c20a047cfe063999787584b0aca7">Val</a>&gt; <a class="el" href="class_tree_map_1_1const__iterator.html#b9ece18c950afbfa6b0fdbfa4ff731d3">TreeMap::const_iterator::T</a>          </td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>

<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00102">102</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.    </td>
  </tr>
</table>
<hr><h2>Constructor &amp; Destructor Documentation</h2>
<a class="anchor" name="27f123de1dda4c35c67d132f620c5b7a"></a><!-- doxytag: member="TreeMap::const_iterator::const_iterator" ref="27f123de1dda4c35c67d132f620c5b7a" args="(Node *x)" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">TreeMap::const_iterator::const_iterator           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="md" nowrap valign="top"><a class="el" href="struct_tree_node.html">Node</a> *&nbsp;</td>
          <td class="mdname1" valign="top" nowrap> <em>x</em>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap><code> [inline, protected]</code></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>

<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00109">109</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.    </td>
  </tr>
</table>
<a class="anchor" name="645ef348f77c435481d85152ee348aa2"></a><!-- doxytag: member="TreeMap::const_iterator::const_iterator" ref="645ef348f77c435481d85152ee348aa2" args="()" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">TreeMap::const_iterator::const_iterator           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="mdname1" valign="top" nowrap>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap><code> [inline]</code></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>

<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00111">111</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.    </td>
  </tr>
</table>
<a class="anchor" name="6e845f4990b76b6659a5e525ee7c917e"></a><!-- doxytag: member="TreeMap::const_iterator::const_iterator" ref="6e845f4990b76b6659a5e525ee7c917e" args="(const const_iterator &amp;a)" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">TreeMap::const_iterator::const_iterator           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="md" nowrap valign="top">const <a class="el" href="class_tree_map_1_1const__iterator.html">const_iterator</a> &amp;&nbsp;</td>
          <td class="mdname1" valign="top" nowrap> <em>a</em>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap><code> [inline]</code></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>

<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00112">112</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.    </td>
  </tr>
</table>
<hr><h2>Member Function Documentation</h2>
<a class="anchor" name="f7a39cedb9cf2cea096b6e77b4794aa2"></a><!-- doxytag: member="TreeMap::const_iterator::operator *" ref="f7a39cedb9cf2cea096b6e77b4794aa2" args="() const " --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">const <a class="el" href="class_tree_map_1_1const__iterator.html#b9ece18c950afbfa6b0fdbfa4ff731d3">T</a>&amp; TreeMap::const_iterator::operator *           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="mdname1" valign="top" nowrap>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap> const<code> [inline]</code></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>

<p>
Reimplemented in <a class="el" href="class_tree_map_1_1iterator.html#f7a39cedb9cf2cea096b6e77b4794aa2">TreeMap::iterator</a>.
<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00114">114</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.
<p>
References <a class="el" href="_tree_map_8h-source.html#l00068">TreeNode::data</a>, and <a class="el" href="_tree_map_8h-source.html#l00106">node</a>.    </td>
  </tr>
</table>
<a class="anchor" name="1afff81678307f558fa6ed1eadd24c40"></a><!-- doxytag: member="TreeMap::const_iterator::operator!=" ref="1afff81678307f558fa6ed1eadd24c40" args="(const const_iterator &amp;a) const " --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">bool TreeMap::const_iterator::operator!=           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="md" nowrap valign="top">const <a class="el" href="class_tree_map_1_1const__iterator.html">const_iterator</a> &amp;&nbsp;</td>
          <td class="mdname1" valign="top" nowrap> <em>a</em>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap> const<code> [inline]</code></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>

<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00138">138</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.
<p>
References <a class="el" href="_tree_map_8h-source.html#l00106">node</a>.    </td>
  </tr>
</table>
<a class="anchor" name="5d4681e027a07e3fb51ab21bef0dcc3d"></a><!-- doxytag: member="TreeMap::const_iterator::operator++" ref="5d4681e027a07e3fb51ab21bef0dcc3d" args="(int)" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top"><a class="el" href="class_tree_map_1_1const__iterator.html">TreeMap::const_iterator</a> TreeMap::const_iterator::operator++           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="md" nowrap valign="top">int&nbsp;</td>
          <td class="mdname1" valign="top" nowrap>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>
<dl compact><dt><b><a class="el" href="todo.html#_todo000016">Todo:</a></b></dt><dd>Implement this</dd></dl>

<p>
Reimplemented in <a class="el" href="class_tree_map_1_1iterator.html#5d4681e027a07e3fb51ab21bef0dcc3d">TreeMap::iterator</a>.
<p>
Definition at line <a class="el" href="asd_8cc-source.html#l00213">213</a> of file <a class="el" href="asd_8cc-source.html">asd.cc</a>.    </td>
  </tr>
</table>
<a class="anchor" name="879fb570af328b721ed45fe254b0a582"></a><!-- doxytag: member="TreeMap::const_iterator::operator++" ref="879fb570af328b721ed45fe254b0a582" args="()" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top"><a class="el" href="class_tree_map_1_1const__iterator.html">TreeMap::const_iterator</a> &amp; TreeMap::const_iterator::operator++           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="mdname1" valign="top" nowrap>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>
<dl compact><dt><b><a class="el" href="todo.html#_todo000015">Todo:</a></b></dt><dd>Implement this</dd></dl>

<p>
Reimplemented in <a class="el" href="class_tree_map_1_1iterator.html#879fb570af328b721ed45fe254b0a582">TreeMap::iterator</a>.
<p>
Definition at line <a class="el" href="asd_8cc-source.html#l00206">206</a> of file <a class="el" href="asd_8cc-source.html">asd.cc</a>.
<p>
Referenced by <a class="el" href="_tree_map_8h-source.html#l00119">operator-&gt;()</a>.    </td>
  </tr>
</table>
<a class="anchor" name="12332c0f3ca9f1be40bf725d24d260ef"></a><!-- doxytag: member="TreeMap::const_iterator::operator--" ref="12332c0f3ca9f1be40bf725d24d260ef" args="(int)" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top"><a class="el" href="class_tree_map_1_1const__iterator.html">TreeMap::const_iterator</a> TreeMap::const_iterator::operator--           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="md" nowrap valign="top">int&nbsp;</td>
          <td class="mdname1" valign="top" nowrap>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>
<dl compact><dt><b><a class="el" href="todo.html#_todo000018">Todo:</a></b></dt><dd>Implement this</dd></dl>

<p>
Reimplemented in <a class="el" href="class_tree_map_1_1iterator.html#12332c0f3ca9f1be40bf725d24d260ef">TreeMap::iterator</a>.
<p>
Definition at line <a class="el" href="asd_8cc-source.html#l00227">227</a> of file <a class="el" href="asd_8cc-source.html">asd.cc</a>.    </td>
  </tr>
</table>
<a class="anchor" name="08e169f7d9d8a763281a98d478c20a02"></a><!-- doxytag: member="TreeMap::const_iterator::operator--" ref="08e169f7d9d8a763281a98d478c20a02" args="()" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top"><a class="el" href="class_tree_map_1_1const__iterator.html">TreeMap::const_iterator</a> &amp; TreeMap::const_iterator::operator--           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="mdname1" valign="top" nowrap>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>
<dl compact><dt><b><a class="el" href="todo.html#_todo000017">Todo:</a></b></dt><dd>Implement this</dd></dl>

<p>
Reimplemented in <a class="el" href="class_tree_map_1_1iterator.html#08e169f7d9d8a763281a98d478c20a02">TreeMap::iterator</a>.
<p>
Definition at line <a class="el" href="asd_8cc-source.html#l00220">220</a> of file <a class="el" href="asd_8cc-source.html">asd.cc</a>.
<p>
Referenced by <a class="el" href="_tree_map_8h-source.html#l00119">operator-&gt;()</a>.    </td>
  </tr>
</table>
<a class="anchor" name="0435166b505820018f60233eb3f00662"></a><!-- doxytag: member="TreeMap::const_iterator::operator-&gt;" ref="0435166b505820018f60233eb3f00662" args="() const " --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">const <a class="el" href="class_tree_map_1_1const__iterator.html#b9ece18c950afbfa6b0fdbfa4ff731d3">T</a>* TreeMap::const_iterator::operator-&gt;           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="mdname1" valign="top" nowrap>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap> const<code> [inline]</code></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>

<p>
Reimplemented in <a class="el" href="class_tree_map_1_1iterator.html#0435166b505820018f60233eb3f00662">TreeMap::iterator</a>.
<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00119">119</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.
<p>
References <a class="el" href="_tree_map_8h-source.html#l00068">TreeNode::data</a>, <a class="el" href="_tree_map_8h-source.html#l00106">node</a>, <a class="el" href="asd_8cc-source.html#l00206">operator++()</a>, and <a class="el" href="asd_8cc-source.html#l00220">operator--()</a>.    </td>
  </tr>
</table>
<a class="anchor" name="af10f269139a928a53584bc453003226"></a><!-- doxytag: member="TreeMap::const_iterator::operator==" ref="af10f269139a928a53584bc453003226" args="(const const_iterator &amp;a) const " --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">bool TreeMap::const_iterator::operator==           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="md" nowrap valign="top">const <a class="el" href="class_tree_map_1_1const__iterator.html">const_iterator</a> &amp;&nbsp;</td>
          <td class="mdname1" valign="top" nowrap> <em>a</em>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap> const<code> [inline]</code></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>

<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00133">133</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.
<p>
References <a class="el" href="_tree_map_8h-source.html#l00106">node</a>.    </td>
  </tr>
</table>
<hr><h2>Friends And Related Function Documentation</h2>
<a class="anchor" name="ec21601f0dade4123a4f02c3ab309706"></a><!-- doxytag: member="TreeMap::const_iterator::TreeMap" ref="ec21601f0dade4123a4f02c3ab309706" args="" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">friend class <a class="el" href="class_tree_map.html">TreeMap</a><code> [friend]</code>          </td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>

<p>
Reimplemented in <a class="el" href="class_tree_map_1_1iterator.html#ec21601f0dade4123a4f02c3ab309706">TreeMap::iterator</a>.
<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00107">107</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.    </td>
  </tr>
</table>
<hr><h2>Member Data Documentation</h2>
<a class="anchor" name="36c4536996ca5615dcf9911f068786dc"></a><!-- doxytag: member="TreeMap::const_iterator::node" ref="36c4536996ca5615dcf9911f068786dc" args="" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top"><a class="el" href="struct_tree_node.html">Node</a>* <a class="el" href="class_tree_map_1_1const__iterator.html#36c4536996ca5615dcf9911f068786dc">TreeMap::const_iterator::node</a><code> [protected]</code>          </td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>
Points to the tree element. 
<p>

<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00106">106</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.
<p>
Referenced by <a class="el" href="_tree_map_8h-source.html#l00153">TreeMap::iterator::iterator()</a>, <a class="el" href="_tree_map_8h-source.html#l00155">TreeMap::iterator::operator *()</a>, <a class="el" href="_tree_map_8h-source.html#l00114">operator *()</a>, <a class="el" href="_tree_map_8h-source.html#l00138">operator!=()</a>, <a class="el" href="_tree_map_8h-source.html#l00159">TreeMap::iterator::operator-&gt;()</a>, <a class="el" href="_tree_map_8h-source.html#l00119">operator-&gt;()</a>, and <a class="el" href="_tree_map_8h-source.html#l00133">operator==()</a>.    </td>
  </tr>
</table>
<hr>The documentation for this class was generated from the following files:<ul>
<li><a class="el" href="_tree_map_8h-source.html">TreeMap.h</a><li><a class="el" href="asd_8cc-source.html">asd.cc</a></ul>
<hr size="1"><address style="align: right;"><small>Generated on Fri Dec 2 01:03:51 2005 for AISDI Cwiczenie 4 by&nbsp;
<a href="http://www.doxygen.org/index.html">
<img src="doxygen.png" alt="doxygen" align="middle" border="0"></a> 1.4.5 </small></address>
</body>
</html>
bef0dcc3d">TreeMap::iterator</a>.
<p>
Definition at line <a class="el" href="asd_8cc-source.html#l00213">213</a> of file <a class="el" href="asd_8cc-source.html">asd.cc</a>.    </td>
  </tr>
</table>
<a class="anchor" name="879fb570tree/info/class_tree_map_1_1const__iterator-members.html                                            0100644 0003673 0000144 00000012354 11704031106 0024745 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html><head><meta http-equiv="Content-Type" content="text/html;charset=iso-8859-1">
<title>AISDI Cwiczenie 4: Member List</title>
<link href="doxygen.css" rel="stylesheet" type="text/css">
<link href="tabs.css" rel="stylesheet" type="text/css">
</head><body>
<!-- Generated by Doxygen 1.4.5 -->
<div class="tabs">
  <ul>
    <li><a href="index.html"><span>Main&nbsp;Page</span></a></li>
    <li id="current"><a href="annotated.html"><span>Classes</span></a></li>
    <li><a href="files.html"><span>Files</span></a></li>
    <li><a href="pages.html"><span>Related&nbsp;Pages</span></a></li>
  </ul></div>
<div class="tabs">
  <ul>
    <li><a href="annotated.html"><span>Class&nbsp;List</span></a></li>
    <li><a href="classes.html"><span>Alphabetical&nbsp;List</span></a></li>
    <li><a href="hierarchy.html"><span>Class&nbsp;Hierarchy</span></a></li>
    <li><a href="functions.html"><span>Class&nbsp;Members</span></a></li>
  </ul></div>
<h1>TreeMap::const_iterator Member List</h1>This is the complete list of members for <a class="el" href="class_tree_map_1_1const__iterator.html">TreeMap::const_iterator</a>, including all inherited members.<p><table>
  <tr class="memlist"><td><a class="el" href="class_tree_map_1_1const__iterator.html#27f123de1dda4c35c67d132f620c5b7a">const_iterator</a>(Node *x)</td><td><a class="el" href="class_tree_map_1_1const__iterator.html">TreeMap::const_iterator</a></td><td><code> [inline, protected]</code></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map_1_1const__iterator.html#645ef348f77c435481d85152ee348aa2">const_iterator</a>()</td><td><a class="el" href="class_tree_map_1_1const__iterator.html">TreeMap::const_iterator</a></td><td><code> [inline]</code></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map_1_1const__iterator.html#6e845f4990b76b6659a5e525ee7c917e">const_iterator</a>(const const_iterator &amp;a)</td><td><a class="el" href="class_tree_map_1_1const__iterator.html">TreeMap::const_iterator</a></td><td><code> [inline]</code></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map_1_1const__iterator.html#36c4536996ca5615dcf9911f068786dc">node</a></td><td><a class="el" href="class_tree_map_1_1const__iterator.html">TreeMap::const_iterator</a></td><td><code> [protected]</code></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map_1_1const__iterator.html#f7a39cedb9cf2cea096b6e77b4794aa2">operator *</a>() const </td><td><a class="el" href="class_tree_map_1_1const__iterator.html">TreeMap::const_iterator</a></td><td><code> [inline]</code></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map_1_1const__iterator.html#1afff81678307f558fa6ed1eadd24c40">operator!=</a>(const const_iterator &amp;a) const </td><td><a class="el" href="class_tree_map_1_1const__iterator.html">TreeMap::const_iterator</a></td><td><code> [inline]</code></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map_1_1const__iterator.html#879fb570af328b721ed45fe254b0a582">operator++</a>()</td><td><a class="el" href="class_tree_map_1_1const__iterator.html">TreeMap::const_iterator</a></td><td></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map_1_1const__iterator.html#5d4681e027a07e3fb51ab21bef0dcc3d">operator++</a>(int)</td><td><a class="el" href="class_tree_map_1_1const__iterator.html">TreeMap::const_iterator</a></td><td></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map_1_1const__iterator.html#08e169f7d9d8a763281a98d478c20a02">operator--</a>()</td><td><a class="el" href="class_tree_map_1_1const__iterator.html">TreeMap::const_iterator</a></td><td></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map_1_1const__iterator.html#12332c0f3ca9f1be40bf725d24d260ef">operator--</a>(int)</td><td><a class="el" href="class_tree_map_1_1const__iterator.html">TreeMap::const_iterator</a></td><td></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map_1_1const__iterator.html#0435166b505820018f60233eb3f00662">operator-&gt;</a>() const </td><td><a class="el" href="class_tree_map_1_1const__iterator.html">TreeMap::const_iterator</a></td><td><code> [inline]</code></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map_1_1const__iterator.html#af10f269139a928a53584bc453003226">operator==</a>(const const_iterator &amp;a) const </td><td><a class="el" href="class_tree_map_1_1const__iterator.html">TreeMap::const_iterator</a></td><td><code> [inline]</code></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map_1_1const__iterator.html#b9ece18c950afbfa6b0fdbfa4ff731d3">T</a> typedef</td><td><a class="el" href="class_tree_map_1_1const__iterator.html">TreeMap::const_iterator</a></td><td></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map_1_1const__iterator.html#ec21601f0dade4123a4f02c3ab309706">TreeMap</a> class</td><td><a class="el" href="class_tree_map_1_1const__iterator.html">TreeMap::const_iterator</a></td><td><code> [friend]</code></td></tr>
</table><hr size="1"><address style="align: right;"><small>Generated on Fri Dec 2 01:03:51 2005 for AISDI Cwiczenie 4 by&nbsp;
<a href="http://www.doxygen.org/index.html">
<img src="doxygen.png" alt="doxygen" align="middle" border="0"></a> 1.4.5 </small></address>
</body>
</html>
" href="class_tree_map_1_1const__iterator.html#27f123de1dda4c35c67d132f620c5b7a">const_iterator</a>(Node *x)</td><td><a class="el" href="class_tree_map_1_1const__iterator.html">TreeMap::const_iterator</a></td><td><code> [inline, protected]</code></td></tr>
  <tr class="memlistree/info/class_tree_map_1_1iterator.html                                                           0100644 0003673 0000144 00000066334 11704031106 0021757 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html><head><meta http-equiv="Content-Type" content="text/html;charset=iso-8859-1">
<title>AISDI Cwiczenie 4: TreeMap::iterator Class Reference</title>
<link href="doxygen.css" rel="stylesheet" type="text/css">
<link href="tabs.css" rel="stylesheet" type="text/css">
</head><body>
<!-- Generated by Doxygen 1.4.5 -->
<div class="tabs">
  <ul>
    <li><a href="index.html"><span>Main&nbsp;Page</span></a></li>
    <li id="current"><a href="annotated.html"><span>Classes</span></a></li>
    <li><a href="files.html"><span>Files</span></a></li>
    <li><a href="pages.html"><span>Related&nbsp;Pages</span></a></li>
  </ul></div>
<div class="tabs">
  <ul>
    <li><a href="annotated.html"><span>Class&nbsp;List</span></a></li>
    <li><a href="classes.html"><span>Alphabetical&nbsp;List</span></a></li>
    <li><a href="hierarchy.html"><span>Class&nbsp;Hierarchy</span></a></li>
    <li><a href="functions.html"><span>Class&nbsp;Members</span></a></li>
  </ul></div>
<div class="nav">
<a class="el" href="class_tree_map.html">TreeMap</a>::<a class="el" href="class_tree_map_1_1iterator.html">iterator</a></div>
<h1>TreeMap::iterator Class Reference</h1><!-- doxytag: class="TreeMap::iterator" --><!-- doxytag: inherits="TreeMap::const_iterator" -->An iterator.  
<a href="#_details">More...</a>
<p>
<code>#include &lt;<a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>&gt;</code>
<p>
Inherits <a class="el" href="class_tree_map_1_1const__iterator.html">TreeMap::const_iterator</a>.
<p>
Inheritance diagram for TreeMap::iterator:<p><center><img src="class_tree_map_1_1iterator__inherit__graph.png" border="0" usemap="#_tree_map_1_1iterator__inherit__map" alt="Inheritance graph"></center>
<map name="_tree_map_1_1iterator__inherit__map">
<area href="class_tree_map_1_1const__iterator.html" shape="rect" coords="125,81,288,108" alt="">
<area href="classstd_1_1iterator.html" shape="rect" coords="7,7,407,33" alt="">
</map>
<center><font size="2">[<a href="graph_legend.html">legend</a>]</font></center>Collaboration diagram for TreeMap::iterator:<p><center><img src="class_tree_map_1_1iterator__coll__graph.png" border="0" usemap="#_tree_map_1_1iterator__coll__map" alt="Collaboration graph"></center>
<map name="_tree_map_1_1iterator__coll__map">
<area href="class_tree_map_1_1const__iterator.html" shape="rect" coords="201,300,364,327" alt="">
<area href="classstd_1_1iterator.html" shape="rect" coords="7,199,407,226" alt="">
<area href="struct_tree_node.html" shape="rect" coords="431,199,511,226" alt="">
<area href="class_c_count.html" shape="rect" coords="391,98,457,124" alt="">
</map>
<center><font size="2">[<a href="graph_legend.html">legend</a>]</font></center><a href="class_tree_map_1_1iterator-members.html">List of all members.</a><table border="0" cellpadding="0" cellspacing="0">
<tr><td></td></tr>
<tr><td colspan="2"><br><h2>Public Types</h2></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top">typedef std::pair&lt; <a class="el" href="class_tree_map.html#897356954c2cd3d41b221e3f24f99bba">Key</a>, <a class="el" href="class_tree_map.html#5988c20a047cfe063999787584b0aca7">Val</a> &gt;&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map_1_1const__iterator.html#b9ece18c950afbfa6b0fdbfa4ff731d3">T</a></td></tr>

<tr><td colspan="2"><br><h2>Public Member Functions</h2></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top">&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map_1_1iterator.html#c49f9eff2ae38470827eedc5b90f1eb1">iterator</a> ()</td></tr>

<tr><td class="memItemLeft" nowrap align="right" valign="top">&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map_1_1iterator.html#f0f6d6b5b544eb701ae3d015e6133e1e">iterator</a> (const <a class="el" href="class_tree_map_1_1const__iterator.html">const_iterator</a> &amp;a)</td></tr>

<tr><td class="memItemLeft" nowrap align="right" valign="top">&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map_1_1iterator.html#5c297ca07cf2a75a9b0227b654c196d9">iterator</a> (const <a class="el" href="class_tree_map_1_1iterator.html">iterator</a> &amp;a)</td></tr>

<tr><td class="memItemLeft" nowrap align="right" valign="top"><a class="el" href="class_tree_map_1_1const__iterator.html#b9ece18c950afbfa6b0fdbfa4ff731d3">T</a> &amp;&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map_1_1iterator.html#f7a39cedb9cf2cea096b6e77b4794aa2">operator *</a> () const </td></tr>

<tr><td class="memItemLeft" nowrap align="right" valign="top"><a class="el" href="class_tree_map_1_1const__iterator.html#b9ece18c950afbfa6b0fdbfa4ff731d3">T</a> *&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map_1_1iterator.html#0435166b505820018f60233eb3f00662">operator-&gt;</a> () const </td></tr>

<tr><td class="memItemLeft" nowrap align="right" valign="top"><a class="el" href="class_tree_map_1_1iterator.html">iterator</a> &amp;&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map_1_1iterator.html#879fb570af328b721ed45fe254b0a582">operator++</a> ()</td></tr>

<tr><td class="memItemLeft" nowrap align="right" valign="top"><a class="el" href="class_tree_map_1_1iterator.html">iterator</a>&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map_1_1iterator.html#5d4681e027a07e3fb51ab21bef0dcc3d">operator++</a> (int)</td></tr>

<tr><td class="memItemLeft" nowrap align="right" valign="top"><a class="el" href="class_tree_map_1_1iterator.html">iterator</a> &amp;&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map_1_1iterator.html#08e169f7d9d8a763281a98d478c20a02">operator--</a> ()</td></tr>

<tr><td class="memItemLeft" nowrap align="right" valign="top"><a class="el" href="class_tree_map_1_1iterator.html">iterator</a>&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map_1_1iterator.html#12332c0f3ca9f1be40bf725d24d260ef">operator--</a> (int)</td></tr>

<tr><td class="memItemLeft" nowrap align="right" valign="top">bool&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map_1_1const__iterator.html#af10f269139a928a53584bc453003226">operator==</a> (const <a class="el" href="class_tree_map_1_1const__iterator.html">const_iterator</a> &amp;a) const </td></tr>

<tr><td class="memItemLeft" nowrap align="right" valign="top">bool&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map_1_1const__iterator.html#1afff81678307f558fa6ed1eadd24c40">operator!=</a> (const <a class="el" href="class_tree_map_1_1const__iterator.html">const_iterator</a> &amp;a) const </td></tr>

<tr><td colspan="2"><br><h2>Protected Attributes</h2></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top"><a class="el" href="struct_tree_node.html">Node</a> *&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map_1_1const__iterator.html#36c4536996ca5615dcf9911f068786dc">node</a></td></tr>

<tr><td class="mdescLeft">&nbsp;</td><td class="mdescRight">Points to the tree element.  <a href="#36c4536996ca5615dcf9911f068786dc"></a><br></td></tr>
<tr><td colspan="2"><br><h2>Private Member Functions</h2></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top">&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map_1_1iterator.html#4869ea6e94137dd3c8ead09023ab2a3f">iterator</a> (<a class="el" href="struct_tree_node.html">Node</a> *x)</td></tr>

<tr><td colspan="2"><br><h2>Friends</h2></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top">class&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map_1_1iterator.html#ec21601f0dade4123a4f02c3ab309706">TreeMap</a></td></tr>

</table>
<hr><a name="_details"></a><h2>Detailed Description</h2>
An iterator. 
<p>

<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00145">145</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.<hr><h2>Member Typedef Documentation</h2>
<a class="anchor" name="b9ece18c950afbfa6b0fdbfa4ff731d3"></a><!-- doxytag: member="TreeMap::iterator::T" ref="b9ece18c950afbfa6b0fdbfa4ff731d3" args="" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">typedef std::pair&lt;<a class="el" href="class_tree_map.html#897356954c2cd3d41b221e3f24f99bba">Key</a>, <a class="el" href="class_tree_map.html#5988c20a047cfe063999787584b0aca7">Val</a>&gt; <a class="el" href="class_tree_map_1_1const__iterator.html#b9ece18c950afbfa6b0fdbfa4ff731d3">TreeMap::const_iterator::T</a><code> [inherited]</code>          </td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>

<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00102">102</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.    </td>
  </tr>
</table>
<hr><h2>Constructor &amp; Destructor Documentation</h2>
<a class="anchor" name="4869ea6e94137dd3c8ead09023ab2a3f"></a><!-- doxytag: member="TreeMap::iterator::iterator" ref="4869ea6e94137dd3c8ead09023ab2a3f" args="(Node *x)" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">TreeMap::iterator::iterator           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="md" nowrap valign="top"><a class="el" href="struct_tree_node.html">Node</a> *&nbsp;</td>
          <td class="mdname1" valign="top" nowrap> <em>x</em>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap><code> [inline, private]</code></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>

<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00147">147</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.    </td>
  </tr>
</table>
<a class="anchor" name="c49f9eff2ae38470827eedc5b90f1eb1"></a><!-- doxytag: member="TreeMap::iterator::iterator" ref="c49f9eff2ae38470827eedc5b90f1eb1" args="()" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">TreeMap::iterator::iterator           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="mdname1" valign="top" nowrap>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap><code> [inline]</code></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>

<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00151">151</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.    </td>
  </tr>
</table>
<a class="anchor" name="f0f6d6b5b544eb701ae3d015e6133e1e"></a><!-- doxytag: member="TreeMap::iterator::iterator" ref="f0f6d6b5b544eb701ae3d015e6133e1e" args="(const const_iterator &amp;a)" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">TreeMap::iterator::iterator           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="md" nowrap valign="top">const <a class="el" href="class_tree_map_1_1const__iterator.html">const_iterator</a> &amp;&nbsp;</td>
          <td class="mdname1" valign="top" nowrap> <em>a</em>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap><code> [inline]</code></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>

<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00152">152</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.    </td>
  </tr>
</table>
<a class="anchor" name="5c297ca07cf2a75a9b0227b654c196d9"></a><!-- doxytag: member="TreeMap::iterator::iterator" ref="5c297ca07cf2a75a9b0227b654c196d9" args="(const iterator &amp;a)" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">TreeMap::iterator::iterator           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="md" nowrap valign="top">const <a class="el" href="class_tree_map_1_1iterator.html">iterator</a> &amp;&nbsp;</td>
          <td class="mdname1" valign="top" nowrap> <em>a</em>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap><code> [inline]</code></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>

<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00153">153</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.
<p>
References <a class="el" href="_tree_map_8h-source.html#l00106">TreeMap::const_iterator::node</a>.    </td>
  </tr>
</table>
<hr><h2>Member Function Documentation</h2>
<a class="anchor" name="f7a39cedb9cf2cea096b6e77b4794aa2"></a><!-- doxytag: member="TreeMap::iterator::operator *" ref="f7a39cedb9cf2cea096b6e77b4794aa2" args="() const " --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top"><a class="el" href="class_tree_map_1_1const__iterator.html#b9ece18c950afbfa6b0fdbfa4ff731d3">T</a>&amp; TreeMap::iterator::operator *           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="mdname1" valign="top" nowrap>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap> const<code> [inline]</code></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>

<p>
Reimplemented from <a class="el" href="class_tree_map_1_1const__iterator.html#f7a39cedb9cf2cea096b6e77b4794aa2">TreeMap::const_iterator</a>.
<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00155">155</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.
<p>
References <a class="el" href="_tree_map_8h-source.html#l00068">TreeNode::data</a>, and <a class="el" href="_tree_map_8h-source.html#l00106">TreeMap::const_iterator::node</a>.    </td>
  </tr>
</table>
<a class="anchor" name="1afff81678307f558fa6ed1eadd24c40"></a><!-- doxytag: member="TreeMap::iterator::operator!=" ref="1afff81678307f558fa6ed1eadd24c40" args="(const const_iterator &amp;a) const " --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">bool TreeMap::const_iterator::operator!=           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="md" nowrap valign="top">const <a class="el" href="class_tree_map_1_1const__iterator.html">const_iterator</a> &amp;&nbsp;</td>
          <td class="mdname1" valign="top" nowrap> <em>a</em>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap> const<code> [inline, inherited]</code></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>

<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00138">138</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.
<p>
References <a class="el" href="_tree_map_8h-source.html#l00106">TreeMap::const_iterator::node</a>.    </td>
  </tr>
</table>
<a class="anchor" name="5d4681e027a07e3fb51ab21bef0dcc3d"></a><!-- doxytag: member="TreeMap::iterator::operator++" ref="5d4681e027a07e3fb51ab21bef0dcc3d" args="(int)" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top"><a class="el" href="class_tree_map_1_1iterator.html">iterator</a> TreeMap::iterator::operator++           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="md" nowrap valign="top">int&nbsp;</td>
          <td class="mdname1" valign="top" nowrap>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap><code> [inline]</code></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>
<dl compact><dt><b><a class="el" href="todo.html#_todo000016">Todo:</a></b></dt><dd>Implement this</dd></dl>

<p>
Reimplemented from <a class="el" href="class_tree_map_1_1const__iterator.html#5d4681e027a07e3fb51ab21bef0dcc3d">TreeMap::const_iterator</a>.
<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00170">170</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.    </td>
  </tr>
</table>
<a class="anchor" name="879fb570af328b721ed45fe254b0a582"></a><!-- doxytag: member="TreeMap::iterator::operator++" ref="879fb570af328b721ed45fe254b0a582" args="()" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top"><a class="el" href="class_tree_map_1_1iterator.html">iterator</a>&amp; TreeMap::iterator::operator++           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="mdname1" valign="top" nowrap>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap><code> [inline]</code></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>
<dl compact><dt><b><a class="el" href="todo.html#_todo000015">Todo:</a></b></dt><dd>Implement this</dd></dl>

<p>
Reimplemented from <a class="el" href="class_tree_map_1_1const__iterator.html#879fb570af328b721ed45fe254b0a582">TreeMap::const_iterator</a>.
<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00164">164</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.    </td>
  </tr>
</table>
<a class="anchor" name="12332c0f3ca9f1be40bf725d24d260ef"></a><!-- doxytag: member="TreeMap::iterator::operator--" ref="12332c0f3ca9f1be40bf725d24d260ef" args="(int)" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top"><a class="el" href="class_tree_map_1_1iterator.html">iterator</a> TreeMap::iterator::operator--           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="md" nowrap valign="top">int&nbsp;</td>
          <td class="mdname1" valign="top" nowrap>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap><code> [inline]</code></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>
<dl compact><dt><b><a class="el" href="todo.html#_todo000018">Todo:</a></b></dt><dd>Implement this</dd></dl>

<p>
Reimplemented from <a class="el" href="class_tree_map_1_1const__iterator.html#12332c0f3ca9f1be40bf725d24d260ef">TreeMap::const_iterator</a>.
<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00183">183</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.    </td>
  </tr>
</table>
<a class="anchor" name="08e169f7d9d8a763281a98d478c20a02"></a><!-- doxytag: member="TreeMap::iterator::operator--" ref="08e169f7d9d8a763281a98d478c20a02" args="()" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top"><a class="el" href="class_tree_map_1_1iterator.html">iterator</a>&amp; TreeMap::iterator::operator--           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="mdname1" valign="top" nowrap>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap><code> [inline]</code></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>
<dl compact><dt><b><a class="el" href="todo.html#_todo000017">Todo:</a></b></dt><dd>Implement this</dd></dl>

<p>
Reimplemented from <a class="el" href="class_tree_map_1_1const__iterator.html#08e169f7d9d8a763281a98d478c20a02">TreeMap::const_iterator</a>.
<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00177">177</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.    </td>
  </tr>
</table>
<a class="anchor" name="0435166b505820018f60233eb3f00662"></a><!-- doxytag: member="TreeMap::iterator::operator-&gt;" ref="0435166b505820018f60233eb3f00662" args="() const " --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top"><a class="el" href="class_tree_map_1_1const__iterator.html#b9ece18c950afbfa6b0fdbfa4ff731d3">T</a>* TreeMap::iterator::operator-&gt;           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="mdname1" valign="top" nowrap>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap> const<code> [inline]</code></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>

<p>
Reimplemented from <a class="el" href="class_tree_map_1_1const__iterator.html#0435166b505820018f60233eb3f00662">TreeMap::const_iterator</a>.
<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00159">159</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.
<p>
References <a class="el" href="_tree_map_8h-source.html#l00068">TreeNode::data</a>, and <a class="el" href="_tree_map_8h-source.html#l00106">TreeMap::const_iterator::node</a>.    </td>
  </tr>
</table>
<a class="anchor" name="af10f269139a928a53584bc453003226"></a><!-- doxytag: member="TreeMap::iterator::operator==" ref="af10f269139a928a53584bc453003226" args="(const const_iterator &amp;a) const " --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">bool TreeMap::const_iterator::operator==           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="md" nowrap valign="top">const <a class="el" href="class_tree_map_1_1const__iterator.html">const_iterator</a> &amp;&nbsp;</td>
          <td class="mdname1" valign="top" nowrap> <em>a</em>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap> const<code> [inline, inherited]</code></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>

<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00133">133</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.
<p>
References <a class="el" href="_tree_map_8h-source.html#l00106">TreeMap::const_iterator::node</a>.    </td>
  </tr>
</table>
<hr><h2>Friends And Related Function Documentation</h2>
<a class="anchor" name="ec21601f0dade4123a4f02c3ab309706"></a><!-- doxytag: member="TreeMap::iterator::TreeMap" ref="ec21601f0dade4123a4f02c3ab309706" args="" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">friend class <a class="el" href="class_tree_map.html">TreeMap</a><code> [friend]</code>          </td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>

<p>
Reimplemented from <a class="el" href="class_tree_map_1_1const__iterator.html#ec21601f0dade4123a4f02c3ab309706">TreeMap::const_iterator</a>.
<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00148">148</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.    </td>
  </tr>
</table>
<hr><h2>Member Data Documentation</h2>
<a class="anchor" name="36c4536996ca5615dcf9911f068786dc"></a><!-- doxytag: member="TreeMap::iterator::node" ref="36c4536996ca5615dcf9911f068786dc" args="" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top"><a class="el" href="struct_tree_node.html">Node</a>* <a class="el" href="class_tree_map_1_1const__iterator.html#36c4536996ca5615dcf9911f068786dc">TreeMap::const_iterator::node</a><code> [protected, inherited]</code>          </td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>
Points to the tree element. 
<p>

<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00106">106</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.
<p>
Referenced by <a class="el" href="_tree_map_8h-source.html#l00153">iterator()</a>, <a class="el" href="_tree_map_8h-source.html#l00155">operator *()</a>, <a class="el" href="_tree_map_8h-source.html#l00114">TreeMap::const_iterator::operator *()</a>, <a class="el" href="_tree_map_8h-source.html#l00138">TreeMap::const_iterator::operator!=()</a>, <a class="el" href="_tree_map_8h-source.html#l00159">operator-&gt;()</a>, <a class="el" href="_tree_map_8h-source.html#l00119">TreeMap::const_iterator::operator-&gt;()</a>, and <a class="el" href="_tree_map_8h-source.html#l00133">TreeMap::const_iterator::operator==()</a>.    </td>
  </tr>
</table>
<hr>The documentation for this class was generated from the following file:<ul>
<li><a class="el" href="_tree_map_8h-source.html">TreeMap.h</a></ul>
<hr size="1"><address style="align: right;"><small>Generated on Fri Dec 2 01:03:51 2005 for AISDI Cwiczenie 4 by&nbsp;
<a href="http://www.doxygen.org/index.html">
<img src="doxygen.png" alt="doxygen" align="middle" border="0"></a> 1.4.5 </small></address>
</body>
</html>
b><a class="el" href="todo.html#_todo000016">Todo:</a></b></dt><dd>Implement this</dd></dl>

<p>
Reimplemented from <a class="el" href="class_tree_map_1_1const__iterator.html#5d4681e027a07e3fb51ab21bef0dcc3d">TreeMap::const_iterator</a>.
<p>
Definition at line <a class="el" href="_tree_map_8tree/info/class_tree_map_1_1iterator-members.html                                                   0100644 0003673 0000144 00000014321 11704031106 0023374 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html><head><meta http-equiv="Content-Type" content="text/html;charset=iso-8859-1">
<title>AISDI Cwiczenie 4: Member List</title>
<link href="doxygen.css" rel="stylesheet" type="text/css">
<link href="tabs.css" rel="stylesheet" type="text/css">
</head><body>
<!-- Generated by Doxygen 1.4.5 -->
<div class="tabs">
  <ul>
    <li><a href="index.html"><span>Main&nbsp;Page</span></a></li>
    <li id="current"><a href="annotated.html"><span>Classes</span></a></li>
    <li><a href="files.html"><span>Files</span></a></li>
    <li><a href="pages.html"><span>Related&nbsp;Pages</span></a></li>
  </ul></div>
<div class="tabs">
  <ul>
    <li><a href="annotated.html"><span>Class&nbsp;List</span></a></li>
    <li><a href="classes.html"><span>Alphabetical&nbsp;List</span></a></li>
    <li><a href="hierarchy.html"><span>Class&nbsp;Hierarchy</span></a></li>
    <li><a href="functions.html"><span>Class&nbsp;Members</span></a></li>
  </ul></div>
<h1>TreeMap::iterator Member List</h1>This is the complete list of members for <a class="el" href="class_tree_map_1_1iterator.html">TreeMap::iterator</a>, including all inherited members.<p><table>
  <tr class="memlist"><td><a class="el" href="class_tree_map_1_1const__iterator.html#27f123de1dda4c35c67d132f620c5b7a">const_iterator</a>(Node *x)</td><td><a class="el" href="class_tree_map_1_1const__iterator.html">TreeMap::const_iterator</a></td><td><code> [inline, protected]</code></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map_1_1const__iterator.html#645ef348f77c435481d85152ee348aa2">const_iterator</a>()</td><td><a class="el" href="class_tree_map_1_1const__iterator.html">TreeMap::const_iterator</a></td><td><code> [inline]</code></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map_1_1const__iterator.html#6e845f4990b76b6659a5e525ee7c917e">const_iterator</a>(const const_iterator &amp;a)</td><td><a class="el" href="class_tree_map_1_1const__iterator.html">TreeMap::const_iterator</a></td><td><code> [inline]</code></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map_1_1iterator.html#4869ea6e94137dd3c8ead09023ab2a3f">iterator</a>(Node *x)</td><td><a class="el" href="class_tree_map_1_1iterator.html">TreeMap::iterator</a></td><td><code> [inline, private]</code></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map_1_1iterator.html#c49f9eff2ae38470827eedc5b90f1eb1">iterator</a>()</td><td><a class="el" href="class_tree_map_1_1iterator.html">TreeMap::iterator</a></td><td><code> [inline]</code></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map_1_1iterator.html#f0f6d6b5b544eb701ae3d015e6133e1e">iterator</a>(const const_iterator &amp;a)</td><td><a class="el" href="class_tree_map_1_1iterator.html">TreeMap::iterator</a></td><td><code> [inline]</code></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map_1_1iterator.html#5c297ca07cf2a75a9b0227b654c196d9">iterator</a>(const iterator &amp;a)</td><td><a class="el" href="class_tree_map_1_1iterator.html">TreeMap::iterator</a></td><td><code> [inline]</code></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map_1_1const__iterator.html#36c4536996ca5615dcf9911f068786dc">node</a></td><td><a class="el" href="class_tree_map_1_1const__iterator.html">TreeMap::const_iterator</a></td><td><code> [protected]</code></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map_1_1iterator.html#f7a39cedb9cf2cea096b6e77b4794aa2">operator *</a>() const </td><td><a class="el" href="class_tree_map_1_1iterator.html">TreeMap::iterator</a></td><td><code> [inline]</code></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map_1_1const__iterator.html#1afff81678307f558fa6ed1eadd24c40">operator!=</a>(const const_iterator &amp;a) const </td><td><a class="el" href="class_tree_map_1_1const__iterator.html">TreeMap::const_iterator</a></td><td><code> [inline]</code></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map_1_1iterator.html#879fb570af328b721ed45fe254b0a582">operator++</a>()</td><td><a class="el" href="class_tree_map_1_1iterator.html">TreeMap::iterator</a></td><td><code> [inline]</code></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map_1_1iterator.html#5d4681e027a07e3fb51ab21bef0dcc3d">operator++</a>(int)</td><td><a class="el" href="class_tree_map_1_1iterator.html">TreeMap::iterator</a></td><td><code> [inline]</code></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map_1_1iterator.html#08e169f7d9d8a763281a98d478c20a02">operator--</a>()</td><td><a class="el" href="class_tree_map_1_1iterator.html">TreeMap::iterator</a></td><td><code> [inline]</code></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map_1_1iterator.html#12332c0f3ca9f1be40bf725d24d260ef">operator--</a>(int)</td><td><a class="el" href="class_tree_map_1_1iterator.html">TreeMap::iterator</a></td><td><code> [inline]</code></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map_1_1iterator.html#0435166b505820018f60233eb3f00662">operator-&gt;</a>() const </td><td><a class="el" href="class_tree_map_1_1iterator.html">TreeMap::iterator</a></td><td><code> [inline]</code></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map_1_1const__iterator.html#af10f269139a928a53584bc453003226">operator==</a>(const const_iterator &amp;a) const </td><td><a class="el" href="class_tree_map_1_1const__iterator.html">TreeMap::const_iterator</a></td><td><code> [inline]</code></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map_1_1const__iterator.html#b9ece18c950afbfa6b0fdbfa4ff731d3">T</a> typedef</td><td><a class="el" href="class_tree_map_1_1const__iterator.html">TreeMap::const_iterator</a></td><td></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map_1_1iterator.html#ec21601f0dade4123a4f02c3ab309706">TreeMap</a> class</td><td><a class="el" href="class_tree_map_1_1iterator.html">TreeMap::iterator</a></td><td><code> [friend]</code></td></tr>
</table><hr size="1"><address style="align: right;"><small>Generated on Fri Dec 2 01:03:51 2005 for AISDI Cwiczenie 4 by&nbsp;
<a href="http://www.doxygen.org/index.html">
<img src="doxygen.png" alt="doxygen" align="middle" border="0"></a> 1.4.5 </small></address>
</body>
</html>
                                                                                                                                                                                                                                                                                                               tree/info/class_tree_map_detail.html                                                                0100644 0003673 0000144 00000013033 11704031106 0021053 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html><head><meta http-equiv="Content-Type" content="text/html;charset=iso-8859-1">
<title>AISDI Cwiczenie 4: TreeMapDetail Class Reference</title>
<link href="doxygen.css" rel="stylesheet" type="text/css">
<link href="tabs.css" rel="stylesheet" type="text/css">
</head><body>
<!-- Generated by Doxygen 1.4.5 -->
<div class="tabs">
  <ul>
    <li><a href="index.html"><span>Main&nbsp;Page</span></a></li>
    <li id="current"><a href="annotated.html"><span>Classes</span></a></li>
    <li><a href="files.html"><span>Files</span></a></li>
    <li><a href="pages.html"><span>Related&nbsp;Pages</span></a></li>
  </ul></div>
<div class="tabs">
  <ul>
    <li><a href="annotated.html"><span>Class&nbsp;List</span></a></li>
    <li><a href="classes.html"><span>Alphabetical&nbsp;List</span></a></li>
    <li><a href="hierarchy.html"><span>Class&nbsp;Hierarchy</span></a></li>
    <li><a href="functions.html"><span>Class&nbsp;Members</span></a></li>
  </ul></div>
<h1>TreeMapDetail Class Reference</h1><!-- doxytag: class="TreeMapDetail" -->A helper class.  
<a href="#_details">More...</a>
<p>
<a href="class_tree_map_detail-members.html">List of all members.</a><table border="0" cellpadding="0" cellspacing="0">
<tr><td></td></tr>
<tr><td colspan="2"><br><h2>Static Protected Member Functions</h2></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top">static void&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map_detail.html#5637e02d8d73d541ed8c19d448ecac17">erase</a> (<a class="el" href="class_tree_map.html">TreeMap</a> *tm, const <a class="el" href="class_tree_map.html#897356954c2cd3d41b221e3f24f99bba">TreeMap::Key</a> &amp;k)</td></tr>

<tr><td class="mdescLeft">&nbsp;</td><td class="mdescRight">Stupid example of a method that modifies a protected field in the <a class="el" href="class_tree_map.html">TreeMap</a> class.  <a href="#5637e02d8d73d541ed8c19d448ecac17"></a><br></td></tr>
<tr><td colspan="2"><br><h2>Friends</h2></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top">class&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_tree_map_detail.html#ec21601f0dade4123a4f02c3ab309706">TreeMap</a></td></tr>

</table>
<hr><a name="_details"></a><h2>Detailed Description</h2>
A helper class. 
<p>

<p>
Definition at line <a class="el" href="asd_8cc-source.html#l00042">42</a> of file <a class="el" href="asd_8cc-source.html">asd.cc</a>.<hr><h2>Member Function Documentation</h2>
<a class="anchor" name="5637e02d8d73d541ed8c19d448ecac17"></a><!-- doxytag: member="TreeMapDetail::erase" ref="5637e02d8d73d541ed8c19d448ecac17" args="(TreeMap *tm, const TreeMap::Key &amp;k)" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">static void TreeMapDetail::erase           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="md" nowrap valign="top"><a class="el" href="class_tree_map.html">TreeMap</a> *&nbsp;</td>
          <td class="mdname" nowrap> <em>tm</em>, </td>
        </tr>
        <tr>
          <td class="md" nowrap align="right"></td>
          <td class="md"></td>
          <td class="md" nowrap>const <a class="el" href="class_tree_map.html#897356954c2cd3d41b221e3f24f99bba">TreeMap::Key</a> &amp;&nbsp;</td>
          <td class="mdname" nowrap> <em>k</em></td>
        </tr>
        <tr>
          <td class="md"></td>
          <td class="md">)&nbsp;</td>
          <td class="md" colspan="2"><code> [inline, static, protected]</code></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>
Stupid example of a method that modifies a protected field in the <a class="el" href="class_tree_map.html">TreeMap</a> class. 
<p>
Feel free to remove this method or add new ones here. 
<p>
Definition at line <a class="el" href="asd_8cc-source.html#l00050">50</a> of file <a class="el" href="asd_8cc-source.html">asd.cc</a>.
<p>
References <a class="el" href="_tree_map_8h-source.html#l00086">TreeMap::root</a>.
<p>
Referenced by <a class="el" href="asd_8cc-source.html#l00184">TreeMap::clear()</a>.    </td>
  </tr>
</table>
<hr><h2>Friends And Related Function Documentation</h2>
<a class="anchor" name="ec21601f0dade4123a4f02c3ab309706"></a><!-- doxytag: member="TreeMapDetail::TreeMap" ref="ec21601f0dade4123a4f02c3ab309706" args="" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">friend class <a class="el" href="class_tree_map.html">TreeMap</a><code> [friend]</code>          </td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>

<p>
Definition at line <a class="el" href="asd_8cc-source.html#l00045">45</a> of file <a class="el" href="asd_8cc-source.html">asd.cc</a>.    </td>
  </tr>
</table>
<hr>The documentation for this class was generated from the following file:<ul>
<li><a class="el" href="asd_8cc-source.html">asd.cc</a></ul>
<hr size="1"><address style="align: right;"><small>Generated on Fri Dec 2 01:03:51 2005 for AISDI Cwiczenie 4 by&nbsp;
<a href="http://www.doxygen.org/index.html">
<img src="doxygen.png" alt="doxygen" align="middle" border="0"></a> 1.4.5 </small></address>
</body>
</html>
d73d541ed8c19d448ecac17"></a><!-- doxytag: member="TreeMapDetail::erase" ref="5637e02d8d73d541ed8c19d448ecac17" args="(TreeMap *tm, const TreeMap::Key &amp;k)" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">static void TreeMapDetail::erase           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td clatree/info/class_tree_map_detail-members.html                                                        0100644 0003673 0000144 00000003722 11704031106 0022507 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html><head><meta http-equiv="Content-Type" content="text/html;charset=iso-8859-1">
<title>AISDI Cwiczenie 4: Member List</title>
<link href="doxygen.css" rel="stylesheet" type="text/css">
<link href="tabs.css" rel="stylesheet" type="text/css">
</head><body>
<!-- Generated by Doxygen 1.4.5 -->
<div class="tabs">
  <ul>
    <li><a href="index.html"><span>Main&nbsp;Page</span></a></li>
    <li id="current"><a href="annotated.html"><span>Classes</span></a></li>
    <li><a href="files.html"><span>Files</span></a></li>
    <li><a href="pages.html"><span>Related&nbsp;Pages</span></a></li>
  </ul></div>
<div class="tabs">
  <ul>
    <li><a href="annotated.html"><span>Class&nbsp;List</span></a></li>
    <li><a href="classes.html"><span>Alphabetical&nbsp;List</span></a></li>
    <li><a href="hierarchy.html"><span>Class&nbsp;Hierarchy</span></a></li>
    <li><a href="functions.html"><span>Class&nbsp;Members</span></a></li>
  </ul></div>
<h1>TreeMapDetail Member List</h1>This is the complete list of members for <a class="el" href="class_tree_map_detail.html">TreeMapDetail</a>, including all inherited members.<p><table>
  <tr class="memlist"><td><a class="el" href="class_tree_map_detail.html#5637e02d8d73d541ed8c19d448ecac17">erase</a>(TreeMap *tm, const TreeMap::Key &amp;k)</td><td><a class="el" href="class_tree_map_detail.html">TreeMapDetail</a></td><td><code> [inline, protected, static]</code></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map_detail.html#ec21601f0dade4123a4f02c3ab309706">TreeMap</a> class</td><td><a class="el" href="class_tree_map_detail.html">TreeMapDetail</a></td><td><code> [friend]</code></td></tr>
</table><hr size="1"><address style="align: right;"><small>Generated on Fri Dec 2 01:03:51 2005 for AISDI Cwiczenie 4 by&nbsp;
<a href="http://www.doxygen.org/index.html">
<img src="doxygen.png" alt="doxygen" align="middle" border="0"></a> 1.4.5 </small></address>
</body>
</html>
                                              tree/info/class_tree_map-members.html                                                               0100644 0003673 0000144 00000017572 11704031106 0021175 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html><head><meta http-equiv="Content-Type" content="text/html;charset=iso-8859-1">
<title>AISDI Cwiczenie 4: Member List</title>
<link href="doxygen.css" rel="stylesheet" type="text/css">
<link href="tabs.css" rel="stylesheet" type="text/css">
</head><body>
<!-- Generated by Doxygen 1.4.5 -->
<div class="tabs">
  <ul>
    <li><a href="index.html"><span>Main&nbsp;Page</span></a></li>
    <li id="current"><a href="annotated.html"><span>Classes</span></a></li>
    <li><a href="files.html"><span>Files</span></a></li>
    <li><a href="pages.html"><span>Related&nbsp;Pages</span></a></li>
  </ul></div>
<div class="tabs">
  <ul>
    <li><a href="annotated.html"><span>Class&nbsp;List</span></a></li>
    <li><a href="classes.html"><span>Alphabetical&nbsp;List</span></a></li>
    <li><a href="hierarchy.html"><span>Class&nbsp;Hierarchy</span></a></li>
    <li><a href="functions.html"><span>Class&nbsp;Members</span></a></li>
  </ul></div>
<h1>TreeMap Member List</h1>This is the complete list of members for <a class="el" href="class_tree_map.html">TreeMap</a>, including all inherited members.<p><table>
  <tr class="memlist"><td><a class="el" href="class_tree_map.html#4b1a01a7db76e79c6194363c78d33615">begin</a>()</td><td><a class="el" href="class_tree_map.html">TreeMap</a></td><td><code> [inline]</code></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map.html#6c34e3a8894af3a2160a3c0baa7e6fad">begin</a>() const </td><td><a class="el" href="class_tree_map.html">TreeMap</a></td><td><code> [inline]</code></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map.html#3616b8000a015689fed4b46c19c06ea2">clear</a>()</td><td><a class="el" href="class_tree_map.html">TreeMap</a></td><td></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map.html#1d79deabb6ad2a93ef5358356055ee3b">count</a>(const Key &amp;_Key) const </td><td><a class="el" href="class_tree_map.html">TreeMap</a></td><td></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map.html#951da6b7179a4f697cc89d36acf74e52">detail</a></td><td><a class="el" href="class_tree_map.html">TreeMap</a></td><td><code> [protected]</code></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map.html#ea1ddff44da5abff286d8b01793eb7ee">empty</a>() const </td><td><a class="el" href="class_tree_map.html">TreeMap</a></td><td></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map.html#f34c4b013e5d012ab5f1bfef486d630f">end</a>()</td><td><a class="el" href="class_tree_map.html">TreeMap</a></td><td><code> [inline]</code></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map.html#37d6974af8ee6af64f7b4f71330853cb">end</a>() const </td><td><a class="el" href="class_tree_map.html">TreeMap</a></td><td><code> [inline]</code></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map.html#99d178e178a2d0a71c1f5698c5879dcf">erase</a>(iterator i)</td><td><a class="el" href="class_tree_map.html">TreeMap</a></td><td></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map.html#4c750f4eb7c25898376b2945bceb60a3">erase</a>(iterator first, iterator last)</td><td><a class="el" href="class_tree_map.html">TreeMap</a></td><td></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map.html#f768666a08bb3f9bf6d59af014dc8a79">erase</a>(const Key &amp;key)</td><td><a class="el" href="class_tree_map.html">TreeMap</a></td><td></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map.html#da5bc54e6c1da79235e9160ee021b9f5">find</a>(const Key &amp;k)</td><td><a class="el" href="class_tree_map.html">TreeMap</a></td><td></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map.html#732153e7bc56dacafa2411864b548219">find</a>(const Key &amp;k) const </td><td><a class="el" href="class_tree_map.html">TreeMap</a></td><td></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map.html#68dd925067e3812184dcedea9211ac4b">info_eq</a>(const TreeMap &amp;another) const </td><td><a class="el" href="class_tree_map.html">TreeMap</a></td><td></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map.html#94500a970d082e87b838a94fed333521">insert</a>(const std::pair&lt; Key, Val &gt; &amp;entry)</td><td><a class="el" href="class_tree_map.html">TreeMap</a></td><td></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map.html#897356954c2cd3d41b221e3f24f99bba">Key</a> typedef</td><td><a class="el" href="class_tree_map.html">TreeMap</a></td><td></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map.html#6c3a6944a808a7c0bbb6788dbec54a9f">Node</a> typedef</td><td><a class="el" href="class_tree_map.html">TreeMap</a></td><td><code> [protected]</code></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map.html#48753429045577c544d7b1765997223e">operator=</a>(const TreeMap &amp;)</td><td><a class="el" href="class_tree_map.html">TreeMap</a></td><td></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map.html#18b0ae91b08ac71b923d1c9dd85f7876">operator==</a>(const TreeMap &amp;a) const </td><td><a class="el" href="class_tree_map.html">TreeMap</a></td><td><code> [inline]</code></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map.html#ce20a84b60c9bcce43c37cb75d29fe50">operator[]</a>(const Key &amp;k)</td><td><a class="el" href="class_tree_map.html">TreeMap</a></td><td></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map.html#44c29edb103a2872f519ad0c9a0fdaaa">P</a> typedef</td><td><a class="el" href="class_tree_map.html">TreeMap</a></td><td></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map.html#63a9f0ea7bb98050796b649e85481845">root</a></td><td><a class="el" href="class_tree_map.html">TreeMap</a></td><td><code> [protected]</code></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map.html#5a9421972c178b3c37b99f953470c6f6">size</a>() const </td><td><a class="el" href="class_tree_map.html">TreeMap</a></td><td></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map.html#3eb1f9410d79d28273ccc045cf8e6478">size_type</a> typedef</td><td><a class="el" href="class_tree_map.html">TreeMap</a></td><td></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map.html#e62bc2a78904e459d5f302a5ff48769a">struct_eq</a>(const TreeMap &amp;another) const </td><td><a class="el" href="class_tree_map.html">TreeMap</a></td><td></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map.html#8c50809795fa8b8f2a3cd019e2acae62">TreeMap</a>()</td><td><a class="el" href="class_tree_map.html">TreeMap</a></td><td></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map.html#36057872ebdcdb89755ff678ad8a5179">TreeMap</a>(const TreeMap &amp;)</td><td><a class="el" href="class_tree_map.html">TreeMap</a></td><td></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map.html#359f4c98a692d55e998de2a0ccbfe3c9">TreeMapDetail</a> class</td><td><a class="el" href="class_tree_map.html">TreeMap</a></td><td><code> [friend]</code></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map.html#9b42b72518de2845832b80e44424fab3">unsafe_insert</a>(const std::pair&lt; Key, Val &gt; &amp;entry)</td><td><a class="el" href="class_tree_map.html">TreeMap</a></td><td></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map.html#5988c20a047cfe063999787584b0aca7">Val</a> typedef</td><td><a class="el" href="class_tree_map.html">TreeMap</a></td><td></td></tr>
  <tr class="memlist"><td><a class="el" href="class_tree_map.html#3d396c0d29bbefef0723fb19a95dd386">~TreeMap</a>()</td><td><a class="el" href="class_tree_map.html">TreeMap</a></td><td></td></tr>
</table><hr size="1"><address style="align: right;"><small>Generated on Fri Dec 2 01:03:51 2005 for AISDI Cwiczenie 4 by&nbsp;
<a href="http://www.doxygen.org/index.html">
<img src="doxygen.png" alt="doxygen" align="middle" border="0"></a> 1.4.5 </small></address>
</body>
</html>
class_tree_map.html#68dd925067e3812184dcedea9211ac4b">info_eq</a>(const TreeMap &amp;another) const </td><td><a class="el" href="classtree/info/classbasic__wfstream.html                                                                 0100644 0003673 0000144 00000003444 11704031106 0020733 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html><head><meta http-equiv="Content-Type" content="text/html;charset=iso-8859-1">
<title>AISDI Cwiczenie 4: basic_wfstream Class Reference</title>
<link href="doxygen.css" rel="stylesheet" type="text/css">
<link href="tabs.css" rel="stylesheet" type="text/css">
</head><body>
<!-- Generated by Doxygen 1.4.5 -->
<div class="tabs">
  <ul>
    <li><a href="index.html"><span>Main&nbsp;Page</span></a></li>
    <li id="current"><a href="annotated.html"><span>Classes</span></a></li>
    <li><a href="files.html"><span>Files</span></a></li>
    <li><a href="pages.html"><span>Related&nbsp;Pages</span></a></li>
  </ul></div>
<div class="tabs">
  <ul>
    <li><a href="annotated.html"><span>Class&nbsp;List</span></a></li>
    <li><a href="classes.html"><span>Alphabetical&nbsp;List</span></a></li>
    <li><a href="hierarchy.html"><span>Class&nbsp;Hierarchy</span></a></li>
    <li><a href="functions.html"><span>Class&nbsp;Members</span></a></li>
  </ul></div>
<h1>basic_wfstream Class Reference</h1><!-- doxytag: class="basic_wfstream" -->Inherited by std::wfstream.
<p>
Inheritance diagram for basic_wfstream:<p><center><img src="classbasic__wfstream__inherit__graph.png" border="0" usemap="#basic__wfstream__inherit__map" alt="Inheritance graph"></center>
<center><font size="2">[<a href="graph_legend.html">legend</a>]</font></center><table border="0" cellpadding="0" cellspacing="0">
<tr><td></td></tr>
</table>
<hr>The documentation for this class was generated from the following file:<hr size="1"><address style="align: right;"><small>Generated on Fri Dec 2 01:03:51 2005 for AISDI Cwiczenie 4 by&nbsp;
<a href="http://www.doxygen.org/index.html">
<img src="doxygen.png" alt="doxygen" align="middle" border="0"></a> 1.4.5 </small></address>
</body>
</html>
                                                                                                                                                                                                                            tree/info/classes.html                                                                              0100644 0003673 0000144 00000006301 11704031106 0016205 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html><head><meta http-equiv="Content-Type" content="text/html;charset=iso-8859-1">
<title>AISDI Cwiczenie 4: Alphabetical List</title>
<link href="doxygen.css" rel="stylesheet" type="text/css">
<link href="tabs.css" rel="stylesheet" type="text/css">
</head><body>
<!-- Generated by Doxygen 1.4.5 -->
<div class="tabs">
  <ul>
    <li><a href="index.html"><span>Main&nbsp;Page</span></a></li>
    <li id="current"><a href="annotated.html"><span>Classes</span></a></li>
    <li><a href="files.html"><span>Files</span></a></li>
    <li><a href="pages.html"><span>Related&nbsp;Pages</span></a></li>
  </ul></div>
<div class="tabs">
  <ul>
    <li><a href="annotated.html"><span>Class&nbsp;List</span></a></li>
    <li id="current"><a href="classes.html"><span>Alphabetical&nbsp;List</span></a></li>
    <li><a href="hierarchy.html"><span>Class&nbsp;Hierarchy</span></a></li>
    <li><a href="functions.html"><span>Class&nbsp;Members</span></a></li>
  </ul></div>
<h1>AISDI Cwiczenie 4 Class Index</h1><p><div class="qindex"><a class="qindex" href="#letter_B">B</a>&nbsp;|&nbsp;<a class="qindex" href="#letter_C">C</a>&nbsp;|&nbsp;<a class="qindex" href="#letter_I">I</a>&nbsp;|&nbsp;<a class="qindex" href="#letter_T">T</a></div><p>
<table align="center" width="95%" border="0" cellspacing="0" cellpadding="0">
<tr><td><a name="letter_B"></a><table border="0" cellspacing="0" cellpadding="0"><tr><td><div class="ah">&nbsp;&nbsp;B&nbsp;&nbsp;</div></td></tr></table>
</td><td><a class="el" href="class_c_count.html">CCount</a>&nbsp;&nbsp;&nbsp;</td><td><a name="letter_T"></a><table border="0" cellspacing="0" cellpadding="0"><tr><td><div class="ah">&nbsp;&nbsp;T&nbsp;&nbsp;</div></td></tr></table>
</td><td><a class="el" href="class_tree_map_1_1const__iterator.html">TreeMap::const_iterator</a>&nbsp;&nbsp;&nbsp;</td><td><a class="el" href="class_tree_map_detail.html">TreeMapDetail</a>&nbsp;&nbsp;&nbsp;</td></tr><tr><td><a class="el" href="classbasic__wfstream.html">basic_wfstream</a>&nbsp;&nbsp;&nbsp;</td><td><a name="letter_I"></a><table border="0" cellspacing="0" cellpadding="0"><tr><td><div class="ah">&nbsp;&nbsp;I&nbsp;&nbsp;</div></td></tr></table>
</td><td><a class="el" href="class_tree_map.html">TreeMap</a>&nbsp;&nbsp;&nbsp;</td><td><a class="el" href="class_tree_map_1_1iterator.html">TreeMap::iterator</a>&nbsp;&nbsp;&nbsp;</td><td><a class="el" href="struct_tree_node.html">TreeNode</a>&nbsp;&nbsp;&nbsp;</td></tr><tr><td><a name="letter_C"></a><table border="0" cellspacing="0" cellpadding="0"><tr><td><div class="ah">&nbsp;&nbsp;C&nbsp;&nbsp;</div></td></tr></table>
</td><td><a class="el" href="classstd_1_1iterator.html">iterator</a> (std)&nbsp;&nbsp;&nbsp;</td></tr></table><p><div class="qindex"><a class="qindex" href="#letter_B">B</a>&nbsp;|&nbsp;<a class="qindex" href="#letter_C">C</a>&nbsp;|&nbsp;<a class="qindex" href="#letter_I">I</a>&nbsp;|&nbsp;<a class="qindex" href="#letter_T">T</a></div><p>
<hr size="1"><address style="align: right;"><small>Generated on Fri Dec 2 01:03:51 2005 for AISDI Cwiczenie 4 by&nbsp;
<a href="http://www.doxygen.org/index.html">
<img src="doxygen.png" alt="doxygen" align="middle" border="0"></a> 1.4.5 </small></address>
</body>
</html>
title>
<link href="doxygen.css" rel="stylesheet" type="text/css">
<link href="tabs.css" rel="stylesheet" type="text/css">
</head><body>
<!-- Generated by Doxygen 1.4.5 -->
<div class="tabs">
  <ul>
    <li><a href="index.html"><span>Main&nbsp;Page</span></a></li>
    <li id="current"><a href="annotated.html"><span>Clatree/info/files.html                                                                                0100644 0003673 0000144 00000003657 11704031106 0015665 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html><head><meta http-equiv="Content-Type" content="text/html;charset=iso-8859-1">
<title>AISDI Cwiczenie 4: File Index</title>
<link href="doxygen.css" rel="stylesheet" type="text/css">
<link href="tabs.css" rel="stylesheet" type="text/css">
</head><body>
<!-- Generated by Doxygen 1.4.5 -->
<div class="tabs">
  <ul>
    <li><a href="index.html"><span>Main&nbsp;Page</span></a></li>
    <li><a href="annotated.html"><span>Classes</span></a></li>
    <li id="current"><a href="files.html"><span>Files</span></a></li>
    <li><a href="pages.html"><span>Related&nbsp;Pages</span></a></li>
  </ul></div>
<div class="tabs">
  <ul>
    <li id="current"><a href="files.html"><span>File&nbsp;List</span></a></li>
    <li><a href="globals.html"><span>File&nbsp;Members</span></a></li>
  </ul></div>
<h1>AISDI Cwiczenie 4 File List</h1>Here is a list of all files with brief descriptions:<table>
  <tr><td class="indexkey"><a class="el" href="asd_8cc.html">asd.cc</a> <a href="asd_8cc-source.html">[code]</a></td><td class="indexvalue">Plik do modyfikacji w w ramach cwiczenia 4 z AISDI </td></tr>
  <tr><td class="indexkey"><a class="el" href="main_8cc.html">main.cc</a> <a href="main_8cc-source.html">[code]</a></td><td class="indexvalue">Plik z funkcja <a class="el" href="main_8cc.html#ea83b916b3f52eec32ae6d54d59b4453">main()</a> do cwiczenia 4 na laboratoriach z AISDI </td></tr>
  <tr><td class="indexkey"><a class="el" href="_tree_map_8h.html">TreeMap.h</a> <a href="_tree_map_8h-source.html">[code]</a></td><td class="indexvalue">Zawiera deklaracje klasy <a class="el" href="class_tree_map.html">TreeMap</a> </td></tr>
</table>
<hr size="1"><address style="align: right;"><small>Generated on Fri Dec 2 01:03:51 2005 for AISDI Cwiczenie 4 by&nbsp;
<a href="http://www.doxygen.org/index.html">
<img src="doxygen.png" alt="doxygen" align="middle" border="0"></a> 1.4.5 </small></address>
</body>
</html>
                                                                                 tree/info/classstd_1_1iterator.html                                                                 0100644 0003673 0000144 00000004202 11704031106 0020600 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html><head><meta http-equiv="Content-Type" content="text/html;charset=iso-8859-1">
<title>AISDI Cwiczenie 4: iterator Class Reference</title>
<link href="doxygen.css" rel="stylesheet" type="text/css">
<link href="tabs.css" rel="stylesheet" type="text/css">
</head><body>
<!-- Generated by Doxygen 1.4.5 -->
<div class="tabs">
  <ul>
    <li><a href="index.html"><span>Main&nbsp;Page</span></a></li>
    <li id="current"><a href="annotated.html"><span>Classes</span></a></li>
    <li><a href="files.html"><span>Files</span></a></li>
    <li><a href="pages.html"><span>Related&nbsp;Pages</span></a></li>
  </ul></div>
<div class="tabs">
  <ul>
    <li><a href="annotated.html"><span>Class&nbsp;List</span></a></li>
    <li><a href="classes.html"><span>Alphabetical&nbsp;List</span></a></li>
    <li><a href="hierarchy.html"><span>Class&nbsp;Hierarchy</span></a></li>
    <li><a href="functions.html"><span>Class&nbsp;Members</span></a></li>
  </ul></div>
<h1>iterator Class Reference</h1><!-- doxytag: class="std::iterator" -->Inherited by <a class="el" href="class_tree_map_1_1const__iterator.html">TreeMap::const_iterator</a>.
<p>
Inheritance diagram for iterator:<p><center><img src="classstd_1_1iterator__inherit__graph.png" border="0" usemap="#iterator__inherit__map" alt="Inheritance graph"></center>
<map name="iterator__inherit__map">
<area href="class_tree_map_1_1const__iterator.html" shape="rect" coords="7,81,169,108" alt="">
<area href="class_tree_map_1_1iterator.html" shape="rect" coords="27,156,149,183" alt="">
</map>
<center><font size="2">[<a href="graph_legend.html">legend</a>]</font></center><table border="0" cellpadding="0" cellspacing="0">
<tr><td></td></tr>
</table>
<hr>The documentation for this class was generated from the following file:<ul>
<li><a class="el" href="_tree_map_8h-source.html">TreeMap.h</a></ul>
<hr size="1"><address style="align: right;"><small>Generated on Fri Dec 2 01:03:51 2005 for AISDI Cwiczenie 4 by&nbsp;
<a href="http://www.doxygen.org/index.html">
<img src="doxygen.png" alt="doxygen" align="middle" border="0"></a> 1.4.5 </small></address>
</body>
</html>
                                                                                                                                                                                                                                                                                                                                                                                              tree/info/doxcfg_8dox.html                                                                          0100644 0003673 0000144 00000002335 11704031106 0016767 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html><head><meta http-equiv="Content-Type" content="text/html;charset=iso-8859-1">
<title>AISDI Cwiczenie 4: doxcfg.dox File Reference</title>
<link href="doxygen.css" rel="stylesheet" type="text/css">
<link href="tabs.css" rel="stylesheet" type="text/css">
</head><body>
<!-- Generated by Doxygen 1.4.5 -->
<div class="tabs">
  <ul>
    <li><a href="index.html"><span>Main&nbsp;Page</span></a></li>
    <li><a href="annotated.html"><span>Classes</span></a></li>
    <li id="current"><a href="files.html"><span>Files</span></a></li>
    <li><a href="pages.html"><span>Related&nbsp;Pages</span></a></li>
  </ul></div>
<div class="tabs">
  <ul>
    <li><a href="files.html"><span>File&nbsp;List</span></a></li>
    <li><a href="globals.html"><span>File&nbsp;Members</span></a></li>
  </ul></div>
<h1>doxcfg.dox File Reference</h1><table border="0" cellpadding="0" cellspacing="0">
<tr><td></td></tr>
</table>
<hr size="1"><address style="align: right;"><small>Generated on Fri Dec 2 01:03:51 2005 for AISDI Cwiczenie 4 by&nbsp;
<a href="http://www.doxygen.org/index.html">
<img src="doxygen.png" alt="doxygen" align="middle" border="0"></a> 1.4.5 </small></address>
</body>
</html>
                                                                                                                                                                                                                                                                                                   tree/info/doxcfg3_8dox.html                                                                         0100644 0003673 0000144 00000002337 11704031107 0017055 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html><head><meta http-equiv="Content-Type" content="text/html;charset=iso-8859-1">
<title>AISDI Cwiczenie 4: doxcfg3.dox File Reference</title>
<link href="doxygen.css" rel="stylesheet" type="text/css">
<link href="tabs.css" rel="stylesheet" type="text/css">
</head><body>
<!-- Generated by Doxygen 1.4.5 -->
<div class="tabs">
  <ul>
    <li><a href="index.html"><span>Main&nbsp;Page</span></a></li>
    <li><a href="annotated.html"><span>Classes</span></a></li>
    <li id="current"><a href="files.html"><span>Files</span></a></li>
    <li><a href="pages.html"><span>Related&nbsp;Pages</span></a></li>
  </ul></div>
<div class="tabs">
  <ul>
    <li><a href="files.html"><span>File&nbsp;List</span></a></li>
    <li><a href="globals.html"><span>File&nbsp;Members</span></a></li>
  </ul></div>
<h1>doxcfg3.dox File Reference</h1><table border="0" cellpadding="0" cellspacing="0">
<tr><td></td></tr>
</table>
<hr size="1"><address style="align: right;"><small>Generated on Fri Dec 2 01:03:51 2005 for AISDI Cwiczenie 4 by&nbsp;
<a href="http://www.doxygen.org/index.html">
<img src="doxygen.png" alt="doxygen" align="middle" border="0"></a> 1.4.5 </small></address>
</body>
</html>
                                                                                                                                                                                                                                                                                                 tree/info/functions.html                                                                            0100644 0003673 0000144 00000022624 11704031107 0016567 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html><head><meta http-equiv="Content-Type" content="text/html;charset=iso-8859-1">
<title>AISDI Cwiczenie 4: Class Members</title>
<link href="doxygen.css" rel="stylesheet" type="text/css">
<link href="tabs.css" rel="stylesheet" type="text/css">
</head><body>
<!-- Generated by Doxygen 1.4.5 -->
<div class="tabs">
  <ul>
    <li><a href="index.html"><span>Main&nbsp;Page</span></a></li>
    <li id="current"><a href="annotated.html"><span>Classes</span></a></li>
    <li><a href="files.html"><span>Files</span></a></li>
    <li><a href="pages.html"><span>Related&nbsp;Pages</span></a></li>
  </ul></div>
<div class="tabs">
  <ul>
    <li><a href="annotated.html"><span>Class&nbsp;List</span></a></li>
    <li><a href="classes.html"><span>Alphabetical&nbsp;List</span></a></li>
    <li><a href="hierarchy.html"><span>Class&nbsp;Hierarchy</span></a></li>
    <li id="current"><a href="functions.html"><span>Class&nbsp;Members</span></a></li>
  </ul></div>
<div class="tabs">
  <ul>
    <li id="current"><a href="functions.html"><span>All</span></a></li>
    <li><a href="functions_func.html"><span>Functions</span></a></li>
    <li><a href="functions_vars.html"><span>Variables</span></a></li>
    <li><a href="functions_type.html"><span>Typedefs</span></a></li>
    <li><a href="functions_rela.html"><span>Related&nbsp;Functions</span></a></li>
  </ul>
</div>
<div class="tabs">
  <ul>
    <li><a href="#index_b"><span>b</span></a></li>
    <li><a href="#index_c"><span>c</span></a></li>
    <li><a href="#index_d"><span>d</span></a></li>
    <li><a href="#index_e"><span>e</span></a></li>
    <li><a href="#index_f"><span>f</span></a></li>
    <li><a href="#index_g"><span>g</span></a></li>
    <li><a href="#index_i"><span>i</span></a></li>
    <li><a href="#index_k"><span>k</span></a></li>
    <li><a href="#index_l"><span>l</span></a></li>
    <li><a href="#index_n"><span>n</span></a></li>
    <li><a href="#index_o"><span>o</span></a></li>
    <li><a href="#index_p"><span>p</span></a></li>
    <li><a href="#index_r"><span>r</span></a></li>
    <li><a href="#index_s"><span>s</span></a></li>
    <li><a href="#index_t"><span>t</span></a></li>
    <li><a href="#index_u"><span>u</span></a></li>
    <li><a href="#index_v"><span>v</span></a></li>
    <li><a href="#index_~"><span>~</span></a></li>
  </ul>
</div>

<p>
Here is a list of all class members with links to the classes they belong to:
<p>
<h3><a class="anchor" name="index_b">- b -</a></h3><ul>
<li>begin()
: <a class="el" href="class_tree_map.html#6c34e3a8894af3a2160a3c0baa7e6fad">TreeMap</a></ul>
<h3><a class="anchor" name="index_c">- c -</a></h3><ul>
<li>CCount()
: <a class="el" href="class_c_count.html#56b8d3879a6fedc1932c5c2733eb7655">CCount</a><li>clear()
: <a class="el" href="class_tree_map.html#3616b8000a015689fed4b46c19c06ea2">TreeMap</a><li>const_iterator()
: <a class="el" href="class_tree_map_1_1const__iterator.html#6e845f4990b76b6659a5e525ee7c917e">TreeMap::const_iterator</a><li>count
: <a class="el" href="class_tree_map.html#1d79deabb6ad2a93ef5358356055ee3b">TreeMap</a>, <a class="el" href="class_c_count.html#e2942a04780e223b215eb8b663cf5353">CCount</a></ul>
<h3><a class="anchor" name="index_d">- d -</a></h3><ul>
<li>data
: <a class="el" href="struct_tree_node.html#8d777f385d3dfec8815d20f7496026dc">TreeNode</a><li>detail
: <a class="el" href="class_tree_map.html#951da6b7179a4f697cc89d36acf74e52">TreeMap</a></ul>
<h3><a class="anchor" name="index_e">- e -</a></h3><ul>
<li>empty()
: <a class="el" href="class_tree_map.html#ea1ddff44da5abff286d8b01793eb7ee">TreeMap</a><li>end()
: <a class="el" href="class_tree_map.html#37d6974af8ee6af64f7b4f71330853cb">TreeMap</a><li>erase()
: <a class="el" href="class_tree_map.html#f768666a08bb3f9bf6d59af014dc8a79">TreeMap</a>, <a class="el" href="class_tree_map_detail.html#5637e02d8d73d541ed8c19d448ecac17">TreeMapDetail</a></ul>
<h3><a class="anchor" name="index_f">- f -</a></h3><ul>
<li>find()
: <a class="el" href="class_tree_map.html#732153e7bc56dacafa2411864b548219">TreeMap</a></ul>
<h3><a class="anchor" name="index_g">- g -</a></h3><ul>
<li>getCount()
: <a class="el" href="class_c_count.html#68b1e82502beaa137b00477d034627d5">CCount</a></ul>
<h3><a class="anchor" name="index_i">- i -</a></h3><ul>
<li>info_eq()
: <a class="el" href="class_tree_map.html#68dd925067e3812184dcedea9211ac4b">TreeMap</a><li>insert()
: <a class="el" href="class_tree_map.html#94500a970d082e87b838a94fed333521">TreeMap</a><li>iterator()
: <a class="el" href="class_tree_map_1_1iterator.html#5c297ca07cf2a75a9b0227b654c196d9">TreeMap::iterator</a></ul>
<h3><a class="anchor" name="index_k">- k -</a></h3><ul>
<li>Key
: <a class="el" href="class_tree_map.html#897356954c2cd3d41b221e3f24f99bba">TreeMap</a></ul>
<h3><a class="anchor" name="index_l">- l -</a></h3><ul>
<li>left
: <a class="el" href="struct_tree_node.html#811882fecd5c7618d7099ebbd39ea254">TreeNode</a></ul>
<h3><a class="anchor" name="index_n">- n -</a></h3><ul>
<li>node
: <a class="el" href="class_tree_map_1_1const__iterator.html#36c4536996ca5615dcf9911f068786dc">TreeMap::const_iterator</a><li>Node
: <a class="el" href="class_tree_map.html#6c3a6944a808a7c0bbb6788dbec54a9f">TreeMap</a></ul>
<h3><a class="anchor" name="index_o">- o -</a></h3><ul>
<li>operator *()
: <a class="el" href="class_tree_map_1_1iterator.html#f7a39cedb9cf2cea096b6e77b4794aa2">TreeMap::iterator</a>, <a class="el" href="class_tree_map_1_1const__iterator.html#f7a39cedb9cf2cea096b6e77b4794aa2">TreeMap::const_iterator</a><li>operator!=()
: <a class="el" href="class_tree_map_1_1const__iterator.html#1afff81678307f558fa6ed1eadd24c40">TreeMap::const_iterator</a><li>operator++()
: <a class="el" href="class_tree_map_1_1iterator.html#5d4681e027a07e3fb51ab21bef0dcc3d">TreeMap::iterator</a>, <a class="el" href="class_tree_map_1_1const__iterator.html#5d4681e027a07e3fb51ab21bef0dcc3d">TreeMap::const_iterator</a><li>operator--()
: <a class="el" href="class_tree_map_1_1iterator.html#12332c0f3ca9f1be40bf725d24d260ef">TreeMap::iterator</a>, <a class="el" href="class_tree_map_1_1const__iterator.html#12332c0f3ca9f1be40bf725d24d260ef">TreeMap::const_iterator</a><li>operator-&gt;()
: <a class="el" href="class_tree_map_1_1iterator.html#0435166b505820018f60233eb3f00662">TreeMap::iterator</a>, <a class="el" href="class_tree_map_1_1const__iterator.html#0435166b505820018f60233eb3f00662">TreeMap::const_iterator</a><li>operator=()
: <a class="el" href="class_tree_map.html#48753429045577c544d7b1765997223e">TreeMap</a><li>operator==()
: <a class="el" href="class_tree_map.html#18b0ae91b08ac71b923d1c9dd85f7876">TreeMap</a>, <a class="el" href="class_tree_map_1_1const__iterator.html#af10f269139a928a53584bc453003226">TreeMap::const_iterator</a><li>operator[]()
: <a class="el" href="class_tree_map.html#ce20a84b60c9bcce43c37cb75d29fe50">TreeMap</a></ul>
<h3><a class="anchor" name="index_p">- p -</a></h3><ul>
<li>P
: <a class="el" href="class_tree_map.html#44c29edb103a2872f519ad0c9a0fdaaa">TreeMap</a><li>parent
: <a class="el" href="struct_tree_node.html#d0e45878043844ffc41aac437e86b602">TreeNode</a></ul>
<h3><a class="anchor" name="index_r">- r -</a></h3><ul>
<li>right
: <a class="el" href="struct_tree_node.html#7c4f29407893c334a6cb7a87bf045c0d">TreeNode</a><li>root
: <a class="el" href="class_tree_map.html#63a9f0ea7bb98050796b649e85481845">TreeMap</a></ul>
<h3><a class="anchor" name="index_s">- s -</a></h3><ul>
<li>size()
: <a class="el" href="class_tree_map.html#5a9421972c178b3c37b99f953470c6f6">TreeMap</a><li>size_type
: <a class="el" href="class_tree_map.html#3eb1f9410d79d28273ccc045cf8e6478">TreeMap</a><li>struct_eq()
: <a class="el" href="class_tree_map.html#e62bc2a78904e459d5f302a5ff48769a">TreeMap</a></ul>
<h3><a class="anchor" name="index_t">- t -</a></h3><ul>
<li>T
: <a class="el" href="class_tree_map_1_1const__iterator.html#b9ece18c950afbfa6b0fdbfa4ff731d3">TreeMap::const_iterator</a>, <a class="el" href="struct_tree_node.html#b9ece18c950afbfa6b0fdbfa4ff731d3">TreeNode</a><li>TreeMap
: <a class="el" href="class_tree_map.html#36057872ebdcdb89755ff678ad8a5179">TreeMap</a>, <a class="el" href="class_tree_map_1_1iterator.html#ec21601f0dade4123a4f02c3ab309706">TreeMap::iterator</a>, <a class="el" href="class_tree_map_1_1const__iterator.html#ec21601f0dade4123a4f02c3ab309706">TreeMap::const_iterator</a>, <a class="el" href="class_tree_map_detail.html#ec21601f0dade4123a4f02c3ab309706">TreeMapDetail</a><li>TreeMapDetail
: <a class="el" href="class_tree_map.html#359f4c98a692d55e998de2a0ccbfe3c9">TreeMap</a><li>TreeNode
: <a class="el" href="struct_tree_node.html#d8a9895b7d52ea3650148d93a1d132ce">TreeNode</a>, <a class="el" href="class_c_count.html#c0ade7f379584bcec5c868e24abd743c">CCount</a></ul>
<h3><a class="anchor" name="index_u">- u -</a></h3><ul>
<li>unsafe_insert()
: <a class="el" href="class_tree_map.html#9b42b72518de2845832b80e44424fab3">TreeMap</a></ul>
<h3><a class="anchor" name="index_v">- v -</a></h3><ul>
<li>Val
: <a class="el" href="class_tree_map.html#5988c20a047cfe063999787584b0aca7">TreeMap</a></ul>
<h3><a class="anchor" name="index_~">- ~ -</a></h3><ul>
<li>~CCount()
: <a class="el" href="class_c_count.html#46a9e57e83393ebb6451f597d02d2338">CCount</a><li>~TreeMap()
: <a class="el" href="class_tree_map.html#3d396c0d29bbefef0723fb19a95dd386">TreeMap</a></ul>
<hr size="1"><address style="align: right;"><small>Generated on Fri Dec 2 01:03:51 2005 for AISDI Cwiczenie 4 by&nbsp;
<a href="http://www.doxygen.org/index.html">
<img src="doxygen.png" alt="doxygen" align="middle" border="0"></a> 1.4.5 </small></address>
</body>
</html>
                                                                                                            tree/info/functions_func.html                                                                       0100644 0003673 0000144 00000013523 11704031107 0017600 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html><head><meta http-equiv="Content-Type" content="text/html;charset=iso-8859-1">
<title>AISDI Cwiczenie 4: Class Members - Functions</title>
<link href="doxygen.css" rel="stylesheet" type="text/css">
<link href="tabs.css" rel="stylesheet" type="text/css">
</head><body>
<!-- Generated by Doxygen 1.4.5 -->
<div class="tabs">
  <ul>
    <li><a href="index.html"><span>Main&nbsp;Page</span></a></li>
    <li id="current"><a href="annotated.html"><span>Classes</span></a></li>
    <li><a href="files.html"><span>Files</span></a></li>
    <li><a href="pages.html"><span>Related&nbsp;Pages</span></a></li>
  </ul></div>
<div class="tabs">
  <ul>
    <li><a href="annotated.html"><span>Class&nbsp;List</span></a></li>
    <li><a href="classes.html"><span>Alphabetical&nbsp;List</span></a></li>
    <li><a href="hierarchy.html"><span>Class&nbsp;Hierarchy</span></a></li>
    <li id="current"><a href="functions.html"><span>Class&nbsp;Members</span></a></li>
  </ul></div>
<div class="tabs">
  <ul>
    <li><a href="functions.html"><span>All</span></a></li>
    <li id="current"><a href="functions_func.html"><span>Functions</span></a></li>
    <li><a href="functions_vars.html"><span>Variables</span></a></li>
    <li><a href="functions_type.html"><span>Typedefs</span></a></li>
    <li><a href="functions_rela.html"><span>Related&nbsp;Functions</span></a></li>
  </ul>
</div>
&nbsp;
<p>
<ul>
<li>begin()
: <a class="el" href="class_tree_map.html#6c34e3a8894af3a2160a3c0baa7e6fad">TreeMap</a><li>CCount()
: <a class="el" href="class_c_count.html#56b8d3879a6fedc1932c5c2733eb7655">CCount</a><li>clear()
: <a class="el" href="class_tree_map.html#3616b8000a015689fed4b46c19c06ea2">TreeMap</a><li>const_iterator()
: <a class="el" href="class_tree_map_1_1const__iterator.html#6e845f4990b76b6659a5e525ee7c917e">TreeMap::const_iterator</a><li>count()
: <a class="el" href="class_tree_map.html#1d79deabb6ad2a93ef5358356055ee3b">TreeMap</a>, <a class="el" href="class_c_count.html#e2942a04780e223b215eb8b663cf5353">CCount</a><li>empty()
: <a class="el" href="class_tree_map.html#ea1ddff44da5abff286d8b01793eb7ee">TreeMap</a><li>end()
: <a class="el" href="class_tree_map.html#37d6974af8ee6af64f7b4f71330853cb">TreeMap</a><li>erase()
: <a class="el" href="class_tree_map.html#f768666a08bb3f9bf6d59af014dc8a79">TreeMap</a>, <a class="el" href="class_tree_map_detail.html#5637e02d8d73d541ed8c19d448ecac17">TreeMapDetail</a><li>find()
: <a class="el" href="class_tree_map.html#732153e7bc56dacafa2411864b548219">TreeMap</a><li>getCount()
: <a class="el" href="class_c_count.html#68b1e82502beaa137b00477d034627d5">CCount</a><li>info_eq()
: <a class="el" href="class_tree_map.html#68dd925067e3812184dcedea9211ac4b">TreeMap</a><li>insert()
: <a class="el" href="class_tree_map.html#94500a970d082e87b838a94fed333521">TreeMap</a><li>iterator()
: <a class="el" href="class_tree_map_1_1iterator.html#5c297ca07cf2a75a9b0227b654c196d9">TreeMap::iterator</a><li>operator *()
: <a class="el" href="class_tree_map_1_1iterator.html#f7a39cedb9cf2cea096b6e77b4794aa2">TreeMap::iterator</a>, <a class="el" href="class_tree_map_1_1const__iterator.html#f7a39cedb9cf2cea096b6e77b4794aa2">TreeMap::const_iterator</a><li>operator!=()
: <a class="el" href="class_tree_map_1_1const__iterator.html#1afff81678307f558fa6ed1eadd24c40">TreeMap::const_iterator</a><li>operator++()
: <a class="el" href="class_tree_map_1_1iterator.html#5d4681e027a07e3fb51ab21bef0dcc3d">TreeMap::iterator</a>, <a class="el" href="class_tree_map_1_1const__iterator.html#5d4681e027a07e3fb51ab21bef0dcc3d">TreeMap::const_iterator</a><li>operator--()
: <a class="el" href="class_tree_map_1_1iterator.html#12332c0f3ca9f1be40bf725d24d260ef">TreeMap::iterator</a>, <a class="el" href="class_tree_map_1_1const__iterator.html#12332c0f3ca9f1be40bf725d24d260ef">TreeMap::const_iterator</a><li>operator-&gt;()
: <a class="el" href="class_tree_map_1_1iterator.html#0435166b505820018f60233eb3f00662">TreeMap::iterator</a>, <a class="el" href="class_tree_map_1_1const__iterator.html#0435166b505820018f60233eb3f00662">TreeMap::const_iterator</a><li>operator=()
: <a class="el" href="class_tree_map.html#48753429045577c544d7b1765997223e">TreeMap</a><li>operator==()
: <a class="el" href="class_tree_map.html#18b0ae91b08ac71b923d1c9dd85f7876">TreeMap</a>, <a class="el" href="class_tree_map_1_1const__iterator.html#af10f269139a928a53584bc453003226">TreeMap::const_iterator</a><li>operator[]()
: <a class="el" href="class_tree_map.html#ce20a84b60c9bcce43c37cb75d29fe50">TreeMap</a><li>size()
: <a class="el" href="class_tree_map.html#5a9421972c178b3c37b99f953470c6f6">TreeMap</a><li>struct_eq()
: <a class="el" href="class_tree_map.html#e62bc2a78904e459d5f302a5ff48769a">TreeMap</a><li>TreeMap()
: <a class="el" href="class_tree_map.html#36057872ebdcdb89755ff678ad8a5179">TreeMap</a>, <a class="el" href="class_tree_map_1_1iterator.html#ec21601f0dade4123a4f02c3ab309706">TreeMap::iterator</a>, <a class="el" href="class_tree_map_1_1const__iterator.html#ec21601f0dade4123a4f02c3ab309706">TreeMap::const_iterator</a>, <a class="el" href="class_tree_map_detail.html#ec21601f0dade4123a4f02c3ab309706">TreeMapDetail</a><li>TreeNode()
: <a class="el" href="struct_tree_node.html#d8a9895b7d52ea3650148d93a1d132ce">TreeNode</a>, <a class="el" href="class_c_count.html#c0ade7f379584bcec5c868e24abd743c">CCount</a><li>unsafe_insert()
: <a class="el" href="class_tree_map.html#9b42b72518de2845832b80e44424fab3">TreeMap</a><li>~CCount()
: <a class="el" href="class_c_count.html#46a9e57e83393ebb6451f597d02d2338">CCount</a><li>~TreeMap()
: <a class="el" href="class_tree_map.html#3d396c0d29bbefef0723fb19a95dd386">TreeMap</a></ul>
<hr size="1"><address style="align: right;"><small>Generated on Fri Dec 2 01:03:51 2005 for AISDI Cwiczenie 4 by&nbsp;
<a href="http://www.doxygen.org/index.html">
<img src="doxygen.png" alt="doxygen" align="middle" border="0"></a> 1.4.5 </small></address>
</body>
</html>
                                                                                                                                                                             tree/info/functions_rela.html                                                                       0100644 0003673 0000144 00000004637 11704031107 0017576 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html><head><meta http-equiv="Content-Type" content="text/html;charset=iso-8859-1">
<title>AISDI Cwiczenie 4: Class Members - Related Functions</title>
<link href="doxygen.css" rel="stylesheet" type="text/css">
<link href="tabs.css" rel="stylesheet" type="text/css">
</head><body>
<!-- Generated by Doxygen 1.4.5 -->
<div class="tabs">
  <ul>
    <li><a href="index.html"><span>Main&nbsp;Page</span></a></li>
    <li id="current"><a href="annotated.html"><span>Classes</span></a></li>
    <li><a href="files.html"><span>Files</span></a></li>
    <li><a href="pages.html"><span>Related&nbsp;Pages</span></a></li>
  </ul></div>
<div class="tabs">
  <ul>
    <li><a href="annotated.html"><span>Class&nbsp;List</span></a></li>
    <li><a href="classes.html"><span>Alphabetical&nbsp;List</span></a></li>
    <li><a href="hierarchy.html"><span>Class&nbsp;Hierarchy</span></a></li>
    <li id="current"><a href="functions.html"><span>Class&nbsp;Members</span></a></li>
  </ul></div>
<div class="tabs">
  <ul>
    <li><a href="functions.html"><span>All</span></a></li>
    <li><a href="functions_func.html"><span>Functions</span></a></li>
    <li><a href="functions_vars.html"><span>Variables</span></a></li>
    <li><a href="functions_type.html"><span>Typedefs</span></a></li>
    <li id="current"><a href="functions_rela.html"><span>Related&nbsp;Functions</span></a></li>
  </ul>
</div>
&nbsp;
<p>
<ul>
<li>TreeMap
: <a class="el" href="class_tree_map.html#36057872ebdcdb89755ff678ad8a5179">TreeMap</a>, <a class="el" href="class_tree_map_1_1iterator.html#ec21601f0dade4123a4f02c3ab309706">TreeMap::iterator</a>, <a class="el" href="class_tree_map_1_1const__iterator.html#ec21601f0dade4123a4f02c3ab309706">TreeMap::const_iterator</a>, <a class="el" href="class_tree_map_detail.html#ec21601f0dade4123a4f02c3ab309706">TreeMapDetail</a><li>TreeMapDetail
: <a class="el" href="class_tree_map.html#359f4c98a692d55e998de2a0ccbfe3c9">TreeMap</a><li>TreeNode
: <a class="el" href="struct_tree_node.html#d8a9895b7d52ea3650148d93a1d132ce">TreeNode</a>, <a class="el" href="class_c_count.html#c0ade7f379584bcec5c868e24abd743c">CCount</a></ul>
<hr size="1"><address style="align: right;"><small>Generated on Fri Dec 2 01:03:51 2005 for AISDI Cwiczenie 4 by&nbsp;
<a href="http://www.doxygen.org/index.html">
<img src="doxygen.png" alt="doxygen" align="middle" border="0"></a> 1.4.5 </small></address>
</body>
</html>
                                                                                                 tree/info/functions_type.html                                                                       0100644 0003673 0000144 00000004575 11704031107 0017635 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html><head><meta http-equiv="Content-Type" content="text/html;charset=iso-8859-1">
<title>AISDI Cwiczenie 4: Class Members - Typedefs</title>
<link href="doxygen.css" rel="stylesheet" type="text/css">
<link href="tabs.css" rel="stylesheet" type="text/css">
</head><body>
<!-- Generated by Doxygen 1.4.5 -->
<div class="tabs">
  <ul>
    <li><a href="index.html"><span>Main&nbsp;Page</span></a></li>
    <li id="current"><a href="annotated.html"><span>Classes</span></a></li>
    <li><a href="files.html"><span>Files</span></a></li>
    <li><a href="pages.html"><span>Related&nbsp;Pages</span></a></li>
  </ul></div>
<div class="tabs">
  <ul>
    <li><a href="annotated.html"><span>Class&nbsp;List</span></a></li>
    <li><a href="classes.html"><span>Alphabetical&nbsp;List</span></a></li>
    <li><a href="hierarchy.html"><span>Class&nbsp;Hierarchy</span></a></li>
    <li id="current"><a href="functions.html"><span>Class&nbsp;Members</span></a></li>
  </ul></div>
<div class="tabs">
  <ul>
    <li><a href="functions.html"><span>All</span></a></li>
    <li><a href="functions_func.html"><span>Functions</span></a></li>
    <li><a href="functions_vars.html"><span>Variables</span></a></li>
    <li id="current"><a href="functions_type.html"><span>Typedefs</span></a></li>
    <li><a href="functions_rela.html"><span>Related&nbsp;Functions</span></a></li>
  </ul>
</div>
&nbsp;
<p>
<ul>
<li>Key
: <a class="el" href="class_tree_map.html#897356954c2cd3d41b221e3f24f99bba">TreeMap</a><li>Node
: <a class="el" href="class_tree_map.html#6c3a6944a808a7c0bbb6788dbec54a9f">TreeMap</a><li>P
: <a class="el" href="class_tree_map.html#44c29edb103a2872f519ad0c9a0fdaaa">TreeMap</a><li>size_type
: <a class="el" href="class_tree_map.html#3eb1f9410d79d28273ccc045cf8e6478">TreeMap</a><li>T
: <a class="el" href="class_tree_map_1_1const__iterator.html#b9ece18c950afbfa6b0fdbfa4ff731d3">TreeMap::const_iterator</a>, <a class="el" href="struct_tree_node.html#b9ece18c950afbfa6b0fdbfa4ff731d3">TreeNode</a><li>Val
: <a class="el" href="class_tree_map.html#5988c20a047cfe063999787584b0aca7">TreeMap</a></ul>
<hr size="1"><address style="align: right;"><small>Generated on Fri Dec 2 01:03:51 2005 for AISDI Cwiczenie 4 by&nbsp;
<a href="http://www.doxygen.org/index.html">
<img src="doxygen.png" alt="doxygen" align="middle" border="0"></a> 1.4.5 </small></address>
</body>
</html>
                                                                                                                                   tree/info/functions_vars.html                                                                       0100644 0003673 0000144 00000005116 11704031107 0017617 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html><head><meta http-equiv="Content-Type" content="text/html;charset=iso-8859-1">
<title>AISDI Cwiczenie 4: Class Members - Variables</title>
<link href="doxygen.css" rel="stylesheet" type="text/css">
<link href="tabs.css" rel="stylesheet" type="text/css">
</head><body>
<!-- Generated by Doxygen 1.4.5 -->
<div class="tabs">
  <ul>
    <li><a href="index.html"><span>Main&nbsp;Page</span></a></li>
    <li id="current"><a href="annotated.html"><span>Classes</span></a></li>
    <li><a href="files.html"><span>Files</span></a></li>
    <li><a href="pages.html"><span>Related&nbsp;Pages</span></a></li>
  </ul></div>
<div class="tabs">
  <ul>
    <li><a href="annotated.html"><span>Class&nbsp;List</span></a></li>
    <li><a href="classes.html"><span>Alphabetical&nbsp;List</span></a></li>
    <li><a href="hierarchy.html"><span>Class&nbsp;Hierarchy</span></a></li>
    <li id="current"><a href="functions.html"><span>Class&nbsp;Members</span></a></li>
  </ul></div>
<div class="tabs">
  <ul>
    <li><a href="functions.html"><span>All</span></a></li>
    <li><a href="functions_func.html"><span>Functions</span></a></li>
    <li id="current"><a href="functions_vars.html"><span>Variables</span></a></li>
    <li><a href="functions_type.html"><span>Typedefs</span></a></li>
    <li><a href="functions_rela.html"><span>Related&nbsp;Functions</span></a></li>
  </ul>
</div>
&nbsp;
<p>
<ul>
<li>count
: <a class="el" href="class_tree_map.html#1d79deabb6ad2a93ef5358356055ee3b">TreeMap</a>, <a class="el" href="class_c_count.html#e2942a04780e223b215eb8b663cf5353">CCount</a><li>data
: <a class="el" href="struct_tree_node.html#8d777f385d3dfec8815d20f7496026dc">TreeNode</a><li>detail
: <a class="el" href="class_tree_map.html#951da6b7179a4f697cc89d36acf74e52">TreeMap</a><li>left
: <a class="el" href="struct_tree_node.html#811882fecd5c7618d7099ebbd39ea254">TreeNode</a><li>node
: <a class="el" href="class_tree_map_1_1const__iterator.html#36c4536996ca5615dcf9911f068786dc">TreeMap::const_iterator</a><li>parent
: <a class="el" href="struct_tree_node.html#d0e45878043844ffc41aac437e86b602">TreeNode</a><li>right
: <a class="el" href="struct_tree_node.html#7c4f29407893c334a6cb7a87bf045c0d">TreeNode</a><li>root
: <a class="el" href="class_tree_map.html#63a9f0ea7bb98050796b649e85481845">TreeMap</a></ul>
<hr size="1"><address style="align: right;"><small>Generated on Fri Dec 2 01:03:51 2005 for AISDI Cwiczenie 4 by&nbsp;
<a href="http://www.doxygen.org/index.html">
<img src="doxygen.png" alt="doxygen" align="middle" border="0"></a> 1.4.5 </small></address>
</body>
</html>
                                                                                                                                                                                                                                                                                                                                                                                                                                                  tree/info/globals.html                                                                              0100644 0003673 0000144 00000003471 11704031107 0016201 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html><head><meta http-equiv="Content-Type" content="text/html;charset=iso-8859-1">
<title>AISDI Cwiczenie 4: Class Members</title>
<link href="doxygen.css" rel="stylesheet" type="text/css">
<link href="tabs.css" rel="stylesheet" type="text/css">
</head><body>
<!-- Generated by Doxygen 1.4.5 -->
<div class="tabs">
  <ul>
    <li><a href="index.html"><span>Main&nbsp;Page</span></a></li>
    <li><a href="annotated.html"><span>Classes</span></a></li>
    <li id="current"><a href="files.html"><span>Files</span></a></li>
    <li><a href="pages.html"><span>Related&nbsp;Pages</span></a></li>
  </ul></div>
<div class="tabs">
  <ul>
    <li><a href="files.html"><span>File&nbsp;List</span></a></li>
    <li id="current"><a href="globals.html"><span>File&nbsp;Members</span></a></li>
  </ul></div>
<div class="tabs">
  <ul>
    <li id="current"><a href="globals.html"><span>All</span></a></li>
    <li><a href="globals_func.html"><span>Functions</span></a></li>
  </ul>
</div>
Here is a list of all file members with links to the files they belong to:
<p>
<ul>
<li>main()
: <a class="el" href="main_8cc.html#ea83b916b3f52eec32ae6d54d59b4453">main.cc</a><li>print()
: <a class="el" href="asd_8cc.html#e29929e8b88737e614f6df9a0f9b6def">asd.cc</a><li>test()
: <a class="el" href="main_8cc.html#5af26b3a0b1f8425bfcd62bcfe8991cc">main.cc</a>, <a class="el" href="asd_8cc.html#5af26b3a0b1f8425bfcd62bcfe8991cc">asd.cc</a><li>Test2()
: <a class="el" href="main_8cc.html#da006f4ed56183a923cadf4bc85ce457">main.cc</a></ul>
<hr size="1"><address style="align: right;"><small>Generated on Fri Dec 2 01:03:52 2005 for AISDI Cwiczenie 4 by&nbsp;
<a href="http://www.doxygen.org/index.html">
<img src="doxygen.png" alt="doxygen" align="middle" border="0"></a> 1.4.5 </small></address>
</body>
</html>
                                                                                                                                                                                                       tree/info/globals_func.html                                                                         0100644 0003673 0000144 00000003365 11704031107 0017216 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html><head><meta http-equiv="Content-Type" content="text/html;charset=iso-8859-1">
<title>AISDI Cwiczenie 4: Class Members</title>
<link href="doxygen.css" rel="stylesheet" type="text/css">
<link href="tabs.css" rel="stylesheet" type="text/css">
</head><body>
<!-- Generated by Doxygen 1.4.5 -->
<div class="tabs">
  <ul>
    <li><a href="index.html"><span>Main&nbsp;Page</span></a></li>
    <li><a href="annotated.html"><span>Classes</span></a></li>
    <li id="current"><a href="files.html"><span>Files</span></a></li>
    <li><a href="pages.html"><span>Related&nbsp;Pages</span></a></li>
  </ul></div>
<div class="tabs">
  <ul>
    <li><a href="files.html"><span>File&nbsp;List</span></a></li>
    <li id="current"><a href="globals.html"><span>File&nbsp;Members</span></a></li>
  </ul></div>
<div class="tabs">
  <ul>
    <li><a href="globals.html"><span>All</span></a></li>
    <li id="current"><a href="globals_func.html"><span>Functions</span></a></li>
  </ul>
</div>
&nbsp;
<p>
<ul>
<li>main()
: <a class="el" href="main_8cc.html#ea83b916b3f52eec32ae6d54d59b4453">main.cc</a><li>print()
: <a class="el" href="asd_8cc.html#e29929e8b88737e614f6df9a0f9b6def">asd.cc</a><li>test()
: <a class="el" href="main_8cc.html#5af26b3a0b1f8425bfcd62bcfe8991cc">main.cc</a>, <a class="el" href="asd_8cc.html#5af26b3a0b1f8425bfcd62bcfe8991cc">asd.cc</a><li>Test2()
: <a class="el" href="main_8cc.html#da006f4ed56183a923cadf4bc85ce457">main.cc</a></ul>
<hr size="1"><address style="align: right;"><small>Generated on Fri Dec 2 01:03:52 2005 for AISDI Cwiczenie 4 by&nbsp;
<a href="http://www.doxygen.org/index.html">
<img src="doxygen.png" alt="doxygen" align="middle" border="0"></a> 1.4.5 </small></address>
</body>
</html>
/li>
    <li id="current"><a href="globals.html"><span>File&nbsp;Members</span></a></li>
  </ul></div>
<div class="tabs">
  <ul>
    <li><a href="globals.html"><span>All</span></a></li>
    <li id="current"><a href="globals_func.html"><span>Functions</span></a></li>
tree/info/graph_legend.html                                                                         0100644 0003673 0000144 00000010601 11704031107 0017166 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html><head><meta http-equiv="Content-Type" content="text/html;charset=iso-8859-1">
<title>AISDI Cwiczenie 4: Graph Legend</title>
<link href="doxygen.css" rel="stylesheet" type="text/css">
<link href="tabs.css" rel="stylesheet" type="text/css">
</head><body>
<!-- Generated by Doxygen 1.4.5 -->
<div class="tabs">
  <ul>
    <li><a href="index.html"><span>Main&nbsp;Page</span></a></li>
    <li><a href="annotated.html"><span>Classes</span></a></li>
    <li><a href="files.html"><span>Files</span></a></li>
    <li><a href="pages.html"><span>Related&nbsp;Pages</span></a></li>
  </ul></div>
<h1>Graph Legend</h1>This page explains how to interpret the graphs that are generated by doxygen.<p>
Consider the following example: <div class="fragment"><pre class="fragment"><span class="comment">/*! Invisible class because of truncation */</span>
<span class="keyword">class </span>Invisible { };
<span class="comment"></span>
<span class="comment">/*! Truncated class, inheritance relation is hidden */</span>
<span class="keyword">class </span>Truncated : <span class="keyword">public</span> Invisible { };

<span class="comment">/* Class not documented with doxygen comments */</span>
<span class="keyword">class </span>Undocumented { };
<span class="comment"></span>
<span class="comment">/*! Class that is inherited using public inheritance */</span>
<span class="keyword">class </span>PublicBase : <span class="keyword">public</span> Truncated { };
<span class="comment"></span>
<span class="comment">/*! A template class */</span>
<span class="keyword">template</span>&lt;<span class="keyword">class</span> T&gt; <span class="keyword">class </span>Templ { };
<span class="comment"></span>
<span class="comment">/*! Class that is inherited using protected inheritance */</span>
<span class="keyword">class </span>ProtectedBase { };
<span class="comment"></span>
<span class="comment">/*! Class that is inherited using private inheritance */</span>
<span class="keyword">class </span>PrivateBase { };
<span class="comment"></span>
<span class="comment">/*! Class that is used by the Inherited class */</span>
<span class="keyword">class </span>Used { };
<span class="comment"></span>
<span class="comment">/*! Super class that inherits a number of other classes */</span>
<span class="keyword">class </span>Inherited : <span class="keyword">public</span> PublicBase,
                  <span class="keyword">protected</span> ProtectedBase,
                  <span class="keyword">private</span> PrivateBase,
                  <span class="keyword">public</span> Undocumented
                  <span class="keyword">public</span> Templ&lt;int&gt;
{
  <span class="keyword">private</span>:
    Used *m_usedClass;
};
</pre></div> If the <code>MAX_DOT_GRAPH_HEIGHT</code> tag in the configuration file is set to 240 this will result in the following graph:<p>
<center><div align="center">
<img src="graph_legend.png" alt="graph_legend.png">
</div>
</center> <p>
The boxes in the above graph have the following meaning: <ul>
<li>
A filled black box represents the struct or class for which the graph is generated. </li>
<li>
A box with a black border denotes a documented struct or class. </li>
<li>
A box with a grey border denotes an undocumented struct or class. </li>
<li>
A box with a red border denotes a documented struct or class forwhich not all inheritance/containment relations are shown. A graph is truncated if it does not fit within the specified boundaries. </li>
</ul>
The arrows have the following meaning: <ul>
<li>
A dark blue arrow is used to visualize a public inheritance relation between two classes. </li>
<li>
A dark green arrow is used for protected inheritance. </li>
<li>
A dark red arrow is used for private inheritance. </li>
<li>
A purple dashed arrow is used if a class is contained or used by another class. The arrow is labeled with the variable(s) through which the pointed class or struct is accessible. </li>
<li>
A yellow dashed arrow denotes a relation between a template instance and the template class it was instantiated from. The arrow is labeled with the template parameters of the instance. </li>
</ul>
<hr size="1"><address style="align: right;"><small>Generated on Fri Dec 2 01:03:52 2005 for AISDI Cwiczenie 4 by&nbsp;
<a href="http://www.doxygen.org/index.html">
<img src="doxygen.png" alt="doxygen" align="middle" border="0"></a> 1.4.5 </small></address>
</body>
</html>
                                                                                                                               tree/info/hierarchy.html                                                                            0100644 0003673 0000144 00000004033 11704031107 0016527 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html><head><meta http-equiv="Content-Type" content="text/html;charset=iso-8859-1">
<title>AISDI Cwiczenie 4: Hierarchical Index</title>
<link href="doxygen.css" rel="stylesheet" type="text/css">
<link href="tabs.css" rel="stylesheet" type="text/css">
</head><body>
<!-- Generated by Doxygen 1.4.5 -->
<div class="tabs">
  <ul>
    <li><a href="index.html"><span>Main&nbsp;Page</span></a></li>
    <li id="current"><a href="annotated.html"><span>Classes</span></a></li>
    <li><a href="files.html"><span>Files</span></a></li>
    <li><a href="pages.html"><span>Related&nbsp;Pages</span></a></li>
  </ul></div>
<div class="tabs">
  <ul>
    <li><a href="annotated.html"><span>Class&nbsp;List</span></a></li>
    <li><a href="classes.html"><span>Alphabetical&nbsp;List</span></a></li>
    <li id="current"><a href="hierarchy.html"><span>Class&nbsp;Hierarchy</span></a></li>
    <li><a href="functions.html"><span>Class&nbsp;Members</span></a></li>
  </ul></div>
<h1>AISDI Cwiczenie 4 Class Hierarchy</h1><a href="inherits.html">Go to the graphical class hierarchy</a>
<p>
This inheritance list is sorted roughly, but not completely, alphabetically:<ul>
<li><a class="el" href="classbasic__wfstream.html">basic_wfstream</a>
<li><a class="el" href="class_c_count.html">CCount</a>
<ul>
<li><a class="el" href="struct_tree_node.html">TreeNode</a>
</ul>
<li><a class="el" href="classstd_1_1iterator.html">iterator</a>
<ul>
<li><a class="el" href="class_tree_map_1_1const__iterator.html">TreeMap::const_iterator</a>
<ul>
<li><a class="el" href="class_tree_map_1_1iterator.html">TreeMap::iterator</a>
</ul>
</ul>
<li><a class="el" href="class_tree_map.html">TreeMap</a>
<li><a class="el" href="class_tree_map_detail.html">TreeMapDetail</a>
</ul>
<hr size="1"><address style="align: right;"><small>Generated on Fri Dec 2 01:03:51 2005 for AISDI Cwiczenie 4 by&nbsp;
<a href="http://www.doxygen.org/index.html">
<img src="doxygen.png" alt="doxygen" align="middle" border="0"></a> 1.4.5 </small></address>
</body>
</html>
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     tree/info/index.html                                                                                0100644 0003673 0000144 00000001730 11704031107 0015661 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html><head><meta http-equiv="Content-Type" content="text/html;charset=iso-8859-1">
<title>AISDI Cwiczenie 4: Main Page</title>
<link href="doxygen.css" rel="stylesheet" type="text/css">
<link href="tabs.css" rel="stylesheet" type="text/css">
</head><body>
<!-- Generated by Doxygen 1.4.5 -->
<div class="tabs">
  <ul>
    <li id="current"><a href="index.html"><span>Main&nbsp;Page</span></a></li>
    <li><a href="annotated.html"><span>Classes</span></a></li>
    <li><a href="files.html"><span>Files</span></a></li>
    <li><a href="pages.html"><span>Related&nbsp;Pages</span></a></li>
  </ul></div>
<h1>AISDI Cwiczenie 4 Documentation</h1>
<p>
<hr size="1"><address style="align: right;"><small>Generated on Fri Dec 2 01:03:51 2005 for AISDI Cwiczenie 4 by&nbsp;
<a href="http://www.doxygen.org/index.html">
<img src="doxygen.png" alt="doxygen" align="middle" border="0"></a> 1.4.5 </small></address>
</body>
</html>
 href="annotated.html"><span>Classes</sptree/info/inherits.html                                                                             0100644 0003673 0000144 00000005351 11704031107 0016402 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html><head><meta http-equiv="Content-Type" content="text/html;charset=iso-8859-1">
<title>AISDI Cwiczenie 4: Graphical Class Hierarchy</title>
<link href="doxygen.css" rel="stylesheet" type="text/css">
<link href="tabs.css" rel="stylesheet" type="text/css">
</head><body>
<!-- Generated by Doxygen 1.4.5 -->
<div class="tabs">
  <ul>
    <li><a href="index.html"><span>Main&nbsp;Page</span></a></li>
    <li id="current"><a href="annotated.html"><span>Classes</span></a></li>
    <li><a href="files.html"><span>Files</span></a></li>
    <li><a href="pages.html"><span>Related&nbsp;Pages</span></a></li>
  </ul></div>
<div class="tabs">
  <ul>
    <li><a href="annotated.html"><span>Class&nbsp;List</span></a></li>
    <li><a href="classes.html"><span>Alphabetical&nbsp;List</span></a></li>
    <li id="current"><a href="hierarchy.html"><span>Class&nbsp;Hierarchy</span></a></li>
    <li><a href="functions.html"><span>Class&nbsp;Members</span></a></li>
  </ul></div>
<h1>AISDI Cwiczenie 4 Graphical Class Hierarchy</h1><a href="hierarchy.html">Go to the textual class hierarchy</a>
<p>
<table border="0" cellspacing="10" cellpadding="0">
<tr><td><img src="inherit__graph__0.png" border="0" alt="" usemap="#basic__wfstream_map">
<map name="basic__wfstream_map">
<area href="classbasic__wfstream.html" shape="rect" coords="7,7,121,33" alt="">
</map></td></tr>
<tr><td><img src="inherit__graph__1.png" border="0" alt="" usemap="#_c_count_map">
<map name="_c_count_map">
<area href="class_c_count.html" shape="rect" coords="7,7,74,33" alt="">
<area href="struct_tree_node.html" shape="rect" coords="123,7,203,33" alt="">
</map></td></tr>
<tr><td><img src="inherit__graph__2.png" border="0" alt="" usemap="#iterator_map">
<map name="iterator_map">
<area href="classstd_1_1iterator.html" shape="rect" coords="7,7,71,33" alt="">
<area href="class_tree_map_1_1const__iterator.html" shape="rect" coords="120,7,283,33" alt="">
<area href="class_tree_map_1_1iterator.html" shape="rect" coords="333,7,456,33" alt="">
</map></td></tr>
<tr><td><img src="inherit__graph__3.png" border="0" alt="" usemap="#_tree_map_map">
<map name="_tree_map_map">
<area href="class_tree_map.html" shape="rect" coords="7,7,81,33" alt="">
</map></td></tr>
<tr><td><img src="inherit__graph__4.png" border="0" alt="" usemap="#_tree_map_detail_map">
<map name="_tree_map_detail_map">
<area href="class_tree_map_detail.html" shape="rect" coords="7,7,116,33" alt="">
</map></td></tr>
</table>
<hr size="1"><address style="align: right;"><small>Generated on Fri Dec 2 01:03:52 2005 for AISDI Cwiczenie 4 by&nbsp;
<a href="http://www.doxygen.org/index.html">
<img src="doxygen.png" alt="doxygen" align="middle" border="0"></a> 1.4.5 </small></address>
</body>
</html>
                                                                                                                                                                                                                                                                                       tree/info/main_8cc.html                                                                             0100644 0003673 0000144 00000014535 11704031107 0016242 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html><head><meta http-equiv="Content-Type" content="text/html;charset=iso-8859-1">
<title>AISDI Cwiczenie 4: main.cc File Reference</title>
<link href="doxygen.css" rel="stylesheet" type="text/css">
<link href="tabs.css" rel="stylesheet" type="text/css">
</head><body>
<!-- Generated by Doxygen 1.4.5 -->
<div class="tabs">
  <ul>
    <li><a href="index.html"><span>Main&nbsp;Page</span></a></li>
    <li><a href="annotated.html"><span>Classes</span></a></li>
    <li id="current"><a href="files.html"><span>Files</span></a></li>
    <li><a href="pages.html"><span>Related&nbsp;Pages</span></a></li>
  </ul></div>
<div class="tabs">
  <ul>
    <li><a href="files.html"><span>File&nbsp;List</span></a></li>
    <li><a href="globals.html"><span>File&nbsp;Members</span></a></li>
  </ul></div>
<h1>main.cc File Reference</h1>Plik z funkcja <a class="el" href="main_8cc.html#ea83b916b3f52eec32ae6d54d59b4453">main()</a> do cwiczenia 4 na laboratoriach z AISDI. <a href="#_details">More...</a>
<p>
<code>#include &lt;iostream&gt;</code><br>
<code>#include &quot;<a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>&quot;</code><br>

<p>
Include dependency graph for main.cc:<p><center><img src="main_8cc__incl.png" border="0" usemap="#main.cc_map" alt=""></center>
<map name="main.cc_map">
<area href="_tree_map_8h-source.html" shape="rect" coords="125,83,211,109" alt="">
</map>

<p>
<a href="main_8cc-source.html">Go to the source code of this file.</a><table border="0" cellpadding="0" cellspacing="0">
<tr><td></td></tr>
<tr><td colspan="2"><br><h2>Functions</h2></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top">int&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="main_8cc.html#da006f4ed56183a923cadf4bc85ce457">Test2</a> ()</td></tr>

<tr><td class="memItemLeft" nowrap align="right" valign="top">void&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="main_8cc.html#5af26b3a0b1f8425bfcd62bcfe8991cc">test</a> ()</td></tr>

<tr><td class="mdescLeft">&nbsp;</td><td class="mdescRight">The big mean test function ;).  <a href="#5af26b3a0b1f8425bfcd62bcfe8991cc"></a><br></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top">int&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="main_8cc.html#ea83b916b3f52eec32ae6d54d59b4453">main</a> ()</td></tr>

</table>
<hr><a name="_details"></a><h2>Detailed Description</h2>
Plik z funkcja <a class="el" href="main_8cc.html#ea83b916b3f52eec32ae6d54d59b4453">main()</a> do cwiczenia 4 na laboratoriach z AISDI. 
<p>
<dl compact><dt><b>Author:</b></dt><dd>Pawel Cichocki, Michal Nowacki</dd></dl>
<dl compact><dt><b>Date:</b></dt><dd>last revision<ul>
<li>2005.12.01 Michal Nowacki: lab #4</li><li>2005.10.27 Pawel Cichocki: added some comments</li><li>2005.10.26 Michal Nowacki: creation - separated from another file</li></ul>
</dd></dl>
COPYRIGHT: Copyright (c) 2005 Instytut Informatyki, Politechnika Warszawska ALL RIGHTS RESERVED 
<p>
Definition in file <a class="el" href="main_8cc-source.html">main.cc</a>.<hr><h2>Function Documentation</h2>
<a class="anchor" name="ea83b916b3f52eec32ae6d54d59b4453"></a><!-- doxytag: member="main.cc::main" ref="ea83b916b3f52eec32ae6d54d59b4453" args="()" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">int main           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="mdname1" valign="top" nowrap>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>

<p>
Definition at line <a class="el" href="main_8cc-source.html#l00033">33</a> of file <a class="el" href="main_8cc-source.html">main.cc</a>.
<p>
References <a class="el" href="asd_8cc-source.html#l00281">test()</a>, and <a class="el" href="main_8cc.html#da006f4ed56183a923cadf4bc85ce457">Test2()</a>.    </td>
  </tr>
</table>
<a class="anchor" name="5af26b3a0b1f8425bfcd62bcfe8991cc"></a><!-- doxytag: member="main.cc::test" ref="5af26b3a0b1f8425bfcd62bcfe8991cc" args="()" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">void test           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="mdname1" valign="top" nowrap>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>
The big mean test function ;). 
<p>

<p>
Definition at line <a class="el" href="asd_8cc-source.html#l00281">281</a> of file <a class="el" href="asd_8cc-source.html">asd.cc</a>.
<p>
References <a class="el" href="asd_8cc-source.html#l00273">print()</a>.
<p>
Referenced by <a class="el" href="main_8cc-source.html#l00033">main()</a>.    </td>
  </tr>
</table>
<a class="anchor" name="da006f4ed56183a923cadf4bc85ce457"></a><!-- doxytag: member="main.cc::Test2" ref="da006f4ed56183a923cadf4bc85ce457" args="()" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">int Test2           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="mdname1" valign="top" nowrap>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>

<p>
Referenced by <a class="el" href="main_8cc-source.html#l00033">main()</a>.    </td>
  </tr>
</table>
<hr size="1"><address style="align: right;"><small>Generated on Fri Dec 2 01:03:51 2005 for AISDI Cwiczenie 4 by&nbsp;
<a href="http://www.doxygen.org/index.html">
<img src="doxygen.png" alt="doxygen" align="middle" border="0"></a> 1.4.5 </small></address>
</body>
</html>
ain.cc File Reference</h1>Plik z funkcja <a class="el" href="main_8cc.html#ea83b916b3f52eec32ae6d54d59b4453">main()</a> do cwiczenia 4 na laboratoriach z AISDI. <atree/info/main_8cc-source.html                                                                      0100644 0003673 0000144 00000006611 11704031107 0017534 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html><head><meta http-equiv="Content-Type" content="text/html;charset=iso-8859-1">
<title>AISDI Cwiczenie 4: main.cc Source File</title>
<link href="doxygen.css" rel="stylesheet" type="text/css">
<link href="tabs.css" rel="stylesheet" type="text/css">
</head><body>
<!-- Generated by Doxygen 1.4.5 -->
<div class="tabs">
  <ul>
    <li><a href="index.html"><span>Main&nbsp;Page</span></a></li>
    <li><a href="annotated.html"><span>Classes</span></a></li>
    <li id="current"><a href="files.html"><span>Files</span></a></li>
    <li><a href="pages.html"><span>Related&nbsp;Pages</span></a></li>
  </ul></div>
<div class="tabs">
  <ul>
    <li><a href="files.html"><span>File&nbsp;List</span></a></li>
    <li><a href="globals.html"><span>File&nbsp;Members</span></a></li>
  </ul></div>
<h1>main.cc</h1><a href="main_8cc.html">Go to the documentation of this file.</a><div class="fragment"><pre class="fragment"><a name="l00001"></a>00001 
<a name="l00020"></a>00020 <span class="preprocessor">#include &lt;iostream&gt;</span>
<a name="l00021"></a>00021 
<a name="l00022"></a>00022 <span class="preprocessor">#ifdef _SUNOS</span>
<a name="l00023"></a>00023 <span class="preprocessor"></span><span class="preprocessor">#include "/home/common/dyd/aisdi/z4/TreeMap.h"</span>
<a name="l00024"></a>00024 <span class="preprocessor">#else</span>
<a name="l00025"></a>00025 <span class="preprocessor"></span><span class="preprocessor">#include "<a class="code" href="_tree_map_8h.html">TreeMap.h</a>"</span>
<a name="l00026"></a>00026 <span class="preprocessor">#endif</span>
<a name="l00027"></a>00027 <span class="preprocessor"></span>
<a name="l00028"></a>00028 <span class="keywordtype">int</span> <a class="code" href="class_c_count.html#e2942a04780e223b215eb8b663cf5353">CCount::count</a>=0;
<a name="l00029"></a>00029 
<a name="l00030"></a>00030 <span class="keywordtype">int</span> <a class="code" href="main_8cc.html#da006f4ed56183a923cadf4bc85ce457">Test2</a>();
<a name="l00031"></a>00031 <span class="keywordtype">void</span> <a class="code" href="asd_8cc.html#5af26b3a0b1f8425bfcd62bcfe8991cc">test</a>();
<a name="l00032"></a>00032 
<a name="l00033"></a><a class="code" href="main_8cc.html#ea83b916b3f52eec32ae6d54d59b4453">00033</a> <span class="keywordtype">int</span> <a class="code" href="main_8cc.html#ea83b916b3f52eec32ae6d54d59b4453">main</a>()
<a name="l00034"></a>00034 {
<a name="l00035"></a>00035    std::cout &lt;&lt; <span class="stringliteral">"AISDI cwiczenie 4: wchodze do funkcji main."</span> &lt;&lt; std::endl;
<a name="l00036"></a>00036    <a class="code" href="asd_8cc.html#5af26b3a0b1f8425bfcd62bcfe8991cc">test</a>();
<a name="l00037"></a>00037    <span class="comment">// Biblioteka z bardziej rygorystyczna wersja tych testow bedzie udostepniona na nastepnych zajeciach.</span>
<a name="l00038"></a>00038    <a class="code" href="main_8cc.html#da006f4ed56183a923cadf4bc85ce457">Test2</a>();
<a name="l00039"></a>00039    <span class="comment">//system("PAUSE");</span>
<a name="l00040"></a>00040    <span class="keywordflow">return</span> EXIT_SUCCESS;
<a name="l00041"></a>00041 }
</pre></div><hr size="1"><address style="align: right;"><small>Generated on Fri Dec 2 01:03:51 2005 for AISDI Cwiczenie 4 by&nbsp;
<a href="http://www.doxygen.org/index.html">
<img src="doxygen.png" alt="doxygen" align="middle" border="0"></a> 1.4.5 </small></address>
</body>
</html>
                                                                                                                       tree/info/pages.html                                                                                0100644 0003673 0000144 00000002103 11704031107 0015644 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html><head><meta http-equiv="Content-Type" content="text/html;charset=iso-8859-1">
<title>AISDI Cwiczenie 4: Page Index</title>
<link href="doxygen.css" rel="stylesheet" type="text/css">
<link href="tabs.css" rel="stylesheet" type="text/css">
</head><body>
<!-- Generated by Doxygen 1.4.5 -->
<div class="tabs">
  <ul>
    <li><a href="index.html"><span>Main&nbsp;Page</span></a></li>
    <li><a href="annotated.html"><span>Classes</span></a></li>
    <li><a href="files.html"><span>Files</span></a></li>
    <li id="current"><a href="pages.html"><span>Related&nbsp;Pages</span></a></li>
  </ul></div>
<h1>AISDI Cwiczenie 4 Related Pages</h1>Here is a list of all related documentation pages:<ul>
<li><a class="el" href="todo.html">Todo List</a>

</ul>
<hr size="1"><address style="align: right;"><small>Generated on Fri Dec 2 01:03:52 2005 for AISDI Cwiczenie 4 by&nbsp;
<a href="http://www.doxygen.org/index.html">
<img src="doxygen.png" alt="doxygen" align="middle" border="0"></a> 1.4.5 </small></address>
</body>
</html>
                                                                                                                                                                                                                                                                                                                                                                                                                                                             tree/info/struct_tree_node.html                                                                     0100644 0003673 0000144 00000046223 11704031107 0020130 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html><head><meta http-equiv="Content-Type" content="text/html;charset=iso-8859-1">
<title>AISDI Cwiczenie 4: TreeNode Struct Reference</title>
<link href="doxygen.css" rel="stylesheet" type="text/css">
<link href="tabs.css" rel="stylesheet" type="text/css">
</head><body>
<!-- Generated by Doxygen 1.4.5 -->
<div class="tabs">
  <ul>
    <li><a href="index.html"><span>Main&nbsp;Page</span></a></li>
    <li id="current"><a href="annotated.html"><span>Classes</span></a></li>
    <li><a href="files.html"><span>Files</span></a></li>
    <li><a href="pages.html"><span>Related&nbsp;Pages</span></a></li>
  </ul></div>
<div class="tabs">
  <ul>
    <li><a href="annotated.html"><span>Class&nbsp;List</span></a></li>
    <li><a href="classes.html"><span>Alphabetical&nbsp;List</span></a></li>
    <li><a href="hierarchy.html"><span>Class&nbsp;Hierarchy</span></a></li>
    <li><a href="functions.html"><span>Class&nbsp;Members</span></a></li>
  </ul></div>
<h1>TreeNode Struct Reference</h1><!-- doxytag: class="TreeNode" --><!-- doxytag: inherits="CCount" -->A class to package the data into so it has the left and right hook for the tree.  
<a href="#_details">More...</a>
<p>
<code>#include &lt;<a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>&gt;</code>
<p>
Inherits <a class="el" href="class_c_count.html">CCount</a>.
<p>
Inheritance diagram for TreeNode:<p><center><img src="struct_tree_node__inherit__graph.png" border="0" usemap="#_tree_node__inherit__map" alt="Inheritance graph"></center>
<map name="_tree_node__inherit__map">
<area href="class_c_count.html" shape="rect" coords="13,7,80,34" alt="">
</map>
<center><font size="2">[<a href="graph_legend.html">legend</a>]</font></center>Collaboration diagram for TreeNode:<p><center><img src="struct_tree_node__coll__graph.png" border="0" usemap="#_tree_node__coll__map" alt="Collaboration graph"></center>
<map name="_tree_node__coll__map">
<area href="class_c_count.html" shape="rect" coords="9,97,76,124" alt="">
</map>
<center><font size="2">[<a href="graph_legend.html">legend</a>]</font></center><a href="struct_tree_node-members.html">List of all members.</a><table border="0" cellpadding="0" cellspacing="0">
<tr><td></td></tr>
<tr><td colspan="2"><br><h2>Public Types</h2></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top">typedef std::pair&lt; int, std::string &gt;&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="struct_tree_node.html#b9ece18c950afbfa6b0fdbfa4ff731d3">T</a></td></tr>

<tr><td colspan="2"><br><h2>Public Member Functions</h2></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top">&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="struct_tree_node.html#1771ccd0efaf3c15a4bf549833e92049">TreeNode</a> (const <a class="el" href="struct_tree_node.html#b9ece18c950afbfa6b0fdbfa4ff731d3">T</a> &amp;d)</td></tr>

<tr><td class="memItemLeft" nowrap align="right" valign="top">&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="struct_tree_node.html#f80e9a2626343d444a53e15fd94e5bf3">TreeNode</a> (const <a class="el" href="struct_tree_node.html#b9ece18c950afbfa6b0fdbfa4ff731d3">T</a> &amp;d, <a class="el" href="struct_tree_node.html">TreeNode</a> *l, <a class="el" href="struct_tree_node.html">TreeNode</a> *r)</td></tr>

<tr><td class="memItemLeft" nowrap align="right" valign="top">&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="struct_tree_node.html#9c2276854bef51bd201e5d87b7557c23">TreeNode</a> (const <a class="el" href="struct_tree_node.html#b9ece18c950afbfa6b0fdbfa4ff731d3">T</a> &amp;d, <a class="el" href="struct_tree_node.html">TreeNode</a> *p)</td></tr>

<tr><td class="memItemLeft" nowrap align="right" valign="top">&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="struct_tree_node.html#d8a9895b7d52ea3650148d93a1d132ce">TreeNode</a> (const <a class="el" href="struct_tree_node.html#b9ece18c950afbfa6b0fdbfa4ff731d3">T</a> &amp;d, <a class="el" href="struct_tree_node.html">TreeNode</a> *p, <a class="el" href="struct_tree_node.html">TreeNode</a> *l, <a class="el" href="struct_tree_node.html">TreeNode</a> *r)</td></tr>

<tr><td colspan="2"><br><h2>Static Public Member Functions</h2></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top">static int&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="class_c_count.html#68b1e82502beaa137b00477d034627d5">getCount</a> ()</td></tr>

<tr><td class="mdescLeft">&nbsp;</td><td class="mdescRight">A public method for getting the count.  <a href="#68b1e82502beaa137b00477d034627d5"></a><br></td></tr>
<tr><td colspan="2"><br><h2>Public Attributes</h2></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top"><a class="el" href="struct_tree_node.html">TreeNode</a> *&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="struct_tree_node.html#d0e45878043844ffc41aac437e86b602">parent</a></td></tr>

<tr><td class="mdescLeft">&nbsp;</td><td class="mdescRight">Parent node.  <a href="#d0e45878043844ffc41aac437e86b602"></a><br></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top"><a class="el" href="struct_tree_node.html">TreeNode</a> *&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="struct_tree_node.html#811882fecd5c7618d7099ebbd39ea254">left</a></td></tr>

<tr><td class="mdescLeft">&nbsp;</td><td class="mdescRight">The left child in the tree.  <a href="#811882fecd5c7618d7099ebbd39ea254"></a><br></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top"><a class="el" href="struct_tree_node.html">TreeNode</a> *&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="struct_tree_node.html#7c4f29407893c334a6cb7a87bf045c0d">right</a></td></tr>

<tr><td class="mdescLeft">&nbsp;</td><td class="mdescRight">The right child in the tree.  <a href="#7c4f29407893c334a6cb7a87bf045c0d"></a><br></td></tr>
<tr><td class="memItemLeft" nowrap align="right" valign="top"><a class="el" href="struct_tree_node.html#b9ece18c950afbfa6b0fdbfa4ff731d3">T</a>&nbsp;</td><td class="memItemRight" valign="bottom"><a class="el" href="struct_tree_node.html#8d777f385d3dfec8815d20f7496026dc">data</a></td></tr>

<tr><td class="mdescLeft">&nbsp;</td><td class="mdescRight">User's data.  <a href="#8d777f385d3dfec8815d20f7496026dc"></a><br></td></tr>
</table>
<hr><a name="_details"></a><h2>Detailed Description</h2>
A class to package the data into so it has the left and right hook for the tree. 
<p>

<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00062">62</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.<hr><h2>Member Typedef Documentation</h2>
<a class="anchor" name="b9ece18c950afbfa6b0fdbfa4ff731d3"></a><!-- doxytag: member="TreeNode::T" ref="b9ece18c950afbfa6b0fdbfa4ff731d3" args="" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">typedef std::pair&lt;int,std::string&gt; <a class="el" href="struct_tree_node.html#b9ece18c950afbfa6b0fdbfa4ff731d3">TreeNode::T</a>          </td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>

<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00064">64</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.    </td>
  </tr>
</table>
<hr><h2>Constructor &amp; Destructor Documentation</h2>
<a class="anchor" name="1771ccd0efaf3c15a4bf549833e92049"></a><!-- doxytag: member="TreeNode::TreeNode" ref="1771ccd0efaf3c15a4bf549833e92049" args="(const T &amp;d)" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">TreeNode::TreeNode           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="md" nowrap valign="top">const <a class="el" href="struct_tree_node.html#b9ece18c950afbfa6b0fdbfa4ff731d3">T</a> &amp;&nbsp;</td>
          <td class="mdname1" valign="top" nowrap> <em>d</em>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap><code> [inline]</code></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>

<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00069">69</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.    </td>
  </tr>
</table>
<a class="anchor" name="f80e9a2626343d444a53e15fd94e5bf3"></a><!-- doxytag: member="TreeNode::TreeNode" ref="f80e9a2626343d444a53e15fd94e5bf3" args="(const T &amp;d, TreeNode *l, TreeNode *r)" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">TreeNode::TreeNode           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="md" nowrap valign="top">const <a class="el" href="struct_tree_node.html#b9ece18c950afbfa6b0fdbfa4ff731d3">T</a> &amp;&nbsp;</td>
          <td class="mdname" nowrap> <em>d</em>, </td>
        </tr>
        <tr>
          <td class="md" nowrap align="right"></td>
          <td class="md"></td>
          <td class="md" nowrap><a class="el" href="struct_tree_node.html">TreeNode</a> *&nbsp;</td>
          <td class="mdname" nowrap> <em>l</em>, </td>
        </tr>
        <tr>
          <td class="md" nowrap align="right"></td>
          <td class="md"></td>
          <td class="md" nowrap><a class="el" href="struct_tree_node.html">TreeNode</a> *&nbsp;</td>
          <td class="mdname" nowrap> <em>r</em></td>
        </tr>
        <tr>
          <td class="md"></td>
          <td class="md">)&nbsp;</td>
          <td class="md" colspan="2"><code> [inline]</code></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>

<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00070">70</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.    </td>
  </tr>
</table>
<a class="anchor" name="9c2276854bef51bd201e5d87b7557c23"></a><!-- doxytag: member="TreeNode::TreeNode" ref="9c2276854bef51bd201e5d87b7557c23" args="(const T &amp;d, TreeNode *p)" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">TreeNode::TreeNode           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="md" nowrap valign="top">const <a class="el" href="struct_tree_node.html#b9ece18c950afbfa6b0fdbfa4ff731d3">T</a> &amp;&nbsp;</td>
          <td class="mdname" nowrap> <em>d</em>, </td>
        </tr>
        <tr>
          <td class="md" nowrap align="right"></td>
          <td class="md"></td>
          <td class="md" nowrap><a class="el" href="struct_tree_node.html">TreeNode</a> *&nbsp;</td>
          <td class="mdname" nowrap> <em>p</em></td>
        </tr>
        <tr>
          <td class="md"></td>
          <td class="md">)&nbsp;</td>
          <td class="md" colspan="2"><code> [inline]</code></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>

<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00071">71</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.    </td>
  </tr>
</table>
<a class="anchor" name="d8a9895b7d52ea3650148d93a1d132ce"></a><!-- doxytag: member="TreeNode::TreeNode" ref="d8a9895b7d52ea3650148d93a1d132ce" args="(const T &amp;d, TreeNode *p, TreeNode *l, TreeNode *r)" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">TreeNode::TreeNode           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="md" nowrap valign="top">const <a class="el" href="struct_tree_node.html#b9ece18c950afbfa6b0fdbfa4ff731d3">T</a> &amp;&nbsp;</td>
          <td class="mdname" nowrap> <em>d</em>, </td>
        </tr>
        <tr>
          <td class="md" nowrap align="right"></td>
          <td class="md"></td>
          <td class="md" nowrap><a class="el" href="struct_tree_node.html">TreeNode</a> *&nbsp;</td>
          <td class="mdname" nowrap> <em>p</em>, </td>
        </tr>
        <tr>
          <td class="md" nowrap align="right"></td>
          <td class="md"></td>
          <td class="md" nowrap><a class="el" href="struct_tree_node.html">TreeNode</a> *&nbsp;</td>
          <td class="mdname" nowrap> <em>l</em>, </td>
        </tr>
        <tr>
          <td class="md" nowrap align="right"></td>
          <td class="md"></td>
          <td class="md" nowrap><a class="el" href="struct_tree_node.html">TreeNode</a> *&nbsp;</td>
          <td class="mdname" nowrap> <em>r</em></td>
        </tr>
        <tr>
          <td class="md"></td>
          <td class="md">)&nbsp;</td>
          <td class="md" colspan="2"><code> [inline]</code></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>

<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00072">72</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.    </td>
  </tr>
</table>
<hr><h2>Member Function Documentation</h2>
<a class="anchor" name="68b1e82502beaa137b00477d034627d5"></a><!-- doxytag: member="TreeNode::getCount" ref="68b1e82502beaa137b00477d034627d5" args="()" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top">static int CCount::getCount           </td>
          <td class="md" valign="top">(&nbsp;</td>
          <td class="mdname1" valign="top" nowrap>          </td>
          <td class="md" valign="top">&nbsp;)&nbsp;</td>
          <td class="md" nowrap><code> [inline, static, inherited]</code></td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>
A public method for getting the count. 
<p>

<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00054">54</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.
<p>
References <a class="el" href="_tree_map_8h-source.html#l00040">CCount::count</a>.    </td>
  </tr>
</table>
<hr><h2>Member Data Documentation</h2>
<a class="anchor" name="8d777f385d3dfec8815d20f7496026dc"></a><!-- doxytag: member="TreeNode::data" ref="8d777f385d3dfec8815d20f7496026dc" args="" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top"><a class="el" href="struct_tree_node.html#b9ece18c950afbfa6b0fdbfa4ff731d3">T</a> <a class="el" href="struct_tree_node.html#8d777f385d3dfec8815d20f7496026dc">TreeNode::data</a>          </td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>
User's data. 
<p>

<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00068">68</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.
<p>
Referenced by <a class="el" href="_tree_map_8h-source.html#l00155">TreeMap::iterator::operator *()</a>, <a class="el" href="_tree_map_8h-source.html#l00114">TreeMap::const_iterator::operator *()</a>, <a class="el" href="_tree_map_8h-source.html#l00159">TreeMap::iterator::operator-&gt;()</a>, and <a class="el" href="_tree_map_8h-source.html#l00119">TreeMap::const_iterator::operator-&gt;()</a>.    </td>
  </tr>
</table>
<a class="anchor" name="811882fecd5c7618d7099ebbd39ea254"></a><!-- doxytag: member="TreeNode::left" ref="811882fecd5c7618d7099ebbd39ea254" args="" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top"><a class="el" href="struct_tree_node.html">TreeNode</a>* <a class="el" href="struct_tree_node.html#811882fecd5c7618d7099ebbd39ea254">TreeNode::left</a>          </td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>
The left child in the tree. 
<p>

<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00066">66</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.    </td>
  </tr>
</table>
<a class="anchor" name="d0e45878043844ffc41aac437e86b602"></a><!-- doxytag: member="TreeNode::parent" ref="d0e45878043844ffc41aac437e86b602" args="" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top"><a class="el" href="struct_tree_node.html">TreeNode</a>* <a class="el" href="struct_tree_node.html#d0e45878043844ffc41aac437e86b602">TreeNode::parent</a>          </td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>
Parent node. 
<p>

<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00065">65</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.    </td>
  </tr>
</table>
<a class="anchor" name="7c4f29407893c334a6cb7a87bf045c0d"></a><!-- doxytag: member="TreeNode::right" ref="7c4f29407893c334a6cb7a87bf045c0d" args="" --><p>
<table class="mdTable" cellpadding="2" cellspacing="0">
  <tr>
    <td class="mdRow">
      <table cellpadding="0" cellspacing="0" border="0">
        <tr>
          <td class="md" nowrap valign="top"><a class="el" href="struct_tree_node.html">TreeNode</a>* <a class="el" href="struct_tree_node.html#7c4f29407893c334a6cb7a87bf045c0d">TreeNode::right</a>          </td>
        </tr>
      </table>
    </td>
  </tr>
</table>
<table cellspacing="5" cellpadding="0" border="0">
  <tr>
    <td>
      &nbsp;
    </td>
    <td>

<p>
The right child in the tree. 
<p>

<p>
Definition at line <a class="el" href="_tree_map_8h-source.html#l00067">67</a> of file <a class="el" href="_tree_map_8h-source.html">TreeMap.h</a>.    </td>
  </tr>
</table>
<hr>The documentation for this struct was generated from the following file:<ul>
<li><a class="el" href="_tree_map_8h-source.html">TreeMap.h</a></ul>
<hr size="1"><address style="align: right;"><small>Generated on Fri Dec 2 01:03:51 2005 for AISDI Cwiczenie 4 by&nbsp;
<a href="http://www.doxygen.org/index.html">
<img src="doxygen.png" alt="doxygen" align="middle" border="0"></a> 1.4.5 </small></address>
</body>
</html>
 <a class="el" href="struct_tree_node.html#b9ece18c950afbfa6b0fdbfa4ff731d3">T</a> &amp;&nbsp;</td>
          <td class="mdname" nowrap> <em>d</em>, </td>
        </tr>
        <tr>
          <td class="md" nowrap align="right"></td>
          <td class="md"></td>
          <td class="md" nowrap><a class="el" href="struct_tree_node.html">TreeNode</a> *&nbsp;</td>tree/info/todo.html                                                                                 0100644 0003673 0000144 00000014004 11704031107 0015515 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html><head><meta http-equiv="Content-Type" content="text/html;charset=iso-8859-1">
<title>AISDI Cwiczenie 4: Todo List</title>
<link href="doxygen.css" rel="stylesheet" type="text/css">
<link href="tabs.css" rel="stylesheet" type="text/css">
</head><body>
<!-- Generated by Doxygen 1.4.5 -->
<div class="tabs">
  <ul>
    <li><a href="index.html"><span>Main&nbsp;Page</span></a></li>
    <li><a href="annotated.html"><span>Classes</span></a></li>
    <li><a href="files.html"><span>Files</span></a></li>
    <li><a href="pages.html"><span>Related&nbsp;Pages</span></a></li>
  </ul></div>
<h1><a class="anchor" name="todo">Todo List</a></h1><a class="anchor" name="_todo000001"></a> <dl>
<dt>Member <a class="el" href="class_tree_map.html#36057872ebdcdb89755ff678ad8a5179">TreeMap::TreeMap</a> (const <a class="el" href="class_tree_map.html">TreeMap</a> &amp;) </dt>
<dd>Implement this</dd>
</dl>
<p>
<a class="anchor" name="_todo000021"></a> <dl>
<dt>Member <a class="el" href="class_tree_map.html#6c34e3a8894af3a2160a3c0baa7e6fad">TreeMap::begin</a> () const  </dt>
<dd>Implement this</dd>
</dl>
<p>
<a class="anchor" name="_todo000020"></a> <dl>
<dt>Member <a class="el" href="class_tree_map.html#4b1a01a7db76e79c6194363c78d33615">TreeMap::begin</a> () </dt>
<dd>Implement this</dd>
</dl>
<p>
<a class="anchor" name="_todo000012"></a> <dl>
<dt>Member <a class="el" href="class_tree_map.html#3616b8000a015689fed4b46c19c06ea2">TreeMap::clear</a> () </dt>
<dd>Implement this</dd>
</dl>
<p>
<a class="anchor" name="_todo000008"></a> <dl>
<dt>Member <a class="el" href="class_tree_map.html#1d79deabb6ad2a93ef5358356055ee3b">TreeMap::count</a> (const Key &amp;_Key) const  </dt>
<dd>Implement this</dd>
</dl>
<p>
<a class="anchor" name="_todo000023"></a> <dl>
<dt>Member <a class="el" href="class_tree_map.html#37d6974af8ee6af64f7b4f71330853cb">TreeMap::end</a> () const  </dt>
<dd>Implement this</dd>
</dl>
<p>
<a class="anchor" name="_todo000022"></a> <dl>
<dt>Member <a class="el" href="class_tree_map.html#f34c4b013e5d012ab5f1bfef486d630f">TreeMap::end</a> () </dt>
<dd>Implement this</dd>
</dl>
<p>
<a class="anchor" name="_todo000011"></a> <dl>
<dt>Member <a class="el" href="class_tree_map.html#f768666a08bb3f9bf6d59af014dc8a79">TreeMap::erase</a> (const Key &amp;key) </dt>
<dd>Implement this</dd>
</dl>
<p>
<a class="anchor" name="_todo000010"></a> <dl>
<dt>Member <a class="el" href="class_tree_map.html#4c750f4eb7c25898376b2945bceb60a3">TreeMap::erase</a> (iterator first, iterator last) </dt>
<dd>Implement this</dd>
</dl>
<p>
<a class="anchor" name="_todo000009"></a> <dl>
<dt>Member <a class="el" href="class_tree_map.html#99d178e178a2d0a71c1f5698c5879dcf">TreeMap::erase</a> (iterator i) </dt>
<dd>Implement this</dd>
</dl>
<p>
<a class="anchor" name="_todo000005"></a> <dl>
<dt>Member <a class="el" href="class_tree_map.html#732153e7bc56dacafa2411864b548219">TreeMap::find</a> (const Key &amp;k) const  </dt>
<dd>Implement this</dd>
</dl>
<p>
<a class="anchor" name="_todo000004"></a> <dl>
<dt>Member <a class="el" href="class_tree_map.html#da5bc54e6c1da79235e9160ee021b9f5">TreeMap::find</a> (const Key &amp;k) </dt>
<dd>Implement this</dd>
</dl>
<p>
<a class="anchor" name="_todo000014"></a> <dl>
<dt>Member <a class="el" href="class_tree_map.html#68dd925067e3812184dcedea9211ac4b">TreeMap::info_eq</a> (const <a class="el" href="class_tree_map.html">TreeMap</a> &amp;another) const  </dt>
<dd>Implement this</dd>
</dl>
<p>
<a class="anchor" name="_todo000002"></a> <dl>
<dt>Member <a class="el" href="class_tree_map.html#94500a970d082e87b838a94fed333521">TreeMap::insert</a> (const std::pair&lt; Key, Val &gt; &amp;entry) </dt>
<dd>Finnish this</dd>
</dl>
<p>
<a class="anchor" name="_todo000019"></a> <dl>
<dt>Member <a class="el" href="class_tree_map.html#48753429045577c544d7b1765997223e">TreeMap::operator=</a> (const <a class="el" href="class_tree_map.html">TreeMap</a> &amp;) </dt>
<dd>Implement this</dd>
</dl>
<p>
<a class="anchor" name="_todo000006"></a> <dl>
<dt>Member <a class="el" href="class_tree_map.html#ce20a84b60c9bcce43c37cb75d29fe50">TreeMap::operator[]</a> (const Key &amp;k) </dt>
<dd>Implement this</dd>
</dl>
<p>
<a class="anchor" name="_todo000007"></a> <dl>
<dt>Member <a class="el" href="class_tree_map.html#5a9421972c178b3c37b99f953470c6f6">TreeMap::size</a> () const  </dt>
<dd>Implement this</dd>
</dl>
<p>
<a class="anchor" name="_todo000013"></a> <dl>
<dt>Member <a class="el" href="class_tree_map.html#e62bc2a78904e459d5f302a5ff48769a">TreeMap::struct_eq</a> (const <a class="el" href="class_tree_map.html">TreeMap</a> &amp;another) const  </dt>
<dd>Implement this</dd>
</dl>
<p>
<a class="anchor" name="_todo000003"></a> <dl>
<dt>Member <a class="el" href="class_tree_map.html#9b42b72518de2845832b80e44424fab3">TreeMap::unsafe_insert</a> (const std::pair&lt; Key, Val &gt; &amp;entry) </dt>
<dd>Finnish this</dd>
</dl>
<p>
<a class="anchor" name="_todo000016"></a> <dl>
<dt>Member <a class="el" href="class_tree_map_1_1const__iterator.html#5d4681e027a07e3fb51ab21bef0dcc3d">TreeMap::const_iterator::operator++</a> (int) </dt>
<dd>Implement this</dd>
</dl>
<p>
<a class="anchor" name="_todo000015"></a> <dl>
<dt>Member <a class="el" href="class_tree_map_1_1const__iterator.html#879fb570af328b721ed45fe254b0a582">TreeMap::const_iterator::operator++</a> () </dt>
<dd>Implement this</dd>
</dl>
<p>
<a class="anchor" name="_todo000018"></a> <dl>
<dt>Member <a class="el" href="class_tree_map_1_1const__iterator.html#12332c0f3ca9f1be40bf725d24d260ef">TreeMap::const_iterator::operator--</a> (int) </dt>
<dd>Implement this</dd>
</dl>
<p>
<a class="anchor" name="_todo000017"></a> <dl>
<dt>Member <a class="el" href="class_tree_map_1_1const__iterator.html#08e169f7d9d8a763281a98d478c20a02">TreeMap::const_iterator::operator--</a> () </dt>
<dd>Implement this</dd>
</dl>
<hr size="1"><address style="align: right;"><small>Generated on Fri Dec 2 01:03:52 2005 for AISDI Cwiczenie 4 by&nbsp;
<a href="http://www.doxygen.org/index.html">
<img src="doxygen.png" alt="doxygen" align="middle" border="0"></a> 1.4.5 </small></address>
</body>
</html>
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            tree/info/struct_tree_node-members.html                                                             0100644 0003673 0000144 00000007136 11704031107 0021560 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html><head><meta http-equiv="Content-Type" content="text/html;charset=iso-8859-1">
<title>AISDI Cwiczenie 4: Member List</title>
<link href="doxygen.css" rel="stylesheet" type="text/css">
<link href="tabs.css" rel="stylesheet" type="text/css">
</head><body>
<!-- Generated by Doxygen 1.4.5 -->
<div class="tabs">
  <ul>
    <li><a href="index.html"><span>Main&nbsp;Page</span></a></li>
    <li id="current"><a href="annotated.html"><span>Classes</span></a></li>
    <li><a href="files.html"><span>Files</span></a></li>
    <li><a href="pages.html"><span>Related&nbsp;Pages</span></a></li>
  </ul></div>
<div class="tabs">
  <ul>
    <li><a href="annotated.html"><span>Class&nbsp;List</span></a></li>
    <li><a href="classes.html"><span>Alphabetical&nbsp;List</span></a></li>
    <li><a href="hierarchy.html"><span>Class&nbsp;Hierarchy</span></a></li>
    <li><a href="functions.html"><span>Class&nbsp;Members</span></a></li>
  </ul></div>
<h1>TreeNode Member List</h1>This is the complete list of members for <a class="el" href="struct_tree_node.html">TreeNode</a>, including all inherited members.<p><table>
  <tr class="memlist"><td><a class="el" href="struct_tree_node.html#8d777f385d3dfec8815d20f7496026dc">data</a></td><td><a class="el" href="struct_tree_node.html">TreeNode</a></td><td></td></tr>
  <tr class="memlist"><td><a class="el" href="class_c_count.html#68b1e82502beaa137b00477d034627d5">getCount</a>()</td><td><a class="el" href="class_c_count.html">CCount</a></td><td><code> [inline, static]</code></td></tr>
  <tr class="memlist"><td><a class="el" href="struct_tree_node.html#811882fecd5c7618d7099ebbd39ea254">left</a></td><td><a class="el" href="struct_tree_node.html">TreeNode</a></td><td></td></tr>
  <tr class="memlist"><td><a class="el" href="struct_tree_node.html#d0e45878043844ffc41aac437e86b602">parent</a></td><td><a class="el" href="struct_tree_node.html">TreeNode</a></td><td></td></tr>
  <tr class="memlist"><td><a class="el" href="struct_tree_node.html#7c4f29407893c334a6cb7a87bf045c0d">right</a></td><td><a class="el" href="struct_tree_node.html">TreeNode</a></td><td></td></tr>
  <tr class="memlist"><td><a class="el" href="struct_tree_node.html#b9ece18c950afbfa6b0fdbfa4ff731d3">T</a> typedef</td><td><a class="el" href="struct_tree_node.html">TreeNode</a></td><td></td></tr>
  <tr class="memlist"><td><a class="el" href="struct_tree_node.html#1771ccd0efaf3c15a4bf549833e92049">TreeNode</a>(const T &amp;d)</td><td><a class="el" href="struct_tree_node.html">TreeNode</a></td><td><code> [inline]</code></td></tr>
  <tr class="memlist"><td><a class="el" href="struct_tree_node.html#f80e9a2626343d444a53e15fd94e5bf3">TreeNode</a>(const T &amp;d, TreeNode *l, TreeNode *r)</td><td><a class="el" href="struct_tree_node.html">TreeNode</a></td><td><code> [inline]</code></td></tr>
  <tr class="memlist"><td><a class="el" href="struct_tree_node.html#9c2276854bef51bd201e5d87b7557c23">TreeNode</a>(const T &amp;d, TreeNode *p)</td><td><a class="el" href="struct_tree_node.html">TreeNode</a></td><td><code> [inline]</code></td></tr>
  <tr class="memlist"><td><a class="el" href="struct_tree_node.html#d8a9895b7d52ea3650148d93a1d132ce">TreeNode</a>(const T &amp;d, TreeNode *p, TreeNode *l, TreeNode *r)</td><td><a class="el" href="struct_tree_node.html">TreeNode</a></td><td><code> [inline]</code></td></tr>
</table><hr size="1"><address style="align: right;"><small>Generated on Fri Dec 2 01:03:52 2005 for AISDI Cwiczenie 4 by&nbsp;
<a href="http://www.doxygen.org/index.html">
<img src="doxygen.png" alt="doxygen" align="middle" border="0"></a> 1.4.5 </small></address>
</body>
</html>
                                                                                                                                                                                                                                                                                                                                                                                                                                  tree/info/_tree_map_8h__dep__incl.md5                                                               0100644 0003673 0000144 00000000040 11704031107 0020751 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        3ce2df0d4ebf51e52fcd659b4a45b174                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                tree/info/_tree_map_8h__incl.md5                                                                    0100644 0003673 0000144 00000000040 11704031107 0017762 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        f76190c432cb275daeec9d7fbba06bdd                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                tree/info/asd_8cc__incl.md5                                                                         0100644 0003673 0000144 00000000040 11704031107 0016734 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        33338ca5b0439fad50db192c9b7241f1                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                tree/info/class_c_count__coll__graph.md5                                                            0100644 0003673 0000144 00000000040 11704031107 0021573 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        25528361521f64b4d7130e00813d3ffa                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                tree/info/class_c_count__inherit__graph.md5                                                         0100644 0003673 0000144 00000000040 11704031107 0022304 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        7380842dabb5b3275a5ab4c3eb5ad07f                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                tree/info/class_tree_map__coll__graph.md5                                                           0100644 0003673 0000144 00000000040 11704031107 0021735 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        70bfbf32b49495888e39eff91aca9bf4                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                tree/info/class_tree_map_1_1const__iterator__coll__graph.md5                                        0100644 0003673 0000144 00000000040 11704031107 0025514 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        a121af670d426275a6c7a2a90856f88a                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                tree/info/class_tree_map_1_1const__iterator__inherit__graph.md5                                     0100644 0003673 0000144 00000000040 11704031107 0026225 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        edf488b9516366e575c8bee1d5b9e4b1                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                tree/info/class_tree_map_1_1iterator__coll__graph.md5                                               0100644 0003673 0000144 00000000040 11704031107 0024147 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        1e1b0f6063aa288565d64351028cb629                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                tree/info/class_tree_map_1_1iterator__inherit__graph.md5                                            0100644 0003673 0000144 00000000040 11704031107 0024660 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        be6f4f98887d58e3c0103cc65428d5aa                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                tree/info/classbasic__wfstream__inherit__graph.md5                                                  0100644 0003673 0000144 00000000040 11704031107 0023643 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        d2668aa07e666670070c69b18fd1adad                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                tree/info/classstd_1_1iterator__inherit__graph.md5                                                  0100644 0003673 0000144 00000000040 11704031107 0023517 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        61d522c6b384b34abeee8c0939da34bb                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                tree/info/inherit__graph__0.md5                                                                     0100644 0003673 0000144 00000000040 11704031107 0017624 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        29b57073723a25aecc9c18bb9a08a08a                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                tree/info/inherit__graph__1.md5                                                                     0100644 0003673 0000144 00000000040 11704031107 0017625 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        16d5e89ea0592af7c3ae2e33526c75c6                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                tree/info/inherit__graph__2.md5                                                                     0100644 0003673 0000144 00000000040 11704031107 0017626 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        f9439b6f9e3ed9f04f0eac7e94c3e795                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                tree/info/inherit__graph__3.md5                                                                     0100644 0003673 0000144 00000000040 11704031107 0017627 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        aec3218b1730417dece30d0bf62540d7                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                tree/info/inherit__graph__4.md5                                                                     0100644 0003673 0000144 00000000040 11704031107 0017630 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        291744c21f9449336ab6bf240fa67635                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                tree/info/main_8cc__incl.md5                                                                        0100644 0003673 0000144 00000000040 11704031107 0017111 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        59cd038ca7a7f88ab8425a239cd5e840                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                tree/info/struct_tree_node__coll__graph.md5                                                         0100644 0003673 0000144 00000000040 11704031110 0022316 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        1e711e26c710ecf66fa5ade10fb0d1b6                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                tree/info/struct_tree_node__inherit__graph.md5                                                      0100644 0003673 0000144 00000000040 11704031110 0023027 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        61fd59adc01476d6752c045efca10128                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                tree/info/graph_legend.dot                                                                          0100644 0003673 0000144 00000004205 11704031110 0017005 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        digraph G
{
  edge [fontname="Helvetica",fontsize=10,labelfontname="Helvetica",labelfontsize=10];
  node [fontname="Helvetica",fontsize=10,shape=record];
  Node9 [shape="box",label="Inherited",fontsize=10,height=0.2,width=0.4,fontname="Helvetica",color="black",style="filled" fontcolor="white"];
  Node10 -> Node9 [dir=back,color="midnightblue",fontsize=10,style="solid",fontname="Helvetica"];
  Node10 [shape="box",label="PublicBase",fontsize=10,height=0.2,width=0.4,fontname="Helvetica",color="black",URL="$classPublicBase.html"];
  Node11 -> Node10 [dir=back,color="midnightblue",fontsize=10,style="solid",fontname="Helvetica"];
  Node11 [shape="box",label="Truncated",fontsize=10,height=0.2,width=0.4,fontname="Helvetica",color="red",URL="$classTruncated.html"];
  Node13 -> Node9 [dir=back,color="darkgreen",fontsize=10,style="solid",fontname="Helvetica"];
  Node13 [shape="box",label="ProtectedBase",fontsize=10,height=0.2,width=0.4,fontname="Helvetica",color="black",URL="$classProtectedBase.html"];
  Node14 -> Node9 [dir=back,color="firebrick4",fontsize=10,style="solid",fontname="Helvetica"];
  Node14 [shape="box",label="PrivateBase",fontsize=10,height=0.2,width=0.4,fontname="Helvetica",color="black",URL="$classPrivateBase.html"];
  Node15 -> Node9 [dir=back,color="midnightblue",fontsize=10,style="solid",fontname="Helvetica"];
  Node15 [shape="box",label="Undocumented",fontsize=10,height=0.2,width=0.4,fontname="Helvetica",color="grey75"];
  Node16 -> Node9 [dir=back,color="midnightblue",fontsize=10,style="solid",fontname="Helvetica"];
  Node16 [shape="box",label="Templ< int >",fontsize=10,height=0.2,width=0.4,fontname="Helvetica",color="black",URL="$classTempl.html"];
  Node17 -> Node16 [dir=back,color="orange",fontsize=10,style="dashed",label="< int >",fontname="Helvetica"];
  Node17 [shape="box",label="Templ< T >",fontsize=10,height=0.2,width=0.4,fontname="Helvetica",color="black",URL="$classTempl.html"];
  Node18 -> Node9 [dir=back,color="darkorchid3",fontsize=10,style="dashed",label="m_usedClass",fontname="Helvetica"];
  Node18 [shape="box",label="Used",fontsize=10,height=0.2,width=0.4,fontname="Helvetica",color="black",URL="$classUsed.html"];
}
                                                                                                                                                                                                                                                                                                                                                                                           tree/main.cc                                                                                        0100644 0003673 0000144 00000002141 11704031110 0014153 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        /** 
@file main.cc

Plik z funkcja main() do cwiczenia 4 na laboratoriach z AISDI.

@author
Pawel Cichocki, Michal Nowacki

@date  
last revision
- 2005.12.01 Michal Nowacki: lab #4
- 2005.10.27 Pawel Cichocki: added some comments
- 2005.10.26 Michal Nowacki: creation - separated from another file

COPYRIGHT:
Copyright (c) 2005 Instytut Informatyki, Politechnika Warszawska
ALL RIGHTS RESERVED
*******************************************************************************/

#include <iostream>

#ifdef _SUNOS
#include "/home/common/dyd/aisdi/tree/TreeMap.h"
#include "timer.h"
#else
#include "TreeMap.h"
#endif

int CCount::count=0;

int Test2();
void test();

int main()
{
   struct time_m czasstart;
   double czas;
   std::cout << "AISDI tree: wchodze do funkcji main." << std::endl;
   test();
   // Biblioteka z bardziej rygorystyczna wersja tych testow bedzie udostepniona na nastepnych zajeciach.
   czasstart = timer_start();
   Test2();
   czas = timer_stop( czasstart );
   std::cout << std::endl << "Czas wykonania Test2() : " << czas << " s." << std::endl;
   //system("PAUSE");
   return EXIT_SUCCESS;
}
                                                                                                                                                                                                                                                                                                                                                                                                                               tree/makefile                                                                                       0100644 0003673 0000144 00000001144 11704031110 0014422 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        all : asd asd_fast

asd : asd.cc
	g++ -D _SUNOS asd.cc /home/common/dyd/aisdi/tree/main.cc /home/common/dyd/aisdi/tree/timer.cc /home/common/dyd/aisdi/tests/ltest_tree.so -o asd 
asd_fast : asd.cc
	g++ -O2 -D NDEBUG -D _SUNOS asd.cc /home/common/dyd/aisdi/tree/main.cc /home/common/dyd/aisdi/tree/timer.cc /home/common/dyd/aisdi/tests/ltest_tree.so -o asd_fast
del :
	rm asd

debug : 
	g++ -g -D _SUNOS asd.cc /home/common/dyd/aisdi/tree/main.cc /home/common/dyd/aisdi/tree/timer.cc /home/common/dyd/aisdi/tests/ltest_tree.so -o asd_debug 
	gdb asd_debug

view:
	lynx /home/common/dyd/aisdi/tree/info/index.html
                                                                                                                                                                                                                                                                                                                                                                                                                            tree/nieaktualne/                                                                                   0040700 0003673 0000144 00000000000 11704031110 0015213 5                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        tree/timer.cc                                                                                       0100644 0003673 0000144 00000002077 11704031110 0014357 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        #include "timer.h"
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

struct time_m timer_start()
{
 struct time_m wyn;
 int who = RUSAGE_SELF;
 struct rusage usage;
 getrusage(who,&usage);
 wyn.sec=usage.ru_utime.tv_sec + usage.ru_stime.tv_sec;
 wyn.usec=usage.ru_utime.tv_usec + usage.ru_stime.tv_usec;
 if (wyn.usec > 1000000) {
	wyn.usec-=1000000;
	wyn.sec++;
 };
 return wyn;
};

double timer_stop(struct time_m old)
{
 struct time_m wyn;
 int who = RUSAGE_SELF;
 struct rusage usage;
 getrusage(who,&usage);
 wyn.sec=usage.ru_utime.tv_sec + usage.ru_stime.tv_sec;
 wyn.usec=usage.ru_utime.tv_usec + usage.ru_stime.tv_usec;
 if (wyn.usec > 1000000) {
	wyn.usec-=1000000;
	wyn.sec++;
 };
 wyn.sec-=old.sec;
 if (old.usec<=wyn.usec)
	{  wyn.usec-=old.usec; }
 else {
	if(wyn.sec>0) wyn.sec--;   //getrusage wywo�. w kr�tkim odst�pie czasu najwyra�niej czasem "g�upieje"
	                           // bo na Solarisie (i tylko tu) bez tego sprawdzenia dostawa�em czasem czasy ujemne
	wyn.usec=1000000+wyn.usec-old.usec;
 };
 return wyn.sec + wyn.usec/1000000.0;
};


                                                                                                                                                                                                                                                                                                                                                                                                                                                                 tree/timer.h                                                                                        0100644 0003673 0000144 00000000270 11704031110 0014212 0                                                                                                    ustar 00jkrol                           student                         0000472 0000062                                                                                                                                                                        #ifndef _TIMER_H
#define _TIMER_H

struct time_m { unsigned int sec,usec; };

struct time_m timer_start();
/* zwraca czas w milisekundach */
double timer_stop(struct time_m);

#endif

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        