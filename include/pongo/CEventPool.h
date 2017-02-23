#pragma once
#include <map>
#include <typeindex>
#include <memory>
#include <list>

class CEventClient;

class CEventPool
{
public:
	CEventPool();
	~CEventPool();

	template <class T>
	void publish(T anEvent)
	{
		auto typeIndex = std::type_index(typeid(T));
		if (events.find(typeIndex) != events.end())
		{
			for (auto& subscriber : events[typeIndex])
			{
				subscriber.addEvent(anEvent);
			}
		}
	}

	template <class T>
	void subscribe(std::shared_ptr<CEventClient> client)
	{
		auto typeIndex = std::type_index(typeid(T));
		if (events.find(typeIndex) == events.end())
		{
			events[typeIndex] = std::list<std::shared_ptr<CEventClient>>();
		}
		events[typeIndex].push_back(client);
	}

private:
	std::map<std::type_index, std::list<std::shared_ptr<CEventClient>>> events;
};

CEventPool::CEventPool()
{
}

CEventPool::~CEventPool()
{
}