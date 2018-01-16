#ifndef SCENEBASE_H
#define SCENEBASE_H

class SceneBase{
public:
	enum SCENE_ID {
		TITLE,
		STAGESELECT,
		MAIN,
		RESULT
	};

	SceneBase() {};
	virtual ~SceneBase() {};

	virtual SCENE_ID Update() = 0;
	virtual void Draw() = 0;
};
#endif