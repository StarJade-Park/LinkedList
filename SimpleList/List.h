#pragma once

#include <iostream>

#include "Node.h"

/*
* Doubly linked list class template
*/
template <typename T>
class List
{
public:
	List( ) :
		m_pHead(new Node<T>),
		m_pTail(new Node<T>),
		m_size(0)
	{
		m_pHead->m_pNextNode = m_pTail;
		m_pTail->m_pPrevNode = m_pHead;
	}

	~List( )
	{
		while ( m_pHead->m_pNextNode != m_pTail )
		{
			delete m_pHead->m_pNextNode;
		}

		SAFE_RELEASE(m_pHead);
		SAFE_RELEASE(m_pTail);
	}

	void insertFront(const T& value)
	{
		new Node<T>(value, m_pHead);
		++m_size;
	}

	void insertBack(const T& value)
	{
		new Node<T>(value, m_pTail->m_pPrevNode);
		++m_size;
	}

	void removeFront( )
	{
		if ( m_pHead->m_pNextNode == m_pTail )
		{
			return;
		}

		delete m_pHead->m_pNextNode;
		--m_size;
	}

	void removeBack( )
	{
		if ( m_pTail->m_pPrevNode == m_pHead )
		{
			return;
		}

		delete m_pTail->m_pPrevNode;
		--m_size;
	}

	bool search(const T& value, Node<T>* node)
	{
		Node<T>* tmp = m_pHead;
		int count = 0;

		while ( tmp->m_pNextNode != m_pTail )
		{
			if ( value == tmp->m_pNextNode->m_value )
			{
				node = tmp->m_pNextNode;
				return true;
			}

			tmp = tmp->m_pNextNode;
		}

		return false;
	}

	void printElements( )
	{
		Node<T>* tmp = m_pHead;

		std::cout << "[HEAD] -> ";

		while ( tmp->m_pNextNode != m_pTail )
		{
			assert(nullptr != tmp->m_pNextNode);

			std::cout << "[" << tmp->m_pNextNode->m_value << "] -> ";
			tmp = tmp->m_pNextNode;
		}

		std::cout << "[TAIL]" << std::endl;
	}

private:
	Node<T>* m_pHead;
	Node<T>* m_pTail;
	int m_size;	
};
