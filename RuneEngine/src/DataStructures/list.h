/**
 * @class rune::List
 * @brief A list that can be used to store data.
 *
 * The methodology for iterating through a list is very similar to a range based loop syntax.
 * To iterate through a list without copying or having to redo iterations, you should create a for loop like this:
 *
 * @code
 * for (TYPE* currentObject = myList.getList(); currentObject != nullptr; currentItem = myList.getNext())
 * {
 *
 *   //Do stuff
 *   currentObject.myFunction();
 *
 * }
 *
 * @endcode
 *
 * @author Thomas Montano
 * @date July 21 2020
*/

#pragma once

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
  class List
  {

  private:
    listItem<T>* listHead;
    listItem<T>* currentlyAccessedItem;

    int listSize;

  public:

    List()
      : listHead(nullptr), listSize(0), currentlyAccessedItem(nullptr)
    {
    }

    ~List()
    {
      clear();
    }

    ///Gets the current head of the list for purposes of iteration.
    /// @returns A pointer to the head of the list.
    /// @warning Do not call this function from inside a list iteration. If you are already looking through this list it will cause an infinite loop.
    T* getList()
    { 
      currentlyAccessedItem = listHead;
      return &(listHead->storedItem);
    }

    ///Gets the next element of the list.
    /// @return A pointer to the next element
    /// @warning Will return nullptr if the end of the list has been reached.
    T* getNext()
    {

      if (currentlyAccessedItem == nullptr)
      {
        return nullptr;
      }

      currentlyAccessedItem = currentlyAccessedItem->nextItem;

      return &(currentlyAccessedItem->storedItem);

    }

    ///Gets the number of elements in the list.
    /// @returns The number of elements in the list.
    int size()
    {
      return listSize;
    }

    ///Adds an element to the end of the list.
    ///@param newData The data point to be added to the list.
    void add(T const& newData)
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
    void insert(T const& newData, int index)
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
    /// @warning This should not be used to iterate through a list. Only use this function if you are looking for single elements.
    T& operator[](int index)
    {

      listItem<T>* currentItem = listHead;

      for (int i = 0; i < index; i++)
      {

        currentItem = currentItem->nextItem;

      }

      return (currentItem->storedItem);

    }

  };

}//namespace rune