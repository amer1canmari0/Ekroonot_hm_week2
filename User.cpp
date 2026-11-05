#include "User.h"

User::User()
    : _id(0), _username(), _age(0)
{
    _devices.init();
}

User::User(const User& other)
    : _id(other._id), _username(other._username), _age(other._age)
{
    _devices.init();
    for (DeviceNode* current = other._devices.get_first(); current != nullptr;
         current = current->get_next())
    {
        _devices.add(current->get_data());
    }
}

User& User::operator=(const User& other)
{
    if (this != &other)
    {
        _devices.clear();
        _id = other._id;
        _username = other._username;
        _age = other._age;
        for (DeviceNode* current = other._devices.get_first(); current != nullptr;
             current = current->get_next())
        {
            _devices.add(current->get_data());
        }
    }
    return *this;
}

User::~User()
{
    _devices.clear();
}

void User::init(unsigned int id, const std::string& username, unsigned int age)
{
    _devices.clear();
    _id = id;
    _username = username;
    _age = age;
}

void User::clear()
{
    _devices.clear();
    _id = 0;
    _username.clear();
    _age = 0;
}

unsigned int User::getID() const
{
    return _id;
}

std::string User::getUserName() const
{
    return _username;
}

unsigned int User::getAge() const
{
    return _age;
}

DevicesList& User::getDevices()
{
    return _devices;
}

const DevicesList& User::getDevices() const
{
    return _devices;
}

void User::addDevice(const Device& newDevice)
{
    _devices.add(newDevice);
}

bool User::checkIfDevicesAreOn() const
{
    for (DeviceNode* current = _devices.get_first(); current != nullptr;
         current = current->get_next())
    {
        if (!current->get_data().isActive())
            return false;
    }
    return true;
}
