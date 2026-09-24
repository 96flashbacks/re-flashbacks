#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common1.h"
#include "make_const_nonconst.h"
#include "levels/rr/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_rr_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _rr_segment_7SegmentRomStart, _rr_segment_7SegmentRomEnd), 
	LOAD_MIO0(0x0A, _cloud_floor_skybox_mio0SegmentRomStart, _cloud_floor_skybox_mio0SegmentRomEnd), 
	LOAD_MIO0_TEXTURE(0x09, _sky_mio0SegmentRomStart, _sky_mio0SegmentRomEnd), 
	LOAD_MIO0(0x05, _group11_mio0SegmentRomStart, _group11_mio0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group11_geoSegmentRomStart, _group11_geoSegmentRomEnd), 
	LOAD_MIO0(0x08, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, BPARAM4(0x01), bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_12), 
	LOAD_MODEL_FROM_GEO(MODEL_RR_FLYING_CARPET, rr_geo_000848), 
	LOAD_MODEL_FROM_GEO(MODEL_RR_ROTATING_BRIDGE_PLATFORM, rr_geo_000878),
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, rr_area_1),
		WARP_NODE(0x0A, LEVEL_RR, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x02, 0x3A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE, 0x02, 0x6C, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_CANNON_BASE, -1574, 2919, 5239, 0, -90, 0, (64 << 16), bhvCannon),
		OBJECT(MODEL_RR_FLYING_CARPET, 2661, -1036, 291, 0, 0, 0, (0x00 << 16), bhvPlatformOnTrack),
		OBJECT(MODEL_RR_FLYING_CARPET, 4923, 664, 628, 0, 90, 0, (0x01 << 16), bhvPlatformOnTrack),
		OBJECT(MODEL_RR_FLYING_CARPET, 2937, 2409, 365, 0, -90, 0, (0x07 << 16), bhvPlatformOnTrack),
		OBJECT(MODEL_RED_FLAME, 9, 3711, -4646, 0, 180, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_NONE, 9, 3749, -4646, 0, 0, 0, (2 << 16), bhvFlamethrower),
		OBJECT(MODEL_NONE, 827, -343, -1540, 0, -10, 0, (2 << 16), bhvFlamethrower),
		OBJECT(MODEL_NONE, 5581, 1448, 1425, 0, -90, 0, (2 << 16), bhvFlamethrower),
		OBJECT(MODEL_NONE, 2171, 2689, -253, 0, -180, 0, 0x00000000, bhvFlamethrower),
		OBJECT(MODEL_NONE, 729, 2818, -22, 0, 0, 0, 0x00000000, bhvFlamethrower),
		MARIO_POS(0x01, -90, 3626, -996, 316),
		OBJECT(MODEL_NONE, 3949, 164, 547, 0, 90, 0, (64 << 16), bhvPoleGrabbing),
		OBJECT(MODEL_NONE, 2939, 1453, 1942, 0, 90, 0, (98 << 16), bhvPoleGrabbing),
		OBJECT(MODEL_NONE, -1574, 2628, 3661, 0, 90, 0, (152 << 16), bhvPoleGrabbing),
		OBJECT(MODEL_RR_ROTATING_BRIDGE_PLATFORM, 637, 1150, 3516, 0, 180, 0, 0x00000000, bhvRRRotatingBridgePlatform),
		OBJECT(MODEL_STAR, -1574, 3151, 858, 0, 180, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 612, 3943, -3658, 0, 180, 0, (1 << 24), bhvStar),
		OBJECT(MODEL_NONE, 3626, -712, 316, 0, -90, 0, (0x0A << 16), bhvSpinAirborneWarp),
		TERRAIN(rr_area_1_collision),
		MACRO_OBJECTS(rr_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_SLIDE),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, -90, 3626, -996, 316),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};