#include <cassert>

#include <UtilLib/General.h>

#include "Event.h"

using namespace ViewLib;

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///

EventHolder::EventHolder() : 
	Handlers()
{
}

void EventHolder::operator += (const EventHandler&& handler)
{
	Handlers.push_back(std::move(handler));
}

void EventHolder::RaiseEvent()
{
	for (auto handler : Handlers)
		handler();
}

///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///
///***///***///---\\\***\\\***\\\___///***___***\\\___///***///***///---\\\***\\\***///