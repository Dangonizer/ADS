#include "hashtable.h"
#include <iostream>

using namespace std;

HashTable::HashTable(int size, double threshold, int methode) : size(size), threshold_rehashing(threshold), m_sondierMethode(methode), elements(0), collisionCount(0)
{
	hashTable = new vector<int>(size);
	for (int i = 0; i < size; i++)
	{
		hashTable->at(i) = -1;
	}
}

HashTable::~HashTable()
{
	delete hashTable;
}

int get_next_prime(int x)
{
	x = x + 1;
	bool found = true;
	while (true)
	{
		found = true;
		for (int i = 2; i <= sqrt(x); i++)
		{
			if (x % i == 0)
			{
				found = false;
				break;
			}
		}
		if (found)
		{
			return x;
		}
		x += 1;
	}
}

int get_last_prime(int x)
{
	x = x - 1;
	bool found = true;
	while (true)
	{
		found = true;
		for (int i = 2; i <= sqrt(x); i++)
		{
			if (x % i == 0)
			{
				found = false;
				break;
			}
		}
		if (found)
		{
			return x;
		}
		x -= 1;
	}
}

// Berechnung des Hashwertes
int HashTable::hashValue(int item)
{
	switch (m_sondierMethode)
	{
	case (1):
		for (int i = 0; i < size; i++)
		{
			int hash = (item + i) % size;
			if (hashTable->at(hash) == -1)
			{
				return hash;
			}
			collisionCount++;
		}

		break;
	case (2):
		// Quadr. Sondieren
		for (int i = 0; i < size; i++)
		{
			int hash = (item + i * i) % size;
			if (hashTable->at(hash) == -1)
			{
				return hash;
			}
			collisionCount++;
		}
		break;
	case (3):
	{
		// Doppeltes Hashing
		int R = get_last_prime(size);
		for (int i = 0; i < size; i++)
		{
			int hash = (item + i * (R - (item % R))) % size;
			if (hashTable->at(hash) == -1)
			{
				return hash;
			}
			collisionCount++;
		}
	}
	default:
		break;
	}
	return 1;
}

void HashTable::rehashing()
{
	if (size < 1000)
	{
		int newsize = get_next_prime(size * 2);
		if (newsize > 1000)
		{
			newsize = 1000;
		}
		vector<int> *newHashTable = new vector<int>(newsize);
		for (int i = 0; i < newsize; i++)
		{
			newHashTable->at(i) = -1;
		}
		vector<int> *oldHashTable = hashTable;
		hashTable = newHashTable;
		int oldsize = size;
		size = newsize;
		collisionCount = 0;
		for (int i = 0; i < oldsize; i++)
		{
			if (oldHashTable->at(i) != -1)
			{
				int hash = hashValue(oldHashTable->at(i));
				hashTable->at(hash) = oldHashTable->at(i);
			}
		}
		delete oldHashTable;
	}
}

int HashTable::insert(int item)
{
	if (((double)elements + 1) / size >= threshold_rehashing)
	{
		rehashing();
	}
	int hash = hashValue(item);
	hashTable->at(hash) = item;
	elements++;
	return hash;
}

int HashTable::at(int i)
{
	return hashTable->at(i);
}

int HashTable::getCollisionCount()
{
	return this->collisionCount;
}

int HashTable::getSize()
{
	return this->size;
}

int HashTable::getElements()
{
	return this->elements;
}

void HashTable::print()
{
	for (int i = 0; i < size; i++)
	{
		cout << "[" << i << "] -> " << hashTable->at(i) << endl;
	}
}