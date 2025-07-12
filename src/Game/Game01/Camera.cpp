#include "Camera.h"
#include <System/Component/ComponentModel.h>
#include <System/Component/ComponentSpringArm.h>
namespace Game01 {
bool Camera::Init()
{
    __super::Init();

    //カメラオブジェクト
    //auto camera = Scene::Object::Create<Object>();    //CreateObject;
    SetName(u8"カメラ");
    auto cam = AddComponent<ComponentCamera>();
    cam->SetPositionAndTarget({0.0f, 60.0f, -50.0f}, {0.0f, 10.0f, 0.0f});

    auto arm = AddComponent<ComponentSpringArm>();
    arm->SetSpringArmObject("Player");
    return true;
}
void Camera::Update()
{
    // 毎フレーム動作する
}
}    // namespace Game01
