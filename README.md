# new-vector-implemention

Constructor & Destructor Documentation
◆ xyVector() [1/4]
template<class T >
xyVector< T >::xyVector
default constructor to init the vector with capacity of 1 and size = 0

◆ xyVector() [2/4]
template<class T >
xyVector< T >::xyVector	(	int 	cap	)	
Construct a new xy Vector with the constructor.

Parameters
cap	to en
◆ xyVector() [3/4]
template<class T >
xyVector< T >::xyVector	(	T * 	dt,
int 	n 
)		
Construct a new xy Vector object.

Parameters
n	enters the size of the vector
◆ ~xyVector()
template<class T >
xyVector< T >::~xyVector
Destroy the xy Vector object.

◆ xyVector() [4/4]
template<class T >
xyVector< T >::xyVector	(	const xyVector< T > & 	another_vec	)	
copy vector with the constructor

Member Function Documentation
◆ Capacity()
template<class T >
int xyVector< T >::Capacity
get the capacity of the vector

Returns
int the capacity of the vector(object)
◆ clear()
template<class T >
void xyVector< T >::clear
clear the vector

◆ empty()
template<class T >
bool xyVector< T >::empty
check if the vector is empty or not

Returns
true if the vector is empty
false it vector is not empty
◆ erase() [1/2]
template<class T >
void xyVector< T >::erase	(	iterator 	iter1,
iterator 	iter2 
)		
deletes the elements from iterator 1 to iterator 2

Parameters
iter1	the first iteratror
iter2	the second iterator
◆ erase() [2/2]
template<class T >
void xyVector< T >::erase	(	iterator 		)	
takes an iterator and deletes it

◆ insert()
template<class T >
void xyVector< T >::insert	(	iterator 	iter,
T 	element 
)		
insert a new element at the iterator position

Parameters
iter	the position in which the element will be put on
element	the element to be inserted
◆ operator<()
template<class T >
bool xyVector< T >::operator<	(	xyVector< T > & 	v	)	
compares two vectors by elements >

Returns
true if the first element that differs in the two vectors in the first vector is bigger > than in the second
false if the first element that differs in the two vectors in the first vector is smaller < than in the second
◆ operator=() [1/2]
template<class T >
xyVector< T > & xyVector< T >::operator=	(	const xyVector< T > && 	another_vec	)	
move the data from object to anther

Returns
xyVector& the vector with new data
◆ operator=() [2/2]
template<class T >
xyVector< T > & xyVector< T >::operator=	(	const xyVector< T > & 	another_vec	)	
copy vector with the assignment operator

Returns
xyVector& the vector with the copied data
◆ operator==()
template<class T >
bool xyVector< T >::operator==	(	xyVector< T > & 	v	)	
checks if two vectors are equal

Returns
true if the two vectors are equal
false if the two vectors are not equal
◆ operator>()
template<class T >
bool xyVector< T >::operator>	(	xyVector< T > & 	v	)	
compares two vectors by elements <

Returns
true if the first element that differs in the two vectors in the first vector is smaller < than in the second
false true if the first element that differs in the two vectors in the first vector is bigger > than in the second
◆ operator[]()
template<class T >
T & xyVector< T >::operator[]	(	int 	idx	)	
access the vector elements using the [] operator

Returns
T& the item with the index entered
◆ pop_back()
template<class T >
T xyVector< T >::pop_back
delete the last element from the vector

Returns
T the item that was deleted
◆ push_back()
template<class T >
int xyVector< T >::push_back	(	T 	item	)	
push back an element of data type T to the vector

Returns
int the element that was pushed
◆ resize()
template<class T >
void xyVector< T >::resize	(	int 	new_size	)	
takes the new size as a parameter and changes teh size of the vector the new size

◆ size()
template<class T >
int xyVector< T >::size
get the vector size

Returns
int the size of the vector
Friends And Related Function Documentation
◆ operator<<
template<class T >
template<class t >
ostream & operator<<	(	ostream & 	out,
xyVector< t > 	v 
)		
friend
fucntion that prints the vector element using << operator

Template Parameters
t	the data type of the vector
Parameters
out	ostream operator
v	the vector itself
Returns
ostream& the output stream operator
