#include "cwmods/cwmods.h"
#include <string>

class BetterBiomes : GenericMod {
	virtual void Initialize() override {
		// This will be called after your mod is loaded. CWSDK internals are initialized at this point, so it's safe to use CWBase() and CWOffset().
	}
};

EXPORT BetterBiomes* MakeMod() {
	return new BetterBiomes();
}
