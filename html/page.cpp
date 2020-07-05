#include "page.hpp"

namespace fastev
{
    HTMLPage::HTMLPage(std::string title)
    {
        _title = title;
    }

    std::stringstream &HTMLPage::body()
    {
        return _body;
    }

    std::string HTMLPage::str()
    {
        std::stringstream ss;
        ss << "<!doctype html><html><head><meta charset=\"utf-8\"><title>" << _title << "</title></head><body>" << _body.str() << "</body></html>";
        return ss.str();
    }

    std::string HTMLPage::title()
    {
        return _title;
    }

} // namespace fastev