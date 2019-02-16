#ifndef NODE_H
#define NODE_H
#include <iostream>

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
      pPrev = NULL;
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
 * Create copy of Linked List.
 *********************************/
template<class T>
Node <T> *copy (Node <T> *pFront )
{
   Node <T> *copyNode = NULL;
   Node <T> *tempNode = pFront;
   
   do
   {
      insert(tempNode->data, copyNode);
      tempNode = tempNode->pNext;
   }
   while(tempNode != NULL)
   
   return copyNode;
}

/***********************************
 * Insert:
 * A simple function that inserts into
 * various parts of the list as a whole.
 ***************************************/
template <class T>
Node <T>* insert(Node <T> *&pFront, T newItem, bool after = false)
{
   Node <T> *itemNode = new Node<T>(newItem); //making a new node
   
   if (pFront == NULL)
   {
      pFront = itemNode;
      return pFront;
   }
   
   if(after)
   {
      //insert after the passed node
      // potentially three nodes involved. the one passed, the new node, the next node. they need to end in that order.
      // first set up the players, we have passed and new, get the next, ad if it is NULL, no biggy.
      
      Node <T> *temp = pFront->pNext;  //this represents what will come after the new one;
      
      //now we start changing pointers. starting with the passed one
      pFront->pNext = itemNode; //the referenced one points forward to the new one.
      
      //the new one need to point both the the passed one, and the next one
      itemNode->pPrev = pFront; //the new one points backward to the referenced one
      itemNode->pNext = temp; //the new one points forward to the next one
      
      //now it is possible that the next one soesn't exist and is NULL, if it is we are done, if not have it point back
      if(temp == NULL)
      {
         return itemNode;
      }
      else
      {
         temp->pPrev = itemNode; //the one that follows the new one now points back to it;
         return itemNode;
      }
   }
   else
   {
      //insert before the passed node similar to the after insert, just different
      //so I need to identify the players again. we have pFront, which will be the back
      //   itemNode, will be in the middle, and temp will be in the front.
      Node <T> *temp = pFront->pPrev;
      
      //Now we start changing pointers, starting with pFront, which will be in back;
      pFront->pPrev = itemNode;

      //next is itemNode, which is in the middle,
      itemNode->pNext = pFront;
      itemNode->pPrev = temp;

      //Now we handle the case of the NULL pointer in temp.
      if(temp == NULL)
      {
         return itemNode;
      }
      else
      {
         temp->pNext = itemNode; //the one that follows the new one now points back to it;
         return itemNode;
      }
      
   }
}
**********************************
 * Insert:
 * A simple function that inserts into
 * various parts of the node as a whole.
 * This is an overload to the above class
 ***************************************/
template <class T>
Node <T>* insert(T newItem, Node <T> *&pFront, bool isHead = false)
{
   Node <T> *itemNode = new Node<T>(newItem); //making a new node
   
   if (pFront == NULL)
   {
      pFront = itemNode;
      return pFront;
   }
   
   if(after)
   {
      //insert after the passed node
      // potentially three nodes involved. the one passed, the new node, the next node. they need to end in that order.
      // first set up the players, we have passed and new, get the next, ad if it is NULL, no biggy.
      
      Node <T> *temp = pFront->pNext;  //this represents what will come after the new one;
      
      //now we start changing pointers. starting with the passed one
      pFront->pNext = itemNode; //the referenced one points forward to the new one.
      
      //the new one need to point both the the passed one, and the next one
      itemNode->pPrev = pFront; //the new one points backward to the referenced one
      itemNode->pNext = temp; //the new one points forward to the next one
      
      //now it is possible that the next one soesn't exist and is NULL, if it is we are done, if not have it point back
      if(temp == NULL)
      {
         return itemNode;
      }
      else
      {
         temp->pPrev = itemNode; //the one that follows the new one now points back to it;
         return itemNode;
      }
   }
   else
   {
      //insert before the passed node similar to the after insert, just different
      //so I need to identify the players again. we have pFront, which will be the back
      //   itemNode, will be in the middle, and temp will be in the front.
      Node <T> *temp = pFront->pPrev;
      
      //Now we start changing pointers, starting with pFront, which will be in back;
      pFront->pPrev = itemNode;

      //next is itemNode, which is in the middle,
      itemNode->pNext = pFront;
      itemNode->pPrev = temp;

      //Now we handle the case of the NULL pointer in temp.
      if(temp == NULL)
      {
         return itemNode;
      }
      else
      {
         temp->pNext = itemNode; //the one that follows the new one now points back to it;
         return itemNode;
      }
      
   }
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
   Node <T> *tempNode = deleteNode = pFront; //i dont understand this line
   while(tempNode != NULL)
   {
      deleteNode = tempNode;
      tempNode = tempNode->pNext;
      delete deleteNode;
   }

   pFront = tempNode;
}
   
#endif /* NODE_H */
