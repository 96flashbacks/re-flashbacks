// 0x0F000A30
const GeoLayout metal_box_geo[] = {
   GEO_CULLING_RADIUS(500),
   GEO_OPEN_NODE(),
#ifdef DECEMBER
      GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0xB4, 70),
#else
      GEO_SHADOW(SHADOW_SQUARE_PERMANENT, 0xB4, 70),
#endif
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_OPAQUE, metal_box_dl),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};
