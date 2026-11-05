#pragma once
#include <string>
#include "User.h"
#include "Page.h"
#include "UserList.h"

class Profile
{
private:
    User _owner;
    Page _page;
    UserList _friends;

public:
    Profile();
    Profile(const Profile& other);
    Profile& operator=(const Profile& other);
    ~Profile();

    void init(const User& owner);
    void clear();

    User getOwner() const;
    const User& getOwnerRef() const { return _owner; }
    void setStatus(const std::string& new_status);
    void addPostToProfilePage(const std::string& post);
    void addFriend(const User& friend_to_add);

    std::string getPage() const;
    std::string getFriends() const;
    std::string getFriendsWithSameNameLength() const;

    // Bonus
    void changeAllWordsInStatus(const std::string& word);
    void changeWordInStatus(const std::string& word_to_replace, const std::string& new_word);
};