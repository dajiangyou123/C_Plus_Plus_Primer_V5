#第 11 章  关联容器

###11.1：描述map和vector的不同。  
1. 首先**map**中的元素是按**关键字**来进行保存和访问的，而**vector**是根据元素的**位置**来进行保存和访问的；   
2. 其次**map**中存储是一对值，即键-值对，而**vector**中仅仅是单一元素（虽然其中也可以包含其他容器）。     

###11.2：分别给出最适合使用list、vector、deque、map以及set的例子。  
1. list：双向链表，适合在任何位置加减元素，不支持随机访问元素；   
2. vector：可变大小数组，适合存储需要随机访问元素的情况，在除了尾部之外的任何位置增减元素效率很低；  
3. deque：双端队列，支持快速随机访问，但其效率比vector低,适用于消息队列；
4. map：键值对存储，适合用字典等；
5. set：集合，适用于存在大量的高效查询操作的案例。   


###11.5：解释map和set的区别。
> map是键值对，set只是一个集合，如果仅仅只需要存储一个关键字的话，那么使用set，如果需要存储一个关键字及其对应的值那么使用map。


###11.6：解释set和list的区别。
> list是一个双向链表，它可以存储不同值的元素，且元素之间无序，而set是一个有序的且不能存储相同值的集合。


###11.9：定义一个map，将单词与一个保存行号的list关联，list中保存的是单词所出现的行号。
```C++
map<string, list<int>> words;
```


###11.10：可以定义一个vector<int>::iterator到int的map吗？list<int>::iterator到int的map呢？能或不能，给予解释。
```C++
map<vector<int>::iterator, int>  m1;                 //可以，因为vector<int>::iterator有比较运算
map<list<int>::iterator, int> m2;                    //不可以，因为list<int>::iterator没有比较运算，声明不提示错误，一旦插入元素就会提示错误。
```


###11.11：不使用decltype重新定义bookstore.
```C++
multiset<Sales_data, bool (*) (const Sales_data &, const Sales_data&) >  bookstore(compareIsbn);
```


###11.15: 对一个int到vector<int>的map，其mapped_type、key_type和value_type分别是什么？
> mapped_type是vector<int>，key_type是int,value_type是pair<const int, vector<int>>.


###11.16: 使用一个map迭代器编写一个表达式，将一个值赋予一个元素。
```C++
map<int, int> m = {{1,2}};
map<int, int>::iterator it = m.begin();
it->second = 3;                 //将3赋给了map中的首元素。
```

###11.17: c是string都得multi,v是string的vector。
```C++
copy(v.begin(), v.end(), inserter(c,c.end()));                 //合法，set有insert
copy(v.begin(), v.end(), back_inserter(c));                    //不合法，set没有push_back
```

###11.18: map<string, int>的迭代器类型。
```C++
map<string, int>::iterator
```


###11.19: 写出P379中名为bookstore的迭代器类型。
```C++
multiset<Sales_data,boole (*)(const Sales_data &, const Sales_data &) > ::iterator;
```


###11.22: 写出map<string, vector<int>>的insert版本的参考类型和返回值。
```C++
map<string, vector<int>> m;
pair< map<string, vector<int>>::iterator, bool>  ret = m.insert({"abc", {1,2,3}});    //参数类型是pair<string, vector<int>>
```


###11.37: 一个无序容器与其有序版本相比有何优势？有序版本有何优势？

> 无序容器的维护的效率高，一般来说其查找添加元素的性能比有序高。有序版本的优势是有序的且对于自定义容器元素类型不需要特定的限制（无序的必须有自己的hash函数）


###注：

> 
* 无论在有序容器中还是在无序容器中，具有相同关键字的元素都是相邻存储的。   

