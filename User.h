#pragma once
#include <string>
#include "DeviceList.h"

class User
{
private:
    unsigned int _id;
    std::string _username;
    unsigned int _age;
    DevicesList _devices;

public:
    User();
    User(const User& other);
    User& operator=(const User& other);
    ~User();

    void init(unsigned int id, const std::string& username, unsigned int age);
    void clear();

    unsigned int getID() const;
    std::string getUserName() const;
    unsigned int getAge() const;
    DevicesList& getDevices();
    const DevicesList& getDevices() const;

    void addDevice(const Device& newDevice);
    bool checkIfDevicesAreOn() const;
};