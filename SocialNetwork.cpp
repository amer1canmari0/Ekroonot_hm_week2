#include "SocialNetwork.h"

void SocialNetwork::init(const std::string& networkName, int minAge)
{
    _networkName = networkName;
    _minAge = minAge;
    _profiles.init();
}

void SocialNetwork::clear()
{
    _profiles.clear();
    _profiles.init();
}

std::string SocialNetwork::getNetworkName() const
{
    return _networkName;
}

int SocialNetwork::getMinAge() const
{
    return _minAge;
}

bool SocialNetwork::addProfile(const Profile& profile_to_add)
{
    if ((int)profile_to_add.getOwner().getAge() < _minAge)
        return false;
    _profiles.add(profile_to_add);
    return true;
}

std::string SocialNetwork::getWindowsDevices() const
{
    std::string result = "";
    bool first = true;
    ProfileNode* pCurr = _profiles.get_first();
    while (pCurr != nullptr)
    {
        const Profile& prof = pCurr->get_data();
        const User& owner = prof.getOwnerRef();
        DeviceNode* dCurr = owner.getDevices().get_first();
        while (dCurr != nullptr)
        {
            const Device& dev = dCurr->get_data();
            std::string os = dev.getOS();
            if (os.find("Windows") != std::string::npos)
            {
                if (!first)
                    result += ", ";
                result += "[" + std::to_string(dev.getID()) + ", " + os + "]";
                first = false;
            }
            dCurr = dCurr->get_next();
        }
        pCurr = pCurr->get_next();
    }
    return result;
}