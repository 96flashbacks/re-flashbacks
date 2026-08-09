// 0x0E0005E8
const GeoLayout wdw_geo_0005E8[] = {
    GEO_CULLING_RADIUS(420),
    GEO_OPEN_NODE(),
#ifndef DECEMBER
        GEO_SHADOW(SHADOW_SQUARE_TOGGLABLE, 0x96, 240),
#endif
        GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, wdw_seg7_dl_07013490),
        GEO_CLOSE_NODE(),
    GEO_CLOSE_NODE(),
    GEO_END(),
};
