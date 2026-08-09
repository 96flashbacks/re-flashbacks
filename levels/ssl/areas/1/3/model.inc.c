// 0x0700BAD8 - 0x0700BAF0
static const Lights1 ssl_seg7_lights_0700BAD8 = gdSPDefLights1(
    0x3f, 0x3f, 0x3f,
    0xff, 0xff, 0xff, 0x28, 0x28, 0x28
);

// 0x0700BAF0 - 0x0700BBB0
static const Vtx ssl_seg7_vertex_0700BAF0[] = {
	{{ {-1023, 0, 2048}, 0, {4033, 990}, {110, 0, 63, 255} }},
	{{ {-1535, 768, 2935}, 0, {-96, -2170}, {110, 0, 64, 255} }},
	{{ {-1535, 0, 2935}, 0, {-96, 990}, {110, 0, 64, 255} }},
	{{ {-1023, 768, 2048}, 0, {4033, -2170}, {110, 0, 63, 255} }},
	{{ {-1535, 768, 2935}, 0, {-96, -2170}, {110, 0, 64, 255} }},
	{{ {-1535, 0, 2935}, 0, {-96, 990}, {110, 0, 192, 255} }},
	{{ {-1023, 768, 3822}, 0, {-4688, -2170}, {110, 0, 192, 255} }},
	{{ {-1023, 0, 3822}, 0, {-4688, 990}, {110, 0, 192, 255} }},
	{{ {-1535, 768, 2935}, 0, {-96, -2170}, {110, 0, 192, 255} }},
	{{ {-1023, 768, 3822}, 0, {-4688, -2170}, {110, 0, 193, 255} }},
};

// 0x0700BBB0 - 0x0700BC18
static const Gfx ssl_seg7_dl_0700BBB0[] = {
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, generic_09000800),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPLight(&ssl_seg7_lights_0700BAD8.l, 1),
    gsSPLight(&ssl_seg7_lights_0700BAD8.a, 2),
    gsSPVertex(ssl_seg7_vertex_0700BAF0, 10, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 3, 4, 0),
	gsSP1Triangle(5, 6, 7, 0),
	gsSP1Triangle(5, 8, 9, 0),
    gsSPEndDisplayList(),
};

// 0x0700BC18 - 0x0700BC88
const Gfx ssl_seg7_dl_0700BC18[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATERGBA, G_CC_MODULATERGBA),
    gsSPClearGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsSPDisplayList(ssl_seg7_dl_0700BBB0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPSetGeometryMode(G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};
