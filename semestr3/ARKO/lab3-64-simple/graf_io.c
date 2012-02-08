// graf_io.c : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

typedef struct
{
	int width, height;
	unsigned char* pImg;
	int imgSize;
	// prosz? pami?ta?, ?e to jest struktura, kt?r? Pa?stwo zarz?dzacie
	// mo?na tu doda? kolejne pola, kt?re b?d? dla Was u?yteczne
} imgInfo;

typedef struct
{
	unsigned short bfType; 
	unsigned int  bfSize; 
	unsigned short bfReserved1; 
	unsigned short bfReserved2; 
	unsigned int  bfOffBits; 
	unsigned int  biSize; 
	int  biWidth; 
	int  biHeight; 
	short biPlanes; 
	short biBitCount; 
	unsigned int  biCompression; 
	unsigned int  biSizeImage; 
	int biXPelsPerMeter; 
	int biYPelsPerMeter; 
	unsigned int  biClrUsed; 
	unsigned int  biClrImportant;
} bmpHdr;
int putLine(int *, int *, int, imgInfo *, int *, int *, int *, int *);
void* freeResources(FILE* pFile, void* pFirst, void* pSnd)
{
/*
	if (pFile != 0)
	//	fclose(pFile);
	if (pFirst != 0)
	//	free(pFirst);
	if (pSnd !=0)
	//	free(pSnd);
*/
	return 0;
}

imgInfo* InitImage (int w, int h)
{
	imgInfo *pImg;
	if ( (pImg = (imgInfo *) malloc(sizeof(imgInfo))) == 0)
		return 0;
	pImg->height = h;
	pImg->width = w;
	pImg->pImg = (unsigned char*) malloc((((w * 3 + 3) >> 2) << 2) * h);
	if (pImg->pImg == 0)
	{
		free(pImg);
		return 0;
	}
	memset(pImg->pImg, 0, (((w * 3 + 3) >> 2) << 2) * h);
	return pImg;
}

imgInfo * copyImage(const imgInfo* pImg)
{
	imgInfo *pNew = InitImage(pImg->width, pImg->height);
	if (pNew != 0)
		memcpy(pNew->pImg, pImg->pImg, pNew->imgSize);
	return pNew;
}

void FreeImage(imgInfo* pInfo)
{
/*	if (pInfo && pInfo->pImg)
	//	free(pInfo->pImg);
	if (pInfo)
	//	free(pInfo);*/
}


imgInfo* readBMP(const char* fname)
{
	imgInfo* pInfo = 0;
	FILE* fbmp = 0;
	bmpHdr bmpHead;
	int lineBytes, y;
	unsigned char* ptr;

	pInfo = 0;
	fbmp = fopen(fname, "rb");
	if (fbmp == 0)
		return 0;

	fread((void *) &bmpHead, sizeof(bmpHead), 1, fbmp);
	// par? sprawdze?
	if (bmpHead.bfType != 0x4D42 || bmpHead.biPlanes != 1 ||
		bmpHead.biBitCount != 24 || 
		(pInfo = (imgInfo *) malloc(sizeof(imgInfo))) == 0)
		return (imgInfo*) freeResources(fbmp, pInfo ? pInfo->pImg : 0, pInfo);

	pInfo->width = bmpHead.biWidth;
	pInfo->height = bmpHead.biHeight;
	if ((pInfo->pImg = (unsigned char*) malloc(bmpHead.biSizeImage)) == 0)
		return (imgInfo*) freeResources(fbmp, pInfo->pImg, pInfo);

	// porz?dki z wysoko?ci? (mo?e by? ujemna)
	ptr = pInfo->pImg;
	lineBytes = ((pInfo->width * 3 + 3) >> 2) << 2; // rozmiar linii w bajtach
	if (pInfo->height > 0)
	{
		// "do g?ry nogami", na pocz?tku d?? obrazu
		ptr += lineBytes * (pInfo->height - 1);
		lineBytes = -lineBytes;
	}
	else
		pInfo->height = -pInfo->height;

	// sekwencja odczytu obrazu 
	// przesuni?cie na stosown? pozycj? w pliku
	if (fseek(fbmp, bmpHead.bfOffBits, SEEK_SET) != 0)
		return (imgInfo*) freeResources(fbmp, pInfo->pImg, pInfo);

	for (y=0; y<pInfo->height; ++y)
	{
		fread(ptr, 1, abs(lineBytes), fbmp);
		ptr += lineBytes;
	}
	fclose(fbmp);
	return pInfo;
}

