#pragma once

#include <cassert>
#include "Macros.h"

#define EMPTY_NODE_TYPE 0

template <typename TYPE>
class Node
{
	template <typename TYPE>
	friend class List;

public:
	Node( ) :
		m_value(EMPTY_NODE_TYPE),
		m_pPrevNode(nullptr),
		m_pNextNode(nullptr)
	{ }
	
	Node(const TYPE& value, Node<TYPE>* node) :
		m_value(value),
		m_pPrevNode(node),
		m_pNextNode(node->m_pNextNode)
	{
		m_pNextNode->m_pPrevNode = m_pPrevNode->m_pNextNode = this;
	}

	~Node( )
	{
		if ( nullptr != m_pPrevNode )
		{
			m_pPrevNode->m_pNextNode = m_pNextNode;
		}

		if ( nullptr != m_pNextNode )
		{
			m_pNextNode->m_pPrevNode = m_pPrevNode;
		}
	}

private:
	Node(const Node&) = delete;
	Node& operator=(const Node&) = delete;

private:
	TYPE m_value;
	Node<TYPE>* m_pPrevNode;
	Node<TYPE>* m_pNextNode;
};
