#include "OctNode.h"
typedef struct Quantizer
{

    OCT_NODE Node;
} Quantizer;
typedef Quantizer *QUANTIZER;
void init_Quantizer(QUANTIZER *Quantizer);
void addColortoQuantizer(COLOR c);