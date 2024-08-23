enum weapon_choice
{
    WCHOICE_NONE,   ///< No weapon choice
    WCHOICE_PLAIN,  ///< Normal weapon choice
    WCHOICE_GOOD,   ///< Chooses from "good" weapons
    WCHOICE_RANGED, ///< Choice of ranged weapon
    WCHOICE_TWOHANDED, ///< Choice of two-handed melee weapon
};

struct job_def
{
    const char* abbrev; ///< Two-letter abbreviation
    const char* name; ///< Long name
    int s, i, d; ///< Starting Str, Dex, and Int
    /// Which species are good at it
    /// No recommended species = job is disabled
    vector<species_type> recommended_species;
    /// What spells start out in their library?
    /// The first spell in the list will be memorised at the start of the game,
    /// if it's level 1 and not useless.
    vector<spell_type> library;
    /// Guaranteed starting equipment. Uses vault spec syntax, with the plus:,
    /// charges:, q:, and ego: tags supported.
    vector<string> equipment;
    weapon_choice wchoice; ///< how the weapon is chosen, if any
    vector<pair<skill_type, int>> skills; ///< starting skills
};

static const map<job_type, job_def> job_data =
{

{ JOB_ABYSSAL_KNIGHT, {
    "AK", "Abyssal Knight",
    4, 4, 4,
    { SP_HILL_ORC, SP_PALENTONGA, SP_SPRIGGAN, SP_TROLL, SP_MERFOLK, SP_BASE_DRACONIAN,
      SP_DEMONSPAWN, },
    { },
    { "leather armour" },
    WCHOICE_PLAIN,
    { { SK_FIGHTING, 3 }, { SK_ARMOUR, 1 }, { SK_DODGING, 1 },
      { SK_INVOCATIONS, 2 }, { SK_WEAPON, 2 }, },
} },

{ JOB_AIR_ELEMENTALIST, {
    "AE", "Air Elementalist",
    0, 7, 5,
    { SP_DEEP_ELF, SP_TENGU, SP_BASE_DRACONIAN, SP_NAGA, SP_VINE_STALKER, },
    {
        SPELL_SHOCK,
        SPELL_SWIFTNESS,
        SPELL_REPEL_MISSILES,
        SPELL_DISCHARGE,
        SPELL_AIRSTRIKE,
        SPELL_LIGHTNING_BOLT
    },
    { "robe" },
    WCHOICE_NONE,
    { { SK_CONJURATIONS, 1 }, { SK_AIR_MAGIC, 3 }, { SK_SPELLCASTING, 2 },
      { SK_DODGING, 2 }, { SK_STEALTH, 2 }, },
} },

{ JOB_ARCANE_MARKSMAN, {
    "AM", "Arcane Marksman",
    2, 5, 5,
    { SP_FORMICID, SP_DEEP_ELF, SP_KOBOLD, SP_SPRIGGAN, SP_TROLL, SP_CENTAUR, },
    {
        SPELL_CORONA,
        SPELL_SLOW,
        SPELL_INNER_FLAME,
        SPELL_PORTAL_PROJECTILE,
        SPELL_CAUSE_FEAR,
        SPELL_LEDAS_LIQUEFACTION
    },
    { "robe" },
    WCHOICE_RANGED,
    { { SK_FIGHTING, 1 }, { SK_DODGING, 2 }, { SK_SPELLCASTING, 1 },
      { SK_HEXES, 3 }, { SK_WEAPON, 2 }, },
} },

{ JOB_ARTIFICER, {
    "Ar", "Artificer",
    4, 3, 5,
    { SP_DEEP_DWARF, SP_HALFLING, SP_KOBOLD, SP_SPRIGGAN, SP_BASE_DRACONIAN,
      SP_DEMONSPAWN, SP_HOMUNCULUS, SP_SPARKBORN },
    { },
    { "leather armour" },
    WCHOICE_NONE,
    { { SK_EVOCATIONS, 3 }, { SK_DODGING, 2 }, { SK_FIGHTING, 1 },
      { SK_STEALTH, 1 }, },
} },

{ JOB_ASSASSIN, {
    "As", "Assassin",
    3, 3, 6,
    { SP_TROLL, SP_HALFLING, SP_SPRIGGAN, SP_DEMONSPAWN, SP_VAMPIRE,
      SP_VINE_STALKER, },
    { },
    { "dagger plus:2", "robe", "cloak", "dart ego:poisoned q:8",
      "dart ego:curare q:2" },
    WCHOICE_NONE,
    { { SK_FIGHTING, 2 }, { SK_DODGING, 1 }, { SK_STEALTH, 4 },
      { SK_THROWING, 2 }, { SK_WEAPON, 2 }, },
} },

{ JOB_BERSERKER, {
    "Be", "Berserker",
    9, -1, 4,
    { SP_HILL_ORC, SP_HALFLING, SP_OGRE, SP_MERFOLK, SP_MINOTAUR, SP_GARGOYLE,
      SP_PALENTONGA, SP_DEMONSPAWN, },
    { },
    { "animal skin" },
    WCHOICE_PLAIN,
    { { SK_FIGHTING, 3 }, { SK_DODGING, 2 }, { SK_WEAPON, 3 }, },
} },

{ JOB_CHAOS_KNIGHT, {
    "CK", "Chaos Knight",
    4, 4, 4,
    { SP_HILL_ORC, SP_TROLL, SP_CENTAUR, SP_MERFOLK, SP_MINOTAUR,
      SP_BASE_DRACONIAN, SP_DEMONSPAWN, },
    { },
    { "leather armour plus:2" },
    WCHOICE_PLAIN,
    { { SK_FIGHTING, 3 }, { SK_ARMOUR, 1 }, { SK_DODGING, 1 },
      { SK_WEAPON, 3 } },
} },

{ JOB_CONJURER, {
    "Cj", "Conjurer",
    0, 7, 5,
    { SP_DEEP_ELF, SP_NAGA, SP_TENGU, SP_BASE_DRACONIAN, SP_DEMIGOD, },
    {
        SPELL_MAGIC_DART,
        SPELL_SEARING_RAY,
        SPELL_DAZZLING_SPRAY,
        SPELL_BATTLESPHERE,
        SPELL_ISKENDERUNS_MYSTIC_BLAST,
        SPELL_FULMINANT_PRISM
    },
    { "robe" },
    WCHOICE_NONE,
    { { SK_CONJURATIONS, 4 }, { SK_SPELLCASTING, 2 }, { SK_DODGING, 2 },
      { SK_STEALTH, 2 }, },
} },

{ JOB_EARTH_ELEMENTALIST, {
    "EE", "Earth Elementalist",
    0, 7, 5,
    { SP_DEEP_ELF, SP_DEEP_DWARF, SP_SPRIGGAN, SP_GARGOYLE, SP_DEMIGOD,
      SP_GHOUL, SP_OCTOPODE, },
    {
        SPELL_SANDBLAST,
        SPELL_STONESKIN,
        SPELL_PASSWALL,
        SPELL_STONE_ARROW,
        SPELL_PETRIFY,
        SPELL_LRD
    },
    { "stone q:30", "robe", },
    WCHOICE_NONE,
    { { SK_TRANSMUTATIONS, 1 }, { SK_EARTH_MAGIC, 3 }, { SK_SPELLCASTING, 2 },
      { SK_DODGING, 2 }, { SK_STEALTH, 2 }, }
} },

{ JOB_ENCHANTER, {
    "En", "Enchanter",
    0, 7, 5,
    { SP_DEEP_ELF, SP_FELID, SP_KOBOLD, SP_SPRIGGAN, SP_NAGA, SP_VAMPIRE, },
    {
        SPELL_CORONA,
        SPELL_HIBERNATION,
        SPELL_CONFUSE,
        SPELL_TUKIMAS_DANCE,
        SPELL_DAZZLING_SPRAY,
    },
    { "dagger plus:1", "robe" },
    WCHOICE_NONE,
    { { SK_WEAPON, 1 }, { SK_HEXES, 3 }, { SK_SPELLCASTING, 2 },
      { SK_DODGING, 2 }, { SK_STEALTH, 3 }, },
} },

{ JOB_FIGHTER, {
    "Fi", "Fighter",
    8, 0, 4,
    { SP_DEEP_DWARF, SP_HILL_ORC, SP_TROLL, SP_MINOTAUR, SP_GARGOYLE,
     SP_PALENTONGA, SP_CENTAUR, },
    { },
    { "scale mail", "shield", "potion of might" },
    WCHOICE_GOOD,
    { { SK_FIGHTING, 3 }, { SK_SHIELDS, 3 }, { SK_ARMOUR, 3 },
      { SK_WEAPON, 2 } },
} },

{ JOB_FIRE_ELEMENTALIST, {
    "FE", "Fire Elementalist",
    0, 7, 5,
    { SP_DEEP_ELF, SP_HILL_ORC, SP_NAGA, SP_TENGU, SP_DEMIGOD, SP_GARGOYLE, },
    {
        SPELL_FLAME_TONGUE,
        SPELL_THROW_FLAME,
        SPELL_CONJURE_FLAME,
        SPELL_INNER_FLAME,
        SPELL_STICKY_FLAME,
        SPELL_FIREBALL,
    },
    { "robe" },
    WCHOICE_NONE,
    { { SK_CONJURATIONS, 1 }, { SK_FIRE_MAGIC, 3 }, { SK_SPELLCASTING, 2 },
      { SK_DODGING, 2 }, { SK_STEALTH, 2 }, },
} },

{ JOB_GLADIATOR, {
    "Gl", "Gladiator",
    6, 0, 6,
    { SP_DEEP_DWARF, SP_HILL_ORC, SP_MERFOLK, SP_MINOTAUR, SP_GARGOYLE,
      SP_CENTAUR, },
    { },
    { "leather armour", "helmet", "throwing net q:3" },
    WCHOICE_GOOD,
    { { SK_FIGHTING, 2 }, { SK_THROWING, 2 }, { SK_DODGING, 3 },
      { SK_WEAPON, 3}, },
} },

{ JOB_HUNTER, {
    "Hu", "Hunter",
    4, 3, 5,
    { SP_HILL_ORC, SP_HALFLING, SP_KOBOLD, SP_OGRE, SP_TROLL, SP_CENTAUR, },
    { },
    { "short sword", "leather armour" },
    WCHOICE_RANGED,
    { { SK_FIGHTING, 2 }, { SK_DODGING, 2 }, { SK_STEALTH, 1 },
      { SK_WEAPON, 4 }, },
} },

{ JOB_ICE_ELEMENTALIST, {
    "IE", "Ice Elementalist",
    0, 7, 5,
    { SP_DEEP_ELF, SP_MERFOLK, SP_NAGA, SP_BASE_DRACONIAN, SP_DEMIGOD,
      SP_GARGOYLE, },
    { SPELL_FREEZE, SPELL_OZOCUBUS_ARMOUR, SPELL_SUMMON_ICE_BEAST }, //select ice spell
    { "robe" },
    WCHOICE_NONE,
    { { SK_CONJURATIONS, 1 }, { SK_ICE_MAGIC, 3 }, { SK_SPELLCASTING, 2 },
      { SK_DODGING, 2 }, { SK_STEALTH, 2 }, },
} },

{ JOB_STALKER, {
    "St", "Stalker",
    2, 4, 6,
    { SP_SPRIGGAN, SP_VAMPIRE, SP_MERFOLK, SP_HUMAN, SP_SLUDGE_ELF },
    {
        SPELL_FULSOME_DISTILLATION,
        SPELL_EVAPORATE,
        SPELL_PASSWALL,
        SPELL_PETRIFY,
        SPELL_WILL_OF_EARTH,
        SPELL_WALL_MELTING
    },
    { "dagger plus:2", "robe", "cloak", "potion of degeneration q:2" },
    WCHOICE_NONE,
    {{ SK_FIGHTING, 1 }, { SK_DODGING, 2 }, { SK_SPELLCASTING, 2 },
     { SK_TRANSMUTATIONS, 3 }, { SK_STEALTH, 3 }, },
} },

 { JOB_DELVER, {
    "De", "Delver",
    4, 2, 6,
    { SP_FELID, SP_SPRIGGAN, SP_CENTAUR, SP_KOBOLD, SP_VAMPIRE, },
    { },
    { "leather armour", "scroll of fog", "scroll of magic mapping",
     "scroll of fear", "potion of haste", "wand of digging charges:3" },
    WCHOICE_PLAIN,
    { { SK_FIGHTING, 3 }, { SK_DODGING, 2 }, { SK_STEALTH, 5 }, { SK_WEAPON, 2 }, },
} },

{ JOB_MONK, {
    "Mo", "Monk",
    3, 2, 7,
    { SP_DEEP_DWARF, SP_HILL_ORC, SP_TROLL, SP_CENTAUR, SP_MERFOLK,
      SP_PALENTONGA, SP_GARGOYLE, SP_DEMONSPAWN, },
    { },
    { "robe" },
    WCHOICE_PLAIN,
    { { SK_FIGHTING, 3 }, { SK_WEAPON, 3 }, { SK_DODGING, 3 },
      { SK_STEALTH, 2 }, },
} },

{ JOB_NECROMANCER, {
    "Ne", "Necromancer",
    0, 7, 5,
    { SP_DEEP_ELF, SP_DEEP_DWARF, SP_HILL_ORC, SP_DEMONSPAWN, SP_MUMMY,
      SP_VAMPIRE, },
    {
        SPELL_PAIN,
        SPELL_ANIMATE_SKELETON,
        SPELL_VAMPIRIC_DRAINING,
        SPELL_REGENERATION,
        SPELL_ANIMATE_DEAD,
        SPELL_EXCRUCIATING_WOUNDS,
    },
    { "robe" },
    WCHOICE_NONE,
    { { SK_SPELLCASTING, 2 }, { SK_NECROMANCY, 4 }, { SK_DODGING, 2 },
      { SK_STEALTH, 2 }, },
} },

{ JOB_SKALD, {
    "Sk", "Skald",
    3, 5, 4,
    { SP_HALFLING, SP_CENTAUR, SP_MERFOLK, SP_BASE_DRACONIAN, SP_VAMPIRE, SP_HOMUNCULUS, },
    {
        SPELL_INFUSION,
        SPELL_SHROUD_OF_GOLUBRIA,
        SPELL_SONG_OF_SLAYING,
        SPELL_SPECTRAL_WEAPON,
        SPELL_REGENERATION,
        SPELL_BARRIER
    },
    { "leather armour" },
    WCHOICE_PLAIN,
    { { SK_FIGHTING, 2 }, { SK_ARMOUR, 1 }, { SK_DODGING, 2 },
      { SK_SPELLCASTING, 2 }, { SK_CHARMS, 3 }, { SK_WEAPON, 2 }, },
} },

{ JOB_SUMMONER, {
    "Su", "Summoner",
    0, 7, 5,
    { SP_DEEP_ELF, SP_HILL_ORC, SP_VINE_STALKER, SP_MERFOLK, SP_TENGU,
      SP_VAMPIRE, },
    {
        SPELL_SUMMON_SMALL_MAMMAL,
        SPELL_CALL_IMP,
        SPELL_CALL_CANINE_FAMILIAR,
        SPELL_SUMMON_GUARDIAN_GOLEM,
        SPELL_SUMMON_LIGHTNING_SPIRE,
    },
    { "robe" },
    WCHOICE_NONE,
    { { SK_SUMMONINGS, 4 }, { SK_SPELLCASTING, 2 }, { SK_DODGING, 2 },
      { SK_STEALTH, 2 }, },
} },

{ JOB_TRANSMUTER, {
    "Tm", "Transmuter",
    2, 5, 5,
    { SP_NAGA, SP_MERFOLK, SP_BASE_DRACONIAN, SP_DEMIGOD, SP_DEMONSPAWN,
      SP_TROLL, SP_SLUDGE_ELF },
    {
        SPELL_BEASTLY_APPENDAGE,
        SPELL_STICKS_TO_SNAKES,
        SPELL_SPIDER_FORM,
        SPELL_ICE_FORM,
        SPELL_BLADE_HANDS
    },
    { "arrow q:12", "robe" },
    WCHOICE_NONE,
    { { SK_FIGHTING, 1 }, { SK_UNARMED_COMBAT, 3 }, { SK_DODGING, 2 },
      { SK_SPELLCASTING, 2 }, { SK_TRANSMUTATIONS, 2 }, },
} },

{ JOB_VENOM_MAGE, {
    "VM", "Venom Mage",
    0, 7, 5,
    { SP_DEEP_ELF, SP_SPRIGGAN, SP_NAGA, SP_MERFOLK, SP_TENGU, SP_FELID,
      SP_DEMONSPAWN, },
    {
        SPELL_STING,
        SPELL_POISONOUS_VAPOURS,
        SPELL_MEPHITIC_CLOUD,
        SPELL_IGNITE_POISON,
        SPELL_OLGREBS_TOXIC_RADIANCE
    },
    { "robe" },
    WCHOICE_NONE,
    { { SK_TRANSMUTATIONS, 1 }, { SK_POISON_MAGIC, 3 }, { SK_SPELLCASTING, 2 },
      { SK_DODGING, 2 }, { SK_STEALTH, 2 }, },
} },

{ JOB_WANDERER, {
    "Wn", "Wanderer",
    0, 0, 0, // Randomised
    { SP_HILL_ORC, SP_SPRIGGAN, SP_CENTAUR, SP_MERFOLK, SP_BASE_DRACONIAN,
      SP_HUMAN, SP_DEMONSPAWN, },
    { }, // Randomised
    { }, // Randomised
    WCHOICE_NONE,
    { }, // Randomised
} },

{ JOB_WARPER, {
    "Wr", "Warper",
    3, 5, 4,
    { SP_FELID, SP_HALFLING, SP_DEEP_DWARF, SP_SPRIGGAN, SP_CENTAUR,
      SP_PALENTONGA, SP_BASE_DRACONIAN, },
    {
        SPELL_BLINK,
        SPELL_SHROUD_OF_GOLUBRIA,
        SPELL_BECKONING,
        SPELL_GRAVITAS,
        SPELL_TELEPORT_OTHER,
        SPELL_MANIFOLD_ASSAULT,
    },
    { "leather armour", "scroll of blinking",
      "boomerang ego:dispersal q:5" },
    WCHOICE_PLAIN,
    { { SK_FIGHTING, 2 }, { SK_ARMOUR, 1 }, { SK_DODGING, 2 },
      { SK_SPELLCASTING, 2 }, { SK_TRANSLOCATIONS, 3 }, { SK_THROWING, 1 },
      { SK_WEAPON, 2 }, },
} },

{ JOB_WIZARD, {
    "Wz", "Wizard",
    -1, 10, 3,
    { SP_DEEP_ELF, SP_NAGA, SP_BASE_DRACONIAN, SP_OCTOPODE, SP_HUMAN,
      SP_MUMMY, },
    {
        SPELL_MAGIC_DART,
        SPELL_BLINK,
        SPELL_CALL_IMP,
        SPELL_REPEL_MISSILES,
        SPELL_SLOW,
        SPELL_CONJURE_FLAME,
        SPELL_MEPHITIC_CLOUD,
    },
    { "robe", "hat" },
    WCHOICE_NONE,
    { { SK_DODGING, 2 }, { SK_STEALTH, 2 }, { SK_SPELLCASTING, 3 },
      { SK_TRANSLOCATIONS, 1 }, { SK_CONJURATIONS, 1 }, { SK_SUMMONINGS, 1 }, },
} },

{ JOB_MELTED_KNIGHT, {
    "MK", "Melted Knight",
    4, 4, 4,
    { SP_HILL_ORC, SP_TROLL, SP_CENTAUR, SP_MERFOLK, SP_MINOTAUR,
      SP_BASE_DRACONIAN, SP_DEMONSPAWN, },
    { },
    { "leather armour", "pair of gloves", "pair of boots"},
    WCHOICE_PLAIN,
    { { SK_FIGHTING, 3 }, { SK_ARMOUR, 1 }, { SK_DODGING, 1 },
      { SK_WEAPON, 3 } },
} },

{ JOB_CRUSADER, {
    "AW", "Arcane Warrior",
    3, 5, 4,
    { SP_HALFLING, SP_CENTAUR, SP_MERFOLK, SP_BASE_DRACONIAN, SP_VAMPIRE, SP_HOMUNCULUS },
    {
        SPELL_SHRAPNEL_CURTAIN,
        SPELL_STONESKIN,
        SPELL_ELENENTAL_WEAPON,
        SPELL_FLAME_STRIKE,
        SPELL_INSULATION,
        SPELL_CONDENSATION_SHIELD,
    },
    { "leather armour" },
    WCHOICE_PLAIN,
    { { SK_FIGHTING, 2 }, { SK_ARMOUR, 1 }, { SK_DODGING, 2 },
      { SK_SPELLCASTING, 2 }, { SK_CHARMS, 3 }, { SK_WEAPON, 2 }, },
} },

{ JOB_CARAVAN, {
    "Ca", "Caravan",
   4, 4, 4,
    { SP_SPRIGGAN, SP_CENTAUR, SP_OCTOPODE, SP_FELID, SP_DEMIGOD,
      SP_HUMAN, SP_DEMONSPAWN, },
    { },
    { "robe", "wand of heal wounds charges:3", "pipe charges:3", "flask of healing mist" },
    WCHOICE_NONE,
    { { SK_ARMOUR, 2 }, { SK_DODGING, 2 }, { SK_STEALTH, 2 }, },
} },

{ JOB_COLLECTOR, {
    "Cl", "Collector",
    5, 3, 4,
    { SP_HILL_ORC, SP_MINOTAUR, SP_DEMIGOD, SP_OCTOPODE, SP_TROLL, SP_FELID, SP_HUMAN },
    { },
    { "hat", "robe plus:1"},
    WCHOICE_PLAIN,
    {  { SK_WEAPON, 2 }, { SK_FIGHTING, 3 } },
} },

{ JOB_WEAPON_MASTER, {
    "WM", "Weapon Master",
    5, 0, 7,
    { SP_MINOTAUR, SP_MERFOLK, SP_TENGU, SP_HIGH_ELF, SP_FORMICID,
      SP_OGRE, SP_TWO_HEADED_OGRE, SP_TROLL, SP_WIGHT, SP_BARACHI, SP_MOUNTAIN_DWARF },
    { },
    { "robe" },
    WCHOICE_TWOHANDED,
    { { SK_FIGHTING, 2 }, { SK_WEAPON, 6 } },
} },
#if TAG_MAJOR_VERSION == 34
{ JOB_DEATH_KNIGHT, {
    "DK", "Death Knight",
    0, 0, 0,
    { },
    { },
    { },
    WCHOICE_NONE,
    { },
} },

{ JOB_HEALER, {
    "He", "Healer",
    0, 0, 0,
    { },
    { },
    { },
    WCHOICE_NONE,
    { },
} },

{ JOB_JESTER, {
    "Jr", "Jester",
    0, 0, 0,
    { },
    { },
    { },
    WCHOICE_NONE,
    { },
} },

{ JOB_PRIEST, {
    "Pr", "Priest",
    0, 0, 0,
    { },
    { },
    { },
    WCHOICE_NONE,
    { },
} },

#endif
};
