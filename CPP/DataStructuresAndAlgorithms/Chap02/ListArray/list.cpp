#include<iostream>
#include<cstring>
#include"list.h"

List::List() {}
List::~List() {}
int List::Get(int index) {
	if (index < 0 || index > m_count)
		return (-1);

	return (m_item[index]);
}

void List::Insert(int index, int val) {
	if (index < 0 || index > m_count)
		return;

	int * oldItem = m_item;
	m_count++;
	m_item = new int[m_count];

	// Fill array
	for (int i = 0, j = 0; i < m_count; i++) {
		if (i == index)
			m_item[i] = val;
		else {
			m_item[i] = oldItem[j];
			j++;
		}
	}

	// remove old array
	delete [] oldItem;
}
int List::Search(int val) {
	for (int i = 0; i < m_count; i++) {
		if (m_item[i] == val)
			return (i);
	}

	return (-1);
}
void List::Remove(int index) {
	if (index < 0 || index > m_count)
		return;

	int * oldItem = m_item;
	m_count--;
	m_item = new int[m_count];

	for (int i = 0, j = 0; i < m_count; ++i, ++j) {
		if (index == j)
			++j;
		
		m_item[i] = oldItem[j];
	}
	delete [] oldItem;
}
int List::Count() {
	return (m_count);
}