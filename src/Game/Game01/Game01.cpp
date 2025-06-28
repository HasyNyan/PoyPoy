#include "Game01.h"
#include "Ground.h"
#include "Camera.h"
#include "Player.h"
#include "Enemy.h"
#include "PlayerUI.h"

namespace Game01 {
bool Game01::Init()
{
    // 最初に1回動作する
    // ただし trueを返さなければ Initに何回も来る仕様。

    //プレイヤーオブジェクト
    Scene::Object::Create<Player>();
    //////エネミーオブジェクト
    ////Scene::Object::Create<Enemy>();
    //カメラオブジェクト
    Scene::Object::Create<Camera>();    //CreateObject;
    ////グラウンドオブジェクト
    Scene::Object::Create<Ground>();

    Scene::Object::Create<PlayerUI>();

    return true;
}
void Game01::Draw()
{
    Super::Draw();
}
void Game01::Exit()
{
}
}    // namespace Game01
