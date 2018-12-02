#include "Map.h"
#include "LTexture.h"



Map::Map(const char* spritesheet, int SCREEN_WIDTH, int SCREEN_HEIGHT)
{
    map_texture = LTexture::LoadTexture(spritesheet);

	int w = dimension::Screen_width();
	int h = dimension::Screen_height();

	blocks[0] = { 0,0,int(w*(0.15)),int(h*(0.11)) };
	blocks[1] = { int(w*(0.19)),0,int(w*(0.098)),int(h*(0.11)) };
	blocks[2] = { int(w*(0.324)),0, int(w*(0.163)),int(h*(0.11)) };
	blocks[3] = { int(w*(0.527)),0, int(w*(0.125)),int(h*(0.11)) };
	blocks[4] = { int(w*(0.688)),0,int(w*(0.099)),int(h*(0.11)) };
	blocks[5] = { int(w*(0.825)),0,int(w*(0.71)),int(h*(0.25)) };
	blocks[6] = { 0,int(h*(0.149)),int(w*(0.074)),int(h*(0.087)) };
	blocks[7] = { int(w*(0.114)),int(h*(0.149)),int(w*(0.196)),int(h*(0.088)) };
	blocks[8] = { int(w*(0.35)),int(h*(0.149)),int(w*(0.124)),int(h*(0.248)) };
	blocks[9] = { int(w*(0.512)),int(h*(0.149)),int(w*(0.274)),int(h*(0.099)) };
	blocks[10] = { int(w*(0.825)),int(h*(0.287)),int(w*(0.137)),int(h*(0.111)) };
	blocks[11] = { int(w*(0.036)),int(h*(0.274)),int(w*(0.113)),int(h*(0.089)) };
	blocks[12] = { int(w*(0.187)),int(h*(0.27)),int(w*(0.124)),int(h*(0.164)) };
	blocks[13] = { int(w*(0.35)),int(h*(0.436)),int(w*(0.123)),int(h*(0.138)) };
	blocks[14] = { int(w*(0.474)),int(h*(0.539)),int(w*(0.124)),int(h*(0.035)) };
	blocks[15] = { int(w*(0.512)),int(h*(0.397)),int(w*(0.088)),int(h*(0.101)) };
	blocks[16] = { int(w*(0.512)),int(h*(0.289)),int(w*(0.074)),int(h*(0.074)) };
	blocks[17] = { int(w*(0.625)),int(h*(0.287)),int(w*(0.076)),int(h*(0.075)) };
	blocks[18] = { int(w*(0.737)),int(h*(0.287)),int(w*(0.05)),int(h*(0.075)) };
	blocks[19] = { int(w*(0.637)),int(h*(0.399)),int(w*(0.149)),int(h*(0.097)) };
	blocks[20] = { int(w*(0.825)),int(h*(0.436)),int(w*(0.175)),int(h*(0.152)) };
	blocks[21] = { int(w*(0.037)),int(h*(0.398)),int(w*(0.149)),int(h*(0.037)) };
	blocks[22] = { int(w*(0.636)),int(h*(0.536)),int(w*(0.149)),int(h*(0.088)) };
	blocks[23] = { int(w*(0.037)),int(h*(0.475)),int(w*(0.274)),int(h*(0.187)) };
	blocks[24] = { int(w*(0.349)),int(h*(0.612)),int(w*(0.249)),int(h*(0.087)) };
	blocks[25] = { int(w*(0.638)),int(h*(0.661)),int(w*(0.149)),int(h*(0.136)) };
	blocks[26] = { int(w*(0.824)),int(h*(0.623)),int(w*(0.139)),int(h*(0.053)) };
	blocks[27] = { int(w*(0.823)),int(h*(0.709)),int(w*(0.139)),int(h*(0.089)) };
	blocks[28] = { 0,int(h*(0.697)),int(w*(0.084)),int(h*(0.177)) };
	blocks[29] = { int(w*(0.086)),int(h*(0.811)),int(w*(0.037)),int(h*(0.063)) };
	blocks[30] = { int(w*(0.125)),int(h*(0.700)),int(w*(0.05)),int(h*(0.072)) };
	blocks[31] = { int(w*(0.211)),int(h*(0.699)),int(w*(0.099)),int(h*(0.075)) };
	blocks[32] = { int(w*(0.348)),int(h*(0.736)),int(w*(0.25)),int(h*(0.0625)) };
	blocks[33] = { int(w*(0.488)),int(h*(0.837)),int(w*(0.298)),int(h*(0.049)) };
	blocks[34] = { int(w*(0.160)),int(h*(0.812)),int(w*(0.15)),int(h*(0.061)) };
	blocks[35] = { int(w*(0.038)),int(h*(0.911)),int(w*(0.086)),int(h*(0.050)) };
	blocks[36] = { int(w*(0.163)),int(h*(0.911)),int(w*(0.148)),int(h*(0.05)) };
	blocks[37] = { int(w*(0.349)),int(h*(0.837)),int(w*(0.101)),int(h*(0.126)) };
	blocks[38] = { int(w*(0.487)),int(h*(0.92)),int(w*(0.076)),int(h*(0.075)) };
	blocks[39] = { int(w*(0.6)),int(h*(0.92)),int(w*(0.188)),int(h*(0.075)) };
	blocks[40] = { int(w*(0.825)),int(h*(0.837)),int(w*(0.138)),int(h*(0.126)) };

	cout << SCREEN_WIDTH << endl << SCREEN_HEIGHT <<  endl;

	nodes[0] = {0, 184, 38, 29};
	nodes[1] = {0, 337, 38, 29};
	nodes[2] = {0, 510, 40, 29};
	nodes[3] = {0, 673, 38, 29};
	nodes[4] = {0, 739, 39, 29};
	nodes[5] = {77, 183, 38, 29};
	nodes[6] = {77, 87, 37, 29};
	nodes[7] = {90, 510, 38, 29};
	nodes[8] = {90, 595, 38, 29};
    nodes[9] = {128, 594, 39, 29};
	nodes[10] = {128, 673, 40, 29};
	nodes[11] = {128, 739, 38, 29};
	nodes[12] = {154, 87, 38, 29};
    nodes[13] = {154, 182, 40, 29};
	nodes[14] = {154, 278, 38, 29};
	nodes[15] = {178, 510, 37, 29};
    nodes[16] = {178, 596, 40, 29};
    nodes[17] = {294, 87, 39, 29};
    nodes[18] = {320, 739, 39, 29};
    nodes[19] = {320, 182, 39, 29};
    nodes[20] = {320, 306, 39, 29};
    nodes[21] = {320, 336, 38, 29};
    nodes[22] = {320, 444, 39, 29};
    nodes[23] = {320, 442, 39, 29};
    nodes[24] = {320, 510, 39, 29};
    nodes[25] = {320, 538, 39, 29};
    nodes[26] = {320, 595, 39, 29};
    nodes[27] = {320, 673, 39, 29};
    nodes[28] = {320, 673, 39, 29};
    nodes[29] = {320, 739, 39, 29};
    nodes[30] = {319, 86, 39, 29};
    nodes[31] = {460, 614, 39, 29};
    nodes[32] = {460, 683, 39, 29};
    nodes[33] = {460, 740, 39, 29};
    nodes[34] = {486, 86, 39, 29};
    nodes[35] = {486, 193, 40, 29};
    nodes[36] = {486, 279, 39, 29};
    nodes[37] = {486, 308, 39, 29};
    nodes[38] = {486, 385, 39, 29};
    nodes[39] = {498, 86, 39, 29};
    nodes[40] = {498, 86, 39, 29};
    nodes[41] = {576, 683, 39, 29};
    nodes[42] = {602, 278, 39, 29};
    nodes[43] = {602, 194, 38, 29};
    nodes[44] = {614, 278, 39, 29};
    nodes[45] = {614, 383, 39, 29};
    nodes[46] = {614, 442, 39, 29};
    nodes[47] = {614, 482, 39, 29};
    nodes[48] = {614, 539, 39, 29};
    nodes[49] = {614, 614, 39, 29};
    nodes[50] = {666, 86, 38, 29};
    nodes[51] = {717, 192, 39, 29};
    nodes[52] = {717, 278, 39, 29};
    nodes[53] = {806, 86, 38, 29};
    nodes[54] = {806, 192, 39, 30};
    nodes[55] = {806, 384, 38, 28};
    nodes[56] = {806, 480, 39, 29};
    nodes[57] = {806, 278, 39, 29};
    nodes[58] = {806, 306, 39, 29};
    nodes[59] = {806, 519, 39, 29};
    nodes[60] = {806, 614, 39, 29};
    nodes[61] = {806, 683, 39, 29};
    nodes[62] = {806, 740, 39, 29};
    nodes[63] = {986, 193, 39, 29};
    nodes[64] = {986, 307, 39, 29};
    nodes[65] = {986, 451, 39, 29};
    nodes[66] = {986, 518, 39, 29};
    nodes[67] = {986, 614, 39, 29};
    nodes[68] = {986, 739, 39, 29};
    nodes[69] = {0, 278, 39, 29};
    nodes[70] = {806, 452, 39, 29};

    adj_matrix[0][1] = {10000 + 154};
    adj_matrix[0][5] = {70};
    adj_matrix[1][2] = {10000 + 174};
    adj_matrix[1][21] = {321};
    adj_matrix[2][1] = {10000-174};
    adj_matrix[2][7] = {88};
    adj_matrix[3][10] = {128};
    adj_matrix[3][4] = {10000 + 64};
    adj_matrix[4][3] = {10000 - 64};
    adj_matrix[4][11] = {128};
    adj_matrix[5][0] = {-78};
    adj_matrix[5][6] = {10000 - 95};
    adj_matrix[5][13] = {76};
    adj_matrix[6][5] = {10000 + 95};
    adj_matrix[6][5] = {76};
    adj_matrix[7][2] = {-90};
    adj_matrix[7][15] = {88};
    adj_matrix[7][8] = {10000 + 85};
    adj_matrix[8][7] = {10000 - 85};
    adj_matrix[8][7] = {38};
    adj_matrix[9][8] = {-38};
    adj_matrix[9][16] = {51};
    adj_matrix[9][10] = {10000 + 79};
    adj_matrix[10][9] = {10000 - 79};
    adj_matrix[10][11] = {10000 + 66};
    adj_matrix[10][27] = {192};
    adj_matrix[10][3] = {-128};
    adj_matrix[11][4] = {-128};
    adj_matrix[11][4] = {10000 - 66};
    adj_matrix[11][4] = {192};
    adj_matrix[12][6] = {-77};
    adj_matrix[12][17] = {140};
    adj_matrix[13][5] = {-77};
    adj_matrix[13][19] = {241};
    adj_matrix[13][14] = {10000 + 96};
    adj_matrix[14][69] = {-154};
    adj_matrix[15][7] = {-88};
    adj_matrix[15][24] = {143};
    adj_matrix[15][16] = {10000 + 87};
    adj_matrix[16][26] = {142};
    adj_matrix[16][9] = {-50};
    adj_matrix[16][15] = {10000 - 87};
    adj_matrix[17][30] = {27};
    adj_matrix[17][12] = {-140};
    adj_matrix[19][20] = {10000 + 124};
    adj_matrix[19][13] = {-166};
    adj_matrix[19][30] = {10000 - 96};
    adj_matrix[20][19] = {10000 - 124};
    adj_matrix[20][21] = {10000 + 30};
    adj_matrix[20][37] = {166};
    adj_matrix[21][20] = {10000 - 30};
    adj_matrix[21][1] = {-320};
    adj_matrix[22][21] = {10000 - 108};
    adj_matrix[22][24] = {10000 + 66};
    adj_matrix[22][46] = {294};
    adj_matrix[24][22] = {10000 - 66};
    adj_matrix[24][25] = {10000 + 28};
    adj_matrix[24][15] = {-142};
    adj_matrix[25][24] = {10000 - 28};
    adj_matrix[25][26] = {10000 + 57};
    adj_matrix[25][48] = {294};
    adj_matrix[26][25] = {10000 - 57};
    adj_matrix[26][27] = {10000 + 78};
    adj_matrix[26][16] = {-142};
    adj_matrix[27][26] = {10000 - 78};
    adj_matrix[27][18] = {10000 - 66};
    adj_matrix[27][10] = {192};

    adj_matrix[18][27] = {10000 - 66};
    adj_matrix[18][11] = {-192};
    adj_matrix[18][33] = {140};

    adj_matrix[31][49] = {154};
    adj_matrix[31][32] = {10000 + 69};
    //adj_matrix[31][]


    adj_matrix[32][41] = {116};
    adj_matrix[32][33] = {10000 + 57};

    adj_matrix[33][32] = {10000 - 57};
    adj_matrix[33][18] = {140};

    adj_matrix[34][35] = {10000 + 107};
    adj_matrix[34][39] = {12};
    adj_matrix[34][30] = {-167};

    adj_matrix[35][34] = {10000 - 107};
    adj_matrix[35][36] = {10000 + 86};
    adj_matrix[35][43] = {116};

    adj_matrix[36][35] = {10000 - 86};
    adj_matrix[36][37] = {10000 + 28};
    adj_matrix[36][42] = {116};

    adj_matrix[37][36] = {10000 - 28};
    adj_matrix[37][38] = {10000 + 77};
    adj_matrix[37][20] = {-166};

    adj_matrix[38][37] = {10000 - 77};
    adj_matrix[38][45] = {128};
    adj_matrix[39][34] = {-12};
    adj_matrix[39][50] = {668};

    adj_matrix[41][32] = {-116};
    adj_matrix[41][61] = {232};

    adj_matrix[42][44] = {12};
    adj_matrix[42][43] = {10000 - 84};
    adj_matrix[42][36] = {-116};

    adj_matrix[43][42] = {10000 + 84};
    adj_matrix[43][35] = {-116};
    adj_matrix[43][51] = {115};

    adj_matrix[44][42] = {-12};
    adj_matrix[44][52] = {103};
    adj_matrix[44][45] = {105};

    adj_matrix[45][38] = {-128};
    adj_matrix[45][55] = {192};
    adj_matrix[45][46] = {10000 + 59};

    adj_matrix[46][22] = {-294};
    adj_matrix[46][47] = {10000 + 40};
    adj_matrix[46][45] = {10000 - 59};

    adj_matrix[47][46] = {10000 - 40};
    adj_matrix[47][48] = {10000 + 57};
    adj_matrix[47][56] = {192};


    adj_matrix[48][25] = {-294};
    adj_matrix[48][49] = {10000 - 75} ;
    adj_matrix[48][47] = {10000 - 57};

    adj_matrix[49][48] = {10000 - 75} ;
    adj_matrix[49][31] = {-154};
    adj_matrix[49][60] = {192};


    adj_matrix[50][39] = {-168};
    adj_matrix[50][53] = {140};

    adj_matrix[51][43] = {-115};
    adj_matrix[51][52] = {10000 + 86};
    adj_matrix[51][54] = {-89};

    adj_matrix[52][44] = {-103};
    adj_matrix[52][51] = {10000 - 86};
    adj_matrix[52][57] = {89};

    adj_matrix[53][50] = {-140};
    adj_matrix[53][54] = {10000 + 106} ;

    adj_matrix[54][53] = {10000 - 106} ;
    adj_matrix[54][51] = {89};
    adj_matrix[54][57] = {10000 + 86};
    adj_matrix[54][63] = {180};

    adj_matrix[55][45] = {-192};
    adj_matrix[55][58] = {10000 - 78};
    adj_matrix[55][56] = {10000 + 96};

    adj_matrix[56][47] = {-192};
    adj_matrix[56][55] = {10000 - 96};
    adj_matrix[56][59] = {10000 + 39};

    adj_matrix[57][52] = {-89};
    adj_matrix[57][58] = {10000 + 28};
    adj_matrix[57][54] = {10000 - 86};

    adj_matrix[58][57] = {10000 + 28};
    adj_matrix[58][55] = {10000 + 78};
    adj_matrix[58][64] = {680};

    adj_matrix[59][56] = {10000 - 39};
    adj_matrix[59][60] = {10000 + 95};
    adj_matrix[59][66] = {180};

    adj_matrix[60][59] = {10000 - 95};
    adj_matrix[60][49] = {-192};
    adj_matrix[60][67] = {180};
    adj_matrix[60][61] = {10000 - 69};

    adj_matrix[61][60] = {10000 - 69};
    adj_matrix[61][62] = {10000 + 57};
    adj_matrix[61][41] = {-230};

    adj_matrix[62][61] = {10000 - 67};
    adj_matrix[62][68] = {180};

    adj_matrix[63][54] = {-180};
    adj_matrix[63][64] = {10000 + 114};

    adj_matrix[64][63] = {10000 - 114};
    adj_matrix[64][58] = {-180};

    adj_matrix[65][66] = {10000 + 67};
    adj_matrix[65][70] = {-180};

    adj_matrix[66][65] = 1;
    adj_matrix[66][67] = 1;
    adj_matrix[66][59] = 1;

    adj_matrix[67][60] = {-180};
    adj_matrix[67][66] = {10000 - 96} ;
    adj_matrix[67][68] = {10000 + 125};

    adj_matrix[68][67] = {10000 - 125};
    adj_matrix[68][62] = {-180} ;

    adj_matrix[69][0] = {10000 - 94};
    adj_matrix[69][1] = {10000 + 59};
    adj_matrix[69][14] = {154};

    adj_matrix[70][55] = {10000 - 68};
    adj_matrix[70][56] = {10000 + 28};
    adj_matrix[70][65] = {180};
}

Map::~Map()
{}

void Map::Update()
{
    pos.x = pos.y = 0;
}

void Map::Render()
{

	SDL_RenderCopy(GameLoop::grenderer, map_texture, NULL, NULL);
	for(int i = 0; i < 71; i++)
    {
        SDL_SetRenderDrawColor(GameLoop::grenderer, 0xff, 0, 0, 0xff);
        SDL_RenderFillRect(GameLoop::grenderer, &(nodes[i]));
    }

}

//---Function to randomly place objects on the screen.
bool Map::PlaceObjects(int x, int y)
{
    SDL_Rect rendering_position =  {x, y, 20, 20};
    //vector<Point>locations ;
    for(int i = 0; i < 41; i++)
    {
        if((GameLoop::CheckCollision(rendering_position, blocks[i])))
            return false;
    }
    return true;
}
