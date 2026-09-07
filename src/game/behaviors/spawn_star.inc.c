// spawn_star.inc.c

static struct ObjectHitbox sCollectStarHitbox = {
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

void bhv_collect_star_init(void) {
    s8 starIndex = (o->oBhvParams >> 24) & 0xFF;
    u8 currentLevelStarFlags = save_file_get_star_flags(gCurrSaveFileNum - 1, COURSE_NUM_TO_INDEX(gCurrCourseNum));

    if (currentLevelStarFlags & (1 << starIndex)) {
        o->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_TRANSPARENT_STAR];
    } else {
        o->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_STAR];
    }

    obj_set_hitbox(o, &sCollectStarHitbox);
}

void bhv_collect_star_loop(void) {
    o->oFaceAngleYaw += 0x800;

    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        mark_obj_for_deletion(o);
        o->oInteractStatus = 0;
    }
}

// The star spawn behavior is much simpler, it's based on the E3 1996 B-Roll footage
void bhv_star_spawn_init(void) {
    o->oPosX = o->oHomeX;
    o->oPosZ = o->oHomeZ;
    o->oPosY = (find_floor_height(o->oPosX, o->oHomeY, o->oPosZ)) + 80.0f;
    o->oVelY = (o->oHomeY - o->oPosY) / 120.0f;
    cur_obj_become_intangible();
}

void bhv_star_spawn_loop(void) {
    switch (o->oAction) {
        case 0:
            o->oFaceAngleYaw += 0x2400;
            spawn_object(o, MODEL_NONE, bhvSparkleSpawn);
            if (o->oTimer == 65)
                o->oAction = 1;
            break;

        case 1:
            obj_move_xyz_using_fvel_and_yaw(o);
            o->oPosY += o->oVelY;
            o->oFaceAngleYaw += 0x2400;
            spawn_object(o, MODEL_NONE, bhvSparkleSpawn);
            if (o->oPosY > o->oHomeY) {
                cur_obj_become_tangible();
                o->oAction = 2;
            }
            break;

        case 2:
            o->oFaceAngleYaw += 0x800;

            if (o->oInteractStatus & INT_STATUS_INTERACTED) {
                mark_obj_for_deletion(o);
                o->oInteractStatus = 0;
            }
            break;
    }
}

struct Object *spawn_star(struct Object *star, f32 homeX, f32 homeY, f32 homeZ) {
    star = spawn_object_abs_with_rot(o, 0, MODEL_STAR, bhvStarSpawnCoordinates,
                                     o->oPosX, o->oPosY, o->oPosZ, 0, 0, 0);
    star->oBhvParams = o->oBhvParams;
    star->oHomeX = homeX;
    star->oHomeY = homeY;
    star->oHomeZ = homeZ;
    star->oFaceAnglePitch = 0;
    star->oFaceAngleRoll = 0;
    return star;
}

void spawn_default_star(f32 homeX, f32 homeY, f32 homeZ) {
    struct Object *star = spawn_star(star, homeX, homeY, homeZ);
    star->oBhvParams2ndByte = 0;
}

void spawn_red_coin_cutscene_star(f32 homeX, f32 homeY, f32 homeZ) {
    struct Object *star = spawn_star(star, homeX, homeY, homeZ);
    star->oBhvParams2ndByte = 1;
}

void spawn_no_exit_star(f32 homeX, f32 homeY, f32 homeZ) {
    struct Object *star = spawn_star(star, homeX, homeY, homeZ);
    star->oBhvParams2ndByte = 1;
    star->oInteractionSubtype |= INT_SUBTYPE_NO_EXIT;
}

void bhv_hidden_red_coin_star_init(void) {
    s16 count;

    if (gCurrCourseNum != COURSE_JRB) {
        spawn_object(o, MODEL_TRANSPARENT_STAR, bhvRedCoinStarMarker);
    }

    count = count_objects_with_behavior(bhvRedCoin);
    if (count == 0) {
        struct Object *star = spawn_object_abs_with_rot(o, 0, MODEL_STAR, bhvStar,
                                                        o->oPosX, o->oPosY, o->oPosZ, 0, 0, 0);
        star->oBhvParams = o->oBhvParams;
        o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
    }

    o->oHiddenStarTriggerCounter = 8 - count;
}

void bhv_hidden_red_coin_star_loop(void) {
    gRedCoinsCollected = o->oHiddenStarTriggerCounter;

    switch (o->oAction) {
        case 0:
            if (o->oHiddenStarTriggerCounter == 8) {
                o->oAction = 1;
            }
            break;

        case 1:
            if (o->oTimer > 2) {
                spawn_red_coin_cutscene_star(o->oPosX, o->oPosY, o->oPosZ);
                spawn_mist_particles();
                o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
            }
            break;
    }
}
