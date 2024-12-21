#ifndef LAB3_BOOK_H
#define LAB3_BOOK_H

#include "Pages.h"
#include "vector.hpp"

class Book
{
private:
    DynamicArray<Page> book_;
public:
    Book() = default;
    
    void append(Page& insert_page)
    {
        book_.push_back(insert_page);
    }
    
    Book(DynamicArray<Page>& book)
    {
        book_ = book;
    }
    
    Book(DynamicArray<Page>&& other) noexcept
        : book_(std::move(other)) {};
    
    size_t GetPageCount()
    {
        return book_.get_size();
    }
    
    Page GetPage(int i)
    {
        return book_[i];
    }
};

#endif //LAB3_BOOK_H
