#ifndef CONFIG_H
#define CONFIG_H

/**
 * @file config.h
 * A catch-all file for configuring various bugfixes and other settings
 * (maybe eventually) in SM64
 */

#define DEBUG
// #define FEBRUARY // DECEMBER, FEBRUARY and leaving undefined for the default March 1996
#define NINTENDO_LOGO

// Support Rumble Pak
#define ENABLE_RUMBLE (0 || VERSION_SH || VERSION_CN)

// Screen Size Defines
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

// Stack Size Defines
#define IDLE_STACKSIZE 0x800
#define STACKSIZE 0x2000
#define UNUSED_STACKSIZE 0x1400

// Border Height Define for NTSC Versions
#ifdef TARGET_N64
#ifndef VERSION_EU
#define BORDER_HEIGHT 8
#else
#define BORDER_HEIGHT 1
#endif
#else
// What's the point of having a border?
#define BORDER_HEIGHT 0
#endif

#endif // CONFIG_H
