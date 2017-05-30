#ifndef VERSION_LAIRD_H
#define VERSION_LAIRD_H
/* Laird version number */
#define SUPPVER1	94
#define SUPPVER2	4
#define SUPPVER3	0
#define	SUPPVER4	0

#define _MACRO2STR(x) #x
#define MACRO2STR(x) _MACRO2STR(x)
#define LAIRD_VERSION_STR_POSTFIX \
 "-Laird_" \
 MACRO2STR(SUPPVER1) "."	 \
 MACRO2STR(SUPPVER2) "." \
 MACRO2STR(SUPPVER3) "." \
 MACRO2STR(SUPPVER4)

/* Modify version string from <version.h> */
#undef VERSION_STR
#define VERSION_STR "2.6" VERSION_STR_POSTFIX GIT_VERSION_STR_POSTFIX \
	LAIRD_VERSION_STR_POSTFIX

#endif /* VERSION_LAIRD_H */
