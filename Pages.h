#ifndef LAB3_PAGES
#define LAB3_PAGES
#include "ArraySequence.h"
#include "Rows.h"
#include "vector.hpp"
class Page
{
private:
    Vector<Row> page_;
public:
    Page() = default;
    
    Page(Vector<Row>& page)
    {
        page_ = page;
    }
    Page(Vector<Row>&& other) noexcept
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


Vector<Page> PageMaker(Vector<Row>& rows, int page_size)
{
    Vector<Page> result;
    int count = 0;
    Vector<Row> buf;
    //Page item;
    for (int i = 0; i < rows.get_size(); i++)
    {
        buf.push_back(rows[i]);
        count++;
        if (count == page_size)
        {
            Page item(buf);
            result.push_back(item);
            std::cout << "programm was hear" << std::endl;
            for (int i = 0; i < buf.get_size(); i++)
            {
                std::cout << buf[i].get() << std::endl;
            }
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
//ArraySequence<Page> PageMaker(ArraySequence<Row>& rows, int page_size)
//{
//    ArraySequence<Page> result;
//    int count_move = rows.GetLength() / page_size;
//    int count_end = rows.GetLength() % page_size;
//    ArraySequence<Row> lines;
////    for (int i = 0; i < count_move; i += page_size)
////    {
////        std::cout << "program was hear" << std::endl;
////        lines = rows.getSubSequence(i, i + page_size);
////        Page item(lines);
////        result.Append(item);
////    }
//    for (int i = 0; i < count_move; i++)
//    {
//        lines = std::move(rows.getSubSequence(i, i + page_size - 1));
//        Page item(std::move(lines));
//        result.Append(std::move(item));
//    }
//    std::cout << "programm was here" << std::endl;
//    if (count_end != 0)
//    {
//        lines = rows.getSubSequence(rows.GetLength() - count_end, rows.GetLength());
//        Page item2(lines);
//        result.Append(item2);
//    }
//    return result;
//}

//#pragma once
//#include "ArraySequence.h"
//#include "Rows.h"
//
//class Page
//{
//private:
//    ArraySequence<Row> rows_; // Массив строк на странице
//
//public:
//    Page() = default;
//
//    explicit Page(const ArraySequence<Row>& rows)
//        : rows_(rows)
//    {
//    }
//
//    explicit Page(ArraySequence<Row>&& rows) noexcept
//        : rows_(std::move(rows))
//    {
//    }
//
//    Page(const Page& other) = default; // Конструктор копирования
//    Page(Page&& other) noexcept = default; // Конструктор перемещения
//    Page& operator=(const Page& other) = default; // Оператор присваивания копированием
//    Page& operator=(Page&& other) noexcept = default; // Оператор присваивания перемещением
//
//    void append(const Row& row)
//    {
//        rows_.Append(row);
//    }
//
//    Row getRow(int index) const
//    {
//        return rows_.Get(index);
//    }
//
//    int getRowCount() const
//    {
//        return rows_.GetLength();
//    }
//
//    ~Page() = default;
//};
//
//ArraySequence<Page> paginate(const ArraySequence<Row>& rows, int rows_per_page)
//{
//    ArraySequence<Page> pages;
//    int total_rows = rows.GetLength();
//    ArraySequence<Row> current_page_rows;
//
//    for (int i = 0; i < total_rows; ++i)
//    {
//        current_page_rows.Append(rows[i]);
//
//        if (current_page_rows.GetLength() == rows_per_page)
//        {
//            pages.Append(Page(std::move(current_page_rows))); // Создаем Page и перемещаем строки
//            current_page_rows.Clear(); // Очищаем текущий буфер
//        }
//    }
//
//    if (current_page_rows.GetLength() > 0) // Добавляем оставшиеся строки
//    {
//        pages.Append(Page(std::move(current_page_rows)));
//    }
//
//    return pages;
//}
//


#endif //LAB3_PAGES
