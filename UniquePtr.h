#pragma once

#include <cstdlib>

using ValueType = char;

class UniquePtr {
public:
    UniquePtr();
    explicit UniquePtr(ValueType* ptr);
    UniquePtr(const ValueType& o) = delete;
    UniquePtr(UniquePtr&& o) noexcept;
    UniquePtr(const UniquePtr& o) = delete;

    ~UniquePtr();

    UniquePtr& operator=(UniquePtr&& o) noexcept;
    UniquePtr& operator=(const UniquePtr& o) = delete;
    UniquePtr& operator=(ValueType* ptr);

    ValueType& operator*() const;
    ValueType* operator->() const;
    ValueType& operator[](const size_t idx);
    const ValueType& operator[](const size_t idx) const;
    ValueType* get() const;
    operator bool() const;

    void reset();
    void reset(ValueType* ptr);
    void release();
private:
    ValueType* _ptr;
};