int saveBMP(const imgInfo* pInfo, const char* fname)
{
	int lineBytes = ((pInfo->width * 3 + 3) >> 2)<<2;
	bmpHdr bmpHead = 
	{
	0x4D42,				// unsigned short bfType; 
	sizeof(bmpHdr),		// unsigned long  bfSize; 
	0, 0,				// unsigned short bfReserved1, bfReserved2; 
	sizeof(bmpHdr),		// unsigned long  bfOffBits; 
	40,					// unsigned long  biSize; 
	pInfo->width,		// long  biWidth; 
	pInfo->height,		// long  biHeight; 
	1,					// short biPlanes; 
	24,					// short biBitCount; 
	0,					// unsigned long  biCompression; 
	lineBytes * pInfo->height,	// unsigned long  biSizeImage; 
	11811,				// long biXPelsPerMeter; = 300 dpi
	11811,				// long biYPelsPerMeter; 
	2,					// unsigned long  biClrUsed; 
	0,					// unsigned long  biClrImportant;
	};

	FILE * fbmp;
	unsigned char *ptr;
	int y;

	if ((fbmp = fopen(fname, "wb")) == 0)
		return -1;
	if (fwrite(&bmpHead, sizeof(bmpHdr), 1, fbmp) != 1)
	{
		fclose(fbmp);
		return -2;
	}

	ptr = pInfo->pImg + lineBytes * (pInfo->height - 1);
	for (y=pInfo->height; y > 0; --y, ptr -= lineBytes)
		if (fwrite(ptr, sizeof(unsigned char), lineBytes, fbmp) != lineBytes)
		{
			fclose(fbmp);
			return -3;
		}
	fclose(fbmp);
	return 0;
}

void putPixel(imgInfo *pInfo, int x, int y, int *rgb)
{
	int lineBytes = ((pInfo->width * 3 + 3) >> 2) << 2;
	unsigned char *pAddr = pInfo->pImg + y * lineBytes + x * 3;
	*pAddr = rgb[0] >> 16;
	*(pAddr+1) = rgb[1] >> 16;
	*(pAddr+2) = rgb[2] >> 16;
}


typedef struct {
	int x, y; // wsp??rz?dne wierzcho?ka
	int rgb[3]; // kolor wierzcho?ka
	/* mo?e co? wi?cej b?dzie potrzebne */
} Vertex;

