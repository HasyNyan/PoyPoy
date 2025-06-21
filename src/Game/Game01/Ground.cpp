#include "Ground.h"
#include <System/Component/ComponentModel.h>
#include <System/Component/ComponentCollisionModel.h>
namespace Game01 {
bool Ground::Init()
{
    __super::Init();

    //GROUND
    SetName("Ground");

    AddComponent<ComponentModel>("data/model/ground.mv1")->SetScaleAxisXYZ(1.0f)->SetTranslate(0.0f)->UseShader(false);

    AddComponent<ComponentCollisionModel>()->AttachToModel();

    return true;
}
void Ground::Update()
{
    // 毎フレーム動作する
}
}    // namespace Game01
