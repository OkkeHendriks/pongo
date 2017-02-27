#pragma once
#include <queue>

#include "CEventPool.h"

class CEventClient : public std::enable_shared_from_this<CEventClient>
{
private:
	CEventClient() = default;
	CEventClient(const CEventClient& o) = default;
public:
	~CEventClient() = default;

	template<typename ... T>
	static std::shared_ptr<CEventClient> create(T&& ... args) {
		return std::shared_ptr<CEventClient>(new CEventClient(std::forward<T>(args)...));
	}

	template <class T>
	void subscribe()
	{
		pool<T>()->subscribe(shared_from_this());
	}

	template <class T>
	void post(T event, bool postToSelf = false)
	{
		pool<T>()->post(shared_from_this(), event, postToSelf);
	}

	template <class T>
	std::queue<T> getMail()
	{
		return pool<T>()->getMail(shared_from_this());
	}

private:
	template <class T>
	static std::shared_ptr<CEventPool<T>>& pool()
	{
		static std::shared_ptr<CEventPool<T>> pool = std::make_shared<CEventPool<T>>();
		return pool;
	}
};
