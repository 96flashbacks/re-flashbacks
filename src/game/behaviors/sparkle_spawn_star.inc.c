// sparkle_spawn_star.inc.c

struct ObjectHitbox sSparkleSpawnStarHitbox = {
    /* interactType:      */ INTERACT_STAR_OR_KEY,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 80,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

void bhv_spawned_star_init(void) {
    s32 starIndex;

    if (!(o->oInteractionSubtype & INT_SUBTYPE_NO_EXIT)) {
        o->oBhvParams = o->parentObj->oBhvParams;
    }

    starIndex = (o->oBhvParams >> 24) & 0xFF;

    if (bit_shift_left(starIndex)
        & save_file_get_star_flags(gCurrSaveFileNum - 1, COURSE_NUM_TO_INDEX(gCurrCourseNum))) {
        cur_obj_set_model(MODEL_TRANSPARENT_STAR);
    }

    cur_obj_play_sound_2(SOUND_GENERAL2_STAR_APPEARS);
}

void set_sparkle_spawn_star_hitbox(void) {
    obj_set_hitbox(o, &sSparkleSpawnStarHitbox);
    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        mark_obj_for_deletion(o);
        o->oInteractStatus = 0;
    }
}

void set_home_to_mario(void) {
    f32 sp1C;
    f32 sp18;

    o->oHomeX = gMarioObject->oPosX;
    o->oHomeZ = gMarioObject->oPosZ;
    o->oHomeY = gMarioObject->oPosY;
    o->oHomeY += 250.0f;
    o->oPosY = o->oHomeY;

    sp1C = o->oHomeX - o->oPosX;
    sp18 = o->oHomeZ - o->oPosZ;
}

void set_y_home_to_pos(void) {
    o->oForwardVel = 0.0f;
    o->oHomeY = o->oPosY;
}

void slow_star_rotation(void) {
    if (o->oAngleVelYaw > 0x400) {
        o->oAngleVelYaw -= 0x40;
    }
}

void bhv_spawned_star_loop(void) {
    o->oAngleVelYaw = 0x400;
    set_sparkle_spawn_star_hitbox();
    slow_star_rotation();
    o->oFaceAngleYaw += o->oAngleVelYaw;
}

void bhv_spawn_star_no_level_exit(u32 starIndex) {
    struct Object *star = spawn_object(o, MODEL_STAR, bhvSpawnedStarNoLevelExit);
    star->oBhvParams = starIndex << 24;
    star->oInteractionSubtype = INT_SUBTYPE_NO_EXIT;
    obj_set_angle(star, 0, 0, 0);
}
