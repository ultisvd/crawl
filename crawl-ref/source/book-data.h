using std::vector;

/*
 * These books have a few goals:
 * 1. Have a variety of spell levels and types, so they're useful to
 *    players who pick them up in different contexts. For example, a book
 *    with a level 5, level 6 and level 9 spell might be helpful to an
 *    mid-game character or a late-game one, or even just provide goals
 *    for an early character.
 * 2. Group spells in a thematic or meaningful fashion. The Book of Pain,
 *    Book of Storms, Wizard Biographies... these tell stories, and players
 *    love stories.
 *
 * Randbooks can play a role in increasing variety, but I do think that
 * fixed books provide an overall better player experience in general.
 *
 * These on average have 3 spells each, so that we can hand them out fairly
 * frequently without giving the player every spell too quickly. Occasionally
 * they can have 2 or 4 spells, and that's fine too. It'd also be fine to have
 * 5 spells for a really special book.
 *
 * They're designed so that almost every spell shows up in 2 books. A few show
 * up in three books, a few in just one (especially lower-level spells that
 * will rarely be useful to players, level 9 spells, and some level 8 spells
 * which are intentionally rarer).
 * A spreadsheet accurate as of June 2021 can be found here:
 * https://docs.google.com/spreadsheets/d/1RCWRO_fltNQDAlbF2h1wx8ZZyulUsyGmNNvkkogxRoo/edit#gid=0
 */

