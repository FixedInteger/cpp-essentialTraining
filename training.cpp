
#include <iostream>
#include <list>

class youtubeChannel
{
    private :
        std::string _name;
        std::string _ownerName;
        int _subscriberCount;
        std::list<std::string> _publishedVideoTitles;
    public :
    youtubeChannel(std::string name, std::string ownerName)
    {
        _name = name;
        _ownerName = ownerName;
        _subscriberCount = 0;
    }
    void getChannelInfo()
    {
        std::cout << "Name: " << _name << std::endl;
        std::cout << "OwnerName: " << _ownerName << std::endl;
        std::cout << "SubscriberCount: " << _subscriberCount << std::endl;
        std::cout << "Videos: " << std::endl;
        for(std::list<std::string>::iterator it = _publishedVideoTitles.begin(); it != _publishedVideoTitles.end(); ++it)
            std::cout << *it << std::endl;
    }
    void subscribe()
    {
        _subscriberCount++;
    }
    void unsubscribe()
    {
        if(_subscriberCount > 0)
            _subscriberCount--;
    }

};
int main()
{
    youtubeChannel ytChannel("CodeBeauty", "Saldina");
    ytChannel.subscribe();
    ytChannel.subscribe();
    ytChannel.subscribe();
    ytChannel.getChannelInfo();
    return 0;
}