#ifndef TERRAIN_H
#define TERRAIN_H

class Terrain {
public:
	Terrain();
	~Terrain();

	void Draw();

private:
	const float kSize = 200.0f;

	int* m_TerrainData;
};
#endif