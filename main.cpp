#include "cwmods/cwmods.h"
#include "enums.h"

bool IsInRange(int min, int max, int v) {
	return (v >= min && v <= max);
}
int CalcMagicNumber(int x, int y) {
	int v1;
	int magicNumber;
	v1 = x + 0xb3f58 + y * 0x39;
	v1 = v1 ^ v1 * 0x2000;
	magicNumber = (100000 - ((v1 * v1 * 0xec4d + 0x131071f) * v1 + 0xd208dd0d &
		0x7fffffff) / 0x53e2) % 0x32;
	return magicNumber;
}
BiomeType CalcBiomeType(long param_1, int x, int y)
{
	if ((x + 1U < 3) && (y + 1U < 3)) {
		return Ocean;
	}
	int magicNumber = CalcMagicNumber(x, y);
	if (IsInRange(1, 10, magicNumber) || IsInRange(0xb, 0x1d, magicNumber))
		return Ocean;
	if (IsInRange(0x1e, 0x1f, magicNumber))
		return Darkwoods;
	if (IsInRange(0x20, 0x21, magicNumber))
		return Hills;
	if (IsInRange(0x22, 0x23, magicNumber))
		return Woodlands;
	if (IsInRange(0x24, 0x25, magicNumber))
		return Jungle;
	if (magicNumber == 0x26)
		return Firelands;
	if (magicNumber == 0x27)
		return SnowForest;
	if (IsInRange(0x28, 0x29, magicNumber))
		return Mountains;
	if (IsInRange(0x2A, 0x2B, magicNumber))
		return Wetlands;
	if (IsInRange(0x2C, 0x2D, magicNumber))
		return Desert;
	if (IsInRange(0x2E, 0x2F, magicNumber))
		return Savannah;
	if (IsInRange(0x30, 0x31, magicNumber))
		return Snowlands;
	if (magicNumber == 0x32)
		return Deadlands;
	if (IsInRange(0x33, 0x35, magicNumber)) {
		return Firelands;
	}
	return Plains;
}
void OverwriteBiomeFunction() {
	WriteFarJMP(CWOffset(0x2B9080), (void*)((int*)&CalcBiomeType));
}
class BetterBiomes : GenericMod {
	virtual void Initialize() override {
		OverwriteBiomeFunction();
	}
};
EXPORT BetterBiomes* MakeMod() {
	return new BetterBiomes();
}