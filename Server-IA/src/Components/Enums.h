#ifndef ENUMS_H__
#define ENUMS_H__

enum Directions
{
	INVALID = -1,
	North = 0,
	East,
	South,
	West,
};

enum Genres
{
	Male = 1,
	Female
};

enum Races
{
	Human = 1,
	Dwarf,
	Gnome,
	Elf,
	DarkElf
};

enum Bodies
{
	Body_Human_Male = 1,
	Body_Human_Female = 2,
	Body_Elf_Dark_Male,
	Body_Elf_Dark_Female,
	Body_Elf_Male,
	Body_Elf_Female = 6,
	Body_Casper_White = 9
};

enum Heads
{
	No_Head = 0,
	Head_Pirate_Male,
	Head_Human_Male_Brown,
	Head_Human_Male_Blonde,
	Head_Casper_White,
	Head_Human_Female_Red = 9

};

enum Shields
{
	NoShield = 0
};

enum Helmets
{
	NoHelmet = 0
};

enum Weapons
{
	NoWeapon = 0
};

enum Items
{
	NoItem = 0,
	Potion_Red,
	Potion_Blue
};

enum Animations
{
	Anim_Spawn = 10,
	Anim_Electrical_Charge = 20,
	Anim_Apocalipsis = 22,
	Anim_Blood = 23
};

enum FXS
{
	MeleeAttackFail = 2,
	Spawn = 3,
	MeleeAttack = 10,
	Heal = 18,
	Resurrect = 20,
	WalkStep1 = 23,
	ApocalipsisExplotion = 27,
	Click_01 = 189
};

enum TRACKS
{

};

enum AxnTags
{
	StopMovingSeq = 0,
	AnimateSeqBody = 1,

};

enum ParticleAnims
{
	NoParticleAnim = 0,
	ExplodingRing = 1,
	MeditationFlowers = 2
};

#endif // !ENUMS_H__
