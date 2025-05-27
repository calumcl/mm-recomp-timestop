#include "global.h"
#include "modding.h"
#include "recompconfig.h"
#include "recomputils.h"
#include "regs.h"

RECOMP_IMPORT("debugprinter", void Debug_Print(u8 line, const char *fmd, ...));

RECOMP_HOOK("Room_ProcessRoomRequest")
s32 Timestop_Hook(PlayState *play, RoomContext *roomCtx) {
  unsigned long cfg = recomp_get_config_u32("timestop_option");
  switch (play->sceneId) {
  case SCENE_KINSTA1:
  case SCENE_KINDAN2:
  case SCENE_KAIZOKU:
  case SCENE_PIRATE:
  case SCENE_TORIDE:
  case SCENE_REDEAD:
  case SCENE_CASTLE:
  case SCENE_IKNINSIDE:
  case SCENE_RANDOM:
    if (cfg == 2) {
      R_TIME_SPEED = 0;
    }
    break;

  case SCENE_MITURIN:
  case SCENE_MITURIN_BS:
  case SCENE_HAKUGIN:
  case SCENE_HAKUGIN_BS:
  case SCENE_SEA:
  case SCENE_SEA_BS:
  case SCENE_INISIE_N:
  case SCENE_INISIE_R:
  case SCENE_INISIE_BS:
    if (cfg != 0) {
      R_TIME_SPEED = 0;
    }
    break;
  }
  return 1;
}