#pragma once
#include <memory>
#include "CEventPool.h"
#include "IEvent.h"


class CEventClient : public std::enable_shared_from_this<CEventClient>
{
public:
	CEventClient(std::shared_ptr<CEventPool> eventPool)
		: mEventPool(eventPool)
	{
		
	}

	~CEventClient()
	{
	}

	template <class T>
	void send(T anEvent)
	{
		mEventPool->publish(anEvent);
	}

	template <class T>
	void subscribe()
	{
		std::list<T> eventList;
		mEventPool->subscribe<T>(shared_from_this());
	}

	template <class T>
	void addEvent(T anEvent)
	{
		mEvents.push_back(anEvent);
	}

	template <class T>
	std::list<T> getEvents()
	{
		std::list<T> events;
		auto typeIndex = std::type_index(typeid(T));		

		if (mEvents.find(typeIndex) == mEvents.end())
			return events;

		for (auto event : mEvents[typeIndex])
		{
			events.push_back(event);
			// Use queue and pop
		}
		return events;
	}

private:
	std::shared_ptr<CEventPool> mEventPool;
	std::map<std::type_index, > mEvents;
};
