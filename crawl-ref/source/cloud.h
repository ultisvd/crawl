/**
 * @file
 * @brief Functions related to clouds.
**/

#pragma once

#include <beam-type.h>

enum cloud_tile_variation
{
    CTVARY_NONE,     ///< fixed tile (or special case)
    CTVARY_DUR,      ///< tile based on remaining cloud duration
    CTVARY_RANDOM,   ///< choose a random tile in set with every redraw
};

struct cloud_tile_info
{
    tileidx_t base;                  ///< The base tile for the cloud type.
    cloud_tile_variation variation;  ///< How (and if) the tile should vary.
};

cloud_struct* cloud_at(coord_def pos);

cloud_type cloud_type_at(const coord_def &pos);
bool cloud_is_yours_at(const coord_def &pos);

void delete_all_clouds();
void delete_cloud(coord_def p);
void remove_tornado_clouds(mid_t whose);
void move_cloud(coord_def src, coord_def newpos);
void swap_clouds(coord_def p1, coord_def p2);

coord_def random_walk(coord_def start, int dist);

void check_place_cloud(cloud_type cl_type, const coord_def& p, int lifetime,
                       const actor *agent, int spread_rate = -1,
                       int excl_rad = -1);
void place_cloud(cloud_type cl_type, const coord_def& ctarget,
                 int cl_range, const actor *agent,
                 int spread_rate = -1, int excl_rad = -1,
                 bool do_conducts = true);

void manage_clouds();
void run_cloud_spreaders(int dur);
int max_cloud_damage(cloud_type cl_type, int power = -1);
string desc_cloud_damage(cloud_type cl_type, bool vs_player);
int actor_apply_cloud(actor *act);
bool actor_cloud_immune(const actor &act, const cloud_struct &cloud);
bool actor_cloud_immune(const actor &act, cloud_type type);
bool mons_avoids_cloud(const monster* mons, coord_def pos,
                       bool placement = false);

colour_t get_cloud_colour(const cloud_struct &cloud);
coord_def get_cloud_originator(const coord_def& pos);

bool is_damaging_cloud(cloud_type type, bool temp = false, bool yours = false);
bool is_harmless_cloud(cloud_type type);
bool is_opaque_cloud(cloud_type ctype);
cloud_type beam2cloud(beam_type flavour);
string cloud_type_name(cloud_type type, bool terse = true);
cloud_type random_smoke_type();
cloud_type cloud_name_to_type(const string &name);
const cloud_tile_info& cloud_type_tile_info(cloud_type type);

void start_still_winds();
void end_still_winds();

 void surround_actor_with_cloud(const actor* a, cloud_type cloud);