#include "Ground.h"
#include <System/Component/ComponentModel.h>
#include <System/Component/ComponentCollisionModel.h>
namespace Game01 {
bool Ground::Init()
{
    __super::Init();

    //グラウンドオブジェクト
    //auto ground = Scene::Object::Create<Object>();
    SetName("Ground");
    AddComponent<ComponentModel>("data/Sample/SwordBout/Stage/Stage00.mv1");
    AddComponent<ComponentCollisionModel>()->AttachToModel();
    return true;
}
void Ground::Update()
{
    // 毎フレーム動作する
}
}    // namespace Game01
