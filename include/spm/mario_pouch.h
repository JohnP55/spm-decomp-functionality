#pragma once

#include <types.h>

#define ITEM_ID_USE_START 0x41
#define ITEM_ID_USE_MAX 0xd8
#define ITEM_ID_MAP_START 0xea
#define ITEM_ID_MAP_MAX 0x11a
#define ITEM_ID_COOK_START 0x78
#define ITEM_ID_COOK_MAX 0xd8
#define ITEM_ID_CARD_START 0x11a
#define ITEM_ID_CARD_MAX 0x21a

#define COIN_MIN 0
#define COIN_MAX 999

#define TOTAL_COIN_MAX 99999

#define MAX_ATTACK 99

#define FLIP_TIMER_MAX 10

namespace spm::mario_pouch {

	struct PouchCharOrPixlInfo
	{
		bool selectable;
		bool selected;
		s16 itemType;
	};
	static_assert(sizeof(PouchCharOrPixlInfo) == 0x4);

	struct PouchMinigameScore
	{
		s32 characterId;
		s32 score;
		u8 unknown_0x8[0x18 - 0x8];
	};
	static_assert(sizeof(PouchMinigameScore) == 0x18);

	struct MarioPouchWork
	{
		u8 unknown_0x0[0x4 - 0x0]; // unused?
		s32 level;
		s32 attack;
		s32 hp;
		s32 maxHp;
		s32 flipTimer;
		s32 xp;
		s32 coins;
		s16 keyItem[32];
		s16 useItem[10];
		s16 shopItem[32];
		PouchCharOrPixlInfo characters[4];
		PouchCharOrPixlInfo pixls[16];
		s32 shopPos32s;
		u32 shopPos32RewardsCollected; // bit mask, index 1 << i
		s8 catchCards[256]; // value is count, index is id - first card id
		u8 unknown_0x20c[256];
		u32 ownedMaps[2]; // [id / 32] & 1 << (id % 32)
		u32 foundMaps[2]; // [id / 32] & 1 << (id % 32)
		u32 knownRecipes[3]; // [id / 32] & 1 << (id % 32)
		u32 knownCards[8]; // [id / 32] & 1 << (id % 32)
		s32 charmsRemaining;
		s32 killsBeforeNextCharm;
		u8 unknown_0x350[0x368 - 0x350];
		PouchMinigameScore minigameScores[4][5];
		u8 unknown_0x548[0x688 - 0x548];
		s32 arcadeTokens;
		s32 totalCoinsCollected;
		s32 maxJumpCombo;
		s32 maxStylishCombo;
		s32 enemiesDefeated;
		u8 unknown_0x69c[0x6a0 - 0x69c]; // unused?
	};
	static_assert(sizeof(MarioPouchWork) == 0x6a0);
	
	MarioPouchWork* pouchGetPtr();
	s32 pouchGetTotalCoinsCollected();
	void pouchSetCoin(s32 targetCoins);
	void pouchAddCoin(s32 coinsToAdd);
	void pouchSetAttack(s32 targetAttack);
	void pouchAddAttack(s32 attackToAdd);
	void pouchSetHp(s32 targetHp);
	void pouchAddHp(s32 hpToAdd);
	
	extern "C" {
		extern MarioPouchWork marioPouchWork;

		extern s32 pouchGetHp();
		
		extern s32 pouchGetXp();
		extern void pouchAddXp(s32 increase);

		extern void pouchRemoveItem(s32 itemId);
		extern void pouchRemoveShopItem(s32 itemId);

		extern s32 pouchGetCurPixl();

		extern s32 pouchCountUseItems();
		extern s32 pouchCountKeyItems();
		extern s32 pouchCountShopItems();
		extern s32 pouchCountChars();
		extern s32 pouchCountPixls();
		
		extern MarioPouchWork * pouchGetPtr_o();
		extern void pouchGetTotalCoinsCollected_o();
		extern void pouchSetCoin_o(s32 targetCoins);
		extern void pouchAddCoin_o(s32 coinsToAdd);
		extern void pouchSetAttack_o(s32 targetAttack);
		extern void pouchAddAttack_o(s32 attackToAdd);
		extern void pouchSetHp_o(s32 targetHp);
		extern void pouchAddHp_o(s32 hpToAdd);
	}
}

