#include "circ_buff.hpp"

template<class T>
circ_buff<T>::circ_buff(circ_buff::size_type capacity) {
    capacity_ = capacity;
    data = new value_type[capacity_ + 1];
    start = 0;
    fin = 0;
}

template<class T>
circ_buff<T>::~circ_buff() {
    delete[] data;
}

template<class T>
void circ_buff<T>::push_back(T val) {
    if (fin == decrement(start, 1))
        start = increment(start, 1);
    data[fin] = val;
    fin = increment(fin, 1);
}
template<class T>
void circ_buff<T>::push_front(T val) {
    if (fin == decrement(start, 1)) {
        fin = decrement(fin, 1);
    }
    start = decrement(start, 1);
    data[start] = val;
}

template<class T>
void circ_buff<T>::pop_back() {
    fin = decrement(fin, 1);
}
template<class T>
void circ_buff<T>::pop_front() {
    start = increment(start, 1);
}

template<class T>
typename circ_buff<T>::reference circ_buff<T>::operator[](circ_buff::size_type index) {
    return data[increment(start, index)];
}

template<class T>
typename circ_buff<T>::const_reference circ_buff<T>::operator[](circ_buff::size_type index) const {
    return data[increment(index, start)];
}

template<class T>
typename circ_buff<T>::size_type circ_buff<T>::size() const {
    return decrement(fin, start);
}

template<class T>
void circ_buff<T>::resize(circ_buff::size_type new_size) {
    auto new_data = new value_type[new_size + 1];
    copy_data(new_data, std::min(decrement(fin, start), new_size));
    delete[] data;
    data = new_data;
    capacity_ = new_size;
    start = 0;
    fin = new_size;
}

template<class T>
typename circ_buff<T>::iterator circ_buff<T>::begin() {
    return iterator(this, 0);
}
template<class T>
typename circ_buff<T>::iterator circ_buff<T>::end() {
    return iterator(this, fin);
}

template<class T>
typename circ_buff<T>::iterator circ_buff<T>::insert(const circ_buff::iterator &pos, T val) {
    auto elem = pos;
    T temp = val;
    fin = increment(fin, 1);
    for (; elem != end(); ++elem) {
        std::swap(*elem, temp);
    }
    if (fin == start)
        start = increment(start, 1);
    return pos;
}

template<class T>
typename circ_buff<T>::iterator circ_buff<T>::erase(const circ_buff::iterator &pos) {
    auto elem = end() - 1;
    T temp = *elem;
    for (; pos <= elem; --elem) {
        std::swap(*elem, temp);
    }
    fin = decrement(fin, 1);
    return pos;
}

template<class T>
circ_buff<T>::iterator::iterator(circ_buff<T> *buff, circ_buff::size_type pos) {
    this->pos_ = pos;
    this->buff = buff;
}

template<class T>
typename circ_buff<T>::reference circ_buff<T>::iterator::operator*() {
    return (*buff)[pos_];
}

template<class T>
typename circ_buff<T>::iterator &circ_buff<T>::iterator::operator++() {
    pos_ = buff->increment(pos_, 1);
    return *this;
}

template<class T>
typename circ_buff<T>::iterator &circ_buff<T>::iterator::operator--() {
    pos_ = buff->decrement(pos_, 1);
    return *this;
}

template<class T>
typename circ_buff<T>::iterator &circ_buff<T>::iterator::operator+=(int val) {
    pos_ = buff->increment(pos_, val);
    return *this;
}

template<class T>
typename circ_buff<T>::iterator &circ_buff<T>::iterator::operator-=(int val) {
    pos_ = buff->decrement(pos_, val);
    return *this;
}

template<class T>
typename circ_buff<T>::iterator circ_buff<T>::iterator::operator+(int val) const {
    return iterator(buff, buff->increment(pos_, val));
}

template<class T>
typename circ_buff<T>::iterator circ_buff<T>::iterator::operator-(int val) const {
    return iterator(buff, buff->decrement(pos_, val));
}

template<class T>
typename circ_buff<T>::iterator
circ_buff<T>::iterator::operator+(const circ_buff::iterator &other) const {
    return iterator(buff, buff->decrement(pos_, other.pos_));
}

template<class T>
typename circ_buff<T>::difference_type
circ_buff<T>::iterator::operator-(const circ_buff::iterator &other) const {
    return buff->decrement(pos_, other.pos_);
}

template<class T>
bool circ_buff<T>::iterator::operator==(const circ_buff::iterator &other) const {
    return pos_ == other.pos_;
}

template<class T>
bool circ_buff<T>::iterator::operator!=(const circ_buff::iterator &other) const {
    return !(*this == other);
}

template<class T>
bool circ_buff<T>::iterator::operator<(const circ_buff::iterator &other) const {
    if ((pos_ < buff->start && other.pos_ < buff->start) || (pos_ >= buff->start && other.pos_ >= buff->start)) {
        return pos_ < other.pos_;
    } else
        return pos_ > other.pos_;
}

template<class T>
bool circ_buff<T>::iterator::operator<=(const circ_buff::iterator &other) const {
    return *this < other || *this == other;
}

template<class T>
bool circ_buff<T>::iterator::operator>(const circ_buff::iterator &other) const {
    return !(*this < other);
}

template<class T>
bool circ_buff<T>::iterator::operator>=(const circ_buff::iterator &other) const {
    return *this > other || *this == other;
}


template<class T>
typename circ_buff<T>::size_type circ_buff<T>::increment(circ_buff::size_type pos, short val) const {
    return (pos + val) % (capacity_ + 1);
}

template<class T>
typename circ_buff<T>::size_type circ_buff<T>::decrement(circ_buff::size_type pos, short val) const {
    return (pos + capacity_ + 1 - val) % (capacity_ + 1);
}

template<class T>
void circ_buff<T>::copy_data(value_type *destination, circ_buff::size_type num) const {
    for (unsigned long long i = 0; i < num; i++) {
        destination[i] = (*this)[i];
    }
}