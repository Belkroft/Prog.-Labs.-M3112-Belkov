#ifndef LAB7_CIRC_BUFF_HPP
#define LAB7_CIRC_BUFF_HPP

#pragma once
#include <iterator>

template<class T>
class circ_buff {

public:

    typedef T value_type;
    typedef T &reference;
    typedef const T &const_reference;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;

    explicit circ_buff(size_type capacity); // co
    ~circ_buff(); // de

    void push_back(T val);
    void push_front(T val);
    void pop_back();
    void pop_front();

    reference operator[](size_type index);
    const_reference operator[](size_type index) const;
    size_type size() const;
    void resize(size_type new_size);

    class iterator : public std::iterator<std::random_access_iterator_tag, T> {
    private:
        size_type pos_{};
        circ_buff<T> *buff;
    public:
        iterator() = default;

        iterator(circ_buff<T> *buff, size_type pos);

        reference operator*();

        iterator &operator++();

        iterator &operator--();

        iterator &operator+=(int val);

        iterator &operator-=(int val);

        iterator operator+(int val) const;

        iterator operator-(int val) const;

        iterator operator+(const iterator &other) const;


        difference_type operator-(const iterator &other) const;


        bool operator==(const iterator &other) const;

        bool operator!=(const iterator &other) const;

        bool operator<(const iterator &other) const;

        bool operator<=(const iterator &other) const;

        bool operator>(const iterator &other) const;

        bool operator>=(const iterator &other) const;

    };

    iterator begin();
    iterator end();

    iterator insert(const iterator &pos, T val);
    iterator erase(const iterator &pos);

private:

    size_type capacity_;
    value_type *data;
    size_type start;
    size_type fin;

    size_type increment(size_type pos, short val) const;
    size_type decrement(size_type pos, short val) const;
    void copy_data(value_type *destination, size_type num) const;
};

#include "buff_func.hpp"

#endif //LAB7_CIRC_BUFF_HPP
