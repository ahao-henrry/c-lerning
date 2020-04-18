#ifndef _AHAO_CFG_H
#define _AHAO_CFG_H

/*
 *write config
 *
 * */
int writeCfg(char* fileName/*in*/, char* key/*in*/, char* value/*in*/);

/*
 *read config
 *
 * */
int readCfg(char* fileName/*in*/, char* key/*in*/, char** value/*out*/);

#endif
