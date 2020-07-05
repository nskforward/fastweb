#ifndef FASTEV_HTML_PAGE
#define FASTEV_HTML_PAGE

#include <string>
#include <sstream>
#include "template.hpp"
#include "../fastev/core/istring.hpp"

namespace fastev
{
    class HTMLPage
    {
    private:
        std::string _title;
        std::stringstream _body;

    public:
        HTMLPage(std::string title);
        std::stringstream &body();
        std::string str();
        std::string title();
        void put(IString &object);

        friend HTMLPage &operator<<(HTMLPage &dst, IString &src)
        {
            dst.body() << src.str();
            return dst;
        }

        friend HTMLPage &operator<<(HTMLPage &dst, std::string src)
        {
            dst.body() << src;
            return dst;
        }
    };

} // namespace fastev

#endif