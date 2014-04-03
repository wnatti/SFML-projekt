#include "TileSys.h"

TileSys::TileSys(TextureLoader &tl)
{
	for(int i = 0; i < 5; i++)
	{
	tile_vector.push_back(Tile(tl,Vector2f(20*i,320)));
	tile_vector.push_back(Tile(tl,Vector2f(400,20*i)));
	}

	std::cout << "Tilesys created" << std::endl;
	//bvec = new std::vector<Bullet>;
}

void TileSys::draw(RenderWindow& window)
{
	tile_it = tile_vector.begin();

	while(tile_it!=tile_vector.end())
	{
		(*tile_it).draw(window);
		tile_it++;
	}
}

//bool TileSys::checkCollision(const Bullet &b)
//{
//	/*std::vector<Bullet> bvec = bs.getBVector();
//	std::vector<Bullet>::iterator bit = bvec.begin();
//
//	tile_it = tile_vector.begin();
//
//	bool something_happened = false;
//
//	while(tile_it!=tile_vector.end())
//	{
//
//		while(bit!=bvec.end())
//		{
//			if((*tile_it).getBounds().intersects((*bit)._boundaries))
//			{
//				return true;
//			}
//		
//			else
//			bit++;
//
//		}
//		
//
//		bit=bvec.begin();
//		tile_it++;
//	
//	}*/
//
//	/*if(something_happened)
//		bvec.shrink_to_fit();*/
//
//	//bs.renewBullets(bvec);
//	//std::cout << bvec.size() << std::endl;
//
//
//	tile_it = tile_vector.begin();
//
//	while(tile_it!=tile_vector.end())
//	{
//		if(tile_it->getBounds().intersects(b._boundaries))
//			return true;
//		else
//		tile_it++;
//	}
//	return false;
//}
//
//void TileSys::eraseCollided(BulletSys &bs)
//{
//	bvec = &bs.getBVector();
//	Findiffer fi(tile_vector);
//	std::vector<Bullet>::iterator bit = std::find_if(bvec->begin(),bvec->end(),fi);
//
//	if(bit!=bvec->end())
//		{
//			bit = bvec->erase(bit);
//			bvec->shrink_to_fit();
//			bs.renewBullets(bvec);
//		}
//}
TileSys::~TileSys(void)
{
}