/*
Funkcja rysuj?ca "czworok?t": cudzys??w dlatego, ?e jest do?? mocno
ograniczony. Wierzcho?ki maj? parami r?wne wsp??rz?dne Y. Pierwsza para
wierzcho?k?w okre?la lew? kraw?d?; druga - praw?.
(v[0].y == v[2].y && v[1].y == v[3].y) && (v[0].x <= v[2].x && v[1].x <= v[3].x)

IN: pInfo - wskazanie na deskryptor obrazu, w kt?rym b?dzie rysowany czworok?t
	v - tablica wierzcho?k?w
*/
void drawQuad(imgInfo *pInfo, Vertex v[4])
{
	int y, ystart, ystop, ylength;
	int lfrgb[4], rtrgb[4], lfdlt[4], rtdlt[4];
	int x, xstart, xstop, xlength;
	int horzrgb[3], horzdlt[3];

	ystart = v[0].y;
	ystop = v[1].y;
	ylength = ystop - ystart;
	if (ylength == 0)
		ylength = 1;

	lfrgb[0] = v[0].rgb[0] << 16;
	lfrgb[1] = v[0].rgb[1] << 16;
	lfrgb[2] = v[0].rgb[2] << 16;
	lfrgb[3] = v[0].x << 16;

	rtrgb[0] = v[2].rgb[0] << 16;
	rtrgb[1] = v[2].rgb[1] << 16;
	rtrgb[2] = v[2].rgb[2] << 16;
	rtrgb[3] = v[2].x << 16;

	lfdlt[0] = ((v[1].rgb[0] << 16) - lfrgb[0]) / ylength;
	lfdlt[1] = ((v[1].rgb[1] << 16) - lfrgb[1]) / ylength;
	lfdlt[2] = ((v[1].rgb[2] << 16) - lfrgb[2]) / ylength;
	lfdlt[3] = ((v[1].x << 16) - lfrgb[3]) / ylength;

	rtdlt[0] = ((v[3].rgb[0] << 16) - rtrgb[0]) / ylength;
	rtdlt[1] = ((v[3].rgb[1] << 16) - rtrgb[1]) / ylength;
	rtdlt[2] = ((v[3].rgb[2] << 16) - rtrgb[2]) / ylength;
	rtdlt[3] = ((v[3].x << 16) - rtrgb[3]) / ylength;

	for (y=ystart; y <= ystop; ++y)
	{
// lfrgb, rtrgb, 
/*
printf("Xlength: %d horzR: %d dltR: %d rtRgb0: %d :: %d\n", xlength, horzrgb[0], horzdlt[0], rtrgb[0], ((rtrgb[0]-lfrgb[0])/xlength));
		// wyznaczenie parametr?w linii poziomej
*/
		xstart = (lfrgb[3] + 0x8000) >> 16; 
		xstop = (rtrgb[3] + 0x8000) >> 16;
		xlength = xstop - xstart;
		if (xlength == 0) 
			xlength = 1;
		horzrgb[0] = lfrgb[0];
		horzrgb[1] = lfrgb[1];
		horzrgb[2] = lfrgb[2];

		horzdlt[0] = (rtrgb[0] - horzrgb[0]) / xlength;
		horzdlt[1] = (rtrgb[1] - horzrgb[1]) / xlength;
		horzdlt[2] = (rtrgb[2] - horzrgb[2]) / xlength;

printf("%d, %d\n", sizeof(lfrgb), sizeof(rtrgb));
		printf("%d =\n", rtrgb[3]+rtdlt[3]);
		printf("%d\n", putLine(lfrgb,rtrgb,y,pInfo, lfdlt, rtdlt, horzrgb, horzdlt));

//		lfrgb[0] += lfdlt[0];
//		lfrgb[1] += lfdlt[1];
//		lfrgb[2] += lfdlt[2];
//		rtrgb[0] += rtdlt[0];
//		rtrgb[1] += rtdlt[1];
//		rtrgb[2] += rtdlt[2];
//		lfrgb[3] += lfdlt[3];
//		rtrgb[3] += rtdlt[3];
	}
}

