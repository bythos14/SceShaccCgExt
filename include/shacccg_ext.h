#ifndef _SHACCCG_EXT_H_
#define _SHACCCG_EXT_H_

#include <psp2/types.h>
#include <psp2/shacccg.h>

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

/**
 * @brief Set the internal source file
 * 
 * The internal source file functions as a special include file. It has special priviledges
 * that allows for the declaration of intrinsics using '__attribute__'.
 * 
 * @param[in] sourceFile - The file to use as internal source code.
 * 
 * @note The sourceFile is not copied by this function.
 */
void sceShaccCgExtSetInternalSourceFile(const SceShaccCgSourceFile *sourceFile);

#ifdef __cplusplus
}
#endif

#endif /* _SHACCCG_EXT_H_ */