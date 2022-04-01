#ifndef _SHACCCG_EXT_H_
#define _SHACCCG_EXT_H_

#include <psp2/types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Enables extensions through module patches
 * 
 * @return 0 on success, -1 on failure
 */
int sceShaccCgExtEnableExtensions();

/**
 * @brief Release extension patches
 * 
 */
void sceShaccCgExtDisableExtensions();

#ifdef __cplusplus
}
#endif

#endif /* _SHACCCG_EXT_H_ */