#include "SignalW.hpp"

#include <ctime>

using namespace Signal;

int SignalW::nextId = 1;

SignalW::SignalW(int id, int force) : id(id), force(force), slotFrom(-1)
{
	if (id == -1)
		id = time(NULL);
}
