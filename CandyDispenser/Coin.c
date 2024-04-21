#include "Coin.h"
Coin makeCoin(int denomination) {
	if (denomination < 0 || denomination % 100 == 0)
	{
		return;
	}
	Coin rtn;
	rtn.denomination = denomination;
	return rtn;
}