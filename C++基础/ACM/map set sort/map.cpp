#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int main()
{
	//multimap与map用法相同，multimap可有重复的key，二者同为红黑树实现
	//unordered_map与map用法相同，unordered_map是无序的哈希表
	//定义map<key,value>name;
	map<int, string>mapint_string;
	map<int, char>mapint_char;
	//插入
	//mapint_char.insert(pair<int, char>(102, 'a'));
	//mapint_string.insert(map<int, string>::value_type(321,"hai"));
	mapint_char[112] = 'c';  //最常用
	//查找
	map<int, char>::iterator it,is;
	it = mapint_char.find(112);	//只能查找key,没找到则返回尾部
	is = mapint_char.find(111);
	//也可以做用自动来定义
	//auto it = mapint_char.find(112);
	//auto is = mapint_char.find(111);
	
	if (is == mapint_char.end())	//找到尾部
		cout << "end" << endl;
	cout <<it->first<<':'<< it->second<<endl;			//输出
	//删除
		//先find
	mapint_char.erase(it);		//删除
	//swap
		map <int, int> m1, m2, m3;
		map <int, int>::iterator m1_Iter;
		m1.insert(pair <int, int>(1, 10));
		m1.insert(pair <int, int>(2, 20));
		m1.insert(pair <int, int>(3, 30));
		m2.insert(pair <int, int>(10, 100));
		m2.insert(pair <int, int>(20, 200));
		m3.insert(pair <int, int>(30, 300));
		cout << "original:";
		for (m1_Iter = m1.begin(); m1_Iter != m1.end(); m1_Iter++)
			cout << " " << m1_Iter->second;
		cout << endl << "new:";
		m1.swap(m2);			//直接交换整个容器
		for (m1_Iter = m1.begin(); m1_Iter != m1.end(); m1_Iter++)
			cout << " " << m1_Iter->second;
		cout << endl << "m2new:";
		for (m1_Iter = m2.begin(); m1_Iter != m2.end(); m1_Iter++)
			cout << " " << m1_Iter->second;
		//排序
			//Map自动根据 "Key" "升序" 排序
		//套娃
		map<int, char>m0;
		map<map<int,char>, string>;
		/*map的基本操作函数：
				begin()          返回指向map头部的迭代器
				clear(）         删除所有元素
				count()          返回指定元素出现的次数
				empty()          如果map为空则返回true
				end()            返回指向map末尾的迭代器
				equal_range()    返回特殊条目的迭代器对
				find()           查找一个元素返回值为指针
				get_allocator()  返回map的配置器
				insert()         插入元素
				key_comp()       返回比较元素key的函数
				lower_bound()    返回键值 >= 给定元素的第一个位置
				max_size()       返回可以容纳的最大元素个数
				rbegin()         返回一个指向map尾部的逆向迭代器
				rend()           返回一个指向map头部的逆向迭代器
				size()           返回map中元素的个数
				upper_bound()     返回键值 > 给定元素的第一个位置
				value_comp()      返回比较元素value的函数*/
}