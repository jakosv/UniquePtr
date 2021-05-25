#include "UniquePtr.h"

template<typename T>
UniquePtr<T>::UniquePtr() {
    _ptr = nullptr;
}

template<typename T>
UniquePtr<T>::UniquePtr(T* ptr) {
    _ptr = ptr;
}

template<typename T>
UniquePtr<T>::UniquePtr(UniquePtr<T>&& o) noexcept {
    _ptr = o._ptr;
    o._ptr = nullptr;
}

template<typename T>
UniquePtr<T>::~UniquePtr() {
    delete[] _ptr;
    _ptr = nullptr;
}

template<typename T>
UniquePtr<T>& UniquePtr<T>::operator=(UniquePtr<T>&& o) noexcept {
    if (this != &o) {
        this->reset();
        _ptr = o._ptr;
        o._ptr = nullptr;
    }
    return *this;
}

template<typename T>
UniquePtr<T>& UniquePtr<T>::operator=(T* ptr) {
    this->reset();
    _ptr = ptr;
    return *this;
} 

template<typename T>
T& UniquePtr<T>::operator*() const {
    return *_ptr;
}

template<typename T>
T* UniquePtr<T>::get() const {
    return _ptr;
}

template<typename T>
T* UniquePtr<T>::operator->() const {
    return _ptr;
}

template<typename T>
T& UniquePtr<T>::operator[](const size_t idx) {
    return _ptr[idx];
}

template<typename T>
const T& UniquePtr<T>::operator[](const size_t idx) const {
    return _ptr[idx];
}

template<typename T>
UniquePtr<T>::operator bool() const {
    return _ptr != nullptr;
}

template<typename T>
void UniquePtr<T>::reset() {
    delete[] _ptr;
    _ptr = nullptr;
}

template<typename T>
void UniquePtr<T>::reset(T* ptr) {
    delete[] _ptr;
    _ptr = ptr;
}

template<typename T>
void UniquePtr<T>::release() {
    _ptr = nullptr;
}

template class UniquePtr<int>;
template class UniquePtr<float>;
template class UniquePtr<double>;
template class UniquePtr<char>;
