#pragma once
#include <map>
#include <memory>
#include <queue>

class CEventClient;

template <class T>
class CEventPool
{
public:
	CEventPool()
	{
	}
	~CEventPool()
	{
	}

	void subscribe(std::shared_ptr<CEventClient> client)
	{
		if (mMailBoxes.find(client) == mMailBoxes.end())
		{
			mMailBoxes[client] = std::queue<T>();
		}
	}

	void post(std::shared_ptr<CEventClient> sender, T event, bool postToSelf)
	{
		for (auto& mailBox : mMailBoxes)
		{
			if (postToSelf || mailBox.first != sender)
				mailBox.second.push(event);
		}
	}

	std::queue<T> getMail(std::shared_ptr<CEventClient> client)
	{
		auto mailBox = mMailBoxes.find(client);
		if (mailBox != mMailBoxes.end())
		{
			std::queue<T> cpy = mailBox->second;
			while (!mailBox->second.empty())
			{
				mailBox->second.pop();
			}
			return cpy;
		}
			

		return std::queue<T>();
	}


private:
	std::map<std::shared_ptr<CEventClient>, std::queue<T>> mMailBoxes;
};
