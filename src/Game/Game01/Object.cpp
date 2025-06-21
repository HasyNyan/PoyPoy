#include "Object.h";
#include <System/Component/ComponentModel.h>
namespace Game01 {
bool Stone::Init()
{
    __super::Init();

    SetName("ストーン");
    SetTranslate({0.0f, 10.0f, 0.0f});

    return true;
}
void Stone::Draw()
{
    Super::Draw();
    //描画する位置を取得
    auto pos = cast(GetTranslate());
    //円の色
    auto color = GetColor(0, 255, 255);
    //描画
    DrawSphere3D(pos, 3.0f, 20, color, color, TRUE);
}
}    // namespace Game01
