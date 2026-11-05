#include "Page.h"

void Page::init()
{
    _status = "";
    _posts = "";
}

std::string Page::getPosts() const
{
    return _posts;
}

std::string Page::getStatus() const
{
    return _status;
}

void Page::clearPage()
{
    _posts = "";
}

void Page::setStatus(const std::string& status)
{
    _status = status;
}

void Page::addLineToPosts(const std::string& new_line)
{
    if (_posts.empty())
        _posts = new_line;
    else
        _posts += "\n" + new_line;
}
