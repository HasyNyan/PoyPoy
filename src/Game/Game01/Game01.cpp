#include "Game01.h"
#include "Ground.h"
#include "Camera.h"
#include "Player.h"
#include "Enemy.h"
#include "Object.h"
namespace Game01 {
bool Game01::Init()
{
    // 最初に1回動作する
    // ただし trueを返さなければ Initに何回も来る仕様。

    //物体オブジェクト
    Scene::Object::Create<Stone>();
    //プレイヤーオブジェクト
    Scene::Object::Create<Player>();
    //////エネミーオブジェクト
    ////Scene::Object::Create<Enemy>();
    //カメラオブジェクト
    Scene::Object::Create<Camera>();    //CreateObject;
    ////グラウンドオブジェクト
    Scene::Object::Create<Ground>();
    //
    return true;
}
}    // namespace Game01
