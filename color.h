typedef struct color
{
    int red;
    int green;
    int blue;

} Color;
typedef Color *COLOR;

int *getArray(COLOR c);
void init_color(COLOR *c, int r, int g, int b);
char *int_to_str(int a);
char *toString(COLOR c);
COLOR normalized(COLOR c, int pixelCount);
void addColor(COLOR c1, COLOR c2);