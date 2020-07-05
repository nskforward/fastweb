#ifndef FASTEV_HTML_HEADER
#define FASTEV_HTML_HEADER

#include <sstream>
#include "../fastev/core/istring.hpp"

namespace fastev
{
    class Header : public IString
    {
    private:
        std::string _text;

    public:
        Header(std::string text);
        std::string str() override;
    };

    Header::Header(std::string text)
    {
        _text = text;
    }

    std::string Header::str()
    {
        std::stringstream ss;
        ss << "<h1>" << _text << "</h1>";
        return ss.str();
    }

} // namespace fastev

#endif