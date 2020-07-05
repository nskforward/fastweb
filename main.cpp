#include "fastev/http/server.hpp"
#include "html/page.hpp"
#include "html/header.hpp"
#include "html/footer.hpp"
#include "version.hpp"
#include <atomic>

using namespace fastev;

int main()
{
    try
    {
        std::atomic_ulong visits = 0;
        Logger::log(LogLevel::INFO, "app version is %s", _APP_VERSION);
        auto s = HTTPServer(8080);
        s.onConnect([](int fd, struct sockaddr &addr) {
            char ip[16];
            Logger::log(LogLevel::INFO, "[fd:%d] connect from %s", fd, TCPSocket::addrToStr(addr, ip));
        });
        s.onDisonnect([](int fd, int worker_id) {
            Logger::log(LogLevel::INFO, "[fd:%d] disconnected", fd);
        });
        s.onRequest([&visits](Request &req) {
            auto page = HTMLPage("Home page");
            auto header = Header(page.title());
            auto login_form = Template("tpl/login_form.html");
            auto footer = Footer(_APP_VERSION);
            page << header;
            page << login_form;
            page.body() << "<p>visits: " << ++visits << "</p>";
            page << footer;
            req.answer(page.str());
        });
        s.start();
    }
    catch (std::exception &e)
    {
        Logger::log(LogLevel::FATAL_ERROR, e.what());
    }
}