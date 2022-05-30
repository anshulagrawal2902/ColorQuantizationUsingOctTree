
//COLOR STRUCT
typedef struct color
{
    int red;
    int green;
    int blue;

} Color;
typedef Color *COLOR;

//OCTNODE STRUCT
typedef struct OctNode
{
    COLOR c;
    int pixelCount;
    int palleteIndex;
    struct OctNode **children;
} OctNode;
typedef OctNode *OCT_NODE;

//LEVELSNODE STRUCT
typedef struct LevelsNode
{
    OCT_NODE nodePtr;
    struct LevelsNode *nextPtr;
} LevelsNode;
typedef LevelsNode *LEVELSNODE;

//QUANTIZER STRUCT
typedef struct Quantizer
{
    LEVELSNODE *levels;
    OCT_NODE root;
} Quantizer;
typedef Quantizer *QUANTIZER;

//COLOR FUNCTIONS
int *getArray(COLOR c);
void init_color(COLOR *c, int r, int g, int b);
char *int_to_str(int a);
char *toString(COLOR c);
void addTwoColors(COLOR c1, COLOR c2);
COLOR normalized(COLOR c, int pixelCount);
int getColorIndex(COLOR color, int level);

//OCTNODE FUNCTIONS
void initOctNode(OCT_NODE *OctNode, QUANTIZER Quantizer, int level);
int isLeaf(OCT_NODE OctNode);
OCT_NODE *getLeafNodes(OCT_NODE OctNode);
void addColor(COLOR color, OCT_NODE OctNode, int level, QUANTIZER Quantizer);
COLOR getColor(OCT_NODE OctNode);
int removeLeaves(OCT_NODE OctNode);

//QUANTIZER FUNCTIONS
void init_Quantizer(QUANTIZER *Quantizer, int levels);
void addColortoQuantizer(COLOR c, QUANTIZER q);
void addLevelNode(OCT_NODE OctNode, int level, QUANTIZER Quantizer);

//UTILS FUNCTIONS
void add_RGB_values_to_Quantizer(char *fileName, QUANTIZER Quantizer);
