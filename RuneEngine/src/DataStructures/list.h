/**
 * @class rune::List
 * @brief A list that can be used to store data.
 *
 * @author Thomas Montano
 * @date July 21 2020
*/

#pragma once
#include <core.h>

namespace rune {

  ///@cond listItem
  template <class T>
  struct listItem
  {

    T storedItem;
    listItem* nextItem;

    listItem()
    {
      nextItem = nullptr;
    }

  };
  ///@endcond

  template <class T>
  class RUNE_ENGINE List
  {

  private:
    listItem<T>* listHead;
    int listSize = 0;

  public:

    List()
    {
      listHead = NULL;
    }

    ~List()
    {
      clear();
    }

    ///Gets the number of elements in the list.
    /// @returns The number of elements in the list.
    int size()
    {
      return listSize;
    }

    ///Adds an element to the end of the list.
    ///@param newData The data point to be added to the list.
    void add(T newData)
    {

      listSize++;
      listItem<T>* newItem = new listItem<T>;
      newItem->storedItem = newData;

      listItem<T>* currentItem = listHead;

      if (listHead == nullptr)
      {

        listHead = newItem;

      }
      else
      {

        while (currentItem->nextItem != nullptr)
        {

          currentItem = currentItem->nextItem;

        }

        currentItem->nextItem = newItem;

      }

    }

    /// Remove an element at the specified index.
    /// @param index The zero based index of the element to be deleted.
    void remove(int index)
    {

      listSize--;
      listItem<T>* currentItem = listHead;

      //Access the element just before the element to be deleted.
      for (int i = 0; i < index - 1; i++)
      {

        currentItem = currentItem->nextItem;

      }

      //If the list is now empty, reset. Otherwise, delete the specified element.
      if (index == 0)
      {
        listItem<T>* temp = listHead;
        listHead = listHead->nextItem;
        delete temp;
      }
      else
      {
        listItem<T>* temp = currentItem->nextItem->nextItem;

        delete currentItem->nextItem;
        currentItem->nextItem = temp;
      }

    }

    ///Clears the list
    void clear()
    {
    
      while (listSize != 0)
      {
      
        //Go through and delete each element of the list
        remove(0);
      
      }

    }

    /// Insert an element at the specified index.
    /// @param newData The element to be inserted.
    /// @param index The zero based index of the location.
    void insert(T newData, int index)
    {

      listSize++;
      listItem<T>* currentItem = listHead;

      listItem<T>* newItem = new listItem<T>;
      newItem->storedItem = newData;

      //Access the element just before the space to be inserted.
      for (int i = 0; i < index - 1; i++)
      {

        currentItem = currentItem->nextItem;

      }

      listItem<T>* temp = currentItem->nextItem;

      currentItem->nextItem = newItem;
      newItem->nextItem = temp;

    }

    /// List access operator
    /// @param index The zero based index of the element to be accessed.
    /// @returns The accessed element.
    T operator[](int index)
    {

      listItem<T>* currentItem = listHead;

      for (int i = 0; i < index; i++)
      {

        currentItem = currentItem->nextItem;

      }

      return currentItem->storedItem;

    }

  };

}//namespace rune