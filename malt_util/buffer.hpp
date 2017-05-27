//
// Created by Mehmet Fatih BAKIR on 29/04/2017.
//

#pragma once

#include <iterator>

namespace malt
{
    template <class ElemT>
    class buffer
    {
        struct deque_bucket;
    public:
        class iterator :
            public std::iterator<std::forward_iterator_tag, ElemT>
        {
            ElemT* elem;
            ElemT* bucket_end;

            friend class buffer;

            iterator(deque_bucket* e)
            {
                elem = e->elems;
                bucket_end = e->elems + bucket_size;
            }

            iterator(ElemT* e)
            {
                elem = e;
                bucket_end = nullptr;
            }

        public:
            iterator() = default;

            bool operator==(const iterator& rhs){
                return rhs.elem == elem;
            }
            bool operator!=(const iterator& rhs){
                return rhs.elem != elem;
            }
            iterator& operator++()
            {
                if (elem == bucket_end)
                {
                    auto next = reinterpret_cast<deque_bucket*>(elem);
                    elem = next->elems;
                    bucket_end = next->elems + bucket_size;
                    return *this;
                }
                ++elem;
                return *this;
            }

            ElemT* operator->()
            {
                return elem;
            }

            ElemT& operator*()
            {
                return *elem;
            }
        };

        using element_type = ElemT;
        static constexpr auto bucket_size = 8;

        size_t size()
        {
            return (last - first - 1) * bucket_size + (end_elem - last->elems);
        }

        size_t capacity()
        {
            return (last - first) * bucket_size;
        }

        template <class... Args>
        void emplace_back(Args&&... args)
        {

        }

        iterator begin()
        {
            return iterator(first);
        }

        iterator end()
        {
            return iterator(end_elem);
        }

    private:
        deque_bucket* first = nullptr;
        deque_bucket* last = nullptr;
        element_type* end_elem = nullptr;

        struct deque_bucket
        {
            element_type elems[bucket_size];
            deque_bucket* next;
        };
    };
}
