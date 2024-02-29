#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <sstream>
#include <iomanip>
#include <utility>

template<typename T>
class Array {
public:
    Array() : len(0), buf(nullptr) {}

    explicit Array(int len) : len(len), buf(new T[len]) {}

    Array(const Array& other) : len(other.len), buf(new T[other.len]) {
        for (int i = 0; i < len; ++i) {
            buf[i] = other.buf[i];
        }
    }

    Array(Array&& other) noexcept : len(0), buf(nullptr) {
        swap(*this, other);
    }

    friend void swap(Array& lhs, Array& rhs) noexcept {
        std::swap(lhs.len, rhs.len);
        std::swap(lhs.buf, rhs.buf);
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            Array temp(other);
            swap(*this, temp);
        }
        return *this;
    }

    Array& operator=(Array&& other) noexcept {
        swap(*this, other);
        return *this;
    }

    ~Array() {
        delete[] buf;
    }

    int length() const {
        return len;
    }

    T& operator[](int index) {
        return buf[index];
    }

    const T& operator[](int index) const {
        return buf[index];
    }

    void fill(const T& val) {
        for (int i = 0; i < len; ++i) {
            buf[i] = val;
        }
    }

private:
    int len;
    T* buf;
};

template<typename T>
inline std::ostream& operator<<(std::ostream& out, const Array<T>& array) {
    std::ostringstream temp;
    temp << std::setprecision(2) << std::fixed << std::right;

    for (int i = 0; i < array.length(); ++i) {
        temp << std::setw(8) << array[i];
    }

    out << temp.str();
    return out;
}

template<typename T>
inline std::istream& operator>>(std::istream& in, Array<T>& array) {
    for (int i = 0; i < array.length(); ++i) {
        in >> array[i];
    }
    return in;
}

#endif
