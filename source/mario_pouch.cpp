#include "spm/mario_pouch.h"
#include <wii/types.h>

namespace spm::mario_pouch
{
	MarioPouchWork* pouchGetPtr()
	{
		return &marioPouchWork;
	}
	
	s32 pouchGetTotalCoinsCollected()
	{
		return marioPouchWork.totalCoinsCollected;
	}
	
	void pouchSetCoin(s32 targetCoins)
	{
		marioPouchWork.coins = targetCoins;
		
		if (marioPouchWork.coins > COIN_MAX) marioPouchWork.coins = COIN_MAX;
		if (marioPouchWork.coins < COIN_MIN) marioPouchWork.coins = COIN_MIN;
		
		return;
	}
	
	void pouchAddCoin(s32 coinsToAdd)
	{
		marioPouchWork.coins += coinsToAdd;
		
		if (marioPouchWork.coins > COIN_MAX) marioPouchWork.coins = COIN_MAX;
		if (marioPouchWork.coins < COIN_MIN) marioPouchWork.coins = COIN_MIN;
		
		if (coinsToAdd > 0)
		{
			marioPouchWork.totalCoinsCollected += coinsToAdd;
			if (marioPouchWork.totalCoinsCollected > TOTAL_COIN_MAX) marioPouchWork.totalCoinsCollected = TOTAL_COIN_MAX;
		}
		
		return;
	}
	
	void pouchSetAttack(s32 targetAttack)
	{
		marioPouchWork.attack = targetAttack;
		
		if (targetAttack > MAX_ATTACK) marioPouchWork.attack = MAX_ATTACK;
		if (marioPouchWork.attack <= 0) marioPouchWork.attack = 1;
		
		return;
	}
	
	void pouchAddAttack(s32 attackToAdd)
	{
		marioPouchWork.attack += attackToAdd;
		
		if (marioPouchWork.attack > MAX_ATTACK) marioPouchWork.attack = MAX_ATTACK;
		if (marioPouchWork.attack <= 0) marioPouchWork.attack = 1;
		
		return;
	}
	
}