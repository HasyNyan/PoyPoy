#include "Game01.h"
#include "Ground.h"
#include "Camera.h"
#include "Player.h"
#include "Cpu.h"
#include "PlayerUI.h"
#include "Timer.h"
#include "Object.h"
#include "Ufo.h"
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
    Scene::Object::Create<Cpu>();
    //カメラオブジェクト
    Scene::Object::Create<Camera>();    //CreateObject;
    ////グラウンドオブジェクト
    Scene::Object::Create<Ground>();

    Scene::Object::Create<PlayerUI>();

    Scene::Object::Create<Ufo>();
    //タイマーオブジェクト
    Scene::Object::Create<Timer>();
    return true;
}
}    // namespace Game01