unsigned char* DrawTriangle(imgInfo *pInfo, Vertex pV[3])
{
	// nie zak?adam niczego specjalnego o kolejno?ci wierzcho?k?w
	// w tej funkcji generalne porz?dki z wierzcho?kami s? do zrobienia

	Vertex vdraw[4];
	int firstidx = 0; // indeks "minimalnego" wierzcho?ka
	int sndidx = -1; // indeks drugiego wierzcho?ka - albo jest to "minimalny",
					 // albo z t? sam? wsp. y i wi?ksz? x
	int thirdidx, fourthidx, sizey;
	float dnm3 = 1.0, dnm4 = 1.0; // mianowniki przydatne przy liczeniu nachylenia odcink?w i interpolacji
	float ftmp;

	if (pV[1].y < pV[firstidx].y || pV[1].y == pV[firstidx].y && pV[1].x < pV[firstidx].x)
		firstidx = 1;
	if (pV[2].y < pV[firstidx].y || pV[2].y == pV[firstidx].y && pV[2].x < pV[firstidx].x)
		firstidx = 2;

	if (pV[(firstidx + 1)%3].y == pV[firstidx].y)
		sndidx = (firstidx + 1)%3;
	else if(pV[(firstidx + 2)%3].y == pV[firstidx].y)
		sndidx = (firstidx + 2)%3;
	else
		sndidx = firstidx;

	if (firstidx != sndidx) // prosta sytuacja, w dodatku ca?y tr?jk?t b?dzie rysowany w jednym kroku
	{
		vdraw[0] = pV[firstidx];
		vdraw[2] = pV[sndidx];
		thirdidx = 3 - (firstidx + sndidx);
		vdraw[1] = pV[thirdidx];
		vdraw[3] = pV[thirdidx];

		drawQuad(pInfo, vdraw);
	}
	else
	{
		// trzeba ustali? lew?/praw? kraw?d?
		thirdidx = (firstidx+1)%3; // wst?pnie lewa -> thirdidx
		fourthidx = (firstidx+2)%3;
		if (pV[thirdidx].y - pV[firstidx].y != 0)
			dnm3 /= pV[thirdidx].y - pV[firstidx].y;
		if (pV[fourthidx].y - pV[firstidx].y != 0)
			dnm4 /= pV[fourthidx].y - pV[firstidx].y;

		if ((pV[fourthidx].x - pV[firstidx].x) * dnm4 < (pV[thirdidx].x - pV[firstidx].x) * dnm3) // lewa jednak -> fourthidx
		{
			fourthidx = (firstidx+1)%3;
			thirdidx = (firstidx+2)%3;
			ftmp = dnm3;
			dnm3 = dnm4;
			dnm4 = ftmp;
		}
		vdraw[0] = pV[firstidx];
		vdraw[2] = pV[firstidx]; // bo firstidx == sndidx
		if (pV[thirdidx].y <= pV[fourthidx].y)
		{
			vdraw[1] = pV[thirdidx];
			// czwarty wierzcho?ek w ?rodku odcinka!
			sizey = vdraw[1].y - vdraw[0].y;
			if (sizey == 0)
				sizey = 1;
			vdraw[3] = pV[firstidx];
			vdraw[3].rgb[0] += (int) ((pV[fourthidx].rgb[0] - pV[firstidx].rgb[0]) * dnm4 * sizey + 0.5);
			vdraw[3].rgb[1] += (int) ((pV[fourthidx].rgb[1] - pV[firstidx].rgb[1]) * dnm4 * sizey + 0.5);
			vdraw[3].rgb[2] += (int) ((pV[fourthidx].rgb[2] - pV[firstidx].rgb[2]) * dnm4 * sizey + 0.5);
			vdraw[3].x += (int) ((pV[fourthidx].x - pV[firstidx].x) * dnm4 * sizey + 0.5);
			vdraw[3].y = vdraw[1].y;
			drawQuad(pInfo, vdraw);
			if (pV[thirdidx].y != pV[fourthidx].y) // wpp. ju? gotowe
			{
				vdraw[0] = pV[thirdidx];
				vdraw[2] = vdraw[3]; // zak?adam, ?e nie jest modyfikowane przez drawQuad!
				vdraw[1] = pV[fourthidx];
				vdraw[3] = pV[fourthidx];
				drawQuad(pInfo, vdraw);
			}
		}
		else
		{
			vdraw[3] = pV[fourthidx];
			// trzeci wierzcho?ek w ?rodku odcinka!
			sizey = vdraw[3].y - vdraw[0].y;
			if (sizey == 0)
				sizey = 1;
			vdraw[1] = pV[firstidx];
			vdraw[1].rgb[0] += (int) ((pV[thirdidx].rgb[0] - pV[firstidx].rgb[0]) * dnm3 * sizey + 0.5);
			vdraw[1].rgb[1] += (int) ((pV[thirdidx].rgb[1] - pV[firstidx].rgb[1]) * dnm3 * sizey + 0.5);
			vdraw[1].rgb[2] += (int) ((pV[thirdidx].rgb[2] - pV[firstidx].rgb[2]) * dnm3 * sizey + 0.5);
			vdraw[1].x += (int) ((pV[thirdidx].x - pV[firstidx].x) * dnm3 * sizey + 0.5);
			vdraw[1].y = vdraw[3].y;
			drawQuad(pInfo, vdraw);
			if (pV[thirdidx].y != pV[fourthidx].y) // wpp. ju? gotowe
			{
				vdraw[0] = vdraw[1]; // zak?adam, ?e nie jest modyfikowane przez drawQuad!
				vdraw[2] = pV[fourthidx]; 
				vdraw[1] = pV[thirdidx];
				vdraw[3] = pV[thirdidx];
				drawQuad(pInfo, vdraw);
			}
		}
		drawQuad(pInfo, vdraw);
	}
	return pInfo->pImg;
}

