// 0x07018728
static Movtex wdw_movtex_area1_water_data[] = {
    MOV_TEX_INIT_LOAD(    1),
    MOV_TEX_ROT_SPEED(   10),
    MOV_TEX_ROT_SCALE(   10),
    MOV_TEX_4_BOX_TRIS(-5590, -3880),
    MOV_TEX_4_BOX_TRIS(-5590,  6730),
    MOV_TEX_4_BOX_TRIS( 4690,  6730),
    MOV_TEX_4_BOX_TRIS( 4690, -3880),
    MOV_TEX_ROT(     ROTATE_COUNTER_CLOCKWISE),
    MOV_TEX_ALPHA(    0x96),
    MOV_TEX_DEFINE(  TEXTURE_WATER),
    MOV_TEX_END(),
};

// 0x07018748
const struct MovtexQuadCollection wdw_movtex_area1_water[] = {
    {0, wdw_movtex_area1_water_data},
    {-1, NULL},
};
