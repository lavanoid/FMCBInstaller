#define GS_SETREG_RGBAQ(r, g, b, a, q) (GS_RGBAQ){(r), (g), (b), (a), (q)}

#define GS_WHITE GS_SETREG_RGBAQ(0xFF,0xFF,0xFF,0x80,0x00)
#define GS_BLACK GS_SETREG_RGBAQ(0x00,0x00,0x00,0x80,0x00)
#define GS_GREY GS_SETREG_RGBAQ(0x30,0x30,0x30,0x80,0x00)
#define GS_LGREY GS_SETREG_RGBAQ(0x50,0x50,0x50,0x80,0x00)
#define GS_DBLUE GS_SETREG_RGBAQ(0x00,0x00,0x50,0x80,0x00)
#define GS_BLUE GS_SETREG_RGBAQ(0x00,0x00,0x80,0x80,0x00)
#define GS_RED GS_SETREG_RGBAQ(0x80,0x00,0x00,0x80,0x00)
#define GS_GREEN GS_SETREG_RGBAQ(0x00,0x80,0x00,0x80,0x00)
#define GS_LBLUE_TRANS GS_SETREG_RGBAQ(0x00,0x00,0x80,0x40,0x00)
#define GS_YELLOW GS_SETREG_RGBAQ(0x80,0x80,0x30,0x80,0x00)

#define GS_WHITE_FONT GS_SETREG_RGBAQ(0x80,0x80,0x80,0x80,0x00)
#define GS_GREY_FONT GS_SETREG_RGBAQ(0x30,0x30,0x30,0x80,0x00)
#define GS_YELLOW_FONT GS_SETREG_RGBAQ(0x80,0x80,0x30,0x80,0x00)
#define GS_BLUE_FONT GS_SETREG_RGBAQ(0x30,0x30,0x80,0x80,0x00)

/* Button types, for use with DrawButtonLegend() */
enum ui_button_types{
	BUTTON_TYPE_R1=0,
	BUTTON_TYPE_R2,
	BUTTON_TYPE_L1,
	BUTTON_TYPE_L2,
	BUTTON_TYPE_UP,
	BUTTON_TYPE_DOWN,
	BUTTON_TYPE_LEFT,
	BUTTON_TYPE_RIGHT,
	BUTTON_TYPE_CIRCLE,
	BUTTON_TYPE_CROSS,
	BUTTON_TYPE_SQUARE,
	BUTTON_TYPE_TRIANGLE,
	BUTTON_TYPE_START,
	BUTTON_TYPE_SELECT
};

#define GIF_PACKET_MAX	1

struct UIDrawGlobal{
	unsigned char vmode, interlaced, ffmd, psm;
	unsigned short int width, height;
	GS_DRAWENV	draw_env;
	GS_DISPENV	disp_env;
	GS_GIF_PACKET	packets[GIF_PACKET_MAX];
	GS_PACKET_TABLE	giftable;
};

int LoadBackground(struct UIDrawGlobal *gsGlobal, GS_IMAGE* Texture);
int LoadPadGraphics(struct UIDrawGlobal *gsGlobal, GS_IMAGE* Texture);
void DrawLine(struct UIDrawGlobal *gsGlobal, short int x1, short int y1, short int x2, short int y2, short int z, GS_RGBAQ rgbaq);
void DrawSprite(struct UIDrawGlobal *gsGlobal, short int x1, short int y1, short int x2, short int y2, short int z, GS_RGBAQ rgbaq);
void DrawSpriteTextured(struct UIDrawGlobal *gsGlobal, GS_IMAGE *texture, short int x1, short int y1, short int u1, short int v1, short int x2, short int y2, short int u2, short int v2, short int z, GS_RGBAQ rgbaq);
void DrawSpriteTexturedClut(struct UIDrawGlobal *gsGlobal, GS_IMAGE *texture, GS_IMAGE *clut, short int x1, short int y1, short int u1, short int v1, short int x2, short int y2, short int u2, short int v2, short int z, GS_RGBAQ rgbaq);
void UploadClut(struct UIDrawGlobal *gsGlobal, GS_IMAGE *clut, const void *buffer);
void DrawBackground(struct UIDrawGlobal *gsGlobal, GS_IMAGE *background);
void DrawButtonLegend(struct UIDrawGlobal *gsGlobal, GS_IMAGE* PadGraphicsTexture, unsigned char ButtonType, float x, float y, int z);
void DrawProgressBar(struct UIDrawGlobal *gsGlobal, float percentage, short int x, short int y, short int z, short int len, GS_RGBAQ colour);
void SyncFlipFB(struct UIDrawGlobal *gsGlobal);
void ExecSyncClear(struct UIDrawGlobal *gsGlobal);