/* 
Na potrzeby test?w: 
rysuje "ko?o" sk?adaj?ce si? z n tr?jk?t?w stosownie kolorowanych
*/
void DrawCircle(imgInfo *pInfo, int x, int y, int r, int n)
{
	Vertex v[3];
	double angle = 2 * 3.14159265359 / n;
	int i;

	v[0].x = x;
	v[0].y = y;
	v[0].rgb[0] = v[0].rgb[1] = v[0].rgb[2] = 123;
/*	v[1].x = x-50;
	v[1].y = y+50;
	v[1].rgb[0] = v[1].rgb[1] = v[1].rgb[2] = 123;
	v[2].x = x+50;
	v[2].y = y+50;
	v[2].rgb[0] = v[2].rgb[1] = v[2].rgb[2] = 123;
*/
	for (i=0; i < n; ++i)
	{

		v[1].x = x + (int) (r * cos(i * angle) + 0.5);
		v[1].y = y + (int) (r * sin(i * angle) + 0.5);
		v[1].rgb[0] = (int) (128 + 127 * cos(i * angle + 2.0 / (3.14159265359 / 3.0)) + 0.5);
		v[1].rgb[1] = (int) (128 + 127 * cos(i * angle + 2.0 / 3.14159265359) + 0.5);
		v[1].rgb[2] = (int) (128 + 127 * cos(i * angle - 2.0 / (3.14159265359 / 3.0)) + 0.5);

		v[2].x = x + (int) (r * cos((i + 1) * angle) + 0.5);
		v[2].y = y + (int) (r * sin((i + 1) * angle) + 0.5);
		v[2].rgb[0] = (int) (128 + 127 * cos((i + 1) * angle + 2.0 / (3.14159265359 / 3.0)) + 0.5);
		v[2].rgb[1] = (int) (128 + 127 * cos((i + 1) * angle + 2.0 / 3.14159265359) + 0.5);
		v[2].rgb[2] = (int) (128 + 127 * cos((i + 1) * angle - 2.0 / (3.14159265359 / 3.0)) + 0.5);
		DrawTriangle(pInfo, v);
	}
}

/* na galerze kompiluj? i konsoliduj?:

	gcc -m32 -fpack-struct=1 -lm graf_io.c

*/

int main(int argc, char* argv[])
{
	imgInfo* pInfo;
	Vertex quad[] = { {100, 50, {255, 0, 0}}, 
						{50, 150, {0, 255, 0}},
						{150, 100, {0, 0, 255}},
						{200, 150, {255,255,255}},
	};
	Vertex tst[] =  { {125, 50, {255, 0, 0}}, 
	{50, 125, {0, 255, 0}},
	{125, 200, {0, 0, 255}},
	{125, 50, {255, 0, 0}}, 
	{200, 125, {0, 255, 0}},
	{125, 200, {0, 0, 255}},
	};

	if (sizeof(bmpHdr) != 54)
	{
		printf("Trzeba zmieni? opcje kompilacji, tak by rozmiar struktury bmpHdr wynosi? 54 bajty.\n");
		return 1;
	}

	pInfo = InitImage(256, 256);

	DrawCircle(pInfo, 127, 127, 100, 12);
	//DrawTriangle(pInfo, tst);
	//DrawTriangle(pInfo, tst+3);

	if (saveBMP(pInfo, "triangles.bmp") != 0)
	{
		printf("B??d zapisu pliku wynikowego.\n");
		return 3;
	}

	FreeImage(pInfo);
	return 0;
}

