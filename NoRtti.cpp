#include "Implementation.h"
#include "Interface.h"
#include <memory>

std::unique_ptr<Interface> createObject() {
	return std::make_unique<Implementation>();
}