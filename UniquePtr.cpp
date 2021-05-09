#include "UniquePtr.h"

UniquePtr::UniquePtr() {
    _ptr = nullptr;
}

UniquePtr::UniquePtr(ValueType* ptr) {
    _ptr = ptr;
}

UniquePtr::UniquePtr(UniquePtr&& o) noexcept {
    _ptr = o._ptr;
    o._ptr = nullptr;
}

UniquePtr::~UniquePtr() {
    delete[] _ptr;
    _ptr = nullptr;
}

UniquePtr& UniquePtr::operator=(UniquePtr&& o) noexcept {
    if (this != &o) {
        this->reset();
        _ptr = o._ptr;
        o._ptr = nullptr;
    }
    return *this;
}

UniquePtr& UniquePtr::operator=(ValueType* ptr) {
    this->reset();
    _ptr = ptr;
    return *this;
} 

ValueType& UniquePtr::operator*() const {
    return *_ptr;
}

ValueType* UniquePtr::get() const {
    return _ptr;
}

ValueType* UniquePtr::operator->() const {
    return _ptr;
}

ValueType& UniquePtr::operator[](const size_t idx) {
    return _ptr[idx];
}
const ValueType& UniquePtr::operator[](const size_t idx) const {
    return _ptr[idx];
}
    
UniquePtr::operator bool() const {
    return _ptr != nullptr;
}

void UniquePtr::reset() {
    delete[] _ptr;
    _ptr = nullptr;
}

void UniquePtr::reset(ValueType* ptr) {
    delete[] _ptr;
    _ptr = ptr;
}

void UniquePtr::release() {
    _ptr = nullptr;
}
