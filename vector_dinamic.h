#ifndef VECTOR_DINAMIC_H
#define VECTOR_DINAMIC_H

#define INITIAL_CAPACITY 2

template<typename ElemType>
class IteratorVector;

template<typename ElemType>
class VectorDinamic {

private:
	ElemType* elements;
	int length;
	int capacity;
	void assureCapacity([[maybe_unused]] int factor = 2);

public:

	// constructor
	VectorDinamic();

	// destructor
	~VectorDinamic();

	// copy vector
	VectorDinamic(const VectorDinamic& copy);

	// operators
	// assignment operator
	VectorDinamic& operator=(const VectorDinamic& vector);

	// move the constructor
	VectorDinamic(VectorDinamic&& vector) noexcept;

	// move the assignation
	VectorDinamic& operator=(VectorDinamic&& vector) noexcept;

	// add in vector
	void push_back(const ElemType& element);

	// delete
	void erase(int position);

	// getter element
	[[maybe_unused]] ElemType& get(int position) const;

	// setter
	[[maybe_unused]] void set(int position, const ElemType& element);

	// we take the length
	[[nodiscard]] int get_length() const noexcept;

	// we declare the iterator as a friend class
	friend class IteratorVector<ElemType>;

	// the iterators of the vector
	IteratorVector<ElemType> begin() const;
	IteratorVector<ElemType> end() const;

	[[nodiscard]] bool empty() const noexcept;
	[[maybe_unused]]IteratorVector<ElemType> iterator() {
		return IteratorVector<ElemType>(*this);
	};
	ElemType& operator[](int position) const;


};

// suprascriere operator
template<typename ElemType>
ElemType& VectorDinamic<ElemType>::operator[](int position) const {
	return elements[position];
}

// constructor
template<typename ElemType>
VectorDinamic<ElemType>::VectorDinamic() : length(0), capacity(INITIAL_CAPACITY) {
	this->elements = new ElemType[INITIAL_CAPACITY];
}

// constructor copy
template<typename ElemType>
VectorDinamic<ElemType>::VectorDinamic(const VectorDinamic<ElemType>& copy) {
	this->capacity = copy.capacity;
	this->length = copy.length;
	this->elements = new ElemType[capacity];

	// Copy only up to the length of the original vector
	for (int i = 0; i < length; ++i) {
		elements[i] = copy.elements[i];
	}
}

// check if its empty
template<typename ElemType>
bool VectorDinamic<ElemType>::empty() const noexcept {
	return length == 0;
}


// assignment
template<typename ElemType>
VectorDinamic<ElemType>& VectorDinamic<ElemType>::operator=(const VectorDinamic<ElemType>& vector) {
	if (this == &vector) {
		return *this;
	}
	delete[] elements;
	elements = new ElemType[vector.capacity];
	// copiem elementele
	for (int i = 0; i < vector.length; ++i) {
		elements[i] = vector.elements[i];
	}
	length = vector.length;
	capacity = vector.capacity;
	return *this;
}

// DESTRUCTOR
template<typename ElemType>
VectorDinamic<ElemType>::~VectorDinamic() {
	delete[] elements;
	length = 0;
	capacity = 0;
}

template<typename ElemType>
VectorDinamic<ElemType>::VectorDinamic(VectorDinamic&& vector) noexcept {
	// copiem datele
	elements = vector.elements;
	length = vector.length;
	capacity = vector.capacity;

	// le stergem din vector
	vector.elements = nullptr;
	vector.length = 0;
	vector.capacity = 0;
}

// moving the assignation
template<typename ElemType>
VectorDinamic<ElemType>& VectorDinamic<ElemType>::operator=(VectorDinamic<ElemType>&& vector) noexcept {
	if (this == &vector) {
		return *this;
	}

	delete[] elements;
	// copiem datele de la vector in this
	elements = vector.elements;
	length = vector.length;
	capacity = vector.capacity;

	// stergem datele de la vector pt ca le-am mutat
	vector.elements = nullptr;
	vector.length = 0;
	vector.capacity = 0;

	return *this;
}

template<typename ElemType>
void VectorDinamic<ElemType>::erase(int position) {
	this->length--;
	for (int i = position; i < this->length; ++i) {
		this->elements[i] = this->elements[i + 1];
	}
}

template<typename ElemType>
void VectorDinamic<ElemType>::push_back(const ElemType& element) {
	assureCapacity();
	elements[length++] = element;
}

// getter
template<typename ElemType>
[[maybe_unused]] ElemType& VectorDinamic<ElemType>::get(int position) const {
	return elements[position];
}

// setter
template<typename ElemType>
[[maybe_unused]] void VectorDinamic<ElemType>::set(int position, const ElemType& element) {
	elements[position] = element;
}

template<typename ElemType>
int VectorDinamic<ElemType>::get_length() const noexcept {
	return length;
}

template<typename ElemType>
void VectorDinamic<ElemType>::assureCapacity([[maybe_unused]] int factor) {
	if (length < capacity) {
		return;
	}
	capacity *= 2;
	auto* aux = new ElemType[capacity];
	for (int i = 0; i < length; ++i) {
		aux[i] = elements[i];
	}
	delete[] elements;
	elements = aux;
}

template<typename ElemType>
IteratorVector<ElemType> VectorDinamic<ElemType>::begin() const {
	return IteratorVector<ElemType>(*this);
}


template<typename ElemType>
IteratorVector<ElemType> VectorDinamic<ElemType>::end() const {
	return IteratorVector<ElemType>(*this, length);
}

template<typename ElemType>
class IteratorVector {
private:
	const VectorDinamic<ElemType>& vector;
	int position = 0;
public:
	explicit IteratorVector(const VectorDinamic<ElemType>& vector);
	IteratorVector(const VectorDinamic<ElemType>& vector, int position) noexcept;

	[[maybe_unused]] [[nodiscard]] bool valid()const;
	ElemType& element() const;
	void next();
	ElemType& operator*();
	IteratorVector& operator++();

	bool operator == (const IteratorVector& ot) noexcept;
	bool operator != (const IteratorVector& ot) noexcept;
};

template<typename ElemType>
IteratorVector<ElemType>::IteratorVector(const VectorDinamic<ElemType>& vec) : vector(vec) {}

template<typename ElemType>
IteratorVector<ElemType>::IteratorVector(const VectorDinamic<ElemType>& vec, int position) noexcept : vector(vec), position(position) {}

template<typename ElemType>
[[maybe_unused]] bool IteratorVector<ElemType>::valid() const {
	return position < vector.length;
}

template<typename ElemType>
ElemType& IteratorVector<ElemType>::element() const {
	return vector.elements[position];
}

template<typename ElemType>
void IteratorVector<ElemType>::next() {
	position++;
}

template<typename ElemType>
ElemType& IteratorVector<ElemType>::operator*() {
	return element();
}

template<typename ElemType>
IteratorVector<ElemType>& IteratorVector<ElemType>::operator++() {
	next();
	return *this;
}

template <typename ElemType>
bool IteratorVector<ElemType>:: operator==(const IteratorVector<ElemType>& ot) noexcept {
	return ot.position == position;
}

template <typename ElemType>
bool IteratorVector<ElemType>:: operator!=(const IteratorVector<ElemType>& ot) noexcept {
	return !(*this == ot);
}
#endif