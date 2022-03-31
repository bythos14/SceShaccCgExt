#ifndef _PATCHES_H_
#define _PATCHES_H_

#include <psp2/types.h>

#ifdef __cplusplus
extern "C" {
#endif

int PatchShacc(SceUID moduleId);

void ReleasePatches();

#ifdef __cplusplus
}
#endif

#endif /* _PATCHES_H_ */