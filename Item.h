#pragma once

#define Property_Zero 0
#define Property_NoSeed 1
#define Property_Dropless 2
#define Property_Beta 4
#define Property_Mod 8
#define Property_Chemical 12
#define Property_Untradable 16
#define Property_Wrenchable 32
#define Property_MultiFacing 64
#define Property_Permanent 128
#define Property_AutoPickup 256
#define Property_WorldLock 512
#define Property_NoSelf 1024
#define Property_RandomGrow 2048
#define Property_Public 4096
#define Property_Foreground 8192

enum ClothTypes {
	HAIR,
	SHIRT,
	PANTS,
	FEET,
	FACE,
	HAND,
	BACK,
	MASK,
	NECKLACE,
	ANCES,
	NONE
};
enum BlockTypes
{
	FOREGROUND,
	BACKGROUND,
	CONSUMABLE,
	SEED,
	Display_Shelf,
	PAIN_BLOCK,
	BEDROCK,
	VIP_ENTRANCE,
	Heart_Monitor,
	Painting_Easel,
	MAIN_DOOR,
	SIGN,
	DOOR,
	CLOTHING,
	FIST,
	WRENCH,
	CHECKPOINT,
	LOCK,
	GATEWAY,
	TREASURE,
	WEATHER,
	TRAMPOLINE,
	MANNEQUIN,
	TOGGLE_FOREGROUND,
	CHEMICAL_COMBINER,
	SWITCH_BLOCK,
	SFX_FOREGROUND,
	RANDOM_BLOCK,
	Spirit_Storage,
	PORTAL,
	PLATFORM,
	Fish_Mount,
	MAILBOX,
	GIVING_TREE,
	MAGIC_EGG,
	CRYSTAL,
	GEMS,
	DEADLY,
	CHEST,
	FACTION,
	BULLETIN_BOARD,
	BOUNCY,
	ANIM_FOREGROUND,
	COMPONENT,
	SUCKER,
	FISH,
	STEAM,
	GROUND_BLOCK,
	PORTRAIT,
	DISPLAY,
	STORAGE,
	VENDING,
	DONATION,
	PHONE,
	SEWINGMACHINE,
	CRIME_VILLAIN,
	PROVIDER,
	ADVENTURE,
	CCTV,
	STORAGE_BOX,
	TIMER,
	ITEM_SUCKER,
	TRICKSTER,
	KRANKEN,
	FOSSIL,
	GEIGER_CHARGER,
	COUNTRY_FLAG,
	AUTO_BLOCK,
	GAME_BLOCK,
	GAME_GENERATOR,
	UNKNOWN
};

struct ItemDB
{
	
};
vector<ItemDB> items;