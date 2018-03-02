#ifndef SCENEBASE_H
#define SCENEBASE_H

class SceneBase{
public:
	enum struct SCENE_ID {
		TITLE,
		STAGESELECT,
		LOAD,
		MAIN,
		GAMECLEAR,
		GAMEOVER
	};

	SceneBase() {};
	virtual ~SceneBase() {};

	virtual SCENE_ID Update() = 0;
	virtual void Draw() = 0;
};
#endif