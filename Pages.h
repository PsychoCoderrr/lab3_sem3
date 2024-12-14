#ifndef LAB3_PAGES
#define LAB3_PAGES
#include "ArraySequence.h"
#include "Rows.h"

class Page
{
private:
    ArraySequence<Row> page_;
public:
    Page() = default;
    
    Page(ArraySequence<Row>& page)
    {
        page_ = page;
    }
    
    void append(Row& line)
    {
        page_.Append(line);
    }
    
};

#endif //LAB3_PAGES
