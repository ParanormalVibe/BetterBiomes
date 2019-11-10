#include "cwmods/cwmods.h"
#include <string>

int CalcBiomeType(long param_1, int x, int y)
{
	int v1;
	int biomeType;

	if ((x + 1U < 3) && (y + 1U < 3)) {
		return 1;
	}
	biomeType = 0;
	v1 = x + 0xb3f58 + y * 0x39;
	v1 = v1 ^ v1 * 0x2000;
	switch ((100000 - ((v1 * v1 * 0xec4d + 0x131071f) * v1 + 0xd208dd0d &
		0x7fffffff) / 0x53e2) % 0x32) {
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
	case 0xb:
	case 0xc:
	case 0xd:
	case 0xe:
	case 0xf:
	case 0x10:
	case 0x11:
	case 0x12:
	case 0x13:
	case 0x14:
	case 0x15:
	case 0x16:
	case 0x17:
	case 0x18:
	case 0x19:
	case 0x1a:
	case 0x1b:
	case 0x1c:
	case 0x1d:
		return 1;
	case 0x1e:
	case 0x1f:
		return 5;
	case 0x20:
	case 0x21:
		return 2;
	case 0x22:
	case 0x23:
		return 3;
	case 0x24:
	case 0x25:
		return 4;
	case 0x26:
		return 0xd;
	case 0x27:
		return 6;
	case 0x28:
	case 0x29:
		return 7;
	case 0x2A:
	case 0x2B:
		return 8;
	case 0x2C:
	case 0x2D:
		return 9;
	case 0x2E:
	case 0x2F:
		return 10;
	case 0x30:
	case 0x31:
		return 0xb;
	case 0x32:
		return 0xc;
	case 0x33:
	case 0x34:
	case 0x35:
		return 0xd;
	}
	return biomeType;
}

void OverwriteBiomeFunction() {
	auto funAddr = &CalcBiomeType;
	WriteFarJMP(CWOffset(0x2B9080), reinterpret_cast<void*&>(funAddr));
}


class BetterBiomes : GenericMod {
	virtual void Initialize() override {
		OverwriteBiomeFunction();
	}
};

EXPORT BetterBiomes* MakeMod() {
	return new BetterBiomes();
}