#ifndef LIST_H
#define LIST_H

/*! @brief Dynamic size array
*
* arr is a pointer to the stored data array
* capacity is current max capacity
* count is current amount of stored elements
* elem_size is size of an element in bytes
*/
typedef struct
{
    void* arr;
    size_t capacity;
    size_t count;
    size_t elem_size;
} list;

/*! @brief Initialize list
*
* @param[in] list_p Pointer to the list
* @param[in] element_size Size of each stored element in bytes
*
* Any list must be initialized before being used
*/
void List_Init(list* list_p, size_t element_size);

/*! @brief Add an element to a list
*
* @param[in] list_p Pointer to the list
* @param[in] elem Element to add
*
* @return 1 if list was expanded 0 otherwise
*/
int List_AddElement(list* list_p, void* elem);

/*! @brief Remove an element at index
*
* @param[in] list_p Pointer to the list
* @param[in] index Index of removed element
*
* Moves back all elements after the removed one
*/
void List_RemoveElementAt(list* list_p, size_t index);

/*! @brief Get an element at index
*
* @param[in] list_p Pointer to the list
* @param[in] index Index of returned element
*
* @return Pointer to the element at index
*/
void* List_GetElementAt(list* list_p, size_t index);

/*! @brief Expand lists capacity
*
* @param[in] list_p Pointer to the list
*
* Doubles lists capacity
*/
void List_Expand(list* list_p);

/*! @brief Frees memory allocated to the list
*
* @param[in] list_p Pointer to the list
*/
void List_Begone(list* list_p);

/*! @brief Easier use of List_Init
*
* @param[in] lst List struct
* @param[in] type Type of stored values
*/
#define ListInit(lst, type) List_Init(&lst, sizeof(type))

/*! @brief Easier use of List_RemoveElementAt
*
* @param[in] lst List struct
* @param[in] idx Index of element to remove
*/
#define ListRemoveAt(lst,idx) List_RemoveElementAt(&lst, idx)

/*! @brief Easier use of List_AddElement
*
* @param[in] lst List struct
* @param[in] elm Element to add
*/
#define ListAdd(lst,elm) List_AddElement(&lst, &elm)

/*! @brief Easier use of List_GetElementAt
*
* @param[in] lst List struct
* @param[in] idx Index of element to get
* @param[in] type Type of stored values
*/
#define ListGet(lst,idx,type) *(type*)List_GetElementAt(&lst, idx)

/*! @brief Easier use of List_Begone
*
* @param[in] lst List struct
*/
#define ListBegone(lst) List_Begone(&lst)

#endif
