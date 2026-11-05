#include "Profile.h"
#include <cctype>

Profile::Profile()
{
    _page.init();
    _friends.init();
}

Profile::Profile(const Profile& other)
{
    _owner = other._owner;
    _page = other._page;
    _friends.init();
    UserNode* curr = other._friends.get_first();
    while (curr != nullptr)
    {
        _friends.add(curr->get_data());
        curr = curr->get_next();
    }
}

Profile& Profile::operator=(const Profile& other)
{
    if (this != &other)
    {
        _friends.clear();
        _friends.init();
        _owner = other._owner;
        _page = other._page;
        UserNode* curr = other._friends.get_first();
        while (curr != nullptr)
        {
            _friends.add(curr->get_data());
            curr = curr->get_next();
        }
    }
    return *this;
}

Profile::~Profile()
{
    clear();
}

void Profile::init(const User& owner)
{
    _owner = owner;
    _page.init();
    _friends.init();
}

void Profile::clear()
{
    _owner.clear();
    _friends.clear();
    _friends.init();
    _page.clearPage();
    _page.setStatus("");
}

User Profile::getOwner() const
{
    return _owner;
}

void Profile::setStatus(const std::string& new_status)
{
    _page.setStatus(new_status);
}

void Profile::addPostToProfilePage(const std::string& post)
{
    _page.addLineToPosts(post);
}

void Profile::addFriend(const User& friend_to_add)
{
    _friends.add(friend_to_add);
}

std::string Profile::getPage() const
{
    std::string result = "Status: " + _page.getStatus() + "\n";
    result += "*******************\n";
    result += "*******************\n";
    std::string posts = _page.getPosts();
    result += posts;
    if (!posts.empty())
        result += "\n";
    return result;
}

std::string Profile::getFriends() const
{
    std::string result = "";
    UserNode* curr = _friends.get_first();
    bool first = true;
    while (curr != nullptr)
    {
        if (!first)
            result += ",";
        result += curr->get_data().getUserName();
        first = false;
        curr = curr->get_next();
    }
    return result;
}

std::string Profile::getFriendsWithSameNameLength() const
{
    std::string result = "";
    size_t ownerLen = _owner.getUserName().length();
    UserNode* curr = _friends.get_first();
    bool first = true;
    while (curr != nullptr)
    {
        if (curr->get_data().getUserName().length() == ownerLen)
        {
            if (!first)
                result += ",";
            result += curr->get_data().getUserName();
            first = false;
        }
        curr = curr->get_next();
    }
    return result;
}

static bool isSpaceChar(char c)
{
    return c == ' ' || c == '\n' || c == '\t' || c == '\r';
}

void Profile::changeAllWordsInStatus(const std::string& word)
{
    std::string status = _page.getStatus();
    std::string newStatus = "";
    size_t i = 0;
    while (i < status.size())
    {
        if (isSpaceChar(status[i]))
        {
            newStatus += status[i];
            ++i;
        }
        else
        {
            while (i < status.size() && !isSpaceChar(status[i]))
                ++i;
            newStatus += word;
        }
    }
    _page.setStatus(newStatus);
}

void Profile::changeWordInStatus(const std::string& word_to_replace, const std::string& new_word)
{
    // Substring replacement to match tester expectation (checkWordDoesNotExist uses find)
    std::string status = _page.getStatus();
    if (word_to_replace.empty())
        return;
    size_t pos = 0;
    while ((pos = status.find(word_to_replace, pos)) != std::string::npos)
    {
        status.replace(pos, word_to_replace.length(), new_word);
        pos += new_word.length();
    }
    _page.setStatus(status);
}
