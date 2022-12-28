/**
 * LISTARRAY.H
 */
#ifndef __LISTARRAY_H__
#define __LISTARRAY_H_

class List {

	private:
		int m_count;
		int * m_item;


	public:
		List();
		~List();
		int Get(int index);
		void Insert(int index, int val);
		int Search(int val);
		void Remove(int index);
		int Count();
};

#endif /* __LISTARRAY_H__ */
