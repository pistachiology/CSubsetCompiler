#ifndef _CSubCFG_H_
#define _CSubCFG_H_

#include <stdio.h>
#include "csg.h"


typedef struct BlockDesc *Block; 
typedef struct livenessVariable *liveVar;

typedef struct BlockDesc {
  Block fail, branch; // jump targets
  CSGNode first, last; // pointer to first and last instruction in basic block
  int block_id;
} BlockDesc;

typedef struct livenessVariable{
    struct livenessVariable *next;
    CSSIdent var;
} livenessVariable;

extern Block block;
extern int leaders_count;
extern Block* genCFG(void);
extern void print_CFG(Block*);
extern liveVar liveness_manager(Block);

#endif