// This needs to be re-ordered when TAG_MAJOR_VERSION changes!
static const vector<spell_type> spellbook_templates[] =
{

{   // Book of Minor Magic
    SPELL_MAGIC_DART,
    SPELL_CALL_IMP,
    SPELL_MEPHITIC_CLOUD,
},

{   // Book of Conjurations
    SPELL_MAGIC_DART,
    SPELL_SEARING_RAY,
    SPELL_FULMINANT_PRISM,
},

{   // Book of Flames
    SPELL_FLAME_TONGUE,
    SPELL_CONJURE_FLAME,
    SPELL_INNER_FLAME,
},

{   // Book of Frost
    SPELL_FREEZE,
    SPELL_THROW_FROST,
    SPELL_THROW_ICICLE,
},

{   // Book of Dryads
    SPELL_SUMMON_FOREST,
    SPELL_SUMMON_MANA_VIPER,
    SPELL_SHADOW_CREATURES,
},

{   // Book of Fire
    SPELL_FIREBALL,
    SPELL_STARBURST,
    SPELL_IGNITION,
},

{   // Book of Ice
    SPELL_BOLT_OF_COLD,
    SPELL_FREEZING_CLOUD,
    SPELL_SIMULACRUM,
},

{   // Book of Spatial Translocations
    SPELL_BLINK,
    SPELL_BECKONING,
    SPELL_MANIFOLD_ASSAULT
},

{   // Book of Hexes  
    SPELL_INNER_FLAME,
    SPELL_CAUSE_FEAR,
    SPELL_DISCORD,
},

{   // Young Poisoner's Handbook
    SPELL_STING,
    SPELL_POISONOUS_VAPOURS,
    SPELL_OLGREBS_TOXIC_RADIANCE,
},

{   // Book of Lightning
    SPELL_DISCHARGE,
    SPELL_LIGHTNING_BOLT,
    //SPELL_MAXWELLS_COUPLING
},

{   // Book of Death
    SPELL_ANIMATE_DEAD,
    SPELL_DEATH_CHANNEL,
    SPELL_HAUNT,
},

{   // Book of Misfortune
    SPELL_SLOW,
    SPELL_CONFUSING_TOUCH,
    SPELL_VIOLENT_UNRAVELLING,
},

{   // Book of Changes
    SPELL_BEASTLY_APPENDAGE,
    SPELL_STICKS_TO_SNAKES, 
    SPELL_SPIDER_FORM,
},

{   // Book of Transfigurations
    SPELL_STONESKIN,
    SPELL_IRRADIATE,
    SPELL_DRAGON_FORM,
},

{   // Fen Folio
    SPELL_SUMMON_FOREST,
    SPELL_HYDRA_FORM,
    SPELL_SUMMON_HYDRA,
},

{   // Book of Vapours
    SPELL_POISONOUS_VAPOURS,
    SPELL_MEPHITIC_CLOUD,
    SPELL_FREEZING_CLOUD,
},

{   // Book of Necromancy
    SPELL_PAIN,
    SPELL_ANIMATE_SKELETON,
    SPELL_ANIMATE_DEAD,
},

{   // Book of Callings
    SPELL_SUMMON_SMALL_MAMMAL,
    SPELL_CALL_CANINE_FAMILIAR,
    SPELL_SUMMON_GUARDIAN_GOLEM,
},

{   // Book of Maledictions
    SPELL_CORONA,
    SPELL_HIBERNATION,
    SPELL_TUKIMAS_DANCE,
},

{   // Book of Air
    SPELL_SHOCK,
    SPELL_SWIFTNESS,
    SPELL_AIRSTRIKE,
},

{   // Book of the Sky
    SPELL_SUMMON_LIGHTNING_SPIRE,
    SPELL_STORM_FORM,
    //SPELL_MAXWELLS_COUPLING
},

{   // Book of the Warp
    SPELL_PORTAL_PROJECTILE,
    SPELL_FORCE_LANCE,
    SPELL_DISJUNCTION,
},

{   // Book of Envenomations
    SPELL_SPIDER_FORM,
    SPELL_OLGREBS_TOXIC_RADIANCE,
    SPELL_INTOXICATE,
},

{   // Book of Unlife
    SPELL_BORGNJORS_VILE_CLUTCH,
    SPELL_CIGOTUVIS_PLAGUE,
    SPELL_INFESTATION,
},

{   // Book of Control
    SPELL_CONFUSE,
    SPELL_CONTROL_UNDEAD,
    SPELL_ENGLACIATION,
},

{   // Book of Battle
    SPELL_INFUSION,
    SPELL_SONG_OF_SLAYING,
    SPELL_SPECTRAL_WEAPON,
},

{   // Book of Geomancy
    SPELL_SANDBLAST,
    SPELL_PASSWALL,
    SPELL_LRD,
},

{   // Book of Stone
    SPELL_STONESKIN,
    SPELL_BOLT_OF_MAGMA,
    SPELL_STATUE_FORM,
},

{   // Book of Wizardry
    SPELL_AGONY,
    SPELL_INVISIBILITY,
    SPELL_SPELLFORGED_SERVITOR,
},

{   // Book of Power
    SPELL_BATTLESPHERE,
    SPELL_IRON_SHOT,
    SPELL_SPELLFORGED_SERVITOR,
},

{   // Book of Cantrips
    SPELL_CORONA,
    SPELL_ANIMATE_SKELETON,
    SPELL_SUMMON_SMALL_MAMMAL,
    SPELL_APPORTATION,
},

{   // Book of Party Tricks
    SPELL_SUMMON_BUTTERFLIES,
    SPELL_APPORTATION,
    SPELL_INTOXICATE,
},

{   // Akashic Record
    SPELL_DISPERSAL,
    SPELL_CONTROLLED_BLINK,
    SPELL_SINGULARITY,
},

{   // Book of Debilitation
    SPELL_SLOW,
    SPELL_VAMPIRIC_DRAINING,
    SPELL_CONFUSING_TOUCH,
},

{   // Book of the Dragon
    SPELL_CAUSE_FEAR,
    SPELL_BOLT_OF_FIRE,
    SPELL_DRAGON_FORM,
    SPELL_DRAGON_CALL,
},

{   // Book of Burglary
    SPELL_SWIFTNESS,
    SPELL_PASSWALL,
    SPELL_INVISIBILITY,
},

{   // Book of Dreams
    SPELL_HIBERNATION,
    SPELL_SPIDER_FORM,
    SPELL_SHADOW_CREATURES,
},

{   // Book of Alchemy
    SPELL_SUBLIMATION_OF_BLOOD,
    SPELL_PETRIFY,
    SPELL_IRRADIATE,
},

{   // Book of Beasts
    SPELL_SUMMON_ICE_BEAST,
    SPELL_SUMMON_MANA_VIPER,
    SPELL_MONSTROUS_MENAGERIE,
},

{   // Book of Annihilations
    SPELL_CHAIN_LIGHTNING,
    SPELL_GLACIATE,
    SPELL_FIRE_STORM,
},

{   // Grand Grimoire
    SPELL_MALIGN_GATEWAY,
    SPELL_SUMMON_HORRIBLE_THINGS,
    SPELL_ELDRITCH_FORM,
},

{   // Necronomicon
    SPELL_BORGNJORS_REVIVIFICATION,
    SPELL_DEATHS_DOOR,
    SPELL_NECROMUTATION,
},

{   // The Memoirs of the virtuoso
    SPELL_ERINGYAS_ROOTSPIKE,
    SPELL_POISON_ARROW,
    SPELL_OLGREBS_LAST_MERCY,
},
    
{   // Book of Stalking
    SPELL_FULSOME_DISTILLATION,
    SPELL_EVAPORATE,
    SPELL_PETRIFY,
},

{   // Book of Frost2
    SPELL_FREEZE,
    SPELL_FROZEN_RAMPARTS,
    SPELL_HAILSTORM,
},

{   // Book of the War Chants
    SPELL_SHRAPNEL_CURTAIN,
    SPELL_ELENENTAL_WEAPON,
    SPELL_FLAME_STRIKE,
},

{   // Tome of Valor
    SPELL_SONG_OF_SLAYING,
    SPELL_FLAME_STRIKE,
    SPELL_RING_OF_FLAMES,
},

{   // Book of Aid
    SPELL_SUMMON_HOODED_MALICE,
    SPELL_SUMMON_LIVELY_MASS,
    SPELL_HASTE,
},
    
{ }, // BOOK_RANDART_LEVEL
{ }, // BOOK_RANDART_THEME
{ }, // BOOK_MANUAL
{ }, // BOOK_BUGGY_DESTRUCTION


{ // Book of Spectacle
    SPELL_DAZZLING_SPRAY,
    SPELL_ISKENDERUNS_MYSTIC_BLAST,
    SPELL_STARBURST,
},

{ // Book of Winter
    SPELL_OZOCUBUS_ARMOUR,
    SPELL_ENGLACIATION,
    SPELL_SIMULACRUM,
},

{ // Book of Spheres
    SPELL_BATTLESPHERE,
    SPELL_FIREBALL,
    SPELL_CONJURE_BALL_LIGHTNING,
    SPELL_IOOD,
},

{ // Book of Armaments
    SPELL_STONE_ARROW,
    SPELL_ANIMATE_ARMOUR,
    SPELL_LEHUDIBS_CRYSTAL_SPEAR,
},

{ // Book of Pain
    SPELL_PAIN,
    SPELL_AGONY,
    SPELL_EXCRUCIATING_WOUNDS,
},

{ // Book of Decay
    SPELL_CORPSE_ROT,
    SPELL_DISPEL_UNDEAD,
    SPELL_DEATH_CHANNEL,
},

{ // Book of Displacement
    SPELL_BECKONING,
    SPELL_GRAVITAS,
    SPELL_TELEPORT_OTHER,
},

{ // Book of Rime
    SPELL_FROZEN_RAMPARTS,
    SPELL_ICE_FORM,
    SPELL_SUMMON_ICE_BEAST,
},

{ // Everburning Encyclopedia
    SPELL_CONJURE_FLAME,
    SPELL_IGNITE_POISON,
    SPELL_STICKY_FLAME,
},

{ // Book of Earth
    SPELL_STONE_ARROW,
    SPELL_BOLT_OF_MAGMA,
    SPELL_SHATTER,
},

{ // Ozocubu's Autobio
    SPELL_OZOCUBUS_ARMOUR,
    SPELL_OZOCUBUS_REFRIGERATION,
},

{ // Book of the Senses
    SPELL_DAZZLING_SPRAY,
    SPELL_AGONY,
    SPELL_SILENCE,
},

{ // Book of the Moon
    SPELL_GOLUBRIAS_PASSAGE,
    SPELL_SILENCE,
    SPELL_LEHUDIBS_CRYSTAL_SPEAR,
},

{ // Book of Blasting
    SPELL_FULMINANT_PRISM,
    SPELL_ISKENDERUNS_MYSTIC_BLAST,
    SPELL_LRD,
},

{ // Book of Iron
    SPELL_ANIMATE_ARMOUR,
    SPELL_BLADE_HANDS,
    SPELL_IRON_SHOT,
},

{ // Inescapable Atlas
    SPELL_BLINK,
    SPELL_MANIFOLD_ASSAULT,
    SPELL_STORM_FORM,
},

{ // Book of the Tundra
    SPELL_HAILSTORM,
    SPELL_ICE_FORM,
    SPELL_SIMULACRUM,
},

{ // Book of Storms
    SPELL_AIRSTRIKE,
    SPELL_SUMMON_LIGHTNING_SPIRE,
    SPELL_LIGHTNING_BOLT,
},

{ // Book of Weapons
    SPELL_ELENENTAL_WEAPON,
    SPELL_EXCRUCIATING_WOUNDS,
    SPELL_BLADE_HANDS,
},

{ // Book of Sloth
    SPELL_PETRIFY,
    SPELL_ENGLACIATION,
    SPELL_STATUE_FORM,
},

{ // Book of Blood
    SPELL_SUBLIMATION_OF_BLOOD,
    SPELL_VAMPIRIC_DRAINING,
    SPELL_SUMMON_HYDRA,
},

{ // There-And-Back Book
    SPELL_GRAVITAS,
    SPELL_TELEPORT_OTHER,
    SPELL_DISPERSAL,
},

{ // Book of Dangerous Friends
    SPELL_SUMMON_GUARDIAN_GOLEM,
    SPELL_IOOD,
    SPELL_SPELLFORGED_SERVITOR,
},

{ // Book of Touch
    SPELL_DISCHARGE,
    SPELL_STICKY_FLAME,
    SPELL_DISPEL_UNDEAD,
},

{ // Book of Chaos
    SPELL_CONJURE_BALL_LIGHTNING,
    SPELL_DISJUNCTION,
    SPELL_DISCORD,
},

{ // Unrestrained Analects
    SPELL_OLGREBS_TOXIC_RADIANCE,
    SPELL_OZOCUBUS_REFRIGERATION,
    SPELL_IGNITION,
},

{ // Great Wizards, Vol. II
    SPELL_INTOXICATE,
    SPELL_BORGNJORS_VILE_CLUTCH,
    SPELL_NOXIOUS_BOG,
},

{ // Great Wizards, Vol. VII
    SPELL_TUKIMAS_DANCE,
    SPELL_GOLUBRIAS_PASSAGE,
    SPELL_VIOLENT_UNRAVELLING,
},

{ // Trismegistus Codex
    SPELL_IGNITE_POISON,
    SPELL_MEPHITIC_CLOUD,
    SPELL_BOLT_OF_MAGMA,
},

{ // Book of the Hunter
    SPELL_CALL_CANINE_FAMILIAR,
    SPELL_PORTAL_PROJECTILE,
    SPELL_LEDAS_LIQUEFACTION,
},

{
  // Book of Enchantments
    SPELL_CONDENSATION_SHIELD,
    SPELL_DEFLECT_MISSILES,
    SPELL_HASTE,
},

{
    // Book of Toxic
    SPELL_NOXIOUS_BOG,
    SPELL_ERINGYAS_ROOTSPIKE,
    SPELL_VENOM_BOLT,
},

{
    // Book of the Tempests
    SPELL_IGNITION,
    SPELL_TORNADO,
    SPELL_SHATTER,
},

{
    // Book of Summonings
    SPELL_RECALL,
    SPELL_AURA_OF_ABJURATION,
    SPELL_SUMMON_LIVELY_MASS,
},

{
    // Book of Pandemonium
    SPELL_CALL_IMP,
    SPELL_SUMMON_DEMON,
    SPELL_SUMMON_GREATER_DEMON,
},

{
    // Book of Liquefaction
    SPELL_LEDAS_LIQUEFACTION,
    SPELL_WILL_OF_EARTH,
    SPELL_WALL_MELTING,
},

{
    // Book of Minor Buff
    SPELL_REPEL_MISSILES,
    SPELL_SHROUD_OF_GOLUBRIA,
    SPELL_REGENERATION,
},

{
    // Book of Shields
    SPELL_INSULATION,
    SPELL_CONDENSATION_SHIELD,
    SPELL_BARRIER,
},

{
    // Book of Darts
    SPELL_MAGIC_DART,
    SPELL_THROW_FROST,
    SPELL_THROW_FLAME,
},

{
    // Book of Mesmerise
    SPELL_SLOW,
    SPELL_CONFUSE,
    SPELL_FORCE_LANCE,
},

{
    // Book of Spy
    SPELL_WALL_MELTING,
    SPELL_INVISIBILITY,
    SPELL_DARKNESS,
},

{
    // Book of Battlemage
    SPELL_REGENERATION,
    SPELL_DEFLECT_MISSILES,
    SPELL_TORNADO,
},

{
    // Book of Plagues
    SPELL_CIGOTUVIS_PLAGUE,
    SPELL_BOLT_OF_DRAINING,
    SPELL_SUMMON_HOODED_MALICE,
},

{
    // Book of Betrayal
    SPELL_AURA_OF_ABJURATION,
    SPELL_SUMMON_GREATER_DEMON,
    SPELL_MALIGN_GATEWAY,
},

};

COMPILE_CHECK(ARRAYSZ(spellbook_templates) == NUM_BOOKS);
