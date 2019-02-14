#ifndef NODE_H
#define NODE_H
#include <iostream>

//this is Ken, just tryng to figure out how gitHub works. you can ignore this comment

template <class T>
class Node
{
  public:
   T data;
   Node <T> *pNext;
   Node <T> *pPrev;

/************************
 * Default Constructor:
 * Create a NULL object.
 ***********************/
   Node()
   {
      pNext = NULL;
      pPrev = NULL; //pointers to NULL for safety
   }  

/**********************************
 * Non Default Constructor:
 * create object with data in it.
 *********************************/  
   Node(T dat)
   {
      data = dat;
      pNext = NULL;
      pPrev = NULL;
   }
};

/**********************************
 * Copy
 * Create copy of linked - list
 *********************************/
template<class T>
Node <T> *copy (Node <T> *pFront )
{					//I might suggest some changes here as well, I'll look at it tomorrow - Ken
   Node <T> *copyNode = NULL;
   Node <T> *tempNode = pFront;
   
   while(tempNode != NULL)
   {
      insert(tempNode->data, copyNode);
      tempNode = tempNode->pNext;
   }
   
   return copyNode;
}

/***********************************
 * Insert:
 * A simple function that inserts into
 * various parts of the node as a whole.
 ***************************************/
template <class T>
Node <T>* insert(Node <T> *&pFront, T newItem, bool isHead = false)
{
   Node <T> *itemNode = new Node<T>(newItem);

   if (pFront == NULL)
   {
      pFront = itemNode;
   }
   else if (isHead)
   {
      itemNode->pNext = pFront;
      pFront->pPrev = itemNode;
      pFront = itemNode;
   }

   else
   {
      itemNode->pNext = pFront->pNext;
      pFront->pNext = temp;
      Node <T> *temp = new Node <T>;
      temp = itemNode->pNext;	//its not just about whats next, its about what comes before too -Ken
      temp->pPrev = itemNode;
      itemNode->pPrev = pFront;
   }

   return pFront;
}

/***********************************
 * Insert:
 * A simple function that inserts into
 * various parts of the node as a whole.
 * This is an overload to the above class
 ***************************************/
template <class T>
Node <T>* insert(T newItem, Node <T> *&pFront, bool isHead = false)
{
	Node <T> *itemNode = new Node<T>(newItem);

	if (pFront == NULL)
	{
		pFront = itemNode;
	}

	else if (isHead)
	{
		itemNode->pNext = pFront;
		pFront->pPrev = itemNode;
		pFront = itemNode;
	}

	else
	{
		itemNode->pNext = pFront->pNext;
		pFront->pNext = temp;
		Node <T> *temp = new Node <T>;
		temp = itemNode->pNext;	//its not just about whats next, its about what comes before too -Ken
		temp->pPrev = itemNode;
		itemNode->pPrev = pFront;
	}

	return pFront;
}


/****************************************
 * Find:
 * Searches the linked list for an item.
 ***************************************/
template <class T>
Node <T> *find(Node <T> *pFront, T finding)
{
   if (pFront == nullptr)
   {
      return nullptr;
   }

   for (Node <T> *tempNode = pFront; tempNode; tempNode = tempNode->pNext)
   {
      if (tempNode->data == finding)
      {
         return tempNode;
      }
   }

   return NULL;
}


/************************************************************
 * << Operator:
 * This loops through the list and prints the items it finds
 *************************************************************/
template<class T>
std::ostream& operator<<(std::ostream &output, Node <T> *pFront)
{
   Node <T> *outputNode = pFront;
   while (outputNode != NULL)
   {
      if (outputNode->pNext == NULL)
      {
         output << outputNode->data;
      }
      else
      {
         output << outputNode->data << ", ";
      }
      outputNode = outputNode->pNext;
   }

   return output;
}


/*******************************************************************
 * freeData:
 * this loops through the list and deletes each node
 * by copying into two temp pointers one to loop through the nodes
 * and the other to free them both are assigned to each other then
 * outside the loop pFront is assigned the NULL value each time.
 ******************************************************************/
template <class T>
void freeData(Node <T> *&pFront)
{
   Node <T> *deleteNode = NULL;
   Node <T> *tempNode = pFront; //This makes more sense to me, I wan't sure what temp = delete = front was supposed to do - Ken
   while(tempNode != NULL)
   {
      deleteNode = tempNode;
      tempNode = tempNode->pNext;
      delete deleteNode;
   }

   pFront = tempNode;
}
   
#endif /* NODE_H */
