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
#include "levels/wdw/header.h"


const LevelScript level_wdw_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _wdw_segment_7SegmentRomStart, _wdw_segment_7SegmentRomEnd), 
	LOAD_MIO0_TEXTURE(0x09, _grass_mio0SegmentRomStart, _grass_mio0SegmentRomEnd), 
	LOAD_MIO0(0x0A, _wdw_skybox_mio0SegmentRomStart, _wdw_skybox_mio0SegmentRomEnd), 
	LOAD_MIO0(0x05, _group1_mio0SegmentRomStart, _group1_mio0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	LOAD_MIO0(0x06, _group13_mio0SegmentRomStart, _group13_mio0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd), 
	LOAD_MIO0(0x08, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, BPARAM4(0x01), bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_2), 
	JUMP_LINK(script_func_global_14), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_SQUARE_FLOATING_PLATFORM, wdw_geo_000580), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_ARROW_LIFT, wdw_geo_000598), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_WATER_LEVEL_DIAMOND, wdw_geo_0005C0), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_HIDDEN_PLATFORM, wdw_geo_0005E8), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_EXPRESS_ELEVATOR, wdw_geo_000610), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_RECTANGULAR_FLOATING_PLATFORM, wdw_geo_000628), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_ROTATING_PLATFORM, wdw_geo_000640), 

	AREA(1, wdw_area_1),
		WARP_NODE(0x0A, LEVEL_WDW, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_WDW, 0x01, 0x0C, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0C, LEVEL_WDW, 0x01, 0x0B, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x02, 0x32, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE, 0x02, 0x64, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_STAR, 1400, 1600, 5600, 0, 90, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 800, 4800, 700, 0, 0, 0, (1 << 24), bhvStar),
		OBJECT(MODEL_STAR, -800, 2300, -2000, 0, 0, 0, (2 << 24), bhvStar),
		OBJECT(MODEL_WDW_WATER_LEVEL_DIAMOND, -767, -2377, 768, 0, 0, 0, 0x00000000, bhvWaterLevelDiamond),
		OBJECT(MODEL_NONE, 435, 1457, 5735, 0, 90, 0, 0x000C0000, bhvFadingWarp),
		OBJECT(MODEL_NONE, -5434, 2304, -2189, 0, 45, 0, 0x000B0000, bhvFadingWarp),
		OBJECT(MODEL_NONE, -767, -2047, 3560, 0, 0, 0, 0x000C0000, bhvFadingWarp),
		OBJECT(MODEL_PURPLE_SWITCH, 3388, 1280, 3391, 0, 0, 0, 0x00000000, bhvFloorSwitchHiddenObjects),
		OBJECT(MODEL_WDW_HIDDEN_PLATFORM, 2239, 1126, 3391, 0, 0, 0, 0x00010000, bhvHiddenObject),
		OBJECT(MODEL_WDW_HIDDEN_PLATFORM, 1215, 1357, 2751, 0, 0, 0, 0x00010000, bhvHiddenObject),
		OBJECT(MODEL_WDW_HIDDEN_PLATFORM, 1215, 1229, 3391, 0, 0, 0, 0x00010000, bhvHiddenObject),
		OBJECT(MODEL_WDW_HIDDEN_PLATFORM, 1599, 1101, 3391, 0, 0, 0, 0x00010000, bhvHiddenObject),
		OBJECT(MODEL_WDW_HIDDEN_PLATFORM, 2879, 1152, 3391, 0, 0, 0, 0x00010000, bhvHiddenObject),
		OBJECT(MODEL_WDW_HIDDEN_PLATFORM, 1215, 1229, 4531, 0, 0, 0, 0x00010000, bhvHiddenObject),
		OBJECT(MODEL_NONE, 0, 0, 0, 0, 0, 0, 0x00000000, bhvInitializeChangingWaterLevel),
		OBJECT(MODEL_SKEETER, 2956, 288, -468, 0, 0, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_SKEETER, 184, 384, 621, 0, 0, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_SKEETER, -4785, 0, 5091, 0, 0, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_SKEETER, -2962, 0, 5808, 0, 0, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_NONE, 3390, 3584, 384, 0, -180, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_STAR, 600, -2650, 0, 0, 0, 0, (3 << 24), bhvStar),
		OBJECT(MODEL_WDW_WATER_LEVEL_DIAMOND, 1920, 2570, -3583, 0, 0, 0, 0x00000000, bhvWaterLevelDiamond),
		OBJECT(MODEL_WDW_WATER_LEVEL_DIAMOND, 3328, 256, 2918, 0, 0, 0, 0x00000000, bhvWaterLevelDiamond),
		OBJECT(MODEL_WDW_WATER_LEVEL_DIAMOND, 640, 1024, 3712, 0, 0, 0, 0x00000000, bhvWaterLevelDiamond),
		OBJECT(MODEL_WDW_WATER_LEVEL_DIAMOND, 1810, 40, -3118, 0, 0, 0, 0x00000000, bhvWaterLevelDiamond),
		OBJECT(MODEL_WDW_RECTANGULAR_FLOATING_PLATFORM, -767, 1152, 128, 0, 0, 0, 0x00000000, bhvWDWRectangularFloatingPlatform),
		OBJECT(MODEL_WDW_SQUARE_FLOATING_PLATFORM, 3390, 0, -522, 0, -180, 0, 0x00000000, bhvWDWSquareFloatingPlatform),
		OBJECT(MODEL_WDW_SQUARE_FLOATING_PLATFORM, -5007, 384, 1536, 0, 0, 0, 0x00000000, bhvWDWSquareFloatingPlatform),
		OBJECT(MODEL_WDW_SQUARE_FLOATING_PLATFORM, -767, 384, 1536, 0, 0, 0, 0x00000000, bhvWDWSquareFloatingPlatform),
		OBJECT(MODEL_WDW_SQUARE_FLOATING_PLATFORM, -795, 2304, -1099, 0, 0, 0, 0x00000000, bhvWDWSquareFloatingPlatform),
		OBJECT(MODEL_WDW_SQUARE_FLOATING_PLATFORM, -795, 2304, -2850, 0, 0, 0, 0x00000000, bhvWDWSquareFloatingPlatform),
		TERRAIN(wdw_seg7_area_1_collision),
		MACRO_OBJECTS(wdw_seg7_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x0003, SEQ_LEVEL_UNDERGROUND),
		TERRAIN_TYPE(TERRAIN_STONE),
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 3395, 1280, 384),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};