#ifndef FASTEV_HTML_FOOTER
#define FASTEV_HTML_FOOTER

#include <sstream>
#include "../fastev/core/istring.hpp"

namespace fastev
{
    class Footer : public IString
    {
    private:
        std::string _text;

    public:
        Footer(std::string text);
        std::string str() override;
    };

    Footer::Footer(std::string text)
    {
        _text = text;
    }

    std::string Footer::str()
    {
        std::stringstream ss;
        ss << "<br><small>Powered by fastev " << _text << "</small>";
        return ss.str();
    }

} // namespace fastev

#endif