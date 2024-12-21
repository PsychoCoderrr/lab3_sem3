#ifndef LAB3_PAGES
#define LAB3_PAGES

#include "Rows.h"
#include "DynamicArray.hpp"

class Page
{
private:
    DynamicArray<Row> page_;
public:
    Page() = default;
    
    Page(DynamicArray<Row>& page)
    {
        page_ = page;
    }
    Page(DynamicArray<Row>&& other) noexcept
        : page_(std::move(other)) {};
    
    void append(Row& line)
    {
        page_.push_back(line);
    }
    
    Row getRow(int index) const
    {
        return page_[index];
    }
    
    size_t getPageSize()
    {
        return page_.get_size();
    }
    ~Page() = default;
};


DynamicArray<Page> PageMaker(DynamicArray<Row>& rows, int page_size)
{
    DynamicArray<Page> result;
    int count = 0;
    DynamicArray<Row> buf;
    for (int i = 0; i < rows.get_size(); i++)
    {
        buf.push_back(rows[i]);
        count++;
        if (count == page_size)
        {
            Page item(buf);
            result.push_back(item);
            buf.erase(buf.begin(), buf.end());
            count = 0;
        }
    }
    if (buf.get_size() != 0)
    {
        Page item2(buf);
        result.push_back(std::move(item2));
        buf.erase(buf.begin(), buf.end());
    }
    return result;
}

#endif //LAB3_PAGES
