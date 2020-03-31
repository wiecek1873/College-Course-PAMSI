#pragma once
#include<string>

#include"List.h"

using namespace std;

template<class KeyType, class ValueType>
class Map
{
public:
	List<ValueType>* values;


	Map();
	Map(const Map<KeyType, ValueType>& map) { values = new List<ValueType>(*map.values); }
	~Map() {delete values; }

	void insert(const KeyType& key, const ValueType& value);
	void remove(const KeyType& key);
	int hash(int key);
	int hash(const string& key);
	ValueType& operator[](const KeyType& key);
	Map<KeyType, ValueType>& operator = (const Map<KeyType, ValueType>& map);
};

template<class KeyType, class ValueType>
Map<KeyType, ValueType>::Map()
{
	values = new List<ValueType>();
	for (int i = 0; i < 50; i++)
		values->pushBack(NULL);
}

template<class KeyType, class ValueType>
void Map<KeyType, ValueType>::insert(const KeyType& key, const ValueType& value)
{
	int index = hash(key);
	(*values)[index] = value;
}

template<class KeyType, class ValueType>
int Map<KeyType, ValueType>::hash(int key)
{
	int out = 0;
	out = key * 3 + 11;
	return out % 50;
}

template<class KeyType, class ValueType>
int Map<KeyType, ValueType>::hash(const string& key)
{
	int out = 0;

	for (unsigned int i = 0; i < key.size(); i++)
	{
		out += int(key[i]);
	}

	return out % 50;
}

template<class KeyType, class ValueType>
void Map<KeyType, ValueType>::remove(const KeyType& key)
{
	int index = hash(key);
	(*values)[index] = 0;
}

template<class KeyType, class ValueType>
ValueType& Map<KeyType, ValueType>::operator[](const KeyType& key)
{
	int index = hash(key);
	return (*values)[index];
}

template<class KeyType, class ValueType>
Map<KeyType, ValueType>& Map<KeyType, ValueType>::operator = (const Map<KeyType,ValueType>& map)
{
	delete this->values;
	this->values = new List<ValueType>(*map.values);
	return *this;
}