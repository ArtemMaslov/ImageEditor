#pragma once

#include <vector>
#include <functional>
#include <future>

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

namespace ViewLib
{
	class EventHolder
	{
		using EventHandler = std::function<void()>;
	public:
		EventHolder();

		void operator += (const EventHandler&& handler);

		void RaiseEvent();

	private:
		std::vector<EventHandler> Handlers;
	};
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///