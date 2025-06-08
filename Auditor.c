#define _GNU_SOURCE
#include <link.h>
#include <string.h>

static const char* rain(void) {
	return "\x1b[1;31;7mRAINING BLOOD\x1b[0m";
}

unsigned int la_objopen(struct link_map* map, Lmid_t lmid,
    uintptr_t* cookie) {
	(void)lmid;
	(void)cookie;
	if (strstr(map->l_name, "Weather")) {
		return LA_FLG_BINDTO | LA_FLG_BINDFROM;
	} else {
		return 0;
	}
}

uintptr_t la_symbind32(Elf32_Sym* sym, unsigned int ndx,
    uintptr_t* refcook, uintptr_t* defcook,
    unsigned int* flags, const char* symname) {
	(void)ndx;
	(void)refcook;
	(void)defcook;
	(void)flags;
	if (strcmp(symname, "todays_weather") == 0) {
		return (uintptr_t)rain;
	}
	return sym->st_value;
}

uintptr_t la_symbind64(Elf64_Sym* sym, unsigned int ndx,
    uintptr_t* refcook, uintptr_t* defcook,
    unsigned int* flags, const char* symname) {
	(void)ndx;
	(void)refcook;
	(void)defcook;
	(void)flags;

	if (strcmp(symname, "todays_weather") == 0) {
		return (uintptr_t)rain;
	}
	return sym->st_value;
}

unsigned int la_version(unsigned int version) {
	(void)version;
	return LAV_CURRENT;
}
